@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.91.18-42a6c.  */
+/* A Bison parser, made by GNU Bison 3.4.92.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.91.18-42a6c"
+#define YYBISON_VERSION "3.4.92"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -354,13 +354,6 @@ typedef int yy_state_fast_t;
     _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
     _Pragma ("GCC diagnostic pop")
-# if defined __cplusplus
-#  define YY_IGNORE_USELESS_CAST_BEGIN                          \
-     _Pragma ("GCC diagnostic push")                            \
-     _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
-#  define YY_IGNORE_USELESS_CAST_END            \
-     _Pragma ("GCC diagnostic pop")
-# endif
 #else
 # define YY_INITIAL_VALUE(Value) Value
 #endif
@@ -368,13 +361,21 @@ typedef int yy_state_fast_t;
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END
 #endif
+#ifndef YY_INITIAL_VALUE
+# define YY_INITIAL_VALUE(Value) /* Nothing. */
+#endif
+
+#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
+# define YY_IGNORE_USELESS_CAST_BEGIN                          \
+    _Pragma ("GCC diagnostic push")                            \
+    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
+# define YY_IGNORE_USELESS_CAST_END            \
+    _Pragma ("GCC diagnostic pop")
+#endif
 #ifndef YY_IGNORE_USELESS_CAST_BEGIN
 # define YY_IGNORE_USELESS_CAST_BEGIN
 # define YY_IGNORE_USELESS_CAST_END
 #endif
-#ifndef YY_INITIAL_VALUE
-# define YY_INITIAL_VALUE(Value) /* Nothing. */
-#endif
 
 
 #define YY_ASSERT(E) ((void) (0 && (E)))
@@ -3063,9 +3064,9 @@ handle_require (location const *loc, char const *version)
       return;
     }
 
-  /* Pretend to be at least 3.4, to check features published in 3.4
-     while developping it.  */
-  const char* api_version = "3.4";
+  /* Pretend to be at least 3.5, to check features published in that
+     version while developping it.  */
+  const char* api_version = "3.5";
   const char* package_version =
     0 < strverscmp (api_version, PACKAGE_VERSION)
     ? api_version : PACKAGE_VERSION;
