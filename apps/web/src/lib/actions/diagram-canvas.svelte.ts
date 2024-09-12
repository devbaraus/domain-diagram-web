import { editor } from '$lib/store';
import _ from 'lodash';

export function diagram(el: HTMLDivElement, value: Diagram) {
    let diagram: Diagram = value;
    let editor = null;
    let fixed = false;
    const canvas = document.createElement('canvas');
    const ctx = canvas.getContext('2d');

    canvas.width = el.getBoundingClientRect().width;
    canvas.height = el.getBoundingClientRect().height;

    el.appendChild(canvas);

    const nodeWidth = 320;
    const lineHeight = 30;
    const columnGap = 60;
    const rowGap = 60;
    const columns = 4;

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

    function formatType(type) {
        return `${type.type}${type.nullable ? '?' : ''}${type.array ? '[]' : ''}`;
    }

    function drawText(text, x, y, color, align = 'left') {
        ctx.fillStyle = color;
        ctx.textAlign = align;
        ctx.fillText(text, x, y);
    }

    function drawRect(x, y, width, height, color) {
        ctx.fillStyle = color;
        ctx.fillRect(x, y, width, height);
    }

    function drawProperties(node, properties, offset, x, y) {
        properties.forEach((prop, i) => {
            drawText(prop.name, x + 10, y + (offset + i) * lineHeight + lineHeight / 2, backgroundColors.property);
            drawText(formatType(prop), x + nodeWidth - 10, y + (offset + i) * lineHeight + lineHeight / 2, backgroundColors.type, 'right');
        });
    }

    function drawMethods(node, methods, offset, x, y) {
        methods.forEach((method, i) => {
            drawText(`${method.name}(${method.parameters.map(p => p.name).join(', ')})`, x + 10, y + (offset + i) * lineHeight + lineHeight / 2, backgroundColors.property);
            drawText(formatType(method.return), x + nodeWidth - 10, y + (offset + i) * lineHeight + lineHeight / 2, backgroundColors.type, 'right');
        });
    }

    function drawNode(node, x, y) {
        const nodeHeight = 50 + ((node.properties?.length ?? 0) + (node.methods?.length ?? 0) + (node.values?.length ?? 0)) * lineHeight;
        drawRect(x, y, nodeWidth, nodeHeight, backgroundColors.node);

        // Draw header
        drawRect(x + 1, y + 1, nodeWidth - 2, 30, backgroundColors[node.type]);
        drawText(node.name, x + nodeWidth / 2, y + 20, backgroundColors.text, 'center');

        // Draw properties and methods
        if (node.properties) {
            drawProperties(node, node.properties, 0, x, y + 40);
        }
        if (node.methods) {
            drawMethods(node, node.methods, node.properties.length, x, y + 40);
        }
    }

    function drawNodes(entities) {
        let columnHeights = new Array(columns).fill(0);
        entities.forEach((node, i) => {
            const columnIndex = i % columns;
            const x = columnIndex * (nodeWidth + columnGap);
            const y = columnHeights[columnIndex];

            columnHeights[columnIndex] += 50 + ((node.properties?.length ?? 0) + (node.methods?.length ?? 0)) * lineHeight + rowGap;

            node.position = { x, y };
            drawNode(node, x, y);
        });
    }

    function drawLinks(links, entities) {
        links.forEach(link => {
            const sourceNode = entities.find(e => e.name === link.source);
            const targetNode = entities.find(e => e.name === link.target);

            if (sourceNode && targetNode) {
                ctx.beginPath();
                ctx.moveTo(sourceNode.position.x + nodeWidth / 2, sourceNode.position.y + 30);
                ctx.lineTo(targetNode.position.x + nodeWidth / 2, targetNode.position.y + 30);
                ctx.strokeStyle = "lightgrey";
                ctx.lineWidth = 1;
                ctx.stroke();
            }
        });
    }

    function draw(value) {
        diagram = value;
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        
        const domainEntities = [value.aggregates, value.entities, value.valueObjects, value.enums, value.events, value.services].flat();
        const links = domainEntities.map(domain => domain.properties?.map(prop => ({
            source: domain.name,
            target: domainEntities.find(e => e.id === prop.type)?.name
        })).flat()).flat().filter(link => link && link.target);

        drawNodes(domainEntities);
        drawLinks(links, domainEntities);
    }

    return {
        update(value: Diagram) {
            if (_.isEqual(value, diagram)) {
                return;
            }
            draw(value);
        },
        destroy() {
            el.removeChild(canvas);
        }
    };
}
