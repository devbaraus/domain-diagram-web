/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'ddd',

  rules: {
    // The main rule for the file
    source_file: $ => repeat($._definition),

    // A definition can be an aggregate, value object, or entity
    _definition: $ => choice(
      $.aggregate,
      $.value_object,
      $.entity
    ),

    // Definition of an aggregate
    aggregate: $ => seq(
      'aggregate',
      $.identifier,
      '{',
      repeat($.property),
      '}'
    ),

    // Definition of a value object
    value_object: $ => seq(
      'value_object',
      $.identifier,
      '{',
      repeat($.value_declaration),
      '}'
    ),

    // Definition of an entity
    entity: $ => seq(
      'entity',
      $.identifier,
      '{',
      repeat($.property),
      '}'
    ),

    // Property definition within aggregates and entities
    property: $ => seq(
      $.identifier,
      ':',
      $.type,
      optional($.array_modifier)
    ),

    // Value declaration within value objects
    value_declaration: $ => seq(
      'value',
      $.identifier
    ),

    // Identifier (names for aggregates, entities, properties, etc.)
    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    // Type (basic types like UUID, String, Boolean, etc.)
    type: $ => choice(
      'UUID',
      'String',
      'Boolean',
      'Float',
      'Int',
      'Date',
      $.identifier // Allows for custom types like Task.id
    ),

    // Array modifier (for defining arrays of properties)
    array_modifier: $ => seq(
      '[',
      ']'
    )
  }
});


