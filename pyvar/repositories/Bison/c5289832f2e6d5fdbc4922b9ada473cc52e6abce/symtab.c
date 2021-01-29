@@ -147,7 +147,7 @@ semantic_type_new (uniqstr tag, const location *loc)
     fprintf (f, " %s { %s }", #Attr, s->props[Attr].code)
 
 void
-symbol_print (symbol *s, FILE *f)
+symbol_print (symbol const *s, FILE *f)
 {
   if (s)
     {
