# Context / BoundedContext

## Concept

A **Bounded Context** is a logical boundary within which a specific domain model applies. It helps divide the problem space into distinct areas where concepts have specific meanings. In Domain-Driven Design, this is crucial for managing complexity by keeping models isolated and reducing coupling.

## Usage

```ddd
Context Inventory {
  // Aggregates, Entities, and other components go here
}

```

```ddd
BoundedContext Shipping {
  // Define entities, aggregates, services, etc. within this context
}

```

---

In the grammar:

A **Context** or **BoundedContext** is defined with an identifier (name) followed by a body of components like Aggregates, Entities, etc.