@@ -256,7 +256,7 @@ b4_percent_code_get[]dnl
 #include <string.h>
 
 #ifndef YY_
-# if YYENABLE_NLS
+# if defined YYENABLE_NLS && YYENABLE_NLS
 #  if ENABLE_NLS
 #   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
 #   define YY_(msgid) dgettext ("bison-runtime", msgid)
@@ -2264,7 +2264,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   yychar = YYEMPTY;
   yylval = yyval_default;
 ]b4_locations_if([
-#if YYLTYPE_IS_TRIVIAL
+#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
   yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
   yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
 #endif
