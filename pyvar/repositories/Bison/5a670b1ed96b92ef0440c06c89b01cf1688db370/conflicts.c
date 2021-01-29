@@ -122,7 +122,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
 	     For right association, keep only the shift.
 	     For nonassociation, keep neither.  */
 
-	  switch (sassoc[i])
+	  switch (symbols[i]->assoc)
 	    {
 	    case right_assoc:
 	      log_resolution (state, lookahead, i, _("shift"));
