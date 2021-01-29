@@ -15,7 +15,7 @@
 #define yyrestart gram_restart
 #define yytext gram_text
 
-#line 19 "scan-gram.c"
+#line 19 "lex.yy.c"
 /* A lexical scanner generated by flex */
 
 /* Scanner skeleton version:
@@ -686,16 +686,16 @@ int yy_flex_debug = 1;
 
 static yyconst short int yy_rule_linenum[92] =
     {   0,
-      117,  118,  119,  120,  121,  122,  123,  124,  125,  126,
-      127,  128,  129,  130,  131,  132,  133,  134,  135,  136,
-      137,  138,  139,  140,  141,  142,  143,  145,  146,  147,
-      148,  150,  151,  152,  157,  160,  163,  166,  167,  170,
-      173,  176,  184,  190,  206,  207,  218,  230,  231,  232,
-      249,  258,  260,  280,  294,  296,  316,  328,  332,  333,
-      334,  335,  336,  337,  338,  339,  340,  355,  361,  362,
-      364,  382,  388,  389,  391,  409,  412,  415,  416,  427,
-      438,  440,  441,  443,  444,  447,  467,  474,  475,  476,
-      497
+      121,  122,  123,  124,  125,  126,  127,  128,  129,  130,
+      131,  132,  133,  134,  135,  136,  137,  138,  139,  140,
+      141,  142,  143,  144,  145,  146,  147,  149,  150,  151,
+      152,  154,  155,  156,  161,  164,  167,  170,  171,  174,
+      177,  180,  188,  194,  210,  211,  222,  234,  235,  236,
+      253,  262,  264,  284,  298,  300,  320,  332,  336,  337,
+      338,  339,  340,  341,  342,  343,  344,  359,  365,  366,
+      368,  386,  392,  393,  395,  413,  416,  419,  420,  431,
+      442,  444,  445,  447,  448,  451,  471,  478,  479,  480,
+      501
 
     } ;
 
@@ -741,6 +741,13 @@ char *yytext;
 #include "reader.h"
 
 /* Each time we match a string, move the end cursor to its end. */
+#define YY_USER_INIT				\
+do {						\
+  LOCATION_RESET (*yylloc);			\
+   /* This is only to avoid GCC warnings. */	\
+  if (yycontrol) {;};				\
+} while (0)
+
 #define YY_USER_ACTION  LOCATION_COLUMNS (*yylloc, yyleng)
 #define YY_LINES        LOCATION_LINES (*yylloc, yyleng); lineno += yyleng;
 #define YY_STEP         LOCATION_STEP (*yylloc)
@@ -779,9 +786,6 @@ scanner_last_string_free (void)
 }
 
 
-/* This is only to avoid GCC warnings. */
-#define YY_USER_INIT    if (yycontrol) {;};
-
 
 static int braces_level = 0;
 static int percent_percent_count = 0;
@@ -801,7 +805,7 @@ static void handle_at PARAMS ((char *cp));
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 805 "scan-gram.c"
+#line 809 "lex.yy.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -963,14 +967,14 @@ YY_DECL
 	register char *yy_cp, *yy_bp;
 	register int yy_act;
 
-#line 93 "scan-gram.l"
+#line 97 "scan-gram.l"
 
 
   /* At each yylex invocation, mark the current position as the
      start of the next token.  */
 #define TR_POS 0
 #if TR_POS
-  fprintf (stderr, "FOO1: ");
+  fprintf (stderr, "FOO1: %p: ", yylloc);
   LOCATION_PRINT (stderr, *yylloc);
   fprintf (stderr, "\n");
 #endif
