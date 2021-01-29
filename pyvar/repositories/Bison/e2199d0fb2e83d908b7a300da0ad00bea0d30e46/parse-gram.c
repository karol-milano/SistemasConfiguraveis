@@ -468,9 +468,9 @@ typedef int yy_state_fast_t;
 
 /* Suppress unused-variable warnings by "using" E.  */
 #if ! defined lint || defined __GNUC__
-# define YYUSE(E) ((void) (E))
+# define YY_USE(E) ((void) (E))
 #else
-# define YYUSE(E) /* empty */
+# define YY_USE(E) /* empty */
 #endif
 
 /* Suppress an incorrect diagnostic about yylval being uninitialized.  */
@@ -1070,8 +1070,8 @@ yy_symbol_value_print (FILE *yyo,
                        yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   FILE *yyoutput = yyo;
-  YYUSE (yyoutput);
-  YYUSE (yylocationp);
+  YY_USE (yyoutput);
+  YY_USE (yylocationp);
   if (!yyvaluep)
     return;
 # ifdef YYPRINT
@@ -1703,8 +1703,8 @@ static void
 yydestruct (const char *yymsg,
             yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 {
-  YYUSE (yyvaluep);
-  YYUSE (yylocationp);
+  YY_USE (yyvaluep);
+  YY_USE (yylocationp);
   if (!yymsg)
     yymsg = "Deleting";
   YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);
