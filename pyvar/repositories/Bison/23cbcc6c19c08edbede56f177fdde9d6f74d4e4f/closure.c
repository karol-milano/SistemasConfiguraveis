@@ -52,13 +52,19 @@ static int varsetsize;
 `-----------------*/
 
 static void
-print_closure (int n)
+print_closure (const char *title, short *array, size_t size)
 {
-  int i;
-  fprintf (stderr, "n = %d\n", n);
-  for (i = 0; i < itemsetsize; ++i)
-    fprintf (stderr, "   %d\n", itemset[i]);
-  fprintf (stderr, "\n\n");
+  size_t i;
+  fprintf (stderr, "Closure: %s\n", title);
+  for (i = 0; i < size; ++i)
+    {
+      short *rp;
+      fprintf (stderr, "  %2d: .", array[i]);
+      for (rp = &ritem[array[i]]; *rp > 0; ++rp)
+	fprintf (stderr, " %s", tags[*rp]);
+      fprintf (stderr, "  (rule %d)\n", -*rp);
+    }
+  fputs ("\n\n", stderr);
 }
 
 
@@ -194,12 +200,7 @@ closure (short *core, int n)
   int ruleno;
 
   if (trace_flag)
-    {
-      fprintf (stderr, "Entering closure (items = {");
-      for (c = 0; c < n; ++c)
-	fprintf (stderr, " %d ", core[c]);
-      fprintf (stderr, "})\n");
-    }
+    print_closure ("input", core, n);
 
   if (n == 0)
     {
@@ -241,7 +242,7 @@ closure (short *core, int n)
     }
 
   if (trace_flag)
-    print_closure (n);
+    print_closure ("output", itemset, itemsetsize);
 }
 
 
