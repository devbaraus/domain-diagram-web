# Aggregate / AggregateRoot

## Concept

An **Aggregate** or **AggregateRoot** is a cluster of related objects that are treated as a single unit. Aggregates ensure that all the changes to related objects are consistent. The AggregateRoot is the entry point, ensuring the integrity of the entire aggregate.

## Usage

```ddd
Aggregate Order {
  orderId: UUID
  status: String
  totalAmount: Float
  addItem(item: Item): Void
}
```

```ddd
AggregateRoot Customer {
  customerId: UUID
  name: String
  changeAddress(address: Address): Void
}
```

---

In the grammar:

**Aggregate** or **AggregateRoot** is followed by an identifier (name) and a body containing fields and methods.