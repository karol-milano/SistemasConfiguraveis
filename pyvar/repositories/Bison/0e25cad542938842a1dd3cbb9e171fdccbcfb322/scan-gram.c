@@ -734,18 +734,18 @@ int yy_flex_debug = 1;
 
 static yyconst short int yy_rule_linenum[104] =
     {   0,
-      218,  219,  220,  221,  222,  223,  224,  225,  226,  227,
-      228,  229,  230,  231,  232,  233,  234,  235,  236,  237,
-      238,  239,  240,  241,  242,  243,  244,  245,  246,  247,
-      248,  249,  250,  251,  253,  258,  260,  261,  262,  263,
-      264,  266,  268,  274,  288,  291,  294,  295,  298,  301,
-      304,  312,  318,  333,  334,  344,  349,  364,  365,  380,
-      381,  393,  403,  422,  438,  457,  469,  483,  484,  485,
-      486,  487,  488,  489,  490,  491,  502,  508,  519,  525,
-      526,  527,  529,  546,  552,  553,  554,  556,  573,  576,
-      579,  580,  583,  594,  595,  596,  609,  611,  616,  635,
-
-      642,  643,  662
+      231,  232,  233,  234,  235,  236,  237,  238,  239,  240,
+      241,  242,  243,  244,  245,  246,  247,  248,  249,  250,
+      251,  252,  253,  254,  255,  256,  257,  258,  259,  260,
+      261,  262,  263,  264,  266,  271,  273,  274,  275,  276,
+      277,  279,  281,  287,  301,  304,  307,  308,  311,  314,
+      317,  325,  331,  346,  347,  357,  362,  377,  378,  393,
+      394,  406,  416,  435,  451,  470,  482,  496,  497,  498,
+      499,  500,  501,  502,  503,  504,  515,  521,  532,  538,
+      539,  540,  542,  559,  565,  566,  567,  569,  586,  589,
+      592,  593,  596,  607,  608,  609,  622,  624,  629,  648,
+
+      655,  656,  675
     } ;
 
 /* The intent behind this definition is that it'll catch
@@ -888,6 +888,19 @@ extend_location (location_t *loc, char const *token, int size)
 }
 
 
+/* Report an unexpected end of file at LOC.  A token or comment began
+   with TOKEN_START, but an end of file was encountered and the
+   expected TOKEN_END was missing.  */
+
+static void
+unexpected_end_of_file (location_t loc,
+			char const *token_start, char const *token_end)
+{
+  complain_at (loc, _("unexpected end of file in `%s ... %s'"),
+	       token_start, token_end);
+}
+
+
 
 /* STRING_OBSTACK -- Used to store all the characters that we need to
    keep (to construct ID, STRINGS etc.).  Use the following macros to
@@ -958,7 +971,7 @@ static int convert_ucn_to_byte (char const *hex_text);
    NUL and newline, as this simplifies our implementation.  */
 /* Zero or more instances of backslash-newline.  Following GCC, allow
    white space between the backslash and the newline.  */
-#line 962 "scan-gram.c"
+#line 975 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -1123,7 +1136,7 @@ YY_DECL
 	register char *yy_cp, *yy_bp;
 	register int yy_act;
 
-#line 203 "scan-gram.l"
+#line 216 "scan-gram.l"
 
 
   int braces_level IF_LINT (= 0);
@@ -1137,7 +1150,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1141 "scan-gram.c"
+#line 1154 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -1240,177 +1253,177 @@ do_action:	/* This label is used only to access EOF actions. */
 
 case 1:
 YY_RULE_SETUP
-#line 218 "scan-gram.l"
+#line 231 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 2:
 YY_RULE_SETUP
-#line 219 "scan-gram.l"
+#line 232 "scan-gram.l"
 return PERCENT_DEBUG;
 	YY_BREAK
 case 3:
 YY_RULE_SETUP
