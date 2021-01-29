@@ -36,11 +36,14 @@ b4_use_push_for_pull_if([
   b4_push_if([m4_define([b4_use_push_for_pull_flag], [[0]])],
              [m4_define([b4_push_flag], [[1]])])])
 
-# Check the value of %define parse.lac, where LAC stands for lookahead
-# correction.
+# Check the value of %define parse.lac and friends, where LAC stands for
+# lookahead correction.
 b4_percent_define_default([[parse.lac]], [[none]])
-b4_percent_define_default([[parse.lac.es-capacity]], [[20]])
-b4_percent_define_check_values([[[[parse.lac]], [[full]], [[none]]]])
+b4_percent_define_default([[parse.lac.es-capacity-initial]], [[20]])
+b4_percent_define_default([[parse.lac.memory-trace]], [[failures]])
+b4_percent_define_check_values([[[[parse.lac]], [[full]], [[none]]]],
+                               [[[[parse.lac.memory-trace]],
+                                 [[failures]], [[full]]]])
 b4_define_flag_if([lac])
 m4_define([b4_lac_flag],
           [m4_if(b4_percent_define_get([[parse.lac]]),
@@ -215,7 +218,11 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
     /* The locations where the error started and ended.  */
     YYLTYPE yyerror_range[3];]])[
 
-    YYSIZE_T yystacksize;]])
+    YYSIZE_T yystacksize;]b4_lac_if([[
+
+    yytype_int16 yyesa@{]b4_percent_define_get([[parse.lac.es-capacity-initial]])[@};
+    yytype_int16 *yyes;
+    YYSIZE_T yyes_capacity;]])])
 
 
 ## --------------------------------------------------------- ##
@@ -410,10 +417,10 @@ typedef short int yytype_int16;
 }
 #endif
 
-#if ! defined yyoverflow || YYERROR_VERBOSE
+#if ]b4_lac_if([[1]], [[! defined yyoverflow || YYERROR_VERBOSE]])[
 
-]b4_push_if([],
-[[/* The parser invokes alloca or malloc; define the necessary symbols.  */
+/* The parser invokes alloca or malloc; define the necessary symbols.  */]dnl
+b4_push_if([], [b4_lac_if([], [[
 
 # ifdef YYSTACK_USE_ALLOCA
 #  if YYSTACK_USE_ALLOCA
@@ -436,10 +443,9 @@ typedef short int yytype_int16;
 #    endif
 #   endif
 #  endif
-# endif
+# endif]])])[
 
-]])dnl
-[# ifdef YYSTACK_ALLOC
+# ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning.  */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
 #  ifndef YYSTACK_ALLOC_MAXIMUM
@@ -475,8 +481,9 @@ void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
-# endif
-#endif /* ! defined yyoverflow || YYERROR_VERBOSE */
+# endif]b4_lac_if([[
+# define YYCOPY_NEEDED 1]])[
+#endif]b4_lac_if([], [[ /* ! defined yyoverflow || YYERROR_VERBOSE */]])[
 
 
 #if (! defined yyoverflow \
@@ -505,23 +512,7 @@ union yyalloc
      ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
       + YYSTACK_GAP_MAXIMUM)])[
 
-/* Copy COUNT objects from FROM to TO.  The source and destination do
-   not overlap.  */
-# ifndef YYCOPY
-#  if defined __GNUC__ && 1 < __GNUC__
-#   define YYCOPY(To, From, Count) \
-      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
-#  else
-#   define YYCOPY(To, From, Count)		\
-      do					\
-	{					\
-	  YYSIZE_T yyi;				\
-	  for (yyi = 0; yyi < (Count); yyi++)	\
-	    (To)[yyi] = (From)[yyi];		\
-	}					\
-      while (YYID (0))
-#  endif
-# endif
+# define YYCOPY_NEEDED 1
 
 /* Relocate STACK from its old location to the new one.  The
    local variables YYSIZE and YYSTACKSIZE give the old and new number of
@@ -541,6 +532,26 @@ union yyalloc
 
 #endif
 
+#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
+/* Copy COUNT objects from FROM to TO.  The source and destination do
+   not overlap.  */
+# ifndef YYCOPY
+#  if defined __GNUC__ && 1 < __GNUC__
+#   define YYCOPY(To, From, Count) \
+      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
+#  else
+#   define YYCOPY(To, From, Count)		\
+      do					\
+	{					\
+	  YYSIZE_T yyi;				\
+	  for (yyi = 0; yyi < (Count); yyi++)	\
+	    (To)[yyi] = (From)[yyi];		\
+	}					\
+      while (YYID (0))
+#  endif
+# endif
+#endif /* !YYCOPY_NEEDED */
+
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  ]b4_final_state_number[
 /* YYLAST -- Last index in YYTABLE.  */
@@ -892,6 +903,68 @@ int yydebug;
 # define YYMAXDEPTH ]b4_stack_depth_max[
 #endif]b4_lac_if([[
 
+/* Given a state stack such that *YYBOTTOM is its bottom, such that
+   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
+   stack, and such that *YYCAPACITY is the maximum number of elements it
+   can hold without a reallocation, make sure there is enough room to
+   store YYADD more elements.  If not, allocate a new stack using
+   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
+   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
+   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
+   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
+   required.  Return 1 if memory is exhausted.  */
+static int
+yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
+#if YYDEBUG
+                      char const *yydebug_prefix,
+                      char const *yydebug_suffix,
+#endif
+                      yytype_int16 **yybottom,
+                      yytype_int16 *yybottom_no_free,
+                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
+{
+  YYSIZE_T yysize_old =
+    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
+  YYSIZE_T yysize_new = yysize_old + yyadd;
+  if (*yycapacity < yysize_new)
+    {
+      YYSIZE_T yyalloc = 2 * yysize_new;
+      yytype_int16 *yybottom_new;
+      /* Use YYMAXDEPTH for maximum stack size given that the stack
+         should never need to grow larger than the main state stack
+         needs to grow without LAC.  */
+      if (YYMAXDEPTH < yysize_new)
+        {
+          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
+                      yydebug_suffix));
+          return 1;
+        }
+      if (YYMAXDEPTH < yyalloc)
+        yyalloc = YYMAXDEPTH;
+      yybottom_new =
+        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
+      if (!yybottom_new)
+        {
+          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
+                      yydebug_suffix));
+          return 1;
+        }
+      if (*yytop != yytop_empty)
+        {
+          YYCOPY (yybottom_new, *yybottom, yysize_old);
+          *yytop = yybottom_new + (yysize_old - 1);
+        }
+      if (*yybottom != yybottom_no_free)
+        YYSTACK_FREE (*yybottom);
+      *yybottom = yybottom_new;
+      *yycapacity = yyalloc;]m4_if(b4_percent_define_get([[parse.lac.memory-trace]]),
+                                   [full], [[
+      YYDPRINTF ((stderr, "%srealloc to %lu%s", yydebug_prefix,
+                  (unsigned long int) yyalloc, yydebug_suffix));]])[
+    }
+  return 0;
+}
+
 /* Establish the initial context for the current lookahead if no initial
    context is currently established.
 
@@ -918,23 +991,23 @@ int yydebug;
    current lookahead, then check if that lookahead can eventually be
    shifted if syntactic actions continue from the current context.
    Report a syntax error if it cannot.  */
