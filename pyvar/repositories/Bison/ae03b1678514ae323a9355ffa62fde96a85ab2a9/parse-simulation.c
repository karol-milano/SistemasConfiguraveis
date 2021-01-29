@@ -272,7 +272,8 @@ typedef void (*chunk_append_fn) (gl_list_t, const void *);
 
 // A version of gl_list_add_last which has the chunk_append_fn
 // signature.
-void list_add_last (gl_list_t list, const void *elt)
+static void
+list_add_last (gl_list_t list, const void *elt)
 {
   gl_list_add_last (list, elt);
 }
@@ -316,7 +317,8 @@ parse_state_list_new (void)
                                true);
 }
 
-void parse_state_list_append (parse_state_list pl, parse_state *ps)
+static void
+parse_state_list_append (parse_state_list pl, parse_state *ps)
 {
   parse_state_retain (ps);
   gl_list_add_last (pl, ps);
@@ -407,7 +409,7 @@ parse_state_lists (parse_state *ps, gl_list_t *sitems,
  * Compute the parse states that result from taking a transition on
  * nullable symbols whenever possible from the given state_item.
  */
-void
+static void
 nullable_closure (parse_state *ps, state_item *si, parse_state_list state_list)
 {
   parse_state *current_ps = ps;
