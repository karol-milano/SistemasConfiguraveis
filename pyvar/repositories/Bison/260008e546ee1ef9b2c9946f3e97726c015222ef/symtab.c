@@ -51,11 +51,13 @@ symbol_new (const char *tag, location_t location)
 
   res->type_name = NULL;
   res->destructor = NULL;
+  res->printer = NULL;
 
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
   res->assoc = right_assoc;
   res->user_token_number = USER_NUMBER_UNDEFINED;
+
   res->alias = NULL;
   res->class = unknown_sym;
 
