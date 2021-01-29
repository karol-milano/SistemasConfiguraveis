@@ -86,13 +86,12 @@ static void
 print_actions (FILE *out, int state)
 {
   int i;
-  int k;
 
   shifts   *shiftp = state_table[state].shift_table;
   reductions *redp = state_table[state].reduction_table;
   errs       *errp = err_table[state];
 
-  if (!shiftp && !redp)
+  if (!shiftp->nshifts && !redp)
     {
       if (final_state == state)
 	fprintf (out, _("    $default\taccept\n"));
@@ -101,37 +100,25 @@ print_actions (FILE *out, int state)
       return;
     }
 
-  if (shiftp)
-    {
-      k = shiftp->nshifts;
+  for (i = 0; i < shiftp->nshifts; i++)
+    if (!SHIFT_IS_DISABLED (shiftp, i))
+      {
+	int state1 = shiftp->shifts[i];
+	int symbol = state_table[state1].accessing_symbol;
+	/* The following line used to be turned off.  */
+	if (ISVAR (symbol))
+	  break;
+	if (symbol == 0)	/* I.e. strcmp(tags[symbol],"$")==0 */
+	  fprintf (out,
+		   _("    $   \tgo to state %d\n"), state1);
+	else
+	  fprintf (out,
+		   _("    %-4s\tshift, and go to state %d\n"),
+		   tags[symbol], state1);
+      }
 
-      for (i = 0; i < k; i++)
-	{
-	  int symbol;
-	  int state1 = shiftp->shifts[i];
-	  if (!state1)
-	    continue;
-	  symbol = state_table[state1].accessing_symbol;
-	  /* The following line used to be turned off.  */
-	  if (ISVAR (symbol))
-	    break;
-	  if (symbol == 0)	/* I.e. strcmp(tags[symbol],"$")==0 */
-	    fprintf (out,
-		     _("    $   \tgo to state %d\n"), state1);
-	  else
-	    fprintf (out,
-		     _("    %-4s\tshift, and go to state %d\n"),
-		     tags[symbol], state1);
-	}
-
-      if (i > 0)
-	fputc ('\n', out);
-    }
-  else
-    {
-      i = 0;
-      k = 0;
-    }
+  if (i > 0)
+    fputc ('\n', out);
 
   if (errp)
     {
@@ -161,18 +148,16 @@ print_actions (FILE *out, int state)
       print_reductions (out, state);
     }
 
-  if (i < k)
+  if (i < shiftp->nshifts)
     {
-      for (; i < k; i++)
-	{
-	  int symbol;
-	  int state1 = shiftp->shifts[i];
-	  if (!state1)
-	    continue;
-	  symbol = state_table[state1].accessing_symbol;
-	  fprintf (out, _("    %-4s\tgo to state %d\n"),
-		   tags[symbol], state1);
-	}
+      for (; i < shiftp->nshifts; i++)
+	if (!SHIFT_IS_DISABLED (shiftp, i))
+	  {
+	    int state1 = shiftp->shifts[i];
+	    int symbol = state_table[state1].accessing_symbol;
+	    fprintf (out, _("    %-4s\tgo to state %d\n"),
+		     tags[symbol], state1);
+	  }
 
       fputc ('\n', out);
     }
