@@ -42,7 +42,7 @@ print_derives (void)
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       for (sp = derives[i]; *sp > 0; sp++)
 	{
-	  short *rhsp;
+	  item_number_t *rhsp;
 	  fprintf (stderr, "\t\t%d:", *sp);
 	  for (rhsp = rules[*sp].rhs; *rhsp >= 0; ++rhsp)
 	    fprintf (stderr, " %s", symbols[*rhsp]->tag);
