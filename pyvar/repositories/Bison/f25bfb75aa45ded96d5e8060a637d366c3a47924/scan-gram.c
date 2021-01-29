@@ -697,8 +697,8 @@ static yyconst short int yy_rule_linenum[93] =
       238,  255,  264,  266,  286,  300,  302,  322,  334,  338,
       339,  340,  341,  342,  343,  344,  345,  346,  361,  367,
       368,  370,  388,  394,  395,  397,  415,  418,  421,  422,
-      433,  444,  446,  458,  460,  461,  464,  484,  491,  492,
-      493,  514
+      433,  444,  446,  448,  451,  452,  455,  475,  482,  483,
+      484,  505
 
     } ;
 
@@ -789,13 +789,13 @@ scanner_last_string_free (void)
 }
 
 
-
 static int braces_level = 0;
 static int percent_percent_count = 0;
 
-static void handle_action_dollar PARAMS ((char *cp, location_t location));
-static void handle_destructor_dollar PARAMS ((char *cp, location_t location));
-static void handle_at PARAMS ((char *cp));
+static void handle_dollar PARAMS ((braced_code_t code_kind,
+				   char *cp, location_t location));
+static void handle_at PARAMS ((braced_code_t code_kind,
+			       char *cp, location_t location));
 
 #define SC_COMMENT 1
 
@@ -1705,42 +1705,33 @@ YY_OBS_GROW; braces_level++;
 case 83:
 YY_RULE_SETUP
 #line 446 "scan-gram.l"
-{
-    switch (current_braced_code)
-      {
-      case action_braced_code:
-	handle_action_dollar (yytext, *yylloc);
-	break;
-
-      case destructor_braced_code:
-	handle_destructor_dollar (yytext, *yylloc);
-	break;
-      }
-  }
+{ handle_dollar (current_braced_code,
+						   yytext, *yylloc); }
 	YY_BREAK
 case 84:
 YY_RULE_SETUP
-#line 458 "scan-gram.l"
-{ handle_at (yytext); }
+#line 448 "scan-gram.l"
+{ handle_at (current_braced_code,
+					       yytext, *yylloc); }
 	YY_BREAK
 case 85:
 YY_RULE_SETUP
-#line 460 "scan-gram.l"
+#line 451 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 86:
 YY_RULE_SETUP
-#line 461 "scan-gram.l"
+#line 452 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 /* A lose $, or /, or etc. */
 case 87:
 YY_RULE_SETUP
-#line 464 "scan-gram.l"
+#line 455 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 466 "scan-gram.l"
+#line 457 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a braced code\n");
@@ -1758,7 +1749,7 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 88:
 YY_RULE_SETUP
-#line 484 "scan-gram.l"
+#line 475 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1768,21 +1759,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 89:
 YY_RULE_SETUP
-#line 491 "scan-gram.l"
+#line 482 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 90:
 YY_RULE_SETUP
-#line 492 "scan-gram.l"
+#line 483 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case 91:
 YY_RULE_SETUP
-#line 493 "scan-gram.l"
+#line 484 "scan-gram.l"
 YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 495 "scan-gram.l"
+#line 486 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a prologue\n");
@@ -1801,11 +1792,11 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 92:
 YY_RULE_SETUP
-#line 514 "scan-gram.l"
+#line 505 "scan-gram.l"
 YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 516 "scan-gram.l"
