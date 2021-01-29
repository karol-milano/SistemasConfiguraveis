@@ -42,6 +42,12 @@
 #include <stdlib.h>
 #ifndef _WIN32
 #include <unistd.h>
+#else
+#ifndef YY_ALWAYS_INTERACTIVE
+#ifndef YY_NEVER_INTERACTIVE
+extern int isatty YY_PROTO(( int ));
+#endif
+#endif
 #endif
 
 /* Use prototypes in function declarations. */
@@ -709,16 +715,16 @@ int yy_flex_debug = 1;
 
 static yyconst short int yy_rule_linenum[101] =
     {   0,
-      130,  131,  132,  133,  134,  135,  136,  137,  138,  139,
-      140,  141,  142,  143,  144,  145,  146,  147,  148,  149,
-      150,  151,  152,  153,  154,  155,  156,  157,  158,  159,
-      160,  161,  163,  164,  165,  166,  168,  169,  170,  176,
-      179,  182,  185,  186,  189,  192,  195,  203,  209,  225,
-      226,  237,  249,  250,  251,  268,  278,  280,  300,  316,
-      318,  338,  350,  354,  355,  356,  357,  358,  359,  360,
-      361,  362,  368,  379,  385,  386,  388,  390,  408,  414,
-      415,  417,  419,  437,  440,  443,  444,  447,  458,  470,
-      472,  474,  477,  478,  481,  501,  508,  509,  510,  530
+      119,  120,  121,  122,  123,  124,  125,  126,  127,  128,
+      129,  130,  131,  132,  133,  134,  135,  136,  137,  138,
+      139,  140,  141,  142,  143,  144,  145,  146,  147,  148,
+      149,  150,  152,  153,  154,  155,  157,  158,  159,  165,
+      168,  171,  174,  175,  178,  181,  184,  192,  198,  214,
+      215,  226,  238,  239,  240,  257,  267,  269,  289,  305,
+      307,  327,  339,  343,  344,  345,  346,  347,  348,  349,
+      350,  351,  357,  368,  374,  375,  377,  379,  397,  403,
+      404,  406,  408,  426,  429,  432,  433,  436,  447,  459,
+      461,  463,  466,  467,  470,  490,  497,  498,  499,  519
 
     } ;
 
