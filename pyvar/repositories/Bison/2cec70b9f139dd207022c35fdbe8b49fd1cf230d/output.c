@@ -375,12 +375,11 @@ action_row (state_t *state)
 
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record MINSHORT as the action.  */
-  if (errp)
-    for (i = 0; i < errp->nerrs; i++)
-      {
-	int symbol = errp->errs[i];
-	actrow[symbol] = MINSHORT;
-      }
+  for (i = 0; i < errp->nerrs; i++)
+    {
+      int symbol = errp->errs[i];
+      actrow[symbol] = MINSHORT;
+    }
 
   /* Now find the most common reduction and make it the default action
      for this state.  */
@@ -903,9 +902,9 @@ output_actions (void)
 
   for (i = 0; i < nstates; ++i)
     {
-      XFREE (state_table[i]->shifts);
+      free (state_table[i]->shifts);
       XFREE (state_table[i]->reductions);
-      XFREE (state_table[i]->errs);
+      free (state_table[i]->errs);
       free (state_table[i]);
     }
   XFREE (state_table);
