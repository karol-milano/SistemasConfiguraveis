@@ -245,7 +245,7 @@ print_reductions (FILE *out, state *s)
   rule *default_reduction = NULL;
   size_t width = 0;
   int i, j;
-  bool non_default_action = false;
+  bool default_reduction_only = true;
 
   if (reds->num == 0)
     return;
@@ -299,7 +299,7 @@ print_reductions (FILE *out, state *s)
 	bool defaulted = false;
 	bool count = bitset_test (no_reduce_set, i);
         if (count)
-          non_default_action = true;
+          default_reduction_only = false;
 
 	for (j = 0; j < reds->num; ++j)
 	  if (bitset_test (reds->lookahead_tokens[j], i))
@@ -308,7 +308,7 @@ print_reductions (FILE *out, state *s)
 		{
 		  if (reds->rules[j] != default_reduction)
                     {
-                      non_default_action = true;
+                      default_reduction_only = false;
                       print_reduction (out, width,
                                        symbols[i]->tag,
                                        reds->rules[j], true);
@@ -319,7 +319,7 @@ print_reductions (FILE *out, state *s)
 		}
 	      else
 		{
-                  non_default_action = true;
+                  default_reduction_only = false;
 		  if (defaulted)
 		    print_reduction (out, width,
 				     symbols[i]->tag,
@@ -339,7 +339,7 @@ print_reductions (FILE *out, state *s)
       print_reduction (out, width, _("$default"), default_reduction, true);
       aver (0 == strcmp (default_reductions, "all")
             || (0 == strcmp (default_reductions, "consistent")
-                && !non_default_action)
+                && default_reduction_only)
             || (reds->num == 1 && reds->rules[0]->number == 0));
       free (default_reductions);
     }
