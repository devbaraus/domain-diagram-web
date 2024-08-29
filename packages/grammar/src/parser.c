#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 50
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 25
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_aggregate = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_entity = 4,
  anon_sym_value_object = 5,
  anon_sym_enum = 6,
  anon_sym_COLON = 7,
  anon_sym_LT = 8,
  anon_sym_GT = 9,
  anon_sym_LBRACK_RBRACK = 10,
  sym_identifier = 11,
  sym_source_file = 12,
  sym__definition = 13,
  sym_aggregate = 14,
  sym_entity = 15,
  sym_value_object = 16,
  sym_enum = 17,
  sym_enum_value = 18,
  sym_field = 19,
  sym_generic_type = 20,
  sym_type = 21,
  aux_sym_source_file_repeat1 = 22,
  aux_sym_aggregate_repeat1 = 23,
  aux_sym_enum_repeat1 = 24,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_aggregate] = "aggregate",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_entity] = "entity",
  [anon_sym_value_object] = "value_object",
  [anon_sym_enum] = "enum",
  [anon_sym_COLON] = ":",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_LBRACK_RBRACK] = "[]",
  [sym_identifier] = "identifier",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_aggregate] = "aggregate",
  [sym_entity] = "entity",
  [sym_value_object] = "value_object",
  [sym_enum] = "enum",
  [sym_enum_value] = "enum_value",
  [sym_field] = "field",
  [sym_generic_type] = "generic_type",
  [sym_type] = "type",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_aggregate_repeat1] = "aggregate_repeat1",
  [aux_sym_enum_repeat1] = "enum_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_aggregate] = anon_sym_aggregate,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_entity] = anon_sym_entity,
  [anon_sym_value_object] = anon_sym_value_object,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LBRACK_RBRACK] = anon_sym_LBRACK_RBRACK,
  [sym_identifier] = sym_identifier,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_aggregate] = sym_aggregate,
  [sym_entity] = sym_entity,
  [sym_value_object] = sym_value_object,
  [sym_enum] = sym_enum,
  [sym_enum_value] = sym_enum_value,
  [sym_field] = sym_field,
  [sym_generic_type] = sym_generic_type,
  [sym_type] = sym_type,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_aggregate_repeat1] = aux_sym_aggregate_repeat1,
  [aux_sym_enum_repeat1] = aux_sym_enum_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_aggregate] = {
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
  [anon_sym_entity] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_value_object] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
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
  [sym_identifier] = {
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
  [sym_enum] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_value] = {
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
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_aggregate_repeat1] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(28);
      ADVANCE_MAP(
        ':', 35,
        '<', 36,
        '>', 37,
        '[', 2,
        'a', 13,
        'e', 19,
        'v', 4,
        '{', 30,
        '}', 31,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '<') ADVANCE(36);
      if (lookahead == '[') ADVANCE(2);
      if (lookahead == '}') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      END_STATE();
    case 2:
      if (lookahead == ']') ADVANCE(38);
      END_STATE();
    case 3:
      if (lookahead == '_') ADVANCE(20);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(17);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(25);
      END_STATE();
    case 6:
      if (lookahead == 'b') ADVANCE(16);
      END_STATE();
    case 7:
      if (lookahead == 'c') ADVANCE(24);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(3);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(7);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(14);
      END_STATE();
    case 12:
      if (lookahead == 'g') ADVANCE(21);
      END_STATE();
    case 13:
      if (lookahead == 'g') ADVANCE(12);
      END_STATE();
    case 14:
      if (lookahead == 'g') ADVANCE(5);
      END_STATE();
    case 15:
      if (lookahead == 'i') ADVANCE(23);
      END_STATE();
    case 16:
      if (lookahead == 'j') ADVANCE(10);
      END_STATE();
    case 17:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 18:
      if (lookahead == 'm') ADVANCE(34);
      END_STATE();
    case 19:
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 20:
      if (lookahead == 'o') ADVANCE(6);
      END_STATE();
    case 21:
      if (lookahead == 'r') ADVANCE(11);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(15);
      if (lookahead == 'u') ADVANCE(18);
      END_STATE();
    case 23:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 24:
      if (lookahead == 't') ADVANCE(33);
      END_STATE();
    case 25:
      if (lookahead == 't') ADVANCE(9);
      END_STATE();
    case 26:
      if (lookahead == 'u') ADVANCE(8);
      END_STATE();
    case 27:
      if (lookahead == 'y') ADVANCE(32);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_aggregate);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_value_object);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_LBRACK_RBRACK);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
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
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_aggregate] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_entity] = ACTIONS(1),
    [anon_sym_value_object] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LBRACK_RBRACK] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(48),
    [sym__definition] = STATE(2),
    [sym_aggregate] = STATE(2),
    [sym_entity] = STATE(2),
    [sym_value_object] = STATE(2),
    [sym_enum] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_aggregate] = ACTIONS(5),
    [anon_sym_entity] = ACTIONS(7),
    [anon_sym_value_object] = ACTIONS(9),
    [anon_sym_enum] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(5), 1,
      anon_sym_aggregate,
    ACTIONS(7), 1,
      anon_sym_entity,
    ACTIONS(9), 1,
      anon_sym_value_object,
    ACTIONS(11), 1,
      anon_sym_enum,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    STATE(3), 6,
      sym__definition,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_enum,
      aux_sym_source_file_repeat1,
  [24] = 6,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      anon_sym_aggregate,
    ACTIONS(20), 1,
      anon_sym_entity,
    ACTIONS(23), 1,
      anon_sym_value_object,
    ACTIONS(26), 1,
      anon_sym_enum,
    STATE(3), 6,
      sym__definition,
      sym_aggregate,
      sym_entity,
      sym_value_object,
      sym_enum,
      aux_sym_source_file_repeat1,
  [48] = 1,
    ACTIONS(29), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [56] = 1,
    ACTIONS(31), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [64] = 1,
    ACTIONS(33), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [72] = 1,
    ACTIONS(35), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [80] = 1,
    ACTIONS(37), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [88] = 1,
    ACTIONS(39), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [96] = 1,
    ACTIONS(41), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [104] = 1,
    ACTIONS(43), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [112] = 1,
    ACTIONS(45), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [120] = 1,
    ACTIONS(47), 5,
      ts_builtin_sym_end,
      anon_sym_aggregate,
      anon_sym_entity,
      anon_sym_value_object,
      anon_sym_enum,
  [128] = 3,
    ACTIONS(49), 1,
      anon_sym_RBRACE,
    ACTIONS(51), 1,
      sym_identifier,
    STATE(19), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [139] = 3,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(53), 1,
      anon_sym_RBRACE,
    STATE(19), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [150] = 3,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(55), 1,
      anon_sym_RBRACE,
    STATE(14), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [161] = 3,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(57), 1,
      anon_sym_RBRACE,
    STATE(19), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [172] = 3,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(59), 1,
      anon_sym_RBRACE,
    STATE(24), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [183] = 3,
    ACTIONS(61), 1,
      anon_sym_RBRACE,
    ACTIONS(63), 1,
      sym_identifier,
    STATE(19), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [194] = 3,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(66), 1,
      anon_sym_RBRACE,
    STATE(27), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [205] = 3,
    ACTIONS(68), 1,
      anon_sym_RBRACE,
    ACTIONS(70), 1,
      sym_identifier,
    STATE(22), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [216] = 3,
    ACTIONS(70), 1,
      sym_identifier,
    ACTIONS(72), 1,
      anon_sym_RBRACE,
    STATE(26), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [227] = 3,
    ACTIONS(49), 1,
      anon_sym_RBRACE,
    ACTIONS(51), 1,
      sym_identifier,
    STATE(17), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [238] = 3,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(74), 1,
      anon_sym_RBRACE,
    STATE(19), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [249] = 3,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(74), 1,
      anon_sym_RBRACE,
    STATE(15), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [260] = 3,
    ACTIONS(76), 1,
      anon_sym_RBRACE,
    ACTIONS(78), 1,
      sym_identifier,
    STATE(26), 2,
      sym_enum_value,
      aux_sym_enum_repeat1,
  [271] = 3,
    ACTIONS(51), 1,
      sym_identifier,
    ACTIONS(81), 1,
      anon_sym_RBRACE,
    STATE(19), 2,
      sym_field,
      aux_sym_aggregate_repeat1,
  [282] = 3,
    ACTIONS(83), 1,
      anon_sym_LT,
    ACTIONS(85), 1,
      sym_identifier,
    STATE(35), 1,
      sym_generic_type,
  [292] = 3,
    ACTIONS(83), 1,
      anon_sym_LT,
    ACTIONS(87), 1,
      sym_identifier,
    STATE(45), 1,
      sym_generic_type,
  [302] = 2,
    ACTIONS(91), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(89), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [310] = 1,
    ACTIONS(93), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [315] = 2,
    ACTIONS(95), 1,
      sym_identifier,
    STATE(31), 1,
      sym_type,
  [322] = 1,
    ACTIONS(97), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [327] = 1,
    ACTIONS(99), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [332] = 1,
    ACTIONS(101), 1,
      sym_identifier,
  [336] = 1,
    ACTIONS(103), 1,
      sym_identifier,
  [340] = 1,
    ACTIONS(105), 1,
      anon_sym_COLON,
  [344] = 1,
    ACTIONS(107), 1,
      sym_identifier,
  [348] = 1,
    ACTIONS(109), 1,
      anon_sym_LBRACE,
  [352] = 1,
    ACTIONS(111), 1,
      anon_sym_LBRACE,
  [356] = 1,
    ACTIONS(113), 1,
      anon_sym_GT,
  [360] = 1,
    ACTIONS(115), 1,
      anon_sym_LBRACE,
  [364] = 1,
    ACTIONS(117), 1,
      anon_sym_LBRACE,
  [368] = 1,
    ACTIONS(119), 1,
      anon_sym_LBRACE,
  [372] = 1,
    ACTIONS(121), 1,
      sym_identifier,
  [376] = 1,
    ACTIONS(123), 1,
      anon_sym_LBRACE,
  [380] = 1,
    ACTIONS(125), 1,
      sym_identifier,
  [384] = 1,
    ACTIONS(127), 1,
      ts_builtin_sym_end,
  [388] = 1,
    ACTIONS(129), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 56,
  [SMALL_STATE(6)] = 64,
  [SMALL_STATE(7)] = 72,
  [SMALL_STATE(8)] = 80,
  [SMALL_STATE(9)] = 88,
  [SMALL_STATE(10)] = 96,
  [SMALL_STATE(11)] = 104,
  [SMALL_STATE(12)] = 112,
  [SMALL_STATE(13)] = 120,
  [SMALL_STATE(14)] = 128,
  [SMALL_STATE(15)] = 139,
  [SMALL_STATE(16)] = 150,
  [SMALL_STATE(17)] = 161,
  [SMALL_STATE(18)] = 172,
  [SMALL_STATE(19)] = 183,
  [SMALL_STATE(20)] = 194,
  [SMALL_STATE(21)] = 205,
  [SMALL_STATE(22)] = 216,
  [SMALL_STATE(23)] = 227,
  [SMALL_STATE(24)] = 238,
  [SMALL_STATE(25)] = 249,
  [SMALL_STATE(26)] = 260,
  [SMALL_STATE(27)] = 271,
  [SMALL_STATE(28)] = 282,
  [SMALL_STATE(29)] = 292,
  [SMALL_STATE(30)] = 302,
  [SMALL_STATE(31)] = 310,
  [SMALL_STATE(32)] = 315,
  [SMALL_STATE(33)] = 322,
  [SMALL_STATE(34)] = 327,
  [SMALL_STATE(35)] = 332,
  [SMALL_STATE(36)] = 336,
  [SMALL_STATE(37)] = 340,
  [SMALL_STATE(38)] = 344,
  [SMALL_STATE(39)] = 348,
  [SMALL_STATE(40)] = 352,
  [SMALL_STATE(41)] = 356,
  [SMALL_STATE(42)] = 360,
  [SMALL_STATE(43)] = 364,
  [SMALL_STATE(44)] = 368,
  [SMALL_STATE(45)] = 372,
  [SMALL_STATE(46)] = 376,
  [SMALL_STATE(47)] = 380,
  [SMALL_STATE(48)] = 384,
  [SMALL_STATE(49)] = 388,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 4, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 5, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 6, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 6, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 4, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 4, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 4, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 5, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate, 5, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_object, 5, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_aggregate_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 3, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 2, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_value, 1, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_type, 3, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [127] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
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
