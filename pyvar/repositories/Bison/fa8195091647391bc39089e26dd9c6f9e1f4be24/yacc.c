@@ -192,7 +192,7 @@ m4_if(b4_prefix, [yy], [],
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
-# define YYDEBUG ]b4_debug_if([1], [0])[
+# define YYDEBUG ]b4_parse_trace_if([1], [0])[
 #endif
 
 /* Enabling verbose error messages.  */
