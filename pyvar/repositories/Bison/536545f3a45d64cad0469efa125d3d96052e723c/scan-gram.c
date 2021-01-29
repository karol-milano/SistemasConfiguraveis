@@ -705,16 +705,16 @@ int yy_flex_debug = 1;
 
 static yyconst short int yy_rule_linenum[101] =
     {   0,
-      122,  123,  124,  125,  126,  127,  128,  129,  130,  131,
-      132,  133,  134,  135,  136,  137,  138,  139,  140,  141,
-      142,  143,  144,  145,  146,  147,  148,  149,  150,  151,
-      152,  153,  155,  156,  157,  158,  160,  161,  162,  167,
-      170,  173,  176,  177,  180,  183,  186,  194,  200,  216,
-      217,  228,  240,  241,  242,  259,  268,  270,  290,  305,
-      307,  327,  339,  343,  344,  345,  346,  347,  348,  349,
-      350,  351,  357,  368,  374,  375,  377,  379,  397,  403,
-      404,  406,  408,  426,  429,  432,  433,  436,  447,  458,
-      460,  462,  465,  466,  469,  489,  496,  497,  498,  518
+      121,  122,  123,  124,  125,  126,  127,  128,  129,  130,
+      131,  132,  133,  134,  135,  136,  137,  138,  139,  140,
+      141,  142,  143,  144,  145,  146,  147,  148,  149,  150,
+      151,  152,  154,  155,  156,  157,  159,  160,  161,  166,
+      169,  172,  175,  176,  179,  182,  185,  193,  199,  215,
+      216,  227,  239,  240,  241,  258,  267,  269,  289,  304,
+      306,  326,  338,  342,  343,  344,  345,  346,  347,  348,
+      349,  350,  356,  367,  373,  374,  376,  378,  396,  402,
+      403,  405,  407,  425,  428,  431,  432,  435,  446,  457,
+      459,  461,  464,  465,  468,  488,  495,  496,  497,  517
 
     } ;
 
