@@ -27,14 +27,25 @@
 #include "relation.h"
 
 void
-relation_print (relation r, relation_node size, FILE *out)
+relation_print (relation r, relation_node size,
+                relation_node_print print, FILE *out)
 {
-  for (relation_node i = 0; i < size; ++i)
+  for (size_t i = 0; i < size; ++i)
     {
-      fprintf (out, "%3lu: ", (unsigned long) i);
+      if (print)
+        print (i, out);
+      else
+        fprintf (out, "%3lu", (unsigned long) i);
+      fputc (':', out);
       if (r[i])
         for (relation_node j = 0; r[i][j] != END_NODE; ++j)
-          fprintf (out, "%3lu ", (unsigned long) r[i][j]);
+          {
+            fputc (' ', out);
+            if (print)
+              print (r[i][j], out);
+            else
+              fprintf (out, "%3lu", (unsigned long) r[i][j]);
+          }
       fputc ('\n', out);
     }
   fputc ('\n', out);
@@ -58,10 +69,8 @@ static bitsetv F;
 static void
 traverse (relation_node i)
 {
-  relation_node height;
-
   vertices[++top] = i;
-  indexes[i] = height = top;
+  relation_node height = indexes[i] = top;
 
   if (R[i])
     for (relation_node j = 0; R[i][j] != END_NODE; ++j)
@@ -116,30 +125,30 @@ relation_digraph (relation r, relation_node size, bitsetv *function)
 `-------------------------------------------*/
 
 void
-relation_transpose (relation *R_arg, relation_node n)
+relation_transpose (relation *R_arg, relation_node size)
 {
   relation r = *R_arg;
 
   if (trace_flag & trace_sets)
     {
       fputs ("relation_transpose: input\n", stderr);
-      relation_print (r, n, stderr);
+      relation_print (r, size, NULL, stderr);
     }
 
   /* Count. */
   /* NEDGES[I] -- total size of NEW_R[I]. */
-  size_t *nedges = xcalloc (n, sizeof *nedges);
-  for (relation_node i = 0; i < n; i++)
+  size_t *nedges = xcalloc (size, sizeof *nedges);
+  for (relation_node i = 0; i < size; i++)
     if (r[i])
       for (relation_node j = 0; r[i][j] != END_NODE; ++j)
         ++nedges[r[i][j]];
 
   /* Allocate. */
   /* The result. */
-  relation new_R = xnmalloc (n, sizeof *new_R);
+  relation new_R = xnmalloc (size, sizeof *new_R);
   /* END_R[I] -- next entry of NEW_R[I]. */
-  relation end_R = xnmalloc (n, sizeof *end_R);
-  for (relation_node i = 0; i < n; i++)
+  relation end_R = xnmalloc (size, sizeof *end_R);
+  for (relation_node i = 0; i < size; i++)
     {
       relation_node *sp = NULL;
       if (nedges[i] > 0)
@@ -152,7 +161,7 @@ relation_transpose (relation *R_arg, relation_node n)
     }
 
   /* Store. */
-  for (relation_node i = 0; i < n; i++)
+  for (relation_node i = 0; i < size; i++)
     if (r[i])
       for (relation_node j = 0; r[i][j] != END_NODE; ++j)
         *end_R[r[i][j]]++ = i;
@@ -161,14 +170,14 @@ relation_transpose (relation *R_arg, relation_node n)
   free (end_R);
 
   /* Free the input: it is replaced with the result. */
-  for (relation_node i = 0; i < n; i++)
+  for (relation_node i = 0; i < size; i++)
     free (r[i]);
   free (r);
 
   if (trace_flag & trace_sets)
     {
       fputs ("relation_transpose: output\n", stderr);
-      relation_print (new_R, n, stderr);
+      relation_print (new_R, size, NULL, stderr);
     }
 
   *R_arg = new_R;
