@@ -219,6 +219,16 @@ static YYLTYPE yyloc_default;
 ]/* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])
 [
+#ifndef YYFREE
+# define YYFREE free
+#endif
+#ifndef YYMALLOC
+# define YYMALLOC malloc
+#endif
+#ifndef YYREALLOC
+# define YYREALLOC realloc
+#endif
+
 #ifdef __cplusplus
    typedef bool yybool;
 #else
@@ -865,13 +875,13 @@ yyinitStateSet (yyGLRStateSet* yyset)
 {
   yyset->yysize = 1;
   yyset->yycapacity = 16;
-  yyset->yystates = (yyGLRState**) malloc (16 * sizeof (yyset->yystates[0]));
+  yyset->yystates = YYMALLOC (16 * sizeof yyset->yystates[0]);
   yyset->yystates[0] = NULL;
 }
 
 static void yyfreeStateSet (yyGLRStateSet* yyset)
 {
-  free (yyset->yystates);
+  YYFREE (yyset->yystates);
 }
 
 /** Initialize STACK to a single empty stack, with total maximum
@@ -884,7 +894,7 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
   yynerrs = 0;
   yystack->yyspaceLeft = yysize;
   yystack->yynextFree = yystack->yyitems =
-    (yyGLRStackItem*) malloc (yysize * sizeof (yystack->yynextFree[0]));
+    YYMALLOC (yysize * sizeof yystack->yynextFree[0]);
   yystack->yysplitPoint = NULL;
   yystack->yylastDeleted = NULL;
   yyinitStateSet (&yystack->yytops);
@@ -948,7 +958,7 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
       yystack->yytops.yystates[yyn] =
 	YYRELOC (yystack->yyitems, yynewStack.yyitems,
 		 yystack->yytops.yystates[yyn], yystate);
-  free (yystack->yyitems);
+  YYFREE (yystack->yyitems);
   yystack->yyitems = yynewStack.yyitems;
   yystack->yynextFree = yynewStack.yynextFree + yysize;
   yystack->yyspaceLeft = yynewStack.yyspaceLeft - yysize;
@@ -962,7 +972,7 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
 static void
 yyfreeGLRStack (yyGLRStack* yystack)
 {
-  free (yystack->yyitems);
+  YYFREE (yystack->yyitems);
   yyfreeStateSet (&yystack->yytops);
 }
 
@@ -1231,9 +1241,9 @@ yysplitStack (yyGLRStack* yystack, int yyk)
     {
       yystack->yytops.yycapacity *= 2;
       yystack->yytops.yystates =
-	(yyGLRState**) realloc (yystack->yytops.yystates,
-				yystack->yytops.yycapacity
-				* sizeof (yyGLRState*));
+	YYREALLOC (yystack->yytops.yystates,
+		   (yystack->yytops.yycapacity
+		    * sizeof yystack->yytops.yystates[0]));
     }
   yystack->yytops.yystates[yystack->yytops.yysize]
     = yystack->yytops.yystates[yyk];
@@ -1644,7 +1654,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 	      }
 	  yysize += (sizeof ("syntax error, unexpected ")
 		     + strlen (yytokenName (*yytokenp)));
-	  yymsg = (char*) malloc (yysize);
+	  yymsg = YYMALLOC (yysize);
 	  if (yymsg != 0)
 	    {
 	      char* yyp = yymsg;
@@ -1663,7 +1673,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 		      }
 		}
 	      yyerror (]b4_lyyerror_args[yymsg);
-	      free (yymsg);
+	      YYFREE (yymsg);
 	    }
 	  else
 	    yyerror (]b4_lyyerror_args["syntax error; also virtual memory exhausted");
