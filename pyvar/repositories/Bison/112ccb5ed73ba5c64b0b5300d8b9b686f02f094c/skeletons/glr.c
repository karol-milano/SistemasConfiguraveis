@@ -21,7 +21,7 @@
 # If we are loaded by glr.cc, do not override c++.m4 definitions by
 # those of c.m4.
 m4_if(b4_skeleton, ["glr.c"],
-      [m4_include(b4_pkgdatadir/[c.m4])])
+      [m4_include(b4_skeletonsdir/[c.m4])])
 
 ## ---------------- ##
 ## Default values.  ##
