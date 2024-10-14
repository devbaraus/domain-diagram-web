/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "ddd",

  rules: {
    // Entry point
    source_file: ($) => repeat($._definition),

    // Definitions
    _definition: ($) =>
      choice(
        $.comment,
        $.aggregate,
        $.entity,
        $.value_object,
        $.enum,
        $.event,
        $.service,
        $.repository,
        $.context,
      ),

    // Context definition
    context: ($) =>
      seq(
        choice("Context", "BoundedContext"),
        $.identifier,
        "{",
        repeat(
          choice(
            $.comment,
            $.aggregate,
            $.entity,
            $.value_object,
            $.enum,
            $.event,
            $.service,
            $.repository,
          ),
        ),
        "}",
      ),

    comment: ($) => token(seq("//", /.*/)),

    // Aggregate definition (with optional generic type)
    aggregate: ($) =>
      seq(
        choice("Aggregate", "AggregateRoot"),
        optional($.generic_type),
        $.identifier,
        "{",
        repeat(choice($.field, $.method_emitter, $.comment)),
        "}",
      ),




    // Entity definition (with optional generic type)
    entity: ($) =>
      seq(
        "Entity",
        optional($.generic_type),
        $.identifier,
        "{",
        repeat(choice($.field, $.method_note, $.comment)),
        "}",
      ),

    // Value Object definition
    value_object: ($) =>
      seq("ValueObject", $.identifier, "{", repeat(choice($.field, $.comment)), "}"),

    // Event definition
    event: ($) =>
      seq(
        choice("DomainEvent", "Event"),
        $.identifier,
        "{",
        repeat(choice($.field, $.comment)),
        "}",
      ),

    // Service definition
    service: ($) =>
      seq(
        choice("DomainService", "Service"),
        $.identifier,
        "{",
        repeat(choice($.method_note, $.comment)),
        "}",
      ),

    // Repository definition
    repository: ($) =>
      seq("Repository", $.identifier, "{", repeat($.method_note), "}"),

    // Enum definition
    enum: ($) => seq("Enum", $.identifier, "{", repeat(choice($.enum_value, $.comment)), "}"),

    // Enum values inside enum definition
    enum_value: ($) => seq($.identifier, optional($.annotation_note)),

    annotation_emitter: ($) => seq("@emits(", seq($.identifier, optional(repeat(seq(",", $.identifier)))), ')'),

    annotation_note: ($) => seq("@note(", $.string, ")"),

    // Method definition
    method: ($) =>
      seq(
        $.identifier,
        "(",
        optional(seq($.field, optional(repeat(seq(",", $.field))))),
        ")",
        optional(seq(":", $.type)),
      )
    ,

    method_emitter: ($) => seq($.method, optional(repeat(choice($.annotation_emitter, $.annotation_note)))),

    method_note: ($) => seq($.method, optional($.annotation_note)),

    // Field definition
    field: ($) => seq(seq($.identifier, ":", $.type, optional(seq("=", $.value))), optional($.annotation_note)),

    // Generic type definition
    generic_type: ($) => seq("<", $.identifier, ">"),

    // Type definition (e.g., String, Int, UUID, TaskID[], TaskID?)
    type: ($) =>
      choice($.reference_type, $.primitive_type, $.array_type, $.nullable_type),

    // Reference to another type (e.g., TaskID)
    reference_type: ($) => $.identifier,

    // Type definition (e.g., String, Int, UUID)
    primitive_type: ($) =>
      choice(
        "String",
        "Int",
        "UUID",
        "Boolean",
        "Int",
        "Float",
        "Date",
        "Null",
        "Void",
      ),

    // Array type definition (e.g., String[])
    array_type: ($) => seq(choice($.reference_type, $.primitive_type), "[]"),

    // Nullable type definition (e.g., String?)
    nullable_type: ($) => seq(choice($.reference_type, $.primitive_type), "?"),

    // Identifier (names for types, fields, entities, etc.)
    identifier: ($) => /[a-zA-Z_]\w*/,

    value: ($) => choice($.string, $.number, $.boolean, $.array, $.null),

    string: ($) => /"[^"]*"/,

    array: ($) =>
      seq(
        "[",
        optional(seq($.value, optional(repeat(seq(",", $.value))))),
        "]",
      ),

    number: ($) => /-?\d+(\.\d+)?/,

    boolean: ($) => choice("true", "false"),

    null: ($) => "null",
  },
});
