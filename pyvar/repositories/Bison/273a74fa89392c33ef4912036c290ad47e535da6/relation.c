@@ -132,7 +132,7 @@ relation_transpose (relation_t *R_arg, int n)
   int *nedges = XCALLOC (int, n);
   int i, j;
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     {
       fputs ("relation_transpose: input\n", stderr);
       relation_print (*R_arg, n, stderr);
@@ -171,7 +171,7 @@ relation_transpose (relation_t *R_arg, int n)
     XFREE ((*R_arg)[i]);
   free (*R_arg);
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     {
       fputs ("relation_transpose: output\n", stderr);
       relation_print (new_R, n, stderr);
