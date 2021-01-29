@@ -500,9 +500,12 @@ static const int YYEMPTY = -2;
 
 typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
-#define YYCHK(YYE)							     \
-   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }	     \
-   while (YYID (0))
+#define YYCHK(YYE)                              \
+  do {                                          \
+    YYRESULTTAG yyflag = YYE;                   \
+    if (yyflag != yyok)                         \
+      return yyflag;                            \
+  } while (YYID (0))
 
 #if YYDEBUG
 
@@ -511,23 +514,23 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 # endif
 
 # define YYDPRINTF(Args)			\
-do {						\
-  if (yydebug)					\
-    YYFPRINTF Args;				\
-} while (YYID (0))
+  do {						\
+    if (yydebug)                                \
+      YYFPRINTF Args;				\
+  } while (YYID (0))
 
 ]b4_yy_symbol_print_generate([b4_c_ansi_function_def])[
 
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			    \
-do {									    \
-  if (yydebug)								    \
-    {									    \
-      YYFPRINTF (stderr, "%s ", Title);					    \
-      yy_symbol_print (stderr, Type,					    \
-		       Value]b4_locations_if([, Location])[]b4_user_args[);  \
-      YYFPRINTF (stderr, "\n");						    \
-    }									    \
-} while (YYID (0))
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
+  do {                                                                  \
+    if (yydebug)                                                        \
+      {                                                                 \
+        YYFPRINTF (stderr, "%s ", Title);                               \
+        yy_symbol_print (stderr, Type,                                  \
+                         Value]b4_locations_if([, Location])[]b4_user_args[); \
+        YYFPRINTF (stderr, "\n");                                       \
+      }                                                                 \
+  } while (YYID (0))
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
