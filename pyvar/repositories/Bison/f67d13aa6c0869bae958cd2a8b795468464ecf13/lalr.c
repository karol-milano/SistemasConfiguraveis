@@ -31,6 +31,7 @@
 #include "lalr.h"
 #include "nullable.h"
 #include "derives.h"
+#include "getargs.h"
 
 /* All the decorated states, indexed by the state number.  Warning:
    there is a state_TABLE in LR0.c, but it is different and static.
@@ -404,59 +405,87 @@ add_lookback_edge (int stateno, int ruleno, int gotono)
 }
 
 
+static void
+matrix_print (FILE *out, short **matrix, int n)
+{
+  int i, j;
+
+  for (i = 0; i < n; ++i)
+    {
+      fprintf (out, "%3d: ", i);
+      if (matrix[i])
+	for (j = 0; matrix[i][j] != -1; ++j)
+	  fprintf (out, "%3d ", matrix[i][j]);
+      fputc ('\n', out);
+    }
+  fputc ('\n', out);
+}
+
 /*-------------------------------------------------------------------.
 | Return the transpose of R_ARG, of size N.  Destroy R_ARG, as it is |
 | replaced with the result.                                          |
+|                                                                    |
+| R_ARG[I] is NULL or a -1 terminated list of numbers.               |
+|                                                                    |
+| RESULT[NUM] is NULL or the -1 terminated list of the I such as NUM |
+| is in R_ARG[I].                                                    |
 `-------------------------------------------------------------------*/
 
 static short **
 transpose (short **R_arg, int n)
 {
-  short **new_R;
-  short **temp_R;
-  short *nedges;
-  int i;
-
-  nedges = XCALLOC (short, n);
-
-  for (i = 0; i < n; i++)
+  /* The result. */
+  short **new_R = XCALLOC (short *, n);
+  /* END_R[I] -- next entry of NEW_R[I]. */
+  short **end_R = XCALLOC (short *, n);
+  /* NEDGES[I] -- total size of NEW_R[I]. */
+  short *nedges = XCALLOC (short, n);
+  int i, j;
+
+  if (trace_flag)
     {
-      short *sp = R_arg[i];
-      if (sp)
-	{
-	  while (*sp >= 0)
-	    nedges[*sp++]++;
-	}
+      fputs ("transpose: input\n", stderr);
+      matrix_print (stderr, R_arg, n);
     }
 
-  new_R = XCALLOC (short *, n);
-  temp_R = XCALLOC (short *, n);
+  /* Count. */
+  for (i = 0; i < n; i++)
+    if (R_arg[i])
+      for (j = 0; R_arg[i][j] >= 0; ++j)
+	++nedges[R_arg[i][j]];
 
+  /* Allocate. */
   for (i = 0; i < n; i++)
     if (nedges[i] > 0)
       {
 	short *sp = XCALLOC (short, nedges[i] + 1);
-	new_R[i] = sp;
-	temp_R[i] = sp;
 	sp[nedges[i]] = -1;
+	new_R[i] = sp;
+	end_R[i] = sp;
       }
 
-  XFREE (nedges);
-
+  /* Store. */
   for (i = 0; i < n; i++)
-    {
-      short *sp = R_arg[i];
-      if (sp)
-	while (*sp >= 0)
-	  *temp_R[*sp++]++ = i;
-    }
+    if (R_arg[i])
+      for (j = 0; R_arg[i][j] >= 0; ++j)
+	{
+	  *end_R[R_arg[i][j]] = i;
+	  ++end_R[R_arg[i][j]];
+	}
 
-  XFREE (temp_R);
+  free (nedges);
+  free (end_R);
 
   /* Free the input: it is replaced with the result. */
   for (i = 0; i < n; i++)
     XFREE (R_arg[i]);
-  XFREE (R_arg);
+  free (R_arg);
+
+  if (trace_flag)
+    {
+      fputs ("transpose: output\n", stderr);
+      matrix_print (stderr, new_R, n);
+    }
 
   return new_R;
 }
