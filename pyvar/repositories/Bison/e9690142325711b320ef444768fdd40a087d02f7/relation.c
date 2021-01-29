@@ -36,8 +36,8 @@ relation_print (relation r, relation_node size, FILE *out)
     {
       fprintf (out, "%3lu: ", (unsigned long int) i);
       if (r[i])
-	for (j = 0; r[i][j] != END_NODE; ++j)
-	  fprintf (out, "%3lu ", (unsigned long int) r[i][j]);
+        for (j = 0; r[i][j] != END_NODE; ++j)
+          fprintf (out, "%3lu ", (unsigned long int) r[i][j]);
       fputc ('\n', out);
     }
   fputc ('\n', out);
@@ -70,25 +70,25 @@ traverse (relation_node i)
   if (R[i])
     for (j = 0; R[i][j] != END_NODE; ++j)
       {
-	if (INDEX[R[i][j]] == 0)
-	  traverse (R[i][j]);
+        if (INDEX[R[i][j]] == 0)
+          traverse (R[i][j]);
 
-	if (INDEX[i] > INDEX[R[i][j]])
-	  INDEX[i] = INDEX[R[i][j]];
+        if (INDEX[i] > INDEX[R[i][j]])
+          INDEX[i] = INDEX[R[i][j]];
 
-	bitset_or (F[i], F[i], F[R[i][j]]);
+        bitset_or (F[i], F[i], F[R[i][j]]);
       }
 
   if (INDEX[i] == height)
     for (;;)
       {
-	j = VERTICES[top--];
-	INDEX[j] = infinity;
+        j = VERTICES[top--];
+        INDEX[j] = infinity;
 
-	if (i == j)
-	  break;
+        if (i == j)
+          break;
 
-	bitset_copy (F[j], F[i]);
+        bitset_copy (F[j], F[i]);
       }
 }
 
@@ -144,17 +144,17 @@ relation_transpose (relation *R_arg, relation_node n)
   for (i = 0; i < n; i++)
     if (r[i])
       for (j = 0; r[i][j] != END_NODE; ++j)
-	++nedges[r[i][j]];
+        ++nedges[r[i][j]];
 
   /* Allocate. */
   for (i = 0; i < n; i++)
     {
       relation_node *sp = NULL;
       if (nedges[i] > 0)
-	{
-	  sp = xnmalloc (nedges[i] + 1, sizeof *sp);
-	  sp[nedges[i]] = END_NODE;
-	}
+        {
+          sp = xnmalloc (nedges[i] + 1, sizeof *sp);
+          sp[nedges[i]] = END_NODE;
+        }
       new_R[i] = sp;
       end_R[i] = sp;
     }
@@ -163,7 +163,7 @@ relation_transpose (relation *R_arg, relation_node n)
   for (i = 0; i < n; i++)
     if (r[i])
       for (j = 0; r[i][j] != END_NODE; ++j)
-	*end_R[r[i][j]]++ = i;
+        *end_R[r[i][j]]++ = i;
 
   free (nedges);
   free (end_R);
