@@ -847,8 +847,8 @@ symbols_new (void)
   accept->content->class = nterm_sym;
   accept->content->number = nvars++;
 
-  /* Construct the YYERRCODE/"error" token */
-  errtoken = symbol_get ("YYERRCODE", empty_loc);
+  /* Construct the YYerror/"error" token */
+  errtoken = symbol_get ("YYerror", empty_loc);
   errtoken->content->class = token_sym;
   errtoken->content->number = ntokens++;
   {
