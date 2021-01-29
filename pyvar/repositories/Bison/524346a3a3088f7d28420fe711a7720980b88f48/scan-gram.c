@@ -710,11 +710,11 @@ static yyconst short int yy_rule_linenum[101] =
       142,  143,  144,  145,  146,  147,  148,  149,  150,  151,
       152,  153,  155,  156,  157,  158,  160,  161,  162,  167,
       170,  173,  176,  177,  180,  183,  186,  194,  200,  216,
-      217,  228,  240,  241,  242,  259,  268,  270,  290,  304,
-      306,  326,  338,  342,  343,  344,  345,  346,  347,  348,
-      349,  350,  356,  367,  373,  374,  376,  378,  396,  402,
-      403,  405,  407,  425,  428,  431,  432,  435,  446,  457,
-      459,  461,  464,  465,  468,  488,  495,  496,  497,  517
+      217,  228,  240,  241,  242,  259,  268,  270,  290,  305,
+      307,  327,  339,  343,  344,  345,  346,  347,  348,  349,
+      350,  351,  357,  368,  374,  375,  377,  379,  397,  403,
+      404,  406,  408,  426,  429,  432,  433,  436,  447,  458,
+      460,  462,  465,  466,  469,  489,  496,  497,  498,  518
 
     } ;
 
@@ -1497,7 +1497,8 @@ YY_RULE_SETUP
       YY_OBS_FINISH;
       yylval->symbol = symbol_get (last_string, *yylloc);
       symbol_class_set (yylval->symbol, token_sym, *yylloc);
-      symbol_user_token_number_set (yylval->symbol, last_string[1], *yylloc);
+      symbol_user_token_number_set (yylval->symbol,
+				    (unsigned char) last_string[1], *yylloc);
       YY_OBS_FREE;
       yy_pop_state ();
       return ID;
@@ -1506,16 +1507,16 @@ YY_RULE_SETUP
 	YY_BREAK
 case 60:
 YY_RULE_SETUP
-#line 304 "scan-gram.l"
+#line 305 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 61:
 YY_RULE_SETUP
-#line 306 "scan-gram.l"
+#line 307 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
-#line 308 "scan-gram.l"
+#line 309 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
@@ -1534,7 +1535,7 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 
 case 62:
 YY_RULE_SETUP
