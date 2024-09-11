import { editorInstance } from '$lib/store';
import * as d3 from 'd3';

export function diagram(el: HTMLDivElement, value: Diagram) {
    let editor = null
    let fixed = false

    editorInstance.subscribe(value => editor = value);

    const svg = d3.select(el)
        .append("svg")
        .attr("width", '100%')
        .attr("height", '100%')
        .attr("viewBox", `0 0 ${el.getBoundingClientRect().width} ${el.getBoundingClientRect().height}`)
        .call(d3.zoom().on("zoom", function (event) {
            fixed = true;
            svgGroup.attr("transform", event.transform);
        }))

    const svgGroup = svg.append("g");


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
        "value_object": "#ff7f00",
        "service": "#6a3d9a",
        "event": "#99e1d9"
    };

    function formatType(type: Type) {
        return `${type.type}${type.nullable ? '?' : ''}${type.array ? '[]' : ''}`
    }

    function drawValues(node: any, values: string[], offset: number) {
        const valuesGroup = node.append("g")
            .attr("class", "values")
            .selectAll("text")
            .data(values)
            .enter();

        valuesGroup.append("text")
            .attr("x", 10)
            .attr("y", (_: never, i: number) => 40 + (offset + i) * lineHeigth + lineHeigth / 2)
            .attr("dy", ".35em")
            .attr("text-anchor", "start")
            .attr("fill", backgroundColors.property)
            .text((value: string) => value);
    }

    function drawProperties(node: any, properties: Property[], offset: number) {
        const propertiesGroup = node.append("g")
            .attr("class", "properties")
            .selectAll("text")
            .data(properties)
            .enter();

        propertiesGroup.append("text")
            .attr("x", 10)
            .attr("y", (_: never, i: number) => 40 + (offset + i) * lineHeigth + lineHeigth / 2)
            .attr("dy", ".35em")
            .attr("text-anchor", "start")
            .attr("fill", backgroundColors.property)
            .text((prop: Property) => prop.name);

        propertiesGroup.append("text")
            .attr("x", 310)
            .attr("y", (_: never, i: number) => 40 + (offset + i) * lineHeigth + lineHeigth / 2)
            .attr("dy", ".35em")
            .attr("text-anchor", "end")
            .attr("fill", backgroundColors.type)
            .text((prop: Property) => formatType(prop));
    }

    function drawMethods(node: any, methods: Method[], offset: number) {
        const methodsGroup = node.append("g")
            .attr("class", "methods")
            .selectAll("text")
            .data(methods)
            .enter();

        methodsGroup.append("text")
            .attr("x", 10)
            .attr("y", (_: never, i: number) => 40 + (offset + i) * lineHeigth + lineHeigth / 2)
            .attr("dy", ".35em")
            .attr("text-anchor", "start")
            .attr("fill", backgroundColors.property)
            .text((method: Method) => `${method.name}(${method.parameters.map(p => p.name).join(', ')})`);

        methodsGroup.append("text")
            .attr("x", 310)
            .attr("y", (_: never, i: number) => 40 + (offset + i) * lineHeigth + lineHeigth / 2)
            .attr("dy", ".35em")
            .attr("text-anchor", "end")
            .attr("fill", backgroundColors.type)
            .text((method: Method) => formatType(method.return));
    }

    // Function to zoom and fit the diagram to the viewport
    function zoomToFit() {
        const bounds = svgGroup.node().getBBox();
        const parent = svg.node().getBoundingClientRect();
        const width = bounds.width, height = bounds.height;
        const midX = bounds.x + width / 2, midY = bounds.y + height / 2;
        const scale = 0.9 / Math.max(width / parent.width, height / parent.height);
        const translate = [parent.width / 2 - scale * midX, parent.height / 2 - scale * midY];

        svg.call(
            d3.zoom().transform,
            d3.zoomIdentity.translate(translate[0], translate[1]).scale(scale)
        );

        svgGroup.attr("transform", `translate(${translate[0]}, ${translate[1]}) scale(${scale})`);
    }

    function draw(value: Diagram) {
        // Define links based on entity properties
        // const domainEntities = [value.aggregates, value.entities, value.valueObjects].flat()
        const domainEntities = [value.aggregates, value.entities, value.valueObjects, value.enums, value.events, value.services].flat()

        const domainEntitiesToLink = [value.aggregates, value.entities, value.valueObjects, value.enums].flat()

        const domainLinks = domainEntitiesToLink.map(domain => {
            return domain.properties?.map(prop => {
                return {
                    source: domain.name, target: domainEntitiesToLink.find(e => {
                        if ('id' in e) return prop.type === e.id;
                        if ('ids' in e) return e.ids.includes(prop.type);
                        return false;
                    })?.name
                };
            })
        }).flat().filter(link => Boolean(link) && Boolean(link.target) && link.source !== link.target);

        // Create links with curved paths
        const links = svgGroup.append("g")
            .attr("class", "links")
            .selectAll("path")
            .data(domainLinks)
            .enter()
            .append("path")
            .attr("stroke", "lightgrey")
            .attr("stroke-width", 1)
            .attr("fill", "none");

        // Create nodes
        const nodes = svgGroup.append("g")
            .attr("class", "nodes")
            .selectAll("g")
            .data(domainEntities)
            .enter()
            .append("g")
            .attr("id", d => d.name)
            .attr("class", (d) => `${d.type} hover:cursor-pointer tooltip`)
            .on("mouseover", function (event, d) {
                d3.select(this).select("rect").attr("stroke", "black");
                links.attr("stroke", l => {
                    if (!l) {
                        return
                    }

                    if (l.source === d.name || l.target === d.name) {
                        return "black"
                    } else {
                        return "lightgrey"
                    }
                });
            })
            .on("mouseout", function (event, d) {
                d3.select(this).select("rect").attr("stroke", "none");
                links.attr("stroke", "lightgrey");
            })
            .on("click", function (event, d) {
                editor.revealLineInCenter(d.line);
                editor.setPosition({ lineNumber: d.line, column: 1 });
                editor.focus();
            })

        // Add rectangles for nodes
        nodes.append("rect")
            .attr("width", nodeWidth)
            .attr("height", d => 50 + ((d.properties?.length ?? 0) + (d.methods?.length ?? 0) + (d.values?.length ?? 0)) * lineHeigth)
            .attr("fill", backgroundColors.node)
            .attr("rx", 4)
            .attr("ry", 4);

        // Add node headers
        nodes.append("rect")
            .attr("width", nodeWidth - 2)
            .attr("height", 30)
            .attr("x", "1")
            .attr("y", "1")
            .attr("rx", 3)
            .attr("ry", 3)
            .attr("fill", d => backgroundColors[d.type]);

        nodes.append("text")
            .attr("x", nodeWidth / 2)
            .attr("y", 20)
            .attr("text-anchor", "middle")
            .attr("font-weight", "bold")
            .attr("fill", backgroundColors.text)
            .text(d => d.name);

        // Add properties to aggregate nodes
        svgGroup.selectAll(".aggregate").each(function (d: Aggregate) {
            drawProperties(d3.select(this), d.properties, 0);

            drawMethods(d3.select(this), d.methods, d.properties.length);
        });

        // Add properties to entity nodes
        svgGroup.selectAll(".entity").each(function (d) {
            drawProperties(d3.select(this), d.properties, 0);

            drawMethods(d3.select(this), d.methods, d.properties.length);
        });

        // Add properties to value object nodes
        svgGroup.selectAll(".value_object").each(function (d) {
            drawProperties(d3.select(this), d.properties, 0);
        });

        // Add enum values to nodes
        svgGroup.selectAll(".enum").each(function (d) {
            drawValues(d3.select(this), d.values, 0);
        });

        svgGroup.selectAll(".event").each(function (d) {
            drawProperties(d3.select(this), d.properties, 0);
        });

        svgGroup.selectAll(".service").each(function (d) {
            drawMethods(d3.select(this), d.methods, 0);
        });

        // Manually position nodes in a Masonry layout
        let columnHeights = new Array(columns).fill(0); // Track the height of each column

        nodes.attr("transform", function (d, i) {
            // const nextColumnIndex = columnHeights.indexOf(Math.min(...columnHeights)); // Find the column with the minimum height
            const nextColumnIndex = i % columns;
            const x = nextColumnIndex * (nodeWidth + columnGap); // Calculate x position
            const y = columnHeights[nextColumnIndex]; // Calculate y position

            columnHeights[nextColumnIndex] += d3.select(this).node().getBBox().height + rowGap; // Update the column height

            d.position.x = x;
            d.position.y = y;
            return `translate(${x}, ${y})`;
        });

        links.attr("d", function (d) {
            const sourceNode = domainEntities.find(entity => {
                if ('id' in entity) return entity.id === d.source;
                if ('ids' in entity) return entity.ids.includes(d.source);
                return false;
            });

            const targetNode = domainEntities.find(
                entity => {
                    if ('id' in entity) return entity.id === d.target;
                    if ('ids' in entity) return entity.ids.includes(d.target);
                    return false;
                }
            );
            if (!sourceNode || !targetNode) return '';

            const dx = targetNode.position.x - sourceNode.position.x;
            const dy = targetNode.position.y - sourceNode.position.y;
            const dr = Math.sqrt(dx * dx + dy * dy);
            return `M${sourceNode.position.x + nodeWidth / 2},${sourceNode.position.y + 30}A${dr},${dr} 0 0,1 ${targetNode.position.x + nodeWidth / 2},${targetNode.position.y + 30}`;
        });

        // link.attr("d", function (d) {
        //     const sourceNode = entities.find(entity => entity.id === d.source);
        //     const targetNode = entities.find(entity => entity.id === d.target);
        //     if (!sourceNode || !targetNode) return '';

        //     const sourceX = sourceNode.x + nodeWidth / 2;
        //     const sourceY = sourceNode.y + 30;
        //     const targetX = targetNode.x + nodeWidth / 2;
        //     const targetY = targetNode.y + 30;

        //     if (sourceX === targetX) {
        //         // Alinhamento vertical
        //         return `M${sourceX},${sourceY}L${targetX},${targetY}`;
        //     } else if (sourceY === targetY) {
        //         // Alinhamento horizontal
        //         return `M${sourceX},${sourceY}L${targetX},${targetY}`;
        //     } else {
        //         // Link com curvas de 90º
        //         const midX = (sourceX + targetX) / 2;
        //         const midY = (sourceY + targetY) / 2;
        //         return `M${sourceX},${sourceY}L${midX},${sourceY}L${midX},${targetY}L${targetX},${targetY}`;
        //     }
        // });

        // link.attr("d", function (d) {
        //     const sourceNode = entities.find(entity => entity.id === d.source);
        //     const targetNode = entities.find(entity => entity.id === d.target);
        //     if (!sourceNode || !targetNode) return '';

        //     const sourceX = sourceNode.x + nodeWidth / 2;
        //     const sourceY = sourceNode.y + 30;
        //     const targetX = targetNode.x + nodeWidth / 2;
        //     const targetY = targetNode.y + 30;
        //     const radius = 15; // Raio das bordas arredondadas

        //     if (sourceX === targetX) {
        //         // Alinhamento vertical
        //         return `M${sourceX},${sourceY}L${targetX},${targetY}`;
        //     } else if (sourceY === targetY) {
        //         // Alinhamento horizontal
        //         return `M${sourceX},${sourceY}L${targetX},${targetY}`;
        //     } else {
        //         // Link com curvas de 90º e bordas arredondadas
        //         const horizontalDir = targetX > sourceX ? 1 : -1;
        //         const verticalDir = targetY > sourceY ? 1 : -1;

        //         const midX = sourceX + horizontalDir * radius;
        //         const midY = sourceY + verticalDir * radius;

        //         return `
        //             M${sourceX},${sourceY}
        //             L${midX},${sourceY}
        //             A${radius},${radius} 0 0,${horizontalDir === 1 ? 1 : 0} ${midX},${midY}
        //             L${midX},${targetY - verticalDir * radius}
        //             A${radius},${radius} 0 0,${verticalDir === 1 ? 1 : 0} ${midX + horizontalDir * radius},${targetY}
        //             L${targetX},${targetY}`;
        //     }
        // });

        if (!fixed) {
            zoomToFit();
        }
    }

    return {
        update(value: Diagram) {
            svgGroup.selectAll('*').remove();
            draw(value);
        },
        destroy() {
            svg.remove();
        }
    };
}
