@@ -253,10 +253,12 @@ parse_state_completed_steps (const parse_state *ps, int *shifts, int *production
 
   gl_list_t sis = root_ps->state_items.contents;
   int count = 0;
-  gl_list_iterator_t it = gl_list_iterator (sis);
+
   state_item *last = NULL;
   state_item *next = NULL;
-  while (gl_list_iterator_next (&it, (const void **) &next, NULL))
+  for (gl_list_iterator_t it = gl_list_iterator (sis);
+       state_item_list_next (&it, &next);
+       )
     {
       if (last && last->state == next->state)
         ++count;
@@ -285,22 +287,24 @@ list_flatten_and_split (gl_list_t *list, gl_list_t *rets, int split, int n,
   int ret_array = 0;
   for (int i = 0; i < n; ++i)
     {
+      const void *p = NULL;
       gl_list_iterator_t it = gl_list_iterator (list[i]);
-      gl_list_t l;
-      while (gl_list_iterator_next (&it, (const void **) &l, NULL))
-        {
-          if (!l)
-            continue;
-          gl_list_iterator_t it2 = gl_list_iterator (l);
-          void *si;
-          while (gl_list_iterator_next (&it2, (const void **) &si, NULL))
-            {
-              if (ret_index++ == split)
-                ++ret_array;
-              if (rets[ret_array])
-                append_fn (rets[ret_array], si);
-            }
-        }
+      while (gl_list_iterator_next (&it, &p, NULL))
+        if (p)
+          {
+            gl_list_t l = (gl_list_t) p;
+            const void *si = NULL;
+            gl_list_iterator_t it2 = gl_list_iterator (l);
+            while (gl_list_iterator_next (&it2, &si, NULL))
+              {
+                if (ret_index++ == split)
+                  ++ret_array;
+                if (rets[ret_array])
+                  append_fn (rets[ret_array], si);
+              }
+            gl_list_iterator_free (&it2);
+          }
+      gl_list_iterator_free (&it);
     }
 }
 
@@ -540,11 +544,12 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
         }
       else
         {
-          gl_list_iterator_t it = gl_list_iterator (prev);
-          state_item *psis;
-          while (gl_list_iterator_next (&it, (const void **) &psis, NULL))
+          state_item *psis = NULL;
+          for (gl_list_iterator_t it = gl_list_iterator (prev);
+               state_item_list_next (&it, &psis);
+               )
             {
-              //Prepend the result from the reverse production
+              // Prepend the result from the reverse production.
               parse_state *copy = copy_parse_state (true, new_root);
               ps_si_prepend (copy, psis);
 
