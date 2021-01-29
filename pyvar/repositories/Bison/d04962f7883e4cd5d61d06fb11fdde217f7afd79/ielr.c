@@ -244,7 +244,7 @@ ielr_compute_follow_kernel_items (bitset ritem_sees_lookahead_set,
             && bitset_test (ritem_sees_lookahead_set, items[j]))
           bitset_set ((*follow_kernel_itemsp)[i], j);
     }
-  relation_digraph (internal_follow_edges, ngotos, follow_kernel_itemsp);
+  relation_digraph (internal_follow_edges, ngotos, *follow_kernel_itemsp);
 
   if (trace_flag & trace_ielr)
     {
@@ -300,7 +300,7 @@ ielr_compute_always_follows (goto_number ***edgesp,
       }
     free (edge_array);
   }
-  relation_digraph (*edgesp, ngotos, always_followsp);
+  relation_digraph (*edgesp, ngotos, *always_followsp);
 
   if (trace_flag & trace_ielr)
     {
