@@ -27,6 +27,7 @@
 #include "system.h"
 #include "bitset.h"
 #include "bitsetv.h"
+#include "relation.h"
 #include "quotearg.h"
 #include "symtab.h"
 #include "gram.h"
@@ -56,76 +57,6 @@ static short **includes;
 static shorts **lookback;
 
 
-/*---------------------------------------------------------------.
-| digraph & traverse.                                            |
-|                                                                |
-| The following variables are used as common storage between the |
-| two.                                                           |
-`---------------------------------------------------------------*/
-
-static short **R;
-static short *INDEX;
-static short *VERTICES;
-static int top;
-static int infinity;
-
-static void
-traverse (int i)
-{
-  int j;
-  int height;
-
-  VERTICES[++top] = i;
-  INDEX[i] = height = top;
-
-  if (R[i])
-    for (j = 0; R[i][j] >= 0; ++j)
-      {
-	if (INDEX[R[i][j]] == 0)
-	  traverse (R[i][j]);
-
-	if (INDEX[i] > INDEX[R[i][j]])
-	  INDEX[i] = INDEX[R[i][j]];
-
-	bitset_or (F[i], F[i], F[R[i][j]]);
-      }
-
-  if (INDEX[i] == height)
-    for (;;)
-      {
-	j = VERTICES[top--];
-	INDEX[j] = infinity;
-
-	if (i == j)
-	  break;
-
-	bitset_copy (F[j], F[i]);
-      }
-}
-
-
-static void
-digraph (short **relation)
-{
-  int i;
-
-  infinity = ngotos + 2;
-  INDEX = XCALLOC (short, ngotos + 1);
-  VERTICES = XCALLOC (short, ngotos + 1);
-  top = 0;
-
-  R = relation;
-
-  for (i = 0; i < ngotos; i++)
-    INDEX[i] = 0;
-
-  for (i = 0; i < ngotos; i++)
-    if (INDEX[i] == 0 && R[i])
-      traverse (i);
-
-  XFREE (INDEX);
-  XFREE (VERTICES);
-}
 
 
 static void
@@ -280,7 +211,7 @@ initialize_F (void)
 	}
     }
 
-  digraph (reads);
+  relation_digraph (reads, ngotos, &F);
 
   for (i = 0; i < ngotos; i++)
     XFREE (reads[i]);
@@ -309,91 +240,6 @@ add_lookback_edge (state_t *state, rule_number_t ruleno, int gotono)
 }
 
 
-static void
-matrix_print (FILE *out, short **matrix, int n)
-{
-  int i, j;
-
-  for (i = 0; i < n; ++i)
-    {
-      fprintf (out, "%3d: ", i);
-      if (matrix[i])
-	for (j = 0; matrix[i][j] != -1; ++j)
-	  fprintf (out, "%3d ", matrix[i][j]);
-      fputc ('\n', out);
-    }
-  fputc ('\n', out);
-}
-
-/*-------------------------------------------------------------------.
-| Return the transpose of R_ARG, of size N.  Destroy R_ARG, as it is |
-| replaced with the result.                                          |
-|                                                                    |
-| R_ARG[I] is NULL or a -1 terminated list of numbers.               |
-|                                                                    |
-| RESULT[NUM] is NULL or the -1 terminated list of the I such as NUM |
-| is in R_ARG[I].                                                    |
-`-------------------------------------------------------------------*/
-
-static short **
-transpose (short **R_arg, int n)
-{
-  /* The result. */
-  short **new_R = XCALLOC (short *, n);
-  /* END_R[I] -- next entry of NEW_R[I]. */
-  short **end_R = XCALLOC (short *, n);
-  /* NEDGES[I] -- total size of NEW_R[I]. */
-  short *nedges = XCALLOC (short, n);
-  int i, j;
-
-  if (trace_flag)
-    {
-      fputs ("transpose: input\n", stderr);
-      matrix_print (stderr, R_arg, n);
-    }
-
-  /* Count. */
-  for (i = 0; i < n; i++)
-    if (R_arg[i])
-      for (j = 0; R_arg[i][j] >= 0; ++j)
-	++nedges[R_arg[i][j]];
-
-  /* Allocate. */
-  for (i = 0; i < n; i++)
-    if (nedges[i] > 0)
-      {
-	short *sp = XCALLOC (short, nedges[i] + 1);
-	sp[nedges[i]] = -1;
-	new_R[i] = sp;
-	end_R[i] = sp;
-      }
-
-  /* Store. */
-  for (i = 0; i < n; i++)
-    if (R_arg[i])
-      for (j = 0; R_arg[i][j] >= 0; ++j)
-	{
-	  *end_R[R_arg[i][j]] = i;
-	  ++end_R[R_arg[i][j]];
-	}
-
-  free (nedges);
-  free (end_R);
-
-  /* Free the input: it is replaced with the result. */
-  for (i = 0; i < n; i++)
-    XFREE (R_arg[i]);
-  free (R_arg);
-
-  if (trace_flag)
-    {
-      fputs ("transpose: output\n", stderr);
-      matrix_print (stderr, new_R, n);
-    }
-
-  return new_R;
-}
-
 
 static void
 build_relations (void)
@@ -459,7 +305,7 @@ build_relations (void)
   XFREE (edge);
   XFREE (states1);
 
-  includes = transpose (includes, ngotos);
+  relation_transpose (&includes, ngotos);
 }
 
 
@@ -469,7 +315,7 @@ compute_FOLLOWS (void)
 {
   int i;
 
-  digraph (includes);
+  relation_digraph (includes, ngotos, &F);
 
   for (i = 0; i < ngotos; i++)
     XFREE (includes[i]);
