@@ -279,7 +279,7 @@ static void
 complain_symbol_redeclared (symbol *s, const char *what, location first,
                             location second)
 {
-  unsigned i = 0;
+  int i = 0;
   locations_sort (&first, &second);
   complain_indent (&second, complaint, &i,
                    _("%s redeclaration for %s"), what, s->tag);
@@ -292,7 +292,7 @@ static void
 complain_semantic_type_redeclared (semantic_type *s, const char *what, location first,
                                    location second)
 {
-  unsigned i = 0;
+  int i = 0;
   locations_sort (&first, &second);
   complain_indent (&second, complaint, &i,
                    _("%s redeclaration for <%s>"), what, s->tag);
@@ -304,7 +304,7 @@ complain_semantic_type_redeclared (semantic_type *s, const char *what, location
 static void
 complain_class_redeclared (symbol *sym, symbol_class class, location second)
 {
-  unsigned i = 0;
+  int i = 0;
   complain_indent (&second, complaint, &i,
                    class == token_sym
                    ? _("symbol %s redeclared as a token")
@@ -463,7 +463,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
         {
           if (s->status == declared)
             {
-              unsigned i = 0;
+              int i = 0;
               complain_indent (&loc, Wother, &i,
                                _("symbol %s redeclared"), sym->tag);
               i += SUB_INDENT;
@@ -668,7 +668,7 @@ symbol_pack_processor (void *this, void *null ATTRIBUTE_UNUSED)
 static void
 complain_user_token_number_redeclared (int num, symbol *first, symbol *second)
 {
-  unsigned i = 0;
+  int i = 0;
   symbols_sort (&first, &second);
   complain_indent (&second->location, complaint, &i,
                    _("user token number %d redeclaration for %s"),
