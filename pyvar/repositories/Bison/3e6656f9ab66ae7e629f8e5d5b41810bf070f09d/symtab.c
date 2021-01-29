@@ -200,13 +200,8 @@ symbol_user_token_number_set (symbol_t *symbol,
 static void
 symbol_free (symbol_t *this)
 {
-#if 0
-  /* This causes crashes because one string can appear more
-     than once.  */
-  XFREE (this->type_name);
-#endif
-  XFREE (this->tag);
-  XFREE (this);
+  free (this->tag);
+  free (this);
 }
 
 
