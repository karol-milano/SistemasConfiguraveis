@@ -41,8 +41,8 @@ m4_define_default([b4_stack_depth_init],  [200])
 # Expand IF-TRUE, if %pure-parser and %parse-param, IF-FALSE otherwise.
 m4_define([b4_yacc_pure_if],
 [b4_pure_if([m4_ifset([b4_parse_param],
-                      [$1], [$2])],
-            [$2])])
+		      [$1], [$2])],
+	    [$2])])
 
 
 # b4_yyerror_args
@@ -82,7 +82,7 @@ m4_define([b4_int_type],
 
        m4_eval([0 <= $1]),                [1], [unsigned int],
 
-	                                       [int])])
+					       [int])])
 
 
 ## ----------------- ##
@@ -187,9 +187,9 @@ b4_location_if([#define yylloc b4_prefix[]lloc])])[
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
+#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
-[typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])
+[typedef union[]m4_bregexp(b4_stype, [^{], [ YYSTYPE])
 b4_stype
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])
@@ -200,7 +200,7 @@ b4_syncline([@oline@], [@ofile@])
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
-]b4_location_if([#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
+]b4_location_if([#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
   int first_line;
@@ -221,11 +221,11 @@ typedef struct YYLTYPE
 b4_syncline([@oline@], [@ofile@])[
 
 #ifndef YYSIZE_T
-# if defined (__SIZE_TYPE__)
+# ifdef __SIZE_TYPE__
 #  define YYSIZE_T __SIZE_TYPE__
-# elif defined (size_t)
+# elif defined size_t
 #  define YYSIZE_T size_t
-# elif ! defined (YYSIZE_T) && ]b4_c_modern[
+# elif ! defined YYSIZE_T && ]b4_c_modern[
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
@@ -248,7 +248,7 @@ b4_syncline([@oline@], [@ofile@])[
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#if !defined (lint) || defined (__GNUC__)
+#if ! defined lint || defined __GNUC__
 # define YYUSE(e) ((void) (e))
 #else
 # define YYUSE(e) /* empty */
@@ -264,7 +264,7 @@ b4_syncline([@oline@], [@ofile@])[
 }
 #endif
 
-#if ! defined (yyoverflow) || YYERROR_VERBOSE
+#if ! defined yyoverflow || YYERROR_VERBOSE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
@@ -272,16 +272,16 @@ b4_syncline([@oline@], [@ofile@])[
 #  if YYSTACK_USE_ALLOCA
 #   ifdef __GNUC__
 #    define YYSTACK_ALLOC __builtin_alloca
-#   elif defined (__BUILTIN_VA_ARG_INCR)
+#   elif defined __BUILTIN_VA_ARG_INCR
 #    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
-#   elif defined (_AIX)
+#   elif defined _AIX
 #    define YYSTACK_ALLOC __alloca
-#   elif defined (_MSC_VER)
+#   elif defined _MSC_VER
 #    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
 #    define alloca _alloca
 #   else
 #    define YYSTACK_ALLOC alloca
-#    if ! defined (_ALLOCA_H) && ! defined (_STDLIB_H) && ]b4_c_modern[
+#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && ]b4_c_modern[
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #     ifndef _STDLIB_H
 #      define _STDLIB_H 1
@@ -312,13 +312,13 @@ extern "C" {
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
-#   if ! defined (malloc) && ! defined (_STDLIB_H) && ]b4_c_modern[
+#   if ! defined malloc && ! defined _STDLIB_H && ]b4_c_modern[
 void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 #  ifndef YYFREE
 #   define YYFREE free
-#   if ! defined (free) && ! defined (_STDLIB_H) && ]b4_c_modern[
+#   if ! defined free && ! defined _STDLIB_H && ]b4_c_modern[
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
@@ -326,13 +326,13 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 }
 #  endif
 # endif
-#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
+#endif /* ! defined yyoverflow || YYERROR_VERBOSE */
 
 
-#if (! defined (yyoverflow) \
-     && (! defined (__cplusplus) \
-	 || (]b4_location_if([[defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
-             && ]])[defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))
+#if (! defined yyoverflow \
+     && (! defined __cplusplus \
+	 || (]b4_location_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
+	     && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
@@ -359,7 +359,7 @@ union yyalloc
 /* Copy COUNT objects from FROM to TO.  The source and destination do
    not overlap.  */
 # ifndef YYCOPY
-#  if defined (__GNUC__) && 1 < __GNUC__
+#  if defined __GNUC__ && 1 < __GNUC__
 #   define YYCOPY(To, From, Count) \
       __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
 #  else
@@ -600,8 +600,8 @@ while (YYID (0))
 # if YYLTYPE_IS_TRIVIAL
 #  define YY_LOCATION_PRINT(File, Loc)			\
      fprintf (File, "%d.%d-%d.%d",			\
-              (Loc).first_line, (Loc).first_column,	\
-              (Loc).last_line,  (Loc).last_column)
+	      (Loc).first_line, (Loc).first_column,	\
+	      (Loc).last_line,  (Loc).last_column)
 # else
 #  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
@@ -636,7 +636,7 @@ do {									  \
     {									  \
       YYFPRINTF (stderr, "%s ", Title);					  \
       yy_symbol_print (stderr,						  \
-                  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
+		  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
       YYFPRINTF (stderr, "\n");						  \
     }									  \
 } while (YYID (0))
@@ -649,8 +649,8 @@ do {									  \
 `------------------------------------------------------------------*/
 
 ]b4_c_function_def([yy_stack_print], [static void],
-                   [[short int *bottom], [bottom]],
-                   [[short int *top],    [top]])[
+		   [[short int *bottom], [bottom]],
+		   [[short int *top],    [top]])[
 {
   YYFPRINTF (stderr, "Stack now");
   for (; bottom <= top; ++bottom)
@@ -670,24 +670,24 @@ do {								\
 `------------------------------------------------*/
 
 ]b4_c_function_def([yy_reduce_print], [static void],
-                   [[YYSTYPE *yyvsp], [yyvsp]],
+		   [[YYSTYPE *yyvsp], [yyvsp]],
     b4_location_if([[[YYLTYPE *yylsp], [yylsp]],])
 		   [[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,])
-                   b4_parse_param)[
+		   b4_parse_param)[
 {
   int yynrhs = yyr2[yyrule];
   int yyi;
   unsigned long int yylno = yyrline[yyrule];
   YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
-             yyrule - 1, yylno);
+	     yyrule - 1, yylno);
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       fprintf (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
-                       &]b4_rhs_value(yynrhs, yyi + 1)[
-                       ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
-	               b4_user_args[);
+		       &]b4_rhs_value(yynrhs, yyi + 1)[
+		       ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+		       b4_user_args[);
       fprintf (stderr, "\n");
     }
 }
@@ -730,7 +730,7 @@ int yydebug;
 #if YYERROR_VERBOSE
 
 # ifndef yystrlen
-#  if defined (__GLIBC__) && defined (_STRING_H)
+#  if defined __GLIBC__ && defined _STRING_H
 #   define yystrlen strlen
 #  else
 /* Return the length of YYSTR.  */
@@ -746,7 +746,7 @@ int yydebug;
 # endif
 
 # ifndef yystpcpy
-#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
+#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
 #   define yystpcpy stpcpy
 #  else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
@@ -840,7 +840,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
 # if 0
       /* This is so xgettext sees the translatable formats that are
-         constructed on the fly.  */
+	 constructed on the fly.  */
       YY_("syntax error, unexpected %s");
       YY_("syntax error, unexpected %s, expecting %s");
       YY_("syntax error, unexpected %s, expecting %s or %s");
@@ -853,13 +853,13 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       static char const yyexpecting[] = ", expecting %s";
       static char const yyor[] = " or %s";
       char yyformat[sizeof yyunexpected
-                    + sizeof yyexpecting - 1
-                    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
-                       * (sizeof yyor - 1))];
+		    + sizeof yyexpecting - 1
+		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
+		       * (sizeof yyor - 1))];
       char const *yyprefix = yyexpecting;
 
       /* Start YYX at -YYN if negative to avoid negative indexes in
-         YYCHECK.  */
+	 YYCHECK.  */
       int yyxbegin = yyn < 0 ? -yyn : 0;
 
       /* Stay within bounds of both yycheck and yytname.  */
@@ -871,22 +871,22 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       yyfmt = yystpcpy (yyformat, yyunexpected);
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-          {
-            if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-              {
-                yycount = 1;
-                yysize = yysize0;
-                yyformat[sizeof yyunexpected - 1] = '\0';
-                break;
-              }
-            yyarg[yycount++] = yytname[yyx];
-            yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-            yysize_overflow |= (yysize1 < yysize);
-            yysize = yysize1;
-            yyfmt = yystpcpy (yyfmt, yyprefix);
-            yyprefix = yyor;
-          }
+	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	  {
+	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
+	      {
+		yycount = 1;
+		yysize = yysize0;
+		yyformat[sizeof yyunexpected - 1] = '\0';
+		break;
+	      }
+	    yyarg[yycount++] = yytname[yyx];
+	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
+	    yysize_overflow |= (yysize1 < yysize);
+	    yysize = yysize1;
+	    yyfmt = yystpcpy (yyfmt, yyprefix);
+	    yyprefix = yyor;
+	  }
 
       yyf = YY_(yyformat);
       yysize1 = yysize + yystrlen (yyf);
@@ -898,25 +898,25 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
       if (yyresult)
 	{
-          /* Avoid sprintf, as that infringes on the user's name space.
-             Don't have undefined behavior even if the translation
-             produced a string with the wrong number of "%s"s.  */
-          char *yyp = yyresult;
-          int yyi = 0;
-          while ((*yyp = *yyf) != '\0')
-            {
-              if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
-                {
-                  yyp += yytnamerr (yyp, yyarg[yyi++]);
-                  yyf += 2;
-                }
-              else
-                {
-                  yyp++;
-                  yyf++;
-                }
-            }
-        }
+	  /* Avoid sprintf, as that infringes on the user's name space.
+	     Don't have undefined behavior even if the translation
+	     produced a string with the wrong number of "%s"s.  */
+	  char *yyp = yyresult;
+	  int yyi = 0;
+	  while ((*yyp = *yyf) != '\0')
+	    {
+	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
+		{
+		  yyp += yytnamerr (yyp, yyarg[yyi++]);
+		  yyf += 2;
+		}
+	      else
+		{
+		  yyp++;
+		  yyf++;
+		}
+	    }
+	}
       return yysize;
     }
 }
