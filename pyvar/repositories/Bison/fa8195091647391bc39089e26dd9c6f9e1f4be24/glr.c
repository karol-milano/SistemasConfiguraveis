@@ -224,7 +224,7 @@ b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
-# define YYDEBUG ]b4_debug_if([1], [0])[
+# define YYDEBUG ]b4_parse_trace_if([1], [0])[
 #endif
 
 /* Enabling verbose error messages.  */
