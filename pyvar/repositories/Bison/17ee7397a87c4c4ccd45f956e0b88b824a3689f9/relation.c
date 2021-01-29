@@ -1,5 +1,5 @@
 /* Binary relations.
-   Copyright (C) 2002  Free Software Foundation, Inc.
+   Copyright (C) 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -19,21 +19,23 @@
    Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
-#include "bitsetv.h"
-#include "relation.h"
+
+#include <bitsetv.h>
+
 #include "getargs.h"
+#include "relation.h"
 
 void
-relation_print (relation_t relation, size_t size, FILE *out)
+relation_print (relation r, size_t size, FILE *out)
 {
   unsigned i, j;
 
   for (i = 0; i < size; ++i)
     {
       fprintf (out, "%3d: ", i);
-      if (relation[i])
-	for (j = 0; relation[i][j] != -1; ++j)
-	  fprintf (out, "%3d ", relation[i][j]);
+      if (r[i])
+	for (j = 0; r[i][j] != -1; ++j)
+	  fprintf (out, "%3d ", r[i][j]);
       fputc ('\n', out);
     }
   fputc ('\n', out);
@@ -47,9 +49,9 @@ relation_print (relation_t relation, size_t size, FILE *out)
 | two.                                                           |
 `---------------------------------------------------------------*/
 
-static relation_t R;
-static relation_nodes_t INDEX;
-static relation_nodes_t VERTICES;
+static relation R;
+static relation_nodes INDEX;
+static relation_nodes VERTICES;
 static int top;
 static int infinity;
 static bitsetv F;
@@ -90,17 +92,16 @@ traverse (int i)
 
 
 void
-relation_digraph (relation_t relation, size_t size,
-		  bitsetv *function)
+relation_digraph (relation r, size_t size, bitsetv *function)
 {
   unsigned i;
 
   infinity = size + 2;
-  INDEX = XCALLOC (relation_node_t, size + 1);
-  VERTICES = XCALLOC (relation_node_t, size + 1);
+  INDEX = XCALLOC (relation_node, size + 1);
+  VERTICES = XCALLOC (relation_node, size + 1);
   top = 0;
 
-  R = relation;
+  R = r;
   F = *function;
 
   for (i = 0; i < size; i++)
@@ -122,12 +123,12 @@ relation_digraph (relation_t relation, size_t size,
 `-------------------------------------------*/
 
 void
-relation_transpose (relation_t *R_arg, int n)
+relation_transpose (relation *R_arg, int n)
 {
   /* The result. */
-  relation_t new_R = XCALLOC (relation_nodes_t, n);
+  relation new_R = XCALLOC (relation_nodes, n);
   /* END_R[I] -- next entry of NEW_R[I]. */
-  relation_t end_R = XCALLOC (relation_nodes_t, n);
+  relation end_R = XCALLOC (relation_nodes, n);
   /* NEDGES[I] -- total size of NEW_R[I]. */
   int *nedges = XCALLOC (int, n);
   int i, j;
@@ -148,7 +149,7 @@ relation_transpose (relation_t *R_arg, int n)
   for (i = 0; i < n; i++)
     if (nedges[i] > 0)
       {
-	relation_node_t *sp = XCALLOC (relation_node_t, nedges[i] + 1);
+	relation_node *sp = XCALLOC (relation_node, nedges[i] + 1);
 	sp[nedges[i]] = -1;
 	new_R[i] = sp;
 	end_R[i] = sp;
