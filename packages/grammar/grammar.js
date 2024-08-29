/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'ddd',

  rules: {
    // Entry point
    source_file: $ => repeat($._definition),

    // Definitions
    _definition: $ => choice(
      $.aggregate,
      $.entity,
      $.value_object,
      $.enum
    ),

    // Aggregate definition (with optional generic type)
    aggregate: $ => seq(
      'aggregate',
      optional($.generic_type),
      $.identifier,
      '{',
      repeat($.field),
      '}'
    ),

    // Entity definition (with optional generic type)
    entity: $ => seq(
      'entity',
      optional($.generic_type),
      $.identifier,
      '{',
      repeat($.field),
      '}'
    ),

    // Value Object definition
    value_object: $ => seq(
      'value_object',
      $.identifier,
      '{',
      repeat($.field),
      '}'
    ),

    // Enum definition
    enum: $ => seq(
      'enum',
      $.identifier,
      '{',
      repeat($.enum_value),
      '}'
    ),

    // Enum values inside enum definition
    enum_value: $ => $.identifier,

    // Field definition
    field: $ => seq(
      $.identifier,
      ':',
      $.type
    ),

    // Generic type definition
    generic_type: $ => seq(
      '<',
      $.identifier,
      '>'
    ),

    // Type definition (e.g., String, Int, UUID, TaskID[])
    type: $ => seq(
      $.identifier,
      optional('[]')
    ),

    // Identifier (names for types, fields, entities, etc.)
    identifier: $ => /[a-zA-Z_]\w*/
  }
});


