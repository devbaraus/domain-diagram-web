import * as d3 from 'd3';
import { on } from 'svelte/events';
import type { SyntaxNode, Tree, Node } from 'web-tree-sitter';

type Entity = {
    id: string,
    description?: string | null;
    name?: string | null;
    type?: string | null;
    values: string[];
    properties: {
        name?: string | null;
        type?: string | null;
    }[];
    methods: {
        name?: string | null;
        parameters: {
            name?: string | null;
            type?: string | null;
        }[];
        returnType?: string | null;
    }[];
    position?: {
        x: number;
        y: number;
        width: number;
        height: number;
    };
};

export function diagram(el: HTMLDivElement, entities: Entity[]) {
    const svg = d3.select(el)
        .append("svg")
        .attr("width", '70dvw')
        .attr("height", window.innerHeight)
        .attr("viewBox", `0 0 ${window.innerWidth} ${window.innerHeight}`)

    // Definições do grid
    const gridSize = 200; // Tamanho de cada célula do grid
    const columns = Math.floor(window.innerWidth / gridSize); // Número de colunas na tela
    let node, link, simulation, entitiesData, entitiesLinks;
    const lineHeigth = 30;
    const nodeWidth = 240;

    const backgroundColors = {
        'text': 'white',
        'node': '#F3F3F3',
        'property': '#595959',
        'type': '#8c8c8c',
        "aggregate": "#1f78b4",
        "entity": "#33a02c",
        "enum": "#e31a1c",
        "value_object": "#ff7f00"
    }


    function draw(entities: Entity[]) {
        entitiesLinks = entities.map((entity, i) => {
            return entity.properties.map((prop, j) => {
                const propType = prop.type?.replaceAll('[', '').replaceAll(']', '');

                return { source: entity.id, target: entities.find(e => e.id === propType || e.name == propType)?.id };
            }).filter(link => link.target !== undefined);
        }).flat();


        simulation = d3.forceSimulation(entities)
            .force("link", d3.forceLink(entitiesLinks).id((d: Entity) => d.id))
            .force("collide", d3.forceCollide(180).iterations(50))
            .force("charge", d3.forceManyBody().strength(-20))
            .force("center", d3.forceCenter(window.innerWidth / 2, window.innerHeight / 2))
            .force("y", d3.forceY(0))
            .force("x", d3.forceX(0));

        link = svg.append("g")
            .attr("class", "links")
            .selectAll("line")
            .data(entitiesLinks)
            .enter()
            .append("line")
            .attr("stroke", "black")
            .attr("stroke-width", 1);

        node = svg.append("g")
            .attr("class", "nodes")
            .selectAll("g")
            .data(entities)
            .enter()
            .append("g");

        // Adiciona o retângulo do nó
        node.append("rect")
            .attr("width", nodeWidth)
            .attr("height", (d) => 50 + (d.properties.length + d.values?.length) * lineHeigth)
            .attr("fill", backgroundColors.node)
            .attr("rx", 4)
            .attr("ry", 4);

        node.append("rect")
            .attr("width", nodeWidth)
            .attr("height", 30)
            .attr("fill", d => backgroundColors[d.type])
        // .attr("rx", 4)
        // .attr("ry", 4)

        node.append("text")
            .attr("x", nodeWidth / 2) // Centraliza horizontalmente
            .attr("y", 20)  // Posiciona no topo do retângulo
            // .attr("dy", ".35em")
            .attr("text-anchor", "middle")
            .attr("font-weight", "bold")
            .attr("fill", backgroundColors.text)
            .text(d => d.name);


        // Adiciona propriedades ao nó
        node.each(function (d) {
            const props = d3.select(this).selectAll(".property")
                .data(d.properties)
                .enter()

            props.append("rect")
                .attr("width", nodeWidth)
                .attr("height", lineHeigth)
                .attr("x", 0) // Margem à esquerda dentro do retângulo
                .attr("y", function (prop, i) {
                    // Espaçamento entre cada propriedade
                    return (50 - lineHeigth / 2) + i * lineHeigth;
                })
                .attr("fill", backgroundColors.node)
            // .on("mouseover", function (event, prop) {
            //     d3.select(this).attr("fill", "lightblue");
            // })
            // .on("mouseout", function (event, prop) {
            //     d3.select(this).attr("fill", backgroundColors.node);
            // })
            // .attr("stroke", "#316896")

            props.append("text")
                .attr("class", "property")
                .attr("x", 10) // Margem à esquerda dentro do retângulo
                .attr("y", function (prop, i) {
                    // Espaçamento entre cada propriedade
                    return 50 + i * lineHeigth;
                })
                .attr("dy", ".35em")
                .attr("text-anchor", "start")
                .attr("fill", backgroundColors.property)
                .text(function (prop) {
                    return `${prop.name}`;
                });

            props.append("text")
                .attr("class", "property")
                .attr("x", nodeWidth - 10) // Margem à esquerda dentro do retângulo
                .attr("y", function (prop, i) {
                    // Espaçamento entre cada propriedade
                    return 50 + i * lineHeigth;
                })
                .attr("dy", ".35em")
                .attr("text-anchor", "end")
                .attr("fill", backgroundColors.type)
                .text(function (prop) {
                    return `${prop.type}`;
                });

        });

        // Adiciona valores enum ao nó
        node.each(function (d) {
            const props = d3.select(this).selectAll(".value")
                .data(d.values)
                .enter()

            props.append("rect")
                .attr("width", nodeWidth)
                .attr("height", lineHeigth)
                .attr("x", 0) // Margem à esquerda dentro do retângulo
                .attr("y", function (prop, i) {
                    // Espaçamento entre cada propriedade
                    return (50 - lineHeigth / 2) + i * lineHeigth;
                })
                .attr("fill", backgroundColors.node)
            // .on("mouseover", function (event, prop) {
            //     d3.select(this).attr("fill", "lightblue");
            // })
            // .on("mouseout", function (event, prop) {
            //     d3.select(this).attr("fill", backgroundColors.node);
            // })
            // .attr("stroke", "#316896")

            props.append("text")
                .attr("class", "value")
                .attr("x", 10) // Margem à esquerda dentro do retângulo
                .attr("y", function (prop, i) {
                    // Espaçamento entre cada propriedade
                    return 50 + i * lineHeigth;
                })
                .attr("dy", ".35em")
                .attr("text-anchor", "start")
                .attr("fill", backgroundColors.property)
                .text(v => v);

            // props.append("text")
            //     .attr("class", "property")
            //     .attr("x", nodeWidth - 10) // Margem à esquerda dentro do retângulo
            //     .attr("y", function (prop, i) {
            //         // Espaçamento entre cada propriedade
            //         return 50 + i * lineHeigth;
            //     })
            //     .attr("dy", ".35em")
            //     .attr("text-anchor", "end")
            //     .attr("fill", backgroundColors.type)
            //     .text(function (prop) {
            //         return `${prop.type}`;
            //     });

        });

        // Posiciona os nós em uma grade
        // node.attr("transform", function (d, i) {
        //     const x = (i % columns) * gridSize + gridSize / 2 - 100; // Calcula a posição x
        //     const y = Math.floor(i / columns) * gridSize + gridSize / 2 - 50; // Calcula a posição y
        //     d.x = x; // Define a posição x no objeto para uso nos links
        //     d.y = y; // Define a posição y no objeto para uso nos links
        //     return `translate(${x}, ${y})`;
        // });

        // // Atualiza a posição dos links após posicionar os nós
        // svg.selectAll("line")
        //     .attr("x1", d => entities[d.source].x + 100)
        //     .attr("y1", d => entities[d.source].y + (25 + entities[d.source].properties.length * 10))
        //     .attr("x2", d => entities[d.target].x + 100)
        //     .attr("y2", d => entities[d.target].y + (25 + entities[d.target].properties.length * 10));

        // simulation.nodes(entities)
        //     .on("tick", () => {
        //         node.attr("transform", function (d) {
        //             return `translate(${d.x - 75}, ${d.y - 25})`;
        //         });
        //     });

        // Atualiza posições com base na simulação de força
        simulation.on("tick", () => {
            node.attr("transform", (d: any) => `translate(${d.x - 100}, ${d.y - 25})`);

            link.attr("x1", d => d.source.x)
                .attr("y1", d => d.source.y)
                .attr("x2", d => d.target.x)
                .attr("y2", d => d.target.y);
        });
    }



    return {
        update(entities: Entity[]) {
            entitiesData = entities;
            svg.selectAll('*').remove();
            draw(entitiesData);
        },
        destroy() {
            svg.remove();
            console.log('destroy');
        }
    };
}