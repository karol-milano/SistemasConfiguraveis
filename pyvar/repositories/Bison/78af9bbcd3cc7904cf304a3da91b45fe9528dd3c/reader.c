@@ -1914,15 +1914,8 @@ symbols_output (void)
       output_token_defines (&defines_obstack);
 
       if (!pure_parser)
-	{
-	  if (spec_name_prefix)
-	    obstack_fgrow1 (&defines_obstack, "\nextern YYSTYPE %slval;\n",
-			    spec_name_prefix);
-	  else
-	    obstack_sgrow (&defines_obstack,
-				 "\nextern YYSTYPE yylval;\n");
-	}
-
+	obstack_fgrow1 (&defines_obstack, "\nextern YYSTYPE %slval;\n",
+			spec_name_prefix);
       if (semantic_parser)
 	{
 	  int i;
