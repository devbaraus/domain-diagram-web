<script lang="ts">
	import { diagram } from '$lib/actions/diagram';
	import type { SyntaxNode, Tree } from 'web-tree-sitter';

	type Props = {
		tree: Tree | undefined;
	};

	let { tree }: Props = $props();

	function extractEntities(node: SyntaxNode | undefined): Entity[] {
		if (!node) {
			return [];
		}

		const entities: Entity[] = [];

		node.children.forEach((child, index) => {
			if (['aggregate', 'entity', 'value_object', 'enum'].includes(child.type)) {
				const entity: Entity = {
					id: child.child(1)?.text.replaceAll('<', '').replaceAll('>', ''),
					name: ['aggregate', 'entity'].includes(child.type)
						? child.child(2)?.text
						: child.child(1)?.text,
					type: child.type,
					values: [],
					properties: [],
					position: {
						x: 0,
						y: 0,
						width: 0,
						height: 0
					}
				};

				child.children.forEach((grandchild) => {
					if (grandchild.type === 'enum_value') {
						entity.values.push(grandchild.child(0)?.text);
					}

					if (grandchild.type === 'field') {
						entity.properties.push({
							name: grandchild.child(0)?.text,
							type: grandchild.child(2)?.text
						});
					}

					entity.position = {
						x: index * 200,
						y: 100,
						width: 200,
						height: 100
					};
				});

				entities.push(entity);
			}
		});

		return entities;
	}
</script>

<div width="800" height="600" use:diagram={extractEntities(tree?.rootNode)}></div>

<style>
	.entity {
		fill: lightblue;
		stroke: steelblue;
		stroke-width: 2px;
	}

	.property {
		font: 12px sans-serif;
	}

	.entity-label {
		font-weight: bold;
	}
</style>