@@ -837,7 +843,7 @@ static void handle_at PARAMS ((braced_code_t code_kind,
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 841 "scan-gram.c"
+#line 847 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -1004,25 +1010,14 @@ YY_DECL
 
   /* At each yylex invocation, mark the current position as the
      start of the next token.  */
-#define TR_POS 0
-#if TR_POS
-  fprintf (stderr, "FOO1: %p: ", yylloc);
-  LOCATION_PRINT (stderr, *yylloc);
-  fprintf (stderr, "\n");
-#endif
   YY_STEP;
-#if TR_POS
-  fprintf (stderr, "BAR1: ");
-  LOCATION_PRINT (stderr, *yylloc);
-  fprintf (stderr, "\n");
-#endif
 
 
 
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1026 "scan-gram.c"
+#line 1021 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -1124,197 +1119,197 @@ do_action:	/* This label is used only to access EOF actions. */
 
 case 1:
 YY_RULE_SETUP
-#line 130 "scan-gram.l"
+#line 119 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 2:
 YY_RULE_SETUP
-#line 131 "scan-gram.l"
+#line 120 "scan-gram.l"
 return PERCENT_DEBUG;
 	YY_BREAK
 case 3:
 YY_RULE_SETUP
-#line 132 "scan-gram.l"
+#line 121 "scan-gram.l"
 return PERCENT_DEFINE;
 	YY_BREAK
 case 4:
 YY_RULE_SETUP
-#line 133 "scan-gram.l"
+#line 122 "scan-gram.l"
 return PERCENT_DEFINES;
 	YY_BREAK
 case 5:
 YY_RULE_SETUP
-#line 134 "scan-gram.l"
+#line 123 "scan-gram.l"
 return PERCENT_DESTRUCTOR;
 	YY_BREAK
 case 6:
 YY_RULE_SETUP
-#line 135 "scan-gram.l"
+#line 124 "scan-gram.l"
 return PERCENT_DPREC;
 	YY_BREAK
 case 7:
 YY_RULE_SETUP
-#line 136 "scan-gram.l"
+#line 125 "scan-gram.l"
 return PERCENT_ERROR_VERBOSE;
 	YY_BREAK
 case 8:
 YY_RULE_SETUP
-#line 137 "scan-gram.l"
+#line 126 "scan-gram.l"
 return PERCENT_EXPECT;
 	YY_BREAK
 case 9:
 YY_RULE_SETUP
-#line 138 "scan-gram.l"
+#line 127 "scan-gram.l"
 return PERCENT_FILE_PREFIX;
 	YY_BREAK
 case 10:
 YY_RULE_SETUP
-#line 139 "scan-gram.l"
+#line 128 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 11:
 YY_RULE_SETUP
-#line 140 "scan-gram.l"
+#line 129 "scan-gram.l"
 return PERCENT_GLR_PARSER;
 	YY_BREAK
 case 12:
 YY_RULE_SETUP
-#line 141 "scan-gram.l"
+#line 130 "scan-gram.l"
 return PERCENT_LEFT;
 	YY_BREAK
 case 13:
 YY_RULE_SETUP
-#line 142 "scan-gram.l"
+#line 131 "scan-gram.l"
 return PERCENT_LOCATIONS;
 	YY_BREAK
 case 14:
 YY_RULE_SETUP
-#line 143 "scan-gram.l"
+#line 132 "scan-gram.l"
 return PERCENT_MERGE;
 	YY_BREAK
 case 15:
 YY_RULE_SETUP
-#line 144 "scan-gram.l"
+#line 133 "scan-gram.l"
 return PERCENT_NAME_PREFIX;
 	YY_BREAK
 case 16:
 YY_RULE_SETUP
-#line 145 "scan-gram.l"
+#line 134 "scan-gram.l"
 return PERCENT_NO_LINES;
 	YY_BREAK
 case 17:
 YY_RULE_SETUP
-#line 146 "scan-gram.l"
+#line 135 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 18:
 YY_RULE_SETUP
-#line 147 "scan-gram.l"
+#line 136 "scan-gram.l"
 return PERCENT_NTERM;
 	YY_BREAK
 case 19:
 YY_RULE_SETUP
-#line 148 "scan-gram.l"
+#line 137 "scan-gram.l"
 return PERCENT_OUTPUT;
 	YY_BREAK
 case 20:
 YY_RULE_SETUP
-#line 149 "scan-gram.l"
+#line 138 "scan-gram.l"
 { rule_length--; return PERCENT_PREC; }
 	YY_BREAK
 case 21:
 YY_RULE_SETUP
-#line 150 "scan-gram.l"
+#line 139 "scan-gram.l"
 return PERCENT_PRINTER;
 	YY_BREAK
 case 22:
 YY_RULE_SETUP
-#line 151 "scan-gram.l"
+#line 140 "scan-gram.l"
 return PERCENT_PURE_PARSER;
 	YY_BREAK
 case 23:
 YY_RULE_SETUP
-#line 152 "scan-gram.l"
+#line 141 "scan-gram.l"
 return PERCENT_RIGHT;
 	YY_BREAK
 case 24:
 YY_RULE_SETUP
-#line 153 "scan-gram.l"
+#line 142 "scan-gram.l"
 return PERCENT_SKELETON;
 	YY_BREAK
 case 25:
 YY_RULE_SETUP
-#line 154 "scan-gram.l"
+#line 143 "scan-gram.l"
 return PERCENT_START;
 	YY_BREAK
 case 26:
 YY_RULE_SETUP
-#line 155 "scan-gram.l"
+#line 144 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 27:
 YY_RULE_SETUP
-#line 156 "scan-gram.l"
+#line 145 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 28:
 YY_RULE_SETUP
-#line 157 "scan-gram.l"
+#line 146 "scan-gram.l"
 return PERCENT_TOKEN_TABLE;
 	YY_BREAK
 case 29:
 YY_RULE_SETUP
-#line 158 "scan-gram.l"
+#line 147 "scan-gram.l"
 return PERCENT_TYPE;
 	YY_BREAK
 case 30:
 YY_RULE_SETUP
-#line 159 "scan-gram.l"
+#line 148 "scan-gram.l"
 return PERCENT_UNION;
 	YY_BREAK
 case 31:
 YY_RULE_SETUP
-#line 160 "scan-gram.l"
+#line 149 "scan-gram.l"
 return PERCENT_VERBOSE;
 	YY_BREAK
 case 32:
 YY_RULE_SETUP
-#line 161 "scan-gram.l"
+#line 150 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 33:
 YY_RULE_SETUP
-#line 163 "scan-gram.l"
+#line 152 "scan-gram.l"
 return EQUAL;
 	YY_BREAK
 case 34:
 YY_RULE_SETUP
-#line 164 "scan-gram.l"
+#line 153 "scan-gram.l"
 { rule_length = 0; return COLON; }
 	YY_BREAK
 case 35:
 YY_RULE_SETUP
-#line 165 "scan-gram.l"
+#line 154 "scan-gram.l"
 { rule_length = 0; return PIPE; }
 	YY_BREAK
 case 36:
 YY_RULE_SETUP
-#line 166 "scan-gram.l"
+#line 155 "scan-gram.l"
 return SEMICOLON;
 	YY_BREAK
 case 37:
 YY_RULE_SETUP
-#line 168 "scan-gram.l"
+#line 157 "scan-gram.l"
 YY_LINES; YY_STEP;
 	YY_BREAK
 case 38:
 YY_RULE_SETUP
-#line 169 "scan-gram.l"
+#line 158 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 case 39:
 YY_RULE_SETUP
-#line 170 "scan-gram.l"
+#line 159 "scan-gram.l"
 {
     yylval->symbol = symbol_get (yytext, *yylloc);
     rule_length++;
@@ -1323,48 +1318,48 @@ YY_RULE_SETUP
 	YY_BREAK
 case 40:
 YY_RULE_SETUP
-#line 176 "scan-gram.l"
+#line 165 "scan-gram.l"
 yylval->integer = strtol (yytext, 0, 10); return INT;
 	YY_BREAK
 /* Characters.  We don't check there is only one.  */
 case 41:
 YY_RULE_SETUP
-#line 179 "scan-gram.l"
+#line 168 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 42:
 YY_RULE_SETUP
-#line 182 "scan-gram.l"
+#line 171 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_STRING);
 	YY_BREAK
 /* Comments. */
 case 43:
 YY_RULE_SETUP
-#line 185 "scan-gram.l"
+#line 174 "scan-gram.l"
 yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 44:
 YY_RULE_SETUP
-#line 186 "scan-gram.l"
+#line 175 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 /* Prologue. */
 case 45:
 YY_RULE_SETUP
-#line 189 "scan-gram.l"
+#line 178 "scan-gram.l"
 yy_push_state (SC_PROLOGUE);
 	YY_BREAK
 /* Code in between braces.  */
 case 46:
 YY_RULE_SETUP
-#line 192 "scan-gram.l"
+#line 181 "scan-gram.l"
 YY_OBS_GROW; ++braces_level; yy_push_state (SC_BRACED_CODE);
 	YY_BREAK
 /* A type. */
 case 47:
 YY_RULE_SETUP
-#line 195 "scan-gram.l"
+#line 184 "scan-gram.l"
 {
     obstack_grow (&string_obstack, yytext + 1, yyleng - 2);
     YY_OBS_FINISH;
@@ -1374,7 +1369,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 48:
 YY_RULE_SETUP
-#line 203 "scan-gram.l"
+#line 192 "scan-gram.l"
 {
     if (++percent_percent_count == 2)
       yy_push_state (SC_EPILOGUE);
@@ -1383,7 +1378,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 49:
 YY_RULE_SETUP
-#line 209 "scan-gram.l"
+#line 198 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": invalid character: `%c'\n"), *yytext);
@@ -1400,12 +1395,12 @@ YY_RULE_SETUP
 
 case 50:
 YY_RULE_SETUP
-#line 225 "scan-gram.l"
+#line 214 "scan-gram.l"
 if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@<:@");
 	YY_BREAK
 case 51:
 YY_RULE_SETUP
-#line 226 "scan-gram.l"
+#line 215 "scan-gram.l"
 if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@:>@");
 	YY_BREAK
 
@@ -1416,7 +1411,7 @@ if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@:>@");
 
 case 52:
 YY_RULE_SETUP
-#line 237 "scan-gram.l"
+#line 226 "scan-gram.l"
 { /* End of the comment. */
     if (yy_top_state () == INITIAL)
       {
@@ -1431,21 +1426,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 53:
 YY_RULE_SETUP
-#line 249 "scan-gram.l"
+#line 238 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case 54:
 YY_RULE_SETUP
-#line 250 "scan-gram.l"
+#line 239 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case 55:
 YY_RULE_SETUP
-#line 251 "scan-gram.l"
+#line 240 "scan-gram.l"
 /* Stray `*'. */if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_COMMENT):
-#line 253 "scan-gram.l"
+#line 242 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a comment\n"));
@@ -1461,7 +1456,7 @@ case YY_STATE_EOF(SC_COMMENT):
 
 case 56:
 YY_RULE_SETUP
-#line 268 "scan-gram.l"
+#line 257 "scan-gram.l"
 {
     assert (yy_top_state () == INITIAL);
     YY_OBS_GROW;
@@ -1474,16 +1469,16 @@ YY_RULE_SETUP
 	YY_BREAK
 case 57:
 YY_RULE_SETUP
-#line 278 "scan-gram.l"
+#line 267 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 58:
 YY_RULE_SETUP
-#line 280 "scan-gram.l"
+#line 269 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_STRING):
-#line 282 "scan-gram.l"
+#line 271 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a string\n"));
@@ -1503,7 +1498,7 @@ case YY_STATE_EOF(SC_ESCAPED_STRING):
 
 case 59:
 YY_RULE_SETUP
-#line 300 "scan-gram.l"
+#line 289 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () == INITIAL);
@@ -1522,16 +1517,16 @@ YY_RULE_SETUP
 	YY_BREAK
 case 60:
 YY_RULE_SETUP
-#line 316 "scan-gram.l"
+#line 305 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 61:
 YY_RULE_SETUP
-#line 318 "scan-gram.l"
+#line 307 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
-#line 320 "scan-gram.l"
+#line 309 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a character\n"));
@@ -1550,7 +1545,7 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 
 case 62:
 YY_RULE_SETUP
-#line 338 "scan-gram.l"
+#line 327 "scan-gram.l"
 {
     long c = strtol (yytext + 1, 0, 8);
     if (c > 255)
@@ -1565,54 +1560,54 @@ YY_RULE_SETUP
 	YY_BREAK
 case 63:
 YY_RULE_SETUP
-#line 350 "scan-gram.l"
+#line 339 "scan-gram.l"
 {
     obstack_1grow (&string_obstack, strtol (yytext + 2, 0, 16));
   }
 	YY_BREAK
 case 64:
 YY_RULE_SETUP
-#line 354 "scan-gram.l"
+#line 343 "scan-gram.l"
 obstack_1grow (&string_obstack, '\a');
 	YY_BREAK
 case 65:
 YY_RULE_SETUP
-#line 355 "scan-gram.l"
+#line 344 "scan-gram.l"
 obstack_1grow (&string_obstack, '\b');
 	YY_BREAK
 case 66:
 YY_RULE_SETUP
-#line 356 "scan-gram.l"
+#line 345 "scan-gram.l"
 obstack_1grow (&string_obstack, '\f');
 	YY_BREAK
 case 67:
 YY_RULE_SETUP
-#line 357 "scan-gram.l"
+#line 346 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n');
 	YY_BREAK
 case 68:
 YY_RULE_SETUP
-#line 358 "scan-gram.l"
+#line 347 "scan-gram.l"
 obstack_1grow (&string_obstack, '\r');
 	YY_BREAK
 case 69:
 YY_RULE_SETUP
-#line 359 "scan-gram.l"
+#line 348 "scan-gram.l"
 obstack_1grow (&string_obstack, '\t');
 	YY_BREAK
 case 70:
 YY_RULE_SETUP
-#line 360 "scan-gram.l"
+#line 349 "scan-gram.l"
 obstack_1grow (&string_obstack, '\v');
 	YY_BREAK
 case 71:
 YY_RULE_SETUP
-#line 361 "scan-gram.l"
+#line 350 "scan-gram.l"
 obstack_1grow (&string_obstack, yytext[1]);
 	YY_BREAK
 case 72:
 YY_RULE_SETUP
-#line 362 "scan-gram.l"
+#line 351 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unrecognized escape: %s\n"), quote (yytext));
@@ -1622,7 +1617,7 @@ YY_RULE_SETUP
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 73:
 YY_RULE_SETUP
-#line 368 "scan-gram.l"
+#line 357 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1634,7 +1629,7 @@ YY_OBS_GROW;
 
 case 74:
 YY_RULE_SETUP
-#line 379 "scan-gram.l"
+#line 368 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () != INITIAL);
@@ -1643,27 +1638,27 @@ YY_RULE_SETUP
 	YY_BREAK
 case 75:
 YY_RULE_SETUP
-#line 385 "scan-gram.l"
+#line 374 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 76:
 YY_RULE_SETUP
-#line 386 "scan-gram.l"
+#line 375 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 77:
 YY_RULE_SETUP
-#line 388 "scan-gram.l"
+#line 377 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 78:
 YY_RULE_SETUP
-#line 390 "scan-gram.l"
+#line 379 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_CHARACTER):
-#line 392 "scan-gram.l"
+#line 381 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a character\n"));
@@ -1680,7 +1675,7 @@ case YY_STATE_EOF(SC_CHARACTER):
 
 case 79:
 YY_RULE_SETUP
-#line 408 "scan-gram.l"
+#line 397 "scan-gram.l"
 {
     assert (yy_top_state () != INITIAL);
     YY_OBS_GROW;
@@ -1689,27 +1684,27 @@ YY_RULE_SETUP
 	YY_BREAK
 case 80:
 YY_RULE_SETUP
-#line 414 "scan-gram.l"
+#line 403 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 81:
 YY_RULE_SETUP
-#line 415 "scan-gram.l"
+#line 404 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 82:
 YY_RULE_SETUP
-#line 417 "scan-gram.l"
+#line 406 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 83:
 YY_RULE_SETUP
-#line 419 "scan-gram.l"
+#line 408 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_STRING):
-#line 421 "scan-gram.l"
+#line 410 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a string\n"));
@@ -1726,30 +1721,30 @@ case YY_STATE_EOF(SC_STRING):
 /* Characters.  We don't check there is only one.  */
 case 84:
 YY_RULE_SETUP
-#line 437 "scan-gram.l"
+#line 426 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 85:
 YY_RULE_SETUP
-#line 440 "scan-gram.l"
+#line 429 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_STRING);
 	YY_BREAK
 /* Comments. */
 case 86:
 YY_RULE_SETUP
-#line 443 "scan-gram.l"
+#line 432 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 87:
 YY_RULE_SETUP
-#line 444 "scan-gram.l"
+#line 433 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* Not comments. */
 case 88:
 YY_RULE_SETUP
-#line 447 "scan-gram.l"
+#line 436 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1761,7 +1756,7 @@ YY_OBS_GROW;
 
 case 89:
 YY_RULE_SETUP
-#line 458 "scan-gram.l"
+#line 447 "scan-gram.l"
 {
     YY_OBS_GROW;
     if (--braces_level == 0)
@@ -1776,39 +1771,39 @@ YY_RULE_SETUP
 	YY_BREAK
 case 90:
 YY_RULE_SETUP
-#line 470 "scan-gram.l"
+#line 459 "scan-gram.l"
 YY_OBS_GROW; braces_level++;
 	YY_BREAK
 case 91:
 YY_RULE_SETUP
-#line 472 "scan-gram.l"
+#line 461 "scan-gram.l"
 { handle_dollar (current_braced_code,
 						   yytext, *yylloc); }
 	YY_BREAK
 case 92:
 YY_RULE_SETUP
-#line 474 "scan-gram.l"
+#line 463 "scan-gram.l"
 { handle_at (current_braced_code,
 					       yytext, *yylloc); }
 	YY_BREAK
 case 93:
 YY_RULE_SETUP
-#line 477 "scan-gram.l"
+#line 466 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 94:
 YY_RULE_SETUP
-#line 478 "scan-gram.l"
+#line 467 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 /* A lose $, or /, or etc. */
 case 95:
 YY_RULE_SETUP
-#line 481 "scan-gram.l"
+#line 470 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 483 "scan-gram.l"
+#line 472 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a braced code\n"));
@@ -1826,7 +1821,7 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 96:
 YY_RULE_SETUP
-#line 501 "scan-gram.l"
+#line 490 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1836,21 +1831,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 97:
 YY_RULE_SETUP
-#line 508 "scan-gram.l"
+#line 497 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 98:
 YY_RULE_SETUP
-#line 509 "scan-gram.l"
+#line 498 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 99:
 YY_RULE_SETUP
-#line 510 "scan-gram.l"
+#line 499 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 512 "scan-gram.l"
+#line 501 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, _(": unexpected end of file in a prologue\n"));
@@ -1869,11 +1864,11 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 100:
 YY_RULE_SETUP
-#line 530 "scan-gram.l"
+#line 519 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 532 "scan-gram.l"
+#line 521 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1884,10 +1879,10 @@ case YY_STATE_EOF(SC_EPILOGUE):
 
 case 101:
 YY_RULE_SETUP
-#line 541 "scan-gram.l"
+#line 530 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1891 "scan-gram.c"
+#line 1886 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2777,7 +2772,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 541 "scan-gram.l"
+#line 530 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
