@@ -118,7 +118,7 @@ m4_define([b4_int_type],
        b4_ints_in($@,      [0], [65535]), [1], [yytype_uint16],
        b4_ints_in($@, [-32768], [32767]), [1], [yytype_int16],
 
-       m4_eval([0 <= $1]),                [1], [unsigned int],
+       m4_eval([0 <= $1]),                [1], [unsigned],
 
                                                [int])])
 
@@ -377,13 +377,13 @@ typedef signed char yytype_int8;
 #ifdef YYTYPE_UINT16
 typedef YYTYPE_UINT16 yytype_uint16;
 #else
-typedef unsigned short int yytype_uint16;
+typedef unsigned short yytype_uint16;
 #endif
 
 #ifdef YYTYPE_INT16
 typedef YYTYPE_INT16 yytype_int16;
 #else
-typedef short int yytype_int16;
+typedef short yytype_int16;
 #endif
 
 #ifndef YYSIZE_T
@@ -395,7 +395,7 @@ typedef short int yytype_int16;
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
-#  define YYSIZE_T unsigned int
+#  define YYSIZE_T unsigned
 # endif
 #endif
 
@@ -571,7 +571,7 @@ union yyalloc
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
 #define YYTRANSLATE(YYX)                                                \
-  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, without out-of-bounds checking.  */
@@ -719,7 +719,7 @@ do {                                                            \
                    ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
                    b4_parse_param]))[
 {
-  unsigned long int yylno = yyrline[yyrule];
+  unsigned long yylno = yyrline[yyrule];
   int yynrhs = yyr2[yyrule];
   int yyi;
   YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
@@ -827,7 +827,7 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
       *yycapacity = yyalloc;]m4_if(b4_percent_define_get([[parse.lac.memory-trace]]),
                                    [full], [[
       YYDPRINTF ((stderr, "%srealloc to %lu%s", yydebug_prefix,
-                  (unsigned long int) yyalloc, yydebug_suffix));]])[
+                  (unsigned long) yyalloc, yydebug_suffix));]])[
     }
   return 0;
 }
@@ -1510,7 +1510,7 @@ b4_locations_if([[  yylsp[0] = ]b4_push_if([b4_pure_if([*])yypushed_loc], [yyllo
       yylsp = yyls + yysize - 1;])[
 
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
-                  (unsigned long int) yystacksize));
+                  (unsigned long) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
