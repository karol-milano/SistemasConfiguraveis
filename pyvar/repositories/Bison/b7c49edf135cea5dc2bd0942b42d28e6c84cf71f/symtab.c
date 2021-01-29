@@ -55,7 +55,7 @@ bucket_new (const char *tag, int hashval)
   res->next = NULL;
   res->tag = xstrdup (tag);
   res->type_name = NULL;
-  res->value = 0;
+  res->value = -1;
   res->prec = 0;
   res->assoc = right_assoc;
   res->user_token_number = SUNDEF;