-#define YY_LAC_ESTABLISH                                       \
-do {                                                           \
-  if (!yy_lac_established)                                     \
-    {                                                          \
-      YYDPRINTF ((stderr,                                      \
-                  "LAC: initial context established for %s\n", \
-                  yytname[yytoken]));                          \
-      yy_lac_established = 1;                                  \
-      {                                                        \
-        int yy_lac_status =                                    \
-          yy_lac (yyssp, yytoken);                             \
-        if (yy_lac_status == 2)                                \
-          goto yyexhaustedlab;                                 \
-        if (yy_lac_status == 1)                                \
-          goto yyerrlab;                                       \
-      }                                                        \
-    }                                                          \
+#define YY_LAC_ESTABLISH                                         \
+do {                                                             \
+  if (!yy_lac_established)                                       \
+    {                                                            \
+      YYDPRINTF ((stderr,                                        \
+                  "LAC: initial context established for %s\n",   \
+                  yytname[yytoken]));                            \
+      yy_lac_established = 1;                                    \
+      {                                                          \
+        int yy_lac_status =                                      \
+          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
+        if (yy_lac_status == 2)                                  \
+          goto yyexhaustedlab;                                   \
+        if (yy_lac_status == 1)                                  \
+          goto yyerrlab;                                         \
+      }                                                          \
+    }                                                            \
 } while (YYID (0))
 
 /* Discard any previous initial lookahead context because of Event,
@@ -964,13 +1037,18 @@ do {                                                                     \
 #endif
 
 /* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
-   eventually (after perhaps some reductions) be shifted, and return 1
-   if not.  Return 2 if memory is exhausted.  */
+   eventually (after perhaps some reductions) be shifted, return 1 if
+   not, or return 2 if memory is exhausted.  As preconditions and
+   postconditions: *YYES_CAPACITY is the allocated size of the array to
+   which *YYES points, and either *YYES = YYESA or *YYES points to an
+   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
+   contents of either array, alter *YYES and *YYES_CAPACITY, and free
+   any old *YYES other than YYESA.  */
 static int
-yy_lac (yytype_int16 *yyssp, int yytoken)
+yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
+        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
 {
   yytype_int16 *yyes_prev = yyssp;
-  yytype_int16 yyes@{]b4_percent_define_get([[parse.lac.es-capacity]])[@};
   yytype_int16 *yyesp = yyes_prev;
   YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
   if (yytoken == YYUNDEFTOK)
@@ -1012,7 +1090,7 @@ yy_lac (yytype_int16 *yyssp, int yytoken)
         YYDPRINTF ((stderr, " R%d", yyrule - 1));
         if (yyesp != yyes_prev)
           {
-            YYSIZE_T yysize = yyesp - yyes + 1;
+            YYSIZE_T yysize = yyesp - *yyes + 1;
             if (yylen < yysize)
               {
                 yyesp -= yylen;
@@ -1040,14 +1118,18 @@ yy_lac (yytype_int16 *yyssp, int yytoken)
         }
         if (yyesp == yyes_prev)
           {
-            yyesp = yyes;
+            yyesp = *yyes;
             *yyesp = yystate;
           }
         else
           {
-            if (yyesp == yyes + (sizeof yyes / sizeof *yyes) - 1)
+            if (yy_lac_stack_realloc (yyes_capacity, 1,
+#if YYDEBUG
+                                      " (", ")",
+#endif
+                                      yyes, yyesa, &yyesp, yyes_prev))
               {
-                YYDPRINTF ((stderr, " (max stack size exceeded)\n"));
+                YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
             *++yyesp = yystate;
@@ -1147,7 +1229,7 @@ yytnamerr (char *yyres, const char *yystr)
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
    about the unexpected token YYTOKEN for the state stack whose top is
    YYSSP.]b4_lac_if([[  In order to see if a particular token T is a
-   valid looakhead, invoke yy_lac (YYSSP, T).]])[
+   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).]])[
 
    Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
    not large enough to hold the message.  In that case, also set
@@ -1156,7 +1238,8 @@ yytnamerr (char *yyres, const char *yystr)
    yy_lac returned 2]])[.  */
 static int
 yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
-                yytype_int16 *yyssp, int yytoken)
+                ]b4_lac_if([[yytype_int16 *yyesa, yytype_int16 **yyes,
+                YYSIZE_T *yyes_capacity, ]])[yytype_int16 *yyssp, int yytoken)
 {
   YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
@@ -1222,7 +1305,8 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
             if (yyx != YYTERROR && yyx != YYUNDEFTOK)
               {
                 {
-                  int yy_lac_status = yy_lac (yyssp, yyx);
+                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
+                                              yyssp, yyx);
                   if (yy_lac_status == 2)
                     return 2;
                   if (yy_lac_status == 1)
@@ -1387,7 +1471,9 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
      stack still needs to be freed.  */
   if (!yyps->yynew && yyps->yyss != yyps->yyssa)
     YYSTACK_FREE (yyps->yyss);
-#endif
+#endif]b4_lac_if([[
+  if (!yyps->yynew && yyps->yyes != yyps->yyesa)
+    YYSTACK_FREE (yyps->yyes);]])[
   free (yyps);]b4_pure_if([], [[
   yypstate_allocated = 0;]])[
 }
