@@ -49,8 +49,8 @@ relation_print (relation r, relation_node size, FILE *out)
 `---------------------------------------------------------------*/
 
 static relation R;
-static relation_nodes INDEX;
-static relation_nodes VERTICES;
+static relation_nodes indexes;
+static relation_nodes vertices;
 static relation_node top;
 static relation_node infinity;
 static bitsetv F;
@@ -60,26 +60,26 @@ traverse (relation_node i)
 {
   relation_node height;
 
-  VERTICES[++top] = i;
-  INDEX[i] = height = top;
+  vertices[++top] = i;
+  indexes[i] = height = top;
 
   if (R[i])
     for (relation_node j = 0; R[i][j] != END_NODE; ++j)
       {
-        if (INDEX[R[i][j]] == 0)
+        if (indexes[R[i][j]] == 0)
           traverse (R[i][j]);
 
-        if (INDEX[i] > INDEX[R[i][j]])
-          INDEX[i] = INDEX[R[i][j]];
+        if (indexes[i] > indexes[R[i][j]])
+          indexes[i] = indexes[R[i][j]];
 
         bitset_or (F[i], F[i], F[R[i][j]]);
       }
 
-  if (INDEX[i] == height)
+  if (indexes[i] == height)
     for (;;)
       {
-        relation_node j = VERTICES[top--];
-        INDEX[j] = infinity;
+        relation_node j = vertices[top--];
+        indexes[j] = infinity;
 
         if (i == j)
           break;
@@ -93,19 +93,19 @@ void
 relation_digraph (relation r, relation_node size, bitsetv *function)
 {
   infinity = size + 2;
-  INDEX = xcalloc (size + 1, sizeof *INDEX);
-  VERTICES = xnmalloc (size + 1, sizeof *VERTICES);
+  indexes = xcalloc (size + 1, sizeof *indexes);
+  vertices = xnmalloc (size + 1, sizeof *vertices);
   top = 0;
 
   R = r;
   F = *function;
 
   for (relation_node i = 0; i < size; i++)
-    if (INDEX[i] == 0 && R[i])
+    if (indexes[i] == 0 && R[i])
       traverse (i);
 
-  free (INDEX);
-  free (VERTICES);
+  free (indexes);
+  free (vertices);
 
   *function = F;
 }
