@@ -438,7 +438,6 @@ reduce_output (FILE *out)
     fprintf (out, "\n\n");
 }
 
-#if TRACE
 static void
 dump_grammar (FILE *out)
 {
@@ -478,7 +477,6 @@ dump_grammar (FILE *out)
     }
   fprintf (out, "\n\n");
 }
-#endif
 
 
 
@@ -539,20 +537,15 @@ reduce_grammar (void)
 	   tags[start_symbol]);
 
   reduce_grammar_tables ();
-#if TRACE
-  dump_grammar (stderr);
-#endif
-
-  if (statistics_flag)
-    fprintf (stderr, _("reduced %s defines %d terminal%s, %d nonterminal%s\
-, and %d production%s.\n"),
-	     infile,
-	     ntokens,
-	     (ntokens == 1 ? "" : "s"),
-	     nvars,
-	     (nvars == 1 ? "" : "s"),
-	     nrules,
-	     (nrules == 1 ? "" : "s"));
+
+  if (trace_flag)
+    {
+      dump_grammar (stderr);
+
+      fprintf (stderr, "reduced %s defines %d terminals, %d nonterminals\
+, and %d productions.\n",
+	       infile, ntokens, nvars, nrules);
+    }
 }
 
 