@@ -986,7 +990,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 990 "scan-gram.c"
+#line 994 "lex.yy.c"
 
 	if ( yy_init )
 		{
@@ -1088,172 +1092,172 @@ do_action:	/* This label is used only to access EOF actions. */
 
 case 1:
 YY_RULE_SETUP
-#line 117 "scan-gram.l"
+#line 121 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 2:
 YY_RULE_SETUP
-#line 118 "scan-gram.l"
+#line 122 "scan-gram.l"
 return PERCENT_DEBUG;
 	YY_BREAK
 case 3:
 YY_RULE_SETUP
-#line 119 "scan-gram.l"
+#line 123 "scan-gram.l"
 return PERCENT_DEFINE;
 	YY_BREAK
 case 4:
 YY_RULE_SETUP
-#line 120 "scan-gram.l"
+#line 124 "scan-gram.l"
 return PERCENT_DEFINES;
 	YY_BREAK
 case 5:
 YY_RULE_SETUP
-#line 121 "scan-gram.l"
+#line 125 "scan-gram.l"
 return PERCENT_ERROR_VERBOSE;
 	YY_BREAK
 case 6:
 YY_RULE_SETUP
-#line 122 "scan-gram.l"
+#line 126 "scan-gram.l"
 return PERCENT_EXPECT;
 	YY_BREAK
 case 7:
 YY_RULE_SETUP
-#line 123 "scan-gram.l"
+#line 127 "scan-gram.l"
 return PERCENT_FILE_PREFIX;
 	YY_BREAK
 case 8:
 YY_RULE_SETUP
-#line 124 "scan-gram.l"
+#line 128 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 9:
 YY_RULE_SETUP
-#line 125 "scan-gram.l"
+#line 129 "scan-gram.l"
 return PERCENT_LEFT;
 	YY_BREAK
 case 10:
 YY_RULE_SETUP
-#line 126 "scan-gram.l"
+#line 130 "scan-gram.l"
 return PERCENT_LOCATIONS;
 	YY_BREAK
 case 11:
 YY_RULE_SETUP
-#line 127 "scan-gram.l"
+#line 131 "scan-gram.l"
 return PERCENT_NAME_PREFIX;
 	YY_BREAK
 case 12:
 YY_RULE_SETUP
-#line 128 "scan-gram.l"
+#line 132 "scan-gram.l"
 return PERCENT_NO_LINES;
 	YY_BREAK
 case 13:
 YY_RULE_SETUP
-#line 129 "scan-gram.l"
+#line 133 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 14:
 YY_RULE_SETUP
-#line 130 "scan-gram.l"
+#line 134 "scan-gram.l"
 return PERCENT_NTERM;
 	YY_BREAK
 case 15:
 YY_RULE_SETUP
-#line 131 "scan-gram.l"
+#line 135 "scan-gram.l"
 return PERCENT_OUTPUT;
 	YY_BREAK
 case 16:
 YY_RULE_SETUP
-#line 132 "scan-gram.l"
+#line 136 "scan-gram.l"
 return PERCENT_PREC;
 	YY_BREAK
 case 17:
 YY_RULE_SETUP
-#line 133 "scan-gram.l"
+#line 137 "scan-gram.l"
 return PERCENT_PURE_PARSER;
 	YY_BREAK
 case 18:
 YY_RULE_SETUP
-#line 134 "scan-gram.l"
+#line 138 "scan-gram.l"
 return PERCENT_RIGHT;
 	YY_BREAK
 case 19:
 YY_RULE_SETUP
-#line 135 "scan-gram.l"
+#line 139 "scan-gram.l"
 return PERCENT_SKELETON;
 	YY_BREAK
 case 20:
 YY_RULE_SETUP
-#line 136 "scan-gram.l"
+#line 140 "scan-gram.l"
 return PERCENT_START;
 	YY_BREAK
 case 21:
 YY_RULE_SETUP
-#line 137 "scan-gram.l"
+#line 141 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 22:
 YY_RULE_SETUP
-#line 138 "scan-gram.l"
+#line 142 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 23:
 YY_RULE_SETUP
-#line 139 "scan-gram.l"
+#line 143 "scan-gram.l"
 return PERCENT_TOKEN_TABLE;
 	YY_BREAK
 case 24:
 YY_RULE_SETUP
-#line 140 "scan-gram.l"
+#line 144 "scan-gram.l"
 return PERCENT_TYPE;
 	YY_BREAK
 case 25:
 YY_RULE_SETUP
-#line 141 "scan-gram.l"
+#line 145 "scan-gram.l"
 return PERCENT_UNION;
 	YY_BREAK
 case 26:
 YY_RULE_SETUP
-#line 142 "scan-gram.l"
+#line 146 "scan-gram.l"
 return PERCENT_VERBOSE;
 	YY_BREAK
 case 27:
 YY_RULE_SETUP
-#line 143 "scan-gram.l"
+#line 147 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 28:
 YY_RULE_SETUP
-#line 145 "scan-gram.l"
+#line 149 "scan-gram.l"
 return EQUAL;
 	YY_BREAK
 case 29:
 YY_RULE_SETUP
-#line 146 "scan-gram.l"
+#line 150 "scan-gram.l"
 return COLON;
 	YY_BREAK
 case 30:
 YY_RULE_SETUP
-#line 147 "scan-gram.l"
+#line 151 "scan-gram.l"
 return PIPE;
 	YY_BREAK
 case 31:
 YY_RULE_SETUP
-#line 148 "scan-gram.l"
+#line 152 "scan-gram.l"
 return SEMICOLON;
 	YY_BREAK
 case 32:
 YY_RULE_SETUP
-#line 150 "scan-gram.l"
+#line 154 "scan-gram.l"
 YY_LINES; YY_STEP;
 	YY_BREAK
 case 33:
 YY_RULE_SETUP
-#line 151 "scan-gram.l"
+#line 155 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 case 34:
 YY_RULE_SETUP
-#line 152 "scan-gram.l"
+#line 156 "scan-gram.l"
 {
     yylval->symbol = getsym (yytext);
     return ID;
@@ -1261,48 +1265,48 @@ YY_RULE_SETUP
 	YY_BREAK
 case 35:
 YY_RULE_SETUP
-#line 157 "scan-gram.l"
+#line 161 "scan-gram.l"
 yylval->integer = strtol (yytext, 0, 10); return INT;
 	YY_BREAK
 /* Characters.  We don't check there is only one.  */
 case 36:
 YY_RULE_SETUP
-#line 160 "scan-gram.l"
+#line 164 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 37:
 YY_RULE_SETUP
-#line 163 "scan-gram.l"
+#line 167 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_STRING);
 	YY_BREAK
 /* Comments. */
 case 38:
 YY_RULE_SETUP
-#line 166 "scan-gram.l"
+#line 170 "scan-gram.l"
 yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 39:
 YY_RULE_SETUP
-#line 167 "scan-gram.l"
+#line 171 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 /* Prologue. */
 case 40:
 YY_RULE_SETUP
-#line 170 "scan-gram.l"
+#line 174 "scan-gram.l"
 yy_push_state (SC_PROLOGUE);
 	YY_BREAK
 /* Code in between braces.  */
 case 41:
 YY_RULE_SETUP
-#line 173 "scan-gram.l"
+#line 177 "scan-gram.l"
 YY_OBS_GROW; ++braces_level; yy_push_state (SC_BRACED_CODE);
 	YY_BREAK
 /* A type. */
 case 42:
 YY_RULE_SETUP
-#line 176 "scan-gram.l"
+#line 180 "scan-gram.l"
 {
     obstack_grow (&string_obstack, yytext + 1, yyleng - 2);
     YY_OBS_FINISH;
@@ -1312,7 +1316,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 43:
 YY_RULE_SETUP
-#line 184 "scan-gram.l"
+#line 188 "scan-gram.l"
 {
     if (++percent_percent_count == 2)
       yy_push_state (SC_EPILOGUE);
@@ -1321,7 +1325,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 44:
 YY_RULE_SETUP
-#line 190 "scan-gram.l"
+#line 194 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": invalid character: `%c'\n", *yytext);
@@ -1338,12 +1342,12 @@ YY_RULE_SETUP
 
 case 45:
 YY_RULE_SETUP
-#line 206 "scan-gram.l"
+#line 210 "scan-gram.l"
 if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@<:@");
 	YY_BREAK
 case 46:
 YY_RULE_SETUP
-#line 207 "scan-gram.l"
+#line 211 "scan-gram.l"
 if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@:>@");
 	YY_BREAK
 
@@ -1354,7 +1358,7 @@ if (YY_START != SC_COMMENT) obstack_sgrow (&string_obstack, "@:>@");
 
 case 47:
 YY_RULE_SETUP
-#line 218 "scan-gram.l"
+#line 222 "scan-gram.l"
 { /* End of the comment. */
     if (yy_top_state () == INITIAL)
       {
@@ -1369,21 +1373,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 48:
 YY_RULE_SETUP
-#line 230 "scan-gram.l"
+#line 234 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case 49:
 YY_RULE_SETUP
-#line 231 "scan-gram.l"
+#line 235 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case 50:
 YY_RULE_SETUP
-#line 232 "scan-gram.l"
+#line 236 "scan-gram.l"
 /* Stray `*'. */if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_COMMENT):
-#line 234 "scan-gram.l"
+#line 238 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a comment\n");
@@ -1399,7 +1403,7 @@ case YY_STATE_EOF(SC_COMMENT):
 
 case 51:
 YY_RULE_SETUP
-#line 249 "scan-gram.l"
+#line 253 "scan-gram.l"
 {
     assert (yy_top_state () == INITIAL);
     YY_OBS_GROW;
@@ -1411,16 +1415,16 @@ YY_RULE_SETUP
 	YY_BREAK
 case 52:
 YY_RULE_SETUP
-#line 258 "scan-gram.l"
+#line 262 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 53:
 YY_RULE_SETUP
-#line 260 "scan-gram.l"
+#line 264 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_STRING):
-#line 262 "scan-gram.l"
+#line 266 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a string\n");
@@ -1440,7 +1444,7 @@ case YY_STATE_EOF(SC_ESCAPED_STRING):
 
 case 54:
 YY_RULE_SETUP
-#line 280 "scan-gram.l"
+#line 284 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () == INITIAL);
@@ -1457,16 +1461,16 @@ YY_RULE_SETUP
 	YY_BREAK
 case 55:
 YY_RULE_SETUP
-#line 294 "scan-gram.l"
+#line 298 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 56:
 YY_RULE_SETUP
-#line 296 "scan-gram.l"
+#line 300 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
-#line 298 "scan-gram.l"
+#line 302 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
@@ -1485,7 +1489,7 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 
 case 57:
 YY_RULE_SETUP
-#line 316 "scan-gram.l"
+#line 320 "scan-gram.l"
 {
     long c = strtol (yytext + 1, 0, 8);
     if (c > 255)
@@ -1500,54 +1504,54 @@ YY_RULE_SETUP
 	YY_BREAK
 case 58:
 YY_RULE_SETUP
-#line 328 "scan-gram.l"
+#line 332 "scan-gram.l"
 {
     obstack_1grow (&string_obstack, strtol (yytext + 2, 0, 16));
   }
 	YY_BREAK
 case 59:
 YY_RULE_SETUP
-#line 332 "scan-gram.l"
+#line 336 "scan-gram.l"
 obstack_1grow (&string_obstack, '\a');
 	YY_BREAK
 case 60:
 YY_RULE_SETUP
-#line 333 "scan-gram.l"
+#line 337 "scan-gram.l"
 obstack_1grow (&string_obstack, '\b');
 	YY_BREAK
 case 61:
 YY_RULE_SETUP
-#line 334 "scan-gram.l"
+#line 338 "scan-gram.l"
 obstack_1grow (&string_obstack, '\f');
 	YY_BREAK
 case 62:
 YY_RULE_SETUP
-#line 335 "scan-gram.l"
+#line 339 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n');
 	YY_BREAK
 case 63:
 YY_RULE_SETUP
-#line 336 "scan-gram.l"
+#line 340 "scan-gram.l"
 obstack_1grow (&string_obstack, '\r');
 	YY_BREAK
 case 64:
 YY_RULE_SETUP
-#line 337 "scan-gram.l"
+#line 341 "scan-gram.l"
 obstack_1grow (&string_obstack, '\t');
 	YY_BREAK
 case 65:
 YY_RULE_SETUP
-#line 338 "scan-gram.l"
+#line 342 "scan-gram.l"
 obstack_1grow (&string_obstack, '\v');
 	YY_BREAK
 case 66:
 YY_RULE_SETUP
-#line 339 "scan-gram.l"
+#line 343 "scan-gram.l"
 obstack_1grow (&string_obstack, yytext[1]);
 	YY_BREAK
 case 67:
 YY_RULE_SETUP
-#line 340 "scan-gram.l"
+#line 344 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unrecognized escape: %s\n", yytext);
@@ -1563,7 +1567,7 @@ YY_RULE_SETUP
 
 case 68:
 YY_RULE_SETUP
-#line 355 "scan-gram.l"
+#line 359 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () != INITIAL);
@@ -1572,21 +1576,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 69:
 YY_RULE_SETUP
-#line 361 "scan-gram.l"
+#line 365 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 70:
 YY_RULE_SETUP
-#line 362 "scan-gram.l"
+#line 366 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 71:
 YY_RULE_SETUP
-#line 364 "scan-gram.l"
+#line 368 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_CHARACTER):
-#line 366 "scan-gram.l"
+#line 370 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
@@ -1603,7 +1607,7 @@ case YY_STATE_EOF(SC_CHARACTER):
 
 case 72:
 YY_RULE_SETUP
-#line 382 "scan-gram.l"
+#line 386 "scan-gram.l"
 {
     assert (yy_top_state () != INITIAL);
     YY_OBS_GROW;
@@ -1612,21 +1616,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 73:
 YY_RULE_SETUP
-#line 388 "scan-gram.l"
+#line 392 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 74:
 YY_RULE_SETUP
-#line 389 "scan-gram.l"
+#line 393 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 75:
 YY_RULE_SETUP
-#line 391 "scan-gram.l"
+#line 395 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_STRING):
-#line 393 "scan-gram.l"
+#line 397 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a string\n");
@@ -1643,24 +1647,24 @@ case YY_STATE_EOF(SC_STRING):
 /* Characters.  We don't check there is only one.  */
 case 76:
 YY_RULE_SETUP
-#line 409 "scan-gram.l"
+#line 413 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 77:
 YY_RULE_SETUP
-#line 412 "scan-gram.l"
+#line 416 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_STRING);
 	YY_BREAK
 /* Comments. */
 case 78:
 YY_RULE_SETUP
-#line 415 "scan-gram.l"
+#line 419 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 79:
 YY_RULE_SETUP
-#line 416 "scan-gram.l"
+#line 420 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1672,7 +1676,7 @@ YY_OBS_GROW;
 
 case 80:
 YY_RULE_SETUP
-#line 427 "scan-gram.l"
+#line 431 "scan-gram.l"
 {
     YY_OBS_GROW;
     if (--braces_level == 0)
@@ -1686,37 +1690,37 @@ YY_RULE_SETUP
 	YY_BREAK
 case 81:
 YY_RULE_SETUP
-#line 438 "scan-gram.l"
+#line 442 "scan-gram.l"
 YY_OBS_GROW; braces_level++;
 	YY_BREAK
 case 82:
 YY_RULE_SETUP
-#line 440 "scan-gram.l"
+#line 444 "scan-gram.l"
 { handle_dollar (yytext); }
 	YY_BREAK
 case 83:
 YY_RULE_SETUP
-#line 441 "scan-gram.l"
+#line 445 "scan-gram.l"
 { handle_at (yytext); }
 	YY_BREAK
 case 84:
 YY_RULE_SETUP
-#line 443 "scan-gram.l"
+#line 447 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 85:
 YY_RULE_SETUP
-#line 444 "scan-gram.l"
+#line 448 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 /* A lose $, or /, or etc. */
 case 86:
 YY_RULE_SETUP
-#line 447 "scan-gram.l"
+#line 451 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 449 "scan-gram.l"
+#line 453 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a braced code\n");
@@ -1734,7 +1738,7 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 87:
 YY_RULE_SETUP
-#line 467 "scan-gram.l"
+#line 471 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1744,21 +1748,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 88:
 YY_RULE_SETUP
-#line 474 "scan-gram.l"
+#line 478 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 89:
 YY_RULE_SETUP
-#line 475 "scan-gram.l"
+#line 479 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 90:
 YY_RULE_SETUP
-#line 476 "scan-gram.l"
+#line 480 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 478 "scan-gram.l"
+#line 482 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a prologue\n");
@@ -1777,11 +1781,11 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 91:
 YY_RULE_SETUP
-#line 497 "scan-gram.l"
+#line 501 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 499 "scan-gram.l"
+#line 503 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1792,10 +1796,10 @@ case YY_STATE_EOF(SC_EPILOGUE):
 
 case 92:
 YY_RULE_SETUP
-#line 508 "scan-gram.l"
+#line 512 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1799 "scan-gram.c"
+#line 1803 "lex.yy.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2685,7 +2689,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 508 "scan-gram.l"
+#line 512 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
