@@ -551,33 +551,17 @@ print_reductions (FILE *out, int state)
 
   if (n - m == 1 && !nodefault)
     {
-      unsigned *fp1 = LA (m);
-      unsigned *fp2 = shiftset;
-      unsigned *fp3 = lookaheadset;
-      unsigned *fp4 = lookaheadset + tokensetsize;
-
+      int k;
       default_rule = LAruleno[m];
 
-      while (fp3 < fp4)
-	*fp3++ = *fp1++ & *fp2++;
-
-      mask = 1;
-      fp3 = lookaheadset;
+      for (k = 0; k < tokensetsize; ++k)
+	lookaheadset[k] = LA (m)[k] & shiftset[k];
 
       for (i = 0; i < ntokens; i++)
-	{
-	  if (mask & *fp3)
-	    fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		     tags[i], default_rule,
-		     tags[rule_table[default_rule].lhs]);
-
-	  mask <<= 1;
-	  if (mask == 0)
-	    {
-	      mask = 1;
-	      fp3++;
-	    }
-	}
+	if (BITISSET (lookaheadset, i))
+	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
+		   tags[i], default_rule,
+		   tags[rule_table[default_rule].lhs]);
 
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       default_rule, tags[rule_table[default_rule].lhs]);
