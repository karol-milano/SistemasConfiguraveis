@@ -463,6 +463,11 @@ typedef int yy_state_fast_t;
 #  define YY_(Msgid) Msgid
 # endif
 #endif
+]b4_has_translations_if([
+#ifndef N_
+# define N_(Msgid) Msgid
+#endif
+])[
 
 ]b4_attribute_define[
 
