@@ -449,6 +449,7 @@ prune_disabled_paths (void)
                   }
               }
             }
+          gl_list_free (queue);
         }
     }
 }
