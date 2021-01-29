@@ -162,7 +162,7 @@ m4_if(b4_prefix, [yy], [],
 #define yydebug b4_prefix[]debug
 #define yynerrs b4_prefix[]nerrs
 b4_locations_if([#define yylloc b4_prefix[]lloc])
-b4_push_if([#define yyresult_get b4_prefix[]result_get
+b4_push_if([
 #define yychar_set b4_prefix[]char_set
 #define yylval_set b4_prefix[]lval_set
 #define yylloc_set b4_prefix[]lloc_set])])[
@@ -973,14 +973,14 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
 ]b4_push_if([
 struct yypvars;
-]b4_c_function_decl([yyresult_get], [int], [[struct yypvars *YYPVARS], [YYPVARS]])[
+#define YYPUSH_MORE 4
 ]b4_c_function_decl([yychar_set], [void], [[struct yypvars *YYPVARS], [YYPVARS]], [[int yychar], [yychar]])[
 ]b4_c_function_decl([yylval_set], [void], [[struct yypvars *YYPVARS], [YYPVARS]], [[YYSTYPE yylval], [yylval]])[
 #ifdef YYLTYPE_IS_TRIVIAL
 ]b4_c_function_decl([yylloc_set], [void], [[struct yypvars *YYPVARS], [YYPVARS]], [[YYLTYPE yylloc], [yylloc]])[
 #endif
 ]b4_c_function_decl([yypvarsinit], [void *], [[void], []])[
-]b4_c_function_decl([yypushparse], [void],
+]b4_c_function_decl([yypushparse], [int],
    [[struct yypvars *YYPVARS], [YYPVARS]])[
 ])[
 
@@ -1103,12 +1103,6 @@ yypvarsinit (void)
   return (void*) pv;
 }
 
-int
-yyresult_get (struct yypvars *YYPVARS)
-{
-  return YYPVARS->yyresult;
-}
-
 void
 yychar_set (struct yypvars *YYPVARS, int yychar)
 {
@@ -1143,7 +1137,7 @@ b4_push_if([b4_declare_yyparse_variables])
 `-------------------------*/
 
 b4_push_if([
-b4_c_function_def([yypushparse], [void], [[struct yypvars *YYPVARS], [YYPVARS]])],[
+b4_c_function_def([yypushparse], [int], [[struct yypvars *YYPVARS], [YYPVARS]])],[
 #ifdef YYPARSE_PARAM
 b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
 #else /* ! YYPARSE_PARAM */
@@ -1423,7 +1417,7 @@ yybackup:
 	pv->yylen	      = yylen;
 	pv->yyval	      = yyval;
 	]b4_locations_if([pv->yyloc = yyloc;])[
-        return;
+        return yyresult;
 gottoken:
         YYDPRINTF((stderr, "Reading a token: "));],[
 	YYDPRINTF ((stderr, "Reading a token: "));
@@ -1717,10 +1711,9 @@ yyreturn:
   if (yymsg != yymsgbuf_ptr)
     YYSTACK_FREE (yymsg);
 #endif
-  ]b4_push_if([pv->yyresult = YYID (yyresult);],[
+  ]b4_push_if([pv->yyresult = YYID (yyresult);])[
     /* Make sure YYID is used.  */
     return YYID (yyresult);
-  ])[
 ]}
 
 b4_push_if([
@@ -1738,9 +1731,8 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 #ifdef YYLTYPE_IS_TRIVIAL
     yylloc_set (ctx, yylloc);
 #endif
-    yypushparse (ctx);
-    status = yyresult_get (ctx);
-  } while (status == 4);
+    status = yypushparse (ctx);
+  } while (status == YYPUSH_MORE);
   free (ctx);
   return status;
 ]}])
@@ -1788,7 +1780,8 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-]b4_push_if([struct ]b4_prefix[pvars;])[
+]b4_push_if([struct ]b4_prefix[pvars;
+#define YYPUSH_MORE 4])[
 ]b4_pure_if([],
 	   [extern YYLTYPE b4_prefix[]lloc;])
 )dnl b4_locations_if
