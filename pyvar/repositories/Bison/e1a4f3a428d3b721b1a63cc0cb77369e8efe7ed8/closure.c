@@ -99,11 +99,8 @@ print_fderives (void)
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       BITSET_FOR_EACH (iter, FDERIVES (i), r, 0)
 	{
-	  item_number_t *rhsp = NULL;
-	  fprintf (stderr, "\t\t%d:", r - 1);
-	  for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
-	    fprintf (stderr, " %s", symbols[*rhsp]->tag);
-	  fputc ('\n', stderr);
+	  fprintf (stderr, "\t\t%3d ", r);
+	  rule_rhs_print (&rules[r], stderr);
 	}
     }
   fprintf (stderr, "\n\n");
