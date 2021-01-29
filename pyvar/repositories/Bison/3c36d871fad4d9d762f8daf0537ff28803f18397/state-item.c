@@ -482,6 +482,12 @@ state_item_print (const state_item *si, FILE *out, const char *prefix)
   putc ('\n', out);
 }
 
+const rule*
+state_item_rule (const state_item *si)
+{
+  return item_rule (si->item);
+}
+
 /**
  * Report the state_item graph
  */
