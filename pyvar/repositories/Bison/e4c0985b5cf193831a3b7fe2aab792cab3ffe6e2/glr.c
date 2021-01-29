@@ -172,8 +172,9 @@ m4_define([b4_rhs_location],
 # b4_shared_declarations
 # ----------------------
 # Declaration that might either go into the header (if --defines)
-# or open coded in the parser body.
-m4_define([b4_shared_declarations],
+# or open coded in the parser body.  glr.cc has its own definition.
+m4_if(b4_skeleton, ["glr.c"],
+[m4_define([b4_shared_declarations],
 [b4_declare_yydebug[
 ]b4_percent_code_get([[requires]])[
 ]b4_token_enums[
@@ -181,7 +182,7 @@ m4_define([b4_shared_declarations],
 ]b4_function_declare(b4_prefix[parse], [int], b4_parse_param)[
 ]b4_percent_code_get([[provides]])[]dnl
 ])
-
+])
 
 ## -------------- ##
 ## Output files.  ##
