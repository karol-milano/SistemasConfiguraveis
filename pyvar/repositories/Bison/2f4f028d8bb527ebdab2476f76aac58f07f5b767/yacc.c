@@ -604,14 +604,9 @@ while (0)
 /* Enable debugging if requested.  */
 #if YYDEBUG
 
-# ifdef YYFPRINTF
-#  define YYFPUTC(Char, Stream) YYFPRINTF (Stream, "%c", Char)
-#  define YYFPUTS(Char, Stream) YYFPRINTF (Stream, "%s", String)
-# else
+# ifndef YYFPRINTF
 #  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYFPRINTF fprintf
-#  define YYFPUTC fputc
-#  define YYFPUTS fputs
 # endif
 
 # define YYDPRINTF(Args)			\
@@ -620,12 +615,6 @@ do {						\
     YYFPRINTF Args;				\
 } while (0)
 
-# define YYDPUTS(String, Stream)		\
-do {						\
-  if (yydebug)					\
-    YYFPUTS (String, Stream);			\
-} while (0)
-
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
 do {								\
   if (yydebug)							\
@@ -633,7 +622,7 @@ do {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr,					\
                   Type, Value]b4_location_if([, Location])[);	\
-      YYFPUTC ('\n', stderr);					\
+      YYFPRINTF (stderr, "\n");					\
     }								\
 } while (0)
 
@@ -646,10 +635,10 @@ do {								\
                    [[short int *bottom], [bottom]],
                    [[short int *top],    [top]])[
 {
-  YYFPUTS ("Stack now", stderr);
+  YYFPRINTF (stderr, "Stack now");
   for (/* Nothing. */; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
-  YYFPUTC ('\n', stderr);
+  YYFPRINTF (stderr, "\n");
 }
 
 # define YY_STACK_PRINT(Bottom, Top)				\
@@ -685,15 +674,11 @@ do {					\
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
-
 #else /* !YYDEBUG */
-
-# define YYDPUTS(String, File)
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
-
 #endif /* !YYDEBUG */
 
 
@@ -1035,7 +1020,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
      rule.  */
   int yylen;
 
-  YYDPUTS ("Starting parse\n", stderr);
+  YYDPRINTF ((stderr, "Starting parse\n"));
 
   yystate = 0;
   yyerrstatus = 0;
@@ -1173,14 +1158,14 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPUTS ("Reading a token: ", stderr);
+      YYDPRINTF ((stderr, "Reading a token: "));
       yychar = YYLEX;
     }
 
   if (yychar <= YYEOF)
     {
       yychar = yytoken = YYEOF;
-      YYDPUTS ("Now at end of input.\n", stderr);
+      YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
     {
