@@ -631,8 +631,17 @@ yysymbol_name (int yysymbol)
   static const char *const yy_sname[] =
   {
   ]b4_symbol_names[
+  };]m4_ifdef([b4_translatable], [[
+  /* YYTRANSLATABLE[SYMBOL-NUM] -- Whether YYTNAME[SYMBOL-NUM] is
+     internationalizable.  */
+  static ]b4_int_type_for([b4_translate])[ yytranslatable[] =
+  {
+  ]b4_translatable[
   };
-  return yy_sname[yysymbol];
+  return (yysymbol < YYNTOKENS && yytranslatable[yysymbol]
+          ? _(yy_sname[yysymbol])
+          : yy_sname[yysymbol]);]], [[
+  return yy_sname[yysymbol];]])[
 }]])[
 #endif
 
@@ -1248,7 +1257,6 @@ yytnamerr (char *yyres, const char *yystr)
     {
       YYPTRDIFF_T yyn = 0;
       char const *yyp = yystr;
-
       for (;;)
         switch (*++yyp)
           {
