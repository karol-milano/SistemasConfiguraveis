@@ -42,12 +42,6 @@
 #include <stdlib.h>
 #ifndef _WIN32
 #include <unistd.h>
-#else
-#ifndef YY_ALWAYS_INTERACTIVE
-#ifndef YY_NEVER_INTERACTIVE
-extern int isatty YY_PROTO(( int ));
-#endif
-#endif
 #endif
 
 /* Use prototypes in function declarations. */
@@ -718,13 +712,13 @@ static yyconst short int yy_rule_linenum[102] =
       235,  236,  237,  238,  239,  240,  241,  242,  243,  244,
       245,  246,  247,  248,  250,  251,  252,  253,  254,  256,
       258,  264,  278,  281,  284,  285,  288,  291,  294,  302,
-      308,  324,  325,  335,  340,  356,  357,  373,  374,  386,
-      396,  416,  432,  452,  464,  478,  479,  480,  481,  482,
-      483,  484,  485,  486,  497,  503,  514,  520,  521,  522,
-      524,  542,  548,  549,  550,  552,  570,  573,  576,  577,
-      580,  591,  603,  605,  607,  610,  613,  633,  640,  641,
+      308,  323,  324,  334,  339,  354,  355,  370,  371,  383,
+      393,  412,  428,  447,  458,  471,  472,  473,  474,  475,
+      476,  477,  478,  479,  489,  494,  505,  511,  512,  513,
+      515,  532,  538,  539,  540,  542,  559,  562,  565,  566,
+      569,  580,  592,  594,  596,  599,  602,  621,  628,  629,
 
-      661
+      648
     } ;
 
 /* The intent behind this definition is that it'll catch
@@ -937,7 +931,7 @@ static int convert_ucn_to_byte (char const *hex_text);
    NUL and newline, as this simplifies our implementation.  */
 /* Zero or more instances of backslash-newline.  Following GCC, allow
    white space between the backslash and the newline.  */
-#line 941 "scan-gram.c"
+#line 935 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -1111,7 +1105,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1115 "scan-gram.c"
+#line 1109 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -1429,7 +1423,7 @@ YY_RULE_SETUP
     num = strtoul (yytext, 0, 10);
     if (INT_MAX < num || errno)
       {
-	complain_at (*yylloc, _("%s is invalid"), yytext);
+	complain_at (*yylloc, _("invalid value: %s"), quote (yytext));
 	num = INT_MAX;
       }
     yylval->integer = num;
@@ -1495,8 +1489,7 @@ case 51:
 YY_RULE_SETUP
 #line 308 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": invalid character: `%c'\n"), *yytext);
+    complain_at (*yylloc, _("invalid character: %s"), quote (yytext));
     YY_STEP;
   }
 	YY_BREAK
@@ -1510,12 +1503,12 @@ YY_RULE_SETUP
 
 case 52:
 YY_RULE_SETUP
-#line 324 "scan-gram.l"
+#line 323 "scan-gram.l"
 obstack_sgrow (&string_obstack, "@<:@");
 	YY_BREAK
 case 53:
 YY_RULE_SETUP
-#line 325 "scan-gram.l"
+#line 324 "scan-gram.l"
 obstack_sgrow (&string_obstack, "@:>@");
 	YY_BREAK
 
@@ -1526,7 +1519,7 @@ obstack_sgrow (&string_obstack, "@:>@");
 
 case 54:
 YY_RULE_SETUP
-#line 335 "scan-gram.l"
+#line 334 "scan-gram.l"
 {
     YY_STEP;
     BEGIN INITIAL;
@@ -1534,14 +1527,13 @@ YY_RULE_SETUP
 	YY_BREAK
 case 55:
 YY_RULE_SETUP
-#line 340 "scan-gram.l"
+#line 339 "scan-gram.l"
 ;
 	YY_BREAK
 case YY_STATE_EOF(SC_YACC_COMMENT):
-#line 342 "scan-gram.l"
+#line 341 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": unexpected end of file in a comment\n"));
+    complain_at (*yylloc, _("unexpected end of file in a comment"));
     BEGIN INITIAL;
   }
 	YY_BREAK
@@ -1553,19 +1545,18 @@ case YY_STATE_EOF(SC_YACC_COMMENT):
 
 case 56:
 YY_RULE_SETUP
-#line 356 "scan-gram.l"
+#line 354 "scan-gram.l"
 YY_OBS_GROW; yy_pop_state ();
 	YY_BREAK
 case 57:
 YY_RULE_SETUP
