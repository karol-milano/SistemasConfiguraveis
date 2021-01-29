@@ -425,6 +425,11 @@ typedef int yy_state_fast_t;
 # endif
 #endif
 
+#ifndef N_
+# define N_(Msgid) Msgid
+#endif
+
+
 #ifndef YY_ATTRIBUTE_PURE
 # if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
 #  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
