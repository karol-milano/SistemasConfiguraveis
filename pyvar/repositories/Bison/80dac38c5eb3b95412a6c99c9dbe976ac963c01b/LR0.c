@@ -522,15 +522,8 @@ save_reductions (void)
     }
 
   /* Make a reductions structure and copy the data into it.  */
-
-  if (count)
-    {
-      reductions *p = REDUCTIONS_ALLOC (count);
-      p->nreds = count;
-      shortcpy (p->rules, redset, count);
-
-      this_state->reductions = p;
-    }
+  this_state->reductions = reductions_new (count);
+  shortcpy (this_state->reductions->rules, redset, count);
 }
 
 
@@ -547,11 +540,14 @@ set_state_table (void)
   for (sp = first_state; sp; sp = sp->next)
     {
       /* Pessimization, but simplification of the code: make sure all
-	 the states have a shifts and errs, even if reduced to 0.  */
+	 the states have a shifts, errs, and reductions, even if
+	 reduced to 0.  */
       if (!sp->shifts)
 	sp->shifts = shifts_new (0);
       if (!sp->errs)
 	sp->errs = errs_new (0);
+      if (!sp->reductions)
+	sp->reductions = reductions_new (0);
 
       state_table[sp->number] = sp;
     }
