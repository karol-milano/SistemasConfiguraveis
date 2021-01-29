@@ -237,9 +237,12 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 	    }
       }
 
-  /* Some tokens have been explicitly made errors.  Allocate a
-     permanent errs structure for this state, to record them.  */
-  state_errs_set (s, nerrs, errors);
+  if (nerrs)
+    {
+      /* Some tokens have been explicitly made errors.  Allocate a
+	 permanent errs structure for this state, to record them.  */
+      state_errs_set (s, nerrs, errors);
+    }
 
   if (obstack_object_size (&solved_conflicts_obstack))
     {
@@ -277,10 +280,7 @@ set_conflicts (state *s, symbol **errors)
   for (i = 0; i < reds->num; ++i)
     if (reds->rules[i]->prec && reds->rules[i]->prec->prec
 	&& !bitset_disjoint_p (reds->lookaheads[i], lookaheadset))
-      {
-	resolve_sr_conflict (s, i, errors);
-	break;
-      }
+      resolve_sr_conflict (s, i, errors);
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
