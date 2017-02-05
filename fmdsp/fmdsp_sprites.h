static const uint8_t test[] = {
  0, 2, 2, 2,
  2, 0, 0, 0,
  2, 0, 2, 2,
  2, 0, 0, 0,
  2, 0, 0, 0,
};

enum {
  TRACK_H = 32,
  TNAME_W = 26,
  TNAME_H = 5,
  TINFO_X = 48,
  NUM_X = 31,
  NUM_W = 8,
  NUM_H = 11,
  KEY_X = 8,
  KEY_Y = 14,
  KEY_W = 35,
  KEY_H = 17,
  KEY_LEFT_X = 1,
  KEY_LEFT_W = 6,
  KEY_RIGHT_W = 11,
  KEY_OCTAVES = 8,
  BAR_L_X = 68,
  BAR_L_W = 14,
  BAR_X = BAR_L_X + BAR_L_W,
  BAR_Y = 1,
  BAR_W = 2,
  BAR_H = 4,
  BAR_CNT = 64,
  COMMENT_Y = 340,
  COMMENT_H = 19,
  PLAYING_X = 0,
  PLAYING_Y = 324,
  PLAYING_W = 72,
  PLAYING_H = 9,
};

enum {
  PALETTE_NUM = 10
};

#define LCDWR 172
#define LCDWG 239
#define LCDWB 7
#define LCDBR 12
#define LCDBG 91
#define LCDBB 0
#define LCD(C) \
  (LCDWR*(C)+LCDBR*(255-C))/256, \
  (LCDWG*(C)+LCDBG*(255-C))/256, \
  (LCDWB*(C)+LCDBB*(255-C))/256

#define LCDB(C) \
  (LCDBR*(C)+LCDWR*(255-C))/256, \
  (LCDBG*(C)+LCDWG*(255-C))/256, \
  (LCDBB*(C)+LCDWB*(255-C))/256

static const uint8_t s_palettes[PALETTE_NUM][FMDSP_PALETTE_COLORS*3] = {
  {
    0, 0, 0,
    170, 170, 153,
    102, 136, 255,
    68, 68, 119,
    204, 204, 187,
    102, 102, 85,
    136, 255, 68,
    51, 51, 238,
    0, 187, 255,
  },
  {
    0, 0, 0,
    187, 187, 170,
    136, 170, 255,
    85, 85, 153,
    204, 204, 187,
    136, 136, 119,
    153, 255, 119,
    102, 85, 255,
    0, 204, 255,
  },
  {
    0, 0, 0,
    255, 102, 0,
    255, 170, 0,
    102, 68, 51,
    153, 136, 102,
    119, 85, 68,
    255, 221, 85,
    255, 102, 0,
    255, 85, 0,
  },
  {
    0, 0, 0,
    170, 170, 153,
    170, 153, 255,
    85, 51, 102,
    204, 204, 187,
    102, 102, 85,
    119, 255, 34,
    136, 68, 221,
    0, 187, 255,
  },
  {
    0, 0, 0,
    187, 187, 170,
    102, 153, 255,
    85, 68, 136,
    255, 255, 238,
    119, 119, 102,
    255, 68, 0,
    85, 85, 255,
    255, 119, 255,
  },
  {
    0, 0, 0,
    255, 51, 119,
    255, 187, 0,
    85, 85, 68,
    119, 119, 102,
    102, 102, 102,
    255, 221, 0,
    255, 0, 51,
    255, 0, 51,
  },
  {
    102, 170, 238,
    0, 17, 136,
    0, 51, 136,
    153, 221, 255,
    153, 221, 255,
    119, 187, 255,
    0, 51, 136,
    34, 102, 187,
    0, 85, 204,
  },
  {
    0, 0, 0,
    170, 170, 136,
    102, 153, 255,
    17, 0, 51,
    170, 170, 153,
    51, 51, 51,
    85, 255, 68,
    34, 17, 255,
    0, 170, 255,
  },
  {
    LCDB(255),
    LCDB(72),
    LCDB(0),
    LCDB(182),
    LCDB(0),
    LCDB(145),
    LCDB(218),
    LCDB(109),
    LCDB(218),
  },
  {
    LCD(255),
    LCD(72),
    LCD(0),
    LCD(182),
    LCD(145),
    LCD(145),
    LCD(0),
    LCD(109),
    LCD(0),
  },
};

