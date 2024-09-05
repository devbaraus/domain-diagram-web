#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 87
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 52
#define ALIAS_COUNT 0
#define TOKEN_COUNT 26
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_Context = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_AggregateRoot = 4,
  anon_sym_Entity = 5,
  anon_sym_ValueObject = 6,
  anon_sym_Event = 7,
  anon_sym_Service = 8,
  anon_sym_Repository = 9,
  anon_sym_Enum = 10,
  anon_sym_LPAREN = 11,
  anon_sym_RPAREN = 12,
  anon_sym_COLON = 13,
  anon_sym_EQ = 14,
  anon_sym_COMMA = 15,
  anon_sym_LT = 16,
  anon_sym_GT = 17,
  anon_sym_LBRACK_RBRACK = 18,
  anon_sym_QMARK = 19,
  sym_identifier = 20,
  sym_string = 21,
  sym_number = 22,
  anon_sym_true = 23,
  anon_sym_false = 24,
  sym_null = 25,
  sym_source_file = 26,
  sym__definition = 27,
  sym_context = 28,
  sym_aggregate = 29,
  sym_entity = 30,
  sym_value_object = 31,
  sym_event = 32,
  sym_service = 33,
  sym_repository = 34,
  sym_enum = 35,
  sym_method = 36,
  sym_method_param = 37,
  sym_field = 38,
  sym_generic_type = 39,
  sym_type = 40,
  sym_primitive_type = 41,
  sym_array_type = 42,
  sym_nullable_type = 43,
  sym_value = 44,
  sym_boolean = 45,
  aux_sym_source_file_repeat1 = 46,
  aux_sym_context_repeat1 = 47,
  aux_sym_aggregate_repeat1 = 48,
  aux_sym_value_object_repeat1 = 49,
  aux_sym_service_repeat1 = 50,
  aux_sym_enum_repeat1 = 51,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_Context] = "Context",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_AggregateRoot] = "AggregateRoot",
  [anon_sym_Entity] = "Entity",
  [anon_sym_ValueObject] = "ValueObject",
  [anon_sym_Event] = "Event",
  [anon_sym_Service] = "Service",
  [anon_sym_Repository] = "Repository",
  [anon_sym_Enum] = "Enum",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_COMMA] = ",",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_LBRACK_RBRACK] = "[]",
  [anon_sym_QMARK] = "\?",
  [sym_identifier] = "identifier",
  [sym_string] = "string",
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
  [sym_method] = "method",
  [sym_method_param] = "method_param",
  [sym_field] = "field",
  [sym_generic_type] = "generic_type",
  [sym_type] = "type",
  [sym_primitive_type] = "primitive_type",
  [sym_array_type] = "array_type",
  [sym_nullable_type] = "nullable_type",
  [sym_value] = "value",
  [sym_boolean] = "boolean",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_context_repeat1] = "context_repeat1",
  [aux_sym_aggregate_repeat1] = "aggregate_repeat1",
  [aux_sym_value_object_repeat1] = "value_object_repeat1",
  [aux_sym_service_repeat1] = "service_repeat1",
  [aux_sym_enum_repeat1] = "enum_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_Context] = anon_sym_Context,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_AggregateRoot] = anon_sym_AggregateRoot,
  [anon_sym_Entity] = anon_sym_Entity,
  [anon_sym_ValueObject] = anon_sym_ValueObject,
  [anon_sym_Event] = anon_sym_Event,
  [anon_sym_Service] = anon_sym_Service,
  [anon_sym_Repository] = anon_sym_Repository,
  [anon_sym_Enum] = anon_sym_Enum,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LBRACK_RBRACK] = anon_sym_LBRACK_RBRACK,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [sym_identifier] = sym_identifier,
  [sym_string] = sym_string,
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
  [sym_method] = sym_method,
  [sym_method_param] = sym_method_param,
  [sym_field] = sym_field,
  [sym_generic_type] = sym_generic_type,
  [sym_type] = sym_type,
  [sym_primitive_type] = sym_primitive_type,
  [sym_array_type] = sym_array_type,
  [sym_nullable_type] = sym_nullable_type,
  [sym_value] = sym_value,
  [sym_boolean] = sym_boolean,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_context_repeat1] = aux_sym_context_repeat1,
  [aux_sym_aggregate_repeat1] = aux_sym_aggregate_repeat1,
  [aux_sym_value_object_repeat1] = aux_sym_value_object_repeat1,
  [aux_sym_service_repeat1] = aux_sym_service_repeat1,
  [aux_sym_enum_repeat1] = aux_sym_enum_repeat1,
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
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
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
  [anon_sym_Event] = {
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
  [anon_sym_COMMA] = {
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
  [sym_method] = {
    .visible = true,
    .named = true,
  },
  [sym_method_param] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(66);
      ADVANCE_MAP(
        '"', 1,
        '(', 77,
        ')', 78,
        ',', 81,
        ':', 79,
        '<', 82,
        '=', 80,
        '>', 83,
        '?', 85,
        'A', 23,
        'C', 38,
        'E', 35,
        'R', 12,
        'S', 19,
        'V', 6,
        '[', 5,
        'f', 7,
        'n', 59,
        't', 45,
        '{', 68,
        '}', 69,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(88);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(87);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == ')') ADVANCE(78);
      if (lookahead == ',') ADVANCE(81);
      if (lookahead == '=') ADVANCE(80);
      if (lookahead == '?') ADVANCE(85);
      if (lookahead == '[') ADVANCE(5);
      if (lookahead == '}') ADVANCE(69);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(86);
      END_STATE();
    case 3:
      if (lookahead == 'O') ADVANCE(9);
      END_STATE();
    case 4:
      if (lookahead == 'R') ADVANCE(41);
      END_STATE();
    case 5:
      if (lookahead == ']') ADVANCE(84);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(33);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(30);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(58);
      END_STATE();
    case 9:
      if (lookahead == 'b') ADVANCE(29);
      END_STATE();
    case 10:
      if (lookahead == 'c') ADVANCE(54);
      END_STATE();
    case 11:
      if (lookahead == 'c') ADVANCE(17);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(43);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(3);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(90);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(74);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(4);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(44);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(10);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(37);
      END_STATE();
    case 23:
      if (lookahead == 'g') ADVANCE(25);
      END_STATE();
    case 24:
      if (lookahead == 'g') ADVANCE(8);
      END_STATE();
    case 25:
      if (lookahead == 'g') ADVANCE(47);
      END_STATE();
    case 26:
      if (lookahead == 'i') ADVANCE(11);
      END_STATE();
    case 27:
      if (lookahead == 'i') ADVANCE(51);
      END_STATE();
    case 28:
      if (lookahead == 'i') ADVANCE(56);
      END_STATE();
    case 29:
      if (lookahead == 'j') ADVANCE(20);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(48);
      END_STATE();
    case 31:
      if (lookahead == 'l') ADVANCE(91);
      END_STATE();
    case 32:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(61);
      END_STATE();
    case 34:
      if (lookahead == 'm') ADVANCE(76);
      END_STATE();
    case 35:
      if (lookahead == 'n') ADVANCE(50);
      if (lookahead == 'v') ADVANCE(22);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(52);
      END_STATE();
    case 38:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 39:
      if (lookahead == 'o') ADVANCE(49);
      END_STATE();
    case 40:
      if (lookahead == 'o') ADVANCE(46);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(42);
      END_STATE();
    case 42:
      if (lookahead == 'o') ADVANCE(55);
      END_STATE();
    case 43:
      if (lookahead == 'p') ADVANCE(39);
      END_STATE();
    case 44:
      if (lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 45:
      if (lookahead == 'r') ADVANCE(60);
      END_STATE();
    case 46:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 47:
      if (lookahead == 'r') ADVANCE(21);
      END_STATE();
    case 48:
      if (lookahead == 's') ADVANCE(16);
      END_STATE();
    case 49:
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 50:
      if (lookahead == 't') ADVANCE(27);
      if (lookahead == 'u') ADVANCE(34);
      END_STATE();
    case 51:
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 52:
      if (lookahead == 't') ADVANCE(73);
      END_STATE();
    case 53:
      if (lookahead == 't') ADVANCE(67);
      END_STATE();
    case 54:
      if (lookahead == 't') ADVANCE(72);
      END_STATE();
    case 55:
      if (lookahead == 't') ADVANCE(70);
      END_STATE();
    case 56:
      if (lookahead == 't') ADVANCE(40);
      END_STATE();
    case 57:
      if (lookahead == 't') ADVANCE(14);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(18);
      END_STATE();
    case 59:
      if (lookahead == 'u') ADVANCE(32);
      END_STATE();
    case 60:
      if (lookahead == 'u') ADVANCE(13);
      END_STATE();
    case 61:
      if (lookahead == 'u') ADVANCE(15);
      END_STATE();
    case 62:
      if (lookahead == 'v') ADVANCE(26);
      END_STATE();
    case 63:
      if (lookahead == 'x') ADVANCE(53);
      END_STATE();
    case 64:
      if (lookahead == 'y') ADVANCE(71);
      END_STATE();
    case 65:
      if (lookahead == 'y') ADVANCE(75);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_Context);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_AggregateRoot);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_Entity);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_ValueObject);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_Event);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_Service);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_Repository);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_Enum);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_LBRACK_RBRACK);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 91:
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
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
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
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_Context] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_AggregateRoot] = ACTIONS(1),
    [anon_sym_Entity] = ACTIONS(1),
    [anon_sym_ValueObject] = ACTIONS(1),
    [anon_sym_Event] = ACTIONS(1),
    [anon_sym_Service] = ACTIONS(1),
    [anon_sym_Repository] = ACTIONS(1),
    [anon_sym_Enum] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LBRACK_RBRACK] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_null] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(71),
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
    [anon_sym_AggregateRoot] = ACTIONS(7),
    [anon_sym_Entity] = ACTIONS(9),
    [anon_sym_ValueObject] = ACTIONS(11),
    [anon_sym_Event] = ACTIONS(13),
    [anon_sym_Service] = ACTIONS(15),
    [anon_sym_Repository] = ACTIONS(17),
    [anon_sym_Enum] = ACTIONS(19),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(5), 1,
      anon_sym_Context,
    ACTIONS(7), 1,
      anon_sym_AggregateRoot,
    ACTIONS(9), 1,
      anon_sym_Entity,
    ACTIONS(11), 1,
      anon_sym_ValueObject,
    ACTIONS(13), 1,
      anon_sym_Event,
    ACTIONS(15), 1,
      anon_sym_Service,
    ACTIONS(17), 1,
      anon_sym_Repository,
    ACTIONS(19), 1,
      anon_sym_Enum,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
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
  [40] = 10,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(25), 1,
      anon_sym_Context,
    ACTIONS(28), 1,
      anon_sym_AggregateRoot,
    ACTIONS(31), 1,
      anon_sym_Entity,
    ACTIONS(34), 1,
      anon_sym_ValueObject,
    ACTIONS(37), 1,
      anon_sym_Event,
    ACTIONS(40), 1,
      anon_sym_Service,
    ACTIONS(43), 1,
      anon_sym_Repository,
    ACTIONS(46), 1,
      anon_sym_Enum,
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
  [80] = 9,
    ACTIONS(49), 1,
      anon_sym_RBRACE,
    ACTIONS(51), 1,
      anon_sym_AggregateRoot,
    ACTIONS(54), 1,
      anon_sym_Entity,
    ACTIONS(57), 1,
      anon_sym_ValueObject,
    ACTIONS(60), 1,
      anon_sym_Event,
    ACTIONS(63), 1,
      anon_sym_Service,
    ACTIONS(66), 1,
      anon_sym_Repository,
    ACTIONS(69), 1,
      anon_sym_Enum,
    STATE(4), 8,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_repository,
      sym_enum,
      aux_sym_context_repeat1,
  [115] = 9,
    ACTIONS(7), 1,
      anon_sym_AggregateRoot,
    ACTIONS(9), 1,
      anon_sym_Entity,
    ACTIONS(11), 1,
      anon_sym_ValueObject,
    ACTIONS(13), 1,
      anon_sym_Event,
    ACTIONS(15), 1,
      anon_sym_Service,
    ACTIONS(17), 1,
      anon_sym_Repository,
    ACTIONS(19), 1,
      anon_sym_Enum,
    ACTIONS(72), 1,
      anon_sym_RBRACE,
    STATE(6), 8,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_repository,
      sym_enum,
      aux_sym_context_repeat1,
  [150] = 9,
    ACTIONS(7), 1,
      anon_sym_AggregateRoot,
    ACTIONS(9), 1,
      anon_sym_Entity,
    ACTIONS(11), 1,
      anon_sym_ValueObject,
    ACTIONS(13), 1,
      anon_sym_Event,
    ACTIONS(15), 1,
      anon_sym_Service,
    ACTIONS(17), 1,
      anon_sym_Repository,
    ACTIONS(19), 1,
      anon_sym_Enum,
    ACTIONS(74), 1,
      anon_sym_RBRACE,
    STATE(4), 8,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_event,
      sym_service,
      sym_repository,
      sym_enum,
      aux_sym_context_repeat1,
  [185] = 1,
    ACTIONS(76), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [198] = 1,
    ACTIONS(78), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [211] = 1,
    ACTIONS(80), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [224] = 1,
    ACTIONS(82), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [237] = 1,
    ACTIONS(84), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [250] = 1,
    ACTIONS(86), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [263] = 1,
    ACTIONS(88), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [276] = 1,
    ACTIONS(90), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [289] = 1,
    ACTIONS(92), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [302] = 1,
    ACTIONS(94), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [315] = 1,
    ACTIONS(96), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [328] = 1,
    ACTIONS(98), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [341] = 1,
    ACTIONS(100), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [354] = 1,
    ACTIONS(102), 10,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_RBRACE,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [367] = 1,
    ACTIONS(104), 9,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [379] = 1,
    ACTIONS(106), 9,
      ts_builtin_sym_end,
      anon_sym_Context,
      anon_sym_AggregateRoot,
      anon_sym_Entity,
      anon_sym_ValueObject,
      anon_sym_Event,
      anon_sym_Service,
      anon_sym_Repository,
      anon_sym_Enum,
  [391] = 1,
    ACTIONS(108), 7,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_COMMA,
      anon_sym_LBRACK_RBRACK,
      anon_sym_QMARK,
      sym_identifier,
  [401] = 3,
    ACTIONS(112), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(114), 1,
      anon_sym_QMARK,
    ACTIONS(110), 5,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_COMMA,
      sym_identifier,
  [415] = 4,
    STATE(54), 1,
      sym_boolean,
    STATE(58), 1,
      sym_value,
    ACTIONS(118), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(116), 3,
      sym_string,
      sym_number,
      sym_null,
  [431] = 3,
    ACTIONS(120), 1,
      anon_sym_RBRACE,
    ACTIONS(122), 1,
      sym_identifier,
    STATE(26), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [443] = 1,
    ACTIONS(125), 5,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_COMMA,
      sym_identifier,
  [451] = 4,
    ACTIONS(127), 1,
      sym_identifier,
    STATE(24), 1,
      sym_primitive_type,
    STATE(27), 1,
      sym_type,
    STATE(31), 2,
      sym_array_type,
      sym_nullable_type,
  [465] = 3,
    ACTIONS(129), 1,
      anon_sym_RBRACE,
    ACTIONS(131), 1,
      sym_identifier,
    STATE(26), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [477] = 3,
    ACTIONS(131), 1,
      sym_identifier,
    ACTIONS(133), 1,
      anon_sym_RBRACE,
    STATE(26), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [489] = 1,
    ACTIONS(110), 5,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_COMMA,
      sym_identifier,
  [497] = 1,
    ACTIONS(135), 5,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_COMMA,
      sym_identifier,
  [505] = 1,
    ACTIONS(137), 5,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_EQ,
      anon_sym_COMMA,
      sym_identifier,
  [513] = 3,
    ACTIONS(131), 1,
      sym_identifier,
    ACTIONS(139), 1,
      anon_sym_RBRACE,
    STATE(30), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [525] = 3,
    ACTIONS(131), 1,
      sym_identifier,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    STATE(29), 3,
      sym_method,
      sym_field,
      aux_sym_aggregate_repeat1,
  [537] = 4,
    ACTIONS(127), 1,
      sym_identifier,
    STATE(24), 1,
      sym_primitive_type,
    STATE(59), 1,
      sym_type,
    STATE(31), 2,
      sym_array_type,
      sym_nullable_type,
  [551] = 3,
    ACTIONS(143), 1,
      anon_sym_RBRACE,
    ACTIONS(145), 1,
      sym_identifier,
    STATE(41), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [562] = 3,
    ACTIONS(147), 1,
      anon_sym_RBRACE,
    ACTIONS(149), 1,
      sym_identifier,
    STATE(39), 2,
      sym_method,
      aux_sym_service_repeat1,
  [573] = 3,
    ACTIONS(149), 1,
      sym_identifier,
    ACTIONS(151), 1,
      anon_sym_RBRACE,
    STATE(46), 2,
      sym_method,
      aux_sym_service_repeat1,
  [584] = 3,
    ACTIONS(145), 1,
      sym_identifier,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    STATE(42), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [595] = 3,
    ACTIONS(145), 1,
      sym_identifier,
    ACTIONS(155), 1,
      anon_sym_RBRACE,
    STATE(42), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [606] = 3,
    ACTIONS(157), 1,
      anon_sym_RBRACE,
    ACTIONS(159), 1,
      sym_identifier,
    STATE(42), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [617] = 3,
    ACTIONS(149), 1,
      sym_identifier,
    ACTIONS(162), 1,
      anon_sym_RBRACE,
    STATE(46), 2,
      sym_method,
      aux_sym_service_repeat1,
  [628] = 3,
    ACTIONS(145), 1,
      sym_identifier,
    ACTIONS(164), 1,
      anon_sym_RBRACE,
    STATE(40), 2,
      sym_field,
      aux_sym_value_object_repeat1,
  [639] = 3,
    ACTIONS(149), 1,
      sym_identifier,
    ACTIONS(166), 1,
      anon_sym_RBRACE,
    STATE(43), 2,
      sym_method,
      aux_sym_service_repeat1,
  [650] = 3,
    ACTIONS(168), 1,
      anon_sym_RBRACE,
    ACTIONS(170), 1,
      sym_identifier,
    STATE(46), 2,
      sym_method,
      aux_sym_service_repeat1,
  [661] = 3,
    ACTIONS(173), 1,
      anon_sym_RBRACE,
    ACTIONS(175), 1,
      sym_identifier,
    STATE(48), 1,
      aux_sym_enum_repeat1,
  [671] = 3,
    ACTIONS(177), 1,
      anon_sym_RBRACE,
    ACTIONS(179), 1,
      sym_identifier,
    STATE(51), 1,
      aux_sym_enum_repeat1,
  [681] = 3,
    ACTIONS(145), 1,
      sym_identifier,
    STATE(50), 1,
      sym_field,
    STATE(83), 1,
      sym_method_param,
  [691] = 3,
    ACTIONS(181), 1,
      anon_sym_RPAREN,
    ACTIONS(183), 1,
      anon_sym_EQ,
    ACTIONS(185), 1,
      anon_sym_COMMA,
  [701] = 3,
    ACTIONS(187), 1,
      anon_sym_RBRACE,
    ACTIONS(189), 1,
      sym_identifier,
    STATE(51), 1,
      aux_sym_enum_repeat1,
  [711] = 3,
    ACTIONS(145), 1,
      sym_identifier,
    STATE(50), 1,
      sym_field,
    STATE(86), 1,
      sym_method_param,
  [721] = 3,
    ACTIONS(145), 1,
      sym_identifier,
    STATE(50), 1,
      sym_field,
    STATE(72), 1,
      sym_method_param,
  [731] = 1,
    ACTIONS(192), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [736] = 1,
    ACTIONS(194), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [741] = 2,
    ACTIONS(196), 1,
      anon_sym_LPAREN,
    ACTIONS(198), 1,
      anon_sym_COLON,
  [748] = 2,
    ACTIONS(200), 1,
      anon_sym_LT,
    STATE(67), 1,
      sym_generic_type,
  [755] = 2,
    ACTIONS(202), 1,
      anon_sym_RPAREN,
    ACTIONS(204), 1,
      anon_sym_COMMA,
  [762] = 1,
    ACTIONS(206), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [767] = 2,
    ACTIONS(200), 1,
      anon_sym_LT,
    STATE(68), 1,
      sym_generic_type,
  [774] = 1,
    ACTIONS(208), 1,
      anon_sym_LBRACE,
  [778] = 1,
    ACTIONS(210), 1,
      sym_identifier,
  [782] = 1,
    ACTIONS(198), 1,
      anon_sym_COLON,
  [786] = 1,
    ACTIONS(212), 1,
      anon_sym_LBRACE,
  [790] = 1,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
  [794] = 1,
    ACTIONS(216), 1,
      anon_sym_LBRACE,
  [798] = 1,
    ACTIONS(218), 1,
      sym_identifier,
  [802] = 1,
    ACTIONS(220), 1,
      sym_identifier,
  [806] = 1,
    ACTIONS(222), 1,
      sym_identifier,
  [810] = 1,
    ACTIONS(224), 1,
      anon_sym_LBRACE,
  [814] = 1,
    ACTIONS(226), 1,
      ts_builtin_sym_end,
  [818] = 1,
    ACTIONS(228), 1,
      anon_sym_RPAREN,
  [822] = 1,
    ACTIONS(230), 1,
      anon_sym_GT,
  [826] = 1,
    ACTIONS(232), 1,
      sym_identifier,
  [830] = 1,
    ACTIONS(234), 1,
      sym_identifier,
  [834] = 1,
    ACTIONS(236), 1,
      anon_sym_COLON,
  [838] = 1,
    ACTIONS(238), 1,
      sym_identifier,
  [842] = 1,
    ACTIONS(240), 1,
      anon_sym_LBRACE,
  [846] = 1,
    ACTIONS(242), 1,
      sym_identifier,
  [850] = 1,
    ACTIONS(244), 1,
      anon_sym_LBRACE,
  [854] = 1,
    ACTIONS(246), 1,
      sym_identifier,
  [858] = 1,
    ACTIONS(248), 1,
      anon_sym_LBRACE,
  [862] = 1,
    ACTIONS(202), 1,
      anon_sym_RPAREN,
  [866] = 1,
    ACTIONS(250), 1,
      sym_identifier,
  [870] = 1,
    ACTIONS(196), 1,
      anon_sym_LPAREN,
  [874] = 1,
    ACTIONS(252), 1,
      anon_sym_RPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 40,
  [SMALL_STATE(4)] = 80,
  [SMALL_STATE(5)] = 115,
  [SMALL_STATE(6)] = 150,
  [SMALL_STATE(7)] = 185,
  [SMALL_STATE(8)] = 198,
  [SMALL_STATE(9)] = 211,
  [SMALL_STATE(10)] = 224,
  [SMALL_STATE(11)] = 237,
  [SMALL_STATE(12)] = 250,
  [SMALL_STATE(13)] = 263,
  [SMALL_STATE(14)] = 276,
  [SMALL_STATE(15)] = 289,
  [SMALL_STATE(16)] = 302,
  [SMALL_STATE(17)] = 315,
  [SMALL_STATE(18)] = 328,
  [SMALL_STATE(19)] = 341,
  [SMALL_STATE(20)] = 354,
  [SMALL_STATE(21)] = 367,
  [SMALL_STATE(22)] = 379,
  [SMALL_STATE(23)] = 391,
  [SMALL_STATE(24)] = 401,
  [SMALL_STATE(25)] = 415,
  [SMALL_STATE(26)] = 431,
  [SMALL_STATE(27)] = 443,
  [SMALL_STATE(28)] = 451,
  [SMALL_STATE(29)] = 465,
  [SMALL_STATE(30)] = 477,
  [SMALL_STATE(31)] = 489,
  [SMALL_STATE(32)] = 497,
  [SMALL_STATE(33)] = 505,
  [SMALL_STATE(34)] = 513,
  [SMALL_STATE(35)] = 525,
  [SMALL_STATE(36)] = 537,
  [SMALL_STATE(37)] = 551,
  [SMALL_STATE(38)] = 562,
  [SMALL_STATE(39)] = 573,
  [SMALL_STATE(40)] = 584,
  [SMALL_STATE(41)] = 595,
  [SMALL_STATE(42)] = 606,
  [SMALL_STATE(43)] = 617,
  [SMALL_STATE(44)] = 628,
  [SMALL_STATE(45)] = 639,
  [SMALL_STATE(46)] = 650,
  [SMALL_STATE(47)] = 661,
  [SMALL_STATE(48)] = 671,
  [SMALL_STATE(49)] = 681,
  [SMALL_STATE(50)] = 691,
  [SMALL_STATE(51)] = 701,
  [SMALL_STATE(52)] = 711,
  [SMALL_STATE(53)] = 721,
  [SMALL_STATE(54)] = 731,
  [SMALL_STATE(55)] = 736,
  [SMALL_STATE(56)] = 741,
  [SMALL_STATE(57)] = 748,
  [SMALL_STATE(58)] = 755,
  [SMALL_STATE(59)] = 762,
  [SMALL_STATE(60)] = 767,
  [SMALL_STATE(61)] = 774,
  [SMALL_STATE(62)] = 778,
  [SMALL_STATE(63)] = 782,
  [SMALL_STATE(64)] = 786,
  [SMALL_STATE(65)] = 790,
  [SMALL_STATE(66)] = 794,
  [SMALL_STATE(67)] = 798,
  [SMALL_STATE(68)] = 802,
  [SMALL_STATE(69)] = 806,
  [SMALL_STATE(70)] = 810,
  [SMALL_STATE(71)] = 814,
  [SMALL_STATE(72)] = 818,
  [SMALL_STATE(73)] = 822,
  [SMALL_STATE(74)] = 826,
  [SMALL_STATE(75)] = 830,
  [SMALL_STATE(76)] = 834,
  [SMALL_STATE(77)] = 838,
  [SMALL_STATE(78)] = 842,
  [SMALL_STATE(79)] = 846,
  [SMALL_STATE(80)] = 850,
  [SMALL_STATE(81)] = 854,
  [SMALL_STATE(82)] = 858,
  [SMALL_STATE(83)] = 862,
  [SMALL_STATE(84)] = 866,
  [SMALL_STATE(85)] = 870,
  [SMALL_STATE(86)] = 874,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(84),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(84),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_context_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 5, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 4, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 4, 0, 0),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 4, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repository, 4, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 4, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 5, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 5, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 5, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event, 5, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 6, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_service, 5, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 6, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repository, 5, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 5, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_context, 4, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0),
  [122] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 3, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_type, 2, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nullable_type, 2, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0),
  [159] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_object_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0),
  [170] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_service_repeat1, 2, 0, 0), SHIFT_REPEAT(85),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_param, 1, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0),
  [189] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_param, 3, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method, 6, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [226] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_type, 3, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_param, 5, 0, 0),
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
