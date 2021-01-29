@@ -134,7 +134,7 @@ relation_transpose (relation_t *R_arg, int n)
 
   if (trace_flag & trace_sets)
     {
-      fputs (_("relation_transpose: input\n"), stderr);
+      fputs ("relation_transpose: input\n", stderr);
       relation_print (*R_arg, n, stderr);
     }
 
@@ -173,7 +173,7 @@ relation_transpose (relation_t *R_arg, int n)
 
   if (trace_flag & trace_sets)
     {
-      fputs (_("relation_transpose: output\n"), stderr);
+      fputs ("relation_transpose: output\n", stderr);
       relation_print (new_R, n, stderr);
     }
 
