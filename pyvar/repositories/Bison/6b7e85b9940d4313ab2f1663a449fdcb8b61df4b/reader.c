@@ -724,7 +724,6 @@ token_buffer);
 	}
 
       prev = t;
-
     }
 }
 
@@ -852,7 +851,7 @@ parse_thong_decl (void)
   token_t token;
   struct bucket *symbol;
   char *typename = 0;
-  int usrtoknum = 0;
+  int usrtoknum = SUNDEF;
 
   token = lex ();		/* fetch typename or first token */
   if (token == tok_typename)
@@ -1724,6 +1723,9 @@ token_translations_init (void)
       /* A token string alias? */
       if (bp->user_token_number == SALIAS)
 	continue;
+
+      assert (bp->user_token_number != SUNDEF);
+
       /* A token which translation has already been set? */
       if (token_translations[bp->user_token_number] != 2)
 	complain (_("tokens %s and %s both assigned number %d"),
@@ -1810,7 +1812,7 @@ packsymbols (void)
 
       if (bp->class == token_sym)
 	{
-	  if (bp->user_token_number == 0)
+	  if (bp->user_token_number == SUNDEF)
 	    bp->user_token_number = ++last_user_token_number;
 	  if (bp->user_token_number > max_user_token_number)
 	    max_user_token_number = bp->user_token_number;
