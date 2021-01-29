@@ -112,8 +112,8 @@ relation_digraph (relation r, size_t size, bitsetv *function)
     if (INDEX[i] == 0 && R[i])
       traverse (i);
 
-  XFREE (INDEX);
-  XFREE (VERTICES);
+  free (INDEX);
+  free (VERTICES);
 
   *function = F;
 }
@@ -170,7 +170,7 @@ relation_transpose (relation *R_arg, int n)
 
   /* Free the input: it is replaced with the result. */
   for (i = 0; i < n; i++)
-    XFREE ((*R_arg)[i]);
+    free ((*R_arg)[i]);
   free (*R_arg);
 
   if (trace_flag & trace_sets)
