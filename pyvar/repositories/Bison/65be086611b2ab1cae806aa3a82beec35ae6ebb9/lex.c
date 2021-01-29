@@ -632,8 +632,8 @@ parse_percent_token (void)
 	&& option_strcmp (token_buffer + 1, tx->name) == 0)
       break;
 
-  if (arg && !tx->ret_val == tok_stropt)
-    fatal (_("`%s' supports no argument: %s"), token_buffer, quotearg (arg));
+  if (arg && tx->ret_val != tok_stropt)
+    fatal (_("`%s' supports no argument: %s"), token_buffer, quote (arg));
 
 
   switch (tx->ret_val)
