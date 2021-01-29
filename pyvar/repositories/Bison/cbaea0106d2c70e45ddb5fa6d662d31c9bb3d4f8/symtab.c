@@ -150,16 +150,20 @@ static void
 symbol_redeclaration (symbol *s, const char *what, location first,
                       location second)
 {
-  complain_at (second, _("%s redeclaration for %s"), what, s->tag);
-  complain_at (first, _("previous declaration"));
+  unsigned i = 0;
+  complain_at_indent (second, &i, _("%s redeclaration for %s"), what, s->tag);
+  i += SUB_INDENT;
+  complain_at_indent (first, &i, _("previous declaration"));
 }
 
 static void
 semantic_type_redeclaration (semantic_type *s, const char *what, location first,
                              location second)
 {
-  complain_at (second, _("%s redeclaration for <%s>"), what, s->tag);
-  complain_at (first, _("previous declaration"));
+  unsigned i = 0;
+  complain_at_indent (second, &i, _("%s redeclaration for <%s>"), what, s->tag);
+  i += SUB_INDENT;
+  complain_at_indent (first, &i, _("previous declaration"));
 }
 
 
@@ -515,6 +519,7 @@ symbol_pack_processor (void *this, void *null ATTRIBUTE_UNUSED)
 static void
 user_token_number_redeclaration (int num, symbol *first, symbol *second)
 {
+  unsigned i = 0;
   /* User token numbers are not assigned during the parsing, but in a
      second step, via a traversal of the symbol table sorted on tag.
 
@@ -526,11 +531,12 @@ user_token_number_redeclaration (int num, symbol *first, symbol *second)
       first = second;
       second = tmp;
     }
-  complain_at (second->location,
-               _("user token number %d redeclaration for %s"),
-               num, second->tag);
-  complain_at (first->location, _("previous declaration for %s"),
-               first->tag);
+  complain_at_indent (second->location, &i,
+                      _("user token number %d redeclaration for %s"),
+                      num, second->tag);
+  complain_at_indent (first->location, &i,
+                      _("previous declaration for %s"),
+                      first->tag);
 }
 
 /*--------------------------------------------------.
@@ -923,10 +929,12 @@ default_tagged_destructor_set (code_props const *destructor)
 {
   if (default_tagged_destructor.code)
     {
-      complain_at (destructor->location,
-                   _("redeclaration for default tagged %%destructor"));
-      complain_at (default_tagged_destructor.location,
-		   _("previous declaration"));
+      unsigned i = 0;
+      complain_at_indent (destructor->location, &i,
+                          _("redeclaration for default tagged %%destructor"));
+      i += SUB_INDENT;
+      complain_at_indent (default_tagged_destructor.location, &i,
+		          _("previous declaration"));
     }
   default_tagged_destructor = *destructor;
 }
@@ -936,10 +944,12 @@ default_tagless_destructor_set (code_props const *destructor)
 {
   if (default_tagless_destructor.code)
     {
-      complain_at (destructor->location,
-                   _("redeclaration for default tagless %%destructor"));
-      complain_at (default_tagless_destructor.location,
-		   _("previous declaration"));
+      unsigned i = 0;
+      complain_at_indent (destructor->location, &i,
+                          _("redeclaration for default tagless %%destructor"));
+      i += SUB_INDENT;
+      complain_at_indent (default_tagless_destructor.location, &i,
+                          _("previous declaration"));
     }
   default_tagless_destructor = *destructor;
 }
@@ -949,10 +959,12 @@ default_tagged_printer_set (code_props const *printer)
 {
   if (default_tagged_printer.code)
     {
-      complain_at (printer->location,
-                   _("redeclaration for default tagged %%printer"));
-      complain_at (default_tagged_printer.location,
-		   _("previous declaration"));
+      unsigned i = 0;
+      complain_at_indent (printer->location, &i,
+                          _("redeclaration for default tagged %%printer"));
+      i += SUB_INDENT;
+      complain_at_indent (default_tagged_printer.location, &i,
+		          _("previous declaration"));
     }
   default_tagged_printer = *printer;
 }
@@ -962,10 +974,12 @@ default_tagless_printer_set (code_props const *printer)
 {
   if (default_tagless_printer.code)
     {
-      complain_at (printer->location,
-                   _("redeclaration for default tagless %%printer"));
-      complain_at (default_tagless_printer.location,
-		   _("previous declaration"));
+      unsigned i = 0;
+      complain_at_indent (printer->location, &i,
+                          _("redeclaration for default tagless %%printer"));
+      i += SUB_INDENT;
+      complain_at_indent (default_tagless_printer.location, &i,
+		          _("previous declaration"));
     }
   default_tagless_printer = *printer;
 }
