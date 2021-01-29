@@ -695,14 +695,14 @@ yysymbol_name (yysymbol_kind_t yysymbol)
 }]])[
 #endif
 
-# ifdef YYPRINT
+#ifdef YYPRINT
 /* YYTOKNUM[NUM] -- (External) token number corresponding to the
    (internal) symbol number NUM (which must be that of a token).  */
 static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 {
   ]b4_toknum[
 };
-# endif
+#endif
 
 #define YYPACT_NINF (]b4_pact_ninf[)
 
@@ -1405,10 +1405,10 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 
   switch (yycount)
     {
-# define YYCASE_(N, S)                      \
+#define YYCASE_(N, S)                       \
       case N:                               \
         yyformat = S;                       \
-      break
+        break
     default: /* Avoid compiler warnings. */
       YYCASE_(0, YY_("syntax error"));
       YYCASE_(1, YY_("syntax error, unexpected %s"));
@@ -1416,7 +1416,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
       YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
       YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
       YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
-# undef YYCASE_
+#undef YYCASE_
     }
 
   /* Compute error message size.  Don't count the "%s"s, but reserve
@@ -1698,7 +1698,7 @@ yysetstate:
         YYSTACK_RELOCATE (yyss_alloc, yyss);
         YYSTACK_RELOCATE (yyvs_alloc, yyvs);]b4_locations_if([
         YYSTACK_RELOCATE (yyls_alloc, yyls);])[
-# undef YYSTACK_RELOCATE
+#  undef YYSTACK_RELOCATE
         if (yyss1 != yyssa)
           YYSTACK_FREE (yyss1);
       }
