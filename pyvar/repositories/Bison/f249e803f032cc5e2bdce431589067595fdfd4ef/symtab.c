@@ -243,9 +243,12 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
     {
       if (sym->type_name)
         symbol_redeclaration (sym, "%type", sym->type_location, loc);
-      uniqstr_assert (type_name);
-      sym->type_name = type_name;
-      sym->type_location = loc;
+      else
+        {
+          uniqstr_assert (type_name);
+          sym->type_name = type_name;
+          sym->type_location = loc;
+        }
     }
 }
 
@@ -261,7 +264,8 @@ symbol_code_props_set (symbol *sym, code_props_type kind,
     symbol_redeclaration (sym, code_props_type_string (kind),
                           sym->props[kind].location,
                           code->location);
-  sym->props[kind] = *code;
+  else
+    sym->props[kind] = *code;
 }
 
 /*-----------------------------------------------------.
@@ -277,7 +281,8 @@ semantic_type_code_props_set (semantic_type *type,
     semantic_type_redeclaration (type, code_props_type_string (kind),
                                  type->props[kind].location,
                                  code->location);
-  type->props[kind] = *code;
+  else
+    type->props[kind] = *code;
 }
 
 /*---------------------------------------------------.
@@ -363,7 +368,8 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
     {
       if (sym->status == declared && !warned)
         complain (&loc, Wother, _("symbol %s redeclared"), sym->tag);
-      sym->status = declared;
+      else
+        sym->status = declared;
     }
 }
 
@@ -618,8 +624,8 @@ symbol_translation (symbol *this)
           (this->user_token_number,
            symbols[token_translations[this->user_token_number]],
            this);
-
-      token_translations[this->user_token_number] = this->number;
+      else
+        token_translations[this->user_token_number] = this->number;
     }
 
   return true;
