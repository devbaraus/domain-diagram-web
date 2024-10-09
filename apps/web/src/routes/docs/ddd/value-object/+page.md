# Value Object

## Concept

A **Value Object** is an object that is defined by its attributes rather than a unique identity. They are immutable, and two Value Objects are considered equal if all their attributes are the same.

## Usage

```ddd
DomainEvent OrderPlaced {
  orderId: UUID
  customerId: UUID
  totalAmount: Float
}
```

```ddd
Event ProductShipped {
  productId: UUID
  shippingDate: Date
}

```

---

In the grammar:

**DomainEvent** or **Event** is followed by an identifier (name) and a body containing the event’s fields.