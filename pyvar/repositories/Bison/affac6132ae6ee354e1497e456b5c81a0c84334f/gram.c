@@ -65,7 +65,7 @@ rule_useful_p (rule *r)
 bool
 rule_useless_p (rule *r)
 {
-  return r->number >= nrules;
+  return !rule_useful_p (r);
 }
 
 
@@ -77,7 +77,7 @@ rule_useless_p (rule *r)
 bool
 rule_never_reduced_p (rule *r)
 {
-  return !r->useful && r->number < nrules;
+  return !r->useful && rule_useful_p (r);
 }
 
 
@@ -317,8 +317,7 @@ grammar_rules_never_reduced_report (const char *message)
     if (!rules[r].useful)
       {
 	location_print (stderr, rules[r].location);
-	fprintf (stderr, ": %s: %s: ",
-		 _("warning"), message);
+	fprintf (stderr, ": %s: %s: ", _("warning"), message);
 	rule_print (&rules[r], stderr);
       }
 }
