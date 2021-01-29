@@ -27,9 +27,7 @@
 #include "xalloc.h"
 #include "complain.h"
 #include "gram.h"
-
-/* functions from main.c */
-extern char *printable_version PARAMS ((int));
+#include "quote.h"
 
 /* Buffer for storing the current token.  */
 char *token_buffer;
@@ -238,8 +236,10 @@ literalchar (char **pp, int *pcode, char term)
 	}
       else
 	{
+	  char buf [] = "c";
+	  buf[0] = c;
 	  complain (_("unknown escape sequence: `\\' followed by `%s'"),
-		    printable_version (c));
+		    quote (buf));
 	  code = '?';
 	}
     }				/* has \ */
