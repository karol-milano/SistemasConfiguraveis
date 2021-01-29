@@ -35,7 +35,7 @@ symbol_new (const char *tag)
 
   res->tag = xstrdup (tag);
   res->type_name = NULL;
-  res->number = -1;
+  res->number = NUMBER_UNDEFINED;
   res->prec = 0;
   res->assoc = right_assoc;
   res->user_token_number = SUNDEF;
