@@ -966,19 +966,24 @@ read_declarations (void)
 
 /*------------------------------------------------------------------.
 | Assuming that a `{' has just been seen, copy everything up to the |
-| matching `}' into ACTION_OBSTACK.                                 |
-|                                                                   |
-| RULE_LENGTH is the number of values in the current rule so far,   |
-| which says where to find `$0' with respect to the top of the      |
-| stack.  It is not the same as the rule->length in the case of mid |
-| rule actions.                                                     |
+| matching `}' into ACTION_OBSTACK, and return a pointer to this    |
+| action.                                                           |
 `------------------------------------------------------------------*/
 
-static void
-parse_action (symbol_list *rule, int rule_length)
+static char *
+parse_action (symbol_list *rule)
 {
   int count = 1;
-  rule->action_line = lineno;
+
+  /* RULE_LENGTH is the number of values in the current rule so far,
+     which says where to find `$0' with respect to the top of the
+     stack.  It is not the same as the rule->length in the case of mid
+     rule actions.  */
+  int rule_length = 0;
+  symbol_list *rhs;
+  for (rhs = rule->next; rhs; rhs = rhs->next)
+    ++rule_length;
+
   while (count > 0)
     {
       int c;
@@ -1025,7 +1030,7 @@ parse_action (symbol_list *rule, int rule_length)
     }
 
   obstack_1grow (&action_obstack, '\0');
-  rule->action = obstack_finish (&action_obstack);
+  return obstack_finish (&action_obstack);
 }
 
 
@@ -1210,6 +1215,33 @@ grammar_current_rule_check (void)
 }
 
 
+/* Attach a SYMBOL to the current rule.  If needed, move the previous
+   action as a mid-rule action.  */
+
+static void
+grammar_current_rule_symbol_append (symbol_t *symbol)
+{
+  if (current_rule->action)
+    grammar_midrule_action ();
+  ++nritems;
+  grammar_symbol_append (symbol);
+}
+
+
+/* Attach an ACTION to the current rule.  If needed, move the previous
+   action as a mid-rule action.  */
+
+static void
+grammar_current_rule_action_append (char *action, int action_line)
+{
+  if (current_rule->action)
+    grammar_midrule_action ();
+  current_rule->action = action;
+  current_rule->action_line = action_line;
+}
+
+
+
 static void
 readgram (void)
 {
@@ -1221,10 +1253,6 @@ readgram (void)
   while (t != tok_two_percents && t != tok_eof)
     if (t == tok_identifier || t == tok_bar)
       {
-	int action_flag = 0;
-	/* Number of symbols in rhs of this rule so far */
-	int rulelength = 0;
-
 	if (t == tok_identifier)
 	  {
 	    lhs = symval;
@@ -1278,26 +1306,16 @@ readgram (void)
 		   rule's rhs.  */
 	      }
 
-	    /* If we just passed an action, that action was in the middle
-	       of a rule, so make a dummy rule to reduce it to a
-	       non-terminal.  */
-	    if (action_flag)
-	      {
-		grammar_midrule_action ();
-		action_flag = 0;
-	      }
-
 	    if (t == tok_identifier)
 	      {
-		++nritems;
-		grammar_symbol_append (symval);
+		grammar_current_rule_symbol_append (symval);
 	      }
 	    else		/* handle an action.  */
 	      {
-		parse_action (current_rule, rulelength);
-		action_flag = 1;
+		int action_line = lineno;
+		char *action = parse_action (current_rule);
+		grammar_current_rule_action_append (action, action_line);
 	      }
-	    ++rulelength;
 	  }			/* end of  read rhs of rule */
 
 	/* Put an empty link in the list to mark the end of this rule  */
@@ -1312,8 +1330,9 @@ readgram (void)
 
 	if (t == tok_left_curly)
 	  {
-	    parse_action (current_rule, rulelength);
-	    action_flag = 1;
+	    int action_line = lineno;
+	    char *action = parse_action (current_rule);
+	    grammar_current_rule_action_append (action, action_line);
 	    t = lex ();
 	  }
 
