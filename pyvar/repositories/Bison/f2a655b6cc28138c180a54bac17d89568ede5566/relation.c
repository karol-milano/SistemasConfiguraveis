@@ -97,8 +97,8 @@ relation_digraph (relation r, size_t size, bitsetv *function)
   unsigned i;
 
   infinity = size + 2;
-  INDEX = XCALLOC (relation_node, size + 1);
-  VERTICES = XCALLOC (relation_node, size + 1);
+  CALLOC (INDEX, size + 1);
+  CALLOC (VERTICES, size + 1);
   top = 0;
 
   R = r;
@@ -126,11 +126,11 @@ void
 relation_transpose (relation *R_arg, int n)
 {
   /* The result. */
-  relation new_R = XCALLOC (relation_nodes, n);
+  relation new_R = CALLOC (new_R, n);
   /* END_R[I] -- next entry of NEW_R[I]. */
-  relation end_R = XCALLOC (relation_nodes, n);
+  relation end_R = CALLOC (end_R, n);
   /* NEDGES[I] -- total size of NEW_R[I]. */
-  int *nedges = XCALLOC (int, n);
+  int *nedges = CALLOC (nedges, n);
   int i, j;
 
   if (trace_flag & trace_sets)
@@ -149,7 +149,7 @@ relation_transpose (relation *R_arg, int n)
   for (i = 0; i < n; i++)
     if (nedges[i] > 0)
       {
-	relation_node *sp = XCALLOC (relation_node, nedges[i] + 1);
+	relation_node *sp = CALLOC (sp, nedges[i] + 1);
 	sp[nedges[i]] = -1;
 	new_R[i] = sp;
 	end_R[i] = sp;
