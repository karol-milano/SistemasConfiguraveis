@@ -329,7 +329,7 @@ state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
           && default_reduction_only_for_accept))
     n_lookahead_tokens += rp->num;
   else
-    s->consistent = 1;
+    s->consistent = true;
 
   return n_lookahead_tokens;
 }
