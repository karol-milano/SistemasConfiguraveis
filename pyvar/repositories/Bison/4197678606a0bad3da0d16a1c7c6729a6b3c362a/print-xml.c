@@ -248,10 +248,11 @@ print_reductions (FILE *out, int level, state *s)
   int report = false;
   int i, j;
 
-  if (reds->num == 0) {
-    xml_puts (out, level, "<reductions/>");
-    return;
-  }
+  if (reds->num == 0)
+    {
+      xml_puts (out, level, "<reductions/>");
+      return;
+    }
 
   if (yydefact[s->number] != 0)
     default_reduction = &rules[yydefact[s->number] - 1];
