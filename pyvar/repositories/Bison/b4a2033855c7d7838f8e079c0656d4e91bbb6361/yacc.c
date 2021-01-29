@@ -506,14 +506,26 @@ while (0)
 #define YYERRCODE	256
 
 
-/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].  */
+/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
+   If N is 0, then set CURRENT to the empty location which ends
+   the previous symbol: RHS[0] (always defined).  */
 
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)		\
-   ((Current).first_line   = (Rhs)[1].first_line,	\
-    (Current).first_column = (Rhs)[1].first_column,	\
-    (Current).last_line    = (Rhs)[N].last_line,	\
-    (Current).last_column  = (Rhs)[N].last_column)
+# define YYLLOC_DEFAULT(Current, Rhs, N)				     \
+do {									     \
+  if (N)								     \
+    {									     \
+      (Current).first_line   = (Rhs)[1].first_line;			     \
+      (Current).first_column = (Rhs)[1].first_column;			     \
+      (Current).last_line    = (Rhs)[N].last_line;			     \
+      (Current).last_column  = (Rhs)[N].last_column;			     \
+    }									     \
+  else									     \
+    {									     \
+      (Current).first_line   = (Current).last_line   = (Rhs)[0].last_line;   \
+      (Current).first_column = (Current).last_column = (Rhs)[0].last_column; \
+    }									     \
+} while(0)
 #endif
 
 
@@ -1021,10 +1033,7 @@ yyreduce:
 
 ]b4_location_if(
 [[  /* Default location. */
-  if (yylen)
-    YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
-  else
-    yyloc = yylsp[0];]])[
+  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);]])[
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
     ]{
