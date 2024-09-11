import { editorInstance } from '$lib/store';
import * as d3 from 'd3';
import _ from 'lodash';

export function diagram(el: HTMLDivElement, value: Diagram) {
    let diagram: Diagram = value;
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
    const columnGap = 60; // Gap between columns
    const rowGap = 60; // Gap between rows
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

    // Helper function to find the closest port based on a target position
    function findClosestPorts(sourcePorts: any, targetPorts: any) {
        const distances = Object.keys(sourcePorts).map(sourcePort => {
            return Object.keys(targetPorts).map(targetPort => {
                const dx = Math.abs(targetPorts[targetPort].x - sourcePorts[sourcePort].x)
                const dy = Math.abs(targetPorts[targetPort].y - sourcePorts[sourcePort].y);
                return { sourcePort, targetPort, distance: Math.sqrt(dx * dx + dy * dy) };
            });
        });

        const closest = distances.flat().reduce((acc, curr) => {
            return acc.distance < curr.distance ? acc : curr;
        });

        return { source: closest.sourcePort, target: closest.targetPort };
    }

    function draw(value: Diagram) {
        diagram = value;
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

        const linkIcons = svgGroup.append("g")
            .attr("class", "link-icons")
            .selectAll("circle")
            .data(domainLinks)
            .enter()
            .append("circle")
            .attr("r", 5)
            .attr("fill", "red")
            .attr("cx", d => {
                const targetNode = domainEntities.find(
                    entity => entity.name === d.target
                );
                return targetNode ? targetNode.position.x + nodeWidth / 2 : 0;
            })
            .attr("cy", d => {
                const targetNode = domainEntities.find(
                    entity => entity.name === d.target
                );
                return targetNode ? targetNode.position.y + 30 : 0;
            });

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

        // Add ports to each node (center-top, middle-right, middle-left, center-bottom)
        nodes.each(function (d) {
            const bounds = d3.select(this).node().getBBox();
            const position = d.position;

            // Define ports
            const ports = {
                top: { x: bounds.width / 2, y: 0 },
                right: { x: bounds.width, y: bounds.height / 2 },
                bottom: { x: bounds.width / 2, y: bounds.height },
                left: { x: 0, y: bounds.height / 2 }
            };

            // Append ports to the node
            // const portsGroup = d3.select(this).append("g").attr("class", "ports");
            // portsGroup.append("circle").attr("cx", ports.top.x).attr("cy", ports.top.y).attr("r", 4).attr("fill", "blue");
            // portsGroup.append("circle").attr("cx", ports.right.x).attr("cy", ports.right.y).attr("r", 4).attr("fill", "blue");
            // portsGroup.append("circle").attr("cx", ports.bottom.x).attr("cy", ports.bottom.y).attr("r", 4).attr("fill", "blue");
            // portsGroup.append("circle").attr("cx", ports.left.x).attr("cy", ports.left.y).attr("r", 4).attr("fill", "blue");

            const absolutePorts = {
                top: { x: position.x + ports.top.x, y: position.y + ports.top.y },
                right: { x: position.x + ports.right.x, y: position.y + ports.right.y },
                bottom: { x: position.x + ports.bottom.x, y: position.y + ports.bottom.y },
                left: { x: position.x + ports.left.x, y: position.y + ports.left.y }
            }

            // Store the port positions in the node data for easy access later
            d.ports = absolutePorts;
        });


        // links.attr("d", function (d) {
        //     const sourceNode = domainEntities.find(entity => {
        //         if ('id' in entity) return entity.id === d.source;
        //         if ('ids' in entity) return entity.ids.includes(d.source);
        //         return false;
        //     });

        //     const targetNode = domainEntities.find(
        //         entity => {
        //             if ('id' in entity) return entity.id === d.target;
        //             if ('ids' in entity) return entity.ids.includes(d.target);
        //             return false;
        //         }
        //     );
        //     if (!sourceNode || !targetNode) return '';

        //     const dx = targetNode.position.x - sourceNode.position.x;
        //     const dy = targetNode.position.y - sourceNode.position.y;
        //     const dr = Math.sqrt(dx * dx + dy * dy);
        //     return `M${sourceNode.position.x + nodeWidth / 2},${sourceNode.position.y + 30}A${dr},${dr} 0 0,1 ${targetNode.position.x + nodeWidth / 2},${targetNode.position.y + 30}`;
        // });

        links.attr("d", function (d) {
            const sourceNode = d3.select(`#${d.source}`).datum();
            const targetNode = d3.select(`#${d.target}`).datum();

            // // Get source and target port positions and reajust to the node position
            const sourcePorts = sourceNode.ports
            const targetPorts = targetNode.ports;


            const closestPorts = findClosestPorts(sourcePorts, targetPorts); // Calculate distances between ports to find the closest connection points


            // // Return a straight path between the nearest source and target ports
            return `M${sourcePorts[closestPorts.source].x},${sourcePorts[closestPorts.source].y}L${targetPorts[closestPorts.target].x},${targetPorts[closestPorts.target].y}`;

            // Return a curved path between the nearest source and target ports
            return `M${sourcePorts[closestPorts.source].x},${sourcePorts[closestPorts.source].y}A${sourcePorts[closestPorts.source].x},${sourcePorts[closestPorts.source].y + 50} ${targetPorts[closestPorts.target].x},${targetPorts[closestPorts.target].y}`;
        });

        // linkIcons.attr("cx", d => {
        //     const targetNode = domainEntities.find(
        //         entity => entity.name === d.target
        //     );
        //     return targetNode ? targetNode.position.x + nodeWidth / 2 : 0;
        // }
        // ).attr("cy", d => {
        //     const targetNode = domainEntities.find(
        //         entity => entity.name === d.target
        //     );
        //     return targetNode ? targetNode.position.y + 30 : 0;
        // });


        if (!fixed) {
            zoomToFit();
        }
    }

    return {
        update(value: Diagram) {
            if (_.isEqual(value, diagram)) {
                return;
            }

            svgGroup.selectAll('*').remove();
            draw(value);
        },
        destroy() {
            svg.remove();
        }
    };
}
