@@ -35,8 +35,8 @@ m4_define_default([b4_stack_depth_init],  [200])
 ## ------------------------ ##
 
 b4_define_flag_if([pure])
-# If glr.cc is including this file and thus has already set b4_pure_flag, don't
-# change the value of b4_pure_flag, and don't record a use of api.pure.
+# If glr.cc is including this file and thus has already set b4_pure_flag,
+# do not change the value of b4_pure_flag, and do not record a use of api.pure.
 m4_ifndef([b4_pure_flag],
 [b4_percent_define_default([[api.pure]], [[false]])
  m4_define([b4_pure_flag],
