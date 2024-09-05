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
        "Context",
        $.identifier,
        "{",
        repeat(
          choice(
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

    // Aggregate definition (with optional generic type)
    aggregate: ($) =>
      seq(
        "AggregateRoot",
        $.generic_type,
        $.identifier,
        "{",
        repeat(choice($.field, $.method)),
        "}",
      ),

    // Entity definition (with optional generic type)
    entity: ($) =>
      seq(
        "Entity",
        $.generic_type,
        $.identifier,
        "{",
        repeat(choice($.field, $.method)),
        "}",
      ),

    // Value Object definition
    value_object: ($) =>
      seq("ValueObject", $.identifier, "{", repeat($.field), "}"),

    // Event definition
    event: ($) => seq("Event", $.identifier, "{", repeat($.field), "}"),

    // Service definition
    service: ($) => seq("Service", $.identifier, "{", repeat($.method), "}"),

    // Repository definition
    repository: ($) =>
      seq("Repository", $.identifier, "{", repeat($.method), "}"),

    // Enum definition
    enum: ($) => seq("Enum", $.identifier, "{", repeat($.identifier), "}"),

    // Enum values inside enum definition
    // enum_value: ($) => $.identifier,

    // Method definition
    method: ($) =>
      seq($.identifier, "(", $.method_param, ")", optional(seq(":", $.type))),

    method_param: ($) =>
      seq(
        $.field,
        optional(seq("=", $.value)),
        optional(seq(",", $.method_param)),
      ),

    // Field definition
    field: ($) => seq($.identifier, ":", $.type),

    // Generic type definition
    generic_type: ($) => seq("<", $.identifier, ">"),

    // Type definition (e.g., String, Int, UUID, TaskID[], TaskID?)
    type: ($) => choice($.primitive_type, $.array_type, $.nullable_type),

    // Type definition (e.g., String, Int, UUID)
    primitive_type: ($) => $.identifier,

    // Array type definition (e.g., TaskID[])
    array_type: ($) => seq($.primitive_type, "[]"),

    // Nullable type definition (e.g., TaskID?)
    nullable_type: ($) => seq($.primitive_type, "?"),

    // Identifier (names for types, fields, entities, etc.)
    identifier: ($) => /[a-zA-Z_]\w*/,

    value: ($) => choice($.string, $.number, $.boolean, $.null),

    string: ($) => /"[^"]*"/,

    number: ($) => /\d+/,

    boolean: ($) => choice("true", "false"),

    null: ($) => "null",
  },
});
