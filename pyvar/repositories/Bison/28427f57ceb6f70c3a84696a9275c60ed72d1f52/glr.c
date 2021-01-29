@@ -214,13 +214,13 @@ b4_percent_code_get([[top]])[
 #define yynerrs ]b4_prefix[nerrs]b4_locations_if([[
 #define yylloc  ]b4_prefix[lloc]])])[
 
-/* Copy the first part of user declarations.  */
+/* First part of user declarations.  */
 ]b4_user_pre_prologue[
 
 ]b4_null_define[
 
 ]b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
-              [b4_shared_declarations])[
+               [b4_shared_declarations])[
 
 /* Enabling verbose error messages.  */
 #ifdef YYERROR_VERBOSE
