@@ -502,7 +502,7 @@ conflicts_print (void)
 
 
 void
-print_reductions (int state)
+print_reductions (FILE *out, int state)
 {
   int i;
   int j;
@@ -580,9 +580,8 @@ print_reductions (int state)
       for (i = 0; i < ntokens; i++)
 	{
 	  if (mask & *fp3)
-	    obstack_fgrow3 (&output_obstack,
-			    _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			    tags[i], default_rule, tags[rlhs[default_rule]]);
+	    fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
+		     tags[i], default_rule, tags[rlhs[default_rule]]);
 
 	  mask <<= 1;
 	  if (mask == 0)
@@ -592,9 +591,8 @@ print_reductions (int state)
 	    }
 	}
 
-      obstack_fgrow2 (&output_obstack,
-		      _("    $default\treduce using rule %d (%s)\n\n"),
-		      default_rule, tags[rlhs[default_rule]]);
+      fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
+	       default_rule, tags[rlhs[default_rule]]);
     }
   else if (n - m >= 1)
     {
@@ -681,7 +679,7 @@ print_reductions (int state)
 		      if (j != default_LA)
 			{
 			  rule = LAruleno[j];
-			  obstack_fgrow3 (&output_obstack,
+			  fprintf (out,
 				   _("    %-4s\treduce using rule %d (%s)\n"),
 				   tags[i], rule, tags[rlhs[rule]]);
 			}
@@ -695,13 +693,13 @@ print_reductions (int state)
 		      if (defaulted)
 			{
 			  rule = LAruleno[default_LA];
-			  obstack_fgrow3 (&output_obstack,
+			  fprintf (out,
 				   _("    %-4s\treduce using rule %d (%s)\n"),
 				   tags[i], rule, tags[rlhs[rule]]);
 			  defaulted = 0;
 			}
 		      rule = LAruleno[j];
-		      obstack_fgrow3 (&output_obstack,
+		      fprintf (out,
 			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
 			       tags[i], rule, tags[rlhs[rule]]);
 		    }
@@ -722,11 +720,8 @@ print_reductions (int state)
 	}
 
       if (default_LA >= 0)
-	obstack_fgrow2 (&output_obstack,
-			_("    $default\treduce using rule %d (%s)\n"),
-			default_rule, tags[rlhs[default_rule]]);
-
-      obstack_1grow (&output_obstack, '\n');
+	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
+		 default_rule, tags[rlhs[default_rule]]);
     }
 }
 
