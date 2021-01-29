@@ -275,7 +275,7 @@ AnnotationList__computePredecessorAnnotations (AnnotationList *self, state *s,
                                                         - 2]))
                     {
                       Sbitset items;
-                      unsigned int rulei;
+                      unsigned rulei;
                       for (rulei = s->items[self_item];
                            !item_number_is_rule_number (ritem[rulei]);
                            ++rulei)