@@ -1405,7 +1491,10 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
 #define yyls yyps->yyls
 #define yylsp yyps->yylsp
 #define yyerror_range yyps->yyerror_range]])[
-#define yystacksize yyps->yystacksize
+#define yystacksize yyps->yystacksize]b4_lac_if([[
+#define yyesa yyps->yyesa
+#define yyes yyps->yyes
+#define yyes_capacity yyps->yyes_capacity]])[
 
 
 /*---------------.
@@ -1471,7 +1560,12 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   yyss = yyssa;
   yyvs = yyvsa;]b4_locations_if([[
   yyls = yylsa;]])[
-  yystacksize = YYINITDEPTH;
+  yystacksize = YYINITDEPTH;]b4_lac_if([[
+
+  yyes = yyesa;
+  yyes_capacity = sizeof yyesa / sizeof *yyes;
+  if (YYMAXDEPTH < yyes_capacity)
+    yyes_capacity = YYMAXDEPTH;]])[
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
@@ -1775,8 +1869,9 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (]b4_yyerror_args[YY_("syntax error"));
 #else
-# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yyssp, \
-                                        yytoken)
+# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \]b4_lac_if([[
+                                        yyesa, &yyes, &yyes_capacity, \]])[
+                                        yyssp, yytoken)
       {
         char const *yymsgp = YY_("syntax error");
         int yysyntax_error_status;]b4_lac_if([[
@@ -1954,7 +2049,9 @@ yyreturn:
 #ifndef yyoverflow
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
-#endif]b4_push_if([[
+#endif]b4_lac_if([[
+  if (yyes != yyesa)
+    YYSTACK_FREE (yyes);]])b4_push_if([[
   yyps->yynew = 1;
 
 yypushreturn:]])[
