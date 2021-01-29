@@ -97,7 +97,7 @@ print_core (FILE *out, state_t *state)
       while (*sp >= 0)
 	sp++;
 
-      rule = -(*sp);
+      rule = item_number_as_rule_number (*sp);
 
       rule_lhs_print (&rules[rule], previous_lhs, out);
       previous_lhs = rules[rule].lhs;
@@ -288,7 +288,7 @@ print_reduction (FILE *out, size_t width,
   if (!enabled)
     fputc ('[', out);
   fprintf (out, _("reduce using rule %d (%s)"),
-	   rule->number - 1, rule->lhs->tag);
+	   rule->number, rule->lhs->tag);
   if (!enabled)
     fputc (']', out);
   fputc ('\n', out);
@@ -473,12 +473,12 @@ print_grammar (FILE *out)
 	END_TEST (50);
 	sprintf (buffer, " (%d)", i);
 
-	for (r = 1; r < nrules + 1; r++)
+	for (r = 0; r < nrules; r++)
 	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
 	    if (item_number_as_symbol_number (*rhsp) == token_translations[i])
 	      {
 		END_TEST (65);
-		sprintf (buffer + strlen (buffer), " %d", r - 1);
+		sprintf (buffer + strlen (buffer), " %d", r);
 		break;
 	      }
 	fprintf (out, "%s\n", buffer);
@@ -493,7 +493,7 @@ print_grammar (FILE *out)
       rule_number_t r;
       const char *tag = symbols[i]->tag;
 
-      for (r = 1; r < nrules + 1; r++)
+      for (r = 0; r < nrules; r++)
 	{
 	  item_number_t *rhsp;
 	  if (rules[r].lhs->number == i)
@@ -517,11 +517,11 @@ print_grammar (FILE *out)
 	  END_TEST (50);
 	  sprintf (buffer + strlen (buffer), _(" on left:"));
 
-	  for (r = 1; r < nrules + 1; r++)
+	  for (r = 0; r < nrules; r++)
 	    {
 	      END_TEST (65);
 	      if (rules[r].lhs->number == i)
-		sprintf (buffer + strlen (buffer), " %d", r - 1);
+		sprintf (buffer + strlen (buffer), " %d", r);
 	    }
 	}
 
@@ -531,14 +531,14 @@ print_grammar (FILE *out)
 	    sprintf (buffer + strlen (buffer), ",");
 	  END_TEST (50);
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
-	  for (r = 1; r < nrules + 1; r++)
+	  for (r = 0; r < nrules; r++)
 	    {
 	      item_number_t *rhsp;
 	      for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
 		if (item_number_as_symbol_number (*rhsp) == i)
 		  {
 		    END_TEST (65);
-		    sprintf (buffer + strlen (buffer), " %d", r - 1);
+		    sprintf (buffer + strlen (buffer), " %d", r);
 		    break;
 		  }
 	    }
