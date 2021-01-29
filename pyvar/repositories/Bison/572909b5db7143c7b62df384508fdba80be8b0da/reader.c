@@ -161,7 +161,7 @@ reader()
   errtoken->user_token_number = 256; /* Value specified by posix.  */
   /* construct a token that represents all undefined literal tokens. */
   /* it is always token number 2.  */
-  getsym("$illegal.")->class = STOKEN;
+  getsym("$undefined.")->class = STOKEN;
   /* Read the declaration section.  Copy %{ ... %} groups to ftable and fdefines file.
      Also notice any %token, %left, etc. found there.  */
   fprintf(ftable, "\n/*  A Bison parser, made from %s", infile);
@@ -1649,7 +1649,8 @@ packsymbols()
       token_translations = NEW2(max_user_token_number+1, short);
 
       /* initialize all entries for literal tokens to 2,
-	 the internal token number for $illegal., which represents all invalid inputs.  */
+	 the internal token number for $undefined.,
+	 which represents all invalid inputs.  */
       for (i = 0; i <= max_user_token_number; i++)
         token_translations[i] = 2;      
     }
