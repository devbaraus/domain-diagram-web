import * as d3 from 'd3';

export function diagram(el: HTMLDivElement, entities: Entity[]) {
    const svg = d3.select(el)
        .append("svg")
        .attr("width", '70dvw')
        .attr("height", window.innerHeight)
        .attr("viewBox", `0 0 ${window.innerWidth} ${window.innerHeight}`)
        .call(d3.zoom().on("zoom", function (event) {
            svgGroup.attr("transform", event.transform);
        }))

    const svgGroup = svg.append("g")

    // const svg = d3.select(el)
    // .append("svg")
    // .attr("width", '70dvw')
    // .attr("height", window.innerHeight)
    // .attr("viewBox", `0 0 ${window.innerWidth} ${window.innerHeight}`)
    // .call(d3.zoom().on("zoom", function(event) {
    //     svgGroup.attr("transform", event.transform);
    // }))
    // .append("g");

    const nodeWidth = 320; // Width of each node
    const lineHeigth = 30;
    const columnGap = 40; // Gap between columns
    const rowGap = 40; // Gap between rows
    const columns = 4; // Number of columns

    const backgroundColors = {
        'text': 'white',
        'node': '#F3F3F3',
        'property': '#595959',
        'type': '#8c8c8c',
        "aggregate": "#1f78b4",
        "entity": "#33a02c",
        "enum": "#e31a1c",
        "value_object": "#ff7f00"
    };

    function draw(entities: Entity[]) {
        // Define links based on entity properties
        const entitiesLinks = entities.map(entity => {
            return entity.properties.map(prop => {
                const propType = prop.type?.replaceAll('[', '').replaceAll(']', '');
                return { source: entity.id, target: entities.find(e => e.id === propType || e.name === propType)?.id };
            }).filter(link => link.target !== undefined);
        }).flat();

        // Create links with curved paths
        const link = svgGroup.append("g")
            .attr("class", "links")
            .selectAll("path")
            .data(entitiesLinks)
            .enter()
            .append("path")
            .attr("stroke", "lightgrey")
            .attr("stroke-width", 1)
            .attr("fill", "none");

        // Create nodes
        const node = svgGroup.append("g")
            .attr("class", "nodes")
            .selectAll("g")
            .data(entities)
            .enter()
            .append("g")
            .on("mouseover", function (event, d) {
                d3.select(this).select("rect").attr("stroke", "black");
                link.attr("stroke", dl => dl.source === d.id || dl.target === d.id ? "black" : "lightgrey");
            })
            .on("mouseout", function (event, d) {
                d3.select(this).select("rect").attr("stroke", "none");
                link.attr("stroke", "lightgrey");
            })

        // Add rectangles for nodes
        node.append("rect")
            .attr("width", nodeWidth)
            .attr("height", d => 50 + (d.properties.length + d.values?.length) * lineHeigth)
            .attr("fill", backgroundColors.node)
            .attr("rx", 4)
            .attr("ry", 4)
            ;

        // Add node headers
        node.append("rect")
            .attr("width", nodeWidth - 2)
            .attr("height", 30)
            .attr("x", "1")
            .attr("y", "1")
            .attr("rx", 3)
            .attr("ry", 3)
            .attr("fill", d => backgroundColors[d.type]);

        node.append("text")
            .attr("x", nodeWidth / 2)
            .attr("y", 20)
            .attr("text-anchor", "middle")
            .attr("font-weight", "bold")
            .attr("fill", backgroundColors.text)
            .text(d => d.name);

        // Add properties to nodes
        node.each(function (d) {
            const props = d3.select(this).selectAll(".property")
                .data(d.properties)
                .enter();

            // props.append("rect")
            //     .attr("width", nodeWidth)
            //     .attr("height", lineHeigth)
            //     .attr("x", 0)
            //     .attr("y", (prop, i) => 40 + i * lineHeigth)
            //     .attr("fill", backgroundColors.node);

            props.append("text")
                .attr("class", "property")
                .attr("x", 10)
                .attr("y", (prop, i) => 40 + i * lineHeigth + lineHeigth / 2)
                .attr("dy", ".35em")
                .attr("text-anchor", "start")
                .attr("fill", backgroundColors.property)
                .text(prop => prop.name);

            props.append("text")
                .attr("class", "property")
                .attr("x", nodeWidth - 10)
                .attr("y", (prop, i) => 40 + i * lineHeigth + lineHeigth / 2)
                .attr("dy", ".35em")
                .attr("text-anchor", "end")
                .attr("fill", backgroundColors.type)
                .text(prop => prop.type);
        });

        // Add enum values to nodes
        node.each(function (d) {
            const values = d3.select(this).selectAll(".value")
                .data(d.values)
                .enter();

            // values.append("rect")
            //     .attr("width", nodeWidth)
            //     .attr("height", lineHeigth)
            //     .attr("x", 0)
            //     .attr("y", (value, i) => 40 + d.properties.length * lineHeigth + i * lineHeigth)
            //     .attr("fill", backgroundColors.node);

            values.append("text")
                .attr("class", "value")
                .attr("x", 10)
                .attr("y", (value, i) => 40 + d.properties.length * lineHeigth + i * lineHeigth + lineHeigth / 2)
                .attr("dy", ".35em")
                .attr("text-anchor", "start")
                .attr("fill", backgroundColors.property)
                .text(value => value);
        });

        // Manually position nodes in a Masonry layout
        let columnHeights = new Array(columns).fill(0); // Track the height of each column

        node.attr("transform", function (d, i) {
            const minHeightIndex = columnHeights.indexOf(Math.min(...columnHeights)); // Find the column with the minimum height
            const x = minHeightIndex * (nodeWidth + columnGap); // Calculate x position
            const y = columnHeights[minHeightIndex]; // Calculate y position

            columnHeights[minHeightIndex] += d3.select(this).node().getBBox().height + rowGap; // Update the column height

            d.x = x;
            d.y = y;
            return `translate(${x}, ${y})`;
        });

        // Update positions of the links
        link.attr("d", function (d) {
            const sourceNode = entities.find(entity => entity.id === d.source);
            const targetNode = entities.find(entity => entity.id === d.target);
            if (!sourceNode || !targetNode) return '';

            const dx = targetNode.x - sourceNode.x;
            const dy = targetNode.y - sourceNode.y;
            const dr = Math.sqrt(dx * dx + dy * dy);
            return `M${sourceNode.x + nodeWidth / 2},${sourceNode.y + 30}A${dr},${dr} 0 0,1 ${targetNode.x + nodeWidth / 2},${targetNode.y + 30}`;
        });
    }

    return {
        update(entities: Entity[]) {
            svgGroup.selectAll('*').remove();
            draw(entities);
        },
        destroy() {
            svg.remove();
        }
    };
}
