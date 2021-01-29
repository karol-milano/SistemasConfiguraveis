@@ -1,5 +1,5 @@
 /* Binary relations.
-   Copyright (C) 2002, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2004, 2005 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -123,6 +123,7 @@ relation_digraph (relation r, relation_node size, bitsetv *function)
 void
 relation_transpose (relation *R_arg, relation_node n)
 {
+  relation r = *R_arg;
   /* The result. */
   relation new_R = xnmalloc (n, sizeof *new_R);
   /* END_R[I] -- next entry of NEW_R[I]. */
@@ -135,14 +136,14 @@ relation_transpose (relation *R_arg, relation_node n)
   if (trace_flag & trace_sets)
     {
       fputs ("relation_transpose: input\n", stderr);
-      relation_print (*R_arg, n, stderr);
+      relation_print (r, n, stderr);
     }
 
   /* Count. */
   for (i = 0; i < n; i++)
-    if ((*R_arg)[i])
-      for (j = 0; (*R_arg)[i][j] != END_NODE; ++j)
-	++nedges[(*R_arg)[i][j]];
+    if (r[i])
+      for (j = 0; r[i][j] != END_NODE; ++j)
+	++nedges[r[i][j]];
 
   /* Allocate. */
   for (i = 0; i < n; i++)
@@ -159,20 +160,17 @@ relation_transpose (relation *R_arg, relation_node n)
 
   /* Store. */
   for (i = 0; i < n; i++)
-    if ((*R_arg)[i])
-      for (j = 0; (*R_arg)[i][j] != END_NODE; ++j)
-	{
-	  *end_R[(*R_arg)[i][j]] = i;
-	  ++end_R[(*R_arg)[i][j]];
-	}
+    if (r[i])
+      for (j = 0; r[i][j] != END_NODE; ++j)
+	*end_R[r[i][j]]++ = i;
 
   free (nedges);
   free (end_R);
 
   /* Free the input: it is replaced with the result. */
   for (i = 0; i < n; i++)
-    free ((*R_arg)[i]);
-  free (*R_arg);
+    free (r[i]);
+  free (r);
 
   if (trace_flag & trace_sets)
     {
