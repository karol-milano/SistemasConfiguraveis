@@ -319,7 +319,8 @@ m4_if(b4_prefix, [yy], [],
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]b4_shared_declarations[
+]b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
+               [b4_shared_declarations])[
 
 /* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