-#line 220 "scan-gram.l"
+#line 233 "scan-gram.l"
 return PERCENT_DEFINE;
 	YY_BREAK
 case 4:
 YY_RULE_SETUP
-#line 221 "scan-gram.l"
+#line 234 "scan-gram.l"
 return PERCENT_DEFINES;
 	YY_BREAK
 case 5:
 YY_RULE_SETUP
-#line 222 "scan-gram.l"
+#line 235 "scan-gram.l"
 return PERCENT_DESTRUCTOR;
 	YY_BREAK
 case 6:
 YY_RULE_SETUP
-#line 223 "scan-gram.l"
+#line 236 "scan-gram.l"
 return PERCENT_DPREC;
 	YY_BREAK
 case 7:
 YY_RULE_SETUP
-#line 224 "scan-gram.l"
+#line 237 "scan-gram.l"
 return PERCENT_ERROR_VERBOSE;
 	YY_BREAK
 case 8:
 YY_RULE_SETUP
-#line 225 "scan-gram.l"
+#line 238 "scan-gram.l"
 return PERCENT_EXPECT;
 	YY_BREAK
 case 9:
 YY_RULE_SETUP
-#line 226 "scan-gram.l"
+#line 239 "scan-gram.l"
 return PERCENT_FILE_PREFIX;
 	YY_BREAK
 case 10:
 YY_RULE_SETUP
-#line 227 "scan-gram.l"
+#line 240 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 11:
 YY_RULE_SETUP
-#line 228 "scan-gram.l"
+#line 241 "scan-gram.l"
 return PERCENT_GLR_PARSER;
 	YY_BREAK
 case 12:
 YY_RULE_SETUP
-#line 229 "scan-gram.l"
+#line 242 "scan-gram.l"
 return PERCENT_LEFT;
 	YY_BREAK
 case 13:
 YY_RULE_SETUP
-#line 230 "scan-gram.l"
+#line 243 "scan-gram.l"
 return PERCENT_LOCATIONS;
 	YY_BREAK
 case 14:
 YY_RULE_SETUP
-#line 231 "scan-gram.l"
+#line 244 "scan-gram.l"
 return PERCENT_MERGE;
 	YY_BREAK
 case 15:
 YY_RULE_SETUP
-#line 232 "scan-gram.l"
+#line 245 "scan-gram.l"
 return PERCENT_NAME_PREFIX;
 	YY_BREAK
 case 16:
 YY_RULE_SETUP
-#line 233 "scan-gram.l"
+#line 246 "scan-gram.l"
 return PERCENT_NO_LINES;
 	YY_BREAK
 case 17:
 YY_RULE_SETUP
-#line 234 "scan-gram.l"
+#line 247 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 18:
 YY_RULE_SETUP
-#line 235 "scan-gram.l"
+#line 248 "scan-gram.l"
 return PERCENT_NTERM;
 	YY_BREAK
 case 19:
 YY_RULE_SETUP
-#line 236 "scan-gram.l"
+#line 249 "scan-gram.l"
 return PERCENT_OUTPUT;
 	YY_BREAK
 case 20:
 YY_RULE_SETUP
-#line 237 "scan-gram.l"
+#line 250 "scan-gram.l"
 return PERCENT_PARSE_PARAM;
 	YY_BREAK
 case 21:
 YY_RULE_SETUP
-#line 238 "scan-gram.l"
+#line 251 "scan-gram.l"
 rule_length--; return PERCENT_PREC;
 	YY_BREAK
 case 22:
 YY_RULE_SETUP
-#line 239 "scan-gram.l"
+#line 252 "scan-gram.l"
 return PERCENT_PRINTER;
 	YY_BREAK
 case 23:
 YY_RULE_SETUP
-#line 240 "scan-gram.l"
+#line 253 "scan-gram.l"
 return PERCENT_PURE_PARSER;
 	YY_BREAK
 case 24:
 YY_RULE_SETUP
