@@ -20,7 +20,13 @@
 
 
 m4_include(b4_pkgdatadir/[c.m4])
-b4_check_percent_code_qualifiers([[requires]], [[provides]], [[top]])
+
+# glr.cc checks %define variables also.
+m4_if(b4_skeleton, [["glr.c"]], [b4_check_percent_define_variables])
+
+b4_check_percent_code_qualifiers([[requires]],
+                                 [[provides]],
+                                 [[top]])
 
 b4_push_if([
 b4_complain([[non-deterministic push parsers are not yet supported]])])
