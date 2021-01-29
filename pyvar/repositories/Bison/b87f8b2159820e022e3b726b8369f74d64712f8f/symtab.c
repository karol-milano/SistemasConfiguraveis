@@ -38,7 +38,7 @@ symbol_new (const char *tag)
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
   res->assoc = right_assoc;
-  res->user_token_number = SUNDEF;
+  res->user_token_number = USER_NUMBER_UNDEFINED;
   res->alias = NULL;
   res->class = unknown_sym;
 
