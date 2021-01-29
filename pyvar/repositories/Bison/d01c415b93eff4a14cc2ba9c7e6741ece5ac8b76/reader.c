@@ -1515,7 +1515,7 @@ readgram (void)
 
       else
 	{
-	  complain (_("invalid input: %s"), token_buffer);
+	  complain (_("invalid input: %s"), quote (token_buffer));
 	  t = lex ();
 	}
     }
