@@ -63,7 +63,6 @@ void
 set_derives (void)
 {
   int i;
-  int lhs;
   shorts *p;
   short *q;
   shorts **dset;
@@ -74,16 +73,14 @@ set_derives (void)
 
   p = delts;
   for (i = nrules; i > 0; i--)
-    {
-      lhs = rule_table[i].lhs;
-      if (lhs >= 0)
-	{
-	  p->next = dset[lhs];
-	  p->value = i;
-	  dset[lhs] = p;
-	  p++;
-	}
-    }
+    if (rule_table[i].useful)
+      {
+	int lhs = rule_table[i].lhs;
+	p->next = dset[lhs];
+	p->value = i;
+	dset[lhs] = p;
+	p++;
+      }
 
   derives = XCALLOC (short *, nvars) - ntokens;
   q = XCALLOC (short, nvars + nrules);
