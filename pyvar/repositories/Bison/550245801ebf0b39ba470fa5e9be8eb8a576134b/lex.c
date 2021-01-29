@@ -485,44 +485,40 @@ parse_percent_token (void)
   obstack_1grow (&token_obstack, '%');
   obstack_1grow (&token_obstack, c);
 
-  switch (c)
+  if (!isalpha (c))
     {
-    case '%':
+      obstack_1grow (&token_obstack, '\0');
       token_buffer = obstack_finish (&token_obstack);
-      return tok_two_percents;
 
-    case '{':
-      token_buffer = obstack_finish (&token_obstack);
-      return tok_percent_left_curly;
+      switch (c)
+	{
+	case '%':
+	  return tok_two_percents;
 
-      /* The following guys are here for backward compatibility with
-	 very ancient Yacc versions.  The paper of Johnson mentions
-	 them (as ancient :).  */
-    case '<':
-      token_buffer = obstack_finish (&token_obstack);
-      return tok_left;
+	case '{':
+	  return tok_percent_left_curly;
 
-    case '>':
-      token_buffer = obstack_finish (&token_obstack);
-      return tok_right;
+	  /* The following guys are here for backward compatibility with
+	     very ancient Yacc versions.  The paper of Johnson mentions
+	     them (as ancient :).  */
+	case '<':
+	  return tok_left;
 
-    case '2':
-      token_buffer = obstack_finish (&token_obstack);
-      return tok_nonassoc;
+	case '>':
+	  return tok_right;
 
-    case '0':
-      token_buffer = obstack_finish (&token_obstack);
-      return tok_token;
+	case '2':
+	  return tok_nonassoc;
 
-    case '=':
-      token_buffer = obstack_finish (&token_obstack);
-      return tok_prec;
-    }
+	case '0':
+	  return tok_token;
 
-  if (!isalpha (c))
-    {
-      token_buffer = obstack_finish (&token_obstack);
-      return tok_illegal;
+	case '=':
+	  return tok_prec;
+
+	default:
+	  return tok_illegal;
+	}
     }
 
   while (c = getc (finput), isalpha (c) || c == '_' || c == '-')
