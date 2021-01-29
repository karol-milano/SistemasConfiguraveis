@@ -58,6 +58,16 @@
 
 #define CUMULATIVE_TIME_LIMIT 120.0f
 
+// This is the fastest way to get the tail node from the gl_list API.
+gl_list_node_t
+list_get_end (gl_list_t list)
+{
+  gl_list_node_t sentinel = gl_list_add_last (list, NULL);
+  gl_list_node_t res = gl_list_previous_node (list, sentinel);
+  gl_list_remove_node (list, sentinel);
+  return res;
+}
+
 typedef struct
 {
   const derivation *d1;
@@ -266,19 +276,17 @@ complete_diverging_example (symbol_number conflict_sym,
       gl_list_add_last (result, derivation_dot ());
       lookahead_required = true;
     }
-  // This is the fastest way to get the tail node from the gl_list API
-  gl_list_node_t tmpd = gl_list_add_last (derivs, NULL);
-  gl_list_node_t tmps = gl_list_add_last (path, NULL);
-  gl_list_node_t deriv = gl_list_previous_node (derivs, tmpd);
-  gl_list_node_t state_node = gl_list_previous_node (path, tmps);
-  gl_list_remove_node (derivs, tmpd);
-  gl_list_remove_node (path, tmps);
-  // we go backwards through the path to create the derivation tree bottom-up.
+
+  gl_list_node_t deriv = list_get_end (derivs);
+
+  // We go backwards through the path to create the derivation tree bottom-up.
   // Effectively this loops through each production once, and generates a
   // derivation of the left hand side by appending all of the rhs symbols.
   // this becomes the derivation of the non-terminal after the dot in the
   // next production, and all of the other symbols of the rule are added as normal.
-  for (; state_node != NULL; state_node = gl_list_previous_node (path, state_node))
+  for (gl_list_node_t state_node = list_get_end (path);
+       state_node != NULL;
+       state_node = gl_list_previous_node (path, state_node))
     {
       state_item *si = (state_item *) gl_list_node_value (path, state_node);
       item_number *item = si->item;
