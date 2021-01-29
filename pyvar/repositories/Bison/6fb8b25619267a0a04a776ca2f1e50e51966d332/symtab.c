@@ -75,8 +75,8 @@ symbol_new (uniqstr tag, location loc)
   /* If the tag is not a string (starts with a double quote), check
      that it is valid for Yacc. */
   if (tag[0] != '\"' && tag[0] != '\'' && strchr (tag, '-'))
-    yacc_at (loc, _("POSIX Yacc forbids dashes in symbol names: %s"),
-             tag);
+    complain_at (loc, Wyacc,
+                 _("POSIX Yacc forbids dashes in symbol names: %s"), tag);
 
   res->tag = tag;
   res->location = loc;
@@ -95,8 +95,8 @@ symbol_new (uniqstr tag, location loc)
   res->status = undeclared;
 
   if (nsyms == SYMBOL_NUMBER_MAXIMUM)
-    fatal (_("too many symbols in input grammar (limit is %d)"),
-           SYMBOL_NUMBER_MAXIMUM);
+    complain (fatal, _("too many symbols in input grammar (limit is %d)"),
+              SYMBOL_NUMBER_MAXIMUM);
   nsyms++;
   return res;
 }
@@ -207,16 +207,16 @@ static void
 symbol_redeclaration (symbol *s, const char *what, location first,
                       location second)
 {
-  complain_at (second, _("%s redeclaration for %s"), what, s->tag);
-  complain_at (first, _("previous declaration"));
+  complain_at (second, complaint, _("%s redeclaration for %s"), what, s->tag);
+  complain_at (first, complaint, _("previous declaration"));
 }
 
 static void
 semantic_type_redeclaration (semantic_type *s, const char *what, location first,
                              location second)
 {
-  complain_at (second, _("%s redeclaration for <%s>"), what, s->tag);
-  complain_at (first, _("previous declaration"));
+  complain_at (second, complaint, _("%s redeclaration for <%s>"), what, s->tag);
+  complain_at (first, complaint, _("previous declaration"));
 }
 
 
@@ -333,7 +333,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
   bool warned = false;
   if (sym->class != unknown_sym && sym->class != class)
     {
-      complain_at (loc, _("symbol %s redefined"), sym->tag);
+      complain_at (loc, complaint, _("symbol %s redefined"), sym->tag);
       // Don't report both "redefined" and "redeclared".
       warned = true;
     }
@@ -348,7 +348,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
   if (declaring)
     {
       if (sym->status == declared && !warned)
-        warn_at (loc, _("symbol %s redeclared"), sym->tag);
+        complain_at (loc, Wother, _("symbol %s redeclared"), sym->tag);
       sym->status = declared;
     }
 }
@@ -369,7 +369,8 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
     user_token_numberp = &sym->alias->user_token_number;
   if (*user_token_numberp != USER_NUMBER_UNDEFINED
       && *user_token_numberp != user_token_number)
-    complain_at (loc, _("redefining user token number of %s"), sym->tag);
+    complain_at (loc, complaint, _("redefining user token number of %s"),
+                 sym->tag);
 
   *user_token_numberp = user_token_number;
   /* User defined $end token? */
