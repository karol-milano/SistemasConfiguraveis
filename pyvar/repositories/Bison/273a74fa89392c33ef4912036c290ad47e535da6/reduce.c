@@ -451,7 +451,7 @@ reduce_grammar (void)
   if (nuseless_productions > 0)
     reduce_grammar_tables ();
 
-  if (trace_flag)
+  if (trace_flag & trace_grammar)
     {
       grammar_dump (stderr, "Reduced Grammar");
 
