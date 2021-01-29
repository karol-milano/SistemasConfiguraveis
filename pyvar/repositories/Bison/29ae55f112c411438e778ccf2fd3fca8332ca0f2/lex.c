@@ -482,43 +482,54 @@ parse_percent_token (void)
   size_t arg_offset = 0;
 
   int c = getc (finput);
+  obstack_1grow (&token_obstack, '%');
+  obstack_1grow (&token_obstack, c);
 
   switch (c)
     {
     case '%':
+      token_buffer = obstack_finish (&token_obstack);
       return tok_two_percents;
 
     case '{':
+      token_buffer = obstack_finish (&token_obstack);
       return tok_percent_left_curly;
 
-      /* FIXME: Who the heck are those 5 guys!?! `%<' = `%left'!!!
-	 Let's ask for there removal.  */
+      /* The following guys are here for backward compatibility with
+	 very ancient Yacc versions.  The paper of Johnson mentions
+	 them (as ancient :).  */
     case '<':
+      token_buffer = obstack_finish (&token_obstack);
       return tok_left;
 
     case '>':
+      token_buffer = obstack_finish (&token_obstack);
       return tok_right;
 
     case '2':
+      token_buffer = obstack_finish (&token_obstack);
       return tok_nonassoc;
 
     case '0':
+      token_buffer = obstack_finish (&token_obstack);
       return tok_token;
 
     case '=':
+      token_buffer = obstack_finish (&token_obstack);
       return tok_prec;
     }
 
   if (!isalpha (c))
-    return tok_illegal;
+    {
+      token_buffer = obstack_finish (&token_obstack);
+      return tok_illegal;
+    }
 
-  obstack_1grow (&token_obstack, '%');
-  while (isalpha (c) || c == '_' || c == '-')
+  while (c = getc (finput), isalpha (c) || c == '_' || c == '-')
     {
       if (c == '_')
 	c = '-';
       obstack_1grow (&token_obstack, c);
-      c = getc (finput);
     }
 
   /* %DIRECTIVE="ARG".  Separate into
