@@ -77,10 +77,12 @@ sym_content_new (symbol *s)
   res->symbol = s;
 
   res->type_name = NULL;
+  res->type_loc = empty_loc;
   for (int i = 0; i < CODE_PROPS_SIZE; ++i)
     code_props_none_init (&res->props[i]);
 
   res->number = NUMBER_UNDEFINED;
+  res->prec_loc = empty_loc;
   res->prec = 0;
   res->assoc = undef_assoc;
   res->user_token_number = USER_NUMBER_UNDEFINED;
