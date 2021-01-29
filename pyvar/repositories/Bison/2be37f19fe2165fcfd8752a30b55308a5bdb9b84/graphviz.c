@@ -51,6 +51,7 @@ start_graph (FILE *fout)
            "digraph %s\n"
            "{\n",
            quote (grammar_file));
+  fprintf (fout, "node [shape=box]\n");
 }
 
 void