-#line 357 "scan-gram.l"
+#line 355 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_COMMENT):
-#line 359 "scan-gram.l"
+#line 357 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": unexpected end of file in a comment\n"));
+    complain_at (*yylloc, _("unexpected end of file in a comment"));
     yy_pop_state ();
   }
 	YY_BREAK
@@ -1577,16 +1568,16 @@ case YY_STATE_EOF(SC_COMMENT):
 
 case 58:
 YY_RULE_SETUP
-#line 373 "scan-gram.l"
+#line 370 "scan-gram.l"
 YY_OBS_GROW; yy_pop_state ();
 	YY_BREAK
 case 59:
 YY_RULE_SETUP
-#line 374 "scan-gram.l"
+#line 371 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_LINE_COMMENT):
-#line 375 "scan-gram.l"
+#line 372 "scan-gram.l"
 yy_pop_state ();
 	YY_BREAK
 
@@ -1598,7 +1589,7 @@ yy_pop_state ();
 
 case 60:
 YY_RULE_SETUP
-#line 386 "scan-gram.l"
+#line 383 "scan-gram.l"
 {
     assert (yy_top_state () == INITIAL);
     YY_OBS_GROW;
@@ -1611,14 +1602,13 @@ YY_RULE_SETUP
 	YY_BREAK
 case 61:
 YY_RULE_SETUP
-#line 396 "scan-gram.l"
+#line 393 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_STRING):
-#line 398 "scan-gram.l"
+#line 395 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": unexpected end of file in a string\n"));
+    complain_at (*yylloc, _("unexpected end of file in a string"));
     assert (yy_top_state () == INITIAL);
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -1635,7 +1625,7 @@ case YY_STATE_EOF(SC_ESCAPED_STRING):
 
 case 62:
 YY_RULE_SETUP
-#line 416 "scan-gram.l"
+#line 412 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () == INITIAL);
@@ -1654,14 +1644,13 @@ YY_RULE_SETUP
 	YY_BREAK
 case 63:
 YY_RULE_SETUP
-#line 432 "scan-gram.l"
+#line 428 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
-#line 434 "scan-gram.l"
+#line 430 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": unexpected end of file in a character\n"));
+    complain_at (*yylloc, _("unexpected end of file in a character"));
     assert (yy_top_state () == INITIAL);
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -1677,13 +1666,12 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 
 case 64:
 YY_RULE_SETUP
-#line 452 "scan-gram.l"
+#line 447 "scan-gram.l"
 {
     unsigned long c = strtoul (yytext + 1, 0, 8);
     if (UCHAR_MAX < c)
       {
-	LOCATION_PRINT (stderr, *yylloc);
-	fprintf (stderr, _(": invalid escape: %s\n"), quote (yytext));
+	complain_at (*yylloc, _("invalid escape: %s"), quote (yytext));
 	YY_STEP;
       }
     else
@@ -1692,15 +1680,14 @@ YY_RULE_SETUP
 	YY_BREAK
 case 65:
 YY_RULE_SETUP
-#line 464 "scan-gram.l"
+#line 458 "scan-gram.l"
 {
     unsigned long c;
     errno = 0;
     c = strtoul (yytext + 2, 0, 16);
     if (UCHAR_MAX < c || errno)
       {
-	LOCATION_PRINT (stderr, *yylloc);
-	fprintf (stderr, _(": invalid escape: %s\n"), quote (yytext));
+	complain_at (*yylloc, _("invalid escape: %s"), quote (yytext));
 	YY_STEP;
       }
     else
@@ -1709,53 +1696,52 @@ YY_RULE_SETUP
 	YY_BREAK
 case 66:
 YY_RULE_SETUP
-#line 478 "scan-gram.l"
+#line 471 "scan-gram.l"
 obstack_1grow (&string_obstack, '\a');
 	YY_BREAK
 case 67:
 YY_RULE_SETUP
-#line 479 "scan-gram.l"
+#line 472 "scan-gram.l"
 obstack_1grow (&string_obstack, '\b');
 	YY_BREAK
 case 68:
 YY_RULE_SETUP
-#line 480 "scan-gram.l"
+#line 473 "scan-gram.l"
 obstack_1grow (&string_obstack, '\f');
 	YY_BREAK
 case 69:
 YY_RULE_SETUP
-#line 481 "scan-gram.l"
+#line 474 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n');
 	YY_BREAK
 case 70:
 YY_RULE_SETUP
-#line 482 "scan-gram.l"
+#line 475 "scan-gram.l"
 obstack_1grow (&string_obstack, '\r');
 	YY_BREAK
 case 71:
 YY_RULE_SETUP
-#line 483 "scan-gram.l"
+#line 476 "scan-gram.l"
 obstack_1grow (&string_obstack, '\t');
 	YY_BREAK
 case 72:
 YY_RULE_SETUP
-#line 484 "scan-gram.l"
+#line 477 "scan-gram.l"
 obstack_1grow (&string_obstack, '\v');
 	YY_BREAK
 case 73:
 YY_RULE_SETUP
-#line 485 "scan-gram.l"
+#line 478 "scan-gram.l"
 obstack_1grow (&string_obstack, yytext[1]);
 	YY_BREAK
 case 74:
 YY_RULE_SETUP
-#line 486 "scan-gram.l"
+#line 479 "scan-gram.l"
 {
     int c = convert_ucn_to_byte (yytext);
     if (c < 0)
       {
-	LOCATION_PRINT (stderr, *yylloc);
-	fprintf (stderr, _(": invalid escape: %s\n"), quote (yytext));
+	complain_at (*yylloc, _("invalid escape: %s"), quote (yytext));
 	YY_STEP;
       }
     else
@@ -1764,17 +1750,16 @@ YY_RULE_SETUP
 	YY_BREAK
 case 75:
 YY_RULE_SETUP
-#line 497 "scan-gram.l"
+#line 489 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": unrecognized escape: %s\n"), quote (yytext));
+    complain_at (*yylloc, _("unrecognized escape: %s"), quote (yytext));
     YY_OBS_GROW;
   }
 	YY_BREAK
 /* FLex wants this rule, in case of a `\<<EOF>>'. */
 case 76:
 YY_RULE_SETUP
-#line 503 "scan-gram.l"
+#line 494 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1786,7 +1771,7 @@ YY_OBS_GROW;
 
 case 77:
 YY_RULE_SETUP
-#line 514 "scan-gram.l"
+#line 505 "scan-gram.l"
 {
     YY_OBS_GROW;
     assert (yy_top_state () != INITIAL);
@@ -1795,30 +1780,29 @@ YY_RULE_SETUP
 	YY_BREAK
 case 78:
 YY_RULE_SETUP
-#line 520 "scan-gram.l"
+#line 511 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 79:
 YY_RULE_SETUP
-#line 521 "scan-gram.l"
+#line 512 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 80:
 YY_RULE_SETUP
-#line 522 "scan-gram.l"
+#line 513 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* Needed for `\<<EOF>>', `\\<<newline>>[', and `\\<<newline>>]'.  */
 case 81:
 YY_RULE_SETUP
-#line 524 "scan-gram.l"
+#line 515 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_CHARACTER):
-#line 526 "scan-gram.l"
+#line 517 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": unexpected end of file in a character\n"));
+    complain_at (*yylloc, _("unexpected end of file in a character"));
     assert (yy_top_state () != INITIAL);
     yy_pop_state ();
   }
@@ -1832,7 +1816,7 @@ case YY_STATE_EOF(SC_CHARACTER):
 
 case 82:
 YY_RULE_SETUP
-#line 542 "scan-gram.l"
+#line 532 "scan-gram.l"
 {
     assert (yy_top_state () != INITIAL);
     YY_OBS_GROW;
@@ -1841,30 +1825,29 @@ YY_RULE_SETUP
 	YY_BREAK
 case 83:
 YY_RULE_SETUP
-#line 548 "scan-gram.l"
+#line 538 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 84:
 YY_RULE_SETUP
-#line 549 "scan-gram.l"
+#line 539 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 85:
 YY_RULE_SETUP
-#line 550 "scan-gram.l"
+#line 540 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* Needed for `\<<EOF>>', `\\<<newline>>[', and `\\<<newline>>]'.  */
 case 86:
 YY_RULE_SETUP
-#line 552 "scan-gram.l"
+#line 542 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_STRING):
-#line 554 "scan-gram.l"
+#line 544 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": unexpected end of file in a string\n"));
+    complain_at (*yylloc, _("unexpected end of file in a string"));
     assert (yy_top_state () != INITIAL);
     yy_pop_state ();
   }
@@ -1878,30 +1861,30 @@ case YY_STATE_EOF(SC_STRING):
 /* Characters.  We don't check there is only one.  */
 case 87:
 YY_RULE_SETUP
-#line 570 "scan-gram.l"
+#line 559 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 88:
 YY_RULE_SETUP
-#line 573 "scan-gram.l"
+#line 562 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_STRING);
 	YY_BREAK
 /* Comments. */
 case 89:
 YY_RULE_SETUP
-#line 576 "scan-gram.l"
+#line 565 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 90:
 YY_RULE_SETUP
-#line 577 "scan-gram.l"
+#line 566 "scan-gram.l"
 YY_OBS_GROW; yy_push_state (SC_LINE_COMMENT);
 	YY_BREAK
 /* Not comments. */
 case 91:
 YY_RULE_SETUP
-#line 580 "scan-gram.l"
+#line 569 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 
@@ -1913,7 +1896,7 @@ YY_OBS_GROW;
 
 case 92:
 YY_RULE_SETUP
-#line 591 "scan-gram.l"
+#line 580 "scan-gram.l"
 {
     YY_OBS_GROW;
     if (--braces_level == 0)
@@ -1928,37 +1911,36 @@ YY_RULE_SETUP
 	YY_BREAK
 case 93:
 YY_RULE_SETUP
-#line 603 "scan-gram.l"
+#line 592 "scan-gram.l"
 YY_OBS_GROW; braces_level++;
 	YY_BREAK
 case 94:
 YY_RULE_SETUP
-#line 605 "scan-gram.l"
+#line 594 "scan-gram.l"
 { handle_dollar (current_braced_code,
 						   yytext, *yylloc); }
 	YY_BREAK
 case 95:
 YY_RULE_SETUP
-#line 607 "scan-gram.l"
+#line 596 "scan-gram.l"
 { handle_at (current_braced_code,
 					       yytext, *yylloc); }
 	YY_BREAK
 case 96:
 YY_RULE_SETUP
-#line 610 "scan-gram.l"
+#line 599 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 /* A stray $, or /, or etc. */
 case 97:
 YY_RULE_SETUP
-#line 613 "scan-gram.l"
+#line 602 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 615 "scan-gram.l"
+#line 604 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": unexpected end of file in a braced code\n"));
+    complain_at (*yylloc, _("unexpected end of file in a braced code"));
     yy_pop_state ();
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -1973,7 +1955,7 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 98:
 YY_RULE_SETUP
-#line 633 "scan-gram.l"
+#line 621 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1983,19 +1965,18 @@ YY_RULE_SETUP
 	YY_BREAK
 case 99:
 YY_RULE_SETUP
-#line 640 "scan-gram.l"
+#line 628 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 100:
 YY_RULE_SETUP
-#line 641 "scan-gram.l"
+#line 629 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 643 "scan-gram.l"
+#line 631 "scan-gram.l"
 {
-    LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, _(": unexpected end of file in a prologue\n"));
+    complain_at (*yylloc, _("unexpected end of file in a prologue"));
     yy_pop_state ();
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -2011,11 +1992,11 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 101:
 YY_RULE_SETUP
-#line 661 "scan-gram.l"
+#line 648 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 663 "scan-gram.l"
+#line 650 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -2026,10 +2007,10 @@ case YY_STATE_EOF(SC_EPILOGUE):
 
 case 102:
 YY_RULE_SETUP
-#line 672 "scan-gram.l"
+#line 659 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 2033 "scan-gram.c"
+#line 2014 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2919,7 +2900,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 672 "scan-gram.l"
+#line 659 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
@@ -2980,7 +2961,7 @@ handle_action_dollar (char *text, location_t location)
 			  rule_length, n, type_name);
 	}
       else
-	complain_at (location, _("invalid value: %s"), text);
+	complain_at (location, _("invalid value: %s"), quote (text));
     }
 }
 
@@ -2997,7 +2978,7 @@ handle_symbol_code_dollar (char *text, location_t location)
   if (*cp == '$')
     obstack_sgrow (&string_obstack, "]b4_dollar_dollar[");
   else
-    complain_at (location, _("%s is invalid"), quote_n (1, text));
+    complain_at (location, _("invalid value: %s"), quote (text));
 }
 
 
@@ -3052,7 +3033,7 @@ handle_action_at (char *text, location_t location)
 			  rule_length, n);
 	}
       else
-	complain_at (location, _("invalid value: %s"), text);
+	complain_at (location, _("invalid value: %s"), quote (text));
     }
 }
 
@@ -3069,7 +3050,7 @@ handle_symbol_code_at (char *text, location_t location)
   if (*cp == '$')
     obstack_sgrow (&string_obstack, "]b4_at_dollar[");
   else
-    complain_at (location, _("%s is invalid"), quote_n (1, text));
+    complain_at (location, _("invalid value: %s"), quote (text));
 }
 
 
@@ -3147,7 +3128,7 @@ convert_ucn_to_byte (char const *ucn)
     code = code < sizeof table ? table[code] : -1;
   }
 #endif
-      
+
   return code;
 }
 
