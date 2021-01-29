@@ -181,11 +181,11 @@ print_actions (FILE *out, int state)
 static void
 print_state (FILE *out, int state)
 {
-  fputs ("\n\n", out);
   fprintf (out, _("state %d"), state);
   fputs ("\n\n", out);
   print_core (out, state);
   print_actions (out, state);
+  fputs ("\n\n", out);
 }
 
 /*-----------------------------------------.
@@ -212,7 +212,7 @@ print_grammar (FILE *out)
   int column = 0;
 
   /* rule # : LHS -> RHS */
-  fprintf (out, "\n%s\n\n", _("Grammar"));
+  fprintf (out, "%s\n\n", _("Grammar"));
   fprintf (out, "  %s\n", _("Number, Line, Rule"));
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
@@ -228,9 +228,11 @@ print_grammar (FILE *out)
 	  fprintf (out, " /* %s */", _("empty"));
 	fputc ('\n', out);
       }
+  fputs ("\n\n", out);
+
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
-  fprintf (out, "\n%s\n\n", _("Terminals, with rules where they appear"));
+  fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
   fprintf (out, "%s (-1)\n", tags[0]);
 
   for (i = 0; i <= max_user_token_number; i++)
@@ -252,9 +254,10 @@ print_grammar (FILE *out)
 	      }
 	fprintf (out, "%s\n", buffer);
       }
+  fputs ("\n\n", out);
+
 
-  fprintf (out, "\n%s\n\n",
-	   _("Nonterminals, with rules where they appear"));
+  fprintf (out, "%s\n\n", _("Nonterminals, with rules where they appear"));
   for (i = ntokens; i <= nsyms - 1; i++)
     {
       int left_count = 0, right_count = 0;
@@ -309,6 +312,7 @@ print_grammar (FILE *out)
 	}
       fprintf (out, "%s\n", buffer);
     }
+  fputs ("\n\n", out);
 }
 
 void
@@ -324,6 +328,8 @@ print_results (void)
 
       size_t size = obstack_object_size (&output_obstack);
       fwrite (obstack_finish (&output_obstack), 1, size, out);
+      if (size)
+	fputs ("\n\n", out);
 
       reduce_output (out);
       conflicts_output (out);
