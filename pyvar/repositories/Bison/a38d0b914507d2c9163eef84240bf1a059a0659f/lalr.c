@@ -473,7 +473,7 @@ state_lookaheads_count (state *s, bool default_reduction_only_for_accept)
   s->consistent =
     !(reds->num > 1
       || (reds->num == 1 && trans->num && TRANSITION_IS_SHIFT (trans, 0))
-      || (reds->num == 1 && reds->rules[0]->number != 0
+      || (reds->num == 1 && !rule_is_initial (reds->rules[0])
           && default_reduction_only_for_accept));
 
   return s->consistent ? 0 : reds->num;