@@ -398,17 +399,17 @@ symbol_check_defined (symbol *sym)
       switch (sym->status)
         {
         case used:
-          warn_at (sym->location,
+          complain_at (sym->location, Wother,
                    _("symbol %s is used, but is not defined as a token"
                      " and has no rules"),
                    sym->tag);
           break;
         case undeclared:
         case needed:
-          complain_at (sym->location,
-                       _("symbol %s is used, but is not defined as a token"
-                         " and has no rules"),
-                       sym->tag);
+          complain_at (sym->location, complaint,
+                    _("symbol %s is used, but is not defined as a token"
+                      " and has no rules"),
+                    sym->tag);
           break;
         case declared:
           /* If declared, then sym->class != unknown_sym. */
@@ -448,14 +449,14 @@ semantic_type_check_defined (semantic_type *sem_type)
       for (int i = 0; i < 2; ++i)
         if (sem_type->props[i].kind != CODE_PROPS_NONE
             && ! sem_type->props[i].is_used)
-          warn_at (sem_type->location,
+          complain_at (sem_type->location, Wother,
                    _("useless %s for type <%s>"),
                    code_props_type_string (i), sem_type->tag);
     }
   else
-    warn_at (sem_type->location,
-             _("type <%s> is used, but is not associated to any symbol"),
-             sem_type->tag);
+    complain_at (sem_type->location, Wother,
+                 _("type <%s> is used, but is not associated to any symbol"),
+                 sem_type->tag);
 
   return true;
 }
@@ -478,11 +479,11 @@ void
 symbol_make_alias (symbol *sym, symbol *str, location loc)
 {
   if (str->alias)
-    warn_at (loc, _("symbol %s used more than once as a literal string"),
-             str->tag);
+    complain_at (loc, Wother,
+              _("symbol %s used more than once as a literal string"), str->tag);
   else if (sym->alias)
-    warn_at (loc, _("symbol %s given more than one literal string"),
-             sym->tag);
+    complain_at (loc, Wother,
+              _("symbol %s given more than one literal string"), sym->tag);
   else
     {
       str->class = token_sym;
@@ -586,10 +587,10 @@ user_token_number_redeclaration (int num, symbol *first, symbol *second)
       first = second;
       second = tmp;
     }
-  complain_at (second->location,
+  complain_at (second->location, complaint,
                _("user token number %d redeclaration for %s"),
                num, second->tag);
-  complain_at (first->location, _("previous declaration for %s"),
+  complain_at (first->location, complaint, _("previous declaration for %s"),
                first->tag);
 }
 
@@ -610,10 +611,10 @@ symbol_translation (symbol *this)
           (this->user_token_number,
            symbols[token_translations[this->user_token_number]],
            this);
-
+      
       token_translations[this->user_token_number] = this->number;
     }
-
+  
   return true;
 }
 
@@ -968,13 +969,13 @@ symbols_pack (void)
   symbols_token_translations_init ();
 
   if (startsymbol->class == unknown_sym)
-    fatal_at (startsymbol_location,
-              _("the start symbol %s is undefined"),
-              startsymbol->tag);
+    complain_at (startsymbol_location, fatal,
+                 _("the start symbol %s is undefined"),
+                 startsymbol->tag);
   else if (startsymbol->class == token_sym)
-    fatal_at (startsymbol_location,
-              _("the start symbol %s is a token"),
-              startsymbol->tag);
+    complain_at (startsymbol_location, fatal,
+                 _("the start symbol %s is a token"),
+                 startsymbol->tag);
 }
 
 
@@ -987,10 +988,10 @@ default_tagged_code_props_set (code_props_type kind, code_props const *code)
 {
   if (default_tagged_code_props[kind].code)
     {
-      complain_at (code->location,
+      complain_at (code->location, complaint,
                    _("redeclaration for default tagged %s"),
                    code_props_type_string (kind));
-      complain_at (default_tagged_code_props[kind].location,
+      complain_at (default_tagged_code_props[kind].location, complaint,
                    _("previous declaration"));
     }
   default_tagged_code_props[kind] = *code;
@@ -1001,10 +1002,10 @@ default_tagless_code_props_set (code_props_type kind, code_props const *code)
 {
   if (default_tagless_code_props[kind].code)
     {
-      complain_at (code->location,
+      complain_at (code->location, complaint,
                    _("redeclaration for default tagless %s"),
                    code_props_type_string (kind));
-      complain_at (default_tagless_code_props[kind].location,
+      complain_at (default_tagless_code_props[kind].location, complaint,
                    _("previous declaration"));
     }
   default_tagless_code_props[kind] = *code;