-#line 241 "scan-gram.l"
+#line 254 "scan-gram.l"
 return PERCENT_RIGHT;
 	YY_BREAK
 case 25:
 YY_RULE_SETUP
-#line 242 "scan-gram.l"
+#line 255 "scan-gram.l"
 return PERCENT_LEX_PARAM;
 	YY_BREAK
 case 26:
 YY_RULE_SETUP
-#line 243 "scan-gram.l"
+#line 256 "scan-gram.l"
 return PERCENT_SKELETON;
 	YY_BREAK
 case 27:
 YY_RULE_SETUP
-#line 244 "scan-gram.l"
+#line 257 "scan-gram.l"
 return PERCENT_START;
 	YY_BREAK
 case 28:
 YY_RULE_SETUP
-#line 245 "scan-gram.l"
+#line 258 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 29:
 YY_RULE_SETUP
-#line 246 "scan-gram.l"
+#line 259 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 30:
 YY_RULE_SETUP
-#line 247 "scan-gram.l"
+#line 260 "scan-gram.l"
 return PERCENT_TOKEN_TABLE;
 	YY_BREAK
 case 31:
 YY_RULE_SETUP
-#line 248 "scan-gram.l"
+#line 261 "scan-gram.l"
 return PERCENT_TYPE;
 	YY_BREAK
 case 32:
 YY_RULE_SETUP
-#line 249 "scan-gram.l"
+#line 262 "scan-gram.l"
 return PERCENT_UNION;
 	YY_BREAK
 case 33:
 YY_RULE_SETUP
-#line 250 "scan-gram.l"
+#line 263 "scan-gram.l"
 return PERCENT_VERBOSE;
 	YY_BREAK
 case 34:
 YY_RULE_SETUP
-#line 251 "scan-gram.l"
+#line 264 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 35:
 YY_RULE_SETUP
