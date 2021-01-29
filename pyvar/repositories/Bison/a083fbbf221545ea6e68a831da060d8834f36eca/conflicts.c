@@ -192,13 +192,13 @@ int lookaheadnum;
 	{
 	  if (sprec[i] < redprec)
 	    {
-	      if (verboseflag) log_resolution(state, lookaheadnum, i, "reduce");
+	      if (verboseflag) log_resolution(state, lookaheadnum, i, _("reduce"));
 	      *fp2 &= ~mask;  /* flush the shift for this token */
 	      flush_shift(state, i);
 	    }
 	  else if (sprec[i] > redprec)
 	    {
-	      if (verboseflag) log_resolution(state, lookaheadnum, i, "shift");
+	      if (verboseflag) log_resolution(state, lookaheadnum, i, _("shift"));
 	      *fp1 &= ~mask;  /* flush the reduce for this token */
 	    }
 	  else
@@ -212,15 +212,15 @@ int lookaheadnum;
 		{
 
 		case RIGHT_ASSOC:
-	          if (verboseflag) log_resolution(state, lookaheadnum, i, "shift");
+	          if (verboseflag) log_resolution(state, lookaheadnum, i, _("shift"));
 		  break;
 
 		case LEFT_ASSOC:
-	          if (verboseflag) log_resolution(state, lookaheadnum, i, "reduce");
+	          if (verboseflag) log_resolution(state, lookaheadnum, i, _("reduce"));
 		  break;
 
 		case NON_ASSOC:
-	          if (verboseflag) log_resolution(state, lookaheadnum, i, "an error");
+	          if (verboseflag) log_resolution(state, lookaheadnum, i, _("an error"));
 		  break;
 		}
 
@@ -296,7 +296,7 @@ int state, LAno, token;
 char *resolution;
 {
   fprintf(foutput,
-	  "Conflict in state %d between rule %d and token %s resolved as %s.\n",
+	  _("Conflict in state %d between rule %d and token %s resolved as %s.\n"),
 	  state, LAruleno[LAno], tags[token], resolution);
 }
 
@@ -341,20 +341,20 @@ verbose_conflict_log()
 	  src_total += src_count;
 	  rrc_total += rrc_count;
 
-	  fprintf(foutput, "State %d contains", i);
+	  fprintf(foutput, _("State %d contains"), i);
 
 	  if (src_count == 1)
-	    fprintf(foutput, " 1 shift/reduce conflict");
+	    fprintf(foutput, _(" 1 shift/reduce conflict"));
 	  else if (src_count > 1)
-	    fprintf(foutput, " %d shift/reduce conflicts", src_count);
+	    fprintf(foutput, _(" %d shift/reduce conflicts"), src_count);
 
 	  if (src_count > 0 && rrc_count > 0)
-	    fprintf(foutput, " and");
+	    fprintf(foutput, _(" and"));
 
 	  if (rrc_count == 1)
-	    fprintf(foutput, " 1 reduce/reduce conflict");
+	    fprintf(foutput, _(" 1 reduce/reduce conflict"));
 	  else if (rrc_count > 1)
-	    fprintf(foutput, " %d reduce/reduce conflicts", rrc_count);
+	    fprintf(foutput, _(" %d reduce/reduce conflicts"), rrc_count);
 
 	  putc('.', foutput);
 	  putc('\n', foutput);
@@ -377,31 +377,31 @@ total_conflicts()
     {
       /* If invoked under the name `yacc', use the output format
 	 specified by POSIX.  */
-      fprintf(stderr, "conflicts: ");
+      fprintf(stderr, _("conflicts: "));
       if (src_total > 0)
-	fprintf(stderr, " %d shift/reduce", src_total);
+	fprintf(stderr, _(" %d shift/reduce"), src_total);
       if (src_total > 0 && rrc_total > 0)
 	fprintf(stderr, ",");
       if (rrc_total > 0)
-	fprintf(stderr, " %d reduce/reduce", rrc_total);
+	fprintf(stderr, _(" %d reduce/reduce"), rrc_total);
       putc('\n', stderr);
     }
   else
     {
-      fprintf(stderr, "%s contains", infile);
+      fprintf(stderr, _("%s contains"), infile);
 
       if (src_total == 1)
-	fprintf(stderr, " 1 shift/reduce conflict");
+	fprintf(stderr, _(" 1 shift/reduce conflict"));
       else if (src_total > 1)
-	fprintf(stderr, " %d shift/reduce conflicts", src_total);
+	fprintf(stderr, _(" %d shift/reduce conflicts"), src_total);
 
       if (src_total > 0 && rrc_total > 0)
-	fprintf(stderr, " and");
+	fprintf(stderr, _(" and"));
 
       if (rrc_total == 1)
-	fprintf(stderr, " 1 reduce/reduce conflict");
+	fprintf(stderr, _(" 1 reduce/reduce conflict"));
       else if (rrc_total > 1)
-	fprintf(stderr, " %d reduce/reduce conflicts", rrc_total);
+	fprintf(stderr, _(" %d reduce/reduce conflicts"), rrc_total);
 
       putc('.', stderr);
       putc('\n', stderr);
@@ -600,7 +600,7 @@ int state;
       for (i = 0; i < ntokens; i++)
 	{
 	  if (mask & *fp3)
-	    fprintf(foutput, "    %-4s\t[reduce using rule %d (%s)]\n",
+	    fprintf(foutput, _("    %-4s\t[reduce using rule %d (%s)]\n"),
 		    tags[i], default_rule, tags[rlhs[default_rule]]);
 
 	  mask <<= 1;
@@ -611,7 +611,7 @@ int state;
 	    }
 	}
 
-      fprintf(foutput, "    $default\treduce using rule %d (%s)\n\n",
+      fprintf(foutput, _("    $default\treduce using rule %d (%s)\n\n"),
 	      default_rule, tags[rlhs[default_rule]]);
     }
   else if (n - m >= 1)
@@ -697,7 +697,7 @@ int state;
 		      if (j != default_LA)
 			{
 			  rule = LAruleno[j];
-			  fprintf(foutput, "    %-4s\treduce using rule %d (%s)\n",
+			  fprintf(foutput, _("    %-4s\treduce using rule %d (%s)\n"),
 				  tags[i], rule, tags[rlhs[rule]]);
 			}
 		      else defaulted = 1;
@@ -709,12 +709,12 @@ int state;
 		      if (defaulted)
 			{
 			  rule = LAruleno[default_LA];
-			  fprintf(foutput, "    %-4s\treduce using rule %d (%s)\n",
+			  fprintf(foutput, _("    %-4s\treduce using rule %d (%s)\n"),
 				  tags[i], rule, tags[rlhs[rule]]);
 			  defaulted = 0;
 			}
 		      rule = LAruleno[j];
-		      fprintf(foutput, "    %-4s\t[reduce using rule %d (%s)]\n",
+		      fprintf(foutput, _("    %-4s\t[reduce using rule %d (%s)]\n"),
 			      tags[i], rule, tags[rlhs[rule]]);
 		    }
 		}
@@ -735,7 +735,7 @@ int state;
 
       if (default_LA >= 0)
 	{
-	  fprintf(foutput, "    $default\treduce using rule %d (%s)\n",
+	  fprintf(foutput, _("    $default\treduce using rule %d (%s)\n"),
 		  default_rule, tags[rlhs[default_rule]]);
 	}
 
