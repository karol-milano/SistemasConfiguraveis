@@ -65,24 +65,36 @@ m4_define_default([b4_stack_depth_init],  [200])
 ## ------------------------ ##
 
 b4_percent_define_default([[api.pure]], [[false]])
-b4_define_flag_if([pure])
-m4_define([b4_pure_flag],
-          [b4_percent_define_flag_if([[api.pure]], [[1]], [[0]])])
-
-# b4_yacc_pure_if(IF-TRUE, IF-FALSE)
-# ----------------------------------
-# Expand IF-TRUE, if %pure-parser and %parse-param, IF-FALSE otherwise.
-m4_define([b4_yacc_pure_if],
-[b4_pure_if([m4_ifset([b4_parse_param],
-		      [$1], [$2])],
-	    [$2])])
-
+b4_percent_define_check_values([[[[api.pure]],
+                                 [[false]], [[true]], [[]], [[full]]]])
+
+m4_define([b4_pure_flag], [[0]])
+m4_case(b4_percent_define_get([[api.pure]]),
+        [false], [m4_define([b4_pure_flag], [[0]])],
+        [true],  [m4_define([b4_pure_flag], [[1]])],
+        [],      [m4_define([b4_pure_flag], [[1]])],
+        [full],  [m4_define([b4_pure_flag], [[2]])])
+
+m4_define([b4_pure_if],
+[m4_case(b4_pure_flag,
+         [0], [$2],
+         [1], [$1],
+         [2], [$1])])
+         [m4_fatal([invalid api.pure value: ]$1)])])
+
+# b4_yyerror_arg_loc_if(ARG)
+# --------------------------
+# Expand ARG iff yyerror is to be given a location as argument.
+m4_define([b4_yyerror_arg_loc_if],
+[b4_locations_if([m4_case(b4_pure_flag,
+                          [1], [m4_ifset([b4_parse_param], [$1])],
+                          [2], [$1])])])
 
 # b4_yyerror_args
 # ---------------
 # Arguments passed to yyerror: user args plus yylloc.
 m4_define([b4_yyerror_args],
-[b4_yacc_pure_if([b4_locations_if([&yylloc, ])])dnl
+[b4_yyerror_arg_loc_if([&yylloc, ])dnl
 m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 
