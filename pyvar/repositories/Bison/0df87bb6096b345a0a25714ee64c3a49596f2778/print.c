@@ -226,7 +226,7 @@ print_grammar (FILE *out)
   int column = 0;
 
   /* rule # : LHS -> RHS */
-  fprintf (out, "\n%s\n", _("Grammar"));
+  fprintf (out, "\n%s\n\n", _("Grammar"));
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
     if (rlhs[i] >= 0)
@@ -237,7 +237,8 @@ print_grammar (FILE *out)
 	  while (*rule > 0)
 	    fprintf (out, " %s", tags[*rule++]);
 	else
-	  fprintf (out, "		/* %s */\n", _("empty"));
+	  fprintf (out, "		/* %s */", _("empty"));
+	fputc ('\n', out);
       }
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
@@ -336,8 +337,7 @@ print_results (void)
       size_t size = obstack_object_size (&output_obstack);
       fwrite (obstack_finish (&output_obstack), 1, size, out);
 
-      if (any_conflicts)
-	print_conflicts (out);
+      conflicts_output (out);
 
       print_grammar (out);
 
