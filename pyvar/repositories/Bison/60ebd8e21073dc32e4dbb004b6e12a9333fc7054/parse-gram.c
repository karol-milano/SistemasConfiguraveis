@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.2.213-aa24.  */
+/* A Bison parser, made by GNU Bison 3.4.90.16-c313.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.2.213-aa24"
+#define YYBISON_VERSION "3.4.90.16-c313"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -78,7 +78,15 @@
 #define yynerrs         gram_nerrs
 
 
-
+# ifndef YY_CAST
+#  ifdef __cplusplus
+#   define YY_CAST(Type, Val) static_cast<Type> (Val)
+#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
+#  else
+#   define YY_CAST(Type, Val) ((Type) (Val))
+#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
+#  endif
+# endif
 # ifndef YY_NULLPTR
 #  if defined __cplusplus
 #   if 201103L <= __cplusplus
@@ -289,10 +297,13 @@ typedef int yytype_uint16;
 # endif
 #endif
 
-#define YYSIZE_MAXIMUM ((YYPTRDIFF_T) (YYPTRDIFF_MAXIMUM < (YYSIZE_T) -1 \
-                                       ? YYPTRDIFF_MAXIMUM : (YYSIZE_T) -1))
+#define YYSIZE_MAXIMUM                                  \
+  YY_CAST (YYPTRDIFF_T,                                 \
+           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
+            ? YYPTRDIFF_MAXIMUM                         \
+            : YY_CAST (YYSIZE_T, -1)))
 
-#define YYSIZEOF(X) ((YYPTRDIFF_T) sizeof (X))
+#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))
 
 /* Stored state numbers (used for stacks). */
 typedef yytype_uint8 yy_state_t;
@@ -451,7 +462,7 @@ union yyalloc
 # ifndef YYCOPY
 #  if defined __GNUC__ && 1 < __GNUC__
 #   define YYCOPY(Dst, Src, Count) \
-      __builtin_memcpy (Dst, Src, (YYSIZE_T) (Count) * sizeof (*(Src)))
+      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
 #  else
 #   define YYCOPY(Dst, Src, Count)              \
       do                                        \
@@ -1225,8 +1236,8 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
       yybottom_new =
-        (yy_state_t *) YYSTACK_ALLOC ((YYSIZE_T)
-                                        (yyalloc * YYSIZEOF (*yybottom_new)));
+        YY_CAST(yy_state_t *,
+                YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yyalloc * YYSIZEOF (*yybottom_new))));
       if (!yybottom_new)
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
@@ -1398,7 +1409,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
-            *yyesp = (yy_state_t) yystate;
+            *yyesp = YY_CAST (yy_state_t, yystate);
           }
         else
           {
@@ -1411,7 +1422,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
-            *++yyesp = (yy_state_t) yystate;
+            *++yyesp = YY_CAST (yy_state_t, yystate);
           }
         YYDPRINTF ((stderr, " G%d", yystate));
       }
@@ -1423,7 +1434,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 
 # ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
-#   define yystrlen(S) ((YYPTRDIFF_T) strlen (S))
+#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
 #  else
 /* Return the length of YYSTR.  */
 static YYPTRDIFF_T
@@ -1845,7 +1856,7 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-   *yyssp = (yy_state_t) yystate;
+   *yyssp = YY_CAST (yy_state_t, yystate);
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1888,8 +1899,8 @@ yysetstate:
       {
         yy_state_t *yyss1 = yyss;
         union yyalloc *yyptr =
-          (union yyalloc *) YYSTACK_ALLOC ((YYSIZE_T)
-                                           YYSTACK_BYTES (yystacksize));
+          YY_CAST (union yyalloc *,
+                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
         if (! yyptr)
           goto yyexhaustedlab;
         YYSTACK_RELOCATE (yyss_alloc, yyss);
@@ -1906,7 +1917,7 @@ yysetstate:
       yylsp = yyls + yysize - 1;
 
       YYDPRINTF ((stderr, "Stack size increased to %ld\n",
-                  (long) yystacksize));
+                  YY_CAST (long, yystacksize)));
 
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
@@ -2619,7 +2630,7 @@ yyerrlab:
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
-            yymsg = (char *) YYSTACK_ALLOC ((YYSIZE_T) yymsg_alloc);
+            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
             if (!yymsg)
               {
                 yymsg = yymsgbuf;
