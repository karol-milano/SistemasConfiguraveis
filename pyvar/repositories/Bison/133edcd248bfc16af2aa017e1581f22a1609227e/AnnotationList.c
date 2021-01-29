@@ -269,7 +269,7 @@ AnnotationList__computePredecessorAnnotations (
                   if (item_number_is_rule_number (ritem[s->items[self_item]
                                                         - 2]))
                     {
-                      unsigned rulei;
+                      int rulei;
                       for (rulei = s->items[self_item];
                            !item_number_is_rule_number (ritem[rulei]);
                            ++rulei)