-#line 326 "scan-gram.l"
+#line 327 "scan-gram.l"
 {
     long c = strtol (yytext + 1, 0, 8);
     if (c > 255)
@@ -1549,54 +1550,54 @@ YY_RULE_SETUP
 	YY_BREAK
 case 63:
 YY_RULE_SETUP
-#line 338 "scan-gram.l"
+#line 339 "scan-gram.l"
 {
     obstack_1grow (&string_obstack, strtol (yytext + 2, 0, 16));
   }
 	YY_BREAK
 case 64:
 YY_RULE_SETUP
-#line 342 "scan-gram.l"
+#line 343 "scan-gram.l"
 obstack_1grow (&string_obstack, '\a');
 	YY_BREAK
 case 65:
 YY_RULE_SETUP
-#line 343 "scan-gram.l"
+#line 344 "scan-gram.l"
 obstack_1grow (&string_obstack, '\b');
 	YY_BREAK
 case 66:
 YY_RULE_SETUP
-#line 344 "scan-gram.l"
+#line 345 "scan-gram.l"
 obstack_1grow (&string_obstack, '\f');
 	YY_BREAK
 case 67:
 YY_RULE_SETUP
-#line 345 "scan-gram.l"
+#line 346 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n');
 	YY_BREAK
 case 68:
 YY_RULE_SETUP
-#line 346 "scan-gram.l"
+#line 347 "scan-gram.l"
 obstack_1grow (&string_obstack, '\r');
 	YY_BREAK
 case 69:
 YY_RULE_SETUP
-#line 347 "scan-gram.l"
+#line 348 "scan-gram.l"
 obstack_1grow (&string_obstack, '\t');
 	YY_BREAK
 case 70:
 YY_RULE_SETUP
-#line 348 "scan-gram.l"
+#line 349 "scan-gram.l"
 obstack_1grow (&string_obstack, '\v');
 	YY_BREAK
 case 71:
 YY_RULE_SETUP
-#line 349 "scan-gram.l"
+#line 350 "scan-gram.l"
 obstack_1grow (&string_obstack, yytext[1]);
 	YY_BREAK
 case 72:
 YY_RULE_SETUP
-#line 350 "scan-gram.l"
+#line 351 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unrecognized escape: %s\n", quote (yytext));
@@ -1606,7 +1607,7 @@ YY_RULE_SETUP
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 73:
 YY_RULE_SETUP
-#line 356 "scan-gram.l"
+#line 357 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1618,7 +1619,7 @@ YY_OBS_GROW;
 
 case 74:
 YY_RULE_SETUP
-#line 367 "scan-gram.l"
+#line 368 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () != INITIAL);
@@ -1627,27 +1628,27 @@ YY_RULE_SETUP
 	YY_BREAK
 case 75:
 YY_RULE_SETUP
-#line 373 "scan-gram.l"
+#line 374 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 76:
 YY_RULE_SETUP
-#line 374 "scan-gram.l"
+#line 375 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 77:
 YY_RULE_SETUP
-#line 376 "scan-gram.l"
+#line 377 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 78:
 YY_RULE_SETUP
-#line 378 "scan-gram.l"
+#line 379 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_CHARACTER):
-#line 380 "scan-gram.l"
+#line 381 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
@@ -1664,7 +1665,7 @@ case YY_STATE_EOF(SC_CHARACTER):
 
 case 79:
 YY_RULE_SETUP
-#line 396 "scan-gram.l"
+#line 397 "scan-gram.l"
 {
     assert (yy_top_state () != INITIAL);
     YY_OBS_GROW;
@@ -1673,27 +1674,27 @@ YY_RULE_SETUP
 	YY_BREAK
 case 80:
 YY_RULE_SETUP
-#line 402 "scan-gram.l"
+#line 403 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 81:
 YY_RULE_SETUP
-#line 403 "scan-gram.l"
+#line 404 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 82:
 YY_RULE_SETUP
-#line 405 "scan-gram.l"
+#line 406 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 83:
 YY_RULE_SETUP
-#line 407 "scan-gram.l"
+#line 408 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_STRING):
-#line 409 "scan-gram.l"
+#line 410 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a string\n");
@@ -1710,30 +1711,30 @@ case YY_STATE_EOF(SC_STRING):
 /* Characters.  We don't check there is only one.  */
 case 84:
 YY_RULE_SETUP
-#line 425 "scan-gram.l"
+#line 426 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 85:
 YY_RULE_SETUP
-#line 428 "scan-gram.l"
+#line 429 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_STRING);
 	YY_BREAK
 /* Comments. */
 case 86:
 YY_RULE_SETUP
-#line 431 "scan-gram.l"
+#line 432 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 87:
 YY_RULE_SETUP
-#line 432 "scan-gram.l"
+#line 433 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* Not comments. */
 case 88:
 YY_RULE_SETUP
-#line 435 "scan-gram.l"
+#line 436 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1745,7 +1746,7 @@ YY_OBS_GROW;
 
 case 89:
 YY_RULE_SETUP
-#line 446 "scan-gram.l"
+#line 447 "scan-gram.l"
 {
     YY_OBS_GROW;
     if (--braces_level == 0)
@@ -1759,39 +1760,39 @@ YY_RULE_SETUP
 	YY_BREAK
 case 90:
 YY_RULE_SETUP
-#line 457 "scan-gram.l"
+#line 458 "scan-gram.l"
 YY_OBS_GROW; braces_level++;
 	YY_BREAK
 case 91:
 YY_RULE_SETUP
-#line 459 "scan-gram.l"
+#line 460 "scan-gram.l"
 { handle_dollar (current_braced_code,
 						   yytext, *yylloc); }
 	YY_BREAK
 case 92:
 YY_RULE_SETUP
-#line 461 "scan-gram.l"
+#line 462 "scan-gram.l"
 { handle_at (current_braced_code,
 					       yytext, *yylloc); }
 	YY_BREAK
 case 93:
 YY_RULE_SETUP
-#line 464 "scan-gram.l"
+#line 465 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 94:
 YY_RULE_SETUP
-#line 465 "scan-gram.l"
+#line 466 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 /* A lose $, or /, or etc. */
 case 95:
 YY_RULE_SETUP
-#line 468 "scan-gram.l"
+#line 469 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 470 "scan-gram.l"
+#line 471 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a braced code\n");
@@ -1809,7 +1810,7 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 96:
 YY_RULE_SETUP
-#line 488 "scan-gram.l"
+#line 489 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1819,21 +1820,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 97:
 YY_RULE_SETUP
-#line 495 "scan-gram.l"
+#line 496 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 98:
 YY_RULE_SETUP
-#line 496 "scan-gram.l"
+#line 497 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 99:
 YY_RULE_SETUP
-#line 497 "scan-gram.l"
+#line 498 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 499 "scan-gram.l"
+#line 500 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a prologue\n");
@@ -1852,11 +1853,11 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 100:
 YY_RULE_SETUP
-#line 517 "scan-gram.l"
+#line 518 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 519 "scan-gram.l"
+#line 520 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1867,10 +1868,10 @@ case YY_STATE_EOF(SC_EPILOGUE):
 
 case 101:
 YY_RULE_SETUP
-#line 528 "scan-gram.l"
+#line 529 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1874 "lex.yy.c"
+#line 1875 "lex.yy.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2760,7 +2761,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 528 "scan-gram.l"
+#line 529 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
