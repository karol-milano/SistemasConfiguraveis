@@ -502,7 +502,6 @@ print_reductions (FILE *out, int state)
 {
   int i;
   int j;
-  int rule;
   int symbol;
   unsigned mask;
   int m;
@@ -541,8 +540,7 @@ print_reductions (FILE *out, int state)
 	{
 	  if (!errp->errs[i])
 	    continue;
-	  symbol = errp->errs[i];
-	  SETBIT (shiftset, symbol);
+	  SETBIT (shiftset, errp->errs[i]);
 	}
     }
 
@@ -650,12 +648,11 @@ print_reductions (FILE *out, int state)
 		  if (count == 0)
 		    {
 		      if (j != default_LA)
-			{
-			  rule = LAruleno[j];
-			  fprintf (out,
-				   _("    %-4s\treduce using rule %d (%s)\n"),
-				   tags[i], rule, tags[rule_table[rule].lhs]);
-			}
+			fprintf (out,
+				 _("    %-4s\treduce using rule %d (%s)\n"),
+				 tags[i],
+				 LAruleno[j],
+				 tags[rule_table[LAruleno[j]].lhs]);
 		      else
 			defaulted = 1;
 
@@ -664,17 +661,17 @@ print_reductions (FILE *out, int state)
 		  else
 		    {
 		      if (defaulted)
-			{
-			  rule = LAruleno[default_LA];
-			  fprintf (out,
-				   _("    %-4s\treduce using rule %d (%s)\n"),
-				   tags[i], rule, tags[rule_table[rule].lhs]);
-			  defaulted = 0;
-			}
-		      rule = LAruleno[j];
+			fprintf (out,
+				 _("    %-4s\treduce using rule %d (%s)\n"),
+				 tags[i],
+				 LAruleno[default_LA],
+				 tags[rule_table[LAruleno[default_LA]].lhs]);
+		      defaulted = 0;
 		      fprintf (out,
 			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			       tags[i], rule, tags[rule_table[rule].lhs]);
+			       tags[i],
+			       LAruleno[j],
+			       tags[rule_table[LAruleno[j]].lhs]);
 		    }
 		}
 
