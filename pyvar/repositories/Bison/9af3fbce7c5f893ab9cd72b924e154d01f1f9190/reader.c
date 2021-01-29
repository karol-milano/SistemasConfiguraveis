@@ -972,8 +972,6 @@ read_declarations (void)
 | which says where to find `$0' with respect to the top of the      |
 | stack.  It is not the same as the rule->length in the case of mid |
 | rule actions.                                                     |
-|                                                                   |
-| This routine is used for actions.                                 |
 `------------------------------------------------------------------*/
 
 static void
@@ -1169,6 +1167,48 @@ grammar_midrule_action (void)
   grammar_symbol_append (sdummy);
 }
 
+/* Set the precedence symbol of the current rule to PRECSYM. */
+
+static void
+grammar_current_rule_prec_set (symbol_t *precsym)
+{
+  if (current_rule->ruleprec)
+    complain (_("two @prec's in a row"));
+  current_rule->ruleprec = precsym;
+}
+
+/* Check that the last rule (CURRENT_RULE) is properly defined.  For
+   instance, there should be no type clash on the default action.  */
+
+static void
+grammar_current_rule_check (void)
+{
+  symbol_t *lhs = current_rule->sym;
+  symbol_t *first_rhs = current_rule->next->sym;
+
+  /* If there is an action, then there is nothing we can do: the user
+     is allowed to shoot in her foot.  */
+  if (current_rule->action)
+    return;
+
+  /* If $$ is being set in default way, report if any type mismatch.
+     */
+  if (first_rhs)
+    {
+      const char *lhs_type = lhs->type_name       ? lhs->type_name       : "";
+      const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
+      if (strcmp (lhs_type, rhs_type))
+	complain (_("type clash (`%s' `%s') on default action"),
+		  lhs_type, rhs_type);
+    }
+  /* Warn if there is no default for $$ but we need one.  */
+  else
+    {
+      if (lhs->type_name)
+	complain (_("empty rule for typed nonterminal, and no action"));
+    }
+}
+
 
 static void
 readgram (void)
@@ -1184,8 +1224,6 @@ readgram (void)
 	int action_flag = 0;
 	/* Number of symbols in rhs of this rule so far */
 	int rulelength = 0;
-	int xactions = 0;	/* JF for error checking */
-	symbol_t *first_rhs = 0;
 
 	if (t == tok_identifier)
 	  {
@@ -1213,7 +1251,7 @@ readgram (void)
 	    if (t == tok_prec)
 	      {
 		t = lex ();
-		current_rule->ruleprec = symval;
+		grammar_current_rule_prec_set (symval);
 		t = lex ();
 	      }
 
@@ -1236,11 +1274,8 @@ readgram (void)
 		    warn (_("previous rule lacks an ending `;'"));
 		    break;
 		  }
-
-		if (!first_rhs)	/* JF */
-		  first_rhs = symval;
-		/* Not followed by colon =>
-		   process as part of this rule's rhs.  */
+		/* Not followed by colon => process as part of this
+		   rule's rhs.  */
 	      }
 
 	    /* If we just passed an action, that action was in the middle
@@ -1261,7 +1296,6 @@ readgram (void)
 	      {
 		parse_action (current_rule, rulelength);
 		action_flag = 1;
-		++xactions;	/* JF */
 	      }
 	    ++rulelength;
 	  }			/* end of  read rhs of rule */
@@ -1271,37 +1305,20 @@ readgram (void)
 
 	if (t == tok_prec)
 	  {
-	    complain (_("two @prec's in a row"));
 	    t = lex ();
-	    current_rule->ruleprec = symval;
+	    grammar_current_rule_prec_set (symval);
 	    t = lex ();
 	  }
 
 	if (t == tok_left_curly)
 	  {
-	    /* This case never occurs -wjh */
-	    if (action_flag)
-	      complain (_("two actions at end of one rule"));
 	    parse_action (current_rule, rulelength);
 	    action_flag = 1;
-	    ++xactions;	/* -wjh */
 	    t = lex ();
 	  }
-	/* If $$ is being set in default way, report if any type
-	   mismatch.  */
-	else if (!xactions
-		 && first_rhs && lhs->type_name != first_rhs->type_name)
-	  {
-	    if (lhs->type_name == 0
-		|| first_rhs->type_name == 0
-		|| strcmp (lhs->type_name, first_rhs->type_name))
-	      complain (_("type clash (`%s' `%s') on default action"),
-			lhs->type_name ? lhs->type_name : "",
-			first_rhs->type_name ? first_rhs->type_name : "");
-	  }
-	/* Warn if there is no default for $$ but we need one.  */
-	else if (!xactions && !first_rhs && lhs->type_name != 0)
-	  complain (_("empty rule for typed nonterminal, and no action"));
+
+	grammar_current_rule_check ();
+
 	if (t == tok_two_percents || t == tok_eof)
 	  warn (_("previous rule lacks an ending `;'"));
 	if (t == tok_semicolon)
