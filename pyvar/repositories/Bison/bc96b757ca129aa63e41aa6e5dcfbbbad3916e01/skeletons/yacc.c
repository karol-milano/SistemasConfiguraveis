@@ -419,7 +419,7 @@ typedef short yytype_int16;
 # elif defined ptrdiff_t && defined PTRDIFF_MAX
 #  define YYPTRDIFF_T ptrdiff_t
 #  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
-# elif 199901 <= __STDC_VERSION__
+# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYPTRDIFF_T ptrdiff_t
 #  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
@@ -436,7 +436,7 @@ typedef short yytype_int16;
 #  define YYSIZE_T __SIZE_TYPE__
 # elif defined size_t
 #  define YYSIZE_T size_t
-# elif 199901 <= __STDC_VERSION__
+# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
