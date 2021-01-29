@@ -504,15 +504,15 @@ ielr_compute_annotation_lists (bitsetv follow_kernel_items,
       (*annotation_listsp)[i] = NULL;
       annotation_counts[i] = 0;
     }
-  for (i = 0; i < nstates; ++i)
-    AnnotationList__compute_from_inadequacies (states[i], follow_kernel_items,
-                                               always_follows, predecessors,
-                                               item_lookahead_sets,
-                                               *inadequacy_listsp,
-                                               *annotation_listsp,
-                                               annotation_counts,
-                                               &max_contributions,
-                                               annotations_obstackp);
+  {
+    InadequacyListNodeCount inadequacy_list_node_count = 0;
+    for (i = 0; i < nstates; ++i)
+      AnnotationList__compute_from_inadequacies (
+        states[i], follow_kernel_items, always_follows, predecessors,
+        item_lookahead_sets, *inadequacy_listsp, *annotation_listsp,
+        annotation_counts, &max_contributions, annotations_obstackp,
+        &inadequacy_list_node_count);
+  }
   *max_annotationsp = 0;
   for (i = 0; i < nstates; ++i)
     {
