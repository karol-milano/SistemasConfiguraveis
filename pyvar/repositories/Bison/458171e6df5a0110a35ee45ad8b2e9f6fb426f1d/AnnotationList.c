@@ -541,9 +541,13 @@ AnnotationList__compute_from_inadequacies (
               {
                 InadequacyList__prependTo (conflict_node,
                                            &inadequacy_lists[s->number]);
-                aver (AnnotationList__insertInto (
-                        annotation_node, &annotation_lists[s->number],
-                        s->nitems));
+                {
+                  bool b =
+                    AnnotationList__insertInto (annotation_node,
+                                                &annotation_lists[s->number],
+                                                s->nitems);
+                  aver (b);
+                }
                 /* This aver makes sure the
                    AnnotationList__computeDominantContribution check above
                    does discard annotations in the simplest case of a S/R
