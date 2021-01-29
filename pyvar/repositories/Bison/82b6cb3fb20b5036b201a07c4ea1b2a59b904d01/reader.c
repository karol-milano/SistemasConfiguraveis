@@ -492,23 +492,22 @@ copy_comment (FILE *fin, struct obstack *oout)
 }
 
 
-/*-----------------------------------------------------------------.
-| FIN is pointing to a location (i.e., a `@').  Output to OOUT a   |
-| reference to this location. STACK_OFFSET is the number of values |
-| in the current rule so far, which says where to find `$0' with   |
-| respect to the top of the stack.                                 |
-`-----------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| FIN is pointing to a location (i.e., a `@').  Output to OOUT a     |
+| reference to this location. RULE_LENGTH is the number of values in |
+| the current rule so far, which says where to find `$0' with        |
+| respect to the top of the stack.                                   |
+`-------------------------------------------------------------------*/
 
 static inline void
-copy_at (FILE *fin, struct obstack *oout, int stack_offset)
+copy_at (FILE *fin, struct obstack *oout, int rule_length)
 {
-  int c;
+  int c = getc (fin);
+  locations_flag = 1;
 
-  c = getc (fin);
   if (c == '$')
     {
-      obstack_sgrow (oout, "yyloc");
-      locations_flag = 1;
+      obstack_sgrow (oout, "]b4_lhs_location[");
     }
   else if (isdigit (c) || c == '-')
     {
@@ -516,16 +515,11 @@ copy_at (FILE *fin, struct obstack *oout, int stack_offset)
 
       ungetc (c, fin);
       n = read_signed_integer (fin);
-      if (n > stack_offset)
+      if (n > rule_length)
 	complain (_("invalid value: %s%d"), "@", n);
       else
-	{
-	  /* Offset is always 0 if parser has already popped the stack
-	     pointer.  */
-	  obstack_fgrow1 (oout, "yylsp[%d]",
-			  n - (semantic_parser ? 0 : stack_offset));
-	  locations_flag = 1;
-	}
+	obstack_fgrow2 (oout, "]b4_rhs_location([%d], [%d])[",
+			rule_length, n);
     }
   else
     {
@@ -536,19 +530,19 @@ copy_at (FILE *fin, struct obstack *oout, int stack_offset)
 }
 
 
-/*-------------------------------------------------------------------.
-| FIN is pointing to a wannabee semantic value (i.e., a `$').        |
-|                                                                    |
-| Possible inputs: $[<TYPENAME>]($|integer)                          |
-|                                                                    |
-| Output to OOUT a reference to this semantic value. STACK_OFFSET is |
-| the number of values in the current rule so far, which says where  |
-| to find `$0' with respect to the top of the stack.                 |
-`-------------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| FIN is pointing to a wannabee semantic value (i.e., a `$').       |
+|                                                                   |
+| Possible inputs: $[<TYPENAME>]($|integer)                         |
+|                                                                   |
+| Output to OOUT a reference to this semantic value. RULE_LENGTH is |
+| the number of values in the current rule so far, which says where |
+| to find `$0' with respect to the top of the stack.                |
+`------------------------------------------------------------------*/
 
 static inline void
 copy_dollar (FILE *fin, struct obstack *oout,
-	     symbol_list *rule, int stack_offset)
+	     symbol_list *rule, int rule_length)
 {
   int c = getc (fin);
   const char *type_name = NULL;
@@ -564,15 +558,15 @@ copy_dollar (FILE *fin, struct obstack *oout,
 
   if (c == '$')
     {
-      obstack_sgrow (oout, "yyval");
-
       if (!type_name)
 	type_name = get_type_name (0, rule);
-      if (type_name)
-	obstack_fgrow1 (oout, ".%s", type_name);
       if (!type_name && typed)
 	complain (_("$$ of `%s' has no declared type"),
 		  rule->sym->tag);
+      if (!type_name)
+	type_name = "";
+      obstack_fgrow1 (oout,
+		      "]b4_lhs_value([%s])[", type_name);
     }
   else if (isdigit (c) || c == '-')
     {
@@ -580,23 +574,19 @@ copy_dollar (FILE *fin, struct obstack *oout,
       ungetc (c, fin);
       n = read_signed_integer (fin);
 
-      if (n > stack_offset)
+      if (n > rule_length)
 	complain (_("invalid value: %s%d"), "$", n);
       else
 	{
 	  if (!type_name && n > 0)
 	    type_name = get_type_name (n, rule);
-
-	  /* Offset is always 0 if parser has already popped the stack
-	     pointer.  */
-	  obstack_fgrow1 (oout, "yyvsp[%d]",
-			  n - (semantic_parser ? 0 : stack_offset));
-
-	  if (type_name)
-	    obstack_fgrow1 (oout, ".%s", type_name);
 	  if (!type_name && typed)
 	    complain (_("$%d of `%s' has no declared type"),
 		      n, rule->sym->tag);
+	  if (!type_name)
+	    type_name = "";
+	  obstack_fgrow3 (oout, "]b4_rhs_value([%d], [%d], [%s])[",
+			  rule_length, n, type_name);
 	}
     }
   else
@@ -1277,19 +1267,19 @@ read_declarations (void)
     }
 }
 
-/*-------------------------------------------------------------------.
-| Assuming that a `{' has just been seen, copy everything up to the  |
-| matching `}' into the actions file.  STACK_OFFSET is the number of |
-| values in the current rule so far, which says where to find `$0'   |
-| with respect to the top of the stack.                              |
-|                                                                    |
-| This routine is used both for actions and guards.  Only            |
-| ACTION_OBSTACK is used, but this is fine, since we use only        |
-| pointers to relevant portions inside this obstack.                 |
-`-------------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Assuming that a `{' has just been seen, copy everything up to the |
+| matching `}' into the actions file.  RULE_LENGTH is the number of |
+| values in the current rule so far, which says where to find `$0'  |
+| with respect to the top of the stack.                             |
+|                                                                   |
+| This routine is used both for actions and guards.  Only           |
+| ACTION_OBSTACK is used, but this is fine, since we use only       |
+| pointers to relevant portions inside this obstack.                |
+`------------------------------------------------------------------*/
 
 static void
-parse_braces (symbol_list *rule, int stack_offset)
+parse_braces (symbol_list *rule, int rule_length)
 {
   int c;
   int count;
@@ -1320,13 +1310,11 @@ parse_braces (symbol_list *rule, int stack_offset)
 	    break;
 
 	  case '$':
-	    copy_dollar (finput, &action_obstack,
-			 rule, stack_offset);
+	    copy_dollar (finput, &action_obstack, rule, rule_length);
 	    break;
 
 	  case '@':
-	    copy_at (finput, &action_obstack,
-		     stack_offset);
+	    copy_at (finput, &action_obstack, rule_length);
 	    break;
 
 	  case EOF:
@@ -1346,22 +1334,22 @@ parse_braces (symbol_list *rule, int stack_offset)
 
 
 static void
-parse_action (symbol_list *rule, int stack_offset)
+parse_action (symbol_list *rule, int rule_length)
 {
   rule->action_line = lineno;
-  parse_braces (rule, stack_offset);
+  parse_braces (rule, rule_length);
   rule->action = obstack_finish (&action_obstack);
 }
 
 
 static void
-parse_guard (symbol_list *rule, int stack_offset)
+parse_guard (symbol_list *rule, int rule_length)
 {
   token_t t = lex ();
   if (t != tok_left_curly)
     complain (_("invalid %s declaration"), "%guard");
   rule->guard_line = lineno;
-  parse_braces (rule, stack_offset);
+  parse_braces (rule, rule_length);
   rule->guard = obstack_finish (&action_obstack);
 }
 
