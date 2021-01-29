@@ -261,7 +261,21 @@ b4_syncline([@oline@], [@ofile@])[
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#define YYUSE(e) do {;} while (/*CONSTCOND*/ 0 && (e))
+#ifndef lint
+# define YYUSE(e) ((void) (e))
+#else
+# define YYUSE(e) /* empty */
+#endif
+
+/* Identity function, used to suppress warnings about constant conditions.  */
+#ifndef lint
+# define YYID(n) (n)
+#else
+]b4_c_function_def([YYID], [static int], [[int i], [i]])[
+{
+  return i;
+}
+#endif
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -292,7 +306,7 @@ b4_syncline([@oline@], [@ofile@])[
 
 # ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning. */
-#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
+#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
 #  ifndef YYSTACK_ALLOC_MAXIMUM
     /* The OS might guarantee only one guard page at the bottom of the stack,
        and a page size can be as small as 4096 bytes.  So we cannot safely
@@ -369,7 +383,7 @@ union yyalloc
 	  for (yyi = 0; yyi < (Count); yyi++)	\
 	    (To)[yyi] = (From)[yyi];		\
 	}					\
-      while (/*CONSTCOND*/ 0)
+      while (YYID (0))
 #  endif
 # endif
 
@@ -387,7 +401,7 @@ union yyalloc
 	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
 	yyptr += yynewbytes / sizeof (*yyptr);				\
       }									\
-    while (/*CONSTCOND*/ 0)
+    while (YYID (0))
 
 #endif
 
@@ -558,7 +572,7 @@ do								\
       yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
-while (/*CONSTCOND*/ 0)
+while (YYID (0))
 
 
 #define YYTERROR	1
@@ -587,7 +601,7 @@ while (/*CONSTCOND*/ 0)
 	  (Current).first_column = (Current).last_column =		\
 	    YYRHSLOC (Rhs, 0).last_column;				\
 	}								\
-    while (/*CONSTCOND*/ 0)
+    while (YYID (0))
 #endif
 
 
@@ -627,7 +641,7 @@ while (/*CONSTCOND*/ 0)
 do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
 do {									  \
@@ -638,7 +652,7 @@ do {									  \
                   Type, Value]b4_location_if([, Location])[]b4_user_args[); \
       YYFPRINTF (stderr, "\n");						  \
     }									  \
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 ]b4_yysymprint_generate([b4_c_function_def])[
 
@@ -661,7 +675,7 @@ do {									  \
 do {								\
   if (yydebug)							\
     yy_stack_print ((Bottom), (Top));				\
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 
 /*------------------------------------------------.
@@ -695,7 +709,7 @@ do {								\
 do {					\
   if (yydebug)				\
     yy_reduce_print (yyvsp, ]b4_location_if([yylsp, ])[Rule]b4_user_args[); \
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
@@ -741,12 +755,10 @@ yystrlen (yystr)
      const char *yystr;
 #   endif
 {
-  const char *yys = yystr;
-
-  while (*yys++ != '\0')
+  YYSIZE_T yylen;
+  for (yylen = 0; yystr[yylen]; yylen++)
     continue;
-
-  return yys - yystr - 1;
+  return yylen;
 }
 #  endif
 # endif
@@ -894,7 +906,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
               }
             yyarg[yycount++] = yytname[yyx];
             yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-            yysize_overflow |= yysize1 < yysize;
+            yysize_overflow |= (yysize1 < yysize);
             yysize = yysize1;
             yyfmt = yystpcpy (yyfmt, yyprefix);
             yyprefix = yyor;
@@ -902,7 +914,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
       yyf = YY_(yyformat);
       yysize1 = yysize + yystrlen (yyf);
-      yysize_overflow |= yysize1 < yysize;
+      yysize_overflow |= (yysize1 < yysize);
       yysize = yysize1;
 
       if (yysize_overflow)
@@ -915,7 +927,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
              produced a string with the wrong number of "%s"s.  */
           char *yyp = yyresult;
           int yyi = 0;
-          while ((*yyp = *yyf))
+          while ((*yyp = *yyf) != '\0')
             {
               if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
                 {
