@@ -51,7 +51,7 @@ m4_define([b4_lac_flag],
           [m4_if(b4_percent_define_get([[parse.lac]]),
                  [none], [[0]], [[1]])])
 
-m4_include(b4_pkgdatadir/[c.m4])
+m4_include(b4_skeletonsdir/[c.m4])
 
 ## ---------------- ##
 ## Default values.  ##
