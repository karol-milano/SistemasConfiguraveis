@@ -374,9 +374,10 @@ m4_if(b4_api_prefix, [yy], [],
 #endif
 
 ]b4_header_include_if([[#include ]b4_percent_define_get([[api.header.include]])],
-                      [/* Use api.header.include to #include this header
+                      [m4_ifval(m4_quote(b4_spec_header_file),
+                                [/* Use api.header.include to #include this header
    instead of duplicating it here.  */
-b4_shared_declarations])[
+])b4_shared_declarations])[
 
 ]b4_user_post_prologue[
 ]b4_percent_code_get[]dnl
