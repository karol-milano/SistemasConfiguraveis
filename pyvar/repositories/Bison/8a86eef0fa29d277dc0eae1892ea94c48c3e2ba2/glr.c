@@ -2554,7 +2554,7 @@ m4_popdef([b4_at_dollar])])dnl
 }
 
 /* DEBUGGING ONLY */
-#ifdef YYDEBUG
+#if YYDEBUG
 static void yypstack (yyGLRStack* yystackp, size_t yyk)
   __attribute__ ((__unused__));
 static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));
@@ -2565,19 +2565,20 @@ yy_yypstack (yyGLRState* yys)
   if (yys->yypred)
     {
       yy_yypstack (yys->yypred);
-      fprintf (stderr, " -> ");
+      YYFPRINTF (stderr, " -> ");
     }
-  fprintf (stderr, "%d@@%lu", yys->yylrState, (unsigned long int) yys->yyposn);
+  YYFPRINTF (stderr, "%d@@%lu", yys->yylrState,
+             (unsigned long int) yys->yyposn);
 }
 
 static void
 yypstates (yyGLRState* yyst)
 {
   if (yyst == NULL)
-    fprintf (stderr, "<null>");
+    YYFPRINTF (stderr, "<null>");
   else
     yy_yypstack (yyst);
-  fprintf (stderr, "\n");
+  YYFPRINTF (stderr, "\n");
 }
 
 static void
@@ -2597,31 +2598,33 @@ yypdumpstack (yyGLRStack* yystackp)
   size_t yyi;
   for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
     {
-      fprintf (stderr, "%3lu. ", (unsigned long int) (yyp - yystackp->yyitems));
+      YYFPRINTF (stderr, "%3lu. ",
+                 (unsigned long int) (yyp - yystackp->yyitems));
       if (*(yybool *) yyp)
 	{
-	  fprintf (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
-		   yyp->yystate.yyresolved, yyp->yystate.yylrState,
-		   (unsigned long int) yyp->yystate.yyposn,
-		   (long int) YYINDEX (yyp->yystate.yypred));
+	  YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
+		     yyp->yystate.yyresolved, yyp->yystate.yylrState,
+		     (unsigned long int) yyp->yystate.yyposn,
+		     (long int) YYINDEX (yyp->yystate.yypred));
 	  if (! yyp->yystate.yyresolved)
-	    fprintf (stderr, ", firstVal: %ld",
-		     (long int) YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
+	    YYFPRINTF (stderr, ", firstVal: %ld",
+		       (long int) YYINDEX (yyp->yystate
+                                             .yysemantics.yyfirstVal));
 	}
       else
 	{
-	  fprintf (stderr, "Option. rule: %d, state: %ld, next: %ld",
-		   yyp->yyoption.yyrule - 1,
-		   (long int) YYINDEX (yyp->yyoption.yystate),
-		   (long int) YYINDEX (yyp->yyoption.yynext));
+	  YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
+		     yyp->yyoption.yyrule - 1,
+		     (long int) YYINDEX (yyp->yyoption.yystate),
+		     (long int) YYINDEX (yyp->yyoption.yynext));
 	}
-      fprintf (stderr, "\n");
+      YYFPRINTF (stderr, "\n");
     }
-  fprintf (stderr, "Tops:");
+  YYFPRINTF (stderr, "Tops:");
   for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
-    fprintf (stderr, "%lu: %ld; ", (unsigned long int) yyi,
-	     (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
-  fprintf (stderr, "\n");
+    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
+	       (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
+  YYFPRINTF (stderr, "\n");
 }
 #endif
 ]
