@@ -544,7 +544,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
     if (yydebug)                                                        \
       {                                                                 \
         YYFPRINTF (stderr, "%s ", Title);                               \
-      yy_symbol_print (stderr, Type, Value]b4_locuser_args([Location])[);        \
+        yy_symbol_print (stderr, Type, Value]b4_locuser_args([Location])[);        \
         YYFPRINTF (stderr, "\n");                                       \
       }                                                                 \
   } while (YYID (0))
