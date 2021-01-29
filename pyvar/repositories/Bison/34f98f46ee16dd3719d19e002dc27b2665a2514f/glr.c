@@ -169,9 +169,9 @@ dnl # ----------------------
 dnl # Declaration that might either go into the header (if --defines)
 dnl # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[m4_ifdef([b4_before_definitions],
-[[/* Copy the %before-definitions blocks.  */
-]b4_before_definitions])[]dnl
+[m4_ifdef([b4_start_header],
+[[/* Copy the %start-header blocks.  */
+]b4_start_header])[]dnl
 
 b4_token_enums(b4_tokens)
 
@@ -203,9 +203,9 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-]m4_ifdef([b4_after_definitions],
-[[/* Copy the %after-definitions blocks.  */
-]b4_after_definitions])[]dnl
+]m4_ifdef([b4_end_header],
+[[/* Copy the %end-header blocks.  */
+]b4_end_header])[]dnl
 ])
 
 b4_defines_if([#include @output_header_name@],
