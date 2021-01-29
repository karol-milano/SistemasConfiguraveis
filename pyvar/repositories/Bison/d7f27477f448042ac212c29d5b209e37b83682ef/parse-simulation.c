@@ -135,7 +135,7 @@ static parse_state *
 copy_parse_state (bool prepend, parse_state *parent)
 {
   parse_state *res = xmalloc (sizeof *res);
-  memcpy (res, parent, sizeof *res);
+  *res = *parent;
   res->state_items.contents
     = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   res->derivs.contents = derivation_list_new ();
