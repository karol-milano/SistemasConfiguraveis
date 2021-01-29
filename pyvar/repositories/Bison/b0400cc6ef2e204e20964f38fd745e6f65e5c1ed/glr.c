@@ -267,8 +267,9 @@ b4_syncline([@oline@], [@ofile@])
 #define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
-#define YYTRANSLATE(YYX) \
-  ((unsigned)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+#define YYTRANSLATE(YYX) 						\
+  ((YYX <= 0) ? YYEOF :							\
+   (unsigned)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
@@ -1505,7 +1506,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	    {
 	      YYDPRINTF ((stderr, "Reading a token: "));
 	      yychar = YYLEX;
-	      *yytokenp = YYTRANSLATE(yychar);
+	      *yytokenp = YYTRANSLATE (yychar);
 	      YYDPRINTF ((stderr, "Next token is %s\n",
 			  yytokenName (*yytokenp)));
 	    }
@@ -1578,8 +1579,7 @@ yyreportParseError (yyGLRStack* yystack,
 	      yysize += strlen (yytokenName (yyx)) + strlen (yyprefix),
 		yycount += 1, yyprefix = " or ";
 	  yymsg = yyp = (char*) malloc (yysize);
-	  sprintf (yyp, "parse error, unexpected %s",
-		   yytokenName (*yytokenp));
+	  sprintf (yyp, "parse error, unexpected %s", yytokenName (*yytokenp));
 	  yyp += strlen (yyp);
 	  if (yycount < 5)
 	    {