+#line 507 "scan-gram.l"
 {
     yy_pop_state ();
     YY_OBS_FINISH;
@@ -1816,10 +1807,10 @@ case YY_STATE_EOF(SC_EPILOGUE):
 
 case 93:
 YY_RULE_SETUP
-#line 525 "scan-gram.l"
+#line 516 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1823 "lex.yy.c"
+#line 1814 "lex.yy.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2709,7 +2700,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 525 "scan-gram.l"
+#line 516 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
@@ -2720,7 +2711,7 @@ int main()
 | Output to the STRING_OBSTACK a reference to this semantic value.  |
 `------------------------------------------------------------------*/
 
-static void
+static inline void
 handle_action_dollar (char *cp, location_t location)
 {
   const char *type_name = NULL;
@@ -2784,21 +2775,17 @@ handle_action_dollar (char *cp, location_t location)
 }
 
 
-/*---------------------------------------------------------------.
-| CP is pointing to $$ in a destructor.  This should probably be |
-| done once the grammar completely parsed, instead of during its |
-| parsing, since that means %type must be specified before       |
-| %destructor.                                                   |
-`---------------------------------------------------------------*/
+/*---------------------------------------.
+| CP is pointing to $$ in a destructor.  |
+`---------------------------------------*/
 
-static void
+static inline void
 handle_destructor_dollar (char *cp, location_t location)
 {
   ++cp;
   if (*cp == '$')
     {
-      /* FIXME: We should find something more robust.  */
-      obstack_sgrow (&string_obstack, "b4_dollar_dollar");
+      obstack_sgrow (&string_obstack, "]b4_dollar_dollar[");
     }
   else
     {
@@ -2808,32 +2795,55 @@ handle_destructor_dollar (char *cp, location_t location)
     }
 }
 
-/*-------------------------------------------------------.
-| CP is pointing to a location (i.e., a `@').  Output to |
-| STRING_OBSTACK a reference to this location.           |
-`-------------------------------------------------------*/
+
+/*-----------------------------------------------------------------.
+| Dispatch onto handle_action_dollar, or handle_destructor_dollar, |
+| depending upon CODE_KIND.                                        |
+`-----------------------------------------------------------------*/
 
 static void
-handle_at (char *cp)
+handle_dollar (braced_code_t braced_code_kind,
+	       char *text, location_t location)
+{
+  switch (braced_code_kind)
+    {
+    case action_braced_code:
+      handle_action_dollar (text, location);
+      break;
+
+    case destructor_braced_code:
+      handle_destructor_dollar (text, location);
+      break;
+    }
+}
+
+
+/*------------------------------------------------------.
+| TEXT is a location token (i.e., a `@...').  Output to |
+| STRING_OBSTACK a reference to this location.          |
+`------------------------------------------------------*/
+
+static inline void
+handle_action_at (char *text, location_t location)
 {
   locations_flag = 1;
-  ++cp;
+  ++text;
 
-  if (*cp == '$')
+  if (*text == '$')
     {
       obstack_sgrow (&string_obstack, "]b4_lhs_location[");
     }
-  else if (isdigit (*cp) || *cp == '-')
+  else if (isdigit (*text) || *text == '-')
     {
       /* RULE_LENGTH is the number of values in the current rule so
 	 far, which says where to find `$0' with respect to the top of
 	 the stack.  It is not the same as the rule->length in the
 	 case of mid rule actions.  */
       int rule_length = symbol_list_length (current_rule->next);
-      int n = strtol (cp, &cp, 10);
+      int n = strtol (text, &text, 10);
 
       if (n > rule_length)
-	complain (_("invalid value: %s%d"), "@", n);
+	complain_at (location, _("invalid value: %s%d"), "@", n);
       else
 	obstack_fgrow2 (&string_obstack, "]b4_rhs_location([%d], [%d])[",
 			rule_length, n);
@@ -2841,11 +2851,59 @@ handle_at (char *cp)
   else
     {
       char buf[] = "@c";
-      buf[1] = *cp;
-      complain (_("%s is invalid"), quote (buf));
+      buf[1] = *text;
+      complain_at (location, _("%s is invalid"), quote (buf));
+    }
+}
+
+
+/*--------------------------------------------.
+| TEXT is expexted tp be @$ in a destructor.  |
+`--------------------------------------------*/
+
+static inline void
+handle_destructor_at (char *text, location_t location)
+{
+  ++text;
+  if (*text == '$')
+    {
+      obstack_sgrow (&string_obstack, "]b4_at_dollar[");
+    }
+  else
+    {
+      char buf[] = "$c";
+      buf[1] = *text;
+      complain_at (location, _("%s is invalid"), quote (buf));
     }
 }
 
+
+/*-------------------------------------------------------------------.
+| Dispatch onto handle_action_at, or handle_destructor_at, depending |
+| upon CODE_KIND.                                                    |
+`-------------------------------------------------------------------*/
+
+static void
+handle_at (braced_code_t braced_code_kind,
+	   char *text, location_t location)
+{
+  switch (braced_code_kind)
+    {
+    case action_braced_code:
+      handle_action_at (text, location);
+      break;
+
+    case destructor_braced_code:
+      handle_destructor_at (text, location);
+      break;
+    }
+}
+
+
+/*-------------------------.
+| Initialize the scanner.  |
+`-------------------------*/
+
 void
 scanner_initialize (void)
 {
@@ -2853,6 +2911,10 @@ scanner_initialize (void)
 }
 
 
+/*-----------------------------------------------.
+| Free all the memory allocated to the scanner.  |
+`-----------------------------------------------*/
+
 void
 scanner_free (void)
 {
