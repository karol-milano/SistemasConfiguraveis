@@ -689,16 +689,16 @@ int yy_flex_debug = 1;
 
 static yyconst short int yy_rule_linenum[92] =
     {   0,
-      115,  116,  117,  118,  119,  120,  121,  122,  123,  124,
-      125,  126,  127,  128,  129,  130,  131,  132,  133,  134,
-      135,  136,  137,  138,  139,  140,  141,  143,  144,  145,
-      146,  148,  149,  150,  157,  160,  163,  166,  167,  170,
-      173,  176,  178,  184,  200,  201,  212,  224,  225,  226,
-      243,  251,  253,  272,  286,  288,  307,  319,  323,  324,
-      325,  326,  327,  328,  329,  330,  331,  346,  352,  353,
-      355,  373,  379,  380,  382,  400,  403,  406,  407,  418,
-      428,  430,  431,  433,  434,  437,  456,  462,  463,  464,
-      484
+      121,  122,  123,  124,  125,  126,  127,  128,  129,  130,
+      131,  132,  133,  134,  135,  136,  137,  138,  139,  140,
+      141,  142,  143,  144,  145,  146,  147,  149,  150,  151,
+      152,  154,  155,  156,  161,  164,  167,  170,  171,  174,
+      177,  180,  189,  195,  211,  212,  223,  235,  236,  237,
+      254,  263,  265,  285,  299,  301,  321,  333,  337,  338,
+      339,  340,  341,  342,  343,  344,  345,  360,  366,  367,
+      369,  387,  393,  394,  396,  414,  417,  420,  421,  432,
+      443,  445,  446,  448,  449,  452,  472,  479,  480,  481,
+      502
 
     } ;
 
@@ -772,7 +772,6 @@ char *last_string;
   do {							\
     obstack_1grow (&string_obstack, '\0');		\
     last_string = obstack_finish (&string_obstack);	\
-    yylval->string = last_string;			\
   } while (0)
 
 #define YY_OBS_FREE						\
@@ -780,6 +779,13 @@ char *last_string;
     obstack_free (&string_obstack, last_string);		\
   } while (0)
 
+void
+scanner_last_string_free (void)
+{
+  YY_OBS_FREE;
+}
+
+
 /* This is only to avoid GCC warnings. */
 #define YY_USER_INIT    if (yycontrol) {;};
 
@@ -802,7 +808,7 @@ static void handle_at PARAMS ((char *cp));
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 806 "scan-gram.c"
+#line 812 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -964,7 +970,7 @@ YY_DECL
 	register char *yy_cp, *yy_bp;
 	register int yy_act;
 
-#line 91 "scan-gram.l"
+#line 97 "scan-gram.l"
 
 
   /* At each yylex invocation, mark the current position as the
@@ -987,7 +993,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 991 "scan-gram.c"
+#line 997 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -1089,228 +1095,232 @@ do_action:	/* This label is used only to access EOF actions. */
 
 case 1:
 YY_RULE_SETUP
-#line 115 "scan-gram.l"
+#line 121 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 2:
 YY_RULE_SETUP
-#line 116 "scan-gram.l"
+#line 122 "scan-gram.l"
 return PERCENT_DEBUG;
 	YY_BREAK
 case 3:
 YY_RULE_SETUP
-#line 117 "scan-gram.l"
+#line 123 "scan-gram.l"
 return PERCENT_DEFINE;
 	YY_BREAK
 case 4:
 YY_RULE_SETUP
-#line 118 "scan-gram.l"
+#line 124 "scan-gram.l"
 return PERCENT_DEFINES;
 	YY_BREAK
 case 5:
 YY_RULE_SETUP
-#line 119 "scan-gram.l"
+#line 125 "scan-gram.l"
 return PERCENT_ERROR_VERBOSE;
 	YY_BREAK
 case 6:
 YY_RULE_SETUP
-#line 120 "scan-gram.l"
+#line 126 "scan-gram.l"
 return PERCENT_EXPECT;
 	YY_BREAK
 case 7:
 YY_RULE_SETUP
-#line 121 "scan-gram.l"
+#line 127 "scan-gram.l"
 return PERCENT_FILE_PREFIX;
 	YY_BREAK
 case 8:
 YY_RULE_SETUP
