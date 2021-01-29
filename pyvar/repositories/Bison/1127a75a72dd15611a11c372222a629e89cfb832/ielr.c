@@ -758,8 +758,8 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
                     if (!bitset_empty_p (lookaheads[i]))
                       break;
                   }
-                // bitset_equal_p uses the size of the first argument, so
-                // lookaheads[i] must be the second argument.
+                /* bitset_equal_p uses the size of the first argument,
+                   so lookaheads[i] must be the second argument.  */
                 else if (!bitset_equal_p ((*this_isocorep)->lookaheads[i],
                                           lookaheads[i]))
                   break;
@@ -1187,8 +1187,8 @@ ielr (void)
   free (to_state);
   if (lr_type == LR_TYPE__CANONICAL_LR)
     {
-      // Reduction lookaheads are computed in ielr_split_states above but are
-      // timed as part of phase 4.
+      /* Reduction lookaheads are computed in ielr_split_states above
+         but are timed as part of phase 4. */
       set_goto_map ();
     }
   else
