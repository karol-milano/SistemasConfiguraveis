@@ -153,13 +153,13 @@ symbol_print (symbol const *s, FILE *f)
 {
   if (s)
     {
-      fprintf (f, "\"%s\"", s->tag);
+      fputs (s->tag, f);
       SYMBOL_ATTR_PRINT (type_name);
       SYMBOL_CODE_PRINT (destructor);
       SYMBOL_CODE_PRINT (printer);
     }
   else
-    fprintf (f, "<NULL>");
+    fputs ("<NULL>", f);
 }
 
 #undef SYMBOL_ATTR_PRINT
