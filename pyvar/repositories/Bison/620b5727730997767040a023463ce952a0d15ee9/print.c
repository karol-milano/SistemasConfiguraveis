@@ -242,7 +242,7 @@ print_reductions (FILE *out, state *s)
 {
   transitions *trans = s->transitions;
   reductions *reds = s->reductions;
-  rule *default_rule = NULL;
+  rule *default_reduction = NULL;
   size_t width = 0;
   int i, j;
   bool non_default_action = false;
@@ -251,7 +251,7 @@ print_reductions (FILE *out, state *s)
     return;
 
   if (yydefact[s->number] != 0)
-    default_rule = &rules[yydefact[s->number] - 1];
+    default_reduction = &rules[yydefact[s->number] - 1];
 
   bitset_zero (no_reduce_set);
   FOR_EACH_SHIFT (trans, i)
@@ -261,7 +261,7 @@ print_reductions (FILE *out, state *s)
       bitset_set (no_reduce_set, s->errs->symbols[i]->number);
 
   /* Compute the width of the lookahead token column.  */
-  if (default_rule)
+  if (default_reduction)
     width = strlen (_("$default"));
 
   if (reds->lookahead_tokens)
@@ -274,7 +274,7 @@ print_reductions (FILE *out, state *s)
 	    {
 	      if (! count)
 		{
-		  if (reds->rules[j] != default_rule)
+		  if (reds->rules[j] != default_reduction)
 		    max_length (&width, symbols[i]->tag);
 		  count = true;
 		}
@@ -306,7 +306,7 @@ print_reductions (FILE *out, state *s)
 	    {
 	      if (! count)
 		{
-		  if (reds->rules[j] != default_rule)
+		  if (reds->rules[j] != default_reduction)
                     {
                       non_default_action = true;
                       print_reduction (out, width,
@@ -323,7 +323,7 @@ print_reductions (FILE *out, state *s)
 		  if (defaulted)
 		    print_reduction (out, width,
 				     symbols[i]->tag,
-				     default_rule, true);
+				     default_reduction, true);
 		  defaulted = false;
 		  print_reduction (out, width,
 				   symbols[i]->tag,
@@ -332,15 +332,16 @@ print_reductions (FILE *out, state *s)
 	    }
       }
 
-  if (default_rule)
+  if (default_reduction)
     {
-      char *default_rules = muscle_percent_define_get ("lr.default_rules");
-      print_reduction (out, width, _("$default"), default_rule, true);
-      aver (0 == strcmp (default_rules, "all")
-            || (0 == strcmp (default_rules, "consistent")
+      char *default_reductions =
+        muscle_percent_define_get ("lr.default_reductions");
+      print_reduction (out, width, _("$default"), default_reduction, true);
+      aver (0 == strcmp (default_reductions, "all")
+            || (0 == strcmp (default_reductions, "consistent")
                 && !non_default_action)
             || (reds->num == 1 && reds->rules[0]->number == 0));
-      free (default_rules);
+      free (default_reductions);
     }
 }
 
