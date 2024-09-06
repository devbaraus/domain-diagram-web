#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 100
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 69
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
  anon_sym_Aggregate = 5,
  anon_sym_AggregateRoot = 6,
  anon_sym_Entity = 7,
  anon_sym_ValueObject = 8,
  anon_sym_DomainEvent = 9,
  anon_sym_Event = 10,
  anon_sym_DomainService = 11,
  anon_sym_Service = 12,
  anon_sym_Repository = 13,
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
  sym_repository = 47,
  sym_enum = 48,
  sym_enum_value = 49,
  sym_method = 50,
  sym_field = 51,
  sym_generic_type = 52,
  sym_type = 53,
  sym_reference_type = 54,
  sym_primitive_type = 55,
  sym_array_type = 56,
  sym_nullable_type = 57,
  sym_value = 58,
  sym_array = 59,
  sym_boolean = 60,
  aux_sym_source_file_repeat1 = 61,
  aux_sym_context_repeat1 = 62,
  aux_sym_aggregate_repeat1 = 63,
  aux_sym_value_object_repeat1 = 64,
  aux_sym_service_repeat1 = 65,
  aux_sym_enum_repeat1 = 66,
  aux_sym_method_repeat1 = 67,
  aux_sym_array_repeat1 = 68,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_Context] = "Context",
  [anon_sym_BoundedContext] = "BoundedContext",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
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
  [sym_repository] = "repository",
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
  [sym_repository] = sym_repository,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(119);
      ADVANCE_MAP(
        '"', 1,
        '(', 134,
        ')', 136,
        ',', 135,
        '-', 117,
        ':', 137,
        '<', 139,
        '=', 138,
        '>', 140,
        '?', 156,
        'A', 43,
        'B', 73,
        'C', 80,
        'D', 11,
        'E', 63,
        'F', 56,
        'I', 67,
        'N', 106,
        'R', 24,
        'S', 33,
        'U', 9,
        'V', 12,
        '[', 185,
        ']', 186,
        'f', 13,
        'n', 109,
        't', 84,
        '{', 122,
        '}', 123,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(184);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        ')', 136,
        ',', 135,
        ':', 137,
        '=', 138,
        '?', 156,
        '[', 10,
        ']', 186,
        '}', 123,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 3:
      if (lookahead == 'B') ADVANCE(174);
      if (lookahead == 'D') ADVANCE(160);
      if (lookahead == 'F') ADVANCE(169);
      if (lookahead == 'I') ADVANCE(173);
      if (lookahead == 'N') ADVANCE(182);
      if (lookahead == 'S') ADVANCE(178);
      if (lookahead == 'U') ADVANCE(159);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 4:
      if (lookahead == 'C') ADVANCE(81);
      END_STATE();
    case 5:
      if (lookahead == 'D') ADVANCE(145);
      END_STATE();
    case 6:
      if (lookahead == 'E') ADVANCE(112);
      if (lookahead == 'S') ADVANCE(41);
      END_STATE();
    case 7:
      if (lookahead == 'I') ADVANCE(5);
      END_STATE();
    case 8:
      if (lookahead == 'O') ADVANCE(18);
      END_STATE();
    case 9:
      if (lookahead == 'U') ADVANCE(7);
      END_STATE();
    case 10:
      if (lookahead == ']') ADVANCE(155);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(101);
      if (lookahead == 'o') ADVANCE(62);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(53);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(66);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(49);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 18:
      if (lookahead == 'b') ADVANCE(52);
      END_STATE();
    case 19:
      if (lookahead == 'c') ADVANCE(98);
      END_STATE();
    case 20:
      if (lookahead == 'c') ADVANCE(30);
      END_STATE();
    case 21:
      if (lookahead == 'c') ADVANCE(32);
      END_STATE();
    case 22:
      if (lookahead == 'd') ADVANCE(4);
      END_STATE();
    case 23:
      if (lookahead == 'd') ADVANCE(34);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(82);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(151);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(189);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(113);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(190);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(131);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(124);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(130);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(83);
      if (lookahead == 't') ADVANCE(85);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(45);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(14);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 42:
      if (lookahead == 'g') ADVANCE(141);
      END_STATE();
    case 43:
      if (lookahead == 'g') ADVANCE(44);
      END_STATE();
    case 44:
      if (lookahead == 'g') ADVANCE(87);
      END_STATE();
    case 45:
      if (lookahead == 'g') ADVANCE(17);
      END_STATE();
    case 46:
      if (lookahead == 'i') ADVANCE(20);
      END_STATE();
    case 47:
      if (lookahead == 'i') ADVANCE(68);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(93);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(65);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(102);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 52:
      if (lookahead == 'j') ADVANCE(35);
      END_STATE();
    case 53:
      if (lookahead == 'l') ADVANCE(89);
      END_STATE();
    case 54:
      if (lookahead == 'l') ADVANCE(153);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(191);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(75);
      END_STATE();
    case 57:
      if (lookahead == 'l') ADVANCE(54);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(37);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(55);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(108);
      END_STATE();
    case 61:
      if (lookahead == 'm') ADVANCE(133);
      END_STATE();
    case 62:
      if (lookahead == 'm') ADVANCE(16);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(91);
      if (lookahead == 'v') ADVANCE(39);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(23);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(6);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(147);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(92);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(94);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(97);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(103);
      END_STATE();
    case 72:
      if (lookahead == 'n') ADVANCE(105);
      END_STATE();
    case 73:
      if (lookahead == 'o') ADVANCE(76);
      END_STATE();
    case 74:
      if (lookahead == 'o') ADVANCE(90);
      END_STATE();
    case 75:
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 76:
      if (lookahead == 'o') ADVANCE(58);
      if (lookahead == 'u') ADVANCE(64);
      END_STATE();
    case 77:
      if (lookahead == 'o') ADVANCE(86);
      END_STATE();
    case 78:
      if (lookahead == 'o') ADVANCE(79);
      END_STATE();
    case 79:
      if (lookahead == 'o') ADVANCE(99);
      END_STATE();
    case 80:
      if (lookahead == 'o') ADVANCE(71);
      END_STATE();
    case 81:
      if (lookahead == 'o') ADVANCE(72);
      END_STATE();
    case 82:
      if (lookahead == 'p') ADVANCE(74);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(110);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(107);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(116);
      END_STATE();
    case 87:
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 88:
      if (lookahead == 'r') ADVANCE(111);
      END_STATE();
    case 89:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 90:
      if (lookahead == 's') ADVANCE(50);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(48);
      if (lookahead == 'u') ADVANCE(61);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(143);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(115);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(129);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(149);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(120);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(128);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(127);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(125);
      END_STATE();
    case 100:
      if (lookahead == 't') ADVANCE(121);
      END_STATE();
    case 101:
      if (lookahead == 't') ADVANCE(25);
      END_STATE();
    case 102:
      if (lookahead == 't') ADVANCE(77);
      END_STATE();
    case 103:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 104:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 105:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 106:
      if (lookahead == 'u') ADVANCE(57);
      END_STATE();
    case 107:
      if (lookahead == 'u') ADVANCE(26);
      END_STATE();
    case 108:
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 109:
      if (lookahead == 'u') ADVANCE(59);
      END_STATE();
    case 110:
      if (lookahead == 'v') ADVANCE(46);
      END_STATE();
    case 111:
      if (lookahead == 'v') ADVANCE(51);
      END_STATE();
    case 112:
      if (lookahead == 'v') ADVANCE(40);
      END_STATE();
    case 113:
      if (lookahead == 'x') ADVANCE(96);
      END_STATE();
    case 114:
      if (lookahead == 'x') ADVANCE(100);
      END_STATE();
    case 115:
      if (lookahead == 'y') ADVANCE(126);
      END_STATE();
    case 116:
      if (lookahead == 'y') ADVANCE(132);
      END_STATE();
    case 117:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 118:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_Context);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_BoundedContext);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_Aggregate);
      if (lookahead == 'R') ADVANCE(78);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_AggregateRoot);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_Entity);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_ValueObject);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_DomainEvent);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_Event);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_DomainService);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_Service);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_Repository);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_Enum);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_String);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_String);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_Int);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_Int);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_UUID);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_UUID);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_Boolean);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_Boolean);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_Float);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_Float);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_Date);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_Date);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_Null);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_Null);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_LBRACK_RBRACK);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'I') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(170);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 191:
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
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
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
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 2},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_Context] = ACTIONS(1),
    [anon_sym_BoundedContext] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
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
    [sym_source_file] = STATE(84),
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
    [anon_sym_Aggregate] = ACTIONS(7),
    [anon_sym_AggregateRoot] = ACTIONS(9),
    [anon_sym_Entity] = ACTIONS(11),
    [anon_sym_ValueObject] = ACTIONS(13),
    [anon_sym_DomainEvent] = ACTIONS(15),
    [anon_sym_Event] = ACTIONS(15),
    [anon_sym_DomainService] = ACTIONS(17),
    [anon_sym_Service] = ACTIONS(17),
    [anon_sym_Repository] = ACTIONS(19),
    [anon_sym_Enum] = ACTIONS(21),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(7), 1,
      anon_sym_Aggregate,
    ACTIONS(9), 1,
      anon_sym_AggregateRoot,
    ACTIONS(11), 1,
      anon_sym_Entity,
    ACTIONS(13), 1,
      anon_sym_ValueObject,
    ACTIONS(19), 1,
      anon_sym_Repository,
    ACTIONS(21), 1,
      anon_sym_Enum,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(5), 2,
      anon_sym_Context,
      anon_sym_BoundedContext,
    ACTIONS(15), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(17), 2,
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
  [46] = 11,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(30), 1,
      anon_sym_Aggregate,
    ACTIONS(33), 1,
      anon_sym_AggregateRoot,
    ACTIONS(36), 1,
      anon_sym_Entity,
    ACTIONS(39), 1,
      anon_sym_ValueObject,
    ACTIONS(48), 1,
      anon_sym_Repository,
    ACTIONS(51), 1,
      anon_sym_Enum,
    ACTIONS(27), 2,
      anon_sym_Context,
      anon_sym_BoundedContext,
    ACTIONS(42), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(45), 2,
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
  [92] = 10,
    ACTIONS(54), 1,
      anon_sym_RBRACE,
    ACTIONS(56), 1,
      anon_sym_Aggregate,
    ACTIONS(59), 1,
      anon_sym_AggregateRoot,
    ACTIONS(62), 1,
      anon_sym_Entity,
    ACTIONS(65), 1,
      anon_sym_ValueObject,
    ACTIONS(74), 1,
      anon_sym_Repository,
    ACTIONS(77), 1,
      anon_sym_Enum,
    ACTIONS(68), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(71), 2,
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
  [132] = 10,
    ACTIONS(7), 1,
      anon_sym_Aggregate,
    ACTIONS(9), 1,
      anon_sym_AggregateRoot,
    ACTIONS(11), 1,
      anon_sym_Entity,
    ACTIONS(13), 1,
      anon_sym_ValueObject,
    ACTIONS(19), 1,
      anon_sym_Repository,
    ACTIONS(21), 1,
      anon_sym_Enum,
    ACTIONS(80), 1,
      anon_sym_RBRACE,
    ACTIONS(15), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(17), 2,
      anon_sym_DomainService,
      anon_sym_Service,
    STATE(6), 8,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_repository,
      sym_enum,
      aux_sym_context_repeat1,
  [172] = 10,
    ACTIONS(7), 1,
      anon_sym_Aggregate,
    ACTIONS(9), 1,
      anon_sym_AggregateRoot,
    ACTIONS(11), 1,
      anon_sym_Entity,
    ACTIONS(13), 1,
      anon_sym_ValueObject,
    ACTIONS(19), 1,
      anon_sym_Repository,
    ACTIONS(21), 1,
      anon_sym_Enum,
    ACTIONS(82), 1,
      anon_sym_RBRACE,
    ACTIONS(15), 2,
      anon_sym_DomainEvent,
      anon_sym_Event,
    ACTIONS(17), 2,
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
  [212] = 2,
    ACTIONS(86), 1,
      anon_sym_Aggregate,
    ACTIONS(84), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [231] = 2,
    ACTIONS(90), 1,
      anon_sym_Aggregate,
    ACTIONS(88), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [250] = 2,
    ACTIONS(94), 1,
      anon_sym_Aggregate,
    ACTIONS(92), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [269] = 2,
    ACTIONS(98), 1,
      anon_sym_Aggregate,
    ACTIONS(96), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [288] = 2,
    ACTIONS(102), 1,
      anon_sym_Aggregate,
    ACTIONS(100), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
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
    ACTIONS(106), 1,
      anon_sym_Aggregate,
    ACTIONS(104), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [326] = 2,
    ACTIONS(110), 1,
      anon_sym_Aggregate,
    ACTIONS(108), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [345] = 2,
    ACTIONS(114), 1,
      anon_sym_Aggregate,
    ACTIONS(112), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [364] = 2,
    ACTIONS(118), 1,
      anon_sym_Aggregate,
    ACTIONS(116), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [383] = 2,
    ACTIONS(122), 1,
      anon_sym_Aggregate,
    ACTIONS(120), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [402] = 2,
    ACTIONS(126), 1,
      anon_sym_Aggregate,
    ACTIONS(124), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [421] = 2,
    ACTIONS(130), 1,
      anon_sym_Aggregate,
    ACTIONS(128), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [440] = 2,
    ACTIONS(134), 1,
      anon_sym_Aggregate,
    ACTIONS(132), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [459] = 2,
    ACTIONS(138), 1,
      anon_sym_Aggregate,
    ACTIONS(136), 13,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [478] = 5,
    ACTIONS(142), 1,
      sym_identifier,
    STATE(68), 1,
      sym_type,
    STATE(31), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(43), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(140), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [502] = 5,
    ACTIONS(142), 1,
      sym_identifier,
    STATE(74), 1,
      sym_type,
    STATE(31), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(43), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(140), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [526] = 2,
    ACTIONS(146), 1,
      anon_sym_Aggregate,
    ACTIONS(144), 12,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [544] = 5,
    ACTIONS(142), 1,
      sym_identifier,
    STATE(33), 1,
      sym_type,
    STATE(31), 2,
      sym_reference_type,
      sym_primitive_type,
    STATE(43), 2,
      sym_array_type,
      sym_nullable_type,
    ACTIONS(140), 7,
      anon_sym_String,
      anon_sym_Int,
      anon_sym_UUID,
      anon_sym_Boolean,
      anon_sym_Float,
      anon_sym_Date,
      anon_sym_Null,
  [568] = 2,
    ACTIONS(150), 1,
      anon_sym_Aggregate,
    ACTIONS(148), 12,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_BoundedContext,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_DomainEvent,
      anon_sym_Event,
      anon_sym_DomainService,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [586] = 6,
    ACTIONS(154), 1,
      anon_sym_LBRACK,
    ACTIONS(156), 1,
      anon_sym_RBRACK,
    STATE(61), 1,
      sym_value,
    ACTIONS(158), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(44), 2,
      sym_array,
      sym_boolean,
    ACTIONS(152), 3,
      sym_string,
      sym_number,
      sym_null,
  [609] = 5,
    ACTIONS(154), 1,
      anon_sym_LBRACK,
    STATE(56), 1,
      sym_value,
    ACTIONS(158), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(44), 2,
      sym_array,
      sym_boolean,
    ACTIONS(152), 3,
      sym_string,
      sym_number,
      sym_null,
  [629] = 5,
    ACTIONS(154), 1,
      anon_sym_LBRACK,
    STATE(77), 1,
      sym_value,
    ACTIONS(158), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(44), 2,
      sym_array,
      sym_boolean,
    ACTIONS(152), 3,
      sym_string,
      sym_number,
      sym_null,
  [649] = 1,
    ACTIONS(160), 7,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_LBRACK_RBRACK,
      anon_sym_QMARK,
      sym_identifier,
  [659] = 1,
    ACTIONS(162), 7,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_LBRACK_RBRACK,
      anon_sym_QMARK,
      sym_identifier,
  [669] = 3,
    ACTIONS(166), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(168), 1,
      anon_sym_QMARK,
    ACTIONS(164), 5,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [683] = 1,
    ACTIONS(170), 5,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [691] = 2,
    ACTIONS(174), 1,
      anon_sym_EQ,
    ACTIONS(172), 4,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [701] = 3,
    ACTIONS(176), 1,
      anon_sym_RBRACE,
    ACTIONS(178), 1,
      sym_identifier,
    STATE(37), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [713] = 1,
    ACTIONS(180), 5,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [721] = 3,
    ACTIONS(178), 1,
      sym_identifier,
    ACTIONS(182), 1,
      anon_sym_RBRACE,
    STATE(37), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [733] = 3,
    ACTIONS(184), 1,
      anon_sym_RBRACE,
    ACTIONS(186), 1,
      sym_identifier,
    STATE(37), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [745] = 1,
    ACTIONS(189), 5,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [753] = 3,
    ACTIONS(178), 1,
      sym_identifier,
    ACTIONS(191), 1,
      anon_sym_RBRACE,
    STATE(36), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [765] = 3,
    ACTIONS(178), 1,
      sym_identifier,
    ACTIONS(193), 1,
      anon_sym_RBRACE,
    STATE(34), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [777] = 1,
    ACTIONS(195), 5,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [785] = 1,
    ACTIONS(197), 5,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [793] = 1,
    ACTIONS(164), 5,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [801] = 1,
    ACTIONS(199), 5,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_RBRACK,
  [809] = 1,
    ACTIONS(201), 5,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
      sym_identifier,
  [817] = 3,
    ACTIONS(203), 1,
      anon_sym_RBRACE,
    ACTIONS(205), 1,
      sym_identifier,
    STATE(59), 2,
      sym_method,
      aux_sym_service_repeat1,
  [828] = 3,
    ACTIONS(205), 1,
      sym_identifier,
    ACTIONS(207), 1,
      anon_sym_RBRACE,
    STATE(59), 2,
      sym_method,
      aux_sym_service_repeat1,
  [839] = 3,
    ACTIONS(209), 1,
      anon_sym_RBRACE,
    ACTIONS(211), 1,
      sym_identifier,
    STATE(57), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [850] = 3,
    ACTIONS(213), 1,
      anon_sym_RBRACE,
    ACTIONS(215), 1,
      sym_identifier,
    STATE(51), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [861] = 3,
    ACTIONS(215), 1,
      sym_identifier,
    ACTIONS(217), 1,
      anon_sym_RBRACE,
    STATE(58), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [872] = 3,
    ACTIONS(215), 1,
      sym_identifier,
    ACTIONS(219), 1,
      anon_sym_RBRACE,
    STATE(58), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [883] = 3,
    ACTIONS(211), 1,
      sym_identifier,
    ACTIONS(221), 1,
      anon_sym_RBRACE,
    STATE(48), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [894] = 3,
    ACTIONS(205), 1,
      sym_identifier,
    ACTIONS(223), 1,
      anon_sym_RBRACE,
    STATE(46), 2,
      sym_method,
      aux_sym_service_repeat1,
  [905] = 3,
    ACTIONS(205), 1,
      sym_identifier,
    ACTIONS(225), 1,
      anon_sym_RBRACE,
    STATE(47), 2,
      sym_method,
      aux_sym_service_repeat1,
  [916] = 3,
    ACTIONS(215), 1,
      sym_identifier,
    ACTIONS(227), 1,
      anon_sym_RBRACE,
    STATE(50), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [927] = 1,
    ACTIONS(229), 4,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_identifier,
  [934] = 3,
    ACTIONS(231), 1,
      anon_sym_RBRACE,
    ACTIONS(233), 1,
      sym_identifier,
    STATE(57), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [945] = 3,
    ACTIONS(236), 1,
      anon_sym_RBRACE,
    ACTIONS(238), 1,
      sym_identifier,
    STATE(58), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [956] = 3,
    ACTIONS(241), 1,
      anon_sym_RBRACE,
    ACTIONS(243), 1,
      sym_identifier,
    STATE(59), 2,
      sym_method,
      aux_sym_service_repeat1,
  [967] = 2,
    ACTIONS(248), 1,
      anon_sym_COLON,
    ACTIONS(246), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [975] = 3,
    ACTIONS(250), 1,
      anon_sym_COMMA,
    ACTIONS(252), 1,
      anon_sym_RBRACK,
    STATE(64), 1,
      aux_sym_array_repeat1,
  [985] = 3,
    ACTIONS(254), 1,
      anon_sym_COMMA,
    ACTIONS(257), 1,
      anon_sym_RPAREN,
    STATE(62), 1,
      aux_sym_method_repeat1,
  [995] = 3,
    ACTIONS(259), 1,
      anon_sym_COMMA,
    ACTIONS(262), 1,
      anon_sym_RBRACK,
    STATE(63), 1,
      aux_sym_array_repeat1,
  [1005] = 3,
    ACTIONS(250), 1,
      anon_sym_COMMA,
    ACTIONS(264), 1,
      anon_sym_RBRACK,
    STATE(63), 1,
      aux_sym_array_repeat1,
  [1015] = 3,
    ACTIONS(266), 1,
      anon_sym_COMMA,
    ACTIONS(268), 1,
      anon_sym_RPAREN,
    STATE(67), 1,
      aux_sym_method_repeat1,
  [1025] = 2,
    ACTIONS(272), 1,
      anon_sym_COLON,
    ACTIONS(270), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1033] = 3,
    ACTIONS(266), 1,
      anon_sym_COMMA,
    ACTIONS(274), 1,
      anon_sym_RPAREN,
    STATE(62), 1,
      aux_sym_method_repeat1,
  [1043] = 1,
    ACTIONS(276), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1048] = 2,
    ACTIONS(215), 1,
      sym_identifier,
    STATE(65), 1,
      sym_field,
  [1055] = 2,
    ACTIONS(278), 1,
      anon_sym_LT,
    STATE(89), 1,
      sym_generic_type,
  [1062] = 2,
    ACTIONS(278), 1,
      anon_sym_LT,
    STATE(88), 1,
      sym_generic_type,
  [1069] = 1,
    ACTIONS(257), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1074] = 2,
    ACTIONS(280), 1,
      anon_sym_LPAREN,
    ACTIONS(282), 1,
      anon_sym_COLON,
  [1081] = 1,
    ACTIONS(284), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1086] = 2,
    ACTIONS(215), 1,
      sym_identifier,
    STATE(72), 1,
      sym_field,
  [1093] = 1,
    ACTIONS(286), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1098] = 1,
    ACTIONS(262), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1103] = 1,
    ACTIONS(288), 1,
      sym_identifier,
  [1107] = 1,
    ACTIONS(290), 1,
      anon_sym_LBRACE,
  [1111] = 1,
    ACTIONS(292), 1,
      sym_identifier,
  [1115] = 1,
    ACTIONS(294), 1,
      sym_identifier,
  [1119] = 1,
    ACTIONS(296), 1,
      sym_identifier,
  [1123] = 1,
    ACTIONS(298), 1,
      sym_identifier,
  [1127] = 1,
    ACTIONS(300), 1,
      ts_builtin_sym_end,
  [1131] = 1,
    ACTIONS(302), 1,
      sym_identifier,
  [1135] = 1,
    ACTIONS(304), 1,
      sym_identifier,
  [1139] = 1,
    ACTIONS(306), 1,
      sym_identifier,
  [1143] = 1,
    ACTIONS(308), 1,
      sym_identifier,
  [1147] = 1,
    ACTIONS(310), 1,
      sym_identifier,
  [1151] = 1,
    ACTIONS(312), 1,
      anon_sym_LBRACE,
  [1155] = 1,
    ACTIONS(314), 1,
      anon_sym_LBRACE,
  [1159] = 1,
    ACTIONS(316), 1,
      anon_sym_LBRACE,
  [1163] = 1,
    ACTIONS(318), 1,
      anon_sym_LBRACE,
  [1167] = 1,
    ACTIONS(320), 1,
      anon_sym_LBRACE,
  [1171] = 1,
    ACTIONS(322), 1,
      anon_sym_GT,
  [1175] = 1,
    ACTIONS(324), 1,
      anon_sym_LBRACE,
  [1179] = 1,
    ACTIONS(326), 1,
      anon_sym_LBRACE,
  [1183] = 1,
    ACTIONS(280), 1,
      anon_sym_LPAREN,
  [1187] = 1,
    ACTIONS(282), 1,
      anon_sym_COLON,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 46,
  [SMALL_STATE(4)] = 92,
  [SMALL_STATE(5)] = 132,
  [SMALL_STATE(6)] = 172,
  [SMALL_STATE(7)] = 212,
  [SMALL_STATE(8)] = 231,
  [SMALL_STATE(9)] = 250,
  [SMALL_STATE(10)] = 269,
  [SMALL_STATE(11)] = 288,
  [SMALL_STATE(12)] = 307,
  [SMALL_STATE(13)] = 326,
  [SMALL_STATE(14)] = 345,
  [SMALL_STATE(15)] = 364,
  [SMALL_STATE(16)] = 383,
  [SMALL_STATE(17)] = 402,
  [SMALL_STATE(18)] = 421,
  [SMALL_STATE(19)] = 440,
  [SMALL_STATE(20)] = 459,
  [SMALL_STATE(21)] = 478,
  [SMALL_STATE(22)] = 502,
  [SMALL_STATE(23)] = 526,
  [SMALL_STATE(24)] = 544,
  [SMALL_STATE(25)] = 568,
  [SMALL_STATE(26)] = 586,
  [SMALL_STATE(27)] = 609,
  [SMALL_STATE(28)] = 629,
  [SMALL_STATE(29)] = 649,
  [SMALL_STATE(30)] = 659,
  [SMALL_STATE(31)] = 669,
  [SMALL_STATE(32)] = 683,
  [SMALL_STATE(33)] = 691,
  [SMALL_STATE(34)] = 701,
  [SMALL_STATE(35)] = 713,
  [SMALL_STATE(36)] = 721,
  [SMALL_STATE(37)] = 733,
  [SMALL_STATE(38)] = 745,
  [SMALL_STATE(39)] = 753,
  [SMALL_STATE(40)] = 765,
  [SMALL_STATE(41)] = 777,
  [SMALL_STATE(42)] = 785,
  [SMALL_STATE(43)] = 793,
  [SMALL_STATE(44)] = 801,
  [SMALL_STATE(45)] = 809,
  [SMALL_STATE(46)] = 817,
  [SMALL_STATE(47)] = 828,
  [SMALL_STATE(48)] = 839,
  [SMALL_STATE(49)] = 850,
  [SMALL_STATE(50)] = 861,
  [SMALL_STATE(51)] = 872,
  [SMALL_STATE(52)] = 883,
  [SMALL_STATE(53)] = 894,
  [SMALL_STATE(54)] = 905,
  [SMALL_STATE(55)] = 916,
  [SMALL_STATE(56)] = 927,
  [SMALL_STATE(57)] = 934,
  [SMALL_STATE(58)] = 945,
  [SMALL_STATE(59)] = 956,
  [SMALL_STATE(60)] = 967,
  [SMALL_STATE(61)] = 975,
  [SMALL_STATE(62)] = 985,
  [SMALL_STATE(63)] = 995,
  [SMALL_STATE(64)] = 1005,
  [SMALL_STATE(65)] = 1015,
  [SMALL_STATE(66)] = 1025,
  [SMALL_STATE(67)] = 1033,
  [SMALL_STATE(68)] = 1043,
  [SMALL_STATE(69)] = 1048,
  [SMALL_STATE(70)] = 1055,
  [SMALL_STATE(71)] = 1062,
  [SMALL_STATE(72)] = 1069,
  [SMALL_STATE(73)] = 1074,
  [SMALL_STATE(74)] = 1081,
  [SMALL_STATE(75)] = 1086,
  [SMALL_STATE(76)] = 1093,
  [SMALL_STATE(77)] = 1098,
  [SMALL_STATE(78)] = 1103,
  [SMALL_STATE(79)] = 1107,
  [SMALL_STATE(80)] = 1111,
  [SMALL_STATE(81)] = 1115,
  [SMALL_STATE(82)] = 1119,
  [SMALL_STATE(83)] = 1123,
  [SMALL_STATE(84)] = 1127,
  [SMALL_STATE(85)] = 1131,
  [SMALL_STATE(86)] = 1135,
  [SMALL_STATE(87)] = 1139,
  [SMALL_STATE(88)] = 1143,
  [SMALL_STATE(89)] = 1147,
  [SMALL_STATE(90)] = 1151,
  [SMALL_STATE(91)] = 1155,
  [SMALL_STATE(92)] = 1159,
  [SMALL_STATE(93)] = 1163,
  [SMALL_STATE(94)] = 1167,
  [SMALL_STATE(95)] = 1171,
  [SMALL_STATE(96)] = 1175,
  [SMALL_STATE(97)] = 1179,
  [SMALL_STATE(98)] = 1183,
  [SMALL_STATE(99)] = 1187,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [30] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [33] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(86),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(82),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(80),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(83),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(86),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(82),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(80),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(83),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 5, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_service, 5, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 5, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 5, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 4, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_service, 4, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 4, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_object, 4, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 4, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 4, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 6, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 6, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 6, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 6, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 5, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 5, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repository, 5, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_repository, 5, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 4, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event, 4, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 5, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event, 5, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 5, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_object, 5, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repository, 4, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_repository, 4, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 5, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aggregate, 5, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [142] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 5, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 5, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 4, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_context, 4, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reference_type, 1, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_type, 2, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 3, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0),
  [186] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0), SHIFT_REPEAT(73),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 4, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nullable_type, 2, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 5, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0),
  [233] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0), SHIFT_REPEAT(76),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0),
  [238] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0),
  [243] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 5, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [254] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_method_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_method_repeat1, 2, 0, 0),
  [259] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 4, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 6, 0, 0),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 7, 0, 0),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_value, 1, 0, 0),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [300] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_type, 3, 0, 0),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
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
