@@ -100,6 +100,28 @@ symbol_new (uniqstr tag, location loc)
   return res;
 }
 
+/* If needed, swap first and second so that first has the earliest
+   location (according to location_cmp).
+
+   Many symbol features (e.g., user token numbers) are not assigned
+   during the parsing, but in a second step, via a traversal of the
+   symbol table sorted on tag.
+
+   However, error messages make more sense if we keep the first
+   declaration first.
+*/
+
+static
+void symbols_sort (symbol **first, symbol **second)
+{
+  if (0 < location_cmp ((*first)->location, (*second)->location))
+    {
+      symbol* tmp = *first;
+      *first = *second;
+      *second = tmp;
+    }
+}
+
 char const *
 code_props_type_string (code_props_type kind)
 {
@@ -587,17 +609,7 @@ static void
 user_token_number_redeclaration (int num, symbol *first, symbol *second)
 {
   unsigned i = 0;
-  /* User token numbers are not assigned during the parsing, but in a
-     second step, via a traversal of the symbol table sorted on tag.
-
-     However, error messages make more sense if we keep the first
-     declaration first.  */
-  if (location_cmp (first->location, second->location) > 0)
-    {
-      symbol* tmp = first;
-      first = second;
-      second = tmp;
-    }
+  symbols_sort (&first, &second);
   complain_indent (&second->location, complaint, &i,
                    _("user token number %d redeclaration for %s"),
                    num, second->tag);
