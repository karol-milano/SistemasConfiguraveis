@@ -185,7 +185,7 @@ output_gram (void)
     int i;
     short *values = XCALLOC (short, nrules + 1);
     for (i = 0; i < nrules + 1; ++i)
-      values[i] = rule_table[i].rhs;
+      values[i] = rules[i].rhs;
     output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
     XFREE (values);
@@ -239,7 +239,7 @@ output_rule_data (void)
   {
     short *values = XCALLOC (short, nrules + 1);
     for (i = 0; i < nrules + 1; ++i)
-      values[i] = rule_table[i].line;
+      values[i] = rules[i].line;
     output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
     muscle_insert ("rline", obstack_finish (&format_obstack));
@@ -291,7 +291,7 @@ output_rule_data (void)
   {
     short *values = XCALLOC (short, nrules + 1);
     for (i = 0; i < nrules + 1; ++i)
-      values[i] = rule_table[i].lhs;
+      values[i] = rules[i].lhs;
     output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
     muscle_insert ("r1", obstack_finish (&format_obstack));
@@ -301,8 +301,8 @@ output_rule_data (void)
   /* Output YYR2. */
   short_tab = XMALLOC (short, nrules + 1);
   for (i = 1; i < nrules; i++)
-    short_tab[i] = rule_table[i + 1].rhs - rule_table[i].rhs - 1;
-  short_tab[nrules] =  nritems - rule_table[nrules].rhs - 1;
+    short_tab[i] = rules[i + 1].rhs - rules[i].rhs - 1;
+  short_tab[nrules] =  nritems - rules[nrules].rhs - 1;
   output_table_data (&format_obstack, short_tab,
 		     0, 1, nrules + 1);
   muscle_insert ("r2", obstack_finish (&format_obstack));
@@ -508,20 +508,20 @@ actions_output (FILE *out, size_t *line)
 {
   int rule;
   for (rule = 1; rule < nrules + 1; ++rule)
-    if (rule_table[rule].action)
+    if (rules[rule].action)
       {
 	fprintf (out, "  case %d:\n", rule);
 
 	if (!no_lines_flag)
 	  fprintf (out, muscle_find ("linef"),
-		   rule_table[rule].action_line,
+		   rules[rule].action_line,
 		   quotearg_style (c_quoting_style,
 				   muscle_find ("filename")));
 	/* As a Bison extension, add the ending semicolon.  Since some
 	   Yacc don't do that, help people using bison as a Yacc
 	   finding their missing semicolons.  */
 	fprintf (out, "{ %s%s }\n    break;\n\n",
-		 rule_table[rule].action,
+		 rules[rule].action,
 		 yacc_flag ? ";" : "");
 
 	/* We always output 4 '\n' per action.  */
@@ -530,7 +530,7 @@ actions_output (FILE *out, size_t *line)
 	if (!no_lines_flag)
 	  ++*line;
 	/* Get the number of lines written by the user.  */
-	*line += get_lines_number (rule_table[rule].action);
+	*line += get_lines_number (rules[rule].action);
       }
 }
 
@@ -544,17 +544,17 @@ guards_output (FILE *out, size_t *line)
 {
   int rule;
   for (rule = 1; rule < nrules + 1; ++rule)
-    if (rule_table[rule].action)
+    if (rules[rule].action)
       {
 	fprintf (out, "  case %d:\n", rule);
 
 	if (!no_lines_flag)
 	  fprintf (out, muscle_find ("linef"),
-		   rule_table[rule].guard_line,
+		   rules[rule].guard_line,
 		   quotearg_style (c_quoting_style,
 				   muscle_find ("filename")));
 	fprintf (out, "{ %s; }\n    break;\n\n",
-		 rule_table[rule].guard);
+		 rules[rule].guard);
 
 	/* We always output 4 '\n' per action.  */
 	*line += 4;
@@ -562,7 +562,7 @@ guards_output (FILE *out, size_t *line)
 	if (!no_lines_flag)
 	  ++*line;
 	/* Get the number of lines written by the user.  */
-	*line += get_lines_number (rule_table[rule].guard);
+	*line += get_lines_number (rules[rule].guard);
       }
 }
 
@@ -1122,7 +1122,7 @@ output (void)
   if (defines_flag)
     header_output ();
 
-  free (rule_table + 1);
+  free (rules + 1);
   obstack_free (&muscle_obstack, NULL);
   obstack_free (&format_obstack, NULL);
   obstack_free (&action_obstack, NULL);
