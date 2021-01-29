@@ -709,16 +709,16 @@ int yy_flex_debug = 1;
 
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
+      130,  131,  132,  133,  134,  135,  136,  137,  138,  139,
+      140,  141,  142,  143,  144,  145,  146,  147,  148,  149,
+      150,  151,  152,  153,  154,  155,  156,  157,  158,  159,
+      160,  161,  163,  164,  165,  166,  168,  169,  170,  176,
+      179,  182,  185,  186,  189,  192,  195,  203,  209,  225,
+      226,  237,  249,  250,  251,  268,  278,  280,  300,  316,
+      318,  338,  350,  354,  355,  356,  357,  358,  359,  360,
+      361,  362,  368,  379,  385,  386,  388,  390,  408,  414,
+      415,  417,  419,  437,  440,  443,  444,  447,  458,  470,
+      472,  474,  477,  478,  481,  501,  508,  509,  510,  530
 
     } ;
 
@@ -812,6 +812,14 @@ scanner_last_string_free (void)
 static int braces_level = 0;
 static int percent_percent_count = 0;
 
+/* Within well-formed rules, RULE_LENGTH is the number of values in
+   the current rule so far, which says where to find `$0' with respect
+   to the top of the stack.  It is not the same as the rule->length in
+   the case of mid rule actions.
+
+   Outside of well-formed rules, RULE_LENGTH has an undefined value.  */
+static int rule_length;
+
 static void handle_dollar PARAMS ((braced_code_t code_kind,
 				   char *cp, location_t location));
 static void handle_at PARAMS ((braced_code_t code_kind,
@@ -829,7 +837,7 @@ static void handle_at PARAMS ((braced_code_t code_kind,
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 833 "scan-gram.c"
+#line 841 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -991,7 +999,7 @@ YY_DECL
 	register char *yy_cp, *yy_bp;
 	register int yy_act;
 
-#line 98 "scan-gram.l"
+#line 106 "scan-gram.l"
 
 
   /* At each yylex invocation, mark the current position as the
@@ -1014,7 +1022,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1018 "scan-gram.c"
+#line 1026 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -1116,246 +1124,247 @@ do_action:	/* This label is used only to access EOF actions. */
 
 case 1:
 YY_RULE_SETUP
-#line 122 "scan-gram.l"
+#line 130 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 2:
 YY_RULE_SETUP
-#line 123 "scan-gram.l"
+#line 131 "scan-gram.l"
 return PERCENT_DEBUG;
 	YY_BREAK
 case 3:
 YY_RULE_SETUP
-#line 124 "scan-gram.l"
+#line 132 "scan-gram.l"
 return PERCENT_DEFINE;
 	YY_BREAK
 case 4:
 YY_RULE_SETUP
-#line 125 "scan-gram.l"
+#line 133 "scan-gram.l"
 return PERCENT_DEFINES;
 	YY_BREAK
 case 5:
 YY_RULE_SETUP
-#line 126 "scan-gram.l"
+#line 134 "scan-gram.l"
 return PERCENT_DESTRUCTOR;
 	YY_BREAK
 case 6:
 YY_RULE_SETUP
-#line 127 "scan-gram.l"
+#line 135 "scan-gram.l"
 return PERCENT_DPREC;
 	YY_BREAK
 case 7:
 YY_RULE_SETUP
-#line 128 "scan-gram.l"
+#line 136 "scan-gram.l"
 return PERCENT_ERROR_VERBOSE;
 	YY_BREAK
 case 8:
 YY_RULE_SETUP
-#line 129 "scan-gram.l"
+#line 137 "scan-gram.l"
 return PERCENT_EXPECT;
 	YY_BREAK
 case 9:
 YY_RULE_SETUP
-#line 130 "scan-gram.l"
+#line 138 "scan-gram.l"
 return PERCENT_FILE_PREFIX;
 	YY_BREAK
 case 10:
 YY_RULE_SETUP
-#line 131 "scan-gram.l"
+#line 139 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 11:
 YY_RULE_SETUP
-#line 132 "scan-gram.l"
+#line 140 "scan-gram.l"
 return PERCENT_GLR_PARSER;
 	YY_BREAK
 case 12:
 YY_RULE_SETUP
-#line 133 "scan-gram.l"
+#line 141 "scan-gram.l"
 return PERCENT_LEFT;
 	YY_BREAK
 case 13:
 YY_RULE_SETUP
-#line 134 "scan-gram.l"
+#line 142 "scan-gram.l"
 return PERCENT_LOCATIONS;
 	YY_BREAK
 case 14:
 YY_RULE_SETUP
-#line 135 "scan-gram.l"
+#line 143 "scan-gram.l"
 return PERCENT_MERGE;
 	YY_BREAK
 case 15:
 YY_RULE_SETUP
-#line 136 "scan-gram.l"
+#line 144 "scan-gram.l"
 return PERCENT_NAME_PREFIX;
 	YY_BREAK
 case 16:
 YY_RULE_SETUP
-#line 137 "scan-gram.l"
+#line 145 "scan-gram.l"
 return PERCENT_NO_LINES;
 	YY_BREAK
 case 17:
 YY_RULE_SETUP
-#line 138 "scan-gram.l"
+#line 146 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 18:
 YY_RULE_SETUP
-#line 139 "scan-gram.l"
+#line 147 "scan-gram.l"
 return PERCENT_NTERM;
 	YY_BREAK
 case 19:
 YY_RULE_SETUP
-#line 140 "scan-gram.l"
+#line 148 "scan-gram.l"
 return PERCENT_OUTPUT;
 	YY_BREAK
 case 20:
 YY_RULE_SETUP
-#line 141 "scan-gram.l"
-return PERCENT_PREC;
+#line 149 "scan-gram.l"
+{ rule_length--; return PERCENT_PREC; }
 	YY_BREAK
 case 21:
 YY_RULE_SETUP
-#line 142 "scan-gram.l"
+#line 150 "scan-gram.l"
 return PERCENT_PRINTER;
 	YY_BREAK
 case 22:
 YY_RULE_SETUP
-#line 143 "scan-gram.l"
+#line 151 "scan-gram.l"
 return PERCENT_PURE_PARSER;
 	YY_BREAK
 case 23:
 YY_RULE_SETUP
-#line 144 "scan-gram.l"
+#line 152 "scan-gram.l"
 return PERCENT_RIGHT;
 	YY_BREAK
 case 24:
 YY_RULE_SETUP
-#line 145 "scan-gram.l"
+#line 153 "scan-gram.l"
 return PERCENT_SKELETON;
 	YY_BREAK
 case 25:
 YY_RULE_SETUP
-#line 146 "scan-gram.l"
+#line 154 "scan-gram.l"
 return PERCENT_START;
 	YY_BREAK
 case 26:
 YY_RULE_SETUP
-#line 147 "scan-gram.l"
+#line 155 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 27:
 YY_RULE_SETUP
-#line 148 "scan-gram.l"
+#line 156 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 28:
 YY_RULE_SETUP
-#line 149 "scan-gram.l"
+#line 157 "scan-gram.l"
 return PERCENT_TOKEN_TABLE;
 	YY_BREAK
 case 29:
 YY_RULE_SETUP
-#line 150 "scan-gram.l"
+#line 158 "scan-gram.l"
 return PERCENT_TYPE;
 	YY_BREAK
 case 30:
 YY_RULE_SETUP
-#line 151 "scan-gram.l"
+#line 159 "scan-gram.l"
 return PERCENT_UNION;
 	YY_BREAK
 case 31:
 YY_RULE_SETUP
-#line 152 "scan-gram.l"
+#line 160 "scan-gram.l"
 return PERCENT_VERBOSE;
 	YY_BREAK
 case 32:
 YY_RULE_SETUP
-#line 153 "scan-gram.l"
+#line 161 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 33:
 YY_RULE_SETUP
-#line 155 "scan-gram.l"
+#line 163 "scan-gram.l"
 return EQUAL;
 	YY_BREAK
 case 34:
 YY_RULE_SETUP
-#line 156 "scan-gram.l"
-return COLON;
+#line 164 "scan-gram.l"
+{ rule_length = 0; return COLON; }
 	YY_BREAK
 case 35:
 YY_RULE_SETUP
-#line 157 "scan-gram.l"
-return PIPE;
+#line 165 "scan-gram.l"
+{ rule_length = 0; return PIPE; }
 	YY_BREAK
 case 36:
 YY_RULE_SETUP
-#line 158 "scan-gram.l"
+#line 166 "scan-gram.l"
 return SEMICOLON;
 	YY_BREAK
 case 37:
 YY_RULE_SETUP
-#line 160 "scan-gram.l"
+#line 168 "scan-gram.l"
 YY_LINES; YY_STEP;
 	YY_BREAK
 case 38:
 YY_RULE_SETUP
-#line 161 "scan-gram.l"
+#line 169 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 case 39:
 YY_RULE_SETUP
-#line 162 "scan-gram.l"
+#line 170 "scan-gram.l"
 {
     yylval->symbol = symbol_get (yytext, *yylloc);
+    rule_length++;
     return ID;
   }
 	YY_BREAK
 case 40:
 YY_RULE_SETUP
-#line 167 "scan-gram.l"
+#line 176 "scan-gram.l"
 yylval->integer = strtol (yytext, 0, 10); return INT;
 	YY_BREAK
 /* Characters.  We don't check there is only one.  */
 case 41:
 YY_RULE_SETUP
-#line 170 "scan-gram.l"
+#line 179 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 42:
 YY_RULE_SETUP
-#line 173 "scan-gram.l"
+#line 182 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_STRING);
 	YY_BREAK
 /* Comments. */
 case 43:
 YY_RULE_SETUP
-#line 176 "scan-gram.l"
+#line 185 "scan-gram.l"
 yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 44:
 YY_RULE_SETUP
-#line 177 "scan-gram.l"
+#line 186 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 /* Prologue. */
 case 45:
 YY_RULE_SETUP
-#line 180 "scan-gram.l"
+#line 189 "scan-gram.l"
 yy_push_state (SC_PROLOGUE);
 	YY_BREAK
 /* Code in between braces.  */
 case 46:
 YY_RULE_SETUP
-#line 183 "scan-gram.l"
+#line 192 "scan-gram.l"
 YY_OBS_GROW; ++braces_level; yy_push_state (SC_BRACED_CODE);
 	YY_BREAK
 /* A type. */
 case 47:
 YY_RULE_SETUP
-#line 186 "scan-gram.l"
+#line 195 "scan-gram.l"
 {
     obstack_grow (&string_obstack, yytext + 1, yyleng - 2);
     YY_OBS_FINISH;
@@ -1365,7 +1374,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 48:
 YY_RULE_SETUP
-#line 194 "scan-gram.l"
+#line 203 "scan-gram.l"
 {
     if (++percent_percent_count == 2)
       yy_push_state (SC_EPILOGUE);
@@ -1374,7 +1383,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 49:
 YY_RULE_SETUP
-#line 200 "scan-gram.l"
+#line 209 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": invalid character: `%c'\n"), *yytext);
@@ -1391,12 +1400,12 @@ YY_RULE_SETUP
 
 case 50:
 YY_RULE_SETUP
-#line 216 "scan-gram.l"
+#line 225 "scan-gram.l"
 if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@<:@");
 	YY_BREAK
 case 51:
 YY_RULE_SETUP
-#line 217 "scan-gram.l"
+#line 226 "scan-gram.l"
 if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@:>@");
 	YY_BREAK
 
@@ -1407,7 +1416,7 @@ if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@:>@");
 
 case 52:
 YY_RULE_SETUP
-#line 228 "scan-gram.l"
+#line 237 "scan-gram.l"
 { /* End of the comment. */
     if (yy_top_state () == INITIAL)
       {
@@ -1422,21 +1431,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 53:
 YY_RULE_SETUP
-#line 240 "scan-gram.l"
+#line 249 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case 54:
 YY_RULE_SETUP
-#line 241 "scan-gram.l"
+#line 250 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case 55:
 YY_RULE_SETUP
-#line 242 "scan-gram.l"
+#line 251 "scan-gram.l"
 /* Stray `*'. */if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_COMMENT):
-#line 244 "scan-gram.l"
+#line 253 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a comment\n"));
@@ -1452,28 +1461,29 @@ case YY_STATE_EOF(SC_COMMENT):
 
 case 56:
 YY_RULE_SETUP
-#line 259 "scan-gram.l"
+#line 268 "scan-gram.l"
 {
     assert (yy_top_state () == INITIAL);
     YY_OBS_GROW;
     YY_OBS_FINISH;
     yylval->string = last_string;
     yy_pop_state ();
+    rule_length++;
     return STRING;
   }
 	YY_BREAK
 case 57:
 YY_RULE_SETUP
-#line 268 "scan-gram.l"
+#line 278 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 58:
 YY_RULE_SETUP
-#line 270 "scan-gram.l"
+#line 280 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_STRING):
-#line 272 "scan-gram.l"
+#line 282 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a string\n"));
@@ -1493,7 +1503,7 @@ case YY_STATE_EOF(SC_ESCAPED_STRING):
 
 case 59:
 YY_RULE_SETUP
-#line 290 "scan-gram.l"
+#line 300 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () == INITIAL);
@@ -1505,22 +1515,23 @@ YY_RULE_SETUP
 				    (unsigned char) last_string[1], *yylloc);
       YY_OBS_FREE;
       yy_pop_state ();
+      rule_length++;
       return ID;
     }
   }
 	YY_BREAK
 case 60:
 YY_RULE_SETUP
-#line 305 "scan-gram.l"
+#line 316 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 61:
 YY_RULE_SETUP
-#line 307 "scan-gram.l"
+#line 318 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
-#line 309 "scan-gram.l"
+#line 320 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a character\n"));
@@ -1539,7 +1550,7 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 
 case 62:
 YY_RULE_SETUP
-#line 327 "scan-gram.l"
+#line 338 "scan-gram.l"
 {
     long c = strtol (yytext + 1, 0, 8);
     if (c > 255)
@@ -1554,54 +1565,54 @@ YY_RULE_SETUP
 	YY_BREAK
 case 63:
 YY_RULE_SETUP
-#line 339 "scan-gram.l"
+#line 350 "scan-gram.l"
 {
     obstack_1grow (&string_obstack, strtol (yytext + 2, 0, 16));
   }
 	YY_BREAK
 case 64:
 YY_RULE_SETUP
-#line 343 "scan-gram.l"
+#line 354 "scan-gram.l"
 obstack_1grow (&string_obstack, '\a');
 	YY_BREAK
 case 65:
 YY_RULE_SETUP
-#line 344 "scan-gram.l"
+#line 355 "scan-gram.l"
 obstack_1grow (&string_obstack, '\b');
 	YY_BREAK
 case 66:
 YY_RULE_SETUP
-#line 345 "scan-gram.l"
+#line 356 "scan-gram.l"
 obstack_1grow (&string_obstack, '\f');
 	YY_BREAK
 case 67:
 YY_RULE_SETUP
-#line 346 "scan-gram.l"
+#line 357 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n');
 	YY_BREAK
 case 68:
 YY_RULE_SETUP
-#line 347 "scan-gram.l"
+#line 358 "scan-gram.l"
 obstack_1grow (&string_obstack, '\r');
 	YY_BREAK
 case 69:
 YY_RULE_SETUP
-#line 348 "scan-gram.l"
+#line 359 "scan-gram.l"
 obstack_1grow (&string_obstack, '\t');
 	YY_BREAK
 case 70:
 YY_RULE_SETUP
-#line 349 "scan-gram.l"
+#line 360 "scan-gram.l"
 obstack_1grow (&string_obstack, '\v');
 	YY_BREAK
 case 71:
 YY_RULE_SETUP
-#line 350 "scan-gram.l"
+#line 361 "scan-gram.l"
 obstack_1grow (&string_obstack, yytext[1]);
 	YY_BREAK
 case 72:
 YY_RULE_SETUP
-#line 351 "scan-gram.l"
+#line 362 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unrecognized escape: %s\n"), quote (yytext));
@@ -1611,7 +1622,7 @@ YY_RULE_SETUP
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 73:
 YY_RULE_SETUP
-#line 357 "scan-gram.l"
+#line 368 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1623,7 +1634,7 @@ YY_OBS_GROW;
 
 case 74:
 YY_RULE_SETUP
-#line 368 "scan-gram.l"
+#line 379 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () != INITIAL);
@@ -1632,27 +1643,27 @@ YY_RULE_SETUP
 	YY_BREAK
 case 75:
 YY_RULE_SETUP
-#line 374 "scan-gram.l"
+#line 385 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 76:
 YY_RULE_SETUP
-#line 375 "scan-gram.l"
+#line 386 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 77:
 YY_RULE_SETUP
-#line 377 "scan-gram.l"
+#line 388 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 78:
 YY_RULE_SETUP
-#line 379 "scan-gram.l"
+#line 390 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_CHARACTER):
-#line 381 "scan-gram.l"
+#line 392 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a character\n"));
@@ -1669,7 +1680,7 @@ case YY_STATE_EOF(SC_CHARACTER):
 
 case 79:
 YY_RULE_SETUP
-#line 397 "scan-gram.l"
+#line 408 "scan-gram.l"
 {
     assert (yy_top_state () != INITIAL);
     YY_OBS_GROW;
@@ -1678,27 +1689,27 @@ YY_RULE_SETUP
 	YY_BREAK
 case 80:
 YY_RULE_SETUP
-#line 403 "scan-gram.l"
+#line 414 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 81:
 YY_RULE_SETUP
-#line 404 "scan-gram.l"
+#line 415 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 82:
 YY_RULE_SETUP
-#line 406 "scan-gram.l"
+#line 417 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 83:
 YY_RULE_SETUP
-#line 408 "scan-gram.l"
+#line 419 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_STRING):
-#line 410 "scan-gram.l"
+#line 421 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a string\n"));
@@ -1715,30 +1726,30 @@ case YY_STATE_EOF(SC_STRING):
 /* Characters.  We don't check there is only one.  */
 case 84:
 YY_RULE_SETUP
-#line 426 "scan-gram.l"
+#line 437 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 85:
 YY_RULE_SETUP
-#line 429 "scan-gram.l"
+#line 440 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_STRING);
 	YY_BREAK
 /* Comments. */
 case 86:
 YY_RULE_SETUP
-#line 432 "scan-gram.l"
+#line 443 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 87:
 YY_RULE_SETUP
-#line 433 "scan-gram.l"
+#line 444 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* Not comments. */
 case 88:
 YY_RULE_SETUP
-#line 436 "scan-gram.l"
+#line 447 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1750,7 +1761,7 @@ YY_OBS_GROW;
 
 case 89:
 YY_RULE_SETUP
-#line 447 "scan-gram.l"
+#line 458 "scan-gram.l"
 {
     YY_OBS_GROW;
     if (--braces_level == 0)
@@ -1758,45 +1769,46 @@ YY_RULE_SETUP
 	yy_pop_state ();
 	YY_OBS_FINISH;
 	yylval->string = last_string;
+	rule_length++;
 	return BRACED_CODE;
       }
   }
 	YY_BREAK
 case 90:
 YY_RULE_SETUP
-#line 458 "scan-gram.l"
+#line 470 "scan-gram.l"
 YY_OBS_GROW; braces_level++;
 	YY_BREAK
 case 91:
 YY_RULE_SETUP
-#line 460 "scan-gram.l"
+#line 472 "scan-gram.l"
 { handle_dollar (current_braced_code,
 						   yytext, *yylloc); }
 	YY_BREAK
 case 92:
 YY_RULE_SETUP
-#line 462 "scan-gram.l"
+#line 474 "scan-gram.l"
 { handle_at (current_braced_code,
 					       yytext, *yylloc); }
 	YY_BREAK
 case 93:
 YY_RULE_SETUP
-#line 465 "scan-gram.l"
+#line 477 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 94:
 YY_RULE_SETUP
-#line 466 "scan-gram.l"
+#line 478 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 /* A lose $, or /, or etc. */
 case 95:
 YY_RULE_SETUP
-#line 469 "scan-gram.l"
+#line 481 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 471 "scan-gram.l"
+#line 483 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a braced code\n"));
@@ -1814,7 +1826,7 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 96:
 YY_RULE_SETUP
-#line 489 "scan-gram.l"
+#line 501 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1824,21 +1836,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 97:
 YY_RULE_SETUP
-#line 496 "scan-gram.l"
+#line 508 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 98:
 YY_RULE_SETUP
-#line 497 "scan-gram.l"
+#line 509 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 99:
 YY_RULE_SETUP
-#line 498 "scan-gram.l"
+#line 510 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 500 "scan-gram.l"
+#line 512 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a prologue\n"));
@@ -1857,11 +1869,11 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 100:
 YY_RULE_SETUP
-#line 518 "scan-gram.l"
+#line 530 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 520 "scan-gram.l"
+#line 532 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1872,10 +1884,10 @@ case YY_STATE_EOF(SC_EPILOGUE):
 
 case 101:
 YY_RULE_SETUP
-#line 529 "scan-gram.l"
+#line 541 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1879 "scan-gram.c"
+#line 1891 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2765,7 +2777,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 529 "scan-gram.l"
+#line 541 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
@@ -2806,11 +2818,6 @@ handle_action_dollar (char *text, location_t location)
     }
   else if (('0' <= *cp && *cp <= '9') || *cp == '-')
     {
-      /* RULE_LENGTH is the number of values in the current rule so
-	 far, which says where to find `$0' with respect to the top of
-	 the stack.  It is not the same as the rule->length in the
-	 case of mid rule actions.  */
-      int rule_length = symbol_list_length (current_rule->next);
       int n = strtol (cp, &cp, 10);
 
       if (n > rule_length)
@@ -2893,11 +2900,6 @@ handle_action_at (char *text, location_t location)
     }
   else if (('0' <= *cp && *cp <= '9') || *cp == '-')
     {
-      /* RULE_LENGTH is the number of values in the current rule so
-	 far, which says where to find `$0' with respect to the top of
-	 the stack.  It is not the same as the rule->length in the
-	 case of mid rule actions.  */
-      int rule_length = symbol_list_length (current_rule->next);
       int n = strtol (cp, &cp, 10);
 
       if (n > rule_length)
