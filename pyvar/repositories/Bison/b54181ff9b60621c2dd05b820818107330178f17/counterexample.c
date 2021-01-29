@@ -1110,10 +1110,7 @@ cex_search_end:;
       // If a search state from Stage 3 is available, use it
       // to construct a more compact nonunifying counterexample.
       if (stage3result)
-        {
-          cex = complete_diverging_examples (stage3result, next_sym);
-          search_state_free (stage3result);
-        }
+        cex = complete_diverging_examples (stage3result, next_sym);
       // Otherwise, construct a nonunifying counterexample that
       // begins from the start state using the shortest
       // lookahead-sensitive path to the reduce item.
@@ -1122,6 +1119,8 @@ cex_search_end:;
     }
   gl_list_free (ssb_queue);
   hash_free (visited);
+  if (stage3result)
+    search_state_free (stage3result);
   return cex;
 }
 
