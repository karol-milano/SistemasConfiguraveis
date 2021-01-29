@@ -604,9 +604,14 @@ while (0)
 /* Enable debugging if requested.  */
 #if YYDEBUG
 
-# ifndef YYFPRINTF
+# ifdef YYFPRINTF
+#  define YYFPUTC(Char, Stream) YYFPRINTF (Stream, "%c", Char)
+#  define YYFPUTS(Char, Stream) YYFPRINTF (Stream, "%s", String)
+# else
 #  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYFPRINTF fprintf
+#  define YYFPUTC fputc
+#  define YYFPUTS fputs
 # endif
 
 # define YYDPRINTF(Args)			\
@@ -615,6 +620,12 @@ do {						\
     YYFPRINTF Args;				\
 } while (0)
 
+# define YYDPUTS(String, Stream)		\
+do {						\
+  if (yydebug)					\
+    YYFPUTS (String, Stream);			\
+} while (0)
+
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
 do {								\
   if (yydebug)							\
@@ -622,7 +633,7 @@ do {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr,					\
                   Type, Value]b4_location_if([, Location])[);	\
-      YYFPRINTF (stderr, "\n");					\
+      YYFPUTC ('\n', stderr);					\
     }								\
 } while (0)
 
@@ -635,10 +646,10 @@ do {								\
                    [[short int *bottom], [bottom]],
                    [[short int *top],    [top]])[
 {
-  YYFPRINTF (stderr, "Stack now");
+  YYFPUTS ("Stack now", stderr);
   for (/* Nothing. */; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
-  YYFPRINTF (stderr, "\n");
+  YYFPUTC ('\n', stderr);
 }
 
 # define YY_STACK_PRINT(Bottom, Top)				\
@@ -674,11 +685,15 @@ do {					\
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
+
 #else /* !YYDEBUG */
+
+# define YYDPUTS(String, File)
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
+
 #endif /* !YYDEBUG */
 
 
@@ -1020,7 +1035,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
      rule.  */
   int yylen;
 
-  YYDPRINTF ((stderr, "Starting parse\n"));
+  YYDPUTS ("Starting parse\n", stderr);
 
   yystate = 0;
   yyerrstatus = 0;
@@ -1158,14 +1173,14 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPRINTF ((stderr, "Reading a token: "));
+      YYDPUTS ("Reading a token: ", stderr);
       yychar = YYLEX;
     }
 
   if (yychar <= YYEOF)
     {
       yychar = yytoken = YYEOF;
-      YYDPRINTF ((stderr, "Now at end of input.\n"));
+      YYDPUTS ("Now at end of input.\n", stderr);
     }
   else
     {
