@@ -62,7 +62,7 @@ print_closure (const char *title, short *array, size_t size)
       fprintf (stderr, "  %2d: .", array[i]);
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
 	fprintf (stderr, " %s", tags[*rp]);
-      fprintf (stderr, "  (rule %d)\n", -*rp);
+      fprintf (stderr, "  (rule %d)\n", -*rp - 1);
     }
   fputs ("\n\n", stderr);
 }
@@ -100,8 +100,8 @@ print_fderives (void)
 	if (BITISSET (FDERIVES (i), j))
 	  {
 	    short *rhsp;
-	    fprintf (stderr, "\t\t%d:", j);
-	    for (rhsp = ritem + rule_table[j].rhs; *rhsp >= 0; ++rhsp)
+	    fprintf (stderr, "\t\t%d:", j - 1);
+	    for (rhsp = &ritem[rule_table[j].rhs]; *rhsp >= 0; ++rhsp)
 	      fprintf (stderr, " %s", tags[*rhsp]);
 	    fputc ('\n', stderr);
 	  }
