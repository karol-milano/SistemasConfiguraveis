@@ -105,6 +105,7 @@ symbol_new (uniqstr tag, location loc)
 
   res->tag = tag;
   res->location = loc;
+  res->location_of_lhs = false;
   res->alias = NULL;
   res->content = sym_content_new (res);
   res->is_alias = false;
@@ -189,6 +190,7 @@ code_props_type_string (code_props_type kind)
   assert (0);
 }
 
+
 /*----------------------------------------.
 | Create a new semantic type, named TAG.  |
 `----------------------------------------*/
@@ -307,6 +309,13 @@ semantic_type_redeclaration (semantic_type *s, const char *what, location first,
 }
 
 
+void
+symbol_location_as_lhs_set (symbol *sym, location loc)
+{
+  if (!sym->location_of_lhs)
+    sym->location = loc;
+}
+
 
 /*-----------------------------------------------------------------.
 | Set the TYPE_NAME associated with SYM.  Does nothing if passed 0 |
