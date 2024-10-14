#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 132
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 81
#define ALIAS_COUNT 0
#define TOKEN_COUNT 43
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_Context = 1,
  anon_sym_BoundedContext = 2,
  anon_sym_LBRACE = 3,
  anon_sym_RBRACE = 4,
  sym_comment = 5,
  anon_sym_Aggregate = 6,
  anon_sym_AggregateRoot = 7,
  anon_sym_Entity = 8,
  anon_sym_ValueObject = 9,
  anon_sym_DomainEvent = 10,
  anon_sym_Event = 11,
  anon_sym_DomainService = 12,
  anon_sym_Service = 13,
  anon_sym_Repository = 14,
  anon_sym_Enum = 15,
  anon_sym_ATemits_LPAREN = 16,
  anon_sym_COMMA = 17,
  anon_sym_RPAREN = 18,
  anon_sym_ATnote_LPAREN = 19,
  anon_sym_LPAREN = 20,
  anon_sym_COLON = 21,
  anon_sym_EQ = 22,
  anon_sym_LT = 23,
  anon_sym_GT = 24,
  anon_sym_String = 25,
  anon_sym_Int = 26,
  anon_sym_UUID = 27,
  anon_sym_Boolean = 28,
  anon_sym_Float = 29,
  anon_sym_Date = 30,
  anon_sym_Null = 31,
  anon_sym_Void = 32,
  anon_sym_LBRACK_RBRACK = 33,
  anon_sym_QMARK = 34,
  sym_identifier = 35,
  sym_string = 36,
  anon_sym_LBRACK = 37,
  anon_sym_RBRACK = 38,
  sym_number = 39,
  anon_sym_true = 40,
  anon_sym_false = 41,
  sym_null = 42,
  sym_source_file = 43,
  sym__definition = 44,
  sym_context = 45,
  sym_aggregate = 46,
  sym_entity = 47,
  sym_value_object = 48,
  sym_event = 49,
  sym_service = 50,
  sym_repository = 51,
  sym_enum = 52,
  sym_enum_value = 53,
  sym_annotation_emitter = 54,
  sym_annotation_note = 55,
  sym_method = 56,
  sym_method_emitter = 57,
  sym_method_note = 58,
  sym_field = 59,
  sym_generic_type = 60,
  sym_type = 61,
  sym_reference_type = 62,
  sym_primitive_type = 63,
  sym_array_type = 64,
  sym_nullable_type = 65,
  sym_value = 66,
  sym_array = 67,
  sym_boolean = 68,
  aux_sym_source_file_repeat1 = 69,
  aux_sym_context_repeat1 = 70,
  aux_sym_aggregate_repeat1 = 71,
  aux_sym_entity_repeat1 = 72,
  aux_sym_value_object_repeat1 = 73,
  aux_sym_service_repeat1 = 74,
  aux_sym_repository_repeat1 = 75,
  aux_sym_enum_repeat1 = 76,
  aux_sym_annotation_emitter_repeat1 = 77,
  aux_sym_method_repeat1 = 78,
  aux_sym_method_emitter_repeat1 = 79,
  aux_sym_array_repeat1 = 80,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_Context] = "Context",
  [anon_sym_BoundedContext] = "BoundedContext",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_comment] = "comment",
  [anon_sym_Aggregate] = "Aggregate",
  [anon_sym_AggregateRoot] = "AggregateRoot",
  [anon_sym_Entity] = "Entity",
  [anon_sym_ValueObject] = "ValueObject",
  [anon_sym_DomainEvent] = "DomainEvent",
  [anon_sym_Event] = "Event",
  [anon_sym_DomainService] = "DomainService",
  [anon_sym_Service] = "Service",
  [anon_sym_Repository] = "Repository",
  [anon_sym_Enum] = "Enum",
  [anon_sym_ATemits_LPAREN] = "@emits(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_ATnote_LPAREN] = "@note(",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_String] = "String",
  [anon_sym_Int] = "Int",
  [anon_sym_UUID] = "UUID",
  [anon_sym_Boolean] = "Boolean",
  [anon_sym_Float] = "Float",
  [anon_sym_Date] = "Date",
  [anon_sym_Null] = "Null",
  [anon_sym_Void] = "Void",
  [anon_sym_LBRACK_RBRACK] = "[]",
  [anon_sym_QMARK] = "\?",
  [sym_identifier] = "identifier",
  [sym_string] = "string",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_number] = "number",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_null] = "null",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_context] = "context",
  [sym_aggregate] = "aggregate",
  [sym_entity] = "entity",
  [sym_value_object] = "value_object",
  [sym_event] = "event",
  [sym_service] = "service",
  [sym_repository] = "repository",
  [sym_enum] = "enum",
  [sym_enum_value] = "enum_value",
  [sym_annotation_emitter] = "annotation_emitter",
  [sym_annotation_note] = "annotation_note",
  [sym_method] = "method",
  [sym_method_emitter] = "method_emitter",
  [sym_method_note] = "method_note",
  [sym_field] = "field",
  [sym_generic_type] = "generic_type",
  [sym_type] = "type",
  [sym_reference_type] = "reference_type",
  [sym_primitive_type] = "primitive_type",
  [sym_array_type] = "array_type",
  [sym_nullable_type] = "nullable_type",
  [sym_value] = "value",
  [sym_array] = "array",
  [sym_boolean] = "boolean",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_context_repeat1] = "context_repeat1",
  [aux_sym_aggregate_repeat1] = "aggregate_repeat1",
  [aux_sym_entity_repeat1] = "entity_repeat1",
  [aux_sym_value_object_repeat1] = "value_object_repeat1",
  [aux_sym_service_repeat1] = "service_repeat1",
  [aux_sym_repository_repeat1] = "repository_repeat1",
  [aux_sym_enum_repeat1] = "enum_repeat1",
  [aux_sym_annotation_emitter_repeat1] = "annotation_emitter_repeat1",
  [aux_sym_method_repeat1] = "method_repeat1",
  [aux_sym_method_emitter_repeat1] = "method_emitter_repeat1",
  [aux_sym_array_repeat1] = "array_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_Context] = anon_sym_Context,
  [anon_sym_BoundedContext] = anon_sym_BoundedContext,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_comment] = sym_comment,
  [anon_sym_Aggregate] = anon_sym_Aggregate,
  [anon_sym_AggregateRoot] = anon_sym_AggregateRoot,
  [anon_sym_Entity] = anon_sym_Entity,
  [anon_sym_ValueObject] = anon_sym_ValueObject,
  [anon_sym_DomainEvent] = anon_sym_DomainEvent,
  [anon_sym_Event] = anon_sym_Event,
  [anon_sym_DomainService] = anon_sym_DomainService,
  [anon_sym_Service] = anon_sym_Service,
  [anon_sym_Repository] = anon_sym_Repository,
  [anon_sym_Enum] = anon_sym_Enum,
  [anon_sym_ATemits_LPAREN] = anon_sym_ATemits_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_ATnote_LPAREN] = anon_sym_ATnote_LPAREN,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_String] = anon_sym_String,
  [anon_sym_Int] = anon_sym_Int,
  [anon_sym_UUID] = anon_sym_UUID,
  [anon_sym_Boolean] = anon_sym_Boolean,
  [anon_sym_Float] = anon_sym_Float,
  [anon_sym_Date] = anon_sym_Date,
  [anon_sym_Null] = anon_sym_Null,
  [anon_sym_Void] = anon_sym_Void,
  [anon_sym_LBRACK_RBRACK] = anon_sym_LBRACK_RBRACK,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [sym_identifier] = sym_identifier,
  [sym_string] = sym_string,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_number] = sym_number,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_null] = sym_null,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_context] = sym_context,
  [sym_aggregate] = sym_aggregate,
  [sym_entity] = sym_entity,
  [sym_value_object] = sym_value_object,
  [sym_event] = sym_event,
  [sym_service] = sym_service,
  [sym_repository] = sym_repository,
  [sym_enum] = sym_enum,
  [sym_enum_value] = sym_enum_value,
  [sym_annotation_emitter] = sym_annotation_emitter,
  [sym_annotation_note] = sym_annotation_note,
  [sym_method] = sym_method,
  [sym_method_emitter] = sym_method_emitter,
  [sym_method_note] = sym_method_note,
  [sym_field] = sym_field,
  [sym_generic_type] = sym_generic_type,
  [sym_type] = sym_type,
  [sym_reference_type] = sym_reference_type,
  [sym_primitive_type] = sym_primitive_type,
  [sym_array_type] = sym_array_type,
  [sym_nullable_type] = sym_nullable_type,
  [sym_value] = sym_value,
  [sym_array] = sym_array,
  [sym_boolean] = sym_boolean,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_context_repeat1] = aux_sym_context_repeat1,
  [aux_sym_aggregate_repeat1] = aux_sym_aggregate_repeat1,
  [aux_sym_entity_repeat1] = aux_sym_entity_repeat1,
  [aux_sym_value_object_repeat1] = aux_sym_value_object_repeat1,
  [aux_sym_service_repeat1] = aux_sym_service_repeat1,
  [aux_sym_repository_repeat1] = aux_sym_repository_repeat1,
  [aux_sym_enum_repeat1] = aux_sym_enum_repeat1,
  [aux_sym_annotation_emitter_repeat1] = aux_sym_annotation_emitter_repeat1,
  [aux_sym_method_repeat1] = aux_sym_method_repeat1,
  [aux_sym_method_emitter_repeat1] = aux_sym_method_emitter_repeat1,
  [aux_sym_array_repeat1] = aux_sym_array_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_Context] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BoundedContext] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_Aggregate] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AggregateRoot] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Entity] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ValueObject] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DomainEvent] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Event] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DomainService] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Service] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Repository] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATemits_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATnote_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_String] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UUID] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Boolean] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Date] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Null] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Void] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_null] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_context] = {
    .visible = true,
    .named = true,
  },
  [sym_aggregate] = {
    .visible = true,
    .named = true,
  },
  [sym_entity] = {
    .visible = true,
    .named = true,
  },
  [sym_value_object] = {
    .visible = true,
    .named = true,
  },
  [sym_event] = {
    .visible = true,
    .named = true,
  },
  [sym_service] = {
    .visible = true,
    .named = true,
  },
  [sym_repository] = {
    .visible = true,
    .named = true,
  },
  [sym_enum] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_value] = {
    .visible = true,
    .named = true,
  },
  [sym_annotation_emitter] = {
    .visible = true,
    .named = true,
  },
  [sym_annotation_note] = {
    .visible = true,
    .named = true,
  },
  [sym_method] = {
    .visible = true,
    .named = true,
  },
  [sym_method_emitter] = {
    .visible = true,
    .named = true,
  },
  [sym_method_note] = {
    .visible = true,
    .named = true,
  },
  [sym_field] = {
    .visible = true,
    .named = true,
  },
  [sym_generic_type] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_reference_type] = {
    .visible = true,
    .named = true,
  },
  [sym_primitive_type] = {
    .visible = true,
    .named = true,
  },
  [sym_array_type] = {
    .visible = true,
    .named = true,
  },
  [sym_nullable_type] = {
    .visible = true,
    .named = true,
  },
  [sym_value] = {
    .visible = true,
    .named = true,
  },
  [sym_array] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_context_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_aggregate_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_entity_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_value_object_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_service_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_repository_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_annotation_emitter_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_method_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_method_emitter_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_array_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(132);
      ADVANCE_MAP(
        '"', 1,
        '(', 152,
        ')', 150,
        ',', 149,
        '-', 130,
        '/', 5,
        ':', 153,
        '<', 155,
        '=', 154,
        '>', 156,
        '?', 174,
        '@', 28,
        'A', 49,
        'B', 82,
        'C', 89,
        'D', 14,
        'E', 72,
        'F', 64,
        'I', 75,
        'N', 119,
        'R', 29,
        'S', 39,
        'U', 12,
        'V', 15,
        '[', 206,
        ']', 207,
        'f', 16,
        'n', 122,
        't', 94,
        '{', 135,
        '}', 136,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(208);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(205);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '(') ADVANCE(151);
      END_STATE();
    case 3:
      if (lookahead == '(') ADVANCE(148);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        ')', 150,
        ',', 149,
        '/', 5,
        ':', 153,
        '<', 155,
        '=', 154,
        '?', 174,
        '@', 28,
        '[', 13,
        ']', 207,
        '}', 136,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(137);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        'B', 195,
        'D', 178,
        'F', 189,
        'I', 193,
        'N', 203,
        'S', 199,
        'U', 177,
        'V', 194,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 7:
      if (lookahead == 'C') ADVANCE(91);
      END_STATE();
    case 8:
      if (lookahead == 'D') ADVANCE(161);
      END_STATE();
    case 9:
      if (lookahead == 'E') ADVANCE(125);
      if (lookahead == 'S') ADVANCE(47);
      END_STATE();
    case 10:
      if (lookahead == 'I') ADVANCE(8);
      END_STATE();
    case 11:
      if (lookahead == 'O') ADVANCE(21);
      END_STATE();
    case 12:
      if (lookahead == 'U') ADVANCE(10);
      END_STATE();
    case 13:
      if (lookahead == ']') ADVANCE(173);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(111);
      if (lookahead == 'o') ADVANCE(70);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(68);
      if (lookahead == 'o') ADVANCE(52);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(61);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(56);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(74);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(105);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(116);
      END_STATE();
    case 21:
      if (lookahead == 'b') ADVANCE(60);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(108);
      END_STATE();
    case 23:
      if (lookahead == 'c') ADVANCE(36);
      END_STATE();
    case 24:
      if (lookahead == 'c') ADVANCE(38);
      END_STATE();
    case 25:
      if (lookahead == 'd') ADVANCE(171);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(7);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(42);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(71);
      if (lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(167);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(210);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(2);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(126);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(211);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(145);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(138);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(144);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(93);
      if (lookahead == 't') ADVANCE(96);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(51);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(26);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(127);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(79);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(98);
      END_STATE();
    case 48:
      if (lookahead == 'g') ADVANCE(157);
      END_STATE();
    case 49:
      if (lookahead == 'g') ADVANCE(50);
      END_STATE();
    case 50:
      if (lookahead == 'g') ADVANCE(97);
      END_STATE();
    case 51:
      if (lookahead == 'g') ADVANCE(20);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(25);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(23);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(77);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(112);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(73);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(103);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(114);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(24);
      END_STATE();
    case 60:
      if (lookahead == 'j') ADVANCE(40);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(100);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(169);
      END_STATE();
    case 63:
      if (lookahead == 'l') ADVANCE(212);
      END_STATE();
    case 64:
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 65:
      if (lookahead == 'l') ADVANCE(62);
      END_STATE();
    case 66:
      if (lookahead == 'l') ADVANCE(63);
      END_STATE();
    case 67:
      if (lookahead == 'l') ADVANCE(43);
      END_STATE();
    case 68:
      if (lookahead == 'l') ADVANCE(121);
      END_STATE();
    case 69:
      if (lookahead == 'm') ADVANCE(147);
      END_STATE();
    case 70:
      if (lookahead == 'm') ADVANCE(17);
      END_STATE();
    case 71:
      if (lookahead == 'm') ADVANCE(55);
      END_STATE();
    case 72:
      if (lookahead == 'n') ADVANCE(117);
      if (lookahead == 'v') ADVANCE(45);
      END_STATE();
    case 73:
      if (lookahead == 'n') ADVANCE(9);
      END_STATE();
    case 74:
      if (lookahead == 'n') ADVANCE(163);
      END_STATE();
    case 75:
      if (lookahead == 'n') ADVANCE(102);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 77:
      if (lookahead == 'n') ADVANCE(48);
      END_STATE();
    case 78:
      if (lookahead == 'n') ADVANCE(104);
      END_STATE();
    case 79:
      if (lookahead == 'n') ADVANCE(107);
      END_STATE();
    case 80:
      if (lookahead == 'n') ADVANCE(115);
      END_STATE();
    case 81:
      if (lookahead == 'n') ADVANCE(118);
      END_STATE();
    case 82:
      if (lookahead == 'o') ADVANCE(85);
      END_STATE();
    case 83:
      if (lookahead == 'o') ADVANCE(101);
      END_STATE();
    case 84:
      if (lookahead == 'o') ADVANCE(19);
      END_STATE();
    case 85:
      if (lookahead == 'o') ADVANCE(67);
      if (lookahead == 'u') ADVANCE(76);
      END_STATE();
    case 86:
      if (lookahead == 'o') ADVANCE(95);
      END_STATE();
    case 87:
      if (lookahead == 'o') ADVANCE(88);
      END_STATE();
    case 88:
      if (lookahead == 'o') ADVANCE(109);
      END_STATE();
    case 89:
      if (lookahead == 'o') ADVANCE(80);
      END_STATE();
    case 90:
      if (lookahead == 'o') ADVANCE(113);
      END_STATE();
    case 91:
      if (lookahead == 'o') ADVANCE(81);
      END_STATE();
    case 92:
      if (lookahead == 'p') ADVANCE(83);
      END_STATE();
    case 93:
      if (lookahead == 'r') ADVANCE(123);
      END_STATE();
    case 94:
      if (lookahead == 'r') ADVANCE(120);
      END_STATE();
    case 95:
      if (lookahead == 'r') ADVANCE(129);
      END_STATE();
    case 96:
      if (lookahead == 'r') ADVANCE(54);
      END_STATE();
    case 97:
      if (lookahead == 'r') ADVANCE(41);
      END_STATE();
    case 98:
      if (lookahead == 'r') ADVANCE(124);
      END_STATE();
    case 99:
      if (lookahead == 's') ADVANCE(3);
      END_STATE();
    case 100:
      if (lookahead == 's') ADVANCE(35);
      END_STATE();
    case 101:
      if (lookahead == 's') ADVANCE(58);
      END_STATE();
    case 102:
      if (lookahead == 't') ADVANCE(159);
      END_STATE();
    case 103:
      if (lookahead == 't') ADVANCE(128);
      END_STATE();
    case 104:
      if (lookahead == 't') ADVANCE(143);
      END_STATE();
    case 105:
      if (lookahead == 't') ADVANCE(165);
      END_STATE();
    case 106:
      if (lookahead == 't') ADVANCE(133);
      END_STATE();
    case 107:
      if (lookahead == 't') ADVANCE(142);
      END_STATE();
    case 108:
      if (lookahead == 't') ADVANCE(141);
      END_STATE();
    case 109:
      if (lookahead == 't') ADVANCE(139);
      END_STATE();
    case 110:
      if (lookahead == 't') ADVANCE(134);
      END_STATE();
    case 111:
      if (lookahead == 't') ADVANCE(30);
      END_STATE();
    case 112:
      if (lookahead == 't') ADVANCE(99);
      END_STATE();
    case 113:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 114:
      if (lookahead == 't') ADVANCE(86);
      END_STATE();
    case 115:
      if (lookahead == 't') ADVANCE(33);
      END_STATE();
    case 116:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 117:
      if (lookahead == 't') ADVANCE(57);
      if (lookahead == 'u') ADVANCE(69);
      END_STATE();
    case 118:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 119:
      if (lookahead == 'u') ADVANCE(65);
      END_STATE();
    case 120:
      if (lookahead == 'u') ADVANCE(31);
      END_STATE();
    case 121:
      if (lookahead == 'u') ADVANCE(34);
      END_STATE();
    case 122:
      if (lookahead == 'u') ADVANCE(66);
      END_STATE();
    case 123:
      if (lookahead == 'v') ADVANCE(53);
      END_STATE();
    case 124:
      if (lookahead == 'v') ADVANCE(59);
      END_STATE();
    case 125:
      if (lookahead == 'v') ADVANCE(46);
      END_STATE();
    case 126:
      if (lookahead == 'x') ADVANCE(106);
      END_STATE();
    case 127:
      if (lookahead == 'x') ADVANCE(110);
      END_STATE();
    case 128:
      if (lookahead == 'y') ADVANCE(140);
      END_STATE();
    case 129:
      if (lookahead == 'y') ADVANCE(146);
      END_STATE();
    case 130:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(208);
      END_STATE();
    case 131:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(209);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_Context);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_BoundedContext);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(137);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_Aggregate);
      if (lookahead == 'R') ADVANCE(87);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_AggregateRoot);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_Entity);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_ValueObject);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_DomainEvent);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_Event);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_DomainService);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_Service);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_Repository);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_Enum);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_ATemits_LPAREN);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_ATnote_LPAREN);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_String);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_String);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_Int);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_Int);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_UUID);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_UUID);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_Boolean);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_Boolean);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_Float);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_Float);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_Date);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_Date);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_Null);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_Null);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_Void);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_Void);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_LBRACK_RBRACK);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'I') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(170);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(208);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(209);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_null);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 6},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 6},
  [26] = {.lex_state = 6},
  [27] = {.lex_state = 6},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 4},
  [30] = {.lex_state = 4},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 4},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 4},
  [42] = {.lex_state = 4},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 4},
  [47] = {.lex_state = 4},
  [48] = {.lex_state = 4},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 4},
  [55] = {.lex_state = 4},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 4},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 4},
  [61] = {.lex_state = 4},
  [62] = {.lex_state = 4},
  [63] = {.lex_state = 4},
  [64] = {.lex_state = 4},
  [65] = {.lex_state = 4},
  [66] = {.lex_state = 4},
  [67] = {.lex_state = 4},
  [68] = {.lex_state = 4},
  [69] = {.lex_state = 4},
  [70] = {.lex_state = 4},
  [71] = {.lex_state = 4},
  [72] = {.lex_state = 4},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 4},
  [75] = {.lex_state = 4},
  [76] = {.lex_state = 4},
  [77] = {.lex_state = 4},
  [78] = {.lex_state = 4},
  [79] = {.lex_state = 4},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 4},
  [82] = {.lex_state = 4},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 4},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 4},
  [93] = {.lex_state = 4},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 4},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 4},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 4},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 4},
  [111] = {.lex_state = 4},
  [112] = {.lex_state = 4},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 4},
  [116] = {.lex_state = 4},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 4},
  [122] = {.lex_state = 4},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 4},
  [127] = {.lex_state = 4},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 4},
  [131] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_Context] = ACTIONS(1),
    [anon_sym_BoundedContext] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_Aggregate] = ACTIONS(1),
    [anon_sym_AggregateRoot] = ACTIONS(1),
    [anon_sym_Entity] = ACTIONS(1),
    [anon_sym_ValueObject] = ACTIONS(1),
    [anon_sym_DomainEvent] = ACTIONS(1),
    [anon_sym_Event] = ACTIONS(1),
    [anon_sym_DomainService] = ACTIONS(1),
    [anon_sym_Service] = ACTIONS(1),
    [anon_sym_Repository] = ACTIONS(1),
    [anon_sym_Enum] = ACTIONS(1),
    [anon_sym_ATemits_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_ATnote_LPAREN] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_String] = ACTIONS(1),
    [anon_sym_Int] = ACTIONS(1),
    [anon_sym_UUID] = ACTIONS(1),
    [anon_sym_Boolean] = ACTIONS(1),
    [anon_sym_Float] = ACTIONS(1),
    [anon_sym_Date] = ACTIONS(1),
    [anon_sym_Null] = ACTIONS(1),
    [anon_sym_Void] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_null] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(114),
    [sym__definition] = STATE(2),
    [sym_context] = STATE(2),
    [sym_aggregate] = STATE(2),
    [sym_entity] = STATE(2),
    [sym_value_object] = STATE(2),
    [sym_event] = STATE(2),
    [sym_service] = STATE(2),
    [sym_repository] = STATE(2),
    [sym_enum] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_Context] = ACTIONS(5),
    [anon_sym_BoundedContext] = ACTIONS(5),
    [sym_comment] = ACTIONS(7),
    [anon_sym_Aggregate] = ACTIONS(9),
    [anon_sym_AggregateRoot] = ACTIONS(11),
    [anon_sym_Entity] = ACTIONS(13),
    [anon_sym_ValueObject] = ACTIONS(15),
    [anon_sym_DomainEvent] = ACTIONS(17),
    [anon_sym_Event] = ACTIONS(17),
    [anon_sym_DomainService] = ACTIONS(19),
    [anon_sym_Service] = ACTIONS(19),
    [anon_sym_Repository] = ACTIONS(21),
    [anon_sym_Enum] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(9), 1,
      anon_sym_Aggregate,
    ACTIONS(11), 1,
      anon_sym_AggregateRoot,
    ACTIONS(13), 1,
      anon_sym_Entity,
    ACTIONS(15), 1,
      anon_sym_ValueObject,
    ACTIONS(21), 1,
      anon_sym_Repository,
    ACTIONS(23), 1,
      anon_sym_Enum,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(5), 2,
      anon_sym_Context,
      anon_sym_BoundedContext,
    ACTIONS(17), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(19), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(3), 10,
      sym__definition,
      sym_context,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_repository,
      sym_enum,
      aux_sym_source_file_repeat1,
  [49] = 12,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    ACTIONS(34), 1,
      sym_comment,
    ACTIONS(37), 1,
      anon_sym_Aggregate,
    ACTIONS(40), 1,
      anon_sym_AggregateRoot,
    ACTIONS(43), 1,
      anon_sym_Entity,
    ACTIONS(46), 1,
      anon_sym_ValueObject,
    ACTIONS(55), 1,
      anon_sym_Repository,
    ACTIONS(58), 1,
      anon_sym_Enum,
    ACTIONS(31), 2,
      anon_sym_Context,
      anon_sym_BoundedContext,
    ACTIONS(49), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(52), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(3), 10,
      sym__definition,
      sym_context,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_repository,
      sym_enum,
      aux_sym_source_file_repeat1,
  [98] = 11,
    ACTIONS(61), 1,
      anon_sym_RBRACE,
    ACTIONS(63), 1,
      sym_comment,
    ACTIONS(66), 1,
      anon_sym_Aggregate,
    ACTIONS(69), 1,
      anon_sym_AggregateRoot,
    ACTIONS(72), 1,
      anon_sym_Entity,
    ACTIONS(75), 1,
      anon_sym_ValueObject,
    ACTIONS(84), 1,
      anon_sym_Repository,
    ACTIONS(87), 1,
      anon_sym_Enum,
    ACTIONS(78), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(81), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(4), 8,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_repository,
      sym_enum,
      aux_sym_context_repeat1,
  [141] = 11,
    ACTIONS(9), 1,
      anon_sym_Aggregate,
    ACTIONS(11), 1,
      anon_sym_AggregateRoot,
    ACTIONS(13), 1,
      anon_sym_Entity,
    ACTIONS(15), 1,
      anon_sym_ValueObject,
    ACTIONS(21), 1,
      anon_sym_Repository,
    ACTIONS(23), 1,
      anon_sym_Enum,
    ACTIONS(90), 1,
      anon_sym_RBRACE,
    ACTIONS(92), 1,
      sym_comment,
    ACTIONS(17), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(19), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(4), 8,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_repository,
      sym_enum,
      aux_sym_context_repeat1,
  [184] = 11,
    ACTIONS(9), 1,
      anon_sym_Aggregate,
    ACTIONS(11), 1,
      anon_sym_AggregateRoot,
    ACTIONS(13), 1,
      anon_sym_Entity,
    ACTIONS(15), 1,
      anon_sym_ValueObject,
    ACTIONS(21), 1,
      anon_sym_Repository,
    ACTIONS(23), 1,
      anon_sym_Enum,
    ACTIONS(94), 1,
      anon_sym_RBRACE,
    ACTIONS(96), 1,
      sym_comment,
    ACTIONS(17), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(19), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(5), 8,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_repository,
      sym_enum,
      aux_sym_context_repeat1,
  [227] = 2,
    ACTIONS(100), 1,
      anon_sym_Aggregate,
    ACTIONS(98), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [247] = 2,
    ACTIONS(104), 1,
      anon_sym_Aggregate,
    ACTIONS(102), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [267] = 2,
    ACTIONS(108), 1,
      anon_sym_Aggregate,
    ACTIONS(106), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [287] = 2,
    ACTIONS(112), 1,
      anon_sym_Aggregate,
    ACTIONS(110), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [307] = 2,
    ACTIONS(116), 1,
      anon_sym_Aggregate,
    ACTIONS(114), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [327] = 2,
    ACTIONS(120), 1,
      anon_sym_Aggregate,
    ACTIONS(118), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [347] = 2,
    ACTIONS(124), 1,
      anon_sym_Aggregate,
    ACTIONS(122), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [367] = 2,
    ACTIONS(128), 1,
      anon_sym_Aggregate,
    ACTIONS(126), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [387] = 2,
    ACTIONS(132), 1,
      anon_sym_Aggregate,
    ACTIONS(130), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [407] = 2,
    ACTIONS(136), 1,
      anon_sym_Aggregate,
    ACTIONS(134), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [427] = 2,
    ACTIONS(140), 1,
      anon_sym_Aggregate,
    ACTIONS(138), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [447] = 2,
    ACTIONS(144), 1,
      anon_sym_Aggregate,
    ACTIONS(142), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [467] = 2,
    ACTIONS(148), 1,
      anon_sym_Aggregate,
    ACTIONS(146), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [487] = 2,
    ACTIONS(152), 1,
      anon_sym_Aggregate,
    ACTIONS(150), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [507] = 2,
    ACTIONS(156), 1,
      anon_sym_Aggregate,
    ACTIONS(154), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [527] = 2,
    ACTIONS(160), 1,
      anon_sym_Aggregate,
    ACTIONS(158), 14,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [547] = 5,
    ACTIONS(164), 1,
      sym_identifier,
    STATE(76), 1,
      sym_type,
    STATE(29), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(36), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(162), 8,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
      anon_sym_Void,
  [572] = 2,
    ACTIONS(168), 1,
      anon_sym_Aggregate,
    ACTIONS(166), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [591] = 5,
    ACTIONS(164), 1,
      sym_identifier,
    STATE(67), 1,
      sym_type,
    STATE(29), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(36), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(162), 8,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
      anon_sym_Void,
  [616] = 5,
    ACTIONS(164), 1,
      sym_identifier,
    STATE(35), 1,
      sym_type,
    STATE(29), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(36), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(162), 8,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
      anon_sym_Void,
  [641] = 5,
    ACTIONS(164), 1,
      sym_identifier,
    STATE(74), 1,
      sym_type,
    STATE(29), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(36), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(162), 8,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
      anon_sym_Void,
  [666] = 2,
    ACTIONS(172), 1,
      anon_sym_Aggregate,
    ACTIONS(170), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      sym_comment,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [685] = 3,
    ACTIONS(176), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(178), 1,
      anon_sym_QMARK,
    ACTIONS(174), 8,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      anon_sym_EQ,
      sym_identifier,
  [702] = 1,
    ACTIONS(180), 10,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      anon_sym_EQ,
      anon_sym_LBRACK_RBRACK,
      anon_sym_QMARK,
      sym_identifier,
  [715] = 1,
    ACTIONS(182), 10,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      anon_sym_EQ,
      anon_sym_LBRACK_RBRACK,
      anon_sym_QMARK,
      sym_identifier,
  [728] = 6,
    ACTIONS(186), 1,
      anon_sym_LBRACK,
    ACTIONS(188), 1,
      anon_sym_RBRACK,
    STATE(89), 1,
      sym_value,
    ACTIONS(190), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(53), 2,
      sym_array,
      sym_boolean,
    ACTIONS(184), 3,
      sym_string,
      sym_number,
      sym_null,
  [751] = 5,
    ACTIONS(186), 1,
      anon_sym_LBRACK,
    STATE(102), 1,
      sym_value,
    ACTIONS(190), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(53), 2,
      sym_array,
      sym_boolean,
    ACTIONS(184), 3,
      sym_string,
      sym_number,
      sym_null,
  [771] = 5,
    ACTIONS(186), 1,
      anon_sym_LBRACK,
    STATE(56), 1,
      sym_value,
    ACTIONS(190), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(53), 2,
      sym_array,
      sym_boolean,
    ACTIONS(184), 3,
      sym_string,
      sym_number,
      sym_null,
  [791] = 4,
    ACTIONS(194), 1,
      anon_sym_ATnote_LPAREN,
    ACTIONS(196), 1,
      anon_sym_EQ,
    STATE(69), 1,
      sym_annotation_note,
    ACTIONS(192), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [808] = 1,
    ACTIONS(174), 8,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      anon_sym_EQ,
      sym_identifier,
  [819] = 4,
    ACTIONS(194), 1,
      anon_sym_ATnote_LPAREN,
    ACTIONS(200), 1,
      anon_sym_ATemits_LPAREN,
    ACTIONS(198), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
    STATE(41), 3,
      sym_annotation_emitter,
      sym_annotation_note,
      aux_sym_method_emitter_repeat1,
  [836] = 1,
    ACTIONS(202), 8,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      anon_sym_EQ,
      sym_identifier,
  [847] = 1,
    ACTIONS(204), 8,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      anon_sym_EQ,
      sym_identifier,
  [858] = 4,
    ACTIONS(194), 1,
      anon_sym_ATnote_LPAREN,
    ACTIONS(200), 1,
      anon_sym_ATemits_LPAREN,
    ACTIONS(206), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
    STATE(37), 3,
      sym_annotation_emitter,
      sym_annotation_note,
      aux_sym_method_emitter_repeat1,
  [875] = 4,
    ACTIONS(210), 1,
      anon_sym_ATemits_LPAREN,
    ACTIONS(213), 1,
      anon_sym_ATnote_LPAREN,
    ACTIONS(208), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
    STATE(41), 3,
      sym_annotation_emitter,
      sym_annotation_note,
      aux_sym_method_emitter_repeat1,
  [892] = 5,
    ACTIONS(216), 1,
      anon_sym_RBRACE,
    ACTIONS(218), 1,
      sym_comment,
    ACTIONS(220), 1,
      sym_identifier,
    STATE(73), 1,
      sym_method,
    STATE(50), 3,
      sym_method_note,
      sym_field,
      aux_sym_entity_repeat1,
  [910] = 5,
    ACTIONS(220), 1,
      sym_identifier,
    ACTIONS(222), 1,
      anon_sym_RBRACE,
    ACTIONS(224), 1,
      sym_comment,
    STATE(40), 1,
      sym_method,
    STATE(49), 3,
      sym_method_emitter,
      sym_field,
      aux_sym_aggregate_repeat1,
  [928] = 5,
    ACTIONS(226), 1,
      anon_sym_RBRACE,
    ACTIONS(228), 1,
      sym_comment,
    ACTIONS(231), 1,
      sym_identifier,
    STATE(73), 1,
      sym_method,
    STATE(44), 3,
      sym_method_note,
      sym_field,
      aux_sym_entity_repeat1,
  [946] = 5,
    ACTIONS(216), 1,
      anon_sym_RBRACE,
    ACTIONS(220), 1,
      sym_identifier,
    ACTIONS(234), 1,
      sym_comment,
    STATE(73), 1,
      sym_method,
    STATE(44), 3,
      sym_method_note,
      sym_field,
      aux_sym_entity_repeat1,
  [964] = 1,
    ACTIONS(236), 7,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [974] = 5,
    ACTIONS(220), 1,
      sym_identifier,
    ACTIONS(238), 1,
      anon_sym_RBRACE,
    ACTIONS(240), 1,
      sym_comment,
    STATE(73), 1,
      sym_method,
    STATE(45), 3,
      sym_method_note,
      sym_field,
      aux_sym_entity_repeat1,
  [992] = 5,
    ACTIONS(220), 1,
      sym_identifier,
    ACTIONS(222), 1,
      anon_sym_RBRACE,
    ACTIONS(242), 1,
      sym_comment,
    STATE(40), 1,
      sym_method,
    STATE(51), 3,
      sym_method_emitter,
      sym_field,
      aux_sym_aggregate_repeat1,
  [1010] = 5,
    ACTIONS(220), 1,
      sym_identifier,
    ACTIONS(242), 1,
      sym_comment,
    ACTIONS(244), 1,
      anon_sym_RBRACE,
    STATE(40), 1,
      sym_method,
    STATE(51), 3,
      sym_method_emitter,
      sym_field,
      aux_sym_aggregate_repeat1,
  [1028] = 5,
    ACTIONS(220), 1,
      sym_identifier,
    ACTIONS(234), 1,
      sym_comment,
    ACTIONS(246), 1,
      anon_sym_RBRACE,
    STATE(73), 1,
      sym_method,
    STATE(44), 3,
      sym_method_note,
      sym_field,
      aux_sym_entity_repeat1,
  [1046] = 5,
    ACTIONS(248), 1,
      anon_sym_RBRACE,
    ACTIONS(250), 1,
      sym_comment,
    ACTIONS(253), 1,
      sym_identifier,
    STATE(40), 1,
      sym_method,
    STATE(51), 3,
      sym_method_emitter,
      sym_field,
      aux_sym_aggregate_repeat1,
  [1064] = 1,
    ACTIONS(256), 7,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
  [1074] = 1,
    ACTIONS(258), 7,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [1084] = 5,
    ACTIONS(220), 1,
      sym_identifier,
    ACTIONS(260), 1,
      anon_sym_RBRACE,
    ACTIONS(262), 1,
      sym_comment,
    STATE(40), 1,
      sym_method,
    STATE(48), 3,
      sym_method_emitter,
      sym_field,
      aux_sym_aggregate_repeat1,
  [1102] = 1,
    ACTIONS(264), 7,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [1112] = 3,
    ACTIONS(194), 1,
      anon_sym_ATnote_LPAREN,
    STATE(81), 1,
      sym_annotation_note,
    ACTIONS(266), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [1126] = 1,
    ACTIONS(268), 7,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [1136] = 1,
    ACTIONS(270), 7,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [1146] = 2,
    ACTIONS(274), 1,
      anon_sym_COLON,
    ACTIONS(272), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
  [1157] = 5,
    ACTIONS(276), 1,
      anon_sym_RBRACE,
    ACTIONS(278), 1,
      sym_comment,
    ACTIONS(280), 1,
      sym_identifier,
    STATE(73), 1,
      sym_method,
    STATE(63), 2,
      sym_method_note,
      aux_sym_service_repeat1,
  [1174] = 2,
    ACTIONS(284), 1,
      anon_sym_COLON,
    ACTIONS(282), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
  [1185] = 5,
    ACTIONS(280), 1,
      sym_identifier,
    ACTIONS(286), 1,
      anon_sym_RBRACE,
    ACTIONS(288), 1,
      sym_comment,
    STATE(73), 1,
      sym_method,
    STATE(60), 2,
      sym_method_note,
      aux_sym_service_repeat1,
  [1202] = 5,
    ACTIONS(290), 1,
      anon_sym_RBRACE,
    ACTIONS(292), 1,
      sym_comment,
    ACTIONS(295), 1,
      sym_identifier,
    STATE(73), 1,
      sym_method,
    STATE(63), 2,
      sym_method_note,
      aux_sym_service_repeat1,
  [1219] = 2,
    ACTIONS(300), 1,
      anon_sym_COLON,
    ACTIONS(298), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
  [1230] = 4,
    ACTIONS(302), 1,
      anon_sym_RBRACE,
    ACTIONS(304), 1,
      sym_comment,
    ACTIONS(306), 1,
      sym_identifier,
    STATE(75), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [1244] = 4,
    ACTIONS(308), 1,
      anon_sym_RBRACE,
    ACTIONS(310), 1,
      sym_comment,
    ACTIONS(312), 1,
      sym_identifier,
    STATE(83), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [1258] = 1,
    ACTIONS(298), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
  [1266] = 1,
    ACTIONS(314), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
  [1274] = 1,
    ACTIONS(316), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [1282] = 4,
    ACTIONS(304), 1,
      sym_comment,
    ACTIONS(306), 1,
      sym_identifier,
    ACTIONS(318), 1,
      anon_sym_RBRACE,
    STATE(75), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [1296] = 4,
    ACTIONS(280), 1,
      sym_identifier,
    ACTIONS(320), 1,
      anon_sym_RBRACE,
    STATE(73), 1,
      sym_method,
    STATE(80), 2,
      sym_method_note,
      aux_sym_repository_repeat1,
  [1310] = 1,
    ACTIONS(322), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
  [1318] = 3,
    ACTIONS(194), 1,
      anon_sym_ATnote_LPAREN,
    STATE(93), 1,
      sym_annotation_note,
    ACTIONS(324), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1330] = 1,
    ACTIONS(326), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
  [1338] = 4,
    ACTIONS(328), 1,
      anon_sym_RBRACE,
    ACTIONS(330), 1,
      sym_comment,
    ACTIONS(333), 1,
      sym_identifier,
    STATE(75), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [1352] = 1,
    ACTIONS(336), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_ATemits_LPAREN,
      anon_sym_ATnote_LPAREN,
      sym_identifier,
  [1360] = 4,
    ACTIONS(312), 1,
      sym_identifier,
    ACTIONS(338), 1,
      anon_sym_RBRACE,
    ACTIONS(340), 1,
      sym_comment,
    STATE(66), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [1374] = 3,
    ACTIONS(194), 1,
      anon_sym_ATnote_LPAREN,
    STATE(88), 1,
      sym_annotation_note,
    ACTIONS(342), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1386] = 4,
    ACTIONS(280), 1,
      sym_identifier,
    ACTIONS(344), 1,
      anon_sym_RBRACE,
    STATE(73), 1,
      sym_method,
    STATE(71), 2,
      sym_method_note,
      aux_sym_repository_repeat1,
  [1400] = 4,
    ACTIONS(346), 1,
      anon_sym_RBRACE,
    ACTIONS(348), 1,
      sym_identifier,
    STATE(73), 1,
      sym_method,
    STATE(80), 2,
      sym_method_note,
      aux_sym_repository_repeat1,
  [1414] = 1,
    ACTIONS(351), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [1422] = 4,
    ACTIONS(306), 1,
      sym_identifier,
    ACTIONS(353), 1,
      anon_sym_RBRACE,
    ACTIONS(355), 1,
      sym_comment,
    STATE(65), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [1436] = 4,
    ACTIONS(357), 1,
      anon_sym_RBRACE,
    ACTIONS(359), 1,
      sym_comment,
    ACTIONS(362), 1,
      sym_identifier,
    STATE(83), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [1450] = 4,
    ACTIONS(306), 1,
      sym_identifier,
    ACTIONS(365), 1,
      anon_sym_RBRACE,
    ACTIONS(367), 1,
      sym_comment,
    STATE(70), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [1464] = 3,
    ACTIONS(369), 1,
      anon_sym_COMMA,
    ACTIONS(371), 1,
      anon_sym_RPAREN,
    STATE(95), 1,
      aux_sym_method_repeat1,
  [1474] = 3,
    ACTIONS(373), 1,
      anon_sym_COMMA,
    ACTIONS(376), 1,
      anon_sym_RBRACK,
    STATE(86), 1,
      aux_sym_array_repeat1,
  [1484] = 3,
    ACTIONS(306), 1,
      sym_identifier,
    ACTIONS(378), 1,
      anon_sym_RPAREN,
    STATE(85), 1,
      sym_field,
  [1494] = 1,
    ACTIONS(380), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1500] = 3,
    ACTIONS(382), 1,
      anon_sym_COMMA,
    ACTIONS(384), 1,
      anon_sym_RBRACK,
    STATE(96), 1,
      aux_sym_array_repeat1,
  [1510] = 3,
    ACTIONS(386), 1,
      anon_sym_COMMA,
    ACTIONS(388), 1,
      anon_sym_RPAREN,
    STATE(97), 1,
      aux_sym_annotation_emitter_repeat1,
  [1520] = 3,
    ACTIONS(390), 1,
      anon_sym_COMMA,
    ACTIONS(393), 1,
      anon_sym_RPAREN,
    STATE(91), 1,
      aux_sym_annotation_emitter_repeat1,
  [1530] = 3,
    ACTIONS(395), 1,
      anon_sym_LT,
    ACTIONS(397), 1,
      sym_identifier,
    STATE(105), 1,
      sym_generic_type,
  [1540] = 1,
    ACTIONS(399), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1546] = 3,
    ACTIONS(401), 1,
      anon_sym_COMMA,
    ACTIONS(404), 1,
      anon_sym_RPAREN,
    STATE(94), 1,
      aux_sym_method_repeat1,
  [1556] = 3,
    ACTIONS(369), 1,
      anon_sym_COMMA,
    ACTIONS(406), 1,
      anon_sym_RPAREN,
    STATE(94), 1,
      aux_sym_method_repeat1,
  [1566] = 3,
    ACTIONS(382), 1,
      anon_sym_COMMA,
    ACTIONS(408), 1,
      anon_sym_RBRACK,
    STATE(86), 1,
      aux_sym_array_repeat1,
  [1576] = 3,
    ACTIONS(386), 1,
      anon_sym_COMMA,
    ACTIONS(410), 1,
      anon_sym_RPAREN,
    STATE(91), 1,
      aux_sym_annotation_emitter_repeat1,
  [1586] = 3,
    ACTIONS(395), 1,
      anon_sym_LT,
    ACTIONS(412), 1,
      sym_identifier,
    STATE(109), 1,
      sym_generic_type,
  [1596] = 2,
    ACTIONS(414), 1,
      anon_sym_LPAREN,
    ACTIONS(416), 1,
      anon_sym_COLON,
  [1603] = 1,
    ACTIONS(393), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1608] = 2,
    ACTIONS(306), 1,
      sym_identifier,
    STATE(103), 1,
      sym_field,
  [1615] = 1,
    ACTIONS(376), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1620] = 1,
    ACTIONS(404), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1625] = 1,
    ACTIONS(418), 1,
      anon_sym_LBRACE,
  [1629] = 1,
    ACTIONS(420), 1,
      sym_identifier,
  [1633] = 1,
    ACTIONS(422), 1,
      anon_sym_LBRACE,
  [1637] = 1,
    ACTIONS(424), 1,
      anon_sym_LBRACE,
  [1641] = 1,
    ACTIONS(426), 1,
      anon_sym_LBRACE,
  [1645] = 1,
    ACTIONS(428), 1,
      sym_identifier,
  [1649] = 1,
    ACTIONS(430), 1,
      sym_identifier,
  [1653] = 1,
    ACTIONS(432), 1,
      sym_identifier,
  [1657] = 1,
    ACTIONS(434), 1,
      sym_identifier,
  [1661] = 1,
    ACTIONS(436), 1,
      anon_sym_LBRACE,
  [1665] = 1,
    ACTIONS(438), 1,
      ts_builtin_sym_end,
  [1669] = 1,
    ACTIONS(440), 1,
      sym_identifier,
  [1673] = 1,
    ACTIONS(442), 1,
      sym_identifier,
  [1677] = 1,
    ACTIONS(444), 1,
      anon_sym_LBRACE,
  [1681] = 1,
    ACTIONS(446), 1,
      anon_sym_LBRACE,
  [1685] = 1,
    ACTIONS(448), 1,
      anon_sym_LBRACE,
  [1689] = 1,
    ACTIONS(450), 1,
      anon_sym_RPAREN,
  [1693] = 1,
    ACTIONS(452), 1,
      sym_identifier,
  [1697] = 1,
    ACTIONS(454), 1,
      sym_identifier,
  [1701] = 1,
    ACTIONS(456), 1,
      anon_sym_GT,
  [1705] = 1,
    ACTIONS(458), 1,
      anon_sym_LBRACE,
  [1709] = 1,
    ACTIONS(460), 1,
      anon_sym_LBRACE,
  [1713] = 1,
    ACTIONS(462), 1,
      sym_identifier,
  [1717] = 1,
    ACTIONS(464), 1,
      sym_identifier,
  [1721] = 1,
    ACTIONS(416), 1,
      anon_sym_COLON,
  [1725] = 1,
    ACTIONS(414), 1,
      anon_sym_LPAREN,
  [1729] = 1,
    ACTIONS(466), 1,
      sym_identifier,
  [1733] = 1,
    ACTIONS(468), 1,
      sym_string,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 49,
  [SMALL_STATE(4)] = 98,
  [SMALL_STATE(5)] = 141,
  [SMALL_STATE(6)] = 184,
  [SMALL_STATE(7)] = 227,
  [SMALL_STATE(8)] = 247,
  [SMALL_STATE(9)] = 267,
  [SMALL_STATE(10)] = 287,
  [SMALL_STATE(11)] = 307,
  [SMALL_STATE(12)] = 327,
  [SMALL_STATE(13)] = 347,
  [SMALL_STATE(14)] = 367,
  [SMALL_STATE(15)] = 387,
  [SMALL_STATE(16)] = 407,
  [SMALL_STATE(17)] = 427,
  [SMALL_STATE(18)] = 447,
  [SMALL_STATE(19)] = 467,
  [SMALL_STATE(20)] = 487,
  [SMALL_STATE(21)] = 507,
  [SMALL_STATE(22)] = 527,
  [SMALL_STATE(23)] = 547,
  [SMALL_STATE(24)] = 572,
  [SMALL_STATE(25)] = 591,
  [SMALL_STATE(26)] = 616,
  [SMALL_STATE(27)] = 641,
  [SMALL_STATE(28)] = 666,
  [SMALL_STATE(29)] = 685,
  [SMALL_STATE(30)] = 702,
  [SMALL_STATE(31)] = 715,
  [SMALL_STATE(32)] = 728,
  [SMALL_STATE(33)] = 751,
  [SMALL_STATE(34)] = 771,
  [SMALL_STATE(35)] = 791,
  [SMALL_STATE(36)] = 808,
  [SMALL_STATE(37)] = 819,
  [SMALL_STATE(38)] = 836,
  [SMALL_STATE(39)] = 847,
  [SMALL_STATE(40)] = 858,
  [SMALL_STATE(41)] = 875,
  [SMALL_STATE(42)] = 892,
  [SMALL_STATE(43)] = 910,
  [SMALL_STATE(44)] = 928,
  [SMALL_STATE(45)] = 946,
  [SMALL_STATE(46)] = 964,
  [SMALL_STATE(47)] = 974,
  [SMALL_STATE(48)] = 992,
  [SMALL_STATE(49)] = 1010,
  [SMALL_STATE(50)] = 1028,
  [SMALL_STATE(51)] = 1046,
  [SMALL_STATE(52)] = 1064,
  [SMALL_STATE(53)] = 1074,
  [SMALL_STATE(54)] = 1084,
  [SMALL_STATE(55)] = 1102,
  [SMALL_STATE(56)] = 1112,
  [SMALL_STATE(57)] = 1126,
  [SMALL_STATE(58)] = 1136,
  [SMALL_STATE(59)] = 1146,
  [SMALL_STATE(60)] = 1157,
  [SMALL_STATE(61)] = 1174,
  [SMALL_STATE(62)] = 1185,
  [SMALL_STATE(63)] = 1202,
  [SMALL_STATE(64)] = 1219,
  [SMALL_STATE(65)] = 1230,
  [SMALL_STATE(66)] = 1244,
  [SMALL_STATE(67)] = 1258,
  [SMALL_STATE(68)] = 1266,
  [SMALL_STATE(69)] = 1274,
  [SMALL_STATE(70)] = 1282,
  [SMALL_STATE(71)] = 1296,
  [SMALL_STATE(72)] = 1310,
  [SMALL_STATE(73)] = 1318,
  [SMALL_STATE(74)] = 1330,
  [SMALL_STATE(75)] = 1338,
  [SMALL_STATE(76)] = 1352,
  [SMALL_STATE(77)] = 1360,
  [SMALL_STATE(78)] = 1374,
  [SMALL_STATE(79)] = 1386,
  [SMALL_STATE(80)] = 1400,
  [SMALL_STATE(81)] = 1414,
  [SMALL_STATE(82)] = 1422,
  [SMALL_STATE(83)] = 1436,
  [SMALL_STATE(84)] = 1450,
  [SMALL_STATE(85)] = 1464,
  [SMALL_STATE(86)] = 1474,
  [SMALL_STATE(87)] = 1484,
  [SMALL_STATE(88)] = 1494,
  [SMALL_STATE(89)] = 1500,
  [SMALL_STATE(90)] = 1510,
  [SMALL_STATE(91)] = 1520,
  [SMALL_STATE(92)] = 1530,
  [SMALL_STATE(93)] = 1540,
  [SMALL_STATE(94)] = 1546,
  [SMALL_STATE(95)] = 1556,
  [SMALL_STATE(96)] = 1566,
  [SMALL_STATE(97)] = 1576,
  [SMALL_STATE(98)] = 1586,
  [SMALL_STATE(99)] = 1596,
  [SMALL_STATE(100)] = 1603,
  [SMALL_STATE(101)] = 1608,
  [SMALL_STATE(102)] = 1615,
  [SMALL_STATE(103)] = 1620,
  [SMALL_STATE(104)] = 1625,
  [SMALL_STATE(105)] = 1629,
  [SMALL_STATE(106)] = 1633,
  [SMALL_STATE(107)] = 1637,
  [SMALL_STATE(108)] = 1641,
  [SMALL_STATE(109)] = 1645,
  [SMALL_STATE(110)] = 1649,
  [SMALL_STATE(111)] = 1653,
  [SMALL_STATE(112)] = 1657,
  [SMALL_STATE(113)] = 1661,
  [SMALL_STATE(114)] = 1665,
  [SMALL_STATE(115)] = 1669,
  [SMALL_STATE(116)] = 1673,
  [SMALL_STATE(117)] = 1677,
  [SMALL_STATE(118)] = 1681,
  [SMALL_STATE(119)] = 1685,
  [SMALL_STATE(120)] = 1689,
  [SMALL_STATE(121)] = 1693,
  [SMALL_STATE(122)] = 1697,
  [SMALL_STATE(123)] = 1701,
  [SMALL_STATE(124)] = 1705,
  [SMALL_STATE(125)] = 1709,
  [SMALL_STATE(126)] = 1713,
  [SMALL_STATE(127)] = 1717,
  [SMALL_STATE(128)] = 1721,
  [SMALL_STATE(129)] = 1725,
  [SMALL_STATE(130)] = 1729,
  [SMALL_STATE(131)] = 1733,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(126),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(121),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(126),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(121),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 5, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 5, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 6, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 6, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 5, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event, 5, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 5, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_service, 5, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 4, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_service, 4, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repository, 5, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_repository, 5, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 4, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event, 4, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 5, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 5, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 4, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_object, 4, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 5, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 5, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 4, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 4, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 5, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_object, 5, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 6, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 6, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repository, 4, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_repository, 4, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 4, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 4, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 4, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 4, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 5, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 5, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 4, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 4, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reference_type, 1, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 3, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_emitter, 2, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nullable_type, 2, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_type, 2, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_emitter, 1, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_method_emitter_repeat1, 2, 0, 0),
  [210] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_method_emitter_repeat1, 2, 0, 0), SHIFT_REPEAT(112),
  [213] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_method_emitter_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0),
  [228] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [231] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 4, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0),
  [250] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [253] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotation_note, 3, 0, 0),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 5, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 4, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 3, 0, 0),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0),
  [292] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [295] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0), SHIFT_REPEAT(129),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 5, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotation_emitter, 3, 0, 0),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 4, 0, 0),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotation_emitter, 4, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_note, 1, 0, 0),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 6, 0, 0),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0),
  [330] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [333] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0), SHIFT_REPEAT(128),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 7, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_value, 1, 0, 0),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_repository_repeat1, 2, 0, 0),
  [348] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_repository_repeat1, 2, 0, 0), SHIFT_REPEAT(129),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 6, 0, 0),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [357] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0),
  [359] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0), SHIFT_REPEAT(83),
  [362] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [373] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_value, 2, 0, 0),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [390] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_annotation_emitter_repeat1, 2, 0, 0), SHIFT_REPEAT(111),
  [393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_annotation_emitter_repeat1, 2, 0, 0),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_note, 2, 0, 0),
  [401] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_method_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_method_repeat1, 2, 0, 0),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [438] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_type, 3, 0, 0),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_ddd(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
