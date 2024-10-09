# Entity

## Concept

An **Entity** is an object that has a distinct identity, which continues to exist throughout its lifecycle, even when its attributes change. It is uniquely identified, usually by an ID.

## Usage

```ddd
Entity Product {
  productId: UUID
  name: String
  price: Float
  updatePrice(newPrice: Float): Void
}
```

---

In the grammar:

The **Entity** keyword is followed by an identifier (name) and a body that contains fields and methods.