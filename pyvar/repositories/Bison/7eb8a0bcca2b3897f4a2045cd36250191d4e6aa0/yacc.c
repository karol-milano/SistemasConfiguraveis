@@ -24,7 +24,12 @@
 b4_use_push_for_pull_if([m4_include(b4_pkgdatadir/[push.c])m4_exit])
 
 m4_include(b4_pkgdatadir/[c.m4])
-b4_check_percent_code_qualifiers([[requires]], [[provides]], [[top]])
+
+b4_check_percent_define_variables
+
+b4_check_percent_code_qualifiers([[requires]],
+                                 [[provides]],
+                                 [[top]])
 
 ## ---------------- ##
 ## Default values.  ##
