@@ -35,7 +35,7 @@ relation_print (relation r, size_t size, FILE *out)
     {
       fprintf (out, "%3d: ", i);
       if (r[i])
-	for (j = 0; r[i][j] != -1; ++j)
+	for (j = 0; r[i][j] != END_NODE; ++j)
 	  fprintf (out, "%3d ", r[i][j]);
       fputc ('\n', out);
     }
@@ -67,7 +67,7 @@ traverse (int i)
   INDEX[i] = height = top;
 
   if (R[i])
-    for (j = 0; R[i][j] >= 0; ++j)
+    for (j = 0; R[i][j] != END_NODE; ++j)
       {
 	if (INDEX[R[i][j]] == 0)
 	  traverse (R[i][j]);
@@ -143,7 +143,7 @@ relation_transpose (relation *R_arg, int n)
   /* Count. */
   for (i = 0; i < n; i++)
     if ((*R_arg)[i])
-      for (j = 0; (*R_arg)[i][j] >= 0; ++j)
+      for (j = 0; (*R_arg)[i][j] != END_NODE; ++j)
 	++nedges[(*R_arg)[i][j]];
 
   /* Allocate. */
@@ -151,7 +151,7 @@ relation_transpose (relation *R_arg, int n)
     if (nedges[i] > 0)
       {
 	relation_node *sp = CALLOC (sp, nedges[i] + 1);
-	sp[nedges[i]] = -1;
+	sp[nedges[i]] = END_NODE;
 	new_R[i] = sp;
 	end_R[i] = sp;
       }
@@ -159,7 +159,7 @@ relation_transpose (relation *R_arg, int n)
   /* Store. */
   for (i = 0; i < n; i++)
     if ((*R_arg)[i])
-      for (j = 0; (*R_arg)[i][j] >= 0; ++j)
+      for (j = 0; (*R_arg)[i][j] != END_NODE; ++j)
 	{
 	  *end_R[(*R_arg)[i][j]] = i;
 	  ++end_R[(*R_arg)[i][j]];
