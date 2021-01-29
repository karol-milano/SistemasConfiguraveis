@@ -435,7 +435,7 @@ reduce_output (FILE *out)
 	if (!rule_table[i].useful)
 	  {
 	    rule r;
-	    fprintf (out, "#%-4d  ", i);
+	    fprintf (out, "#%-4d  ", i - 1);
 	    fprintf (out, "%s:", tags[rule_table[i].lhs]);
 	    for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
 	      fprintf (out, " %s", tags[*r]);
