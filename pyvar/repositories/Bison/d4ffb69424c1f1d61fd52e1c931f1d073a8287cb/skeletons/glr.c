@@ -32,7 +32,9 @@ m4_if(b4_skeleton, ["glr.c"],
 m4_define_default([b4_stack_depth_max], [10000])
 m4_define_default([b4_stack_depth_init],  [200])
 
-
+# Included header.
+b4_percent_define_default([[api.header.include]],
+                          [["@basename(]b4_spec_header_file[@)"]])
 
 ## ------------------------ ##
 ## Pure/impure interfaces.  ##
@@ -228,8 +230,8 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 ]b4_cast_define[
 ]b4_null_define[
 
-]b4_header_if([[#include "@basename(]b4_spec_header_file[@)"]],
-               [b4_shared_declarations])[
+]b4_header_if([[#include ]b4_percent_define_get([[api.header.include]])],
+              [b4_shared_declarations])[
 
 ]b4_glr_cc_if([b4_glr_cc_setup],
               [b4_declare_symbol_enum])[
