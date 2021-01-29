@@ -117,7 +117,7 @@ copy_parse_state (bool prepend, parse_state *parent)
   ret->prepend = prepend;
   ret->reference_count = 0;
   ret->free_contents_early = false;
-  ++parent->reference_count;
+  parse_state_retain (parent);
   ++allocs;
   return ret;
 }
@@ -177,26 +177,29 @@ parse_state_retain_deriv (parse_state *ps)
 }
 
 void
-free_parse_state (parse_state *ps)
+free_parse_state (parse_state *original_ps)
 {
-  if (ps == NULL)
-    return;
-  --ps->reference_count;
-  // need to keep the parse state around
-  // for visited, but its contents can be freed
-  if ((ps->reference_count == 1 && ps->free_contents_early) ||
-      (ps->reference_count == 0 && !ps->free_contents_early))
+  bool free_contents = true;
+  for (parse_state *ps = original_ps; ps && free_contents; ps = ps->parent)
     {
-      if (ps->state_items.contents)
-        gl_list_free (ps->state_items.contents);
-      if (ps->derivs.contents)
-        gl_list_free (ps->derivs.contents);
-      free_parse_state (ps->parent);
-    }
-  if (ps->reference_count <= 0)
-    {
-      free (ps);
-      ++frees;
+      --ps->reference_count;
+      free_contents = (ps->reference_count == 1 && ps->free_contents_early)
+        || (ps->reference_count == 0 && !ps->free_contents_early);
+      // need to keep the parse state around for visited hash set,
+      // but its contents and parent can be freed
+      if (free_contents)
+        {
+          if (ps->state_items.contents)
+            gl_list_free (ps->state_items.contents);
+          if (ps->derivs.contents)
+            gl_list_free (ps->derivs.contents);
+        }
+      if (ps->reference_count <= 0)
+        {
+          free (ps);
+          ++frees;
+          break;
+        }
     }
 }
 
@@ -370,7 +373,7 @@ nullable_closure (parse_state *ps, state_item *si, gl_list_t state_list)
       current_ps = copy_parse_state (false, current_ps);
       ps_chunk_append (&current_ps->state_items, nsi);
       ps_chunk_append (&current_ps->derivs, derivation_new (sp, NULL));
-      ++current_ps->reference_count;
+      parse_state_retain (current_ps);
       gl_list_add_last (state_list, current_ps);
     }
 }
@@ -395,7 +398,7 @@ simulate_transition (parse_state *ps)
   parse_state *next_ps = copy_parse_state (false, ps);
   ps_chunk_append (&next_ps->state_items, state_items + si_next);
   ps_chunk_append (&next_ps->derivs, derivation_new (sym, NULL));
-  ++next_ps->reference_count;
+  parse_state_retain (next_ps);
   gl_list_add_last (result, next_ps);
 
   nullable_closure (next_ps, state_items + si_next, result);
@@ -444,7 +447,7 @@ simulate_production (parse_state *ps, symbol_number compat_sym)
             continue;
           parse_state *next_ps = copy_parse_state (false, ps);
           ps_chunk_append (&next_ps->state_items, next);
-          ++next_ps->reference_count;
+          parse_state_retain (next_ps);
           gl_list_add_last (result, next_ps);
           if (next_ps->depth >= 0)
             ++next_ps->depth;
@@ -487,7 +490,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
       state_item *tail = (state_item *) new_root->state_items.tail_elt;
       ps_chunk_append (&new_root->state_items,
                        state_items + si_trans[tail - state_items]);
-      ++new_root->reference_count;
+      parse_state_retain (new_root);
       gl_list_add_last (result, new_root);
     }
   else
@@ -509,7 +512,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
           ps_chunk *sis = &copy->state_items;
           const state_item *tail = sis->tail_elt;
           ps_chunk_append (sis, state_items + si_trans[tail - state_items]);
-          ++copy->reference_count;
+          parse_state_retain (copy);
           gl_list_add_last (result, copy);
           nullable_closure (copy, (state_item *) sis->tail_elt, result);
         }
@@ -534,7 +537,7 @@ parser_prepend (parse_state *ps)
   BITSET_FOR_EACH (biter, prev, sin, 0)
   {
     parse_state *copy = copy_parse_state (true, ps);
-    copy->reference_count++;
+    parse_state_retain (copy);
     ps_chunk_prepend (&copy->state_items, state_items + sin);
     if (SI_TRANSITION (head))
       ps_chunk_prepend (&copy->derivs, derivation_new (prepend_sym, NULL));
