@@ -304,7 +304,7 @@ gen_lookaheads (void)
         continue;
 
       bitset lookahead = si->lookahead;
-      gl_list_t queue =
+      state_item_list queue =
         gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true, 1,
                         (const void **) &si);
 
@@ -390,7 +390,7 @@ disable_state_item (state_item *si)
 static void
 prune_forward (const state_item *si)
 {
-  gl_list_t queue =
+  state_item_list queue =
     gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true, 1,
                     (const void **) &si);
 
@@ -425,7 +425,7 @@ prune_forward (const state_item *si)
 static void
 prune_backward (const state_item *si)
 {
-  gl_list_t queue =
+  state_item_list queue =
     gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true, 1,
                     (const void **) &si);
 
