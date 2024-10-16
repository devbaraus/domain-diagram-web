import { editor as editorInstance } from '$lib/store';
import * as d3 from 'd3';
import _ from 'lodash';

export function diagram(el: HTMLDivElement, value: Diagram) {
    let diagram: Diagram = value;
    let editor = null
    let fixed = false
    const minZoom = 0.1, maxZoom = 2;

    editorInstance?.subscribe(value => editor = value);

    const svg = d3.select(el)
        .append("svg")
        .attr("id", "diagram")
        .attr("width", '100%')
        .attr("height", '100%')
        .attr("viewBox", `0 0 ${el.getBoundingClientRect().width} ${el.getBoundingClientRect().height}`)
        .call(d3.zoom()
            .scaleExtent([minZoom, maxZoom])
            .on("zoom", function (event) {
                fixed = true;
                svgGroup.attr("transform", event.transform);
            }))

    const style = svg.append("style")
    style.text(`@import url('https://fonts.googleapis.com/css2?family=Fira+Code:wght@400;700&display=swap');
            text {
                font-family: 'Fira Code', monospace;
            }`);


    const svgGroup = svg.append("g");
    let links, nodes, contexts



    const colors = [
        "#dd6b66",
        "#759aa0",
        "#e69d87",
        "#8dc1a9",
        "#ea7e53",
        "#eedd78",
        "#73a373",
        "#73b9bc",
        "#7289ab",
        "#91ca8c",
        "#f49f42"
    ]

    const layout = {
        contextPadding: 60,
        nodeWidth: 320,
        lineHeigth: 30,
        columnGap: 60,
        rowGap: 30,
        columns: 4,
        contextColumns: 1
    }

    const backgroundColors = {
        'text': 'white',
        'node': '#F3F3F3',
        'property': '#595959',
        'context': '#FDFDFD',
        'repository': '#ce6a85',
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
            .attr("y", (_: never, i: number) => 40 + (offset + i) * layout.lineHeigth + layout.lineHeigth / 2)
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
            .text((prop: Property) => prop.name)
            .attr("x", 10)
            .attr("y", (_: never, i: number) => 40 + (offset + i) * layout.lineHeigth + layout.lineHeigth / 2)
            .attr("dy", ".35em")
            .attr("text-anchor", "start")
            .attr("fill", backgroundColors.property)
            // append sibling text with type
            .append("tspan")
            .text((prop: Property) =>
                formatType(prop)
            )
            .attr("text-anchor", "end")
            .attr("dx", 10)
            .attr("fill", backgroundColors.type)
        // .attr("x", function (prop: Property) {
        //     const parent = d3.select(this.parentNode);
        //     const textLength = parent.node().getComputedTextLength();
        //     const selfLength = d3.select(this).node().getComputedTextLength();
        //     const rowLength = textLength + 10 + selfLength

        //     return rowLength > layout.nodeWidth - 10 ? rowLength : layout.nodeWidth - 10;
        // })


    }

    function drawMethods(node: any, methods: Method[], offset: number) {
        const methodsGroup = node.append("g")
            .attr("class", "methods")
            .selectAll("text")
            .data(methods)
            .enter();

        methodsGroup.append("text")
            .attr("x", 10)
            .attr("y", (_: never, i: number) => 40 + (offset + i) * layout.lineHeigth + layout.lineHeigth / 2)
            .attr("dy", ".35em")
            .attr("text-anchor", "start")
            .attr("fill", backgroundColors.property)
            .text((method: Method) => `${method.name}(${method.parameters.map(p => p.name).join(', ')})`)
            .append("tspan")
            .text((method: Method) => formatType(method.return))
            .attr("text-anchor", "end")
            .attr("dx", 10)
            .attr("fill", backgroundColors.type)
    }


    function getBBox(elements) {
        if (elements.size() === 0) {
            return { x: 0, y: 0, width: layout.nodeWidth, height: 0 };
        }

        let minX = Infinity, minY = Infinity, maxX = -Infinity, maxY = -Infinity;

        elements.each(function (d) {
            const bbox = d3.select(this).node().getBBox();

            minX = Math.min(minX, bbox.x + d.position.x);
            minY = Math.min(minY, bbox.y + d.position.y);
            maxX = Math.max(maxX, bbox.x + bbox.width + d.position.x);
            maxY = Math.max(maxY, bbox.y + bbox.height + d.position.y);
        });

        const combinedWidth = maxX - minX;
        const combinedHeight = maxY - minY;

        return { x: minX, y: minY, width: combinedWidth, height: combinedHeight };
    }

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

        if (!isNaN(translate[0]) && !isNaN(translate[1]) && !isNaN(scale)) {
            svgGroup.attr("transform", `translate(${translate[0]}, ${translate[1]}) scale(${scale})`);
        }
    }

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

    function drawDomain(value: Diagram) {
        const domainEntities = [value.aggregates, value.entities, value.valueObjects, value.enums, value.events, value.services, value.repositories].flat()

        nodes = svgGroup.append("g")
            .attr("class", "nodes")
            .selectAll("g")
            .data(domainEntities)
            .enter()
            .append("g")
            .attr("id", d => `node-${d.name}`)
            .attr("class", (d) => `${d.type} context-${d.context}`)
            .on("mouseover", function (event, d) {
                d3.select(this).select("rect").attr("stroke", "black");
                links.each(function (l) {
                    if (l.source === d.name || l.target === d.name) {
                        d3.select(this).attr("stroke", "black").raise();
                    }
                })
            })
            .on("mouseout", function (event, d) {
                d3.select(this).select("rect").attr("stroke", "none");
                links.attr("stroke", "lightgrey");
            })
            .on("click", function (event, d) {
                editor.revealLineInCenter(d.markup.start.row + 1);
                editor.setPosition({ lineNumber: d.markup.start.row + 1, column: d.markup.start.column + 1 });
                editor.focus();
            })

        nodes.append("rect")
            .attr("width", layout.nodeWidth)
            .attr("height", d => 50 + ((d.properties?.length ?? 0) + (d.methods?.length ?? 0) + (d.values?.length ?? 0)) * layout.lineHeigth)
            .attr("fill", backgroundColors.node)
            .attr("rx", 4)
            .attr("ry", 4);

        nodes.append("rect")
            .attr("width", layout.nodeWidth - 2)
            .attr("height", 30)
            .attr("x", "1")
            .attr("y", "1")
            .attr("rx", 3)
            .attr("ry", 3)
            .attr("fill", d => backgroundColors[d.type]);

        nodes.append("text")
            .attr("x", layout.nodeWidth / 2)
            .attr("y", 20)
            .attr("text-anchor", "middle")
            .attr("font-weight", "bold")
            .attr("fill", backgroundColors.text)
            .text(d => d.name);

        svgGroup.selectAll(".aggregate").each(function (d: Aggregate) {
            drawProperties(d3.select(this), d.properties, 0);

            drawMethods(d3.select(this), d.methods, d.properties.length);
        });

        svgGroup.selectAll(".entity").each(function (d) {
            drawProperties(d3.select(this), d.properties, 0);

            drawMethods(d3.select(this), d.methods, d.properties.length);
        });

        svgGroup.selectAll(".value_object").each(function (d) {
            drawProperties(d3.select(this), d.properties, 0);
        });

        svgGroup.selectAll(".repository").each(function (d) {
            drawMethods(d3.select(this), d.methods, 0);
        });

        svgGroup.selectAll(".enum").each(function (d) {
            drawValues(d3.select(this), d.values, 0);
        });

        svgGroup.selectAll(".event").each(function (d) {
            drawProperties(d3.select(this), d.properties, 0);
        });

        svgGroup.selectAll(".service").each(function (d) {
            drawMethods(d3.select(this), d.methods, 0);
        });

        // refresh positions and widths
        nodes.each(function (d) {
            const bounds = d3.select(this).node().getBBox();
            const rects = d3.select(this).selectAll("rect");
            const text = d3.select(this).select("text");

            rects.each(function (d) {
                const self = d3.select(this);
                self.attr("width", bounds.width + 10);
            })

            text.attr("x", (bounds.width + 10) / 2)
        })
    }

    function positionDiagram(value: Diagram) {
        for (const context of value.contexts) {
            const nodes = svgGroup.selectAll(`.context-${context.name}`);
            let heights = new Array(layout.columns).fill(0);
            let xPos = new Array(layout.columns).fill(0);

            nodes.each(function (d, i) {
                const nextColumnIndex = heights.indexOf(Math.min(...heights))
                const nextWidthIndex = (nextColumnIndex + 1) % layout.columns;
                const width = d3.select(this).node().getBBox().width;

                heights[nextColumnIndex] += d3.select(this).node().getBBox().height + layout.rowGap;

                if (nextWidthIndex !== 0 && (width + layout.columnGap) > xPos[nextWidthIndex]) {
                    xPos[nextWidthIndex] = width + layout.columnGap;
                }
            });

            heights = new Array(layout.columns).fill(0);

            nodes.attr("transform", function (d, i) {
                const nextColumnIndex = heights.indexOf(Math.min(...heights));
                // const nextColumnIndex = i % layout.columns;
                const x = xPos.slice(0, nextColumnIndex).reduce((acc, curr) => acc + curr, 0) + xPos[nextColumnIndex];
                const y = heights[nextColumnIndex];

                heights[nextColumnIndex] += d3.select(this).node().getBBox().height + layout.rowGap;

                d.position.x = x;
                d.position.y = y;
                return `translate(${x}, ${y})`;
            })
        }

        let cColWidth = new Array(layout.contextColumns).fill(0);
        let cColHeight = new Array(layout.contextColumns).fill(0);

        contexts.each(function (context: Context, index: number) {
            const sel = d3.select(this);

            const relIndex = index % layout.contextColumns;

            const box = getBBox(svgGroup.selectAll(`.context-${context.name}`));


            cColWidth[relIndex] = Math.max(box.width, cColWidth[relIndex]);

            sel.selectChild('rect')
                .attr('width', box.width + layout.contextPadding)
                .attr('height', box.height + layout.contextPadding)
        })



        contexts.attr("transform", function (d, i) {
            const nextColumnIndex = i % layout.contextColumns;
            const x = cColWidth.slice(0, nextColumnIndex).reduce((acc, curr) => acc + curr, 0) + nextColumnIndex * layout.columnGap * 2
            const y = cColHeight[nextColumnIndex];

            cColHeight[nextColumnIndex] += d3.select(this).node().getBBox().height + layout.contextPadding * 2;

            d.position.x = x
            d.position.y = y

            return `translate(${x}, ${y})`;
        });

        contexts.each(function (context: Context, index: number) {
            const nodes = svgGroup.selectAll(`.context-${context.name}`);

            nodes.attr("transform", function (d, i) {
                d.position.x = d.position.x + context.position.x
                d.position.y = d.position.y + context.position.y
                return `translate(${d.position.x}, ${d.position.y})`;
            });

            nodes.each(function (d) {
                const bounds = d3.select(this).node().getBBox();
                const position = d.position;

                const ports = {
                    top: { x: bounds.width / 2, y: 0, pos: 'top' },
                    right: { x: bounds.width, y: bounds.height / 2, pos: 'right' },
                    bottom: { x: bounds.width / 2, y: bounds.height, pos: 'bottom' },
                    left: { x: 0, y: bounds.height / 2, pos: 'left' }
                };

                const absolutePorts = {
                    top: { x: position.x + ports.top.x, y: position.y + ports.top.y, pos: 'top' },
                    right: { x: position.x + ports.right.x, y: position.y + ports.right.y, pos: 'right' },
                    bottom: { x: position.x + ports.bottom.x, y: position.y + ports.bottom.y, pos: 'bottom' },
                    left: { x: position.x + ports.left.x, y: position.y + ports.left.y, pos: 'left' }
                }

                d.ports = absolutePorts;
            });
        })
    }

    function drawContexts(value: Diagram) {
        layout.contextColumns = Math.ceil(Math.sqrt(value.contexts.length));

        const contextsToRender = value.contexts.filter(c => [c.aggregates, c.entities, c.valueObjects, c.enums, c.services, c.events, c.repositories].flat().length > 0);

        contexts = svgGroup.append("g")
            .attr("class", "contexts")
            .selectAll("g")
            .data(contextsToRender)
            .enter()
            .append("g")
            .attr("id", d => `context-${d.name}`)
            .attr("class", (d) => d.type)

        contexts.each(function (context: Context, index: number) {
            const sel = d3.select(this);

            if (context.id !== 'DEFAULT') {
                sel.append("rect")
                    .attr("fill", `${colors[index % colors.length]}30`)
                    .attr("stroke", `${colors[index % colors.length]}`)
                    .attr("stroke-dasharray", "3 3")
                    .attr("x", -layout.contextPadding / 2)
                    .attr("y", -layout.contextPadding / 2)
                    .attr("rx", 4)
                    .attr("ry", 4);
            } else {
                sel.append("rect")
                    .attr("fill", 'none')
                    .attr("stroke", 'none')
                    .attr("x", -layout.contextPadding / 2)
                    .attr("y", -layout.contextPadding / 2)
                    .attr("rx", 4)
                    .attr("ry", 4);
            }

            if (context.id !== 'DEFAULT') {
                sel.append("text")
                    .attr("y", -(layout.contextPadding / 2) + 5)
                    .attr("text-anchor", "start")
                    .attr("font-weight", "bold")
                    .attr("fill", backgroundColors.property)
                    .text(d => d.name);
            }
        })
    }

    function draw(value: Diagram) {
        diagram = value

        const domainEntitiesToLink = [value.aggregates, value.entities, value.valueObjects, value.enums].flat()

        const domainLinks = domainEntitiesToLink.map(domain => {
            const connections = []

            domain.properties?.forEach(prop => {
                connections.push({
                    source: domain.name, target: domainEntitiesToLink.find(e => {
                        if ('id' in e) return prop.type === e.id;
                        if ('ids' in e) return e.ids.includes(prop.type);
                        return false;
                    })?.name,
                    type: 'solid'
                })
            })

            domain.methods?.forEach(method => {
                method.emits?.events.forEach(eventName => {
                    connections.push({
                        source: domain.name, target: value.events.find(e => e.type == 'event' && e.name === eventName)?.name, type: 'dashed'
                    })
                })
            })

            return connections

        }).flat().filter(link => Boolean(link) && Boolean(link.target) && link.source !== link.target);

        drawContexts(value);

        links = svgGroup.append("g")
            .attr("class", "links")
            .selectAll("path")
            .data(domainLinks)
            .enter()
            .append("path")
            .attr("stroke", "lightgrey")
            .attr("stroke-width", 1)
            .attr("fill", "none")
            .attr("stroke-dasharray", d => d.type === 'dashed' ? "5" : "none");

        drawDomain(value);

        positionDiagram(value);

        links.attr("d", function (d) {
            const sourceNode = d3.select(`#node-${d.source}`).datum();
            const targetNode = d3.select(`#node-${d.target}`).datum();

            const sourcePorts = sourceNode.ports
            const targetPorts = targetNode.ports;

            const closestPorts = findClosestPorts(sourcePorts, targetPorts);

            const isHorizontal = sourcePorts[closestPorts.source].pos === 'right' || sourcePorts[closestPorts.source].pos === 'left';

            const link = isHorizontal ? d3.linkHorizontal() : d3.linkVertical();

            return link
                .source(() => [sourcePorts[closestPorts.source].x, sourcePorts[closestPorts.source].y])
                .target(() => [targetPorts[closestPorts.target].x, targetPorts[closestPorts.target].y])();
        });

        if (!fixed) {
            zoomToFit();
        }
    }

    if (value) {
        draw(value);
    }

    return {
        update(value: Diagram) {
            if (_.isUndefined(value)) {
                return;
            }

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
