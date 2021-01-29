@@ -37,6 +37,10 @@ m4_define_default([b4_stack_depth_init],  [200])
 ## Pure/impure interfaces.  ##
 ## ------------------------ ##
 
+b4_percent_define_default([[api.pure]], [[false]])
+b4_define_flag_if([pure])
+m4_define([b4_pure_flag],
+          [b4_percent_define_flag_if([[api.pure]], [[1]], [[0]])])
 
 # b4_yacc_pure_if(IF-TRUE, IF-FALSE)
 # ----------------------------------
