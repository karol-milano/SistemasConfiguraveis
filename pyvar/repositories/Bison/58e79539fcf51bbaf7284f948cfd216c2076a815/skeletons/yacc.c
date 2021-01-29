@@ -1770,6 +1770,17 @@ yyread_pushed_token:]])[
       yytoken = ]b4_symbol(0, [kind])[;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
+  else if (yychar == ]b4_symbol(1, [id])[)
+    {
+      /* The scanner already issued an error message, process directly
+         to error recovery.  But do not keep the error token as
+         lookahead, it is too special and may lead us to an endless
+         loop in error recovery. */
+      yychar = ]b4_symbol(2, [id])[;
+      yytoken = ]b4_symbol(1, [kind])[;]b4_locations_if([[
+      yyerror_range[1] = yylloc;]])[
+      goto yyerrlab1;
+    }
   else
     {
       yytoken = YYTRANSLATE (yychar);
