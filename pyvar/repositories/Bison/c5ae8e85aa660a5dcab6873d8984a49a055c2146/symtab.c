@@ -55,7 +55,6 @@ static symbol *
 symbol_new (uniqstr tag, location loc)
 {
   symbol *res = xmalloc (sizeof *res);
-
   uniqstr_assert (tag);
 
   /* If the tag is not a string (starts with a double quote), check
@@ -68,8 +67,11 @@ symbol_new (uniqstr tag, location loc)
   res->location = loc;
 
   res->type_name = NULL;
-  for (int i = 0; i < CODE_PROPS_SIZE; ++i)
-    code_props_none_init (&res->props[i]);
+  {
+    int i;
+    for (i = 0; i < CODE_PROPS_SIZE; ++i)
+      code_props_none_init (&res->props[i]);
+  }
 
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
@@ -113,8 +115,11 @@ semantic_type_new (uniqstr tag, const location *loc)
   res->tag = tag;
   res->location = loc ? *loc : empty_location;
   res->status = undeclared;
-  for (int i = 0; i < CODE_PROPS_SIZE; ++i)
-    code_props_none_init (&res->props[i]);
+  {
+    int i;
+    for (i = 0; i < CODE_PROPS_SIZE; ++i)
+      code_props_none_init (&res->props[i]);
+  }
 
   return res;
 }
@@ -329,7 +334,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
   if (sym->class != unknown_sym && sym->class != class)
     {
       complain (&loc, complaint, _("symbol %s redefined"), sym->tag);
-      // Don't report both "redefined" and "redeclared".
+      /* Don't report both "redefined" and "redeclared".  */
       warned = true;
     }
 
@@ -401,8 +406,11 @@ symbol_check_defined (symbol *sym)
       sym->number = nvars++;
     }
 
-  for (int i = 0; i < 2; ++i)
-    symbol_code_props_get (sym, i)->is_used = true;
+  {
+    int i;
+    for (i = 0; i < 2; ++i)
+      symbol_code_props_get (sym, i)->is_used = true;
+  }
 
   /* Set the semantic type status associated to the current symbol to
      'declared' so that we could check semantic types unnecessary uses. */
@@ -419,12 +427,13 @@ symbol_check_defined (symbol *sym)
 static inline bool
 semantic_type_check_defined (semantic_type *sem_type)
 {
-  // <*> and <> do not have to be "declared".
+  /* <*> and <> do not have to be "declared".  */
   if (sem_type->status == declared
       || !*sem_type->tag
       || STREQ(sem_type->tag, "*"))
     {
-      for (int i = 0; i < 2; ++i)
+      int i;
+      for (i = 0; i < 2; ++i)
         if (sem_type->props[i].kind != CODE_PROPS_NONE
             && ! sem_type->props[i].is_used)
           complain (&sem_type->location, Wother,
@@ -500,11 +509,14 @@ symbol_check_alias_consistency (symbol *this)
     }
 
 
-  for (int i = 0; i < CODE_PROPS_SIZE; ++i)
-    if (str->props[i].code)
-      symbol_code_props_set (sym, i, &str->props[i]);
-    else if (sym->props[i].code)
-      symbol_code_props_set (str, i, &sym->props[i]);
+  {
+    int i;
+    for (i = 0; i < CODE_PROPS_SIZE; ++i)
+      if (str->props[i].code)
+        symbol_code_props_set (sym, i, &str->props[i]);
+      else if (sym->props[i].code)
+        symbol_code_props_set (str, i, &sym->props[i]);
+  }
 
   if (sym->prec || str->prec)
     {
