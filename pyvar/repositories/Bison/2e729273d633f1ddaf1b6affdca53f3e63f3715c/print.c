@@ -111,21 +111,14 @@ print_actions (FILE *out, int state)
       return;
     }
 
-  for (i = 0; i < shiftp->nshifts; i++)
+  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
 	int state1 = shiftp->shifts[i];
 	int symbol = state_table[state1]->accessing_symbol;
-	/* The following line used to be turned off.  */
-	if (ISVAR (symbol))
-	  break;
-	if (symbol == 0)	/* I.e. strcmp(tags[symbol],"$")==0 */
-	  fprintf (out,
-		   _("    $   \tgo to state %d\n"), state1);
-	else
-	  fprintf (out,
-		   _("    %-4s\tshift, and go to state %d\n"),
-		   tags[symbol], state1);
+	fprintf (out,
+		 _("    %-4s\tshift, and go to state %d\n"),
+		 tags[symbol], state1);
       }
 
   if (i > 0)
