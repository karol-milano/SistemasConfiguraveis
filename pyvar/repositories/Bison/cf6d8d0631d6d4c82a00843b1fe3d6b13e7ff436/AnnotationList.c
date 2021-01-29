@@ -276,7 +276,8 @@ AnnotationList__computePredecessorAnnotations (
                         obstack_free (annotations_obstackp,
                                       annotation_node->contributions[ci]);
                         annotation_node->contributions[ci] = NULL;
-                        break;
+                        // "Break" out of SBITSET__FOR_EACH.
+                        goto after_sbitset__for_each;
                       }
                     else
                       {
@@ -309,6 +310,7 @@ AnnotationList__computePredecessorAnnotations (
                                     predecessor_item);
                   }
               }
+          after_sbitset__for_each:;
           }
           if (annotation_node->contributions[ci])
             {
