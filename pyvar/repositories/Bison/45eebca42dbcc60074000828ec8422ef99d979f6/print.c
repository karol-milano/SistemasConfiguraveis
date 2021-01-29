@@ -206,7 +206,7 @@ print_errs (FILE *out, state *s)
 
 
 /*-------------------------------------------------------------------------.
-| Report a reduction of RULE on LOOKAHEAD_TOKEN (which can be `default').  |
+| Report a reduction of RULE on LOOKAHEAD_TOKEN (which can be 'default').  |
 | If not ENABLED, the rule is masked by a shift or a reduce (S/R and       |
 | R/R conflicts).                                                          |
 `-------------------------------------------------------------------------*/
@@ -514,7 +514,7 @@ print_results (void)
   print_grammar (out);
 
   /* If the whole state item sets, not only the kernels, are wanted,
-     `closure' will be run, which needs memory allocation/deallocation.   */
+     'closure' will be run, which needs memory allocation/deallocation.   */
   if (report_flag & report_itemsets)
     new_closure (nritems);
   /* Storage for print_reductions.  */
