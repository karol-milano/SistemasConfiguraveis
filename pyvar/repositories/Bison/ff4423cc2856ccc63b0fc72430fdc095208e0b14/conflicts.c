@@ -45,11 +45,10 @@ static int rrc_count;
 static inline void
 log_resolution (int state, int LAno, int token, char *resolution)
 {
-  if (verbose_flag)
-    fprintf (foutput,
-	     _("\
+  obstack_fgrow4 (&output_obstack,
+		  _("\
 Conflict in state %d between rule %d and token %s resolved as %s.\n"),
-	     state, LAruleno[LAno], tags[token], resolution);
+		  state, LAruleno[LAno], tags[token], resolution);
 }
 
 
@@ -407,29 +406,38 @@ count_rr_conflicts (int state)
     }
 }
 
-/*----------------------------------------------------------.
-| Output to OUT a human readable report on shift/reduce and |
-| reduce/reduce conflict numbers (SRC_NUM, RRC_NUM).        |
-`----------------------------------------------------------*/
+/*--------------------------------------------------------------.
+| Return a human readable string which reports shift/reduce and |
+| reduce/reduce conflict numbers (SRC_NUM, RRC_NUM).            |
+`--------------------------------------------------------------*/
 
-static void
-conflict_report (FILE *out, int src_num, int rrc_num)
+static const char *
+conflict_report (int src_num, int rrc_num)
 {
+  static char res[4096];
+  char *cp = res;
+
   if (src_num == 1)
-    fprintf (out, _(" 1 shift/reduce conflict"));
+    sprintf (cp, _(" 1 shift/reduce conflict"));
   else if (src_num > 1)
-    fprintf (out, _(" %d shift/reduce conflicts"), src_num);
+    sprintf (cp, _(" %d shift/reduce conflicts"), src_num);
+  cp += strlen (cp);
 
   if (src_num > 0 && rrc_num > 0)
-    fprintf (out, _(" and"));
+    sprintf (cp, _(" and"));
+  cp += strlen (cp);
 
   if (rrc_num == 1)
-    fprintf (out, _(" 1 reduce/reduce conflict"));
+    sprintf (cp, _(" 1 reduce/reduce conflict"));
   else if (rrc_num > 1)
-    fprintf (out, _(" %d reduce/reduce conflicts"), rrc_num);
+    sprintf (cp, _(" %d reduce/reduce conflicts"), rrc_num);
+  cp += strlen (cp);
+
+  *cp++ = '.';
+  *cp++ = '\n';
+  *cp++ = '\0';
 
-  putc ('.', out);
-  putc ('\n', out);
+  return res;
 }
 
 
@@ -458,8 +466,9 @@ print_conflicts (void)
 
 	  if (verbose_flag)
 	    {
-	      fprintf (foutput, _("State %d contains"), i);
-	      conflict_report (foutput, src_count, rrc_count);
+	      obstack_fgrow1 (&output_obstack, _("State %d contains"), i);
+	      obstack_sgrow (&output_obstack,
+			     conflict_report (src_count, rrc_count));
 	    }
 	}
     }
@@ -481,7 +490,7 @@ print_conflicts (void)
   else
     {
       fprintf (stderr, _("%s contains"), infile);
-      conflict_report (stderr, src_total, rrc_total);
+      fputs (conflict_report (src_total, rrc_total), stderr);
     }
 }
 
@@ -565,8 +574,9 @@ print_reductions (int state)
       for (i = 0; i < ntokens; i++)
 	{
 	  if (mask & *fp3)
-	    fprintf (foutput, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		     tags[i], default_rule, tags[rlhs[default_rule]]);
+	    obstack_fgrow3 (&output_obstack,
+			    _("    %-4s\t[reduce using rule %d (%s)]\n"),
+			    tags[i], default_rule, tags[rlhs[default_rule]]);
 
 	  mask <<= 1;
 	  if (mask == 0)
@@ -576,8 +586,9 @@ print_reductions (int state)
 	    }
 	}
 
-      fprintf (foutput, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule, tags[rlhs[default_rule]]);
+      obstack_fgrow2 (&output_obstack,
+		      _("    $default\treduce using rule %d (%s)\n\n"),
+		      default_rule, tags[rlhs[default_rule]]);
     }
   else if (n - m >= 1)
     {
@@ -664,7 +675,7 @@ print_reductions (int state)
 		      if (j != default_LA)
 			{
 			  rule = LAruleno[j];
-			  fprintf (foutput,
+			  obstack_fgrow3 (&output_obstack,
 				   _("    %-4s\treduce using rule %d (%s)\n"),
 				   tags[i], rule, tags[rlhs[rule]]);
 			}
@@ -678,13 +689,13 @@ print_reductions (int state)
 		      if (defaulted)
 			{
 			  rule = LAruleno[default_LA];
-			  fprintf (foutput,
+			  obstack_fgrow3 (&output_obstack,
 				   _("    %-4s\treduce using rule %d (%s)\n"),
 				   tags[i], rule, tags[rlhs[rule]]);
 			  defaulted = 0;
 			}
 		      rule = LAruleno[j];
-		      fprintf (foutput,
+		      obstack_fgrow3 (&output_obstack,
 			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
 			       tags[i], rule, tags[rlhs[rule]]);
 		    }
@@ -705,12 +716,11 @@ print_reductions (int state)
 	}
 
       if (default_LA >= 0)
-	{
-	  fprintf (foutput, _("    $default\treduce using rule %d (%s)\n"),
-		   default_rule, tags[rlhs[default_rule]]);
-	}
+	obstack_fgrow2 (&output_obstack,
+			_("    $default\treduce using rule %d (%s)\n"),
+			default_rule, tags[rlhs[default_rule]]);
 
-      putc ('\n', foutput);
+      obstack_1grow (&output_obstack, '\n');
     }
 }
 
