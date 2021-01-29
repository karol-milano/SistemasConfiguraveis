@@ -689,7 +689,7 @@ yysymbol_name (yysymbol_kind_t yysymbol)
 }
 #endif
 
-# ifdef YYPRINT
+#ifdef YYPRINT
 /* YYTOKNUM[NUM] -- (External) token number corresponding to the
    (internal) symbol number NUM (which must be that of a token).  */
 static const yytype_int16 yytoknum[] =
@@ -702,7 +702,7 @@ static const yytype_int16 yytoknum[] =
      305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      315
 };
-# endif
+#endif
 
 #define YYPACT_NINF (-80)
 
@@ -977,8 +977,8 @@ do {                                            \
    This macro was not mandated originally: define only if we know
    we won't break user code: when these are the locations we know.  */
 
-#ifndef YY_LOCATION_PRINT
-# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
+# ifndef YY_LOCATION_PRINT
+#  if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
 
 /* Print *YYLOCP on YYO.  Private, do not rely on its existence. */
 
@@ -1008,13 +1008,13 @@ yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
   return res;
  }
 
-#  define YY_LOCATION_PRINT(File, Loc)          \
+#   define YY_LOCATION_PRINT(File, Loc)          \
   yy_location_print_ (File, &(Loc))
 
-# else
-#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
-# endif
-#endif
+#  else
+#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
+#  endif
+# endif /* !defined YY_LOCATION_PRINT */
 
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
@@ -1906,7 +1906,7 @@ yysetstate:
         YYSTACK_RELOCATE (yyss_alloc, yyss);
         YYSTACK_RELOCATE (yyvs_alloc, yyvs);
         YYSTACK_RELOCATE (yyls_alloc, yyls);
-# undef YYSTACK_RELOCATE
+#  undef YYSTACK_RELOCATE
         if (yyss1 != yyssa)
           YYSTACK_FREE (yyss1);
       }
