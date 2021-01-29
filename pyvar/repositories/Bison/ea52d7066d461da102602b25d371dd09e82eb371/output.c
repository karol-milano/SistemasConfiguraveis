@@ -515,25 +515,25 @@ token_actions (void)
 `-----------------------------*/
 
 static void
-actions_output (struct obstack *oout)
+actions_output (FILE *out)
 {
   int rule;
   for (rule = 1; rule < nrules + 1; ++rule)
     if (rule_table[rule].action)
       {
-	obstack_fgrow1 (oout, "  case %d:\n", rule);
+	fprintf (out, "  case %d:\n", rule);
 
 	if (!no_lines_flag)
-	  obstack_fgrow2 (oout, muscle_find ("linef"),
-			  rule_table[rule].action_line,
-			  quotearg_style (c_quoting_style,
-					  muscle_find ("filename")));
-	obstack_1grow (oout, '{');
-	obstack_sgrow (oout, rule_table[rule].action);
+	  fprintf (out, muscle_find ("linef"),
+		   rule_table[rule].action_line,
+		   quotearg_style (c_quoting_style,
+				   muscle_find ("filename")));
 	/* As a Bison extension, add the ending semicolon.  Since some
 	   Yacc don't do that, help people using bison as a Yacc
 	   finding their missing semicolons.  */
-	obstack_fgrow1 (oout, "%s}\n    break;\n\n", yacc_flag ? ";" : "");
+	fprintf (out, "{ %s%s }\n    break;\n\n",
+		 rule_table[rule].action,
+		 yacc_flag ? ";" : "");
       }
 }
 
@@ -924,7 +924,7 @@ output_actions (void)
 `------------------------------------------------------------*/
 
 static void
-output_parser (const char *skel_filename, struct obstack *oout)
+output_parser (const char *skel_filename, FILE *out)
 {
   int c;
   FILE *fskel;
@@ -941,7 +941,7 @@ output_parser (const char *skel_filename, struct obstack *oout)
 	{
 	  if (c == '\n')
 	    ++line;
-	  obstack_1grow (oout, c);
+	  putc (c, out);
 	  c = getc (fskel);
 	}
       else if ((c = getc (fskel)) == '%')
@@ -958,19 +958,19 @@ output_parser (const char *skel_filename, struct obstack *oout)
 	  muscle_key = obstack_finish (&muscle_obstack);
 	  muscle_value = muscle_find (muscle_key);
 	  if (!strcmp (muscle_key, "actions"))
-	    actions_output (oout);
+	    actions_output (out);
 	  else if (!strcmp (muscle_key, "line"))
-	    obstack_fgrow1 (oout, "%d", line + 1);
+	    fprintf (out, "%d", line + 1);
 	  else if (muscle_value)
-	    obstack_sgrow (oout, muscle_value);
+	    fputs (muscle_value, out);
 	  else
 	    {
-	      obstack_sgrow (oout, "%%");
-	      obstack_sgrow (oout, muscle_key);
+	      fputs ("%%", out);
+	      fputs (muscle_key, out);
 	    }
 	}
       else
-	obstack_1grow (oout, '%');
+	putc ('%', out);
     }
 
   /* End.  */
@@ -984,6 +984,7 @@ output_parser (const char *skel_filename, struct obstack *oout)
 static void
 output_master_parser (void)
 {
+  FILE *parser = xfopen (parser_file_name, "w");
   if (!skeleton)
     {
       if (semantic_parser)
@@ -992,7 +993,9 @@ output_master_parser (void)
 	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
     }
   muscle_insert ("skeleton", skeleton);
-  output_parser (skeleton, &table_obstack);
+
+  output_parser (skeleton, parser);
+  xfclose (parser);
 }
 
 
