@@ -128,7 +128,7 @@ set_goto_map (void)
 	}
     }
 
-  XFREE (temp_map);
+  free (temp_map);
 }
 
 
@@ -203,10 +203,10 @@ initialize_F (void)
   relation_digraph (reads, ngotos, &F);
 
   for (i = 0; i < ngotos; i++)
-    XFREE (reads[i]);
+    free (reads[i]);
 
-  XFREE (reads);
-  XFREE (edge);
+  free (reads);
+  free (edge);
 }
 
 
@@ -283,8 +283,8 @@ build_relations (void)
 	}
     }
 
-  XFREE (edge);
-  XFREE (states1);
+  free (edge);
+  free (states1);
 
   relation_transpose (&includes, ngotos);
 }
@@ -299,9 +299,9 @@ compute_FOLLOWS (void)
   relation_digraph (includes, ngotos, &F);
 
   for (i = 0; i < ngotos; i++)
-    XFREE (includes[i]);
+    free (includes[i]);
 
-  XFREE (includes);
+  free (includes);
 }
 
 
@@ -319,7 +319,7 @@ compute_look_ahead_tokens (void)
   for (i = 0; i < nLA; i++)
     LIST_FREE (goto_list, lookback[i]);
 
-  XFREE (lookback);
+  free (lookback);
   bitsetv_free (F);
 }
 
