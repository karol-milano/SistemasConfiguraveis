@@ -31,7 +31,7 @@
 
 /* Buffer for storing the current token.  */
 struct obstack token_obstack;
-char *token_buffer = NULL;
+const char *token_buffer = NULL;
 
 bucket *symval;
 int numval;
@@ -234,10 +234,10 @@ literalchar (struct obstack *out, int *pcode, char term)
 	}
       else
 	{
-	  char buf [] = "c";
-	  buf[0] = c;
+	  char badchar [] = "c";
+	  badchar[0] = c;
 	  complain (_("unknown escape sequence: `\\' followed by `%s'"),
-		    quote (buf));
+		    quote (badchar));
 	  code = '?';
 	}
     }				/* has \ */
