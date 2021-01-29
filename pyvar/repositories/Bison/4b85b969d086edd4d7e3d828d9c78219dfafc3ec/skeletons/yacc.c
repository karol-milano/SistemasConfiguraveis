@@ -403,50 +403,10 @@ m4_if(b4_api_prefix, [yy], [],
 ]b4_declare_symbol_enum[
 
 ]b4_user_post_prologue[
-]b4_percent_code_get[]dnl
-
-[#ifdef short
-# undef short
-#endif
-
+]b4_percent_code_get[
 ]b4_c99_int_type_define[
 
-#ifndef YYPTRDIFF_T
-# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
-#  define YYPTRDIFF_T __PTRDIFF_TYPE__
-#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
-# elif defined PTRDIFF_MAX
-#  ifndef ptrdiff_t
-#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
-#  endif
-#  define YYPTRDIFF_T ptrdiff_t
-#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
-# else
-#  define YYPTRDIFF_T long
-#  define YYPTRDIFF_MAXIMUM LONG_MAX
-# endif
-#endif
-
-#ifndef YYSIZE_T
-# ifdef __SIZE_TYPE__
-#  define YYSIZE_T __SIZE_TYPE__
-# elif defined size_t
-#  define YYSIZE_T size_t
-# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
-#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
-#  define YYSIZE_T size_t
-# else
-#  define YYSIZE_T unsigned
-# endif
-#endif
-
-#define YYSIZE_MAXIMUM                                  \
-  YY_CAST (YYPTRDIFF_T,                                 \
-           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
-            ? YYPTRDIFF_MAXIMUM                         \
-            : YY_CAST (YYSIZE_T, -1)))
-
-#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))
+]b4_sizes_types_define[
 
 /* Stored state numbers (used for stacks). */
 typedef ]b4_int_type(0, m4_eval(b4_states_number - 1))[ yy_state_t;
