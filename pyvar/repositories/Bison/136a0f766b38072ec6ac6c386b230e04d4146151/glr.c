@@ -162,16 +162,16 @@ m4_if(b4_prefix, [yy], [],
 #define yylloc  b4_prefix[]lloc])[
 
 /* Copy the first part of user declarations.  */
-]b4_pre_prologue
+]b4_user_pre_prologue
 
 dnl # b4_shared_declarations
 dnl # ----------------------
 dnl # Declaration that might either go into the header (if --defines)
 dnl # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[m4_ifdef([b4_start_header],
-[[/* Copy the %start-header blocks.  */
-]b4_start_header])[]dnl
+[m4_ifdef([b4_requires],
+[[/* Copy the %requires blocks.  */
+]b4_user_requires])[]dnl
 
 b4_token_enums(b4_tokens)
 
@@ -202,9 +202,9 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-]m4_ifdef([b4_end_header],
-[[/* Copy the %end-header blocks.  */
-]b4_end_header])[]dnl
+]m4_ifdef([b4_provides],
+[[/* Copy the %provides blocks.  */
+]b4_user_provides])[]dnl
 ])
 
 b4_defines_if([#include @output_header_name@],
