@@ -491,7 +491,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
       YYFPRINTF Args;                           \
   } while (YYID (0))
 
-]b4_yy_symbol_print_generate([b4_function_define])[
+]b4_yy_symbol_print_generate[
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
   do {                                                                  \
@@ -872,7 +872,7 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 
                               /* Bison grammar-table manipulation.  */
 
-]b4_yydestruct_generate([b4_function_define])[
+]b4_yydestruct_generate[
 
 /** Number of symbols composing the right hand side of rule #RULE.  */
 static inline int
