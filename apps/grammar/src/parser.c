#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 105
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 68
#define ALIAS_COUNT 0
#define TOKEN_COUNT 39
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
  anon_sym_Enum = 14,
  anon_sym_LPAREN = 15,
  anon_sym_COMMA = 16,
  anon_sym_RPAREN = 17,
  anon_sym_COLON = 18,
  anon_sym_EQ = 19,
  anon_sym_LT = 20,
  anon_sym_GT = 21,
  anon_sym_String = 22,
  anon_sym_Int = 23,
  anon_sym_UUID = 24,
  anon_sym_Boolean = 25,
  anon_sym_Float = 26,
  anon_sym_Date = 27,
  anon_sym_Null = 28,
  anon_sym_LBRACK_RBRACK = 29,
  anon_sym_QMARK = 30,
  sym_identifier = 31,
  sym_string = 32,
  anon_sym_LBRACK = 33,
  anon_sym_RBRACK = 34,
  sym_number = 35,
  anon_sym_true = 36,
  anon_sym_false = 37,
  sym_null = 38,
  sym_source_file = 39,
  sym__definition = 40,
  sym_context = 41,
  sym_aggregate = 42,
  sym_entity = 43,
  sym_value_object = 44,
  sym_event = 45,
  sym_service = 46,
  sym_enum = 47,
  sym_enum_value = 48,
  sym_method = 49,
  sym_field = 50,
  sym_generic_type = 51,
  sym_type = 52,
  sym_reference_type = 53,
  sym_primitive_type = 54,
  sym_array_type = 55,
  sym_nullable_type = 56,
  sym_value = 57,
  sym_array = 58,
  sym_boolean = 59,
  aux_sym_source_file_repeat1 = 60,
  aux_sym_context_repeat1 = 61,
  aux_sym_aggregate_repeat1 = 62,
  aux_sym_value_object_repeat1 = 63,
  aux_sym_service_repeat1 = 64,
  aux_sym_enum_repeat1 = 65,
  aux_sym_method_repeat1 = 66,
  aux_sym_array_repeat1 = 67,
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
  [anon_sym_Enum] = "Enum",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
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
  [sym_enum] = "enum",
  [sym_enum_value] = "enum_value",
  [sym_method] = "method",
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
  [aux_sym_value_object_repeat1] = "value_object_repeat1",
  [aux_sym_service_repeat1] = "service_repeat1",
  [aux_sym_enum_repeat1] = "enum_repeat1",
  [aux_sym_method_repeat1] = "method_repeat1",
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
  [anon_sym_Enum] = anon_sym_Enum,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
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
  [sym_enum] = sym_enum,
  [sym_enum_value] = sym_enum_value,
  [sym_method] = sym_method,
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
  [aux_sym_value_object_repeat1] = aux_sym_value_object_repeat1,
  [aux_sym_service_repeat1] = aux_sym_service_repeat1,
  [aux_sym_enum_repeat1] = aux_sym_enum_repeat1,
  [aux_sym_method_repeat1] = aux_sym_method_repeat1,
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
  [anon_sym_Enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
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
  [sym_enum] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_value] = {
    .visible = true,
    .named = true,
  },
  [sym_method] = {
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
  [aux_sym_value_object_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_service_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_method_repeat1] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(111);
      ADVANCE_MAP(
        '"', 1,
        '(', 126,
        ')', 128,
        ',', 127,
        '-', 109,
        '/', 3,
        ':', 129,
        '<', 131,
        '=', 130,
        '>', 132,
        '?', 148,
        'A', 43,
        'B', 72,
        'C', 77,
        'D', 12,
        'E', 62,
        'F', 55,
        'I', 66,
        'N', 99,
        'S', 33,
        'U', 10,
        'V', 13,
        '[', 177,
        ']', 178,
        'f', 14,
        'n', 102,
        't', 80,
        '{', 114,
        '}', 115,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(179);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(176);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        ')', 128,
        ',', 127,
        '/', 3,
        ':', 129,
        '<', 131,
        '=', 130,
        '?', 148,
        '[', 11,
        ']', 178,
        '}', 115,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 3:
      if (lookahead == '/') ADVANCE(116);
      END_STATE();
    case 4:
      if (lookahead == 'B') ADVANCE(166);
      if (lookahead == 'D') ADVANCE(152);
      if (lookahead == 'F') ADVANCE(161);
      if (lookahead == 'I') ADVANCE(165);
      if (lookahead == 'N') ADVANCE(174);
      if (lookahead == 'S') ADVANCE(170);
      if (lookahead == 'U') ADVANCE(151);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 5:
      if (lookahead == 'C') ADVANCE(78);
      END_STATE();
    case 6:
      if (lookahead == 'D') ADVANCE(137);
      END_STATE();
    case 7:
      if (lookahead == 'E') ADVANCE(105);
      if (lookahead == 'S') ADVANCE(41);
      END_STATE();
    case 8:
      if (lookahead == 'I') ADVANCE(6);
      END_STATE();
    case 9:
      if (lookahead == 'O') ADVANCE(19);
      END_STATE();
    case 10:
      if (lookahead == 'U') ADVANCE(8);
      END_STATE();
    case 11:
      if (lookahead == ']') ADVANCE(147);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(95);
      if (lookahead == 'o') ADVANCE(61);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(59);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(52);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(65);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(89);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(49);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(97);
      END_STATE();
    case 19:
      if (lookahead == 'b') ADVANCE(51);
      END_STATE();
    case 20:
      if (lookahead == 'c') ADVANCE(92);
      END_STATE();
    case 21:
      if (lookahead == 'c') ADVANCE(30);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(32);
      END_STATE();
    case 23:
      if (lookahead == 'd') ADVANCE(5);
      END_STATE();
    case 24:
      if (lookahead == 'd') ADVANCE(34);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(181);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(106);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(9);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(182);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(124);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(117);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(123);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(79);
      if (lookahead == 't') ADVANCE(81);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(45);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(15);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(107);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(68);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(83);
      END_STATE();
    case 42:
      if (lookahead == 'g') ADVANCE(133);
      END_STATE();
    case 43:
      if (lookahead == 'g') ADVANCE(44);
      END_STATE();
    case 44:
      if (lookahead == 'g') ADVANCE(82);
      END_STATE();
    case 45:
      if (lookahead == 'g') ADVANCE(18);
      END_STATE();
    case 46:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 47:
      if (lookahead == 'i') ADVANCE(67);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(87);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(64);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 51:
      if (lookahead == 'j') ADVANCE(35);
      END_STATE();
    case 52:
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 53:
      if (lookahead == 'l') ADVANCE(145);
      END_STATE();
    case 54:
      if (lookahead == 'l') ADVANCE(183);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(37);
      END_STATE();
    case 57:
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(54);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 60:
      if (lookahead == 'm') ADVANCE(125);
      END_STATE();
    case 61:
      if (lookahead == 'm') ADVANCE(17);
      END_STATE();
    case 62:
      if (lookahead == 'n') ADVANCE(85);
      if (lookahead == 'v') ADVANCE(39);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(7);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(139);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(86);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(88);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(91);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(96);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(98);
      END_STATE();
    case 72:
      if (lookahead == 'o') ADVANCE(75);
      END_STATE();
    case 73:
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 74:
      if (lookahead == 'o') ADVANCE(76);
      END_STATE();
    case 75:
      if (lookahead == 'o') ADVANCE(56);
      if (lookahead == 'u') ADVANCE(63);
      END_STATE();
    case 76:
      if (lookahead == 'o') ADVANCE(93);
      END_STATE();
    case 77:
      if (lookahead == 'o') ADVANCE(70);
      END_STATE();
    case 78:
      if (lookahead == 'o') ADVANCE(71);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(103);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(100);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(104);
      END_STATE();
    case 84:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 85:
      if (lookahead == 't') ADVANCE(48);
      if (lookahead == 'u') ADVANCE(60);
      END_STATE();
    case 86:
      if (lookahead == 't') ADVANCE(135);
      END_STATE();
    case 87:
      if (lookahead == 't') ADVANCE(108);
      END_STATE();
    case 88:
      if (lookahead == 't') ADVANCE(122);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(141);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(112);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(121);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(120);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(118);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(113);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(25);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 99:
      if (lookahead == 'u') ADVANCE(57);
      END_STATE();
    case 100:
      if (lookahead == 'u') ADVANCE(26);
      END_STATE();
    case 101:
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 102:
      if (lookahead == 'u') ADVANCE(58);
      END_STATE();
    case 103:
      if (lookahead == 'v') ADVANCE(46);
      END_STATE();
    case 104:
      if (lookahead == 'v') ADVANCE(50);
      END_STATE();
    case 105:
      if (lookahead == 'v') ADVANCE(40);
      END_STATE();
    case 106:
      if (lookahead == 'x') ADVANCE(90);
      END_STATE();
    case 107:
      if (lookahead == 'x') ADVANCE(94);
      END_STATE();
    case 108:
      if (lookahead == 'y') ADVANCE(119);
      END_STATE();
    case 109:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(179);
      END_STATE();
    case 110:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(180);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_Context);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_BoundedContext);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(116);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_Aggregate);
      if (lookahead == 'R') ADVANCE(74);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_AggregateRoot);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_Entity);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_ValueObject);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_DomainEvent);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_Event);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_DomainService);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_Service);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_Enum);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_String);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_String);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_Int);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_Int);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_UUID);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_UUID);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_Boolean);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_Boolean);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_Float);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_Float);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_Date);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_Date);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_Null);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_Null);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_LBRACK_RBRACK);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'I') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(179);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(180);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 183:
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
  [21] = {.lex_state = 4},
  [22] = {.lex_state = 4},
  [23] = {.lex_state = 4},
  [24] = {.lex_state = 4},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 2},
  [42] = {.lex_state = 2},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 2},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 2},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 2},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
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
    [anon_sym_Enum] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
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
    [sym_source_file] = STATE(91),
    [sym__definition] = STATE(3),
    [sym_context] = STATE(3),
    [sym_aggregate] = STATE(3),
    [sym_entity] = STATE(3),
    [sym_value_object] = STATE(3),
    [sym_event] = STATE(3),
    [sym_service] = STATE(3),
    [sym_enum] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
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
    [anon_sym_Enum] = ACTIONS(21),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(28), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_Aggregate,
    ACTIONS(34), 1,
      anon_sym_AggregateRoot,
    ACTIONS(37), 1,
      anon_sym_Entity,
    ACTIONS(40), 1,
      anon_sym_ValueObject,
    ACTIONS(49), 1,
      anon_sym_Enum,
    ACTIONS(25), 2,
      anon_sym_Context,
      anon_sym_BoundedContext,
    ACTIONS(43), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(46), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(2), 9,
      sym__definition,
      sym_context,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_enum,
      aux_sym_source_file_repeat1,
  [45] = 11,
    ACTIONS(9), 1,
      anon_sym_Aggregate,
    ACTIONS(11), 1,
      anon_sym_AggregateRoot,
    ACTIONS(13), 1,
      anon_sym_Entity,
    ACTIONS(15), 1,
      anon_sym_ValueObject,
    ACTIONS(21), 1,
      anon_sym_Enum,
    ACTIONS(52), 1,
      ts_builtin_sym_end,
    ACTIONS(54), 1,
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
    STATE(2), 9,
      sym__definition,
      sym_context,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_enum,
      aux_sym_source_file_repeat1,
  [90] = 10,
    ACTIONS(9), 1,
      anon_sym_Aggregate,
    ACTIONS(11), 1,
      anon_sym_AggregateRoot,
    ACTIONS(13), 1,
      anon_sym_Entity,
    ACTIONS(15), 1,
      anon_sym_ValueObject,
    ACTIONS(21), 1,
      anon_sym_Enum,
    ACTIONS(56), 1,
      anon_sym_RBRACE,
    ACTIONS(58), 1,
      sym_comment,
    ACTIONS(17), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(19), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(6), 7,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_enum,
      aux_sym_context_repeat1,
  [129] = 10,
    ACTIONS(9), 1,
      anon_sym_Aggregate,
    ACTIONS(11), 1,
      anon_sym_AggregateRoot,
    ACTIONS(13), 1,
      anon_sym_Entity,
    ACTIONS(15), 1,
      anon_sym_ValueObject,
    ACTIONS(21), 1,
      anon_sym_Enum,
    ACTIONS(60), 1,
      anon_sym_RBRACE,
    ACTIONS(62), 1,
      sym_comment,
    ACTIONS(17), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(19), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(4), 7,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_enum,
      aux_sym_context_repeat1,
  [168] = 10,
    ACTIONS(64), 1,
      anon_sym_RBRACE,
    ACTIONS(66), 1,
      sym_comment,
    ACTIONS(69), 1,
      anon_sym_Aggregate,
    ACTIONS(72), 1,
      anon_sym_AggregateRoot,
    ACTIONS(75), 1,
      anon_sym_Entity,
    ACTIONS(78), 1,
      anon_sym_ValueObject,
    ACTIONS(87), 1,
      anon_sym_Enum,
    ACTIONS(81), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(84), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(6), 7,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_enum,
      aux_sym_context_repeat1,
  [207] = 2,
    ACTIONS(92), 1,
      anon_sym_Aggregate,
    ACTIONS(90), 13,
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
      anon_sym_Enum,
  [226] = 2,
    ACTIONS(96), 1,
      anon_sym_Aggregate,
    ACTIONS(94), 13,
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
      anon_sym_Enum,
  [245] = 2,
    ACTIONS(100), 1,
      anon_sym_Aggregate,
    ACTIONS(98), 13,
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
      anon_sym_Enum,
  [264] = 2,
    ACTIONS(104), 1,
      anon_sym_Aggregate,
    ACTIONS(102), 13,
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
      anon_sym_Enum,
  [283] = 2,
    ACTIONS(108), 1,
      anon_sym_Aggregate,
    ACTIONS(106), 13,
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
      anon_sym_Enum,
  [302] = 2,
    ACTIONS(112), 1,
      anon_sym_Aggregate,
    ACTIONS(110), 13,
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
      anon_sym_Enum,
  [321] = 2,
    ACTIONS(116), 1,
      anon_sym_Aggregate,
    ACTIONS(114), 13,
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
      anon_sym_Enum,
  [340] = 2,
    ACTIONS(120), 1,
      anon_sym_Aggregate,
    ACTIONS(118), 13,
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
      anon_sym_Enum,
  [359] = 2,
    ACTIONS(124), 1,
      anon_sym_Aggregate,
    ACTIONS(122), 13,
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
      anon_sym_Enum,
  [378] = 2,
    ACTIONS(128), 1,
      anon_sym_Aggregate,
    ACTIONS(126), 13,
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
      anon_sym_Enum,
  [397] = 2,
    ACTIONS(132), 1,
      anon_sym_Aggregate,
    ACTIONS(130), 13,
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
      anon_sym_Enum,
  [416] = 2,
    ACTIONS(136), 1,
      anon_sym_Aggregate,
    ACTIONS(134), 13,
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
      anon_sym_Enum,
  [435] = 2,
    ACTIONS(140), 1,
      anon_sym_Aggregate,
    ACTIONS(138), 13,
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
      anon_sym_Enum,
  [454] = 2,
    ACTIONS(144), 1,
      anon_sym_Aggregate,
    ACTIONS(142), 13,
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
      anon_sym_Enum,
  [473] = 5,
    ACTIONS(148), 1,
      sym_identifier,
    STATE(78), 1,
      sym_type,
    STATE(30), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(45), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(146), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [497] = 5,
    ACTIONS(148), 1,
      sym_identifier,
    STATE(71), 1,
      sym_type,
    STATE(30), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(45), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(146), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [521] = 5,
    ACTIONS(148), 1,
      sym_identifier,
    STATE(72), 1,
      sym_type,
    STATE(30), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(45), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(146), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [545] = 5,
    ACTIONS(148), 1,
      sym_identifier,
    STATE(44), 1,
      sym_type,
    STATE(30), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(45), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(146), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [569] = 2,
    ACTIONS(152), 1,
      anon_sym_Aggregate,
    ACTIONS(150), 12,
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
      anon_sym_Enum,
  [587] = 2,
    ACTIONS(156), 1,
      anon_sym_Aggregate,
    ACTIONS(154), 12,
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
      anon_sym_Enum,
  [605] = 6,
    ACTIONS(160), 1,
      anon_sym_LBRACK,
    ACTIONS(162), 1,
      anon_sym_RBRACK,
    STATE(66), 1,
      sym_value,
    ACTIONS(164), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(47), 2,
      sym_array,
      sym_boolean,
    ACTIONS(158), 3,
      sym_string,
      sym_number,
      sym_null,
  [628] = 5,
    ACTIONS(160), 1,
      anon_sym_LBRACK,
    STATE(81), 1,
      sym_value,
    ACTIONS(164), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(47), 2,
      sym_array,
      sym_boolean,
    ACTIONS(158), 3,
      sym_string,
      sym_number,
      sym_null,
  [648] = 5,
    ACTIONS(160), 1,
      anon_sym_LBRACK,
    STATE(54), 1,
      sym_value,
    ACTIONS(164), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(47), 2,
      sym_array,
      sym_boolean,
    ACTIONS(158), 3,
      sym_string,
      sym_number,
      sym_null,
  [668] = 3,
    ACTIONS(168), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(170), 1,
      anon_sym_QMARK,
    ACTIONS(166), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [683] = 1,
    ACTIONS(172), 8,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_LBRACK_RBRACK,
      anon_sym_QMARK,
      sym_identifier,
  [694] = 1,
    ACTIONS(174), 8,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_LBRACK_RBRACK,
      anon_sym_QMARK,
      sym_identifier,
  [705] = 1,
    ACTIONS(176), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [714] = 4,
    ACTIONS(178), 1,
      anon_sym_RBRACE,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(182), 1,
      sym_identifier,
    STATE(40), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [729] = 4,
    ACTIONS(182), 1,
      sym_identifier,
    ACTIONS(184), 1,
      anon_sym_RBRACE,
    ACTIONS(186), 1,
      sym_comment,
    STATE(43), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [744] = 4,
    ACTIONS(182), 1,
      sym_identifier,
    ACTIONS(186), 1,
      sym_comment,
    ACTIONS(188), 1,
      anon_sym_RBRACE,
    STATE(43), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [759] = 4,
    ACTIONS(182), 1,
      sym_identifier,
    ACTIONS(186), 1,
      sym_comment,
    ACTIONS(190), 1,
      anon_sym_RBRACE,
    STATE(43), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [774] = 4,
    ACTIONS(182), 1,
      sym_identifier,
    ACTIONS(190), 1,
      anon_sym_RBRACE,
    ACTIONS(192), 1,
      sym_comment,
    STATE(36), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [789] = 1,
    ACTIONS(194), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [798] = 4,
    ACTIONS(182), 1,
      sym_identifier,
    ACTIONS(186), 1,
      sym_comment,
    ACTIONS(196), 1,
      anon_sym_RBRACE,
    STATE(43), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [813] = 4,
    ACTIONS(182), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_RBRACE,
    ACTIONS(198), 1,
      sym_comment,
    STATE(35), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [828] = 4,
    ACTIONS(182), 1,
      sym_identifier,
    ACTIONS(200), 1,
      anon_sym_RBRACE,
    ACTIONS(202), 1,
      sym_comment,
    STATE(37), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [843] = 4,
    ACTIONS(204), 1,
      anon_sym_RBRACE,
    ACTIONS(206), 1,
      sym_comment,
    ACTIONS(209), 1,
      sym_identifier,
    STATE(43), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [858] = 2,
    ACTIONS(214), 1,
      anon_sym_EQ,
    ACTIONS(212), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [869] = 1,
    ACTIONS(166), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [878] = 1,
    ACTIONS(216), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [887] = 1,
    ACTIONS(218), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [896] = 1,
    ACTIONS(220), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [905] = 1,
    ACTIONS(222), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [914] = 1,
    ACTIONS(224), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [923] = 4,
    ACTIONS(226), 1,
      anon_sym_RBRACE,
    ACTIONS(228), 1,
      sym_comment,
    ACTIONS(230), 1,
      sym_identifier,
    STATE(57), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [937] = 4,
    ACTIONS(232), 1,
      anon_sym_RBRACE,
    ACTIONS(234), 1,
      sym_comment,
    ACTIONS(237), 1,
      sym_identifier,
    STATE(52), 2,
      sym_method,
      aux_sym_service_repeat1,
  [951] = 4,
    ACTIONS(240), 1,
      anon_sym_RBRACE,
    ACTIONS(242), 1,
      sym_comment,
    ACTIONS(244), 1,
      sym_identifier,
    STATE(52), 2,
      sym_method,
      aux_sym_service_repeat1,
  [965] = 1,
    ACTIONS(246), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [973] = 4,
    ACTIONS(248), 1,
      anon_sym_RBRACE,
    ACTIONS(250), 1,
      sym_comment,
    ACTIONS(252), 1,
      sym_identifier,
    STATE(60), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [987] = 4,
    ACTIONS(250), 1,
      sym_comment,
    ACTIONS(252), 1,
      sym_identifier,
    ACTIONS(254), 1,
      anon_sym_RBRACE,
    STATE(60), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [1001] = 4,
    ACTIONS(256), 1,
      anon_sym_RBRACE,
    ACTIONS(258), 1,
      sym_comment,
    ACTIONS(261), 1,
      sym_identifier,
    STATE(57), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [1015] = 4,
    ACTIONS(252), 1,
      sym_identifier,
    ACTIONS(264), 1,
      anon_sym_RBRACE,
    ACTIONS(266), 1,
      sym_comment,
    STATE(56), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [1029] = 4,
    ACTIONS(230), 1,
      sym_identifier,
    ACTIONS(268), 1,
      anon_sym_RBRACE,
    ACTIONS(270), 1,
      sym_comment,
    STATE(51), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [1043] = 4,
    ACTIONS(272), 1,
      anon_sym_RBRACE,
    ACTIONS(274), 1,
      sym_comment,
    ACTIONS(277), 1,
      sym_identifier,
    STATE(60), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [1057] = 4,
    ACTIONS(244), 1,
      sym_identifier,
    ACTIONS(280), 1,
      anon_sym_RBRACE,
    ACTIONS(282), 1,
      sym_comment,
    STATE(53), 2,
      sym_method,
      aux_sym_service_repeat1,
  [1071] = 4,
    ACTIONS(252), 1,
      sym_identifier,
    ACTIONS(284), 1,
      anon_sym_RBRACE,
    ACTIONS(286), 1,
      sym_comment,
    STATE(55), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [1085] = 2,
    ACTIONS(290), 1,
      anon_sym_COLON,
    ACTIONS(288), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1094] = 2,
    ACTIONS(294), 1,
      anon_sym_COLON,
    ACTIONS(292), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1103] = 2,
    ACTIONS(298), 1,
      anon_sym_COLON,
    ACTIONS(296), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1112] = 3,
    ACTIONS(300), 1,
      anon_sym_COMMA,
    ACTIONS(302), 1,
      anon_sym_RBRACK,
    STATE(68), 1,
      aux_sym_array_repeat1,
  [1122] = 3,
    ACTIONS(304), 1,
      anon_sym_COMMA,
    ACTIONS(307), 1,
      anon_sym_RBRACK,
    STATE(67), 1,
      aux_sym_array_repeat1,
  [1132] = 3,
    ACTIONS(300), 1,
      anon_sym_COMMA,
    ACTIONS(309), 1,
      anon_sym_RBRACK,
    STATE(67), 1,
      aux_sym_array_repeat1,
  [1142] = 3,
    ACTIONS(311), 1,
      anon_sym_COMMA,
    ACTIONS(313), 1,
      anon_sym_RPAREN,
    STATE(77), 1,
      aux_sym_method_repeat1,
  [1152] = 3,
    ACTIONS(315), 1,
      anon_sym_LT,
    ACTIONS(317), 1,
      sym_identifier,
    STATE(89), 1,
      sym_generic_type,
  [1162] = 1,
    ACTIONS(319), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1168] = 1,
    ACTIONS(321), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1174] = 3,
    ACTIONS(323), 1,
      anon_sym_COMMA,
    ACTIONS(326), 1,
      anon_sym_RPAREN,
    STATE(73), 1,
      aux_sym_method_repeat1,
  [1184] = 1,
    ACTIONS(328), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1190] = 3,
    ACTIONS(315), 1,
      anon_sym_LT,
    ACTIONS(330), 1,
      sym_identifier,
    STATE(86), 1,
      sym_generic_type,
  [1200] = 3,
    ACTIONS(252), 1,
      sym_identifier,
    ACTIONS(332), 1,
      anon_sym_RPAREN,
    STATE(69), 1,
      sym_field,
  [1210] = 3,
    ACTIONS(311), 1,
      anon_sym_COMMA,
    ACTIONS(334), 1,
      anon_sym_RPAREN,
    STATE(73), 1,
      aux_sym_method_repeat1,
  [1220] = 1,
    ACTIONS(292), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1226] = 2,
    ACTIONS(336), 1,
      anon_sym_LPAREN,
    ACTIONS(338), 1,
      anon_sym_COLON,
  [1233] = 1,
    ACTIONS(326), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1238] = 1,
    ACTIONS(307), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1243] = 2,
    ACTIONS(252), 1,
      sym_identifier,
    STATE(80), 1,
      sym_field,
  [1250] = 1,
    ACTIONS(340), 1,
      anon_sym_LBRACE,
  [1254] = 1,
    ACTIONS(342), 1,
      anon_sym_LBRACE,
  [1258] = 1,
    ACTIONS(344), 1,
      anon_sym_LBRACE,
  [1262] = 1,
    ACTIONS(346), 1,
      sym_identifier,
  [1266] = 1,
    ACTIONS(348), 1,
      sym_identifier,
  [1270] = 1,
    ACTIONS(350), 1,
      sym_identifier,
  [1274] = 1,
    ACTIONS(352), 1,
      sym_identifier,
  [1278] = 1,
    ACTIONS(354), 1,
      anon_sym_LBRACE,
  [1282] = 1,
    ACTIONS(356), 1,
      ts_builtin_sym_end,
  [1286] = 1,
    ACTIONS(358), 1,
      sym_identifier,
  [1290] = 1,
    ACTIONS(360), 1,
      anon_sym_LBRACE,
  [1294] = 1,
    ACTIONS(362), 1,
      anon_sym_LBRACE,
  [1298] = 1,
    ACTIONS(364), 1,
      sym_identifier,
  [1302] = 1,
    ACTIONS(366), 1,
      sym_identifier,
  [1306] = 1,
    ACTIONS(368), 1,
      anon_sym_LBRACE,
  [1310] = 1,
    ACTIONS(370), 1,
      anon_sym_GT,
  [1314] = 1,
    ACTIONS(372), 1,
      sym_identifier,
  [1318] = 1,
    ACTIONS(374), 1,
      anon_sym_LBRACE,
  [1322] = 1,
    ACTIONS(376), 1,
      anon_sym_LBRACE,
  [1326] = 1,
    ACTIONS(378), 1,
      sym_identifier,
  [1330] = 1,
    ACTIONS(338), 1,
      anon_sym_COLON,
  [1334] = 1,
    ACTIONS(336), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 45,
  [SMALL_STATE(4)] = 90,
  [SMALL_STATE(5)] = 129,
  [SMALL_STATE(6)] = 168,
  [SMALL_STATE(7)] = 207,
  [SMALL_STATE(8)] = 226,
  [SMALL_STATE(9)] = 245,
  [SMALL_STATE(10)] = 264,
  [SMALL_STATE(11)] = 283,
  [SMALL_STATE(12)] = 302,
  [SMALL_STATE(13)] = 321,
  [SMALL_STATE(14)] = 340,
  [SMALL_STATE(15)] = 359,
  [SMALL_STATE(16)] = 378,
  [SMALL_STATE(17)] = 397,
  [SMALL_STATE(18)] = 416,
  [SMALL_STATE(19)] = 435,
  [SMALL_STATE(20)] = 454,
  [SMALL_STATE(21)] = 473,
  [SMALL_STATE(22)] = 497,
  [SMALL_STATE(23)] = 521,
  [SMALL_STATE(24)] = 545,
  [SMALL_STATE(25)] = 569,
  [SMALL_STATE(26)] = 587,
  [SMALL_STATE(27)] = 605,
  [SMALL_STATE(28)] = 628,
  [SMALL_STATE(29)] = 648,
  [SMALL_STATE(30)] = 668,
  [SMALL_STATE(31)] = 683,
  [SMALL_STATE(32)] = 694,
  [SMALL_STATE(33)] = 705,
  [SMALL_STATE(34)] = 714,
  [SMALL_STATE(35)] = 729,
  [SMALL_STATE(36)] = 744,
  [SMALL_STATE(37)] = 759,
  [SMALL_STATE(38)] = 774,
  [SMALL_STATE(39)] = 789,
  [SMALL_STATE(40)] = 798,
  [SMALL_STATE(41)] = 813,
  [SMALL_STATE(42)] = 828,
  [SMALL_STATE(43)] = 843,
  [SMALL_STATE(44)] = 858,
  [SMALL_STATE(45)] = 869,
  [SMALL_STATE(46)] = 878,
  [SMALL_STATE(47)] = 887,
  [SMALL_STATE(48)] = 896,
  [SMALL_STATE(49)] = 905,
  [SMALL_STATE(50)] = 914,
  [SMALL_STATE(51)] = 923,
  [SMALL_STATE(52)] = 937,
  [SMALL_STATE(53)] = 951,
  [SMALL_STATE(54)] = 965,
  [SMALL_STATE(55)] = 973,
  [SMALL_STATE(56)] = 987,
  [SMALL_STATE(57)] = 1001,
  [SMALL_STATE(58)] = 1015,
  [SMALL_STATE(59)] = 1029,
  [SMALL_STATE(60)] = 1043,
  [SMALL_STATE(61)] = 1057,
  [SMALL_STATE(62)] = 1071,
  [SMALL_STATE(63)] = 1085,
  [SMALL_STATE(64)] = 1094,
  [SMALL_STATE(65)] = 1103,
  [SMALL_STATE(66)] = 1112,
  [SMALL_STATE(67)] = 1122,
  [SMALL_STATE(68)] = 1132,
  [SMALL_STATE(69)] = 1142,
  [SMALL_STATE(70)] = 1152,
  [SMALL_STATE(71)] = 1162,
  [SMALL_STATE(72)] = 1168,
  [SMALL_STATE(73)] = 1174,
  [SMALL_STATE(74)] = 1184,
  [SMALL_STATE(75)] = 1190,
  [SMALL_STATE(76)] = 1200,
  [SMALL_STATE(77)] = 1210,
  [SMALL_STATE(78)] = 1220,
  [SMALL_STATE(79)] = 1226,
  [SMALL_STATE(80)] = 1233,
  [SMALL_STATE(81)] = 1238,
  [SMALL_STATE(82)] = 1243,
  [SMALL_STATE(83)] = 1250,
  [SMALL_STATE(84)] = 1254,
  [SMALL_STATE(85)] = 1258,
  [SMALL_STATE(86)] = 1262,
  [SMALL_STATE(87)] = 1266,
  [SMALL_STATE(88)] = 1270,
  [SMALL_STATE(89)] = 1274,
  [SMALL_STATE(90)] = 1278,
  [SMALL_STATE(91)] = 1282,
  [SMALL_STATE(92)] = 1286,
  [SMALL_STATE(93)] = 1290,
  [SMALL_STATE(94)] = 1294,
  [SMALL_STATE(95)] = 1298,
  [SMALL_STATE(96)] = 1302,
  [SMALL_STATE(97)] = 1306,
  [SMALL_STATE(98)] = 1310,
  [SMALL_STATE(99)] = 1314,
  [SMALL_STATE(100)] = 1318,
  [SMALL_STATE(101)] = 1322,
  [SMALL_STATE(102)] = 1326,
  [SMALL_STATE(103)] = 1330,
  [SMALL_STATE(104)] = 1334,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(88),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(95),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(95),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 4, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 4, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 5, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 5, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 4, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_service, 4, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 5, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 5, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 5, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_object, 5, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 5, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event, 5, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 4, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event, 4, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 5, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_service, 5, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 4, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 4, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 6, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 6, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 6, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 6, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 5, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 5, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 4, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 4, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 4, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_object, 4, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 4, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 4, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 5, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 5, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reference_type, 1, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nullable_type, 2, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 4, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0),
  [206] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [209] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 3, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_type, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0),
  [234] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [237] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0), SHIFT_REPEAT(104),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 5, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0),
  [258] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [261] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0),
  [274] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [277] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0), SHIFT_REPEAT(103),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 4, 0, 0),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 5, 0, 0),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 3, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [304] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 7, 0, 0),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 6, 0, 0),
  [323] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_method_repeat1, 2, 0, 0), SHIFT_REPEAT(82),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_method_repeat1, 2, 0, 0),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_value, 1, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [356] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_type, 3, 0, 0),
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