@@ -99,7 +99,7 @@ traverse (relation_node i)
 
 
 void
-relation_digraph (relation r, relation_node size, bitsetv *function)
+relation_digraph (relation r, relation_node size, bitsetv function)
 {
   infinity = size + 2;
   indexes = xcalloc (size + 1, sizeof *indexes);
@@ -107,7 +107,7 @@ relation_digraph (relation r, relation_node size, bitsetv *function)
   top = 0;
 
   R = r;
-  F = *function;
+  F = function;
 
   for (relation_node i = 0; i < size; i++)
     if (indexes[i] == 0 && R[i])
@@ -116,7 +116,7 @@ relation_digraph (relation r, relation_node size, bitsetv *function)
   free (indexes);
   free (vertices);
 
-  *function = F;
+  function = F;
 }
 
 
