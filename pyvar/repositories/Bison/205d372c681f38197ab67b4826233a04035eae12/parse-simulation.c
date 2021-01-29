@@ -30,17 +30,17 @@
 
 typedef struct parse_state
 {
-  // path of state-items the parser has traversed
+  // Path of state-items the parser has traversed.
   struct si_chunk
   {
-    // elements newly added in this chunk
+    // Elements newly added in this chunk.
     state_item_list contents;
-    // properties of the linked list this chunk represents
+    // Properties of the linked list this chunk represents.
     const state_item *head_elt;
     const state_item *tail_elt;
     size_t total_size;
   } state_items;
-  // list of derivations of the symbols
+  // List of derivations of the symbols.
   struct deriv_chunk
   {
     derivation_list contents;
@@ -50,16 +50,13 @@ typedef struct parse_state
   } derivs;
   struct parse_state *parent;
   int reference_count;
-  // incremented during productions,
-  // decremented during reductions
+  // Incremented during productions, decremented during reductions.
   int depth;
-  // whether the contents of the chunks should be
-  // prepended or appended to the list the chunks
-  // represent
+  // Whether the contents of the chunks should be prepended or
+  // appended to the list the chunks represent.
   bool prepend;
-  // causes chunk contents to be freed when the
-  // reference count is one. Used when only the chunk metadata
-  // will be needed.
+  // Causes chunk contents to be freed when the reference count is
+  // one. Used when only the chunk metadata will be needed.
   bool free_contents_early;
 } parse_state;
 
@@ -438,9 +435,8 @@ simulate_transition (parse_state *ps)
   // symbols into account.
   parse_state_list result = parse_state_list_new ();
   state_item_number si_next = si->trans;
-  // check for disabled transition, shouldn't happen
-  // as any state_items that lead to these should be
-  // disabled.
+  // Check for disabled transition, shouldn't happen as any
+  // state_items that lead to these should be disabled.
   if (si_next < 0)
     return result;
   parse_state *next_ps = copy_parse_state (false, ps);
