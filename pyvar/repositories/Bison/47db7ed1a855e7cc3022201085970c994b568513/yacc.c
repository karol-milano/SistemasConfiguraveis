@@ -638,21 +638,6 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 #define YYERROR         goto yyerrorlab
 
 
-/* Like YYERROR except do call yyerror.  This remains here temporarily
-   to ease the transition to the new meaning of YYERROR, for GCC.
-   Once GCC version 2 has supplanted version 1, this can go.  However,
-   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
-   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
-   discussed.  */
-
-#define YYFAIL          goto yyerrlab
-#if defined YYFAIL
-  /* This is here to suppress warnings from the GCC cpp's
-     -Wunused-macros.  Normally we don't worry about that warning, but
-     some users do, and we want to make it easy for users to remove
-     YYFAIL uses, which will produce warnings from Bison 2.5.  */
-#endif
-
 #define YYRECOVERING()  (!!yyerrstatus)
 
 #define YYBACKUP(Token, Value)                                  \
@@ -1177,10 +1162,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   int yycount = 0;
 
   /* There are many possibilities here to consider:
-     - Assume YYFAIL is not used.  It's too flawed to consider.  See
-       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
-       for details.  YYERROR is fine as it does not invoke this
-       function.
      - If this state is a consistent state with a default action, then
        the only way this function was invoked is if the default action
        is an error action.  In that case, don't check for expected
@@ -1769,9 +1750,9 @@ yyreduce:
   goto yynewstate;
 
 
-/*------------------------------------.
-| yyerrlab -- here on detecting error |
-`------------------------------------*/
+/*--------------------------------------.
+| yyerrlab -- here on detecting error.  |
+`--------------------------------------*/
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
