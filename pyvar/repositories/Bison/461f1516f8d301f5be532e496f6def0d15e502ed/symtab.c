@@ -122,6 +122,19 @@ void symbols_sort (symbol **first, symbol **second)
     }
 }
 
+/* Likewise, for locations.  */
+
+static
+void locations_sort (location *first, location *second)
+{
+  if (0 < location_cmp (*first, *second))
+    {
+      location tmp = *first;
+      *first = *second;
+      *second = tmp;
+    }
+}
+
 char const *
 code_props_type_string (code_props_type kind)
 {
@@ -232,6 +245,7 @@ symbol_redeclaration (symbol *s, const char *what, location first,
                       location second)
 {
   unsigned i = 0;
+  locations_sort (&first, &second);
   complain_indent (&second, complaint, &i,
                    _("%s redeclaration for %s"), what, s->tag);
   i += SUB_INDENT;
@@ -244,6 +258,7 @@ semantic_type_redeclaration (semantic_type *s, const char *what, location first,
                              location second)
 {
   unsigned i = 0;
+  locations_sort (&first, &second);
   complain_indent (&second, complaint, &i,
                    _("%s redeclaration for <%s>"), what, s->tag);
   i += SUB_INDENT;
