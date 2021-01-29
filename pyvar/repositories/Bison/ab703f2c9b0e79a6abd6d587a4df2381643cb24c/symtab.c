@@ -80,12 +80,12 @@ symbol_new (uniqstr tag, location loc)
 
 #define SYMBOL_ATTR_PRINT(Attr)				\
   if (s->Attr)						\
-    fprintf (stderr, " %s { %s }", #Attr, s->Attr)
+    fprintf (f, " %s { %s }", #Attr, s->Attr)
 
 void
 symbol_print (symbol *s, FILE *f)
 {
-  fprintf (stderr, "\"%s\"", s->tag);
+  fprintf (f, "\"%s\"", s->tag);
   SYMBOL_ATTR_PRINT (type_name);
   SYMBOL_ATTR_PRINT (destructor);
   SYMBOL_ATTR_PRINT (printer);
