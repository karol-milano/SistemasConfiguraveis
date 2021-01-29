@@ -108,11 +108,12 @@ b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
 /* This is the parser code for GLR (Generalized LR) parser. */
 
 /* FIXME: minimize these */
-#include <stdlib.h>
+#include <assert.h>
 #include <setjmp.h>
-#include <stdio.h>
 #include <stdarg.h>
-#include <assert.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 /* Identify Bison output.  */
 #define YYBISON	1
@@ -1497,7 +1498,8 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
     {
 #if YYERROR_VERBOSE
       yySymbol* const yytokenp = yystack->yytokenp;
-      int yyn, yyx, yycount, yysize;
+      int yyn, yyx, yycount;
+      size_t yysize;
       const char* yyprefix;
       char* yyp;
       char* yymsg;
@@ -1761,20 +1763,19 @@ static void yypstack (yyGLRStack* yystack, int yyk) ATTRIBUTE_UNUSED;
 static void yypdumpstack (yyGLRStack* yystack) ATTRIBUTE_UNUSED;
 
 static void
-yypstates (yyGLRState* yyst)
+yy_yypstack (yyGLRState* yys)
 {
-  static void
-  yy_yypstack (yyGLRState* yys)
+  if (yys->yypred)
     {
-      if (yys->yypred == NULL)
-	fprintf (stderr, "%d@%d", yys->yylrState, yys->yyposn);
-      else
-	{
-	  yy_yypstack (yys->yypred);
-	  fprintf (stderr, " -> %d@%d", yys->yylrState, yys->yyposn);
-	}
+      yy_yypstack (yys->yypred);
+      fprintf (stderr, " -> ");
     }
+  fprintf (stderr, "%d@%lu", yys->yylrState, (unsigned long) yys->yyposn);
+}
 
+static void
+yypstates (yyGLRState* yyst)
+{
   if (yyst == NULL)
     fprintf (stderr, "<null>");
   else
@@ -1799,28 +1800,30 @@ yypdumpstack (yyGLRStack* yystack)
   size_t yyi;
   for (yyp = yystack->yyitems; yyp < yystack->yynextFree; yyp += 1)
     {
-      fprintf (stderr, "%3d. ", yyp - yystack->yyitems);
+      fprintf (stderr, "%3lu. ", (unsigned long) (yyp - yystack->yyitems));
       if (*(bool*) yyp)
 	{
-	  fprintf (stderr, "Res: %d, LR State: %d, posn: %d, pred: %d",
+	  fprintf (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
 		   yyp->yystate.yyresolved, yyp->yystate.yylrState,
-		   yyp->yystate.yyposn,
-		   YYINDEX(yyp->yystate.yypred));
+		   (unsigned long) yyp->yystate.yyposn,
+		   (long) YYINDEX (yyp->yystate.yypred));
 	  if (! yyp->yystate.yyresolved)
-	    fprintf (stderr, ", firstVal: %d",
-		     YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
+	    fprintf (stderr, ", firstVal: %ld",
+		     (long) YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
 	}
       else
 	{
-	  fprintf (stderr, "Option. rule: %d, state: %d, next: %d",
-		   yyp->yyoption.yyrule, YYINDEX (yyp->yyoption.yystate),
-		   YYINDEX (yyp->yyoption.yynext));
+	  fprintf (stderr, "Option. rule: %d, state: %ld, next: %ld",
+		   yyp->yyoption.yyrule,
+		   (long) YYINDEX (yyp->yyoption.yystate),
+		   (long) YYINDEX (yyp->yyoption.yynext));
 	}
       fprintf (stderr, "\n");
     }
   fprintf (stderr, "Tops:");
   for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
-    fprintf (stderr, "%d: %d; ", yyi, YYINDEX (yystack->yytops.yystates[yyi]));
+    fprintf (stderr, "%lu: %ld; ", (unsigned long) yyi,
+	     (long) YYINDEX (yystack->yytops.yystates[yyi]));
   fprintf (stderr, "\n");
 }
 
