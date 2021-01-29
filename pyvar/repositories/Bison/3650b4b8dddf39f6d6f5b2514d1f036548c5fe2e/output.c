@@ -344,11 +344,11 @@ prepare_tokens (void)
   /* Output YYTOKNUM. */
   {
     int i;
-    int *values = XCALLOC (int, ntokens + 1);
-    for (i = 0; i < ntokens + 1; ++i)
+    int *values = XCALLOC (int, ntokens);
+    for (i = 0; i < ntokens; ++i)
       values[i] = symbols[i]->user_token_number;
     muscle_insert_int_table ("toknum", values,
-			     0, 1, ntokens + 1);
+			     values[0], 1, ntokens);
     free (values);
   }
 }
