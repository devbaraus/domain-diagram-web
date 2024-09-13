#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 97
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
  [19] = {.lex_state = 4},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 4},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 4},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 2},
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
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 2},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
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
    [sym_source_file] = STATE(94),
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
    STATE(5), 7,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_enum,
      aux_sym_context_repeat1,
  [129] = 10,
    ACTIONS(60), 1,
      anon_sym_RBRACE,
    ACTIONS(62), 1,
      sym_comment,
    ACTIONS(65), 1,
      anon_sym_Aggregate,
    ACTIONS(68), 1,
      anon_sym_AggregateRoot,
    ACTIONS(71), 1,
      anon_sym_Entity,
    ACTIONS(74), 1,
      anon_sym_ValueObject,
    ACTIONS(83), 1,
      anon_sym_Enum,
    ACTIONS(77), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(80), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(5), 7,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_enum,
      aux_sym_context_repeat1,
  [168] = 10,
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
    ACTIONS(86), 1,
      anon_sym_RBRACE,
    ACTIONS(88), 1,
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
  [435] = 5,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(35), 1,
      sym_type,
    STATE(30), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(34), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(138), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [459] = 5,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(62), 1,
      sym_type,
    STATE(30), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(34), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(138), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [483] = 2,
    ACTIONS(144), 1,
      anon_sym_Aggregate,
    ACTIONS(142), 12,
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
  [501] = 5,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(68), 1,
      sym_type,
    STATE(30), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(34), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(138), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [525] = 2,
    ACTIONS(148), 1,
      anon_sym_Aggregate,
    ACTIONS(146), 12,
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
  [543] = 5,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(63), 1,
      sym_type,
    STATE(30), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(34), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(138), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [567] = 6,
    ACTIONS(152), 1,
      anon_sym_LBRACK,
    ACTIONS(154), 1,
      anon_sym_RBRACK,
    STATE(66), 1,
      sym_value,
    ACTIONS(156), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(36), 2,
      sym_array,
      sym_boolean,
    ACTIONS(150), 3,
      sym_string,
      sym_number,
      sym_null,
  [590] = 5,
    ACTIONS(152), 1,
      anon_sym_LBRACK,
    STATE(73), 1,
      sym_value,
    ACTIONS(156), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(36), 2,
      sym_array,
      sym_boolean,
    ACTIONS(150), 3,
      sym_string,
      sym_number,
      sym_null,
  [610] = 5,
    ACTIONS(152), 1,
      anon_sym_LBRACK,
    STATE(52), 1,
      sym_value,
    ACTIONS(156), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(36), 2,
      sym_array,
      sym_boolean,
    ACTIONS(150), 3,
      sym_string,
      sym_number,
      sym_null,
  [630] = 1,
    ACTIONS(158), 8,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_LBRACK_RBRACK,
      anon_sym_QMARK,
      sym_identifier,
  [641] = 1,
    ACTIONS(160), 8,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_LBRACK_RBRACK,
      anon_sym_QMARK,
      sym_identifier,
  [652] = 3,
    ACTIONS(164), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(166), 1,
      anon_sym_QMARK,
    ACTIONS(162), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [667] = 1,
    ACTIONS(168), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [676] = 4,
    ACTIONS(170), 1,
      anon_sym_RBRACE,
    ACTIONS(172), 1,
      sym_comment,
    ACTIONS(174), 1,
      sym_identifier,
    STATE(41), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [691] = 1,
    ACTIONS(176), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [700] = 1,
    ACTIONS(162), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [709] = 2,
    ACTIONS(180), 1,
      anon_sym_EQ,
    ACTIONS(178), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [720] = 1,
    ACTIONS(182), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [729] = 4,
    ACTIONS(174), 1,
      sym_identifier,
    ACTIONS(184), 1,
      anon_sym_RBRACE,
    ACTIONS(186), 1,
      sym_comment,
    STATE(32), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [744] = 4,
    ACTIONS(174), 1,
      sym_identifier,
    ACTIONS(188), 1,
      anon_sym_RBRACE,
    ACTIONS(190), 1,
      sym_comment,
    STATE(44), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [759] = 1,
    ACTIONS(192), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [768] = 1,
    ACTIONS(194), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [777] = 4,
    ACTIONS(196), 1,
      anon_sym_RBRACE,
    ACTIONS(198), 1,
      sym_comment,
    ACTIONS(201), 1,
      sym_identifier,
    STATE(41), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [792] = 1,
    ACTIONS(204), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [801] = 1,
    ACTIONS(206), 6,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [810] = 4,
    ACTIONS(172), 1,
      sym_comment,
    ACTIONS(174), 1,
      sym_identifier,
    ACTIONS(208), 1,
      anon_sym_RBRACE,
    STATE(41), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [825] = 4,
    ACTIONS(210), 1,
      anon_sym_RBRACE,
    ACTIONS(212), 1,
      sym_comment,
    ACTIONS(214), 1,
      sym_identifier,
    STATE(53), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [839] = 4,
    ACTIONS(216), 1,
      anon_sym_RBRACE,
    ACTIONS(218), 1,
      sym_comment,
    ACTIONS(221), 1,
      sym_identifier,
    STATE(46), 2,
      sym_method,
      aux_sym_service_repeat1,
  [853] = 4,
    ACTIONS(224), 1,
      anon_sym_RBRACE,
    ACTIONS(226), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym_identifier,
    STATE(56), 2,
      sym_method,
      aux_sym_service_repeat1,
  [867] = 4,
    ACTIONS(230), 1,
      anon_sym_RBRACE,
    ACTIONS(232), 1,
      sym_comment,
    ACTIONS(234), 1,
      sym_identifier,
    STATE(55), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [881] = 4,
    ACTIONS(234), 1,
      sym_identifier,
    ACTIONS(236), 1,
      anon_sym_RBRACE,
    ACTIONS(238), 1,
      sym_comment,
    STATE(48), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [895] = 4,
    ACTIONS(214), 1,
      sym_identifier,
    ACTIONS(240), 1,
      anon_sym_RBRACE,
    ACTIONS(242), 1,
      sym_comment,
    STATE(51), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [909] = 4,
    ACTIONS(212), 1,
      sym_comment,
    ACTIONS(214), 1,
      sym_identifier,
    ACTIONS(244), 1,
      anon_sym_RBRACE,
    STATE(53), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [923] = 1,
    ACTIONS(246), 5,
      anon_sym_RBRACE,
      sym_comment,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [931] = 4,
    ACTIONS(248), 1,
      anon_sym_RBRACE,
    ACTIONS(250), 1,
      sym_comment,
    ACTIONS(253), 1,
      sym_identifier,
    STATE(53), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [945] = 4,
    ACTIONS(214), 1,
      sym_identifier,
    ACTIONS(256), 1,
      anon_sym_RBRACE,
    ACTIONS(258), 1,
      sym_comment,
    STATE(45), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [959] = 4,
    ACTIONS(260), 1,
      anon_sym_RBRACE,
    ACTIONS(262), 1,
      sym_comment,
    ACTIONS(265), 1,
      sym_identifier,
    STATE(55), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [973] = 4,
    ACTIONS(228), 1,
      sym_identifier,
    ACTIONS(268), 1,
      anon_sym_RBRACE,
    ACTIONS(270), 1,
      sym_comment,
    STATE(46), 2,
      sym_method,
      aux_sym_service_repeat1,
  [987] = 2,
    ACTIONS(274), 1,
      anon_sym_COLON,
    ACTIONS(272), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [996] = 2,
    ACTIONS(278), 1,
      anon_sym_COLON,
    ACTIONS(276), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1005] = 2,
    ACTIONS(282), 1,
      anon_sym_COLON,
    ACTIONS(280), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1014] = 1,
    ACTIONS(284), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1020] = 3,
    ACTIONS(286), 1,
      anon_sym_COMMA,
    ACTIONS(289), 1,
      anon_sym_RPAREN,
    STATE(61), 1,
      aux_sym_method_repeat1,
  [1030] = 1,
    ACTIONS(272), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1036] = 1,
    ACTIONS(291), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1042] = 3,
    ACTIONS(214), 1,
      sym_identifier,
    ACTIONS(293), 1,
      anon_sym_RPAREN,
    STATE(69), 1,
      sym_field,
  [1052] = 3,
    ACTIONS(295), 1,
      anon_sym_COMMA,
    ACTIONS(297), 1,
      anon_sym_RPAREN,
    STATE(61), 1,
      aux_sym_method_repeat1,
  [1062] = 3,
    ACTIONS(299), 1,
      anon_sym_COMMA,
    ACTIONS(301), 1,
      anon_sym_RBRACK,
    STATE(70), 1,
      aux_sym_array_repeat1,
  [1072] = 3,
    ACTIONS(303), 1,
      anon_sym_COMMA,
    ACTIONS(306), 1,
      anon_sym_RBRACK,
    STATE(67), 1,
      aux_sym_array_repeat1,
  [1082] = 1,
    ACTIONS(308), 3,
      anon_sym_RBRACE,
      sym_comment,
      sym_identifier,
  [1088] = 3,
    ACTIONS(295), 1,
      anon_sym_COMMA,
    ACTIONS(310), 1,
      anon_sym_RPAREN,
    STATE(65), 1,
      aux_sym_method_repeat1,
  [1098] = 3,
    ACTIONS(299), 1,
      anon_sym_COMMA,
    ACTIONS(312), 1,
      anon_sym_RBRACK,
    STATE(67), 1,
      aux_sym_array_repeat1,
  [1108] = 2,
    ACTIONS(314), 1,
      anon_sym_LPAREN,
    ACTIONS(316), 1,
      anon_sym_COLON,
  [1115] = 1,
    ACTIONS(289), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1120] = 1,
    ACTIONS(306), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1125] = 2,
    ACTIONS(214), 1,
      sym_identifier,
    STATE(72), 1,
      sym_field,
  [1132] = 2,
    ACTIONS(318), 1,
      anon_sym_LT,
    STATE(81), 1,
      sym_generic_type,
  [1139] = 2,
    ACTIONS(318), 1,
      anon_sym_LT,
    STATE(82), 1,
      sym_generic_type,
  [1146] = 1,
    ACTIONS(320), 1,
      sym_identifier,
  [1150] = 1,
    ACTIONS(322), 1,
      sym_identifier,
  [1154] = 1,
    ACTIONS(324), 1,
      anon_sym_LBRACE,
  [1158] = 1,
    ACTIONS(326), 1,
      sym_identifier,
  [1162] = 1,
    ACTIONS(328), 1,
      sym_identifier,
  [1166] = 1,
    ACTIONS(330), 1,
      sym_identifier,
  [1170] = 1,
    ACTIONS(332), 1,
      sym_identifier,
  [1174] = 1,
    ACTIONS(334), 1,
      anon_sym_LBRACE,
  [1178] = 1,
    ACTIONS(336), 1,
      anon_sym_LBRACE,
  [1182] = 1,
    ACTIONS(338), 1,
      anon_sym_LBRACE,
  [1186] = 1,
    ACTIONS(340), 1,
      anon_sym_LBRACE,
  [1190] = 1,
    ACTIONS(342), 1,
      anon_sym_GT,
  [1194] = 1,
    ACTIONS(344), 1,
      sym_identifier,
  [1198] = 1,
    ACTIONS(346), 1,
      sym_identifier,
  [1202] = 1,
    ACTIONS(348), 1,
      anon_sym_LBRACE,
  [1206] = 1,
    ACTIONS(350), 1,
      anon_sym_LBRACE,
  [1210] = 1,
    ACTIONS(352), 1,
      sym_identifier,
  [1214] = 1,
    ACTIONS(354), 1,
      ts_builtin_sym_end,
  [1218] = 1,
    ACTIONS(314), 1,
      anon_sym_LPAREN,
  [1222] = 1,
    ACTIONS(316), 1,
      anon_sym_COLON,
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
  [SMALL_STATE(20)] = 459,
  [SMALL_STATE(21)] = 483,
  [SMALL_STATE(22)] = 501,
  [SMALL_STATE(23)] = 525,
  [SMALL_STATE(24)] = 543,
  [SMALL_STATE(25)] = 567,
  [SMALL_STATE(26)] = 590,
  [SMALL_STATE(27)] = 610,
  [SMALL_STATE(28)] = 630,
  [SMALL_STATE(29)] = 641,
  [SMALL_STATE(30)] = 652,
  [SMALL_STATE(31)] = 667,
  [SMALL_STATE(32)] = 676,
  [SMALL_STATE(33)] = 691,
  [SMALL_STATE(34)] = 700,
  [SMALL_STATE(35)] = 709,
  [SMALL_STATE(36)] = 720,
  [SMALL_STATE(37)] = 729,
  [SMALL_STATE(38)] = 744,
  [SMALL_STATE(39)] = 759,
  [SMALL_STATE(40)] = 768,
  [SMALL_STATE(41)] = 777,
  [SMALL_STATE(42)] = 792,
  [SMALL_STATE(43)] = 801,
  [SMALL_STATE(44)] = 810,
  [SMALL_STATE(45)] = 825,
  [SMALL_STATE(46)] = 839,
  [SMALL_STATE(47)] = 853,
  [SMALL_STATE(48)] = 867,
  [SMALL_STATE(49)] = 881,
  [SMALL_STATE(50)] = 895,
  [SMALL_STATE(51)] = 909,
  [SMALL_STATE(52)] = 923,
  [SMALL_STATE(53)] = 931,
  [SMALL_STATE(54)] = 945,
  [SMALL_STATE(55)] = 959,
  [SMALL_STATE(56)] = 973,
  [SMALL_STATE(57)] = 987,
  [SMALL_STATE(58)] = 996,
  [SMALL_STATE(59)] = 1005,
  [SMALL_STATE(60)] = 1014,
  [SMALL_STATE(61)] = 1020,
  [SMALL_STATE(62)] = 1030,
  [SMALL_STATE(63)] = 1036,
  [SMALL_STATE(64)] = 1042,
  [SMALL_STATE(65)] = 1052,
  [SMALL_STATE(66)] = 1062,
  [SMALL_STATE(67)] = 1072,
  [SMALL_STATE(68)] = 1082,
  [SMALL_STATE(69)] = 1088,
  [SMALL_STATE(70)] = 1098,
  [SMALL_STATE(71)] = 1108,
  [SMALL_STATE(72)] = 1115,
  [SMALL_STATE(73)] = 1120,
  [SMALL_STATE(74)] = 1125,
  [SMALL_STATE(75)] = 1132,
  [SMALL_STATE(76)] = 1139,
  [SMALL_STATE(77)] = 1146,
  [SMALL_STATE(78)] = 1150,
  [SMALL_STATE(79)] = 1154,
  [SMALL_STATE(80)] = 1158,
  [SMALL_STATE(81)] = 1162,
  [SMALL_STATE(82)] = 1166,
  [SMALL_STATE(83)] = 1170,
  [SMALL_STATE(84)] = 1174,
  [SMALL_STATE(85)] = 1178,
  [SMALL_STATE(86)] = 1182,
  [SMALL_STATE(87)] = 1186,
  [SMALL_STATE(88)] = 1190,
  [SMALL_STATE(89)] = 1194,
  [SMALL_STATE(90)] = 1198,
  [SMALL_STATE(91)] = 1202,
  [SMALL_STATE(92)] = 1206,
  [SMALL_STATE(93)] = 1210,
  [SMALL_STATE(94)] = 1214,
  [SMALL_STATE(95)] = 1218,
  [SMALL_STATE(96)] = 1222,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(76),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(83),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(90),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(76),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(83),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(90),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 6, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 6, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 5, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_object, 5, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 4, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event, 4, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 4, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_object, 4, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 4, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_service, 4, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 5, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 5, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 6, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 6, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 4, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 4, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 5, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 5, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 5, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_service, 5, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 5, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event, 5, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 5, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 5, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 5, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 5, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 4, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 4, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reference_type, 1, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_type, 2, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nullable_type, 2, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 3, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 4, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0),
  [198] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [201] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0),
  [218] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [221] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0), SHIFT_REPEAT(95),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 5, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0),
  [250] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [253] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0),
  [262] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [265] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 5, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 3, 0, 0),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 4, 0, 0),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_value, 1, 0, 0),
  [286] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_method_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_method_repeat1, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 7, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [303] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 6, 0, 0),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_type, 3, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [354] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
