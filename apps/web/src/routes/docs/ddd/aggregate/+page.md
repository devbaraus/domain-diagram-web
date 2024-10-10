# Aggregate / AggregateRoot

## Concept

An **Aggregate** or **AggregateRoot** is a cluster of related objects that are treated as a single unit. Aggregates ensure that all the changes to related objects are consistent. The AggregateRoot is the entry point, ensuring the integrity of the entire aggregate.

## Usage

```ddd
Aggregate Order {
  name: CategoryName
  slug: Slug
  companyId: CompanyID
  parentId: CategoryID
  childrenIds: CategoryID[]
  isActive: boolean
  createdAt: Date
  updatedAt: Date?
  deletedAt: Date?
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