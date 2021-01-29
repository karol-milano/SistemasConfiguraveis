@@ -180,11 +180,11 @@ print_errs (FILE *out, const state *s)
 }
 
 
-/*-------------------------------------------------------------------------.
+/*-------------------------------------------------------------------.
 | Report a reduction of RULE on LOOKAHEAD (which can be 'default').  |
-| If not ENABLED, the rule is masked by a shift or a reduce (S/R and       |
-| R/R conflicts).                                                          |
-`-------------------------------------------------------------------------*/
+| If not ENABLED, the rule is masked by a shift or a reduce (S/R and |
+| R/R conflicts).                                                    |
+`-------------------------------------------------------------------*/
 
 static void
 print_reduction (FILE *out, size_t width,
