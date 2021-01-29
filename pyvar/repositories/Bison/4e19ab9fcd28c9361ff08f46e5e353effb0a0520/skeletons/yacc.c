@@ -294,6 +294,25 @@ m4_define([b4_shared_declarations],
 ]b4_cpp_guard_close([b4_spec_defines_file])[]dnl
 ])
 
+
+# b4_header_include_if(IF-TRUE, IF-FALSE)
+# ---------------------------------------
+# Run IF-TRUE if we generate an output file and api.header.include
+# is defined.
+m4_define([b4_header_include_if],
+[m4_ifval(m4_quote(b4_spec_defines_file),
+          [b4_percent_define_ifdef([[api.header.include]],
+                                   [$1],
+                                   [$2])],
+          [$2])])
+
+m4_if(b4_spec_defines_file, [[y.tab.h]],
+      [b4_percent_define_default([[api.header.include]],
+                                 [["@basename(]b4_spec_defines_file[@)"]])])
+
+
+
+
 ## -------------- ##
 ## Output files.  ##
 ## -------------- ##
@@ -354,11 +373,10 @@ m4_if(b4_api_prefix, [yy], [],
 # define YYERROR_VERBOSE ]b4_error_verbose_if([1], [0])[
 #endif
 
-]m4_ifval(m4_quote(b4_spec_defines_file),
-[[/* In a future release of Bison, this section will be replaced
-   by #include "@basename(]b4_spec_defines_file[@)".  */
-]])dnl
-b4_shared_declarations[
+]b4_header_include_if([[#include ]b4_percent_define_get([[api.header.include]])],
+                      [/* Use api.header.include to #include this header
+   instead of duplicating it here.  */
+b4_shared_declarations])[
 
 ]b4_user_post_prologue[
 ]b4_percent_code_get[]dnl
