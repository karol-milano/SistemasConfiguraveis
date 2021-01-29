@@ -32,6 +32,8 @@ int ntokens;
 int nvars;
 
 short *ritem = NULL;
+int nritems;
+
 rule_t *rule_table = NULL;
 short *rprec = NULL;
 short *rprecsym = NULL;
@@ -60,8 +62,8 @@ ritem_print (FILE *out)
 {
   int i;
   fputs ("RITEM\n", out);
-  for (i = 0; ritem[i]; ++i)
-    if (ritem[i] > 0)
+  for (i = 0; i < nritems; ++i)
+    if (ritem[i] >= 0)
       fprintf (out, "  %s", tags[ritem[i]]);
     else
       fprintf (out, "  (rule %d)\n", -ritem[i]);
