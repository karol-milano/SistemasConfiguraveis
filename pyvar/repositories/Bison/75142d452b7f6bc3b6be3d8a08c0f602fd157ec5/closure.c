@@ -60,7 +60,7 @@ print_closure (const char *title, short *array, size_t size)
     {
       short *rp;
       fprintf (stderr, "  %2d: .", array[i]);
-      for (rp = &ritem[array[i]]; *rp > 0; ++rp)
+      for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
 	fprintf (stderr, " %s", tags[*rp]);
       fprintf (stderr, "  (rule %d)\n", -*rp);
     }
@@ -101,7 +101,7 @@ print_fderives (void)
 	  {
 	    short *rhsp;
 	    fprintf (stderr, "\t\t%d:", j);
-	    for (rhsp = ritem + rule_table[j].rhs; *rhsp > 0; ++rhsp)
+	    for (rhsp = ritem + rule_table[j].rhs; *rhsp >= 0; ++rhsp)
 	      fprintf (stderr, " %s", tags[*rhsp]);
 	    fputc ('\n', stderr);
 	  }
