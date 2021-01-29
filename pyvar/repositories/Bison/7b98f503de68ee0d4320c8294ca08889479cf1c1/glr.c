@@ -740,10 +740,9 @@ b4_syncline([@oline@], [@ofile@])
 }
 
 
-static YYSTYPE
+static void
 yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 {
-  YYSTYPE yyval = *yy0;
   /* `Use' the arguments.  */
   (void) yy0;
   (void) yy1;
@@ -752,7 +751,6 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
     {
       b4_mergers
     }
-  return yyval;
 }
 [
 			      /* Bison grammar-table manipulation.  */
@@ -1475,7 +1473,7 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 	      YYSTYPE yyval1;
 	      YYLTYPE yydummy;
 	      YYCHK (yyresolveAction (yyp, yystack, &yyval1, &yydummy]b4_user_args[));
-	      *yyvalp = yyuserMerge (yymerger[yyp->yyrule], yyvalp, &yyval1);
+	      yyuserMerge (yymerger[yyp->yyrule], yyvalp, &yyval1);
 	    }
 	}
       return yyok;
