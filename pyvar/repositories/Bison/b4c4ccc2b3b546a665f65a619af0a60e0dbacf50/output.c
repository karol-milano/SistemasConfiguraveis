@@ -202,14 +202,18 @@ output_gram (void)
   muscle_insert ("prhs", obstack_finish (&format_obstack));
 
   {
-    short *yyrhs;
-    int i;
-
-    yyrhs = XMALLOC (short, nritems);
-
-    for (i = 1; i < nritems; ++i)
-      yyrhs[i] = ritem[i] >= 0 ? ritem[i] : -1;
+    short *rhsp;
+    int r;
+    int i = 0;
+    short *yyrhs = XMALLOC (short, nritems);
 
+    for (r = 1; r < nrules + 1; ++r)
+      {
+	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+	  yyrhs[i++] = *rhsp;
+	yyrhs[i++] = -1;
+      }
+    assert (i == nritems);
     output_table_data (&format_obstack, yyrhs,
 		       ritem[0], 1, nritems);
     muscle_insert ("rhs", obstack_finish (&format_obstack));
