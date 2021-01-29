@@ -546,7 +546,7 @@ AnnotationList__compute_from_inadequacies (
                     AnnotationList__insertInto (annotation_node,
                                                 &annotation_lists[s->number],
                                                 s->nitems);
-                  aver (b);
+                  aver (b); (void) b;
                 }
                 /* This aver makes sure the
                    AnnotationList__computeDominantContribution check above
