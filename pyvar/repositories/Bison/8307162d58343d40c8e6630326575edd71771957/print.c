@@ -366,7 +366,7 @@ print_reductions (FILE *out, state_t *state)
 		  if (redp->rules[j] != default_rule)
 		    print_reduction (out, width,
 				     symbols[i]->tag,
-				     redp->rules[j], TRUE);
+				     redp->rules[j], true);
 		  else
 		    defaulted = 1;
 		  count++;
@@ -376,18 +376,18 @@ print_reductions (FILE *out, state_t *state)
 		  if (defaulted)
 		    print_reduction (out, width,
 				     symbols[i]->tag,
-				     default_rule, TRUE);
+				     default_rule, true);
 		  defaulted = 0;
 		  print_reduction (out, width,
 				   symbols[i]->tag,
-				   redp->rules[j], FALSE);
+				   redp->rules[j], false);
 		}
 	    }
       }
 
   if (default_rule)
     print_reduction (out, width,
-		     _("$default"), default_rule, TRUE);
+		     _("$default"), default_rule, true);
 }
 
 
@@ -400,11 +400,11 @@ static void
 print_actions (FILE *out, state_t *state)
 {
   /* Print shifts.  */
-  print_transitions (state, out, TRUE);
+  print_transitions (state, out, true);
   print_errs (out, state);
   print_reductions (out, state);
   /* Print gotos.  */
-  print_transitions (state, out, FALSE);
+  print_transitions (state, out, false);
 }
 
 
