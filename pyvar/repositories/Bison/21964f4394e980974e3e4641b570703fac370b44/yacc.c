@@ -33,7 +33,12 @@ m4_define_default([b4_stack_depth_init],  [200])
 # Location type.
 m4_define_default([b4_location_type], [yyltype])
 
-
+# Accumule in b4_lex_param all the yylex arguments.
+# Yes, this is quite ugly...
+m4_define([b4_lex_param],
+m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
+b4_location_if([, [[YYLTYPE *], [&yylloc]]])])dnl
+m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
 
 ## ----------------- ##
@@ -61,15 +66,6 @@ m4_define([b4_rhs_value],
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
@@ -86,19 +82,6 @@ m4_define([b4_rhs_location],
 
 
 
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
@@ -530,10 +513,7 @@ while (0)
 #ifdef YYLEX_PARAM
 # define YYLEX yylex (b4_pure_if([&yylval[]b4_location_if([, &yylloc]), ])YYLEX_PARAM)
 #else
-# define YYLEX b4_c_function_call([yylex], [int],
-                   b4_pure_if([[[[]], [[&yylval]]],
-                               b4_location_if([[[], [&yylloc]],])])
-                   m4_fst(b4_lex_param))
+# define YYLEX b4_c_function_call([yylex], [int], b4_lex_param)
 #endif
 
 /* Enable debugging if requested.  */