#undef LCDWR
#undef LCDWG
#undef LCDWB
#undef LCDBR
#undef LCDBG
#undef LCDBB
#undef LCD

static const uint8_t s_track[TNAME_W*TNAME_H] = {
  1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
  0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
  0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
  0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1,
};
static const uint8_t s_t_fm[TNAME_W*TNAME_H] = {
  0, 2, 2, 2, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  2, 0, 2, 2, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static const uint8_t s_t_ssg[TNAME_W*TNAME_H] = {
  0, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 2, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static const uint8_t s_t_adpcm[TNAME_W*TNAME_H] = {
  0, 2, 2, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 0, 2, 0, 0, 2, 0, 0,
  2, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0,
  2, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0,
  2, 0, 2, 2, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0,
  2, 0, 0, 2, 0, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 0, 0, 2, 0, 0,
};
static const uint8_t s_t_ppz8[TNAME_W*TNAME_H] = {
  2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0,
  2, 0, 0, 2, 0, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
  2, 0, 0, 2, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0,
  2, 0, 2, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
  2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0,
};
static const uint8_t s_num[10][NUM_W*NUM_H] = {
  {
    0, 0, 0, 2, 2, 2, 0, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 0, 3, 3, 0, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 0, 2, 2, 2, 0, 0, 0,
  },
  {
    0, 0, 0, 3, 3, 3, 0, 0,
    0, 0, 3, 0, 0, 0, 3, 0,
    0, 0, 3, 0, 0, 0, 2, 0,
    0, 0, 3, 0, 0, 0, 2, 0,
    0, 0, 3, 0, 0, 0, 2, 0,
    0, 0, 0, 3, 3, 0, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 0, 3, 3, 3, 0, 0, 0,
  },
  {
    0, 0, 0, 2, 2, 2, 0, 0,
    0, 0, 3, 0, 0, 0, 3, 0,
    0, 0, 3, 0, 0, 0, 2, 0,
    0, 0, 3, 0, 0, 0, 2, 0,
    0, 0, 3, 0, 0, 0, 2, 0,
    0, 0, 0, 2, 2, 0, 0, 0,
    0, 2, 0, 0, 0, 3, 0, 0,
    0, 2, 0, 0, 0, 3, 0, 0,
    0, 2, 0, 0, 0, 3, 0, 0,
    0, 2, 0, 0, 0, 3, 0, 0,
    0, 0, 2, 2, 2, 0, 0, 0,
  },
  {
    0, 0, 0, 2, 2, 2, 0, 0,
    0, 0, 3, 0, 0, 0, 3, 0,
    0, 0, 3, 0, 0, 0, 2, 0,
    0, 0, 3, 0, 0, 0, 2, 0,
    0, 0, 3, 0, 0, 0, 2, 0,
    0, 0, 0, 2, 2, 0, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 0, 2, 2, 2, 0, 0, 0,
  },
  {
    0, 0, 0, 3, 3, 3, 0, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 0, 2, 2, 0, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 0, 3, 3, 3, 0, 0, 0,
  },
  {
    0, 0, 0, 2, 2, 2, 0, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 0, 2, 2, 0, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 0, 2, 2, 2, 0, 0, 0,
  },
  {
    0, 0, 0, 2, 2, 2, 0, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 0, 2, 2, 0, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 0, 2, 2, 2, 0, 0, 0,
  },
  {
    0, 0, 0, 2, 2, 2, 0, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 0, 3, 3, 0, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 0, 3, 3, 3, 0, 0, 0,
  },
  {
    0, 0, 0, 2, 2, 2, 0, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 0, 2, 2, 0, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 2, 0, 0, 0, 2, 0, 0,
    0, 0, 2, 2, 2, 0, 0, 0,
  },
  {
    0, 0, 0, 2, 2, 2, 0, 0,
    0, 0, 2, 0, 0, 0, 3, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 2, 0, 0, 0, 2, 0,
    0, 0, 0, 2, 2, 0, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 3, 0, 0, 0, 2, 0, 0,
    0, 0, 2, 2, 2, 0, 0, 0,
  }
};
static const uint8_t s_key_bg[KEY_W*KEY_H] = {
  4,4,4,0,0,0,4,4,0,0,0,4,4,4,0,4,4,4,0,0,0,4,4,0,0,0,4,4,0,0,0,4,4,4,0,
  4,4,4,0,0,0,4,4,0,0,0,4,4,4,0,4,4,4,0,0,0,4,4,0,0,0,4,4,0,0,0,4,4,4,0,
  4,4,4,0,0,0,4,4,0,0,0,4,4,4,0,4,4,4,0,0,0,4,4,0,0,0,4,4,0,0,0,4,4,4,0,
  4,4,4,0,0,0,4,4,0,0,0,4,4,4,0,4,4,4,0,0,0,4,4,0,0,0,4,4,0,0,0,4,4,4,0,
  4,4,4,0,0,0,4,4,0,0,0,4,4,4,0,4,4,4,0,0,0,4,4,0,0,0,4,4,0,0,0,4,4,4,0,
  4,4,4,0,0,0,4,4,0,0,0,4,4,4,0,4,4,4,0,0,0,4,4,0,0,0,4,4,0,0,0,4,4,4,0,
  4,4,4,0,0,0,4,4,0,0,0,4,4,4,0,4,4,4,0,0,0,4,4,0,0,0,4,4,0,0,0,4,4,4,0,
  4,4,4,5,0,0,4,4,5,0,0,4,4,4,0,4,4,4,5,0,0,4,4,5,0,0,4,4,5,0,0,4,4,4,0,
  4,4,4,5,5,0,4,4,5,5,0,4,4,4,0,4,4,4,5,5,0,4,4,5,5,0,4,4,5,5,0,4,4,4,0,
  4,4,4,0,0,0,4,4,0,0,0,4,4,4,0,4,4,4,0,0,0,4,4,0,0,0,4,4,0,0,0,4,4,4,0,
  4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,
  4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,
  4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,
  4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,
  4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,
  4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,4,4,4,4,0,
  5,4,4,5,0,5,4,4,5,0,5,4,4,5,0,5,4,4,5,0,5,4,4,5,0,5,4,4,5,0,5,4,4,5,0,
};
static const uint8_t s_key_left[KEY_LEFT_W*KEY_H] = {
  0, 0, 0, 4, 4, 4,
  0, 0, 0, 4, 4, 4,
  0, 0, 0, 4, 4, 4,
  0, 0, 0, 4, 4, 4,
  0, 0, 0, 4, 4, 4,
  0, 0, 0, 4, 4, 4,
  0, 0, 0, 4, 4, 4,
  5, 0, 0, 4, 4, 4,
  5, 5, 0, 4, 4, 4,
  0, 0, 0, 4, 4, 4,
  4, 0, 4, 4, 4, 4,
  4, 0, 4, 4, 4, 4,
  4, 0, 4, 4, 4, 4,
  4, 0, 4, 4, 4, 4,
  4, 0, 4, 4, 4, 4,
  4, 0, 4, 4, 4, 4,
  5, 0, 5, 4, 4, 5,
};
static const uint8_t s_key_right[KEY_RIGHT_W*KEY_H] = {
  4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0,
  4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0,
  4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0,
  4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0,
  4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0,
  4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0,
  4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0,
  4, 4, 4, 5, 0, 0, 4, 4, 5, 0, 0,
  4, 4, 4, 5, 5, 0, 4, 4, 5, 5, 0,
  4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0,
  4, 4, 4, 4, 0, 4, 4, 4, 4, 0, 4,
  4, 4, 4, 4, 0, 4, 4, 4, 4, 0, 4,
  4, 4, 4, 4, 0, 4, 4, 4, 4, 0, 4,
  4, 4, 4, 4, 0, 4, 4, 4, 4, 0, 4,
  4, 4, 4, 4, 0, 4, 4, 4, 4, 0, 4,
  4, 4, 4, 4, 0, 4, 4, 4, 4, 0, 4,
  5, 4, 4, 5, 0, 5, 4, 4, 5, 0, 5,
};
static const uint8_t s_key_mask[KEY_W*KEY_H] = {
  1,1,1,2,2,2,3,3,4,4,4,5,5,5,0,6,6,6,7,7,7,8,8,9,9,9, 10,10,11,11,11,12,12,12,0,
  1,1,1,2,2,2,3,3,4,4,4,5,5,5,0,6,6,6,7,7,7,8,8,9,9,9, 10,10,11,11,11,12,12,12,0,
  1,1,1,2,2,2,3,3,4,4,4,5,5,5,0,6,6,6,7,7,7,8,8,9,9,9, 10,10,11,11,11,12,12,12,0,
  1,1,1,2,2,2,3,3,4,4,4,5,5,5,0,6,6,6,7,7,7,8,8,9,9,9, 10,10,11,11,11,12,12,12,0,
  1,1,1,2,2,2,3,3,4,4,4,5,5,5,0,6,6,6,7,7,7,8,8,9,9,9, 10,10,11,11,11,12,12,12,0,
  1,1,1,2,2,2,3,3,4,4,4,5,5,5,0,6,6,6,7,7,7,8,8,9,9,9, 10,10,11,11,11,12,12,12,0,
  1,1,1,2,2,2,3,3,4,4,4,5,5,5,0,6,6,6,7,7,7,8,8,9,9,9, 10,10,11,11,11,12,12,12,0,
  1,1,1,0,2,2,3,3,0,4,4,5,5,5,0,6,6,6,0,7,7,8,8,0,9,9, 10,10,0, 11,11,12,12,12,0,
  1,1,1,0,0,2,3,3,0,0,4,5,5,5,0,6,6,6,0,0,7,8,8,0,0,9, 10,10,0, 0, 11,12,12,12,0,
  1,1,1,2,2,2,3,3,4,4,4,5,5,5,0,6,6,6,7,7,7,8,8,9,9,9, 10,10,11,11,11,12,12,12,0,
  1,1,1,1,0,3,3,3,3,0,5,5,5,5,0,6,6,6,6,0,8,8,8,8,0,10,10,10,10,0, 12,12,12,12,0,
  1,1,1,1,0,3,3,3,3,0,5,5,5,5,0,6,6,6,6,0,8,8,8,8,0,10,10,10,10,0, 12,12,12,12,0,
  1,1,1,1,0,3,3,3,3,0,5,5,5,5,0,6,6,6,6,0,8,8,8,8,0,10,10,10,10,0, 12,12,12,12,0,
  1,1,1,1,0,3,3,3,3,0,5,5,5,5,0,6,6,6,6,0,8,8,8,8,0,10,10,10,10,0, 12,12,12,12,0,
  1,1,1,1,0,3,3,3,3,0,5,5,5,5,0,6,6,6,6,0,8,8,8,8,0,10,10,10,10,0, 12,12,12,12,0,
  1,1,1,1,0,3,3,3,3,0,5,5,5,5,0,6,6,6,6,0,8,8,8,8,0,10,10,10,10,0, 12,12,12,12,0,
  0,1,1,0,0,0,3,3,0,0,0,5,5,0,0,0,6,6,0,0,0,8,8,0,0,0, 10,10,0, 0, 0, 12,12,0, 0,
};
static const uint8_t s_bar_l[BAR_L_W*BAR_H] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
};
static const uint8_t s_bar[BAR_W*BAR_H] = {
  1, 0,
  1, 0,
  1, 0,
  1, 0,
};
static const uint8_t s_playing[PLAYING_W*PLAYING_H] = {
  2,2,2,2,2,2,2,0,0,2,2,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,2,2,0,0,0,0,2,2,0,2,2,0,2,2,0,0,0,0,2,2,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  2,2,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,2,2,2,0,0,0,2,2,0,2,2,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  2,2,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,2,2,2,2,0,0,0,2,2,0,2,2,2,2,0,0,2,2,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  2,2,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,2,2,0,2,2,0,2,2,0,2,2,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  2,2,2,2,2,2,2,0,0,2,2,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,2,2,0,0,2,2,2,2,0,2,2,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  2,2,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,2,2,0,0,0,2,2,2,0,2,2,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,
  2,2,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,2,2,0,0,0,0,2,2,0,0,2,2,2,2,2,2,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
};
