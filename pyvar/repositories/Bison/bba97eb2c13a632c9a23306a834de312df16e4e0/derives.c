@@ -68,14 +68,13 @@ set_derives (void)
 
   p = delts;
   for (i = nrules; i > 0; i--)
-    if (rules[i].useful)
-      {
-	int lhs = rules[i].lhs;
-	p->next = dset[lhs];
-	p->value = i;
-	dset[lhs] = p;
-	p++;
-      }
+    {
+      int lhs = rules[i].lhs->number;
+      p->next = dset[lhs];
+      p->value = i;
+      dset[lhs] = p;
+      p++;
+    }
 
   derives = XCALLOC (short *, nvars) - ntokens;
   q = XCALLOC (short, nvars + nrules);
