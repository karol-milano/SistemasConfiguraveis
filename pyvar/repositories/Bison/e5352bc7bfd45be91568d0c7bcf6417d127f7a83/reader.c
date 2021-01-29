@@ -1326,7 +1326,10 @@ readgram (void)
 		unlex (t1);
 		symval = ssave;
 		if (t1 == tok_colon)
-		  break;
+		  {
+		    complain (_("previous rule lacks an ending `;'"));
+		    break;
+		  }
 
 		if (!first_rhs)	/* JF */
 		  first_rhs = symval;
