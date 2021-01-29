@@ -141,6 +141,11 @@ digraph (short **relation)
   XFREE (VERTICES);
 }
 
+
+/*--------------------.
+| Build STATE_TABLE.  |
+`--------------------*/
+
 static void
 set_state_table (void)
 {
@@ -643,22 +648,18 @@ compute_lookaheads (void)
   unsigned *fp2;
   unsigned *fp3;
   shorts *sp;
-  unsigned *rowp;
   shorts *sptmp;		/* JF */
 
-  rowp = LA;
   for (i = 0; i < state_table[nstates].lookaheads; i++)
     {
-      fp3 = rowp + tokensetsize;
+      fp3 = LA (i + 1);
       for (sp = lookback[i]; sp; sp = sp->next)
 	{
-	  fp1 = rowp;
+	  fp1 = LA (i);
 	  fp2 = F + tokensetsize * sp->value;
 	  while (fp1 < fp3)
 	    *fp1++ |= *fp2++;
 	}
-
-      rowp = fp3;
     }
 
   for (i = 0; i < state_table[nstates].lookaheads; i++)
