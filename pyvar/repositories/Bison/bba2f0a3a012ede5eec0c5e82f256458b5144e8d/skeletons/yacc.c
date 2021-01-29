@@ -1702,7 +1702,7 @@ yybackup:
       yylval = yypushed_val;]b4_locations_if([[
       yylloc = yypushed_loc;]])])[
 yyread_pushed_token:]])[
-      YYDPRINTF ((stderr, "Reading a token: "));]b4_push_if([b4_pure_if([[
+      YYDPRINTF ((stderr, "Reading a token\n"));]b4_push_if([b4_pure_if([[
       yychar = yypushed_char;
       if (yypushed_val)
         yylval = *yypushed_val;]b4_locations_if([[
