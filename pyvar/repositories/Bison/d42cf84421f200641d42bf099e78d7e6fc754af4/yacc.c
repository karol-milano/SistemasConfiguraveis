@@ -71,14 +71,15 @@ m4_ifdef([b4_lex_param], b4_lex_param)))
 # b4_int_type(MIN, MAX)
 # ---------------------
 # Return the smallest int type able to handle numbers ranging from
-# MIN to MAX (included).  We overwrite the version from c.m4 which relies
-# on "signed char" which is not portable to old K&R compilers.
+# MIN to MAX (included).  Overwrite the version from c.m4, which
+# uses only C89 types, so that the user can override the shorter
+# types, and so that pre-C89 compilers are handled correctly.
 m4_define([b4_int_type],
-[m4_if(b4_ints_in($@,      [0],   [255]), [1], [unsigned char],
-       b4_ints_in($@,   [-128],   [127]), [1], [yysigned_char],
+[m4_if(b4_ints_in($@,      [0],   [255]), [1], [yytype_uint8],
+       b4_ints_in($@,   [-128],   [127]), [1], [yytype_int8],
 
-       b4_ints_in($@,      [0], [65535]), [1], [unsigned short int],
-       b4_ints_in($@, [-32768], [32767]), [1], [short int],
+       b4_ints_in($@,      [0], [65535]), [1], [yytype_uint16],
+       b4_ints_in($@, [-32768], [32767]), [1], [yytype_int16],
 
        m4_eval([0 <= $1]),                [1], [unsigned int],
 
@@ -220,6 +221,36 @@ typedef struct YYLTYPE
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])[
 
+#ifdef short
+# undef short
+#endif
+
+#ifdef YYTYPE_UINT8
+typedef YYTYPE_UINT8 yytype_uint8;
+#else
+typedef unsigned char yytype_uint8;
+#endif
+
+#ifdef YYTYPE_INT8
+typedef YYTYPE_INT8 yytype_int8;
+#elif ]b4_c_modern[
+typedef signed char yytype_int8;
+#else
+typedef short int yytype_int8;
+#endif
+
+#ifdef YYTYPE_UINT16
+typedef YYTYPE_UINT16 yytype_uint16;
+#else
+typedef unsigned short int yytype_uint16;
+#endif
+
+#ifdef YYTYPE_INT16
+typedef YYTYPE_INT16 yytype_int16;
+#else
+typedef short int yytype_int16;
+#endif
+
 #ifndef YYSIZE_T
 # ifdef __SIZE_TYPE__
 #  define YYSIZE_T __SIZE_TYPE__
@@ -337,7 +368,7 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  short int yyss;
+  yytype_int16 yyss;
   YYSTYPE yyvs;
   ]b4_location_if([  YYLTYPE yyls;
 ])dnl
@@ -350,10 +381,10 @@ union yyalloc
    N elements.  */
 ]b4_location_if(
 [# define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (short int) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
+     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
       + 2 * YYSTACK_GAP_MAXIMUM)],
 [# define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
+     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
       + YYSTACK_GAP_MAXIMUM)])[
 
 /* Copy COUNT objects from FROM to TO.  The source and destination do
@@ -392,12 +423,6 @@ union yyalloc
 
 #endif
 
-#if ]b4_c_modern[
-   typedef signed char yysigned_char;
-#else
-   typedef short int yysigned_char;
-#endif
-
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  ]b4_final_state_number[
 /* YYLAST -- Last index in YYTABLE.  */
@@ -649,8 +674,8 @@ do {									  \
 `------------------------------------------------------------------*/
 
 ]b4_c_function_def([yy_stack_print], [static void],
-		   [[short int *bottom], [bottom]],
-		   [[short int *top],    [top]])[
+		   [[yytype_int16 *bottom], [bottom]],
+		   [[yytype_int16 *top],    [top]])[
 {
   YYFPRINTF (stderr, "Stack now");
   for (; bottom <= top; ++bottom)
@@ -993,9 +1018,9 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
      to reallocate them elsewhere.  */
 
   /* The state stack.  */
-  short int yyssa[YYINITDEPTH];
-  short int *yyss = yyssa;
-  short int *yyssp;
+  yytype_int16 yyssa[YYINITDEPTH];
+  yytype_int16 *yyss = yyssa;
+  yytype_int16 *yyssp;
 
   /* The semantic value stack.  */
   YYSTYPE yyvsa[YYINITDEPTH];
@@ -1082,7 +1107,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	   these so that the &'s don't force the real ones into
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
-	short int *yyss1 = yyss;
+	yytype_int16 *yyss1 = yyss;
 ]b4_location_if([	YYLTYPE *yyls1 = yyls;])[
 
 	/* Each stack pointer address is followed by the size of the
@@ -1110,7 +1135,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	yystacksize = YYMAXDEPTH;
 
       {
-	short int *yyss1 = yyss;
+	yytype_int16 *yyss1 = yyss;
 	union yyalloc *yyptr =
 	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
 	if (! yyptr)
