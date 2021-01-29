@@ -261,19 +261,19 @@ b4_syncline([@oline@], [@ofile@])
 
 #ifndef __attribute__
 /* This feature is available in gcc versions 2.5 and later.  */
-# if !defined (__GNUC__) || __GNUC__ < 2 || \
-(__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
+# if (!defined (__GNUC__) || __GNUC__ < 2 \
+      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__)
 #  define __attribute__(Spec) /* empty */
-# else
-]b4_location_if([#  define YYOPTIONAL_LOC(Name) Name],[
-#  if defined (__cplusplus)
-#   define YYOPTIONAL_LOC(Name) /* empty */
-#  else
-#   define YYOPTIONAL_LOC(Name) Name __attribute__ ((__unused__))
-#  endif])[
 # endif
 #endif
 
+]b4_location_if([#define YYOPTIONAL_LOC(Name) Name],[
+#ifdef __cplusplus
+# define YYOPTIONAL_LOC(Name) /* empty */
+#else
+# define YYOPTIONAL_LOC(Name) Name __attribute__ ((__unused__))
+#endif])[
+
 #ifndef YYASSERT
 # define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
 #endif
