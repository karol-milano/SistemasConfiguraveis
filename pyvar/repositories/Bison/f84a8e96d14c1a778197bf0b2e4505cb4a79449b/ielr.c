@@ -929,7 +929,7 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
  *     compatibility or, if <tt>annotation_lists = NULL</tt>, the canonical
  *     LR(1) state compatibility test was used.
  *   - If <tt>annotation_lists = NULL</tt>, reduction lookahead sets were
- *     computed in all states.  TV_IELR_PHASE4 was pushed while they were
+ *     computed in all states.  tv_ielr_phase4 was pushed while they were
  *     computed from item lookahead sets.
  */
 static void
@@ -1004,7 +1004,7 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
      lookahead sets.  */
   if (!annotation_lists)
     {
-      timevar_push (TV_IELR_PHASE4);
+      timevar_push (tv_ielr_phase4);
       initialize_LA ();
       for (state_list *node = first_state; node; node = node->next)
         if (!node->state->consistent)
@@ -1037,7 +1037,7 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
                   }
               }
           }
-      timevar_pop (TV_IELR_PHASE4);
+      timevar_pop (tv_ielr_phase4);
     }
 
   /* Free state list.  */
@@ -1080,7 +1080,7 @@ ielr (void)
   }
 
   /* Phase 0: LALR(1).  */
-  timevar_push (TV_LALR);
+  timevar_push (tv_lalr);
   if (lr_type == LR_TYPE__CANONICAL_LR)
     set_goto_map ();
   else
@@ -1088,10 +1088,10 @@ ielr (void)
   if (lr_type == LR_TYPE__LALR)
     {
       bitsetv_free (goto_follows);
-      timevar_pop (TV_LALR);
+      timevar_pop (tv_lalr);
       return;
     }
-  timevar_pop (TV_LALR);
+  timevar_pop (tv_lalr);
 
   {
     bitsetv follow_kernel_items;
@@ -1104,14 +1104,14 @@ ielr (void)
     {
       /* Phase 1: Compute Auxiliary Tables.  */
       state ***predecessors;
-      timevar_push (TV_IELR_PHASE1);
+      timevar_push (tv_ielr_phase1);
       ielr_compute_auxiliary_tables (
         &follow_kernel_items, &always_follows,
         lr_type == LR_TYPE__CANONICAL_LR ? NULL : &predecessors);
-      timevar_pop (TV_IELR_PHASE1);
+      timevar_pop (tv_ielr_phase1);
 
       /* Phase 2: Compute Annotations.  */
-      timevar_push (TV_IELR_PHASE2);
+      timevar_push (tv_ielr_phase2);
       if (lr_type != LR_TYPE__CANONICAL_LR)
         {
           obstack_init (&annotations_obstack);
@@ -1125,11 +1125,11 @@ ielr (void)
           bitsetv_free (goto_follows);
           lalr_free ();
         }
-      timevar_pop (TV_IELR_PHASE2);
+      timevar_pop (tv_ielr_phase2);
     }
 
     /* Phase 3: Split States.  */
-    timevar_push (TV_IELR_PHASE3);
+    timevar_push (tv_ielr_phase3);
     {
       state_number nstates_lr0 = nstates;
       ielr_split_states (follow_kernel_items, always_follows,
@@ -1144,11 +1144,11 @@ ielr (void)
     free (annotation_lists);
     bitsetv_free (follow_kernel_items);
     bitsetv_free (always_follows);
-    timevar_pop (TV_IELR_PHASE3);
+    timevar_pop (tv_ielr_phase3);
   }
 
   /* Phase 4: Compute Reduction Lookaheads.  */
-  timevar_push (TV_IELR_PHASE4);
+  timevar_push (tv_ielr_phase4);
   free (goto_map);
   free (from_state);
   free (to_state);
@@ -1163,5 +1163,5 @@ ielr (void)
       lalr ();
       bitsetv_free (goto_follows);
     }
-  timevar_pop (TV_IELR_PHASE4);
+  timevar_pop (tv_ielr_phase4);
 }
