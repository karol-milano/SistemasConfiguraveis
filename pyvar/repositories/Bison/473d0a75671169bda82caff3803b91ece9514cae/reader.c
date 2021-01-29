@@ -341,7 +341,7 @@ void
 grammar_current_rule_prec_set (symbol_t *precsym, location_t location)
 {
   if (current_rule->ruleprec)
-    complain_at (location, _("two @prec's in a row"));
+    complain_at (location, _("only one %s allowed per rule"), "%prec");
   current_rule->ruleprec = precsym;
 }
 
@@ -351,11 +351,12 @@ void
 grammar_current_rule_dprec_set (int dprec, location_t location)
 {
   if (! glr_parser)
-    warn_at (location, _("%%dprec affects only GLR parsers"));
+    warn_at (location, _("%s affects only GLR parsers"), "%dprec");
   if (dprec <= 0)
-    complain_at (location, _("%%dprec must be followed by positive number"));
+    complain_at (location,
+		 _("%s must be followed by positive number"), "%dprec");
   else if (current_rule->dprec != 0)
-    complain_at (location, _("only one %%dprec allowed per rule"));
+    complain_at (location, _("only one %s allowed per rule"), "%dprec");
   current_rule->dprec = dprec;
 }
 
@@ -366,9 +367,9 @@ void
 grammar_current_rule_merge_set (const char* name, location_t location)
 {
   if (! glr_parser)
-    warn_at (location, _("%%merge affects only GLR parsers"));
+    warn_at (location, _("%s affects only GLR parsers"), "%merge");
   if (current_rule->merger != 0)
-    complain_at (location, _("only one %%merge allowed per rule"));
+    complain_at (location, _("only one %s allowed per rule"), "%merge");
   current_rule->merger =
     get_merge_function (name, current_rule->sym->type_name, location);
 }
@@ -499,8 +500,8 @@ reader (void)
   finput = xfopen (infile, "r");
   gram_in = finput;
 
-  gram_debug = !!getenv ("parse");
-  gram__flex_debug = !!getenv ("scan");
+  gram__flex_debug = trace_flag & trace_scan;
+  gram_debug = trace_flag & trace_parse;
   scanner_initialize ();
   gram_parse (&gram_control);
 
