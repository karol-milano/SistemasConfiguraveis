@@ -522,47 +522,6 @@ conflicts_output (FILE *out)
     fputs ("\n\n", out);
 }
 
-void
-conflicts_output_xml (FILE *out, int level)
-{
-  bool printed_sth = false;
-  state_number i;
-  int src_num;
-  int rrc_num;
-
-  for (i = 0; i < nstates; i++)
-    {
-      state *s = states[i];
-      if (conflicts[i])
-	{
-	  if (!printed_sth) {
-	    fputc ('\n', out);
-	    xml_puts (out, level, "<conflicts>");
-	  }
-
-	  src_num = count_sr_conflicts (s);
-	  rrc_num = count_rr_conflicts (s, true);
-
-	  if (src_num)
-	    xml_printf (out, level + 1,
-			"<conflict state=\"%d\" num=\"%d\""
-			" type=\"shift/reduce\"/>",
-			i, src_num);
-	  if (rrc_num)
-	    xml_printf (out, level + 1,
-			"<conflict state=\"%d\" num=\"%d\""
-			" type=\"reduce/reduce\"/>",
-			i, rrc_num);
-
-	  printed_sth = true;
-	}
-    }
-  if (printed_sth)
-    xml_puts (out, level, "</conflicts>");
-  else
-    xml_puts (out, level, "<conflicts/>");
-}
-
 /*--------------------------------------------------------.
 | Total the number of S/R and R/R conflicts.  Unlike the  |
 | code in conflicts_output, however, count EACH pair of   |
