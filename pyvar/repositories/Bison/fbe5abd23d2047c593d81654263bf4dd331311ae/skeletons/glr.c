@@ -152,7 +152,7 @@ m4_define([b4_rhs_location],
 m4_define([b4_call_merger],
 [b4_case([$1],
          [    b4_symbol_if([$3], [has_type],
-                           [yy0->b4_symbol($3, type) = $2 (*yy0, *yy1);],
+                           [yy0->b4_symbol($3, slot) = $2 (*yy0, *yy1);],
                            [*yy0 = $2 (*yy0, *yy1);])])])
 
 
