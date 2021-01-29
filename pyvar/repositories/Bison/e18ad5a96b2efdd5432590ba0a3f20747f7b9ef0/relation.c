@@ -29,14 +29,11 @@
 void
 relation_print (relation r, relation_node size, FILE *out)
 {
-  relation_node i;
-  relation_node j;
-
-  for (i = 0; i < size; ++i)
+  for (relation_node i = 0; i < size; ++i)
     {
       fprintf (out, "%3lu: ", (unsigned long) i);
       if (r[i])
-        for (j = 0; r[i][j] != END_NODE; ++j)
+        for (relation_node j = 0; r[i][j] != END_NODE; ++j)
           fprintf (out, "%3lu ", (unsigned long) r[i][j]);
       fputc ('\n', out);
     }
@@ -61,14 +58,13 @@ static bitsetv F;
 static void
 traverse (relation_node i)
 {
-  relation_node j;
   relation_node height;
 
   VERTICES[++top] = i;
   INDEX[i] = height = top;
 
   if (R[i])
-    for (j = 0; R[i][j] != END_NODE; ++j)
+    for (relation_node j = 0; R[i][j] != END_NODE; ++j)
       {
         if (INDEX[R[i][j]] == 0)
           traverse (R[i][j]);
@@ -82,7 +78,7 @@ traverse (relation_node i)
   if (INDEX[i] == height)
     for (;;)
       {
-        j = VERTICES[top--];
+        relation_node j = VERTICES[top--];
         INDEX[j] = infinity;
 
         if (i == j)
@@ -96,8 +92,6 @@ traverse (relation_node i)
 void
 relation_digraph (relation r, relation_node size, bitsetv *function)
 {
-  relation_node i;
-
   infinity = size + 2;
   INDEX = xcalloc (size + 1, sizeof *INDEX);
   VERTICES = xnmalloc (size + 1, sizeof *VERTICES);
@@ -106,7 +100,7 @@ relation_digraph (relation r, relation_node size, bitsetv *function)
   R = r;
   F = *function;
 
-  for (i = 0; i < size; i++)
+  for (relation_node i = 0; i < size; i++)
     if (INDEX[i] == 0 && R[i])
       traverse (i);
 
@@ -125,14 +119,6 @@ void
 relation_transpose (relation *R_arg, relation_node n)
 {
   relation r = *R_arg;
-  /* The result. */
-  relation new_R = xnmalloc (n, sizeof *new_R);
-  /* END_R[I] -- next entry of NEW_R[I]. */
-  relation end_R = xnmalloc (n, sizeof *end_R);
-  /* NEDGES[I] -- total size of NEW_R[I]. */
-  size_t *nedges = xcalloc (n, sizeof *nedges);
-  relation_node i;
-  relation_node j;
 
   if (trace_flag & trace_sets)
     {
@@ -141,13 +127,19 @@ relation_transpose (relation *R_arg, relation_node n)
     }
 
   /* Count. */
-  for (i = 0; i < n; i++)
+  /* NEDGES[I] -- total size of NEW_R[I]. */
+  size_t *nedges = xcalloc (n, sizeof *nedges);
+  for (relation_node i = 0; i < n; i++)
     if (r[i])
-      for (j = 0; r[i][j] != END_NODE; ++j)
+      for (relation_node j = 0; r[i][j] != END_NODE; ++j)
         ++nedges[r[i][j]];
 
   /* Allocate. */
-  for (i = 0; i < n; i++)
+  /* The result. */
+  relation new_R = xnmalloc (n, sizeof *new_R);
+  /* END_R[I] -- next entry of NEW_R[I]. */
+  relation end_R = xnmalloc (n, sizeof *end_R);
+  for (relation_node i = 0; i < n; i++)
     {
       relation_node *sp = NULL;
       if (nedges[i] > 0)
@@ -160,16 +152,16 @@ relation_transpose (relation *R_arg, relation_node n)
     }
 
   /* Store. */
-  for (i = 0; i < n; i++)
+  for (relation_node i = 0; i < n; i++)
     if (r[i])
-      for (j = 0; r[i][j] != END_NODE; ++j)
+      for (relation_node j = 0; r[i][j] != END_NODE; ++j)
         *end_R[r[i][j]]++ = i;
 
   free (nedges);
   free (end_R);
 
   /* Free the input: it is replaced with the result. */
-  for (i = 0; i < n; i++)
+  for (relation_node i = 0; i < n; i++)
     free (r[i]);
   free (r);
 
