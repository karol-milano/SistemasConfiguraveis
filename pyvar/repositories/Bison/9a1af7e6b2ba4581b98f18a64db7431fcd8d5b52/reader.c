@@ -1548,13 +1548,8 @@ record_rule_line ()
   if (nrules >= rline_allocated)
     {
       rline_allocated = nrules * 2;
-      rline = (short *) realloc (rline,
-				 rline_allocated * sizeof (short));
-      if (rline == 0)
-	{
-	  fprintf (stderr, "%s: memory exhausted\n", program_name);
-	  done (1);
-	}
+      rline = (short *) xrealloc (rline,
+				  rline_allocated * sizeof (short));
     }
   rline[nrules] = lineno;
 }
