@@ -1678,15 +1678,37 @@ read_additionnal_code (void)
 static void
 token_translations_init (void)
 {
-  int last_user_token_number = 256;
+  int num_256_available_p = TRUE;
   int i;
 
-  /* Set the user numbers. */
+  /* Find the highest user token number, and whether 256, the POSIX
+     preferred user token number for the error token, is used.  */
+  max_user_token_number = 0;
+  for (i = 0; i < ntokens; ++i)
+    {
+      symbol_t *this = symbols[i];
+      if (this->user_token_number != SUNDEF)
+	{
+	  if (this->user_token_number > max_user_token_number)
+	    max_user_token_number = this->user_token_number;
+	  if (this->user_token_number == 256)
+	    num_256_available_p = FALSE;
+	}
+    }
+
+  /* If 256 is not used, assign it to error, to follow POSIX.  */
+  if (num_256_available_p && errtoken->user_token_number == SUNDEF)
+    errtoken->user_token_number = 256;
+
+  /* Set the missing user numbers. */
+  if (max_user_token_number < 256)
+    max_user_token_number = 256;
+
   for (i = 0; i < ntokens; ++i)
     {
       symbol_t *this = symbols[i];
       if (this->user_token_number == SUNDEF)
-	this->user_token_number = ++last_user_token_number;
+	this->user_token_number = ++max_user_token_number;
       if (this->user_token_number > max_user_token_number)
 	max_user_token_number = this->user_token_number;
     }
@@ -1698,7 +1720,6 @@ token_translations_init (void)
      inputs.  */
   for (i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = undeftoken->number;
-
   symbols_do (symbol_translation, NULL);
 }
 
@@ -1824,7 +1845,6 @@ reader (void)
   errtoken = getsym ("error");
   errtoken->class = token_sym;
   errtoken->number = ntokens++;
-  errtoken->user_token_number = 256;	/* Value specified by POSIX.  */
 
   /* Construct a token that represents all undefined literal tokens.
      It is always token number 2.  */
