@@ -111,8 +111,8 @@ semantic_type_new (uniqstr tag, const location *loc)
 
   uniqstr_assert (tag);
   res->tag = tag;
-  if (loc)
-    res->location = *loc;
+  res->location = loc ? *loc : empty_location;
+  res->status = undeclared;
   for (int i = 0; i < CODE_PROPS_SIZE; ++i)
     code_props_none_init (&res->props[i]);
 
