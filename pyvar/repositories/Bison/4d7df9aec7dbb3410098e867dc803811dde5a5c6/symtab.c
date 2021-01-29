@@ -210,11 +210,11 @@ semantic_type_new (uniqstr tag, const location *loc)
 `-----------------*/
 
 #define SYMBOL_ATTR_PRINT(Attr)                         \
-  if (s->content->Attr)                                 \
+  if (s->content && s->content->Attr)                   \
     fprintf (f, " %s { %s }", #Attr, s->content->Attr)
 
 #define SYMBOL_CODE_PRINT(Attr)                                         \
-  if (s->content->props[Attr].code)                                     \
+  if (s->content && s->content->props[Attr].code)                       \
     fprintf (f, " %s { %s }", #Attr, s->content->props[Attr].code)
 
 void
