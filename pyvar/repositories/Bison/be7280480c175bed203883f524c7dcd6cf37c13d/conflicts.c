@@ -387,60 +387,20 @@ count_rr_conflicts (state *s, int one_per_token)
 }
 
 
-/*--------------------------------------------------------------.
-| Return a human readable string which reports shift/reduce and |
-| reduce/reduce conflict numbers (SRC_NUM, RRC_NUM).            |
-`--------------------------------------------------------------*/
-
-static const char *
-conflict_report (int src_num, int rrc_num)
-{
-  static char res[4096];
-  char *cp = res;
-
-  if (src_num >= 1)
-    {
-      sprintf (cp, ngettext ("%d shift/reduce conflict",
-			     "%d shift/reduce conflicts", src_num), src_num);
-      cp += strlen (cp);
-    }
-
-  if (src_num > 0 && rrc_num > 0)
-    {
-      sprintf (cp, " %s ", _("and"));
-      cp += strlen (cp);
-    }
-
-  if (rrc_num >= 1)
-    {
-      sprintf (cp, ngettext ("%d reduce/reduce conflict",
-			     "%d reduce/reduce conflicts", rrc_num), rrc_num);
-      cp += strlen (cp);
-    }
-
-  *cp++ = '\0';
-
-  return res;
-}
-
-
-/*----------------------------------------------------------------.
-| Same as above, but report the number of conflicts a` la POSIX.  |
-`----------------------------------------------------------------*/
+/*--------------------------------------------------------.
+| Report the number of conflicts, using the Yacc format.  |
+`--------------------------------------------------------*/
 
 static void
-conflict_report_yacc (int src_num, int rrc_num)
+conflict_report (FILE *out, int src_num, int rrc_num)
 {
-  /* If invoked with `--yacc', use the output format specified by
-     POSIX.  */
-  fprintf (stderr, _("conflicts: "));
-  if (src_num > 0)
-    fprintf (stderr, _(" %d shift/reduce"), src_num);
-  if (src_num > 0 && rrc_num > 0)
-    fprintf (stderr, ",");
-  if (rrc_num > 0)
-    fprintf (stderr, _(" %d reduce/reduce"), rrc_num);
-  putc ('\n', stderr);
+  if (src_num && rrc_num)
+    fprintf (out, _("conflicts: %d shift/reduce, %d reduce/reduce\n"),
+	     src_num, rrc_num);
+  else if (src_num)
+    fprintf (out, _("conflicts: %d shift/reduce\n"), src_num);
+  else if (rrc_num)
+    fprintf (out, _("conflicts: %d reduce/reduce\n"), rrc_num);
 }
 
 
@@ -458,10 +418,9 @@ conflicts_output (FILE *out)
       state *s = states[i];
       if (conflicts[i])
 	{
-	  fprintf (out, _("State %d contains "), i);
-	  fprintf (out, "%s.\n",
-		   conflict_report (count_sr_conflicts (s),
-				    count_rr_conflicts (s, true)));
+	  fprintf (out, _("State %d "), i);
+	  conflict_report (out, count_sr_conflicts (s),
+			   count_rr_conflicts (s, true));
 	  printed_sth = true;
 	}
     }
@@ -529,10 +488,9 @@ conflicts_print (void)
     return;
 
   /* Report the total number of conflicts on STDERR.  */
-  if (yacc_flag)
-    conflict_report_yacc (src_total, rrc_total);
-  else
-    warn ("%s", conflict_report (src_total, rrc_total));
+  if (! yacc_flag)
+    fprintf (stderr, "%s: ", current_file);
+  conflict_report (stderr, src_total, rrc_total);
 
   if (expected_conflicts != -1)
     {
