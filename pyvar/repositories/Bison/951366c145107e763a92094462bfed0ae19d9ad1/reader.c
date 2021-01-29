@@ -962,16 +962,13 @@ parse_skel_decl (void)
 static void
 read_declarations (void)
 {
-  int c;
-  int tok;
-
   for (;;)
     {
-      c = skip_white_space ();
+      int c = skip_white_space ();
 
       if (c == '%')
 	{
-	  tok = parse_percent_token ();
+	  token_t tok = parse_percent_token ();
 
 	  switch (tok)
 	    {
@@ -1033,6 +1030,13 @@ read_declarations (void)
 	    case tok_noop:
 	      break;
 
+	    case tok_stropt:
+	    case tok_intopt:
+	    case tok_obsolete:
+	    case tok_illegal:
+	      abort ();
+	      break;
+
 	    default:
 	      complain (_("unrecognized: %s"), token_buffer);
 	      skip_to_char ('%');
