@@ -26,17 +26,17 @@
 #include "relation.h"
 
 void
-relation_print (relation r, size_t size, FILE *out)
+relation_print (relation r, relation_node size, FILE *out)
 {
-  unsigned int i;
-  unsigned int j;
+  relation_node i;
+  relation_node j;
 
   for (i = 0; i < size; ++i)
     {
-      fprintf (out, "%3d: ", i);
+      fprintf (out, "%3lu: ", (unsigned long int) i);
       if (r[i])
 	for (j = 0; r[i][j] != END_NODE; ++j)
-	  fprintf (out, "%3d ", r[i][j]);
+	  fprintf (out, "%3lu ", (unsigned long int) r[i][j]);
       fputc ('\n', out);
     }
   fputc ('\n', out);
@@ -53,15 +53,15 @@ relation_print (relation r, size_t size, FILE *out)
 static relation R;
 static relation_nodes INDEX;
 static relation_nodes VERTICES;
-static int top;
-static int infinity;
+static relation_node top;
+static relation_node infinity;
 static bitsetv F;
 
 static void
-traverse (int i)
+traverse (relation_node i)
 {
-  int j;
-  int height;
+  relation_node j;
+  relation_node height;
 
   VERTICES[++top] = i;
   INDEX[i] = height = top;
@@ -93,9 +93,9 @@ traverse (int i)
 
 
 void
-relation_digraph (relation r, size_t size, bitsetv *function)
+relation_digraph (relation r, relation_node size, bitsetv *function)
 {
-  unsigned int i;
+  relation_node i;
 
   infinity = size + 2;
   INDEX = xcalloc (size + 1, sizeof *INDEX);
@@ -121,15 +121,16 @@ relation_digraph (relation r, size_t size, bitsetv *function)
 `-------------------------------------------*/
 
 void
-relation_transpose (relation *R_arg, int n)
+relation_transpose (relation *R_arg, relation_node n)
 {
   /* The result. */
   relation new_R = xnmalloc (n, sizeof *new_R);
   /* END_R[I] -- next entry of NEW_R[I]. */
   relation end_R = xnmalloc (n, sizeof *end_R);
   /* NEDGES[I] -- total size of NEW_R[I]. */
-  int *nedges = xcalloc (n, sizeof *nedges);
-  int i, j;
+  size_t *nedges = xcalloc (n, sizeof *nedges);
+  relation_node i;
+  relation_node j;
 
   if (trace_flag & trace_sets)
     {
