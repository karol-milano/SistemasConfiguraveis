@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.2.139-1283.  */
+/* A Bison parser, made by GNU Bison 3.4.2.169-2644f.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.2.139-1283"
+#define YYBISON_VERSION "3.4.2.169-2644f"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -185,11 +185,6 @@
   /* A string that describes a char (e.g., 'a' -> "'a'").  */
   static char const *char_name (char);
 
-  #define YYTYPE_INT16 int_fast16_t
-  #define YYTYPE_INT8 int_fast8_t
-  #define YYTYPE_UINT16 uint_fast16_t
-  #define YYTYPE_UINT8 uint_fast8_t
-
   /* Add style to semantic values in traces.  */
   static void tron (FILE *yyo);
   static void troff (FILE *yyo);
@@ -208,46 +203,77 @@
 # undef short
 #endif
 
-#ifdef YYTYPE_UINT8
-typedef YYTYPE_UINT8 yytype_uint8;
-#else
-typedef unsigned char yytype_uint8;
+/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
+   <limits.h> and (if available) <stdint.h> are included
+   so that the code can choose integer types of a good width.  */
+
+#ifndef __PTRDIFF_MAX__
+# ifndef INT_MAX
+#  include <limits.h> /* INFRINGES ON USER NAME SPACE */
+# endif
+# ifndef PTRDIFF_MAX
+#  if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
+#   include <stdint.h> /* INFRINGES ON USER NAME SPACE */
+#  endif
+# endif
 #endif
 
-#ifdef YYTYPE_INT8
-typedef YYTYPE_INT8 yytype_int8;
+/* Narrow types that promote to a signed type and that can represent a
+   signed or unsigned integer of at least N bits.  In tables they can
+   save space and decrease cache pressure.  Promoting to a signed type
+   helps avoid bugs in integer arithmetic.  */
+
+#ifdef __INT_LEAST8_MAX__
+typedef __INT_LEAST8_TYPE__ yytype_int8;
+#elif defined INT_LEAST8_MAX
+typedef int_least8_t yytype_int8;
 #else
 typedef signed char yytype_int8;
 #endif
 
-#ifdef YYTYPE_UINT16
-typedef YYTYPE_UINT16 yytype_uint16;
+#ifdef __INT_LEAST16_MAX__
+typedef __INT_LEAST16_TYPE__ yytype_int16;
+#elif defined INT_LEAST16_MAX
+typedef int_least16_t yytype_int16;
 #else
-typedef unsigned short yytype_uint16;
+typedef short yytype_int16;
 #endif
 
-#ifdef YYTYPE_INT16
-typedef YYTYPE_INT16 yytype_int16;
+#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
+typedef __UINT_LEAST8_TYPE__ yytype_uint8;
+#elif (!defined __UINT_LEAST8_MAX__ && defined UINT_LEAST8_MAX \
+       && UINT_LEAST8_MAX <= INT_MAX)
+typedef uint_least8_t yytype_uint8;
+#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
+typedef unsigned char yytype_uint8;
 #else
-typedef short yytype_int16;
+typedef short yytype_uint8;
+#endif
+
+#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
+typedef __UINT_LEAST16_TYPE__ yytype_uint16;
+#elif (!defined __UINT_LEAST16_MAX__ && defined UINT_LEAST16_MAX \
+       && UINT_LEAST16_MAX <= INT_MAX)
+typedef uint_least16_t yytype_uint16;
+#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
+typedef unsigned short yytype_uint16;
+#else
+typedef int yytype_uint16;
 #endif
 
 #ifndef YYPTRDIFF_T
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
-#  define YYPTRDIFF_T int
-#  include <limits.h> /* INFRINGES ON USER NAME SPACE */
-#  define YYPTRDIFF_MAXIMUM INT_MAX
+#  define YYPTRDIFF_T long
+#  define YYPTRDIFF_MAXIMUM LONG_MAX
 # endif
 #endif
 