@@ -956,7 +956,7 @@ YYLTYPE yylloc;])
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
 b4_pure_if([],
-           [b4_declare_parser_variables])
+	   [b4_declare_parser_variables])
 
 
 /*----------.
@@ -1323,15 +1323,15 @@ yyerrlab:
 	 error, discard it.  */
 
       if (yychar <= YYEOF)
-        {
+	{
 	  /* Return failure if at end of input.  */
 	  if (yychar == YYEOF)
 	    YYABORT;
-        }
+	}
       else
 	{
 	  yydestruct ("Error: discarding",
-                      yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+		      yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
 	  yychar = YYEMPTY;
 	}
     }
@@ -1388,7 +1388,7 @@ yyerrlab1:
 
 ]b4_location_if([[      yyerror_range[0] = *yylsp;]])[
       yydestruct ("Error: popping",
-                  yystos[yystate], yyvsp]b4_location_if([, yylsp])[]b4_user_args[);
+		  yystos[yystate], yyvsp]b4_location_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1475,9 +1475,9 @@ b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
 
 b4_token_enums_defines(b4_tokens)
 
-#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
+#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 m4_ifdef([b4_stype],
-[typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])
+[typedef union[]m4_bregexp(b4_stype, [^{], [ YYSTYPE])
 b4_stype
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])
@@ -1492,7 +1492,7 @@ b4_pure_if([],
 [extern YYSTYPE b4_prefix[]lval;])
 
 b4_location_if(
-[#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
+[#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
   int first_line;
