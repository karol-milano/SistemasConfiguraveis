@@ -1207,10 +1207,10 @@ yyparse_context_location (const yyparse_context_t *yyctx)
                      b4_parse_param)],
          [simple],
 [[]],
-[[# ifndef yystrlen
-#  if defined __GLIBC__ && defined _STRING_H
-#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
-#  else
+[[#ifndef yystrlen
+# if defined __GLIBC__ && defined _STRING_H
+#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
+# else
 /* Return the length of YYSTR.  */
 ]b4_function_define([yystrlen], [static YYPTRDIFF_T],
    [[const char *yystr], [yystr]])[
@@ -1220,13 +1220,13 @@ yyparse_context_location (const yyparse_context_t *yyctx)
     continue;
   return yylen;
 }
-#  endif
 # endif
+#endif
 
-# ifndef yystpcpy
-#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
-#   define yystpcpy stpcpy
-#  else
+#ifndef yystpcpy
+# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
+#  define yystpcpy stpcpy
+# else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
 ]b4_function_define([yystpcpy], [static char *],
@@ -1240,12 +1240,12 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 
   return yyd - 1;
 }
-#  endif
 # endif
+#endif
 
 ]m4_case(b4_percent_define_get([[parse.error]]),
          [verbose],
-[[# ifndef yytnamerr
+[[#ifndef yytnamerr
 /* Copy to YYRES the contents of YYSTR after stripping away unnecessary
    quotes and backslashes, so that it's suitable for yyerror.  The
    heuristic is that double-quoting is unnecessary unless the string
@@ -1293,7 +1293,7 @@ yytnamerr (char *yyres, const char *yystr)
   else
     return yystrlen (yystr);
 }
-# endif
+#endif
 ]])[
 
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
@@ -1343,7 +1343,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 
   /* Compute error message size.  Don't count the "%s"s, but reserve
      room for the terminator.  */
-  yysize = (yystrlen (yyformat) - 2 * yycount) + 1;
+  yysize = yystrlen (yyformat) - 2 * yycount + 1;
   {
     int yyi;
     for (yyi = 0; yyi < yycount; ++yyi)
@@ -1393,9 +1393,9 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 
 ]b4_yydestruct_define[
 
-]b4_pure_if([], [
+]b4_pure_if([], [[
 
-b4_declare_scanner_communication_variables])[]b4_push_if([[
+]b4_declare_scanner_communication_variables])[]b4_push_if([[
 
 struct yypstate
   {]b4_declare_parser_state_variables[
