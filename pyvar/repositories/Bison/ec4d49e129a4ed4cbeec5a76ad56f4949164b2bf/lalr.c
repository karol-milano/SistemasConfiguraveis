@@ -550,6 +550,14 @@ lookahead_tokens_print (FILE *out)
 void
 lalr (void)
 {
+  if (trace_flag & trace_automaton)
+    {
+      fputc ('\n', stderr);
+      begin_use_class ("trace0", stderr);
+      fprintf (stderr, "lalr: begin");
+      end_use_class ("trace0", stderr);
+      fputc ('\n', stderr);
+    }
   initialize_LA ();
   set_goto_map ();
   initialize_goto_follows ();
@@ -560,6 +568,13 @@ lalr (void)
 
   if (trace_flag & trace_sets)
     lookahead_tokens_print (stderr);
+  if (trace_flag & trace_automaton)
+    {
+      begin_use_class ("trace0", stderr);
+      fprintf (stderr, "lalr: done");
+      end_use_class ("trace0", stderr);
+      fputc ('\n', stderr);
+    }
 }
 
 
