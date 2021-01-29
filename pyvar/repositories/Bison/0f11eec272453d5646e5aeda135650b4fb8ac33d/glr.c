@@ -203,7 +203,7 @@ m4_if(b4_prefix, [yy], [],
 ]b4_null_define[
 
 ]b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
-              [b4_shared_declarations])[
+               [b4_shared_declarations])[
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
