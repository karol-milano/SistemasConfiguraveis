@@ -1538,7 +1538,7 @@ token_translations_init (void)
   /* Initialize all entries for literal tokens to 2, the internal
      token number for $undefined., which represents all invalid
      inputs.  */
-  for (i = 0; i <= max_user_token_number; i++)
+  for (i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = 2;
 
   for (bp = firstsymbol; bp; bp = bp->next)
