@@ -714,7 +714,7 @@ do {                                                                      \
     }                                                                     \
 } while (YYID (0))
 
-]b4_yy_symbol_print_generate[
+]b4_yy_symbol_print_define[
 
 /*------------------------------------------------------------------.
 | yy_stack_print -- Print the state stack from its BOTTOM up to its |
@@ -1284,7 +1284,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 }
 #endif /* YYERROR_VERBOSE */
 
-]b4_yydestruct_generate[
+]b4_yydestruct_define[
 
 ]b4_pure_if([], [
 
