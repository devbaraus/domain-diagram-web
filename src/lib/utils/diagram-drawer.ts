export function drawAggregates(node: any, aggregates: any) {
    aggregates.forEach((aggregate: any) => {
        node.addAggregate(aggregate);
    });

}