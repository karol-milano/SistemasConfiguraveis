@@ -85,10 +85,15 @@ symbol_new (uniqstr tag, location loc)
 void
 symbol_print (symbol *s, FILE *f)
 {
-  fprintf (f, "\"%s\"", s->tag);
-  SYMBOL_ATTR_PRINT (type_name);
-  SYMBOL_ATTR_PRINT (destructor);
-  SYMBOL_ATTR_PRINT (printer);
+  if (s)
+    {
+      fprintf (f, "\"%s\"", s->tag);
+      SYMBOL_ATTR_PRINT (type_name);
+      SYMBOL_ATTR_PRINT (destructor);
+      SYMBOL_ATTR_PRINT (printer);
+    }
+  else
+    fprintf (f, "<NULL>");
 }
 
 #undef SYMBOL_ATTR_PRINT
