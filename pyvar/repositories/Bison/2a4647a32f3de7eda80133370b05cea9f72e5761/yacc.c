@@ -246,6 +246,9 @@ b4_syncline([@oline@], [@ofile@])[
 # endif
 #endif
 
+/* Suppress unused-variable warnings by "using" E.  */
+#define YYUSE(e) do {;} while (/*CONSTCOND*/ 0 && (e))
+
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
@@ -355,7 +358,7 @@ union yyalloc
 	  for (yyi = 0; yyi < (Count); yyi++)	\
 	    (To)[yyi] = (From)[yyi];		\
 	}					\
-      while (0)
+      while (/*CONSTCOND*/ 0)
 #  endif
 # endif
 
@@ -373,7 +376,7 @@ union yyalloc
 	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
 	yyptr += yynewbytes / sizeof (*yyptr);				\
       }									\
-    while (0)
+    while (/*CONSTCOND*/ 0)
 
 #endif
 
@@ -544,7 +547,7 @@ do								\
       yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
-while (0)
+while (/*CONSTCOND*/ 0)
 
 
 #define YYTERROR	1
@@ -573,7 +576,7 @@ while (0)
 	  (Current).first_column = (Current).last_column =		\
 	    YYRHSLOC (Rhs, 0).last_column;				\
 	}								\
-    while (0)
+    while (/*CONSTCOND*/ 0)
 #endif
 
 
@@ -613,7 +616,7 @@ while (0)
 do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
 do {								\
@@ -624,7 +627,7 @@ do {								\
                   Type, Value]b4_location_if([, Location])[);	\
       YYFPRINTF (stderr, "\n");					\
     }								\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 /*------------------------------------------------------------------.
 | yy_stack_print -- Print the state stack from its BOTTOM up to its |
@@ -645,7 +648,7 @@ do {								\
 do {								\
   if (yydebug)							\
     yy_stack_print ((Bottom), (Top));				\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 
 /*------------------------------------------------.
@@ -669,7 +672,7 @@ do {								\
 do {					\
   if (yydebug)				\
     yy_reduce_print (Rule);		\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
@@ -1351,7 +1354,7 @@ yyerrorlab:
   /* Pacify compilers like GCC when the user code never invokes
      YYERROR and the label yyerrorlab therefore never appears in user
      code.  */
-  if (0)
+  if (/*CONSTCOND*/ 0)
      goto yyerrorlab;
 
 ]b4_location_if([[  yyerror_range[0] = yylsp[1-yylen];
