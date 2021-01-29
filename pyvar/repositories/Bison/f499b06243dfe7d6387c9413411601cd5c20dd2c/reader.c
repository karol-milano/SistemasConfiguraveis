@@ -40,9 +40,14 @@ typedef struct symbol_list
   struct symbol_list *next;
   bucket *sym;
   int line;
+
   /* The action is attached to the LHS of a rule. */
   const char *action;
   int action_line;
+
+  /* The guard is attached to the LHS of a rule. */
+  const char *guard;
+  int guard_line;
   bucket *ruleprec;
 } symbol_list;
 
@@ -76,6 +81,8 @@ symbol_list_new (bucket *sym)
   res->line = lineno;
   res->action = NULL;
   res->action_line = 0;
+  res->guard = NULL;
+  res->guard_line = 0;
   res->ruleprec = NULL;
   return res;
 }
@@ -1088,6 +1095,8 @@ copy_action (symbol_list *rule, int stack_offset)
   count = 1;
   c = getc (finput);
 
+  rule->action_line = lineno;
+
   while (count > 0)
     {
       while (c != '}')
@@ -1144,7 +1153,6 @@ copy_action (symbol_list *rule, int stack_offset)
 
   obstack_1grow (&action_obstack, '\0');
   rule->action = obstack_finish (&action_obstack);
-  rule->action_line = lineno;
 }
 
 /*-------------------------------------------------------------------.
@@ -1167,12 +1175,7 @@ copy_guard (symbol_list *rule, int stack_offset)
   if (semantic_parser)
     stack_offset = 0;
 
-  obstack_fgrow1 (&guard_obstack, "\ncase %d:\n", nrules);
-  if (!no_lines_flag)
-    obstack_fgrow2 (&guard_obstack, muscle_find ("linef"),
-		    lineno, quotearg_style (c_quoting_style,
-					    muscle_find ("filename")));
-  obstack_1grow (&guard_obstack, '{');
+  rule->guard_line = lineno;
 
   count = 0;
   c = getc (finput);
@@ -1231,19 +1234,8 @@ copy_guard (symbol_list *rule, int stack_offset)
 	c = getc (finput);
     }
 
-  c = skip_white_space ();
-
-  obstack_sgrow (&guard_obstack, ";\n    break;}");
-  if (c == '{')
-    copy_action (rule, stack_offset);
-  else if (c == '=')
-    {
-      c = getc (finput);	/* why not skip_white_space -wjh */
-      if (c == '{')
-	copy_action (rule, stack_offset);
-    }
-  else
-    ungetc (c, finput);
+  obstack_1grow (&guard_obstack, '\0');
+  rule->guard = obstack_finish (&guard_obstack);
 }
 
 
@@ -1466,6 +1458,7 @@ readgram (void)
 	    crule->ruleprec = symval;
 	    t = lex ();
 	  }
+
 	if (t == tok_guard)
 	  {
 	    if (!semantic_parser)
@@ -1474,7 +1467,8 @@ readgram (void)
 	    copy_guard (crule, rulelength);
 	    t = lex ();
 	  }
-	else if (t == tok_left_curly)
+
+	if (t == tok_left_curly)
 	  {
 	    /* This case never occurs -wjh */
 	    if (action_flag)
@@ -1781,6 +1775,8 @@ packgram (void)
       rule_table[ruleno].useful = TRUE;
       rule_table[ruleno].action = p->action;
       rule_table[ruleno].action_line = p->action_line;
+      rule_table[ruleno].guard = p->guard;
+      rule_table[ruleno].guard_line = p->guard_line;
 
       p = p->next;
       while (p && p->sym)
