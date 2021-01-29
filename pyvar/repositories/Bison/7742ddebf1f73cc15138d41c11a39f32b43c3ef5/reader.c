@@ -1738,12 +1738,12 @@ symbols_save (void)
       if (c != '\0')
 	continue;
 
-      obstack_fgrow2 (&tokendefs, "# define\t%s\t%d\n",
+      obstack_fgrow2 (&tokendefs, "# define %s\t%d\n",
 		      symbol, bp->user_token_number);
       if (semantic_parser)
 	/* FIXME: This is probably wrong, and should be just as
 	   above. --akim.  */
-	obstack_fgrow2 (&tokendefs, "# define\tT%s\t%d\n", symbol, bp->value);
+	obstack_fgrow2 (&tokendefs, "# define T%s\t%d\n", symbol, bp->value);
     }
 
   obstack_1grow (&tokendefs, 0);
