@@ -318,7 +318,8 @@ b4_percent_code_get[]dnl
 #ifndef __attribute__
 /* This feature is available in gcc versions 2.5 and later.  */
 # if (! defined __GNUC__ || __GNUC__ < 2 \
-      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__)
+      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) \
+      || (defined __STRICT_ANSI__ && __STRICT_ANSI__))
 #  define __attribute__(Spec) /* empty */
 # endif
 #endif
