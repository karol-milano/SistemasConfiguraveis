@@ -1157,7 +1157,7 @@ yyerrlab:
 	      }
 
 	  yyf = _(yyformat);
-	  yysize1 = yysize + strlen (yyf);
+	  yysize1 = yysize + yystrlen (yyf);
 	  yysize_overflow |= yysize1 < yysize;
 	  yysize = yysize1;
 