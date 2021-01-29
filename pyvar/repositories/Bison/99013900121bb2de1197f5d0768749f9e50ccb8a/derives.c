@@ -44,7 +44,7 @@ print_derives (void)
 	{
 	  short *rhsp;
 	  fprintf (stderr, "\t\t%d:", *sp);
-	  for (rhsp = &ritem[rules[*sp].rhs]; *rhsp >= 0; ++rhsp)
+	  for (rhsp = rules[*sp].rhs; *rhsp >= 0; ++rhsp)
 	    fprintf (stderr, " %s", symbols[*rhsp]->tag);
 	  fprintf (stderr, " (rule %d)\n", -*rhsp - 1);
 	}
