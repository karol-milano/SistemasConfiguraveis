@@ -202,11 +202,11 @@ print_errs (FILE *out, int level, state *s)
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
 print_reduction (FILE *out, int level, char const *lookahead,
