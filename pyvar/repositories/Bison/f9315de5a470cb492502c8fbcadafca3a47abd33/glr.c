@@ -1606,35 +1606,44 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 		YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   yySemanticOption* yybest;
-  yySemanticOption* yyp;
+  yySemanticOption** yypp;
   yybool yymerge;
 
   yybest = yyoptionList;
   yymerge = yyfalse;
-  for (yyp = yyoptionList->yynext; yyp != NULL; yyp = yyp->yynext)
+  for (yypp = &yyoptionList->yynext; *yypp != NULL; )
     {
+      yySemanticOption* yyp = *yypp;
+
       if (yyidenticalOptions (yybest, yyp))
-	yymergeOptionSets (yybest, yyp);
+	{
+	  yymergeOptionSets (yybest, yyp);
+	  *yypp = yyp->yynext;
+	}
       else
-	switch (yypreference (yybest, yyp))
-	  {
-	  case 0:
-	    yyreportAmbiguity (yybest, yyp, yystack]b4_pure_args[);
-	    break;
-	  case 1:
-	    yymerge = yytrue;
-	    break;
-	  case 2:
-	    break;
-	  case 3:
-	    yybest = yyp;
-	    yymerge = yyfalse;
-	    break;
-	  }
+	{
+	  switch (yypreference (yybest, yyp))
+	    {
+	    case 0:
+	      yyreportAmbiguity (yybest, yyp, yystack]b4_pure_args[);
+	      break;
+	    case 1:
+	      yymerge = yytrue;
+	      break;
+	    case 2:
+	      break;
+	    case 3:
+	      yybest = yyp;
+	      yymerge = yyfalse;
+	      break;
+	    }
+	  yypp = &yyp->yynext;
+	}
     }
 
   if (yymerge)
     {
+      yySemanticOption* yyp;
       int yyprec = yydprec[yybest->yyrule];
       YYCHK (yyresolveAction (yybest, yystack, yyvalp, yylocp]b4_user_args[));
       for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
