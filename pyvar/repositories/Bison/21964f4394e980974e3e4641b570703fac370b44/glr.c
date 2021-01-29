@@ -31,6 +31,14 @@ m4_define_default([b4_stack_depth_init],  [200])
 # Location type.
 m4_define_default([b4_location_type], [yyltype])
 
+# Accumule in b4_lex_param all the yylex arguments.
+# Yes, this is quite ugly...
+m4_define([b4_lex_param],
+m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[yylvalp]]][]dnl
+b4_location_if([, [[YYLTYPE *], [yyllocp]]])])dnl
+m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
+
+m4_define_default([b4_parse_param])
 
 
 ## ----------------- ##
@@ -58,15 +66,6 @@ m4_define([b4_rhs_value],
 ## Locations.  ##
 ## ----------- ##
 
-# b4_location_if(IF-TRUE, IF-FALSE)
-# ---------------------------------
-# Expand IF-TRUE, if locations are used, IF-FALSE otherwise.
-m4_define([b4_location_if],
-[m4_if(b4_locations_flag, [1],
-       [$1],
-       [$2])])
-
-
 # b4_lhs_location()
 # -----------------
 # Expansion of @$.
@@ -83,19 +82,6 @@ m4_define([b4_rhs_location],
 
 
 
-## -------------- ##
-## %pure-parser.  ##
-## -------------- ##
-
-# b4_pure_if(IF-TRUE, IF-FALSE)
-# -----------------------------
-# Expand IF-TRUE, if %pure-parser, IF-FALSE otherwise.
-m4_define([b4_pure_if],
-[m4_if(b4_pure, [1],
-       [$1],
-       [$2])])
-
-
 ## ------------------- ##
 ## Output file names.  ##
 ## ------------------- ##
@@ -428,18 +414,10 @@ int yyparse (void);
 #endif
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
+#define YYLEX ]b4_c_function_call([yylex], [int], b4_lex_param)[
 
 ]b4_pure_if(
 [
-#ifdef YYLEX_PARAM
-# define YYLEX	yylex (yylvalp, b4_location_if([yyllocp, ])YYLEX_PARAM)
-#else
-# define YYLEX	yylex (yylvalp[]b4_location_if([, yyllocp]))
-#endif],
-[#define YYLEX  yylex ()])
-
-b4_pure_if(
-[
 #undef yynerrs
 #define yynerrs (yystack->yyerrcnt)
 #undef yychar
@@ -1712,9 +1690,9 @@ yyparse (YYPARSE_PARAM_ARG)
 
   while (yytrue)
     {
-      /* For efficiency, we have two loops, of which the first of which
-       * is specialized to deterministic operation (single stack, no
-       * potential ambiguity). */
+      /* For efficiency, we have two loops, the first of which is
+	 specialized to deterministic operation (single stack, no
+	 potential ambiguity).  */
 
       /* Standard mode */
       while (yytrue)
