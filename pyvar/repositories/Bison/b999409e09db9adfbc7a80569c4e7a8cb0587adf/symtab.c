@@ -194,11 +194,11 @@ symbol_redeclaration (symbol *s, const char *what, location first,
                       location second)
 {
   unsigned i = 0;
-  complain_at_indent (second, complaint, &i,
-                      _("%s redeclaration for %s"), what, s->tag);
+  complain_indent (&second, complaint, &i,
+                   _("%s redeclaration for %s"), what, s->tag);
   i += SUB_INDENT;
-  complain_at_indent (first, complaint, &i,
-                      _("previous declaration"));
+  complain_indent (&first, complaint, &i,
+                   _("previous declaration"));
 }
 
 static void
@@ -206,11 +206,11 @@ semantic_type_redeclaration (semantic_type *s, const char *what, location first,
                              location second)
 {
   unsigned i = 0;
-  complain_at_indent (second, complaint, &i,
-                      _("%s redeclaration for <%s>"), what, s->tag);
+  complain_indent (&second, complaint, &i,
+                   _("%s redeclaration for <%s>"), what, s->tag);
   i += SUB_INDENT;
-  complain_at_indent (first, complaint, &i,
-                      _("previous declaration"));
+  complain_indent (&first, complaint, &i,
+                   _("previous declaration"));
 }
 
 
@@ -566,13 +566,13 @@ user_token_number_redeclaration (int num, symbol *first, symbol *second)
       first = second;
       second = tmp;
     }
-  complain_at_indent (second->location, complaint, &i,
-                      _("user token number %d redeclaration for %s"),
-                      num, second->tag);
+  complain_indent (&second->location, complaint, &i,
+                   _("user token number %d redeclaration for %s"),
+                   num, second->tag);
   i += SUB_INDENT;
-  complain_at_indent (first->location, complaint, &i,
-                      _("previous declaration for %s"),
-                      first->tag);
+  complain_indent (&first->location, complaint, &i,
+                   _("previous declaration for %s"),
+                   first->tag);
 }
 
 /*--------------------------------------------------.
