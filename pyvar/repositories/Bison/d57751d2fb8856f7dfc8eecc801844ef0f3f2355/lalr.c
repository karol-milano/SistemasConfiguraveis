@@ -352,9 +352,8 @@ compute_lookahead_tokens (void)
 static int
 state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
 {
-  int n_lookahead_tokens = 0;
-  reductions *rp = s->reductions;
-  transitions *sp = s->transitions;
+  const reductions *rp = s->reductions;
+  const transitions *sp = s->transitions;
 
   /* Transitions are only disabled during conflict resolution, and that
      hasn't happened yet, so there should be no need to check that
@@ -371,15 +370,13 @@ state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
      a lookahead token that makes sense there, and so no lookahead token
      should be read) if the user has otherwise disabled default
      reductions.  */
-  if (rp->num > 1
+  s->consistent =
+    !(rp->num > 1
       || (rp->num == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0))
       || (rp->num == 1 && rp->rules[0]->number != 0
-          && default_reduction_only_for_accept))
-    n_lookahead_tokens += rp->num;
-  else
-    s->consistent = true;
+          && default_reduction_only_for_accept));
 
-  return n_lookahead_tokens;
+  return s->consistent ? 0 : rp->num;
 }
 
 
