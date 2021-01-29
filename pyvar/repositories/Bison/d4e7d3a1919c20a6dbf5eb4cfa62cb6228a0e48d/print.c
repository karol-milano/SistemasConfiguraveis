@@ -105,6 +105,32 @@ print_core (FILE *out, state_t *state)
 	  for (/* Nothing */; *sp >= 0; ++sp)
 	    fprintf (out, " %s", escape (symbols[*sp]->tag));
 
+	  /* Experimental feature: display the lookaheads. */
+	  if (trace_flag && state->nlookaheads)
+	    {
+	      int j, k;
+	      int nlookaheads = 0;
+	      /* Look for lookaheads corresponding to this rule. */
+	      for (j = 0; j < state->nlookaheads; ++j)
+		for (k = 0; k < ntokens; ++k)
+		  if (bitset_test (LA[state->lookaheadsp + j], k)
+		      && LArule[state->lookaheadsp + j]->number == rule)
+		    nlookaheads++;
+	      if (nlookaheads)
+		{
+		  fprintf (out, "  [");
+		  for (j = 0; j < state->nlookaheads; ++j)
+		    for (k = 0; k < ntokens; ++k)
+		      if (bitset_test (LA[state->lookaheadsp + j], k)
+			  && LArule[state->lookaheadsp + j]->number == rule)
+			fprintf (out, "%s%s",
+				 quotearg_style (escape_quoting_style,
+						 symbols[k]->tag),
+				 --nlookaheads ? ", " : "");
+		  fprintf (out, "]");
+		}
+	    }
+
 	  fprintf (out, _("   (rule %d)"), rule - 1);
 	  fputc ('\n', out);
 	}
