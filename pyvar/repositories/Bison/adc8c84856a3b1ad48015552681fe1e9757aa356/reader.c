@@ -1692,6 +1692,10 @@ packgram (void)
   int ruleno;
   symbol_list *p;
 
+  /* We use short to index items.  */
+  if (nitems >= MAXSHORT)
+    fatal (_("too many items (max %d)"), MAXSHORT);
+
   ritem = XCALLOC (short, nitems + 1);
   rule_table = XCALLOC (rule_t, nrules) - 1;
 