-#line 253 "scan-gram.l"
+#line 266 "scan-gram.l"
 {
     complain_at (*yylloc, _("invalid directive: %s"), quote (yytext));
     YY_STEP;
@@ -1418,42 +1431,42 @@ YY_RULE_SETUP
 	YY_BREAK
 case 36:
 YY_RULE_SETUP
-#line 258 "scan-gram.l"
+#line 271 "scan-gram.l"
 handle_syncline (yytext + strlen ("#line "), yylloc); YY_STEP;
 	YY_BREAK
 case 37:
 YY_RULE_SETUP
-#line 260 "scan-gram.l"
+#line 273 "scan-gram.l"
 return EQUAL;
 	YY_BREAK
 case 38:
 YY_RULE_SETUP
-#line 261 "scan-gram.l"
+#line 274 "scan-gram.l"
 rule_length = 0; return COLON;
 	YY_BREAK
 case 39:
 YY_RULE_SETUP
-#line 262 "scan-gram.l"
+#line 275 "scan-gram.l"
 rule_length = 0; return PIPE;
 	YY_BREAK
 case 40:
 YY_RULE_SETUP
-#line 263 "scan-gram.l"
+#line 276 "scan-gram.l"
 return COMMA;
 	YY_BREAK
 case 41:
 YY_RULE_SETUP
-#line 264 "scan-gram.l"
+#line 277 "scan-gram.l"
 return SEMICOLON;
 	YY_BREAK
 case 42:
 YY_RULE_SETUP
-#line 266 "scan-gram.l"
+#line 279 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 case 43:
 YY_RULE_SETUP
-#line 268 "scan-gram.l"
+#line 281 "scan-gram.l"
 {
     yylval->symbol = symbol_get (yytext, *yylloc);
     rule_length++;
@@ -1462,7 +1475,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 44:
 YY_RULE_SETUP
-#line 274 "scan-gram.l"
+#line 287 "scan-gram.l"
 {
     unsigned long num;
     errno = 0;
@@ -1479,42 +1492,42 @@ YY_RULE_SETUP
 /* Characters.  We don't check there is only one.  */
 case 45:
 YY_RULE_SETUP
-#line 288 "scan-gram.l"
+#line 301 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 46:
 YY_RULE_SETUP
-#line 291 "scan-gram.l"
+#line 304 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_ESCAPED_STRING);
 	YY_BREAK
 /* Comments. */
 case 47:
 YY_RULE_SETUP
-#line 294 "scan-gram.l"
+#line 307 "scan-gram.l"
 BEGIN SC_YACC_COMMENT;
 	YY_BREAK
 case 48:
 YY_RULE_SETUP
-#line 295 "scan-gram.l"
+#line 308 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 /* Prologue. */
 case 49:
 YY_RULE_SETUP
-#line 298 "scan-gram.l"
+#line 311 "scan-gram.l"
 yy_push_state (SC_PROLOGUE);
 	YY_BREAK
 /* Code in between braces.  */
 case 50:
 YY_RULE_SETUP
-#line 301 "scan-gram.l"
+#line 314 "scan-gram.l"
 YY_OBS_GROW; braces_level = 0; yy_push_state (SC_BRACED_CODE);
 	YY_BREAK
 /* A type. */
 case 51:
 YY_RULE_SETUP
-#line 304 "scan-gram.l"
+#line 317 "scan-gram.l"
 {
     obstack_grow (&string_obstack, yytext + 1, yyleng - 2);
     YY_OBS_FINISH;
@@ -1524,7 +1537,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 52:
 YY_RULE_SETUP
-#line 312 "scan-gram.l"
+#line 325 "scan-gram.l"
 {
     if (++percent_percent_count == 2)
       yy_push_state (SC_EPILOGUE);
@@ -1533,7 +1546,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 53:
 YY_RULE_SETUP
-#line 318 "scan-gram.l"
+#line 331 "scan-gram.l"
 {
     complain_at (*yylloc, _("invalid character: %s"), quote (yytext));
     YY_STEP;
@@ -1549,12 +1562,12 @@ YY_RULE_SETUP
 
 case 54:
 YY_RULE_SETUP
-#line 333 "scan-gram.l"
+#line 346 "scan-gram.l"
 obstack_sgrow (&string_obstack, "@<:@");
 	YY_BREAK
 case 55:
 YY_RULE_SETUP
-#line 334 "scan-gram.l"
+#line 347 "scan-gram.l"
 obstack_sgrow (&string_obstack, "@:>@");
 	YY_BREAK
 
@@ -1565,7 +1578,7 @@ obstack_sgrow (&string_obstack, "@:>@");
 
 case 56:
 YY_RULE_SETUP
-#line 344 "scan-gram.l"
+#line 357 "scan-gram.l"
 {
     YY_STEP;
     BEGIN INITIAL;
@@ -1573,13 +1586,13 @@ YY_RULE_SETUP
 	YY_BREAK
 case 57:
 YY_RULE_SETUP
-#line 349 "scan-gram.l"
+#line 362 "scan-gram.l"
 ;
 	YY_BREAK
 case YY_STATE_EOF(SC_YACC_COMMENT):
-#line 351 "scan-gram.l"
+#line 364 "scan-gram.l"
 {
-    complain_at (*yylloc, _("unexpected end of file in a comment"));
+    unexpected_end_of_file (*yylloc, "/*", "*/");
     BEGIN INITIAL;
   }
 	YY_BREAK
@@ -1591,18 +1604,18 @@ case YY_STATE_EOF(SC_YACC_COMMENT):
 
 case 58:
 YY_RULE_SETUP
-#line 364 "scan-gram.l"
+#line 377 "scan-gram.l"
 YY_OBS_GROW; yy_pop_state ();
 	YY_BREAK
 case 59:
 YY_RULE_SETUP
-#line 365 "scan-gram.l"
+#line 378 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_COMMENT):
-#line 367 "scan-gram.l"
+#line 380 "scan-gram.l"
 {
-    complain_at (*yylloc, _("unexpected end of file in a comment"));
+    unexpected_end_of_file (*yylloc, "/*", "*/");
     yy_pop_state ();
   }
 	YY_BREAK
@@ -1614,16 +1627,16 @@ case YY_STATE_EOF(SC_COMMENT):
 
 case 60:
 YY_RULE_SETUP
-#line 380 "scan-gram.l"
+#line 393 "scan-gram.l"
 YY_OBS_GROW; yy_pop_state ();
 	YY_BREAK
 case 61:
 YY_RULE_SETUP
-#line 381 "scan-gram.l"
+#line 394 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_LINE_COMMENT):
-#line 382 "scan-gram.l"
+#line 395 "scan-gram.l"
 yy_pop_state ();
 	YY_BREAK
 
@@ -1635,7 +1648,7 @@ yy_pop_state ();
 
 case 62:
 YY_RULE_SETUP
-#line 393 "scan-gram.l"
+#line 406 "scan-gram.l"
 {
     assert (yy_top_state () == INITIAL);
     YY_OBS_GROW;
@@ -1648,13 +1661,13 @@ YY_RULE_SETUP
 	YY_BREAK
 case 63:
 YY_RULE_SETUP
-#line 403 "scan-gram.l"
+#line 416 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_STRING):
-#line 405 "scan-gram.l"
+#line 418 "scan-gram.l"
 {
-    complain_at (*yylloc, _("unexpected end of file in a string"));
+    unexpected_end_of_file (*yylloc, "\"", "\"");
     assert (yy_top_state () == INITIAL);
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -1671,7 +1684,7 @@ case YY_STATE_EOF(SC_ESCAPED_STRING):
 
 case 64:
 YY_RULE_SETUP
-#line 422 "scan-gram.l"
+#line 435 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () == INITIAL);
@@ -1690,13 +1703,13 @@ YY_RULE_SETUP
 	YY_BREAK
 case 65:
 YY_RULE_SETUP
-#line 438 "scan-gram.l"
+#line 451 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
-#line 440 "scan-gram.l"
+#line 453 "scan-gram.l"
 {
-    complain_at (*yylloc, _("unexpected end of file in a character literal"));
+    unexpected_end_of_file (*yylloc, "'", "'");
     assert (yy_top_state () == INITIAL);
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -1712,7 +1725,7 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 
 case 66:
 YY_RULE_SETUP
-#line 457 "scan-gram.l"
+#line 470 "scan-gram.l"
 {
     unsigned long c = strtoul (yytext + 1, 0, 8);
     if (UCHAR_MAX < c)
@@ -1727,7 +1740,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 67:
 YY_RULE_SETUP
-#line 469 "scan-gram.l"
+#line 482 "scan-gram.l"
 {
     unsigned long c;
     errno = 0;
@@ -1744,47 +1757,47 @@ YY_RULE_SETUP
 	YY_BREAK
 case 68:
 YY_RULE_SETUP
-#line 483 "scan-gram.l"
+#line 496 "scan-gram.l"
 obstack_1grow (&string_obstack, '\a');
 	YY_BREAK
 case 69:
 YY_RULE_SETUP
-#line 484 "scan-gram.l"
+#line 497 "scan-gram.l"
 obstack_1grow (&string_obstack, '\b');
 	YY_BREAK
 case 70:
 YY_RULE_SETUP
-#line 485 "scan-gram.l"
+#line 498 "scan-gram.l"
 obstack_1grow (&string_obstack, '\f');
 	YY_BREAK
 case 71:
 YY_RULE_SETUP
-#line 486 "scan-gram.l"
+#line 499 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n');
 	YY_BREAK
 case 72:
 YY_RULE_SETUP
-#line 487 "scan-gram.l"
+#line 500 "scan-gram.l"
 obstack_1grow (&string_obstack, '\r');
 	YY_BREAK
 case 73:
 YY_RULE_SETUP
-#line 488 "scan-gram.l"
+#line 501 "scan-gram.l"
 obstack_1grow (&string_obstack, '\t');
 	YY_BREAK
 case 74:
 YY_RULE_SETUP
-#line 489 "scan-gram.l"
+#line 502 "scan-gram.l"
 obstack_1grow (&string_obstack, '\v');
 	YY_BREAK
 case 75:
 YY_RULE_SETUP
-#line 490 "scan-gram.l"
+#line 503 "scan-gram.l"
 obstack_1grow (&string_obstack, yytext[1]);
 	YY_BREAK
 case 76:
 YY_RULE_SETUP
-#line 491 "scan-gram.l"
+#line 504 "scan-gram.l"
 {
     int c = convert_ucn_to_byte (yytext);
     if (c < 0)
@@ -1799,7 +1812,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 77:
 YY_RULE_SETUP
-#line 502 "scan-gram.l"
+#line 515 "scan-gram.l"
 {
     complain_at (*yylloc, _("unrecognized escape sequence: %s"),
 		 quote (yytext));
@@ -1809,7 +1822,7 @@ YY_RULE_SETUP
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 78:
 YY_RULE_SETUP
-#line 508 "scan-gram.l"
+#line 521 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1821,7 +1834,7 @@ YY_OBS_GROW;
 
 case 79:
 YY_RULE_SETUP
-#line 519 "scan-gram.l"
+#line 532 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () != INITIAL);
@@ -1830,29 +1843,29 @@ YY_RULE_SETUP
 	YY_BREAK
 case 80:
 YY_RULE_SETUP
-#line 525 "scan-gram.l"
+#line 538 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 81:
 YY_RULE_SETUP
-#line 526 "scan-gram.l"
+#line 539 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 82:
 YY_RULE_SETUP
-#line 527 "scan-gram.l"
+#line 540 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* Needed for `\<<EOF>>', `\\<<newline>>[', and `\\<<newline>>]'.  */
 case 83:
 YY_RULE_SETUP
-#line 529 "scan-gram.l"
+#line 542 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_CHARACTER):
-#line 531 "scan-gram.l"
+#line 544 "scan-gram.l"
 {
-    complain_at (*yylloc, _("unexpected end of file in a character literal"));
+    unexpected_end_of_file (*yylloc, "'", "'");
     assert (yy_top_state () != INITIAL);
     yy_pop_state ();
   }
@@ -1866,7 +1879,7 @@ case YY_STATE_EOF(SC_CHARACTER):
 
 case 84:
 YY_RULE_SETUP
-#line 546 "scan-gram.l"
+#line 559 "scan-gram.l"
 {
     assert (yy_top_state () != INITIAL);
     YY_OBS_GROW;
@@ -1875,29 +1888,29 @@ YY_RULE_SETUP
 	YY_BREAK
 case 85:
 YY_RULE_SETUP
-#line 552 "scan-gram.l"
+#line 565 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 86:
 YY_RULE_SETUP
-#line 553 "scan-gram.l"
+#line 566 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 87:
 YY_RULE_SETUP
-#line 554 "scan-gram.l"
+#line 567 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* Needed for `\<<EOF>>', `\\<<newline>>[', and `\\<<newline>>]'.  */
 case 88:
 YY_RULE_SETUP
-#line 556 "scan-gram.l"
+#line 569 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_STRING):
-#line 558 "scan-gram.l"
+#line 571 "scan-gram.l"
 {
-    complain_at (*yylloc, _("unexpected end of file in a string"));
+    unexpected_end_of_file (*yylloc, "\"", "\"");
     assert (yy_top_state () != INITIAL);
     yy_pop_state ();
   }
@@ -1911,30 +1924,30 @@ case YY_STATE_EOF(SC_STRING):
 /* Characters.  We don't check there is only one.  */
 case 89:
 YY_RULE_SETUP
-#line 573 "scan-gram.l"
+#line 586 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 90:
 YY_RULE_SETUP
-#line 576 "scan-gram.l"
+#line 589 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_STRING);
 	YY_BREAK
 /* Comments. */
 case 91:
 YY_RULE_SETUP
-#line 579 "scan-gram.l"
+#line 592 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 92:
 YY_RULE_SETUP
-#line 580 "scan-gram.l"
+#line 593 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_LINE_COMMENT);
 	YY_BREAK
 /* Not comments. */
 case 93:
 YY_RULE_SETUP
-#line 583 "scan-gram.l"
+#line 596 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1946,17 +1959,17 @@ YY_OBS_GROW;
 
 case 94:
 YY_RULE_SETUP
-#line 594 "scan-gram.l"
+#line 607 "scan-gram.l"
 YY_OBS_GROW; braces_level++;
 	YY_BREAK
 case 95:
 YY_RULE_SETUP
-#line 595 "scan-gram.l"
+#line 608 "scan-gram.l"
 YY_OBS_GROW; braces_level--;
 	YY_BREAK
 case 96:
 YY_RULE_SETUP
-#line 596 "scan-gram.l"
+#line 609 "scan-gram.l"
 {
     YY_OBS_GROW;
     braces_level--;
@@ -1972,13 +1985,13 @@ YY_RULE_SETUP
 	YY_BREAK
 case 97:
 YY_RULE_SETUP
-#line 609 "scan-gram.l"
+#line 622 "scan-gram.l"
 { handle_dollar (current_braced_code,
 						   yytext, *yylloc); }
 	YY_BREAK
 case 98:
 YY_RULE_SETUP
-#line 611 "scan-gram.l"
+#line 624 "scan-gram.l"
 { handle_at (current_braced_code,
 					       yytext, *yylloc); }
 	YY_BREAK
@@ -1986,13 +1999,13 @@ YY_RULE_SETUP
      than incorrrectly (as `<' `<%').  */
 case 99:
 YY_RULE_SETUP
-#line 616 "scan-gram.l"
+#line 629 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 618 "scan-gram.l"
+#line 631 "scan-gram.l"
 {
-    complain_at (*yylloc, _("unexpected end of file in `{ ... }'"));
+    unexpected_end_of_file (*yylloc, "{", "}");
     yy_pop_state ();
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -2007,7 +2020,7 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 100:
 YY_RULE_SETUP
-#line 635 "scan-gram.l"
+#line 648 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -2017,18 +2030,18 @@ YY_RULE_SETUP
 	YY_BREAK
 case 101:
 YY_RULE_SETUP
-#line 642 "scan-gram.l"
+#line 655 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 102:
 YY_RULE_SETUP
-#line 643 "scan-gram.l"
+#line 656 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 645 "scan-gram.l"
+#line 658 "scan-gram.l"
 {
-    complain_at (*yylloc, _("unexpected end of file in `%%{ ... %%}'"));
+    unexpected_end_of_file (*yylloc, "%{", "%}");
     yy_pop_state ();
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -2044,11 +2057,11 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 103:
 YY_RULE_SETUP
-#line 662 "scan-gram.l"
+#line 675 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 664 "scan-gram.l"
+#line 677 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -2059,10 +2072,10 @@ case YY_STATE_EOF(SC_EPILOGUE):
 
 case 104:
 YY_RULE_SETUP
-#line 673 "scan-gram.l"
+#line 686 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 2066 "scan-gram.c"
+#line 2079 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2954,7 +2967,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 673 "scan-gram.l"
+#line 686 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
@@ -3156,7 +3169,7 @@ convert_ucn_to_byte (char const *ucn)
     /* A non-ASCII host.  Use CODE to index into a table of the C
        basic execution character set, which is guaranteed to exist on
        all Standard C platforms.  This table also includes '$', '@',
-       and '`', which not in the basic execution character set but
+       and '`', which are not in the basic execution character set but
        which are unibyte characters on all the platforms that we know
        about.  */
     static signed char const table[] =
