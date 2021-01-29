@@ -1,4 +1,4 @@
-                                                                    -*- C -*-
+#                                                             -*- C -*-
 
 # GLR skeleton for Bison
 
@@ -147,6 +147,15 @@ m4_define([b4_rhs_location],
 [(b4_rhs_data([$1], [$2]).yyloc)])
 
 
+# b4_call_merger(MERGER-NUM, MERGER-NAME, SYMBOL-SUM)
+# ---------------------------------------------------
+m4_define([b4_call_merger],
+[b4_case([$1],
+         [    b4_symbol_if([$3], [has_type],
+                           [yy0->b4_symbol($3, type) = $2 (*yy0, *yy1);],
+                           [*yy0 = $2 (*yy0, *yy1);])])])
+
+
 ## -------------- ##
 ## Declarations.  ##
 ## -------------- ##
