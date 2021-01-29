@@ -54,7 +54,7 @@ print_core (FILE *out, int state)
   short *sp;
   short *sp1;
 
-  statep = state_table[state];
+  statep = state_table[state].state;
   k = statep->nitems;
 
   if (k == 0)
@@ -124,7 +124,7 @@ print_actions (FILE *out, int state)
 	  if (!shiftp->shifts[i])
 	    continue;
 	  state1 = shiftp->shifts[i];
-	  symbol = accessing_symbol[state1];
+	  symbol = state_table[state1].accessing_symbol;
 	  /* The following line used to be turned off.  */
 	  if (ISVAR (symbol))
 	    break;
@@ -184,7 +184,7 @@ print_actions (FILE *out, int state)
 	  if (!shiftp->shifts[i])
 	    continue;
 	  state1 = shiftp->shifts[i];
-	  symbol = accessing_symbol[state1];
+	  symbol = state_table[state1].accessing_symbol;
 	  fprintf (out, _("    %-4s\tgo to state %d\n"),
 		   tags[symbol], state1);
 	}
