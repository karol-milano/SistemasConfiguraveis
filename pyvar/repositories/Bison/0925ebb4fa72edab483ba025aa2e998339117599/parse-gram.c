@@ -327,6 +327,9 @@ typedef struct YYLTYPE
 #  ifndef YYSTACK_ALLOC_MAXIMUM
 #   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
 #  endif
+#  ifdef __cplusplus
+extern "C" {
+#  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
 #   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
@@ -341,6 +344,9 @@ void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
+#  ifdef __cplusplus
+}
+#  endif
 # endif
 #endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
 
@@ -1165,8 +1171,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 863 of yacc.c.  */
-#line 1170 "parse-gram.c"
+/* Line 869 of yacc.c.  */
+#line 1176 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1750,8 +1756,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1059 of yacc.c.  */
-#line 1755 "parse-gram.c"
+/* Line 1065 of yacc.c.  */
+#line 1761 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
