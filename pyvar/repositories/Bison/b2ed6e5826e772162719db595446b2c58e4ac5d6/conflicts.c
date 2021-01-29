@@ -587,7 +587,8 @@ print_reductions (FILE *out, int state)
 	{
 	  if (mask & *fp3)
 	    fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		     tags[i], default_rule, tags[rlhs[default_rule]]);
+		     tags[i], default_rule,
+		     tags[rule_table[default_rule].lhs]);
 
 	  mask <<= 1;
 	  if (mask == 0)
@@ -598,7 +599,7 @@ print_reductions (FILE *out, int state)
 	}
 
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule, tags[rlhs[default_rule]]);
+	       default_rule, tags[rule_table[default_rule].lhs]);
     }
   else if (n - m >= 1)
     {
@@ -687,7 +688,7 @@ print_reductions (FILE *out, int state)
 			  rule = LAruleno[j];
 			  fprintf (out,
 				   _("    %-4s\treduce using rule %d (%s)\n"),
-				   tags[i], rule, tags[rlhs[rule]]);
+				   tags[i], rule, tags[rule_table[rule].lhs]);
 			}
 		      else
 			defaulted = 1;
@@ -701,13 +702,13 @@ print_reductions (FILE *out, int state)
 			  rule = LAruleno[default_LA];
 			  fprintf (out,
 				   _("    %-4s\treduce using rule %d (%s)\n"),
-				   tags[i], rule, tags[rlhs[rule]]);
+				   tags[i], rule, tags[rule_table[rule].lhs]);
 			  defaulted = 0;
 			}
 		      rule = LAruleno[j];
 		      fprintf (out,
 			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			       tags[i], rule, tags[rlhs[rule]]);
+			       tags[i], rule, tags[rule_table[rule].lhs]);
 		    }
 		}
 
@@ -727,7 +728,7 @@ print_reductions (FILE *out, int state)
 
       if (default_LA >= 0)
 	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
-		 default_rule, tags[rlhs[default_rule]]);
+		 default_rule, tags[rule_table[default_rule].lhs]);
     }
 }
 
