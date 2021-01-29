@@ -98,16 +98,13 @@ relation_digraph (relation r, size_t size, bitsetv *function)
   unsigned int i;
 
   infinity = size + 2;
-  CALLOC (INDEX, size + 1);
-  CALLOC (VERTICES, size + 1);
+  INDEX = xcalloc (size + 1, sizeof *INDEX);
+  VERTICES = xnmalloc (size + 1, sizeof *VERTICES);
   top = 0;
 
   R = r;
   F = *function;
 
-  for (i = 0; i < size; i++)
-    INDEX[i] = 0;
-
   for (i = 0; i < size; i++)
     if (INDEX[i] == 0 && R[i])
       traverse (i);
@@ -127,11 +124,11 @@ void
 relation_transpose (relation *R_arg, int n)
 {
   /* The result. */
-  relation new_R = CALLOC (new_R, n);
+  relation new_R = xnmalloc (n, sizeof *new_R);
   /* END_R[I] -- next entry of NEW_R[I]. */
-  relation end_R = CALLOC (end_R, n);
+  relation end_R = xnmalloc (n, sizeof *end_R);
   /* NEDGES[I] -- total size of NEW_R[I]. */
-  int *nedges = CALLOC (nedges, n);
+  int *nedges = xcalloc (n, sizeof *nedges);
   int i, j;
 
   if (trace_flag & trace_sets)
@@ -148,13 +145,16 @@ relation_transpose (relation *R_arg, int n)
 
   /* Allocate. */
   for (i = 0; i < n; i++)
-    if (nedges[i] > 0)
-      {
-	relation_node *sp = CALLOC (sp, nedges[i] + 1);
-	sp[nedges[i]] = END_NODE;
-	new_R[i] = sp;
-	end_R[i] = sp;
-      }
+    {
+      relation_node *sp = NULL;
+      if (nedges[i] > 0)
+	{
+	  sp = xnmalloc (nedges[i] + 1, sizeof *sp);
+	  sp[nedges[i]] = END_NODE;
+	}
+      new_R[i] = sp;
+      end_R[i] = sp;
+    }
 
   /* Store. */
   for (i = 0; i < n; i++)
