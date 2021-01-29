@@ -114,7 +114,7 @@ m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 # ---------------------
 # Return a narrow int type able to handle numbers ranging from
 # MIN to MAX (included).  Overwrite the version from c.m4,
-# so that the user can override the shorter types.
+# so that the code can use C99 types if available.
 m4_define([b4_int_type],
 [m4_if(b4_ints_in($@,   [-127],   [127]), [1], [yytype_int8],
        b4_ints_in($@,      [0],   [255]), [1], [yytype_uint8],
@@ -388,26 +388,54 @@ m4_if(b4_api_prefix, [yy], [],
 # undef short
 #endif
 
-#ifdef YYTYPE_UINT8
-typedef YYTYPE_UINT8 yytype_uint8;
-#else
+/* On compilers that do not define __PTRDIFF_MAX__ etc., include
+   <limits.h> and (if available) <stdint.h> so that the code can
+   choose integer types of a good width.  */
+
+#ifndef __PTRDIFF_MAX__
+# include <limits.h> /* INFRINGES ON USER NAME SPACE */
+# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
+#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
+# endif
+#endif
+
+/* Narrow types that promote to a signed type and that can represent a
+   signed or unsigned integer of at least N bits.  In tables they can
+   save space and decrease cache pressure.  Promoting to a signed type
+   helps avoid bugs in integer arithmetic.  */
+
+#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
+typedef __UINT_LEAST8_TYPE__ yytype_uint8;
+#elif defined UINT_LEAST8_MAX && UINT_LEAST8_MAX <= INT_MAX
+typedef uint_least8_t yytype_uint8;
+#elif UCHAR_MAX <= INT_MAX
 typedef unsigned char yytype_uint8;
+#else
+typedef short yytype_uint8;
 #endif
 
-#ifdef YYTYPE_INT8
-typedef YYTYPE_INT8 yytype_int8;
+#if defined __INT_LEAST8_MAX__ && __INT_LEAST8_MAX__ <= __INT_MAX__
+typedef __INT_LEAST8_TYPE__ yytype_int8;
+#elif defined INT_LEAST8_MAX && INT_LEAST8_MAX <= INT_MAX
+typedef int_least8_t yytype_int8;
 #else
 typedef signed char yytype_int8;
 #endif
 
-#ifdef YYTYPE_UINT16
-typedef YYTYPE_UINT16 yytype_uint16;
-#else
+#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
+typedef __UINT_LEAST16_TYPE__ yytype_uint16;
+#elif defined UINT_LEAST16_MAX && UINT_LEAST16_MAX <= INT_MAX
+typedef uint_least16_t yytype_uint16;
+#elif USHRT_MAX <= INT_MAX
 typedef unsigned short yytype_uint16;
+#else
+typedef int yytype_uint16;
 #endif
 
-#ifdef YYTYPE_INT16
-typedef YYTYPE_INT16 yytype_int16;
+#if defined __INT_LEAST16_MAX__ && __INT_LEAST16_MAX__ <= __INT_MAX__
+typedef __INT_LEAST16_TYPE__ yytype_int16;
+#elif defined INT_LEAST16_MAX && INT_LEAST16_MAX <= INT_MAX
+typedef int_least16_t yytype_int16;
 #else
 typedef short yytype_int16;
 #endif
@@ -416,17 +444,14 @@ typedef short yytype_int16;
 # if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
 #  define YYPTRDIFF_T __PTRDIFF_TYPE__
 #  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
-# elif defined ptrdiff_t && defined PTRDIFF_MAX
-#  define YYPTRDIFF_T ptrdiff_t
-#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
-# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
-#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
+# elif defined PTRDIFF_MAX
+#  ifndef ptrdiff_t
+#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
+#  endif
 #  define YYPTRDIFF_T ptrdiff_t
-#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
 # else
 #  define YYPTRDIFF_T long
-#  include <limits.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYPTRDIFF_MAXIMUM LONG_MAX
 # endif
 #endif