-#line 122 "scan-gram.l"
+#line 128 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 9:
 YY_RULE_SETUP
-#line 123 "scan-gram.l"
+#line 129 "scan-gram.l"
 return PERCENT_LEFT;
 	YY_BREAK
 case 10:
 YY_RULE_SETUP
-#line 124 "scan-gram.l"
+#line 130 "scan-gram.l"
 return PERCENT_LOCATIONS;
 	YY_BREAK
 case 11:
 YY_RULE_SETUP
-#line 125 "scan-gram.l"
+#line 131 "scan-gram.l"
 return PERCENT_NAME_PREFIX;
 	YY_BREAK
 case 12:
 YY_RULE_SETUP
-#line 126 "scan-gram.l"
+#line 132 "scan-gram.l"
 return PERCENT_NO_LINES;
 	YY_BREAK
 case 13:
 YY_RULE_SETUP
-#line 127 "scan-gram.l"
+#line 133 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 14:
 YY_RULE_SETUP
-#line 128 "scan-gram.l"
+#line 134 "scan-gram.l"
 return PERCENT_NTERM;
 	YY_BREAK
 case 15:
 YY_RULE_SETUP
-#line 129 "scan-gram.l"
+#line 135 "scan-gram.l"
 return PERCENT_OUTPUT;
 	YY_BREAK
 case 16:
 YY_RULE_SETUP
-#line 130 "scan-gram.l"
+#line 136 "scan-gram.l"
 return PERCENT_PREC;
 	YY_BREAK
 case 17:
 YY_RULE_SETUP
-#line 131 "scan-gram.l"
+#line 137 "scan-gram.l"
 return PERCENT_PURE_PARSER;
 	YY_BREAK
 case 18:
 YY_RULE_SETUP
-#line 132 "scan-gram.l"
+#line 138 "scan-gram.l"
 return PERCENT_RIGHT;
 	YY_BREAK
 case 19:
 YY_RULE_SETUP
-#line 133 "scan-gram.l"
+#line 139 "scan-gram.l"
 return PERCENT_SKELETON;
 	YY_BREAK
 case 20:
 YY_RULE_SETUP
-#line 134 "scan-gram.l"
+#line 140 "scan-gram.l"
 return PERCENT_START;
 	YY_BREAK
 case 21:
 YY_RULE_SETUP
-#line 135 "scan-gram.l"
+#line 141 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 22:
 YY_RULE_SETUP
-#line 136 "scan-gram.l"
+#line 142 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 23:
 YY_RULE_SETUP
-#line 137 "scan-gram.l"
+#line 143 "scan-gram.l"
 return PERCENT_TOKEN_TABLE;
 	YY_BREAK
 case 24:
 YY_RULE_SETUP
-#line 138 "scan-gram.l"
+#line 144 "scan-gram.l"
 return PERCENT_TYPE;
 	YY_BREAK
 case 25:
 YY_RULE_SETUP
-#line 139 "scan-gram.l"
+#line 145 "scan-gram.l"
 return PERCENT_UNION;
 	YY_BREAK
 case 26:
 YY_RULE_SETUP
-#line 140 "scan-gram.l"
+#line 146 "scan-gram.l"
 return PERCENT_VERBOSE;
 	YY_BREAK
 case 27:
 YY_RULE_SETUP
-#line 141 "scan-gram.l"
+#line 147 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 28:
 YY_RULE_SETUP
-#line 143 "scan-gram.l"
+#line 149 "scan-gram.l"
 return EQUAL;
 	YY_BREAK
 case 29:
 YY_RULE_SETUP
-#line 144 "scan-gram.l"
+#line 150 "scan-gram.l"
 return COLON;
 	YY_BREAK
 case 30:
 YY_RULE_SETUP
-#line 145 "scan-gram.l"
+#line 151 "scan-gram.l"
 return PIPE;
 	YY_BREAK
 case 31:
 YY_RULE_SETUP
-#line 146 "scan-gram.l"
+#line 152 "scan-gram.l"
 return SEMICOLON;
 	YY_BREAK
 case 32:
 YY_RULE_SETUP
-#line 148 "scan-gram.l"
+#line 154 "scan-gram.l"
 YY_LINES; YY_STEP;
 	YY_BREAK
 case 33:
 YY_RULE_SETUP