@@ -467,19 +493,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   296,   296,   305,   306,   310,   311,   317,   321,   326,
-     327,   332,   333,   334,   335,   336,   341,   346,   347,   348,
-     349,   350,   351,   351,   352,   353,   354,   355,   356,   357,
-     358,   359,   363,   364,   373,   374,   378,   389,   393,   397,
-     405,   415,   416,   426,   427,   433,   446,   446,   451,   451,
-     456,   460,   470,   471,   472,   473,   477,   478,   483,   484,
-     488,   489,   493,   494,   495,   508,   517,   521,   525,   533,
-     534,   538,   551,   552,   564,   568,   572,   580,   582,   587,
-     594,   604,   608,   612,   620,   621,   629,   630,   636,   637,
-     638,   645,   645,   653,   654,   655,   660,   663,   665,   667,
-     669,   671,   673,   675,   677,   679,   684,   685,   694,   718,
-     719,   720,   721,   733,   735,   762,   767,   768,   773,   782,
-     783,   787,   788
+       0,   291,   291,   300,   301,   305,   306,   312,   316,   321,
+     322,   327,   328,   329,   330,   331,   336,   341,   342,   343,
+     344,   345,   346,   346,   347,   348,   349,   350,   351,   352,
+     353,   354,   358,   359,   368,   369,   373,   384,   388,   392,
+     400,   410,   411,   421,   422,   428,   441,   441,   446,   446,
+     451,   455,   465,   466,   467,   468,   472,   473,   478,   479,
+     483,   484,   488,   489,   490,   503,   512,   516,   520,   528,
+     529,   533,   546,   547,   559,   563,   567,   575,   577,   582,
+     589,   599,   603,   607,   615,   616,   624,   625,   631,   632,
+     633,   640,   640,   648,   649,   650,   655,   658,   660,   662,
+     664,   666,   668,   670,   672,   674,   679,   680,   689,   713,
+     714,   715,   716,   728,   730,   757,   762,   763,   768,   777,
+     778,   782,   783
 };
 #endif
 
@@ -1183,7 +1209,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
                       yy_state_num **yytop, yy_state_num *yytop_empty)
 {
   YYPTRDIFF_T yysize_old =
-    *yytop == yytop_empty ? 0 : (YYPTRDIFF_T) (*yytop - *yybottom + 1);
+    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
   YYPTRDIFF_T yysize_new = yysize_old + yyadd;
   if (*yycapacity < yysize_new)
     {
@@ -1347,7 +1373,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         YYDPRINTF ((stderr, " R%d", yyrule - 1));
         if (yyesp != yyes_prev)
           {
-            YYPTRDIFF_T yysize = (YYPTRDIFF_T) (yyesp - *yyes + 1);
+            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
             if (yylen < yysize)
               {
                 yyesp -= yylen;
@@ -1478,7 +1504,7 @@ yytnamerr (char *yyres, const char *yystr)
     }
 
   if (yyres)
-    return (YYPTRDIFF_T) (yystpcpy (yyres, yystr) - yyres);
+    return yystpcpy (yyres, yystr) - yyres;
   else
     return yystrlen (yystr);
 }
@@ -1782,7 +1808,7 @@ YYLTYPE yylloc = yyloc_default;
   yystacksize = YYINITDEPTH;
 
   yyes = yyesa;
-  yyes_capacity = (YYPTRDIFF_T) (sizeof yyesa / sizeof *yyes);
+  yyes_capacity = 20;
   if (YYMAXDEPTH < yyes_capacity)
     yyes_capacity = YYMAXDEPTH;
 
@@ -1829,7 +1855,7 @@ yysetstate:
 #else
     {
       /* Get the current used size of the three stacks, in elements.  */
-      YYPTRDIFF_T yysize = (YYPTRDIFF_T) (yyssp - yyss + 1);
+      YYPTRDIFF_T yysize = yyssp - yyss + 1;
 
 # if defined yyoverflow
       {
