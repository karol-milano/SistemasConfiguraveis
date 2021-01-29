@@ -41,6 +41,9 @@ typedef struct symbol_list
   struct symbol_list *next;
   bucket *sym;
   int line;
+  /* The action is attached to the LHS of a rule. */
+  const char *action;
+  int action_line;
   bucket *ruleprec;
 }
 symbol_list;
@@ -1131,16 +1134,6 @@ copy_action (symbol_list *rule, int stack_offset)
   if (semantic_parser)
     stack_offset = 0;
 
-  obstack_fgrow1 (&action_obstack, "\ncase %d:\n", nrules);
-
-  if (!no_lines_flag)
-    {
-      obstack_fgrow2 (&action_obstack, muscle_find ("linef"),
-		      lineno, quotearg_style (c_quoting_style,
-					      muscle_find ("filename")));
-    }
-  obstack_1grow (&action_obstack, '{');
-
   count = 1;
   c = getc (finput);
 
@@ -1198,13 +1191,9 @@ copy_action (symbol_list *rule, int stack_offset)
 	}
     }
 
-  /* As a Bison extension, add the ending semicolon.  Since some Yacc
-     don't do that, help people using bison as a Yacc finding their
-     missing semicolons.  */
-  if (yacc_flag)
-    obstack_sgrow (&action_obstack, "}\n    break;");
-  else
-    obstack_sgrow (&action_obstack, ";\n    break;}");
+  obstack_1grow (&action_obstack, '\0');
+  rule->action = obstack_finish (&action_obstack);
+  rule->action_line = lineno;
 }
 
 /*-------------------------------------------------------------------.
@@ -1879,6 +1868,8 @@ packgram (void)
       rule_table[ruleno].rhs = itemno;
       rule_table[ruleno].line = p->line;
       rule_table[ruleno].useful = TRUE;
+      rule_table[ruleno].action = p->action;
+      rule_table[ruleno].action_line = p->action_line;
 
       p = p->next;
       while (p && p->sym)
