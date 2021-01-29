@@ -461,62 +461,6 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
       return yychk_flag;                        \
   } while (0)
 
-#if ]b4_api_PREFIX[DEBUG
-
-# ifndef YYFPRINTF
-#  define YYFPRINTF fprintf
-# endif
-
-# define YY_FPRINTF                             \
-  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_
-
-# define YY_FPRINTF_(Args)                      \
-  do {                                          \
-    YYFPRINTF Args;                             \
-    YY_IGNORE_USELESS_CAST_END                  \
-  } while (0)
-
-# define YY_DPRINTF                             \
-  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_
-
-# define YY_DPRINTF_(Args)                      \
-  do {                                          \
-    if (yydebug)                                \
-      YYFPRINTF Args;                           \
-    YY_IGNORE_USELESS_CAST_END                  \
-  } while (0)
-
-]b4_yy_location_print_define[
-
-]b4_yy_symbol_print_define[
-
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
-  do {                                                                  \
-    if (yydebug)                                                        \
-      {                                                                 \
-        YY_FPRINTF ((stderr, "%s ", Title));                            \
-        yy_symbol_print (stderr, Type, Value]b4_locuser_args([Location])[);        \
-        YY_FPRINTF ((stderr, "\n"));                                    \
-      }                                                                 \
-  } while (0)
-
-/* Nonzero means print parse trace.  It is left uninitialized so that
-   multiple parsers can coexist.  */
-int yydebug;
-
-struct yyGLRStack;
-static void yypstack (struct yyGLRStack* yystackp, ptrdiff_t yyk)
-  YY_ATTRIBUTE_UNUSED;
-static void yypdumpstack (struct yyGLRStack* yystackp)
-  YY_ATTRIBUTE_UNUSED;
-
-#else /* !]b4_api_PREFIX[DEBUG */
-
-# define YY_DPRINTF(Args) do {} while (yyfalse)
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
-
-#endif /* !]b4_api_PREFIX[DEBUG */
-
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
 #ifndef YYINITDEPTH
 # define YYINITDEPTH ]b4_stack_depth_init[
@@ -755,6 +699,62 @@ yytokenName (yySymbol yytoken)
 }
 #endif
 
+#if ]b4_api_PREFIX[DEBUG
+
+# ifndef YYFPRINTF
+#  define YYFPRINTF fprintf
+# endif
+
+# define YY_FPRINTF                             \
+  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_
+
+# define YY_FPRINTF_(Args)                      \
+  do {                                          \
+    YYFPRINTF Args;                             \
+    YY_IGNORE_USELESS_CAST_END                  \
+  } while (0)
+
+# define YY_DPRINTF                             \
+  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_
+
+# define YY_DPRINTF_(Args)                      \
+  do {                                          \
+    if (yydebug)                                \
+      YYFPRINTF Args;                           \
+    YY_IGNORE_USELESS_CAST_END                  \
+  } while (0)
+
+]b4_yy_location_print_define[
+
+]b4_yy_symbol_print_define[
+
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
+  do {                                                                  \
+    if (yydebug)                                                        \
+      {                                                                 \
+        YY_FPRINTF ((stderr, "%s ", Title));                            \
+        yy_symbol_print (stderr, Type, Value]b4_locuser_args([Location])[);        \
+        YY_FPRINTF ((stderr, "\n"));                                    \
+      }                                                                 \
+  } while (0)
+
+/* Nonzero means print parse trace.  It is left uninitialized so that
+   multiple parsers can coexist.  */
+int yydebug;
+
+struct yyGLRStack;
+static void yypstack (struct yyGLRStack* yystackp, ptrdiff_t yyk)
+  YY_ATTRIBUTE_UNUSED;
+static void yypdumpstack (struct yyGLRStack* yystackp)
+  YY_ATTRIBUTE_UNUSED;
+
+#else /* !]b4_api_PREFIX[DEBUG */
+
+# define YY_DPRINTF(Args) do {} while (yyfalse)
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
+
+#endif /* !]b4_api_PREFIX[DEBUG */
+
 /** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
  *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
  *  containing the pointer to the next state in the chain.  */
