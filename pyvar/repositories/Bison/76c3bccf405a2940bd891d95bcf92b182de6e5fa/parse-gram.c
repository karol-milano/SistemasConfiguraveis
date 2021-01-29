@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.90.  */
+/* A Bison parser, made by GNU Bison 3.5.91.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.90"
+#define YYBISON_VERSION "3.5.91"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1304,8 +1304,8 @@ yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
                        YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
-                       &yyvsp[(yyi + 1) - (yynrhs)]
-                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
+                       &yyvsp[(yyi + 1) - (yynrhs)],
+                       &(yylsp[(yyi + 1) - (yynrhs)]));
       YYFPRINTF (stderr, "\n");
     }
 }
@@ -2738,10 +2738,8 @@ yyerrlab1:
   YY_IGNORE_MAYBE_UNINITIALIZED_END
 
   yyerror_range[2] = yylloc;
-  /* Using YYLLOC is tempting, but would change the location of
-     the lookahead.  YYLOC is available though.  */
-  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
-  *++yylsp = yyloc;
+  ++yylsp;
+  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);
 
   /* Shift the error token.  */
   YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);
