@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.22-948cd-dirty.  */
+/* A Bison parser, made by GNU Bison 3.5.49-3790-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.22-948cd-dirty"
+#define YYBISON_VERSION "3.5.49-3790-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -552,6 +552,15 @@ static const char *const yytname[] =
   "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
   "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
 };
+
+/* The user-facing name of the symbol whose (internal) number is
+   YYSYMBOL.  No bounds checking.  */
+static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
+static const char *
+yysymbol_name (int yysymbol)
+{
+  return yytname[yysymbol];
+}
 #endif
 
 # ifdef YYPRINT
@@ -794,8 +803,9 @@ static const yytype_int8 yyr2[] =
       }                                                           \
   while (0)
 
-/* Error token number */
+/* Error symbol internal number. */
 #define YYTERROR        1
+/* Error token external number. */
 #define YYERRCODE       256
 
 
@@ -1293,7 +1303,7 @@ do {                                                             \
     {                                                            \
       YYDPRINTF ((stderr,                                        \
                   "LAC: initial context established for %s\n",   \
-                  yytname[yytoken]));                            \
+                  yysymbol_name(yytoken)));                      \
       yy_lac_established = 1;                                    \
       {                                                          \
         int yy_lac_status =                                      \
@@ -1345,7 +1355,8 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 {
   yy_state_t *yyes_prev = yyssp;
   yy_state_t *yyesp = yyes_prev;
-  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
+  /* Reduce until we encounter a shift and thereby accept the token.  */
+  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name(yytoken)));
   if (yytoken == YYUNDEFTOK)
     {
       YYDPRINTF ((stderr, " Always Err\n"));
@@ -1358,6 +1369,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
           || (yyrule += yytoken) < 0 || YYLAST < yyrule
           || yycheck[yyrule] != yytoken)
         {
+          /* Use the default action.  */
           yyrule = yydefact[+*yyesp];
           if (yyrule == 0)
             {
@@ -1367,6 +1379,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
         }
       else
         {
+          /* Use the action from yytable.  */
           yyrule = yytable[yyrule];
           if (yytable_value_is_error (yyrule))
             {
@@ -1380,9 +1393,12 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
             }
           yyrule = -yyrule;
         }
+      /* By now we know we have to simulate a reduce.  */
+      YYDPRINTF ((stderr, " R%d", yyrule - 1));
       {
+        /* Pop the corresponding number of values from the stack.  */
         YYPTRDIFF_T yylen = yyr2[yyrule];
-        YYDPRINTF ((stderr, " R%d", yyrule - 1));
+        /* First pop from the LAC stack as many tokens as possible.  */
         if (yyesp != yyes_prev)
           {
             YYPTRDIFF_T yysize = yyesp - *yyes + 1;
@@ -1393,13 +1409,15 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
               }
             else
               {
-                yylen -= yysize;
                 yyesp = yyes_prev;
+                yylen -= yysize;
               }
           }
+        /* Only afterwards look at the main stack.  */
         if (yylen)
           yyesp = yyes_prev -= yylen;
       }
+      /* Push the resulting state of the reduction.  */
       {
         yy_state_fast_t yystate;
         {
@@ -1573,8 +1591,6 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   if (yytoken != YYEMPTY)
     {
       int yyn = yypact[+*yyssp];
-      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
-      yysize = yysize0;
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
@@ -1790,8 +1806,10 @@ YYLTYPE yylloc = yyloc_default;
     yy_state_t *yyes;
     YYPTRDIFF_T yyes_capacity;
 
+  /* Whether LAC context is established.  A Boolean.  */
   int yy_lac_established = 0;
   int yyn;
+  /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
   int yytoken = 0;
