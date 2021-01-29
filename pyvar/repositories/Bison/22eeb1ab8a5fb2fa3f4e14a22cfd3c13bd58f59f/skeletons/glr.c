@@ -669,12 +669,12 @@ yysymbol_name (yysymbol_kind_t yysymbol)
 
 ]b4_yy_symbol_print_define[
 
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
+# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
   do {                                                                  \
     if (yydebug)                                                        \
       {                                                                 \
         YY_FPRINTF ((stderr, "%s ", Title));                            \
-        yy_symbol_print (stderr, Type, Value]b4_locuser_args([Location])[);        \
+        yy_symbol_print (stderr, Kind, Value]b4_locuser_args([Location])[);        \
         YY_FPRINTF ((stderr, "\n"));                                    \
       }                                                                 \
   } while (0)
@@ -691,7 +691,7 @@ static void yypdumpstack (yyGLRStack* yystackp)
 #else /* !]b4_api_PREFIX[DEBUG */
 
 # define YY_DPRINTF(Args) do {} while (yyfalse)
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
+# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
 
 #endif /* !]b4_api_PREFIX[DEBUG */
 
