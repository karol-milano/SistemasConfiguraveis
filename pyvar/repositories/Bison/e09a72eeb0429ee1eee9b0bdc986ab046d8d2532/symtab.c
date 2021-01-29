@@ -295,42 +295,29 @@ static void
 complain_symbol_redeclared (symbol *s, const char *what, location first,
                             location second)
 {
-  int i = 0;
   locations_sort (&first, &second);
-  complain_indent (&second, complaint, &i,
-                   _("%s redeclaration for %s"), what, s->tag);
-  i += SUB_INDENT;
-  complain_indent (&first, complaint, &i,
-                   _("previous declaration"));
+  complain (&second, complaint, _("%s redeclaration for %s"), what, s->tag);
+  subcomplain (&first, complaint, _("previous declaration"));
 }
 
 static void
 complain_semantic_type_redeclared (semantic_type *s, const char *what, location first,
                                    location second)
 {
-  int i = 0;
   locations_sort (&first, &second);
-  complain_indent (&second, complaint, &i,
-                   _("%s redeclaration for <%s>"), what, s->tag);
-  i += SUB_INDENT;
-  complain_indent (&first, complaint, &i,
-                   _("previous declaration"));
+  complain (&second, complaint, _("%s redeclaration for <%s>"), what, s->tag);
+  subcomplain (&first, complaint, _("previous declaration"));
 }
 
 static void
 complain_class_redeclared (symbol *sym, symbol_class class, location second)
 {
-  int i = 0;
-  complain_indent (&second, complaint, &i,
-                   class == token_sym
-                   ? _("symbol %s redeclared as a token")
-                   : _("symbol %s redeclared as a nonterminal"), sym->tag);
+  complain (&second, complaint,
+            class == token_sym
+            ? _("symbol %s redeclared as a token")
+            : _("symbol %s redeclared as a nonterminal"), sym->tag);
   if (!location_empty (sym->location))
-    {
-      i += SUB_INDENT;
-      complain_indent (&sym->location, complaint, &i,
-                       _("previous definition"));
-    }
+    subcomplain (&sym->location, complaint, _("previous definition"));
 }
 
 static const symbol *
@@ -546,12 +533,10 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
         {
           if (s->status == declared)
             {
-              int i = 0;
-              complain_indent (&loc, Wother, &i,
-                               _("symbol %s redeclared"), sym->tag);
-              i += SUB_INDENT;
-              complain_indent (&sym->location, Wother, &i,
-                               _("previous declaration"));
+              complain (&loc, Wother,
+                        _("symbol %s redeclared"), sym->tag);
+              subcomplain (&sym->location, Wother,
+                           _("previous declaration"));
             }
           else
             s->status = declared;
@@ -731,15 +716,13 @@ symbol_pack (symbol *this)
 static void
 complain_user_token_number_redeclared (int num, symbol *first, symbol *second)
 {
-  int i = 0;
   symbols_sort (&first, &second);
-  complain_indent (&second->location, complaint, &i,
-                   _("user token number %d redeclaration for %s"),
-                   num, second->tag);
-  i += SUB_INDENT;
-  complain_indent (&first->location, complaint, &i,
-                   _("previous declaration for %s"),
-                   first->tag);
+  complain (&second->location, complaint,
+            _("user token number %d redeclaration for %s"),
+            num, second->tag);
+  subcomplain (&first->location, complaint,
+               _("previous declaration for %s"),
+               first->tag);
 }
 
 /*--------------------------------------------------.
