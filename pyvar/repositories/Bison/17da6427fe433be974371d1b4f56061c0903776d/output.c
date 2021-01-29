@@ -1075,15 +1075,7 @@ prepare (void)
   MACRO_INSERT_INT ("ntokens", ntokens);
 
   if (spec_name_prefix)
-    {
-      MACRO_INSERT_PREFIX ("yylex", "lex");
-      MACRO_INSERT_PREFIX ("yychar", "char");
-      MACRO_INSERT_PREFIX ("yylval", "lval");
-      MACRO_INSERT_PREFIX ("yydebug", "debug");
-      MACRO_INSERT_PREFIX ("yyerror", "error");
-      MACRO_INSERT_PREFIX ("yynerrs", "nerrs");
-      MACRO_INSERT_PREFIX ("yyparse", "parse");
-    }
+    MACRO_INSERT_STRING ("prefix", spec_name_prefix);
 }
 
 /*----------------------------------------------------------.
