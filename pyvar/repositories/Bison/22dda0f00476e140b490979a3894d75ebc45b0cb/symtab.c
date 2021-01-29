@@ -83,7 +83,7 @@ symbol_new (uniqstr tag, location loc)
     fprintf (stderr, " %s { %s }", #Attr, s->Attr)
 
 void
-symbol_print (FILE *f, symbol *s)
+symbol_print (symbol *s, FILE *f)
 {
   fprintf (stderr, "\"%s\"", s->tag);
   SYMBOL_ATTR_PRINT (type_name);
