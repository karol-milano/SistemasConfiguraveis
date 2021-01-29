@@ -21,6 +21,9 @@ m4_divert(-1)                                                       -*- C -*-
 
 m4_include(b4_pkgdatadir/[c.m4])
 
+b4_push_if([
+m4_fatal([Non-deterministic push parsers are not yet supported])])
+
 ## ---------------- ##
 ## Default values.  ##
 ## ---------------- ##
