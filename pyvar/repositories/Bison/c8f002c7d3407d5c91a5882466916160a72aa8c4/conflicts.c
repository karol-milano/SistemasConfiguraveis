@@ -451,15 +451,10 @@ void
 conflicts_output (FILE *out)
 {
   bool printed_sth = FALSE;
-  bool *used_rules = XCALLOC (bool, nrules);
   state_number_t i;
   for (i = 0; i < nstates; i++)
     {
       state_t *s = states[i];
-      reductions_t *reds = s->reductions;
-      int j;
-      for (j = 0; j < reds->num; ++j)
-	used_rules[reds->rules[j]->number] = TRUE;
       if (conflicts[i])
 	{
 	  fprintf (out, _("State %d contains "), i);
@@ -471,23 +466,6 @@ conflicts_output (FILE *out)
     }
   if (printed_sth)
     fputs ("\n\n", out);
-
-  for (i = 0; i < nstates; i++)
-    {
-      state_t *s = states[i];
-      reductions_t *r = s->reductions;
-      int j;
-      for (j = 0; j < r->num; ++j)
-	if (!used_rules[r->rules[j]->number])
-	  {
-	    LOCATION_PRINT (stderr, r->rules[j]->location);
-	    fprintf (stderr, ": %s: %s: ",
-		     _("warning"),
-		     _("rule never reduced because of conflicts"));
-	    rule_print (r->rules[j], stderr);
-	  }
-    }
-  free (used_rules);
 }
 
 /*--------------------------------------------------------.
