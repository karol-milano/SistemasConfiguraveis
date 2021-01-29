@@ -316,7 +316,7 @@ grammar_rules_never_reduced_report (const char *message)
   for (r = 0; r < nrules ; ++r)
     if (!rules[r].useful)
       {
-	LOCATION_PRINT (stderr, rules[r].location);
+	location_print (stderr, rules[r].location);
 	fprintf (stderr, ": %s: %s: ",
 		 _("warning"), message);
 	rule_print (&rules[r], stderr);
