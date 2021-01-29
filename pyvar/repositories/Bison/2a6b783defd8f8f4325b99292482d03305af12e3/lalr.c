@@ -340,7 +340,6 @@ compute_lookahead_tokens (void)
 static int
 state_lookahead_tokens_count (state *s)
 {
-  int k;
   int n_lookahead_tokens = 0;
   reductions *rp = s->reductions;
   transitions *sp = s->transitions;
@@ -348,21 +347,17 @@ state_lookahead_tokens_count (state *s)
   /* We need a lookahead either to distinguish different
      reductions (i.e., there are two or more), or to distinguish a
      reduction from a shift.  Otherwise, it is straightforward,
-     and the state is `consistent'.  */
+     and the state is `consistent'.  There is no need to check that
+     transition 0 hasn't been disabled before checking if it is a
+     shift since transitions are only disabled during conflict
+     resolution, and that hasn't happened yet.  */
+  aver (sp->num == 0 || !TRANSITION_IS_DISABLED (sp, 0));
   if (rp->num > 1
-      || (rp->num == 1 && sp->num &&
-	  !TRANSITION_IS_DISABLED (sp, 0) && TRANSITION_IS_SHIFT (sp, 0)))
+      || (rp->num == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0)))
     n_lookahead_tokens += rp->num;
   else
     s->consistent = 1;
 
-  for (k = 0; k < sp->num; k++)
-    if (!TRANSITION_IS_DISABLED (sp, k) && TRANSITION_IS_ERROR (sp, k))
-      {
-	s->consistent = 0;
-	break;
-      }
-
   return n_lookahead_tokens;
 }
 
