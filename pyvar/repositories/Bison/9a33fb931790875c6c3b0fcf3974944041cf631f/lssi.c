@@ -41,12 +41,12 @@ typedef struct lssi
 lssi *
 new_lssi (state_item_number si, lssi *p, bitset l, bool free_l)
 {
-  lssi *ret = xmalloc (sizeof (lssi));
-  ret->si = si;
-  ret->parent = p;
-  ret->lookahead = l;
-  ret->free_lookahead = free_l;
-  return ret;
+  lssi *res = xmalloc (sizeof *res);
+  res->si = si;
+  res->parent = p;
+  res->lookahead = l;
+  res->free_lookahead = free_l;
+  return res;
 }
 
 void
@@ -240,10 +240,10 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
       fputs ("Cannot find shortest path to conflict state.", stderr);
       exit (1);
     }
-  gl_list_t ret =
+  gl_list_t res =
     gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   for (lssi *sn = n; sn != NULL; sn = sn->parent)
-    gl_list_add_first (ret, state_items + sn->si);
+    gl_list_add_first (res, state_items + sn->si);
 
   hash_free (visited);
   gl_list_free (queue);
@@ -251,12 +251,12 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
   if (trace_flag & trace_cex)
     {
       puts ("REDUCE ITEM PATH:");
-      gl_list_iterator_t it = gl_list_iterator (ret);
+      gl_list_iterator_t it = gl_list_iterator (res);
       const void *sip;
       while (gl_list_iterator_next (&it, &sip, NULL))
         print_state_item ((state_item *) sip, stdout);
     }
-  return ret;
+  return res;
 }
 
 /**
