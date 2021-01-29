@@ -2119,8 +2119,6 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   if (yytoken != YYEMPTY)
     {
       int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
-      ptrdiff_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
-      yysize = yysize0;
       yyarg[yycount++] = yytokenName (yytoken);
       if (!yypact_value_is_default (yyn))
         {
@@ -2139,17 +2137,9 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
                 if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                   {
                     yycount = 1;
-                    yysize = yysize0;
                     break;
                   }
                 yyarg[yycount++] = yytokenName (yyx);
-                {
-                  ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yytokenName (yyx));
-                  if (YYSIZEMAX - yysize < yysz)
-                    yysize_overflow = yytrue;
-                  else
-                    yysize += yysz;
-                }
               }
         }
     }
@@ -2170,14 +2160,19 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #undef YYCASE_
     }
 
+  /* Compute error message size.  Don't count the "%s"s, but reserve
+     room for the terminator.  */
+  yysize = YY_CAST (ptrdiff_t, strlen (yyformat)) - 2 * yycount + 1;
   {
-    /* Don't count the "%s"s in the final size, but reserve room for
-       the terminator.  */
-    ptrdiff_t yysz = YY_CAST (ptrdiff_t, strlen (yyformat)) - 2 * yycount + 1;
-    if (YYSIZEMAX - yysize < yysz)
-      yysize_overflow = yytrue;
-    else
-      yysize += yysz;
+    int yyi;
+    for (yyi = 0; yyi < yycount; ++yyi)
+      {
+        ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yyarg[yyi]);
+        if (YYSIZEMAX - yysize < yysz)
+          yysize_overflow = yytrue;
+        else
+          yysize += yysz;
+      }
   }
 
   if (!yysize_overflow)
