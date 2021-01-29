@@ -342,7 +342,7 @@ state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
   /* We need a lookahead either to distinguish different reductions
      (i.e., there are two or more), or to distinguish a reduction from a
      shift.  Otherwise, it is straightforward, and the state is
-     `consistent'.  However, do not treat a state with any reductions as
+     'consistent'.  However, do not treat a state with any reductions as
      consistent unless it is the accepting state (because there is never
      a lookahead token that makes sense there, and so no lookahead token
      should be read) if the user has otherwise disabled default
