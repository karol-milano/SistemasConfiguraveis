@@ -61,8 +61,8 @@ symbol_new (uniqstr tag, location loc)
   /* If the tag is not a string (starts with a double quote), check
      that it is valid for Yacc. */
   if (tag[0] != '\"' && tag[0] != '\'' && strchr (tag, '-'))
-    complain_at (loc, Wyacc,
-                 _("POSIX Yacc forbids dashes in symbol names: %s"), tag);
+    complain (&loc, Wyacc,
+              _("POSIX Yacc forbids dashes in symbol names: %s"), tag);
 
   res->tag = tag;
   res->location = loc;
@@ -81,7 +81,7 @@ symbol_new (uniqstr tag, location loc)
   res->status = undeclared;
 
   if (nsyms == SYMBOL_NUMBER_MAXIMUM)
-    complain (fatal, _("too many symbols in input grammar (limit is %d)"),
+    complain (NULL, fatal, _("too many symbols in input grammar (limit is %d)"),
               SYMBOL_NUMBER_MAXIMUM);
   nsyms++;
   return res;
@@ -328,7 +328,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
   bool warned = false;
   if (sym->class != unknown_sym && sym->class != class)
     {
-      complain_at (loc, complaint, _("symbol %s redefined"), sym->tag);
+      complain (&loc, complaint, _("symbol %s redefined"), sym->tag);
       // Don't report both "redefined" and "redeclared".
       warned = true;
     }
@@ -343,7 +343,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
   if (declaring)
     {
       if (sym->status == declared && !warned)
-        complain_at (loc, Wother, _("symbol %s redeclared"), sym->tag);
+        complain (&loc, Wother, _("symbol %s redeclared"), sym->tag);
       sym->status = declared;
     }
 }
@@ -364,8 +364,8 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
     user_token_numberp = &sym->alias->user_token_number;
   if (*user_token_numberp != USER_NUMBER_UNDEFINED
       && *user_token_numberp != user_token_number)
-    complain_at (loc, complaint, _("redefining user token number of %s"),
-                 sym->tag);
+    complain (&loc, complaint, _("redefining user token number of %s"),
+              sym->tag);
 
   *user_token_numberp = user_token_number;
   /* User defined $end token? */
@@ -392,11 +392,11 @@ symbol_check_defined (symbol *sym)
   if (sym->class == unknown_sym)
     {
       assert (sym->status != declared);
-      complain_at (sym->location,
-                   sym->status == needed ? complaint : Wother,
-                   _("symbol %s is used, but is not defined as a token"
-                     " and has no rules"),
-                   sym->tag);
+      complain (&sym->location,
+                sym->status == needed ? complaint : Wother,
+                _("symbol %s is used, but is not defined as a token"
+                  " and has no rules"),
+                  sym->tag);
       sym->class = nterm_sym;
       sym->number = nvars++;
     }
@@ -427,14 +427,14 @@ semantic_type_check_defined (semantic_type *sem_type)
       for (int i = 0; i < 2; ++i)
         if (sem_type->props[i].kind != CODE_PROPS_NONE
             && ! sem_type->props[i].is_used)
-          complain_at (sem_type->location, Wother,
-                       _("useless %s for type <%s>"),
-                       code_props_type_string (i), sem_type->tag);
+          complain (&sem_type->location, Wother,
+                    _("useless %s for type <%s>"),
+                    code_props_type_string (i), sem_type->tag);
     }
   else
-    complain_at (sem_type->location, Wother,
-                 _("type <%s> is used, but is not associated to any symbol"),
-                 sem_type->tag);
+    complain (&sem_type->location, Wother,
+              _("type <%s> is used, but is not associated to any symbol"),
+              sem_type->tag);
 
   return true;
 }
@@ -457,10 +457,10 @@ void
 symbol_make_alias (symbol *sym, symbol *str, location loc)
 {
   if (str->alias)
-    complain_at (loc, Wother,
+    complain (&loc, Wother,
               _("symbol %s used more than once as a literal string"), str->tag);
   else if (sym->alias)
-    complain_at (loc, Wother,
+    complain (&loc, Wother,
               _("symbol %s given more than one literal string"), sym->tag);
   else
     {
@@ -950,11 +950,11 @@ symbols_pack (void)
   symbols_token_translations_init ();
 
   if (startsymbol->class == unknown_sym)
-    complain_at (startsymbol_location, fatal,
-                 _("the start symbol %s is undefined"),
-                 startsymbol->tag);
+    complain (&startsymbol_location, fatal,
+              _("the start symbol %s is undefined"),
+              startsymbol->tag);
   else if (startsymbol->class == token_sym)
-    complain_at (startsymbol_location, fatal,
-                 _("the start symbol %s is a token"),
-                 startsymbol->tag);
+    complain (&startsymbol_location, fatal,
+              _("the start symbol %s is a token"),
+              startsymbol->tag);
 }
