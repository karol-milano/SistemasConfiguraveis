@@ -609,6 +609,15 @@ static const char *const yytname[] =
 {
   ]b4_tname[
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
@@ -885,7 +894,7 @@ do {                                                             \
     {                                                            \
       YYDPRINTF ((stderr,                                        \
                   "LAC: initial context established for %s\n",   \
-                  yytname[yytoken]));                            \
+                  yysymbol_name(yytoken)));                      \
       yy_lac_established = 1;                                    \
       {                                                          \
         int yy_lac_status =                                      \
@@ -937,7 +946,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 {
   yy_state_t *yyes_prev = yyssp;
   yy_state_t *yyesp = yyes_prev;
-  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
+  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name(yytoken)));
   if (yytoken == YYUNDEFTOK)
     {
       YYDPRINTF ((stderr, " Always Err\n"));
