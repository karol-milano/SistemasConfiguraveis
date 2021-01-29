@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.2.115-5e16-dirty.  */
+/* A Bison parser, made by GNU Bison 3.4.2.139-1283.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.2.115-5e16-dirty"
+#define YYBISON_VERSION "3.4.2.139-1283"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -239,7 +239,7 @@ typedef short yytype_int16;
 # elif defined ptrdiff_t && defined PTRDIFF_MAX
 #  define YYPTRDIFF_T ptrdiff_t
 #  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
-# elif 199901 <= __STDC_VERSION__
+# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYPTRDIFF_T ptrdiff_t
 #  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
@@ -256,7 +256,7 @@ typedef short yytype_int16;
 #  define YYSIZE_T __SIZE_TYPE__
 # elif defined size_t
 #  define YYSIZE_T size_t
-# elif 199901 <= __STDC_VERSION__
+# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
@@ -331,18 +331,6 @@ typedef yytype_uint8 yy_state_num;
 #endif
 
 
-/* Suppress bogus -Wconversion warnings from GCC.  */
-#if 4 < __GNUC__ + (7 <= __GNUC_MINOR__)
-# define YY_CONVERT_INT_BEGIN \
-    _Pragma ("GCC diagnostic push") \
-    _Pragma ("GCC diagnostic ignored \"-Wconversion\"")
-# define YY_CONVERT_INT_END \
-    _Pragma ("GCC diagnostic pop")
-#else
-# define YY_CONVERT_INT_BEGIN
-# define YY_CONVERT_INT_END
-#endif
-
 #define YY_ASSERT(E) ((void) (0 && (E)))
 
 #if 1
@@ -1194,7 +1182,8 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
                       yy_state_num *yybottom_no_free,
                       yy_state_num **yytop, yy_state_num *yytop_empty)
 {
-  YYPTRDIFF_T yysize_old = *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
+  YYPTRDIFF_T yysize_old =
+    *yytop == yytop_empty ? 0 : (YYPTRDIFF_T) (*yytop - *yybottom + 1);
   YYPTRDIFF_T yysize_new = yysize_old + yyadd;
   if (*yycapacity < yysize_new)
     {
@@ -1358,7 +1347,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         YYDPRINTF ((stderr, " R%d", yyrule - 1));
         if (yyesp != yyes_prev)
           {
-            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
+            YYPTRDIFF_T yysize = (YYPTRDIFF_T) (yyesp - *yyes + 1);
             if (yylen < yysize)
               {
                 yyesp -= yylen;
@@ -1385,9 +1374,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
-            YY_CONVERT_INT_BEGIN
-            *yyesp = yystate;
-            YY_CONVERT_INT_END
+            *yyesp = (yy_state_num) yystate;
           }
         else
           {
@@ -1400,9 +1387,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
-            YY_CONVERT_INT_BEGIN
-            *++yyesp = yystate;
-            YY_CONVERT_INT_END
+            *++yyesp = (yy_state_num) yystate;
           }
         YYDPRINTF ((stderr, " G%d", yystate));
       }
@@ -1492,10 +1477,10 @@ yytnamerr (char *yyres, const char *yystr)
     do_not_strip_quotes: ;
     }
 
-  if (! yyres)
+  if (yyres)
+    return (YYPTRDIFF_T) (yystpcpy (yyres, yystr) - yyres);
+  else
     return yystrlen (yystr);
-
-  return yystpcpy (yyres, yystr) - yyres;
 }
 # endif
 
@@ -1797,7 +1782,7 @@ YYLTYPE yylloc = yyloc_default;
   yystacksize = YYINITDEPTH;
 
   yyes = yyesa;
-  yyes_capacity = sizeof yyesa / sizeof *yyes;
+  yyes_capacity = (YYPTRDIFF_T) (sizeof yyesa / sizeof *yyes);
   if (YYMAXDEPTH < yyes_capacity)
     yyes_capacity = YYMAXDEPTH;
 
@@ -1836,9 +1821,7 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-  YY_CONVERT_INT_BEGIN
-  *yyssp = yystate;
-  YY_CONVERT_INT_END
+   *yyssp = (yy_state_num) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1846,7 +1829,7 @@ yysetstate:
 #else
     {
       /* Get the current used size of the three stacks, in elements.  */
-      YYPTRDIFF_T yysize = yyssp - yyss + 1;
+      YYPTRDIFF_T yysize = (YYPTRDIFF_T) (yyssp - yyss + 1);
 
 # if defined yyoverflow
       {