-#line 149 "scan-gram.l"
+#line 155 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 case 34:
 YY_RULE_SETUP
-#line 150 "scan-gram.l"
+#line 156 "scan-gram.l"
 {
-    YY_OBS_INIT; YY_OBS_GROW; YY_OBS_FINISH;
-    yylval->symbol = getsym (last_string);
-    YY_OBS_FREE;
+    yylval->symbol = getsym (yytext);
     return ID;
   }
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
 YY_OBS_INIT; YY_OBS_GROW; yy_push_state (SC_ESCAPED_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 37:
 YY_RULE_SETUP
-#line 163 "scan-gram.l"
+#line 167 "scan-gram.l"
 YY_OBS_INIT; YY_OBS_GROW; yy_push_state (SC_ESCAPED_STRING);
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
 YY_OBS_INIT; yy_push_state (SC_PROLOGUE);
 	YY_BREAK
 /* Code in between braces.  */
 case 41:
 YY_RULE_SETUP
-#line 173 "scan-gram.l"
+#line 177 "scan-gram.l"
 YY_OBS_INIT; YY_OBS_GROW; ++braces_level; yy_push_state (SC_BRACED_CODE);
 	YY_BREAK
 /* A type. */
 case 42:
 YY_RULE_SETUP
-#line 176 "scan-gram.l"
-YY_OBS_INIT; obstack_grow (&string_obstack, yytext + 1, yyleng - 2); YY_OBS_FINISH; return TYPE;
+#line 180 "scan-gram.l"
+{
+    YY_OBS_INIT;
+    obstack_grow (&string_obstack, yytext + 1, yyleng - 2);
+    YY_OBS_FINISH;
+    yylval->string = last_string;
+    return TYPE;
+  }
 	YY_BREAK
 case 43:
 YY_RULE_SETUP
-#line 178 "scan-gram.l"
+#line 189 "scan-gram.l"
 {
     if (++percent_percent_count == 2)
       yy_push_state (SC_EPILOGUE);
@@ -1319,7 +1329,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 44:
 YY_RULE_SETUP
-#line 184 "scan-gram.l"
+#line 195 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": invalid character: `%c'\n", *yytext);
@@ -1336,12 +1346,12 @@ YY_RULE_SETUP
 
 case 45:
 YY_RULE_SETUP
-#line 200 "scan-gram.l"
+#line 211 "scan-gram.l"
 obstack_sgrow (&string_obstack, "@<:@");
 	YY_BREAK
 case 46:
 YY_RULE_SETUP
-#line 201 "scan-gram.l"
+#line 212 "scan-gram.l"
 obstack_sgrow (&string_obstack, "@:>@");
 	YY_BREAK
 
@@ -1352,7 +1362,7 @@ obstack_sgrow (&string_obstack, "@:>@");
 
 case 47:
 YY_RULE_SETUP
-#line 212 "scan-gram.l"
+#line 223 "scan-gram.l"
 { /* End of the comment. */
     if (yy_top_state () == INITIAL)
       {
@@ -1367,21 +1377,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 48:
 YY_RULE_SETUP
-#line 224 "scan-gram.l"
+#line 235 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case 49:
 YY_RULE_SETUP
-#line 225 "scan-gram.l"
+#line 236 "scan-gram.l"
 if (yy_top_state () != INITIAL) YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case 50:
 YY_RULE_SETUP
-#line 226 "scan-gram.l"
+#line 237 "scan-gram.l"
 /* Stray `*'. */if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_COMMENT):
-#line 228 "scan-gram.l"
+#line 239 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a comment\n");
@@ -1397,32 +1407,34 @@ case YY_STATE_EOF(SC_COMMENT):
 
 case 51:
 YY_RULE_SETUP
-#line 243 "scan-gram.l"
+#line 254 "scan-gram.l"
 {
     assert (yy_top_state () == INITIAL);
     YY_OBS_GROW;
     YY_OBS_FINISH;
+    yylval->string = last_string;
     yy_pop_state ();
     return STRING;
   }
 	YY_BREAK
 case 52:
 YY_RULE_SETUP
-#line 251 "scan-gram.l"
+#line 263 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 53:
 YY_RULE_SETUP
-#line 253 "scan-gram.l"
+#line 265 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_STRING):
-#line 255 "scan-gram.l"
+#line 267 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a string\n");
     assert (yy_top_state () == INITIAL);
     YY_OBS_FINISH;
+    yylval->string = last_string;
     yy_pop_state ();
     return STRING;
   }
@@ -1436,7 +1448,7 @@ case YY_STATE_EOF(SC_ESCAPED_STRING):
 
 case 54:
 YY_RULE_SETUP
-#line 272 "scan-gram.l"
+#line 285 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () == INITIAL);
@@ -1453,21 +1465,22 @@ YY_RULE_SETUP
 	YY_BREAK
 case 55:
 YY_RULE_SETUP
-#line 286 "scan-gram.l"
+#line 299 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 56:
 YY_RULE_SETUP
-#line 288 "scan-gram.l"
+#line 301 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
-#line 290 "scan-gram.l"
+#line 303 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
     assert (yy_top_state () == INITIAL);
     YY_OBS_FINISH;
+    yylval->string = last_string;
     yy_pop_state ();
     return CHARACTER;
   }
@@ -1480,7 +1493,7 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 
 case 57:
 YY_RULE_SETUP
-#line 307 "scan-gram.l"
+#line 321 "scan-gram.l"
 {
     long c = strtol (yytext + 1, 0, 8);
     if (c > 255)
@@ -1495,54 +1508,54 @@ YY_RULE_SETUP
 	YY_BREAK
 case 58:
 YY_RULE_SETUP
-#line 319 "scan-gram.l"
+#line 333 "scan-gram.l"
 {
     obstack_1grow (&string_obstack, strtol (yytext + 2, 0, 16));
   }
 	YY_BREAK
 case 59:
 YY_RULE_SETUP
-#line 323 "scan-gram.l"
+#line 337 "scan-gram.l"
 obstack_1grow (&string_obstack, '\a');
 	YY_BREAK
 case 60:
 YY_RULE_SETUP
-#line 324 "scan-gram.l"
+#line 338 "scan-gram.l"
 obstack_1grow (&string_obstack, '\b');
 	YY_BREAK
 case 61:
 YY_RULE_SETUP
-#line 325 "scan-gram.l"
+#line 339 "scan-gram.l"
 obstack_1grow (&string_obstack, '\f');
 	YY_BREAK
 case 62:
 YY_RULE_SETUP
-#line 326 "scan-gram.l"
+#line 340 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n');
 	YY_BREAK
 case 63:
 YY_RULE_SETUP
-#line 327 "scan-gram.l"
+#line 341 "scan-gram.l"
 obstack_1grow (&string_obstack, '\r');
 	YY_BREAK
 case 64:
 YY_RULE_SETUP
-#line 328 "scan-gram.l"
+#line 342 "scan-gram.l"
 obstack_1grow (&string_obstack, '\t');
 	YY_BREAK
 case 65:
 YY_RULE_SETUP
-#line 329 "scan-gram.l"
+#line 343 "scan-gram.l"
 obstack_1grow (&string_obstack, '\v');
 	YY_BREAK
 case 66:
 YY_RULE_SETUP
-#line 330 "scan-gram.l"
+#line 344 "scan-gram.l"
 obstack_1grow (&string_obstack, yytext[1]);
 	YY_BREAK
 case 67:
 YY_RULE_SETUP
-#line 331 "scan-gram.l"
+#line 345 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unrecognized escape: %s\n", yytext);
@@ -1558,7 +1571,7 @@ YY_RULE_SETUP
 
 case 68:
 YY_RULE_SETUP
-#line 346 "scan-gram.l"
+#line 360 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () != INITIAL);
@@ -1567,21 +1580,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 69:
 YY_RULE_SETUP
-#line 352 "scan-gram.l"
+#line 366 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 70:
 YY_RULE_SETUP
-#line 353 "scan-gram.l"
+#line 367 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 71:
 YY_RULE_SETUP
-#line 355 "scan-gram.l"
+#line 369 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_CHARACTER):
-#line 357 "scan-gram.l"
+#line 371 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
@@ -1598,7 +1611,7 @@ case YY_STATE_EOF(SC_CHARACTER):
 
 case 72:
 YY_RULE_SETUP
-#line 373 "scan-gram.l"
+#line 387 "scan-gram.l"
 {
     assert (yy_top_state () != INITIAL);
     YY_OBS_GROW;
@@ -1607,21 +1620,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 73:
 YY_RULE_SETUP
-#line 379 "scan-gram.l"
+#line 393 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 74:
 YY_RULE_SETUP
-#line 380 "scan-gram.l"
+#line 394 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 75:
 YY_RULE_SETUP
-#line 382 "scan-gram.l"
+#line 396 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_STRING):
-#line 384 "scan-gram.l"
+#line 398 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a string\n");
@@ -1638,24 +1651,24 @@ case YY_STATE_EOF(SC_STRING):
 /* Characters.  We don't check there is only one.  */
 case 76:
 YY_RULE_SETUP
-#line 400 "scan-gram.l"
+#line 414 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 77:
 YY_RULE_SETUP
-#line 403 "scan-gram.l"
+#line 417 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_STRING);
 	YY_BREAK
 /* Comments. */
 case 78:
 YY_RULE_SETUP
-#line 406 "scan-gram.l"
+#line 420 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 79:
 YY_RULE_SETUP
-#line 407 "scan-gram.l"
+#line 421 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1667,56 +1680,58 @@ YY_OBS_GROW;
 
 case 80:
 YY_RULE_SETUP
-#line 418 "scan-gram.l"
+#line 432 "scan-gram.l"
 {
     YY_OBS_GROW;
     if (--braces_level == 0)
       {
 	yy_pop_state ();
 	YY_OBS_FINISH;
+	yylval->string = last_string;
 	return BRACED_CODE;
       }
   }
 	YY_BREAK
 case 81:
 YY_RULE_SETUP
-#line 428 "scan-gram.l"
+#line 443 "scan-gram.l"
 YY_OBS_GROW; braces_level++;
 	YY_BREAK
 case 82:
 YY_RULE_SETUP
-#line 430 "scan-gram.l"
+#line 445 "scan-gram.l"
 { handle_dollar (yytext); }
 	YY_BREAK
 case 83:
 YY_RULE_SETUP
-#line 431 "scan-gram.l"
+#line 446 "scan-gram.l"
 { handle_at (yytext); }
 	YY_BREAK
 case 84:
 YY_RULE_SETUP
-#line 433 "scan-gram.l"
+#line 448 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 85:
 YY_RULE_SETUP
-#line 434 "scan-gram.l"
+#line 449 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 /* A lose $, or /, or etc. */
 case 86:
 YY_RULE_SETUP
-#line 437 "scan-gram.l"
+#line 452 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 439 "scan-gram.l"
+#line 454 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a braced code\n");
     yy_pop_state ();
     YY_OBS_FINISH;
-    return PROLOGUE;
+    yylval->string = last_string;
+    return BRACED_CODE;
   }
 	YY_BREAK
 
@@ -1727,35 +1742,37 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 87:
 YY_RULE_SETUP
-#line 456 "scan-gram.l"
+#line 472 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
+    yylval->string = last_string;
     return PROLOGUE;
   }
 	YY_BREAK
 case 88:
 YY_RULE_SETUP
-#line 462 "scan-gram.l"
+#line 479 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 89:
 YY_RULE_SETUP
-#line 463 "scan-gram.l"
+#line 480 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 90:
 YY_RULE_SETUP
-#line 464 "scan-gram.l"
+#line 481 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 466 "scan-gram.l"
+#line 483 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a prologue\n");
     yy_pop_state ();
     YY_OBS_FINISH;
+    yylval->string = last_string;
     return PROLOGUE;
   }
 	YY_BREAK
@@ -1768,24 +1785,25 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 91:
 YY_RULE_SETUP
-#line 484 "scan-gram.l"
+#line 502 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 486 "scan-gram.l"
+#line 504 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
+    yylval->string = last_string;
     return EPILOGUE;
   }
 	YY_BREAK
 
 case 92:
 YY_RULE_SETUP
-#line 494 "scan-gram.l"
+#line 513 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1789 "scan-gram.c"
+#line 1807 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2675,7 +2693,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 494 "scan-gram.l"
+#line 513 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
@@ -2792,3 +2810,9 @@ handle_at (char *cp)
       complain (_("%s is invalid"), quote (buf));
     }
 }
+
+void
+scanner_free (void)
+{
+  obstack_free (&string_obstack, 0);
+}
