@@ -111,6 +111,37 @@ bitsetv_ones (bsetv)
 }
 
 
+/* Given a vector BSETV of N bitsets of size N, modify its contents to
+   be the transitive closure of what was given.  */
+void
+bitsetv_transitive_closure (bsetv)
+     bitset *bsetv;
+{
+  unsigned int i;
+  unsigned int j;
+
+  for (i = 0; bsetv[i]; i++)
+    for (j = 0; bsetv[j]; j++)
+      if (bitset_test (bsetv[j], i))
+        bitset_or (bsetv[j], bsetv[j], bsetv[i]);
+}
+
+
+/* Given a vector BSETV of N bitsets of size N, modify its contents to
+   be the reflexive transitive closure of what was given.  This is 
+   the same as transitive closure but with all bits on the diagonal
+   of the bit matrix set.  */
+void
+bitsetv_reflexive_transitive_closure (bitsetv bsetv)
+{
+  int i;
+
+  bitsetv_transitive_closure (bsetv);
+  for (i = 0; bsetv[i]; i++)
+    bitset_set (bsetv[i], i);
+}
+
+
 /* Dump the contents of a bitset vector BSETV with N_VECS elements to
    FILE.  */
 void
