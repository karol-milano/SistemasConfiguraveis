@@ -100,7 +100,13 @@ print_fderives (void)
 
       for (j = 0; j <= nrules; j++)
 	if (BITISSET (rp, j))
-	  fprintf (stderr, "\t\t%d (%s)\n", j, tags[j]);
+	  {
+	    short *rhsp;
+	    fprintf (stderr, "\t\t%d:", j);
+	    for (rhsp = ritem + rule_table[j].rhs; *rhsp > 0; ++rhsp)
+	      fprintf (stderr, " %s", tags[*rhsp]);
+	    fputc ('\n', stderr);
+	  }
     }
   fprintf (stderr, "\n\n");
 }
