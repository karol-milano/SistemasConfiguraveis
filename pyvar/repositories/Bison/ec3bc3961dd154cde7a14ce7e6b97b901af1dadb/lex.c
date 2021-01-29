@@ -484,7 +484,7 @@ option_strcmp (const char *left, const char *right)
 token_t
 parse_percent_token (void)
 {
-  const struct option_table_struct *tx = NULL;
+  const struct option_table_s *tx = NULL;
   const char *arg = NULL;
   /* Where the ARG was found in token_buffer. */
   size_t arg_offset = 0;
@@ -578,15 +578,16 @@ parse_percent_token (void)
   switch (tx->ret_val)
     {
     case tok_stropt:
-      assert (tx->set_flag);
+      assert (tx->flag);
       if (arg)
 	{
+	  char **flag = (char **) tx->flag;
 	  /* Keep only the first assignment: command line options have
 	     already been processed, and we want them to have
 	     precedence.  Side effect: if this %-option is used
 	     several times, only the first is honored.  Bah.  */
-	  if (!*((char **) (tx->set_flag)))
-	    *((char **) (tx->set_flag)) = xstrdup (arg);
+	  if (!*flag)
+	    *flag = xstrdup (arg);
 	}
       else
 	fatal (_("`%s' requires an argument"), token_buffer);
@@ -594,8 +595,8 @@ parse_percent_token (void)
       break;
 
     case tok_intopt:
-      assert (tx->set_flag);
-      *((int *) (tx->set_flag)) = 1;
+      assert (tx->flag);
+      *((int *) (tx->flag)) = 1;
       return tok_noop;
       break;
 
