@@ -286,9 +286,9 @@ typedef short int yytype_int16;
 #ifndef lint
 # define YYID(n) (n)
 #else
-]b4_c_function_def([YYID], [static int], [[int i], [i]])[
+]b4_c_function_def([YYID], [static int], [[int yyi], [yyi]])[
 {
-  return i;
+  return yyi;
 }
 #endif
 
@@ -673,12 +673,15 @@ do {									  \
 `------------------------------------------------------------------*/
 
 ]b4_c_function_def([yy_stack_print], [static void],
-		   [[yytype_int16 *bottom], [bottom]],
-		   [[yytype_int16 *top],    [top]])[
+		   [[yytype_int16 *yybottom], [yybottom]],
+		   [[yytype_int16 *yytop],    [yytop]])[
 {
   YYFPRINTF (stderr, "Stack now");
-  for (; bottom <= top; ++bottom)
-    YYFPRINTF (stderr, " %d", *bottom);
+  for (; yybottom <= yytop; yybottom++)
+    {
+      int yybot = *yybottom;
+      YYFPRINTF (stderr, " %d", yybot);
+    }
   YYFPRINTF (stderr, "\n");
 }
 
