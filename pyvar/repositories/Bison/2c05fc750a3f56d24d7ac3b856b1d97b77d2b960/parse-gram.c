@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.3.219-2a6f.  */
+/* A Bison parser, made by GNU Bison 3.5.4.236-8d75.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.3.219-2a6f"
+#define YYBISON_VERSION "3.5.4.236-8d75"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -101,7 +101,7 @@
 
 #include "src/parse-gram.h"
 /* Symbol type.  */
-enum yysymbol_type_t
+enum yysymbol_kind_t
 {
   YYSYMBOL_YYEMPTY = -2,
   YYSYMBOL_YYEOF = 0,
@@ -208,7 +208,7 @@ enum yysymbol_type_t
   YYSYMBOL_string_as_id = 101,
   YYSYMBOL_102_epilogue_opt = 102
 };
-typedef enum yysymbol_type_t yysymbol_type_t;
+typedef enum yysymbol_kind_t yysymbol_kind_t;
 
 
 
@@ -608,7 +608,7 @@ union yyalloc
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
-#define YYTRANSLATE(YYX) YY_CAST (yysymbol_type_t, YYX)
+#define YYTRANSLATE(YYX) YY_CAST (yysymbol_kind_t, YYX)
 
 #if GRAM_DEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
@@ -631,15 +631,15 @@ static const yytype_int16 yyrline[] =
 #endif
 
 /** Accessing symbol of state STATE.  */
-#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_type_t, yystos[State])
+#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])
 
 #if 1
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (yysymbol_type_t yysymbol) YY_ATTRIBUTE_UNUSED;
+static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;
 
 static const char *
-yysymbol_name (yysymbol_type_t yysymbol)
+yysymbol_name (yysymbol_kind_t yysymbol)
 {
   static const char *const yy_sname[] =
   {
@@ -1035,7 +1035,7 @@ do {                                                                      \
 
 static void
 yy_symbol_value_print (FILE *yyo,
-                       yysymbol_type_t yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+                       yysymbol_kind_t yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   FILE *yyoutput = yyo;
   YYUSE (yyoutput);
@@ -1246,7 +1246,7 @@ troff (yyo);
 
 static void
 yy_symbol_print (FILE *yyo,
-                 yysymbol_type_t yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+                 yysymbol_kind_t yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   YYFPRINTF (yyo, "%s %s (",
              yytype < YYNTOKENS ? "token" : "nterm", yysymbol_name (yytype));
@@ -1480,7 +1480,7 @@ do {                                                                     \
    any old *YYES other than YYESA.  */
 static int
 yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
-        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_type_t yytoken)
+        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
 {
   yy_state_t *yyes_prev = yyssp;
   yy_state_t *yyesp = yyes_prev;
@@ -1590,7 +1590,7 @@ typedef struct
   yy_state_t *yyesa;
   yy_state_t **yyes;
   YYPTRDIFF_T *yyes_capacity;
-  yysymbol_type_t yytoken;
+  yysymbol_kind_t yytoken;
   YYLTYPE *yylloc;
 } yypcontext_t;
 
@@ -1602,7 +1602,7 @@ typedef struct
    YYARG up to YYARGN. */
 static int
 yyexpected_tokens (const yypcontext_t *yyctx,
-                   yysymbol_type_t yyarg[], int yyargn)
+                   yysymbol_kind_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1610,7 +1610,7 @@ yyexpected_tokens (const yypcontext_t *yyctx,
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
     {
-      yysymbol_type_t yysym = YY_CAST (yysymbol_type_t, yyx);
+      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
       if (yysym != YYSYMBOL_YYERROR && yysym != YYSYMBOL_YYUNDEF)
         switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
           {
@@ -1634,10 +1634,10 @@ yyexpected_tokens (const yypcontext_t *yyctx,
 
 
 /* The token type of the lookahead of this context.  */
-static yysymbol_type_t
+static yysymbol_kind_t
 yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
-static yysymbol_type_t
+static yysymbol_kind_t
 yypcontext_token (const yypcontext_t *yyctx)
 {
   return yyctx->yytoken;
@@ -1663,7 +1663,7 @@ yyreport_syntax_error (const yypcontext_t *yyctx);
 
 static void
 yydestruct (const char *yymsg,
-            yysymbol_type_t yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
+            yysymbol_kind_t yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 {
   YYUSE (yyvaluep);
   YYUSE (yylocationp);
@@ -1789,7 +1789,7 @@ YYLTYPE yylloc = yyloc_default;
   /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  yysymbol_type_t yytoken = YYSYMBOL_YYEMPTY;
+  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;
@@ -2595,7 +2595,7 @@ yyreduce:
      case of YYERROR or YYBACKUP, subsequent parser actions might lead
      to an incorrect destructor call or verbose syntax error message
      before the lookahead is translated.  */
-  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_type_t, yyr1[yyn]), &yyval, &yyloc);
+  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);
 
   YYPOPSTACK (yylen);
   yylen = 0;
@@ -2806,11 +2806,11 @@ yyreport_syntax_error (const yypcontext_t *ctx)
   enum { ARGS_MAX = 5 };
   const char *argv[ARGS_MAX];
   int argc = 0;
-  yysymbol_type_t unexpected = yypcontext_token (ctx);
+  yysymbol_kind_t unexpected = yypcontext_token (ctx);
   if (unexpected != YYSYMBOL_YYEMPTY)
     {
       argv[argc++] = yysymbol_name (unexpected);
-      yysymbol_type_t expected[ARGS_MAX - 1];
+      yysymbol_kind_t expected[ARGS_MAX - 1];
       int nexpected = yyexpected_tokens (ctx, expected, ARGS_MAX - 1);
       if (nexpected < 0)
         res = nexpected;
