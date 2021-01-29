@@ -653,14 +653,7 @@ compute_lookaheads (void)
 
   /* Free LOOKBACK. */
   for (i = 0; i < state_table[nstates].lookaheads; i++)
-    {
-      shorts *sptmp;
-      for (sp = lookback[i]; sp; sp = sptmp)
-	{
-	  sptmp = sp->next;
-	  XFREE (sp);
-	}
-    }
+    LIST_FREE (shorts, lookback[i]);
 
   XFREE (lookback);
   XFREE (F);
