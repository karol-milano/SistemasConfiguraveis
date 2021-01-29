@@ -304,6 +304,10 @@ typedef struct YYLTYPE
    /* Pacify GCC's `empty if-body' warning. */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
 #  ifndef YYSTACK_ALLOC_MAXIMUM
+    /* The OS might guarantee only one guard page at the bottom of the stack,
+       and a page size can be as small as 4096 bytes.  So we cannot safely
+       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
+       to allow for a few compiler-allocated temporary stack slots.  */
 #   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
 #  endif
 # else
@@ -1158,8 +1162,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 856 of yacc.c.  */
-#line 1163 "parse-gram.c"
+/* Line 860 of yacc.c.  */
+#line 1167 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1743,8 +1747,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1052 of yacc.c.  */
-#line 1748 "parse-gram.c"
+/* Line 1056 of yacc.c.  */
+#line 1752 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1893,15 +1897,7 @@ yyerrlab:
           /* If at end of input, pop the error token,
 	     then the rest of the stack, then return failure.  */
 	  if (yychar == YYEOF)
-	     for (;;)
-	       {
-                 yyerror_range[0] = *yylsp;
-		 YYPOPSTACK;
-		 if (yyssp == yyss)
-		   YYABORT;
-		 yydestruct (_("Error: popping"),
-                             yystos[*yyssp], yyvsp, yylsp);
-	       }
+	    YYABORT;
         }
       else
 	{
@@ -2006,11 +2002,23 @@ yyabortlab:
 `----------------------------------------------*/
 yyoverflowlab:
   yyerror (_("parser stack overflow"));
+  yydestruct (_("Error: discarding lookahead"),
+	      yytoken, &yylval, &yylloc);
   yyresult = 2;
   /* Fall through.  */
 #endif
 
 yyreturn:
+  if (yyssp != yyss)
+    for (;;)
+      {
+	yyerror_range[0] = *yylsp;
+	YYPOPSTACK;
+	if (yyssp == yyss)
+	  break;
+	yydestruct (_("Error: popping"),
+		    yystos[*yyssp], yyvsp, yylsp);
+      }
 #ifndef yyoverflow
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
