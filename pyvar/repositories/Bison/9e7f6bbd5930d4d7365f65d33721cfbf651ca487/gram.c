@@ -78,14 +78,14 @@ ritem_print (FILE *out)
 size_t
 ritem_longest_rhs (void)
 {
-  short *itemp;
   int length;
   int max;
+  int i;
 
   length = 0;
   max = 0;
-  for (itemp = ritem; *itemp; itemp++)
-    if (*itemp > 0)
+  for (i = 0; i < nritems; ++i)
+    if (ritem[i] >= 0)
       {
 	length++;
       }
