@@ -385,6 +385,7 @@ count_rr_conflicts (state_t *state, int one_per_token)
   return rrc_count;
 }
 
+
 /*--------------------------------------------------------------.
 | Return a human readable string which reports shift/reduce and |
 | reduce/reduce conflict numbers (SRC_NUM, RRC_NUM).            |
@@ -416,14 +417,32 @@ conflict_report (int src_num, int rrc_num)
       cp += strlen (cp);
     }
 
-  *cp++ = '.';
-  *cp++ = '\n';
   *cp++ = '\0';
 
   return res;
 }
 
 
+/*----------------------------------------------------------------.
+| Same as above, but report the number of conflicts a` la POSIX.  |
+`----------------------------------------------------------------*/
+
+static void
+conflict_report_yacc (int src_num, int rrc_num)
+{
+  /* If invoked with `--yacc', use the output format specified by
+     POSIX.  */
+  fprintf (stderr, _("conflicts: "));
+  if (src_num > 0)
+    fprintf (stderr, _(" %d shift/reduce"), src_num);
+  if (src_num > 0 && rrc_num > 0)
+    fprintf (stderr, ",");
+  if (rrc_num > 0)
+    fprintf (stderr, _(" %d reduce/reduce"), rrc_num);
+  putc ('\n', stderr);
+}
+
+
 /*-----------------------------------------------------------.
 | Output the detailed description of states with conflicts.  |
 `-----------------------------------------------------------*/
@@ -443,8 +462,9 @@ conflicts_output (FILE *out)
       if (conflicts[i])
 	{
 	  fprintf (out, _("State %d contains "), i);
-	  fputs (conflict_report (count_sr_conflicts (s),
-				  count_rr_conflicts (s, TRUE)), out);
+	  fprintf (out, "%s.\n",
+		   conflict_report (count_sr_conflicts (s),
+				    count_rr_conflicts (s, TRUE)));
 	  printed_sth = TRUE;
 	}
     }
@@ -530,32 +550,15 @@ conflicts_print (void)
 
   /* Report the total number of conflicts on STDERR.  */
   if (yacc_flag)
-    {
-      /* If invoked with `--yacc', use the output format specified by
-	 POSIX.  */
-      fprintf (stderr, _("conflicts: "));
-      if (src_total > 0)
-	fprintf (stderr, _(" %d shift/reduce"), src_total);
-      if (src_total > 0 && rrc_total > 0)
-	fprintf (stderr, ",");
-      if (rrc_total > 0)
-	fprintf (stderr, _(" %d reduce/reduce"), rrc_total);
-      putc ('\n', stderr);
-    }
+    conflict_report_yacc (src_total, rrc_total);
   else
-    {
-      fprintf (stderr, _("%s contains "), infile);
-      fputs (conflict_report (src_total, rrc_total), stderr);
-    }
+    warn ("%s", conflict_report (src_total, rrc_total));
 
   if (expected_conflicts != -1 && !src_ok)
-    {
-      complain_message_count++;
-      fprintf (stderr, ngettext ("expected %d shift/reduce conflict\n",
-				 "expected %d shift/reduce conflicts\n",
-				 expected_conflicts),
-	       expected_conflicts);
-    }
+    complain (ngettext ("expected %d shift/reduce conflict",
+			"expected %d shift/reduce conflicts",
+			expected_conflicts),
+	      expected_conflicts);
 }
 
 