@@ -771,7 +771,6 @@ do {						\
 #define YY_LINES        LOCATION_LINES (*yylloc, yyleng); lineno += yyleng;
 #define YY_STEP         LOCATION_STEP (*yylloc)
 
-
 /* STRING_OBSTACK -- Used to store all the characters that we need to
    keep (to construct ID, STRINGS etc.).  Use the following macros to
    use it.
@@ -825,7 +824,7 @@ static void handle_at PARAMS ((braced_code_t code_kind,
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 829 "lex.yy.c"
+#line 828 "lex.yy.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -987,7 +986,7 @@ YY_DECL
 	register char *yy_cp, *yy_bp;
 	register int yy_act;
 
-#line 98 "scan-gram.l"
+#line 97 "scan-gram.l"
 
 
   /* At each yylex invocation, mark the current position as the
@@ -1010,7 +1009,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1014 "lex.yy.c"
+#line 1013 "lex.yy.c"
 
 	if ( yy_init )
 		{
@@ -1112,197 +1111,197 @@ do_action:	/* This label is used only to access EOF actions. */
 
 case 1:
 YY_RULE_SETUP
-#line 122 "scan-gram.l"
+#line 121 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 2:
 YY_RULE_SETUP
-#line 123 "scan-gram.l"
+#line 122 "scan-gram.l"
 return PERCENT_DEBUG;
 	YY_BREAK
 case 3:
 YY_RULE_SETUP
-#line 124 "scan-gram.l"
+#line 123 "scan-gram.l"
 return PERCENT_DEFINE;
 	YY_BREAK
 case 4:
 YY_RULE_SETUP
-#line 125 "scan-gram.l"
+#line 124 "scan-gram.l"
 return PERCENT_DEFINES;
 	YY_BREAK
 case 5:
 YY_RULE_SETUP
-#line 126 "scan-gram.l"
+#line 125 "scan-gram.l"
 return PERCENT_DESTRUCTOR;
 	YY_BREAK
 case 6:
 YY_RULE_SETUP
-#line 127 "scan-gram.l"
+#line 126 "scan-gram.l"
 return PERCENT_DPREC;
 	YY_BREAK
 case 7:
 YY_RULE_SETUP
-#line 128 "scan-gram.l"
+#line 127 "scan-gram.l"
 return PERCENT_ERROR_VERBOSE;
 	YY_BREAK
 case 8:
 YY_RULE_SETUP
-#line 129 "scan-gram.l"
+#line 128 "scan-gram.l"
 return PERCENT_EXPECT;
 	YY_BREAK
 case 9:
 YY_RULE_SETUP
-#line 130 "scan-gram.l"
+#line 129 "scan-gram.l"
 return PERCENT_FILE_PREFIX;
 	YY_BREAK
 case 10:
 YY_RULE_SETUP
-#line 131 "scan-gram.l"
+#line 130 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 11:
 YY_RULE_SETUP
-#line 132 "scan-gram.l"
+#line 131 "scan-gram.l"
 return PERCENT_GLR_PARSER;
 	YY_BREAK
 case 12:
 YY_RULE_SETUP
-#line 133 "scan-gram.l"
+#line 132 "scan-gram.l"
 return PERCENT_LEFT;
 	YY_BREAK
 case 13:
 YY_RULE_SETUP
-#line 134 "scan-gram.l"
+#line 133 "scan-gram.l"
 return PERCENT_LOCATIONS;
 	YY_BREAK
 case 14:
 YY_RULE_SETUP
-#line 135 "scan-gram.l"
+#line 134 "scan-gram.l"
 return PERCENT_MERGE;
 	YY_BREAK
 case 15:
 YY_RULE_SETUP
-#line 136 "scan-gram.l"
+#line 135 "scan-gram.l"
 return PERCENT_NAME_PREFIX;
 	YY_BREAK
 case 16:
 YY_RULE_SETUP
-#line 137 "scan-gram.l"
+#line 136 "scan-gram.l"
 return PERCENT_NO_LINES;
 	YY_BREAK
 case 17:
 YY_RULE_SETUP
-#line 138 "scan-gram.l"
+#line 137 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 18:
 YY_RULE_SETUP
-#line 139 "scan-gram.l"
+#line 138 "scan-gram.l"
 return PERCENT_NTERM;
 	YY_BREAK
 case 19:
 YY_RULE_SETUP
-#line 140 "scan-gram.l"
+#line 139 "scan-gram.l"
 return PERCENT_OUTPUT;
 	YY_BREAK
 case 20:
 YY_RULE_SETUP
-#line 141 "scan-gram.l"
+#line 140 "scan-gram.l"
 return PERCENT_PREC;
 	YY_BREAK
 case 21:
 YY_RULE_SETUP
-#line 142 "scan-gram.l"
+#line 141 "scan-gram.l"
 return PERCENT_PRINTER;
 	YY_BREAK
 case 22:
 YY_RULE_SETUP
-#line 143 "scan-gram.l"
+#line 142 "scan-gram.l"
 return PERCENT_PURE_PARSER;
 	YY_BREAK
 case 23:
 YY_RULE_SETUP
-#line 144 "scan-gram.l"
+#line 143 "scan-gram.l"
 return PERCENT_RIGHT;
 	YY_BREAK
 case 24:
 YY_RULE_SETUP
-#line 145 "scan-gram.l"
+#line 144 "scan-gram.l"
 return PERCENT_SKELETON;
 	YY_BREAK
 case 25:
 YY_RULE_SETUP
-#line 146 "scan-gram.l"
+#line 145 "scan-gram.l"
 return PERCENT_START;
 	YY_BREAK
 case 26:
 YY_RULE_SETUP
-#line 147 "scan-gram.l"
+#line 146 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 27:
 YY_RULE_SETUP
-#line 148 "scan-gram.l"
+#line 147 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 28:
 YY_RULE_SETUP
-#line 149 "scan-gram.l"
+#line 148 "scan-gram.l"
 return PERCENT_TOKEN_TABLE;
 	YY_BREAK
 case 29:
 YY_RULE_SETUP
-#line 150 "scan-gram.l"
+#line 149 "scan-gram.l"
 return PERCENT_TYPE;
 	YY_BREAK
 case 30:
 YY_RULE_SETUP
-#line 151 "scan-gram.l"
+#line 150 "scan-gram.l"
 return PERCENT_UNION;
 	YY_BREAK
 case 31:
 YY_RULE_SETUP
-#line 152 "scan-gram.l"
+#line 151 "scan-gram.l"
 return PERCENT_VERBOSE;
 	YY_BREAK
 case 32:
 YY_RULE_SETUP
-#line 153 "scan-gram.l"
+#line 152 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 33:
 YY_RULE_SETUP
-#line 155 "scan-gram.l"
+#line 154 "scan-gram.l"
 return EQUAL;
 	YY_BREAK
 case 34:
 YY_RULE_SETUP
-#line 156 "scan-gram.l"
+#line 155 "scan-gram.l"
 return COLON;
 	YY_BREAK
 case 35:
 YY_RULE_SETUP
-#line 157 "scan-gram.l"
+#line 156 "scan-gram.l"
 return PIPE;
 	YY_BREAK
 case 36:
 YY_RULE_SETUP
-#line 158 "scan-gram.l"
+#line 157 "scan-gram.l"
 return SEMICOLON;
 	YY_BREAK
 case 37:
 YY_RULE_SETUP
-#line 160 "scan-gram.l"
+#line 159 "scan-gram.l"
 YY_LINES; YY_STEP;
 	YY_BREAK
 case 38:
 YY_RULE_SETUP
-#line 161 "scan-gram.l"
+#line 160 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 case 39:
 YY_RULE_SETUP
-#line 162 "scan-gram.l"
+#line 161 "scan-gram.l"
 {
     yylval->symbol = symbol_get (yytext, *yylloc);
     return ID;
@@ -1310,48 +1309,48 @@ YY_RULE_SETUP
 	YY_BREAK
 case 40:
 YY_RULE_SETUP
-#line 167 "scan-gram.l"
+#line 166 "scan-gram.l"
 yylval->integer = strtol (yytext, 0, 10); return INT;
 	YY_BREAK
 /* Characters.  We don't check there is only one.  */
 case 41:
 YY_RULE_SETUP
-#line 170 "scan-gram.l"
+#line 169 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 42:
 YY_RULE_SETUP
-#line 173 "scan-gram.l"
+#line 172 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_STRING);
 	YY_BREAK
 /* Comments. */
 case 43:
 YY_RULE_SETUP
-#line 176 "scan-gram.l"
+#line 175 "scan-gram.l"
 yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 44:
 YY_RULE_SETUP
-#line 177 "scan-gram.l"
+#line 176 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 /* Prologue. */
 case 45:
 YY_RULE_SETUP
-#line 180 "scan-gram.l"
+#line 179 "scan-gram.l"
 yy_push_state (SC_PROLOGUE);
 	YY_BREAK
 /* Code in between braces.  */
 case 46:
 YY_RULE_SETUP
-#line 183 "scan-gram.l"
+#line 182 "scan-gram.l"
 YY_OBS_GROW; ++braces_level; yy_push_state (SC_BRACED_CODE);
 	YY_BREAK
 /* A type. */
 case 47:
 YY_RULE_SETUP
-#line 186 "scan-gram.l"
+#line 185 "scan-gram.l"
 {
     obstack_grow (&string_obstack, yytext + 1, yyleng - 2);
     YY_OBS_FINISH;
@@ -1361,7 +1360,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 48:
 YY_RULE_SETUP
-#line 194 "scan-gram.l"
+#line 193 "scan-gram.l"
 {
     if (++percent_percent_count == 2)
       yy_push_state (SC_EPILOGUE);
@@ -1370,7 +1369,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 49:
 YY_RULE_SETUP
-#line 200 "scan-gram.l"
+#line 199 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": invalid character: `%c'\n", *yytext);
@@ -1387,12 +1386,12 @@ YY_RULE_SETUP
 
 case 50:
 YY_RULE_SETUP
-#line 216 "scan-gram.l"
+#line 215 "scan-gram.l"
 if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@<:@");
 	YY_BREAK
 case 51:
 YY_RULE_SETUP
-#line 217 "scan-gram.l"
+#line 216 "scan-gram.l"
 if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@:>@");
 	YY_BREAK
 
@@ -1403,7 +1402,7 @@ if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@:>@");
 
 case 52:
 YY_RULE_SETUP
-#line 228 "scan-gram.l"
+#line 227 "scan-gram.l"
 { /* End of the comment. */
     if (yy_top_state () == INITIAL)
       {
@@ -1418,21 +1417,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 53:
 YY_RULE_SETUP
-#line 240 "scan-gram.l"
+#line 239 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case 54:
 YY_RULE_SETUP
-#line 241 "scan-gram.l"
+#line 240 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case 55:
 YY_RULE_SETUP
-#line 242 "scan-gram.l"
+#line 241 "scan-gram.l"
 /* Stray `*'. */if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_COMMENT):
-#line 244 "scan-gram.l"
+#line 243 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a comment\n");
@@ -1448,7 +1447,7 @@ case YY_STATE_EOF(SC_COMMENT):
 
 case 56:
 YY_RULE_SETUP
-#line 259 "scan-gram.l"
+#line 258 "scan-gram.l"
 {
     assert (yy_top_state () == INITIAL);
     YY_OBS_GROW;
@@ -1460,16 +1459,16 @@ YY_RULE_SETUP
 	YY_BREAK
 case 57:
 YY_RULE_SETUP
-#line 268 "scan-gram.l"
+#line 267 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 58:
 YY_RULE_SETUP
-#line 270 "scan-gram.l"
+#line 269 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_STRING):
-#line 272 "scan-gram.l"
+#line 271 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a string\n");
@@ -1489,7 +1488,7 @@ case YY_STATE_EOF(SC_ESCAPED_STRING):
 
 case 59:
 YY_RULE_SETUP
-#line 290 "scan-gram.l"
+#line 289 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () == INITIAL);
@@ -1507,16 +1506,16 @@ YY_RULE_SETUP
 	YY_BREAK
 case 60:
 YY_RULE_SETUP
-#line 305 "scan-gram.l"
+#line 304 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 61:
 YY_RULE_SETUP
-#line 307 "scan-gram.l"
+#line 306 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
-#line 309 "scan-gram.l"
+#line 308 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
@@ -1535,7 +1534,7 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 
 case 62:
 YY_RULE_SETUP
-#line 327 "scan-gram.l"
+#line 326 "scan-gram.l"
 {
     long c = strtol (yytext + 1, 0, 8);
     if (c > 255)
@@ -1550,54 +1549,54 @@ YY_RULE_SETUP
 	YY_BREAK
 case 63:
 YY_RULE_SETUP
-#line 339 "scan-gram.l"
+#line 338 "scan-gram.l"
 {
     obstack_1grow (&string_obstack, strtol (yytext + 2, 0, 16));
   }
 	YY_BREAK
 case 64:
 YY_RULE_SETUP
-#line 343 "scan-gram.l"
+#line 342 "scan-gram.l"
 obstack_1grow (&string_obstack, '\a');
 	YY_BREAK
 case 65:
 YY_RULE_SETUP
-#line 344 "scan-gram.l"
+#line 343 "scan-gram.l"
 obstack_1grow (&string_obstack, '\b');
 	YY_BREAK
 case 66:
 YY_RULE_SETUP
-#line 345 "scan-gram.l"
+#line 344 "scan-gram.l"
 obstack_1grow (&string_obstack, '\f');
 	YY_BREAK
 case 67:
 YY_RULE_SETUP
-#line 346 "scan-gram.l"
+#line 345 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n');
 	YY_BREAK
 case 68:
 YY_RULE_SETUP
-#line 347 "scan-gram.l"
+#line 346 "scan-gram.l"
 obstack_1grow (&string_obstack, '\r');
 	YY_BREAK
 case 69:
 YY_RULE_SETUP
-#line 348 "scan-gram.l"
+#line 347 "scan-gram.l"
 obstack_1grow (&string_obstack, '\t');
 	YY_BREAK
 case 70:
 YY_RULE_SETUP
-#line 349 "scan-gram.l"
+#line 348 "scan-gram.l"
 obstack_1grow (&string_obstack, '\v');
 	YY_BREAK
 case 71:
 YY_RULE_SETUP
-#line 350 "scan-gram.l"
+#line 349 "scan-gram.l"
 obstack_1grow (&string_obstack, yytext[1]);
 	YY_BREAK
 case 72:
 YY_RULE_SETUP
-#line 351 "scan-gram.l"
+#line 350 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unrecognized escape: %s\n", quote (yytext));
@@ -1607,7 +1606,7 @@ YY_RULE_SETUP
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 73:
 YY_RULE_SETUP
-#line 357 "scan-gram.l"
+#line 356 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1619,7 +1618,7 @@ YY_OBS_GROW;
 
 case 74:
 YY_RULE_SETUP
-#line 368 "scan-gram.l"
+#line 367 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () != INITIAL);
@@ -1628,27 +1627,27 @@ YY_RULE_SETUP
 	YY_BREAK
 case 75:
 YY_RULE_SETUP
-#line 374 "scan-gram.l"
+#line 373 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 76:
 YY_RULE_SETUP
-#line 375 "scan-gram.l"
+#line 374 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 77:
 YY_RULE_SETUP
-#line 377 "scan-gram.l"
+#line 376 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 78:
 YY_RULE_SETUP
-#line 379 "scan-gram.l"
+#line 378 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_CHARACTER):
-#line 381 "scan-gram.l"
+#line 380 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
@@ -1665,7 +1664,7 @@ case YY_STATE_EOF(SC_CHARACTER):
 
 case 79:
 YY_RULE_SETUP
-#line 397 "scan-gram.l"
+#line 396 "scan-gram.l"
 {
     assert (yy_top_state () != INITIAL);
     YY_OBS_GROW;
@@ -1674,27 +1673,27 @@ YY_RULE_SETUP
 	YY_BREAK
 case 80:
 YY_RULE_SETUP
-#line 403 "scan-gram.l"
+#line 402 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 81:
 YY_RULE_SETUP
-#line 404 "scan-gram.l"
+#line 403 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 82:
 YY_RULE_SETUP
-#line 406 "scan-gram.l"
+#line 405 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 83:
 YY_RULE_SETUP
-#line 408 "scan-gram.l"
+#line 407 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_STRING):
-#line 410 "scan-gram.l"
+#line 409 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a string\n");
@@ -1711,30 +1710,30 @@ case YY_STATE_EOF(SC_STRING):
 /* Characters.  We don't check there is only one.  */
 case 84:
 YY_RULE_SETUP
-#line 426 "scan-gram.l"
+#line 425 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 85:
 YY_RULE_SETUP
-#line 429 "scan-gram.l"
+#line 428 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_STRING);
 	YY_BREAK
 /* Comments. */
 case 86:
 YY_RULE_SETUP
-#line 432 "scan-gram.l"
+#line 431 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 87:
 YY_RULE_SETUP
-#line 433 "scan-gram.l"
+#line 432 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* Not comments. */
 case 88:
 YY_RULE_SETUP
-#line 436 "scan-gram.l"
+#line 435 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1746,7 +1745,7 @@ YY_OBS_GROW;
 
 case 89:
 YY_RULE_SETUP
-#line 447 "scan-gram.l"
+#line 446 "scan-gram.l"
 {
     YY_OBS_GROW;
     if (--braces_level == 0)
@@ -1760,39 +1759,39 @@ YY_RULE_SETUP
 	YY_BREAK
 case 90:
 YY_RULE_SETUP
-#line 458 "scan-gram.l"
+#line 457 "scan-gram.l"
 YY_OBS_GROW; braces_level++;
 	YY_BREAK
 case 91:
 YY_RULE_SETUP
-#line 460 "scan-gram.l"
+#line 459 "scan-gram.l"
 { handle_dollar (current_braced_code,
 						   yytext, *yylloc); }
 	YY_BREAK
 case 92:
 YY_RULE_SETUP
-#line 462 "scan-gram.l"
+#line 461 "scan-gram.l"
 { handle_at (current_braced_code,
 					       yytext, *yylloc); }
 	YY_BREAK
 case 93:
 YY_RULE_SETUP
-#line 465 "scan-gram.l"
+#line 464 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 94:
 YY_RULE_SETUP
-#line 466 "scan-gram.l"
+#line 465 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 /* A lose $, or /, or etc. */
 case 95:
 YY_RULE_SETUP
-#line 469 "scan-gram.l"
+#line 468 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 471 "scan-gram.l"
+#line 470 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a braced code\n");
@@ -1810,7 +1809,7 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 96:
 YY_RULE_SETUP
-#line 489 "scan-gram.l"
+#line 488 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1820,21 +1819,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 97:
 YY_RULE_SETUP
-#line 496 "scan-gram.l"
+#line 495 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 98:
 YY_RULE_SETUP
-#line 497 "scan-gram.l"
+#line 496 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 99:
 YY_RULE_SETUP
-#line 498 "scan-gram.l"
+#line 497 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 500 "scan-gram.l"
+#line 499 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a prologue\n");
@@ -1853,11 +1852,11 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 100:
 YY_RULE_SETUP
-#line 518 "scan-gram.l"
+#line 517 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 520 "scan-gram.l"
+#line 519 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1868,10 +1867,10 @@ case YY_STATE_EOF(SC_EPILOGUE):
 
 case 101:
 YY_RULE_SETUP
-#line 529 "scan-gram.l"
+#line 528 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1875 "lex.yy.c"
+#line 1874 "lex.yy.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2761,7 +2760,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 529 "scan-gram.l"
+#line 528 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
@@ -2967,4 +2966,6 @@ void
 scanner_free (void)
 {
   obstack_free (&string_obstack, 0);
+  /* Reclaim Flex's buffers.  */
+  yy_delete_buffer (YY_CURRENT_BUFFER);
 }
