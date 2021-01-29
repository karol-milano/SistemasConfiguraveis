@@ -43,9 +43,9 @@ print_derives (void)
 	{
 	  short *rhsp;
 	  fprintf (stderr, "\t\t%d:", *sp);
-	  for (rhsp = ritem + rule_table[*sp].rhs; *rhsp > 0; ++rhsp)
+	  for (rhsp = ritem + rule_table[*sp].rhs; *rhsp >= 0; ++rhsp)
 	    fprintf (stderr, " %s", tags[*rhsp]);
-	  fprintf (stderr, " (rule %d)\n", -*rhsp);
+	  fprintf (stderr, " (rule %d)\n", -*rhsp - 1);
 	}
     }
 
