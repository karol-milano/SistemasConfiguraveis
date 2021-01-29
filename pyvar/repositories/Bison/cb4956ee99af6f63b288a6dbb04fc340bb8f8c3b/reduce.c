@@ -352,10 +352,6 @@ reduce_grammar_tables (void)
 	      sprec[n] = sprec[i];
 	      tags[n] = tags[i];
 	    }
-	  else
-	    {
-	      free (tags[i]);
-	    }
 	}
 
       /* Replace all symbol numbers in valid data structures.  */
