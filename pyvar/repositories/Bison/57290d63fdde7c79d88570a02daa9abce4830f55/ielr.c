@@ -50,7 +50,7 @@ lr_type_get (void)
 {
   char *type = muscle_percent_define_get ("lr.type");
   LrType res;
-  if (STREQ (type, "lr(0)"))
+  if (STREQ (type, "lr""(0)"))
     res = LR_TYPE__LR0;
   else if (STREQ (type, "lalr"))
     res = LR_TYPE__LALR;
