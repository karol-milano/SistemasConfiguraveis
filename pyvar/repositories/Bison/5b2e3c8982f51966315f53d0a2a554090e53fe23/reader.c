@@ -122,6 +122,7 @@ static int lastprec;  /* incremented for each %left, %right or %nonassoc seen */
 static int gensym_count;  /* incremented for each generated symbol */
 
 static bucket *errtoken;
+static bucket *undeftoken;
 
 /* Nonzero if any action or guard uses the @n construct.  */
 static int yylsp_needed;
@@ -190,7 +191,9 @@ reader()
   errtoken->user_token_number = 256; /* Value specified by posix.  */
   /* construct a token that represents all undefined literal tokens. */
   /* it is always token number 2.  */
-  getsym("$undefined.")->class = STOKEN;
+  undeftoken = getsym("$undefined.");
+  undeftoken->class = STOKEN;
+  undeftoken->user_token_number = 2;
   /* Read the declaration section.  Copy %{ ... %} groups to ftable and fdefines file.
      Also notice any %token, %left, etc. found there.  */
   if (noparserflag)
