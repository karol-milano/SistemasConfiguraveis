@@ -378,15 +378,85 @@ init_firsts (void)
 }
 
 static inline void
-disable_state_item (state_item_number sin)
+disable_state_item (state_item *si)
 {
-  state_item *si = state_items + sin;
   si->trans = -2;
   bitset_free (si->revs);
   if (si->prods)
     bitset_free (si->prods);
 }
 
+/* disable all transitions and productions that can only be
+ * reached through this state_item.
+ */
+static void
+prune_forward (const state_item *si)
+{
+  gl_list_t queue =
+    gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true, 1,
+                    (const void **) &si);
+
+  while (gl_list_size (queue) > 0)
+    {
+      state_item *dsi = (state_item *) gl_list_get_at (queue, 0);
+      gl_list_remove_at (queue, 0);
+      if (dsi->trans >= 0)
+        gl_list_add_last (queue, state_items + dsi->trans);
+
+      if (dsi->prods)
+        {
+          bitset_iterator biter;
+          state_item_number sin;
+          BITSET_FOR_EACH (biter, dsi->prods, sin, 0)
+            {
+              const state_item *prod = state_items + sin;
+              bitset_reset (prod->revs, dsi - state_items);
+              if (bitset_empty_p (prod->revs))
+                gl_list_add_last (queue, prod);
+            }
+        }
+      if (dsi != si)
+        disable_state_item (dsi);
+    }
+  gl_list_free (queue);
+}
+
+/* disable all state_item paths that lead to
+ * si and nowhere else.
+ */
+static void
+prune_backward (const state_item *si)
+{
+  gl_list_t queue =
+    gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true, 1,
+                    (const void **) &si);
+
+  while (gl_list_size (queue) > 0)
+    {
+      state_item *dsi = (state_item *) gl_list_get_at (queue, 0);
+      gl_list_remove_at (queue, 0);
+      bitset_iterator biter;
+      state_item_number sin;
+      BITSET_FOR_EACH (biter, dsi->revs, sin, 0)
+        {
+          if (SI_DISABLED (sin))
+            continue;
+          state_item *rev = state_items + sin;
+          if (rev->prods)
+            {
+              bitset_reset (rev->prods, dsi - state_items);
+              if (bitset_empty_p (rev->prods))
+                gl_list_add_last (queue, rev);
+            }
+          else
+            gl_list_add_last (queue, rev);
+        }
+      if (dsi != si)
+        disable_state_item (dsi);
+    }
+  gl_list_free (queue);
+}
+
 /*
  To make searches more efficient, we can prune away paths that are
  caused by disabled transitions.
@@ -399,40 +469,9 @@ prune_disabled_paths (void)
       state_item *si = state_items + i;
       if (si->trans == -1 && item_number_is_symbol_number (*si->item))
         {
-          // disable the transitions out of i
-          for (state_item_number j = si->trans; j != -1; j = state_items[j].trans)
-            disable_state_item (j);
-
-          gl_list_t queue =
-            gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true, 1,
-                            (const void **) &si);
-
-          // For each disabled transition, traverse through all state_items
-          // accessible through reverse transition steps, and set their
-          // lookaheads to the reduction items lookahead
-          while (gl_list_size (queue) > 0)
-            {
-              const state_item *prev = gl_list_get_at (queue, 0);
-              gl_list_remove_at (queue, 0);
-              state_item_number prev_num = prev - state_items;
-
-              bitset rsi = prev->revs;
-              bitset_iterator biter;
-              state_item_number sin;
-              BITSET_FOR_EACH (biter, rsi, sin, 0)
-              {
-                if (SI_TRANSITION (prev))
-                  gl_list_add_first (queue, &state_items[sin]);
-                else
-                  {
-                    bitset p = state_items[sin].prods;
-                    if (p)
-                      bitset_reset (p, prev_num);
-                  }
-              }
-              disable_state_item (prev_num);
-            }
-          gl_list_free (queue);
+          prune_forward (si);
+          prune_backward (si);
+          disable_state_item (si);
         }
     }
 }
@@ -459,6 +498,12 @@ state_items_report (void)
         {
           state_item *si = state_items + j;
           item_print (si->item, NULL, stdout);
+          if (SI_DISABLED (j))
+            {
+              item_print (si->item, NULL, stdout);
+              puts (" DISABLED");
+              continue;
+            }
           puts ("");
           if (si->trans >= 0)
             {
