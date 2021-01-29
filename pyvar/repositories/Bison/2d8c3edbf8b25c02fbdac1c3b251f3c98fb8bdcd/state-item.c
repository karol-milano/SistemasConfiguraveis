@@ -73,6 +73,7 @@ hash_pair_lookup (Hash_table *tab, int key)
   hash_pair *hp = (hash_pair *) hash_lookup (tab, l);
   if (!hp)
     return NULL;
+  free (l);
   return hp->l;
 }
 
@@ -174,6 +175,7 @@ init_state_items (void)
 
     }
   state_item_map[nstates] = nstate_items;
+  bitsetv_free (production_items);
 }
 
 static size_t
@@ -193,7 +195,9 @@ state_sym_lookup (symbol_number sym, Hash_table *h)
 {
   state *s = xmalloc (sizeof (state));
   s->accessing_symbol = sym;
-  return hash_lookup (h, s);
+  state *res = hash_lookup (h, s);
+  free (s);
+  return res;
 }
 
 static void
@@ -234,6 +238,7 @@ init_trans (void)
                 }
             }
         }
+      free (transition_set);
     }
 }
 
@@ -306,7 +311,7 @@ init_prods (void)
                 bitset_set (si_revs[prod], j);
             }
         }
-
+      free (closure_map);
     }
 }
 
@@ -345,6 +350,7 @@ gen_lookaheads (void)
                 gl_list_add_first (queue, &state_items[sin]);
             }
         }
+      gl_list_free (queue);
     }
 }
 
