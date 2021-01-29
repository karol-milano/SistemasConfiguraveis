@@ -728,6 +728,7 @@ production_step (search_state *ss, int parser_state)
       copy->complexity = complexity;
       ssb_append (copy);
     }
+  gl_list_free (prods);
 }
 
 static inline int
@@ -776,6 +777,7 @@ reduction_step (search_state *ss, const item_number *conflict_item,
       copy->complexity += r_cost + PRODUCTION_COST + 2 * SHIFT_COST;
       gl_list_add_last (result, copy);
     }
+  gl_list_free (reduced);
   return result;
 }
 
