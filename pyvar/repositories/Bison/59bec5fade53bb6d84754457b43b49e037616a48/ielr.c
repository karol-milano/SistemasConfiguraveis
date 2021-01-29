@@ -198,7 +198,7 @@ ielr_compute_internal_follow_edges (bitset ritem_sees_lookahead_set,
   if (trace_flag & trace_ielr)
     {
       fprintf (stderr, "internal_follow_edges:\n");
-      relation_print (*edgesp, ngotos, stderr);
+      relation_print (*edgesp, ngotos, NULL, stderr);
     }
 }
 
@@ -305,7 +305,7 @@ ielr_compute_always_follows (goto_number ***edgesp,
   if (trace_flag & trace_ielr)
     {
       fprintf (stderr, "always follow edges:\n");
-      relation_print (*edgesp, ngotos, stderr);
+      relation_print (*edgesp, ngotos, NULL, stderr);
       fprintf (stderr, "always_follows:\n");
       debug_bitsetv (*always_followsp);
     }
