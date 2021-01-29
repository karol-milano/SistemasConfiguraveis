@@ -701,8 +701,8 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
         AnnotationIndex ai;
         AnnotationList *a;
         for (ai = 0, a = annotation_lists[lr0_isocore->state->number];
-           a;
-           ++ai, a = a->next)
+             a;
+             ++ai, a = a->next)
         work1[ai] =
           AnnotationList__computeDominantContribution (
             a, lr0_isocore->state->nitems, lookaheads, false);
@@ -982,7 +982,7 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
          this_state;
          this_state = this_state->next)
       {
-        state *s = this_state->state;
+        const state *s = this_state->state;
         for (int i = 0; i < s->transitions->num; ++i)
           {
             state *t = s->transitions->states[i];
