@@ -425,9 +425,9 @@ typedef short yytype_int16;
 #  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
 # else
-#  define YYPTRDIFF_T int
+#  define YYPTRDIFF_T long
 #  include <limits.h> /* INFRINGES ON USER NAME SPACE */
-#  define YYPTRDIFF_MAXIMUM INT_MAX
+#  define YYPTRDIFF_MAXIMUM LONG_MAX
 # endif
 #endif
 
@@ -857,7 +857,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
                       yy_state_num **yytop, yy_state_num *yytop_empty)
 {
   YYPTRDIFF_T yysize_old =
-    *yytop == yytop_empty ? 0 : (YYPTRDIFF_T) (*yytop - *yybottom + 1);
+    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
   YYPTRDIFF_T yysize_new = yysize_old + yyadd;
   if (*yycapacity < yysize_new)
     {
@@ -1024,7 +1024,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         YYDPRINTF ((stderr, " R%d", yyrule - 1));
         if (yyesp != yyes_prev)
           {
-            YYPTRDIFF_T yysize = (YYPTRDIFF_T) (yyesp - *yyes + 1);
+            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
             if (yylen < yysize)
               {
                 yyesp -= yylen;
@@ -1155,7 +1155,7 @@ yytnamerr (char *yyres, const char *yystr)
     }
 
   if (yyres)
-    return (YYPTRDIFF_T) (yystpcpy (yyres, yystr) - yyres);
+    return yystpcpy (yyres, yystr) - yyres;
   else
     return yystrlen (yystr);
 }
@@ -1535,7 +1535,7 @@ yysetstate:
 #else
     {
       /* Get the current used size of the three stacks, in elements.  */
-      YYPTRDIFF_T yysize = (YYPTRDIFF_T) (yyssp - yyss + 1);
+      YYPTRDIFF_T yysize = yyssp - yyss + 1;
 
 # if defined yyoverflow
       {
