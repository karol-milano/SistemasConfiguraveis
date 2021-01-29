@@ -856,7 +856,8 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
                       yy_state_num *yybottom_no_free,
                       yy_state_num **yytop, yy_state_num *yytop_empty)
 {
-  YYPTRDIFF_T yysize_old = *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
+  YYPTRDIFF_T yysize_old =
+    *yytop == yytop_empty ? 0 : (YYPTRDIFF_T) (*yytop - *yybottom + 1);
   YYPTRDIFF_T yysize_new = yysize_old + yyadd;
   if (*yycapacity < yysize_new)
     {
@@ -1023,7 +1024,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         YYDPRINTF ((stderr, " R%d", yyrule - 1));
         if (yyesp != yyes_prev)
           {
-            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
+            YYPTRDIFF_T yysize = (YYPTRDIFF_T) (yyesp - *yyes + 1);
             if (yylen < yysize)
               {
                 yyesp -= yylen;
@@ -1534,7 +1535,7 @@ yysetstate:
 #else
     {
       /* Get the current used size of the three stacks, in elements.  */
-      YYPTRDIFF_T yysize = yyssp - yyss + 1;
+      YYPTRDIFF_T yysize = (YYPTRDIFF_T) (yyssp - yyss + 1);
 
 # if defined yyoverflow
       {
