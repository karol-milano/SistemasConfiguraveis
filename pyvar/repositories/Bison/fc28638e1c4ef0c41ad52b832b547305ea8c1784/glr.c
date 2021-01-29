@@ -2016,7 +2016,6 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
   size_t yysize0 = yytnamerr (YY_NULL, yytokenName (yytoken));
   size_t yysize = yysize0;
-  size_t yysize1;
   yybool yysize_overflow = yyfalse;
   char* yymsg = YY_NULL;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
@@ -2076,9 +2075,11 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
                     break;
                   }
                 yyarg[yycount++] = yytokenName (yyx);
-                yysize1 = yysize + yytnamerr (YY_NULL, yytokenName (yyx));
-                yysize_overflow |= yysize1 < yysize;
-                yysize = yysize1;
+                {
+                  size_t yysz = yysize + yytnamerr (YY_NULL, yytokenName (yyx));
+                  yysize_overflow |= yysz < yysize;
+                  yysize = yysz;
+                }
               }
         }
     }
@@ -2098,9 +2099,11 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #undef YYCASE_
     }
 
-  yysize1 = yysize + strlen (yyformat);
-  yysize_overflow |= yysize1 < yysize;
-  yysize = yysize1;
+  {
+    size_t yysz = yysize + strlen (yyformat);
+    yysize_overflow |= yysz < yysize;
+    yysize = yysz;
+  }
 
   if (!yysize_overflow)
     yymsg = (char *) YYMALLOC (yysize);
