@@ -30,6 +30,7 @@
 #include "getargs.h"
 #include "gram.h"
 #include "lalr.h"
+#include "print-xml.h"
 #include "reader.h"
 #include "state.h"
 #include "symtab.h"
@@ -39,6 +40,7 @@ int expected_sr_conflicts = -1;
 int expected_rr_conflicts = -1;
 static char *conflicts;
 static struct obstack solved_conflicts_obstack;
+static struct obstack solved_conflicts_xml_obstack;
 
 static bitset shift_set;
 static bitset lookahead_set;
@@ -72,23 +74,25 @@ log_resolution (rule *r, symbol_number token,
 	case shift_resolution:
 	case right_resolution:
 	  obstack_fgrow2 (&solved_conflicts_obstack,
-			  _("\
-    Conflict between rule %d and token %s resolved as shift"),
+			  _("    Conflict between rule %d and token %s"
+			    " resolved as shift"),
 			  r->number,
 			  symbols[token]->tag);
 	  break;
+
 	case reduce_resolution:
 	case left_resolution:
 	  obstack_fgrow2 (&solved_conflicts_obstack,
-			  _("\
-    Conflict between rule %d and token %s resolved as reduce"),
+			  _("    Conflict between rule %d and token %s"
+			    " resolved as reduce"),
 			  r->number,
 			  symbols[token]->tag);
 	  break;
+
 	case nonassoc_resolution:
 	  obstack_fgrow2 (&solved_conflicts_obstack,
-			  _("\
-    Conflict between rule %d and token %s resolved as an error"),
+			  _("    Conflict between rule %d and token %s"
+			    " resolved as an error"),
 			  r->number,
 			  symbols[token]->tag);
 	  break;
@@ -122,13 +126,87 @@ log_resolution (rule *r, symbol_number token,
 			  " (%%right %s)",
 			  symbols[token]->tag);
 	  break;
+
 	case nonassoc_resolution:
 	  obstack_fgrow1 (&solved_conflicts_obstack,
 			  " (%%nonassoc %s)",
 			  symbols[token]->tag);
 	  break;
 	}
+
       obstack_sgrow (&solved_conflicts_obstack, ".\n");
+
+      /* XML report */
+      if (xml_flag)
+	{
+	  /* The description of the resolution. */
+	  switch (resolution)
+	    {
+	    case shift_resolution:
+	    case right_resolution:
+	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
+			      "<resolution rule=\"%d\" symbol=\"%s\""
+			      " type=\"shift\">",
+			      r->number,
+			      xml_escape (symbols[token]->tag));
+	      break;
+
+	    case reduce_resolution:
+	    case left_resolution:
+	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
+			      "<resolution rule=\"%d\" symbol=\"%s\""
+			      " type=\"reduce\">",
+			      r->number,
+			      xml_escape (symbols[token]->tag));
+	      break;
+
+	    case nonassoc_resolution:
+	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
+			      "<resolution rule=\"%d\" symbol=\"%s\""
+			      " type=\"error\">",
+			      r->number,
+			      xml_escape (symbols[token]->tag));
+	      break;
+	    }
+
+	  /* The reason. */
+	  switch (resolution)
+	    {
+	    case shift_resolution:
+	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
+			      "%s &lt; %s",
+			      xml_escape_n (0, r->prec->tag),
+			      xml_escape_n (1, symbols[token]->tag));
+	      break;
+
+	    case reduce_resolution:
+	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
+			      "%s &lt; %s",
+			      xml_escape_n (0, symbols[token]->tag),
+			      xml_escape_n (1, r->prec->tag));
+	      break;
+
+	    case left_resolution:
+	      obstack_fgrow1 (&solved_conflicts_xml_obstack,
+			      "%%left %s",
+			      xml_escape (symbols[token]->tag));
+	      break;
+
+	    case right_resolution:
+	      obstack_fgrow1 (&solved_conflicts_xml_obstack,
+			      "%%right %s",
+			      xml_escape (symbols[token]->tag));
+	      break;
+
+	    case nonassoc_resolution:
+	      obstack_fgrow1 (&solved_conflicts_xml_obstack,
+			      "%%nonassoc %s",
+			      xml_escape (symbols[token]->tag));
+	  break;
+	    }
+
+	  obstack_sgrow (&solved_conflicts_xml_obstack, "</resolution>\n");
+	}
     }
 }
 
@@ -281,6 +359,11 @@ set_conflicts (state *s, symbol **errors)
       obstack_1grow (&solved_conflicts_obstack, '\0');
       s->solved_conflicts = obstack_finish (&solved_conflicts_obstack);
     }
+  if (obstack_object_size (&solved_conflicts_xml_obstack))
+    {
+      obstack_1grow (&solved_conflicts_xml_obstack, '\0');
+      s->solved_conflicts_xml = obstack_finish (&solved_conflicts_xml_obstack);
+    }
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
@@ -309,6 +392,7 @@ conflicts_solve (void)
   shift_set = bitset_create (ntokens, BITSET_FIXED);
   lookahead_set = bitset_create (ntokens, BITSET_FIXED);
   obstack_init (&solved_conflicts_obstack);
+  obstack_init (&solved_conflicts_xml_obstack);
 
   for (i = 0; i < nstates; i++)
     {
@@ -438,6 +522,47 @@ conflicts_output (FILE *out)
     fputs ("\n\n", out);
 }
 
+void
+conflicts_output_xml (FILE *out, int level)
+{
+  bool printed_sth = false;
+  state_number i;
+  int src_num;
+  int rrc_num;
+
+  for (i = 0; i < nstates; i++)
+    {
+      state *s = states[i];
+      if (conflicts[i])
+	{
+	  if (!printed_sth) {
+	    fputc ('\n', out);
+	    xml_puts (out, level, "<conflicts>");
+	  }
+
+	  src_num = count_sr_conflicts (s);
+	  rrc_num = count_rr_conflicts (s, true);
+
+	  if (src_num)
+	    xml_printf (out, level + 1,
+			"<conflict state=\"%d\" num=\"%d\""
+			" type=\"shift/reduce\"/>",
+			i, src_num);
+	  if (rrc_num)
+	    xml_printf (out, level + 1,
+			"<conflict state=\"%d\" num=\"%d\""
+			" type=\"reduce/reduce\"/>",
+			i, rrc_num);
+
+	  printed_sth = true;
+	}
+    }
+  if (printed_sth)
+    xml_puts (out, level, "</conflicts>");
+  else
+    xml_puts (out, level, "<conflicts/>");
+}
+
 /*--------------------------------------------------------.
 | Total the number of S/R and R/R conflicts.  Unlike the  |
 | code in conflicts_output, however, count EACH pair of   |
@@ -540,4 +665,5 @@ conflicts_free (void)
   bitset_free (shift_set);
   bitset_free (lookahead_set);
   obstack_free (&solved_conflicts_obstack, NULL);
+  obstack_free (&solved_conflicts_xml_obstack, NULL);
 }
