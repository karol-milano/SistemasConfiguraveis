@@ -734,45 +734,27 @@ save_row (int state)
 | Figure out the actions for the specified state, indexed by        |
 | lookahead token type.                                             |
 |                                                                   |
-| The yydefact table is output now.  The detailed info is saved for |
-| putting into yytable later.                                       |
+| The YYDEFACT table is output now.  The detailed info is saved for |
+| putting into YYTABLE later.                                       |
 `------------------------------------------------------------------*/
 
 static void
 token_actions (void)
 {
   int i;
-  int j;
-  int k;
+  short *yydefact = NEW2 (nstates, short);
 
   actrow = NEW2 (ntokens, short);
-
-  k = action_row (0);
-  fprintf (ftable, "\nstatic const short yydefact[] = {%6d", k);
-  save_row (0);
-
-  j = 10;
-  for (i = 1; i < nstates; i++)
+  for (i = 0; i < nstates; ++i)
     {
-      putc (',', ftable);
-
-      if (j >= 10)
-	{
-	  putc ('\n', ftable);
-	  j = 1;
-	}
-      else
-	{
-	  j++;
-	}
-
-      k = action_row (i);
-      fprintf (ftable, "%6d", k);
+      yydefact[i] = action_row (i);
       save_row (i);
     }
-
-  fprintf (ftable, "\n};\n");
   FREE (actrow);
+
+  output_short_table (ftable, "yydefact", yydefact,
+		      yydefact[0], 1, nstates);
+  FREE (yydefact);
 }
 
 
