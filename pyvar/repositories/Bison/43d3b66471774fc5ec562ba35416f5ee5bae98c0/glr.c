@@ -245,6 +245,13 @@ b4_syncline([@oline@], [@ofile@])
 # if !defined (__GNUC__) || __GNUC__ < 2 || \
 (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
 #  define __attribute__(Spec) /* empty */
+# else
+]b4_location_if([#  define YYOPTIONAL_LOC(Name) Name],[
+#  if defined (__cplusplus)
+#   define YYOPTIONAL_LOC(Name) /* empty */
+#  else
+#   define YYOPTIONAL_LOC(Name) Name ATTRIBUTE_UNUSED
+#  endif])[
 # endif
 #endif
 
@@ -719,7 +726,7 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
 static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp,
-	      YYLTYPE* yylocp]b4_location_if(, [ ATTRIBUTE_UNUSED])[,
+	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
 	      yyGLRStack* yystack
               ]b4_user_formals[)
 {
@@ -1748,7 +1755,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 static void
 yyrecoverSyntaxError (yyGLRStack* yystack,
 		      YYSTYPE* yylvalp,
-		      YYLTYPE* yyllocp]b4_location_if(, [ ATTRIBUTE_UNUSED])[
+		      YYLTYPE* YYOPTIONAL_LOC (yyllocp)
 		      ]b4_user_formals[)
 {
   yySymbol* const yytokenp = yystack->yytokenp;
