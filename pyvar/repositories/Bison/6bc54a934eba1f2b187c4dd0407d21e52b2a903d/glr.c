@@ -1256,10 +1256,10 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 # define YY_REDUCE_PRINT(Args)
 #else
 # define YY_REDUCE_PRINT(Args)          \
-do {                                    \
-  if (yydebug)                          \
-    yy_reduce_print Args;               \
-} while (0)
+  do {                                  \
+    if (yydebug)                        \
+      yy_reduce_print Args;             \
+  } while (0)
 
 /*----------------------------------------------------------------------.
 | Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
