@@ -74,6 +74,25 @@ symbol_new (uniqstr tag, location loc)
 }
 
 
+/*-----------------.
+| Print a symbol.  |
+`-----------------*/
+
+#define SYMBOL_ATTR_PRINT(Attr)				\
+  if (s->Attr)						\
+    fprintf (stderr, " %s { %s }", #Attr, s->Attr)
+
+void
+symbol_print (FILE *f, symbol *s)
+{
+  fprintf (stderr, "\"%s\"", s->tag);
+  SYMBOL_ATTR_PRINT (type_name);
+  SYMBOL_ATTR_PRINT (destructor);
+  SYMBOL_ATTR_PRINT (printer);
+}
+
+#undef SYMBOL_ATTR_PRINT
+
 /*------------------------------------------------------------------.
 | Complain that S's WHAT is redeclared at SECOND, and was first set |
 | at FIRST.                                                         |
