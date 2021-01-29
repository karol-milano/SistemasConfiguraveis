@@ -86,40 +86,40 @@ static int frees = 0;
 static parse_state *
 empty_parse_state (void)
 {
-  parse_state *ret = xcalloc (1, sizeof (parse_state));
-  ret->state_items.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
+  parse_state *res = xcalloc (1, sizeof (parse_state));
+  res->state_items.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
                                                     NULL, NULL, true);
-  ret->derivs.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
+  res->derivs.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
                                                NULL, NULL, true);
   ++allocs;
-  return ret;
+  return res;
 }
 
 parse_state *
 new_parse_state (const state_item *si)
 {
-  parse_state *ret = empty_parse_state ();
-  ps_chunk_append (&ret->state_items, si);
-  ps_chunk_append (&ret->derivs, derivation_dot ());
-  return ret;
+  parse_state *res = empty_parse_state ();
+  ps_chunk_append (&res->state_items, si);
+  ps_chunk_append (&res->derivs, derivation_dot ());
+  return res;
 }
 
 static parse_state *
 copy_parse_state (bool prepend, parse_state *parent)
 {
-  parse_state *ret = xmalloc (sizeof (parse_state));
-  memcpy (ret, parent, sizeof (parse_state));
-  ret->state_items.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
+  parse_state *res = xmalloc (sizeof *res);
+  memcpy (res, parent, sizeof *res);
+  res->state_items.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
                                                     NULL, NULL, true);
-  ret->derivs.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
+  res->derivs.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
                                                NULL, NULL, true);
-  ret->parent = parent;
-  ret->prepend = prepend;
-  ret->reference_count = 0;
-  ret->free_contents_early = false;
+  res->parent = parent;
+  res->prepend = prepend;
+  res->reference_count = 0;
+  res->free_contents_early = false;
   parse_state_retain (parent);
   ++allocs;
-  return ret;
+  return res;
 }
 
 bool
