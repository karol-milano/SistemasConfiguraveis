@@ -30,15 +30,15 @@
 
 /* Buffer for storing the current token.  */
 static struct obstack token_obstack;
-char *token_buffer = NULL;
+const char *token_buffer = NULL;
 
-bucket *symval;
+bucket *symval = NULL;
 int numval;
 
 /* A token to be reread, see unlex and lex. */
 static token_t unlexed = tok_undef;
 static bucket *unlexed_symval = NULL;
-static char *unlexed_token_buffer = NULL;
+static const char *unlexed_token_buffer = NULL;
 
 void
 lex_init (void)
@@ -554,9 +554,9 @@ token_t
 parse_percent_token (void)
 {
   const struct option_table_struct *tx = NULL;
-  /* Where `=' was found in token_buffer. */
-  size_t equal_offset = 0;
-  char *arg = NULL;
+  const char *arg = NULL;
+  /* Where the ARG was found in token_buffer. */
+  size_t arg_offset = 0;
 
   int c = getc (finput);
 
@@ -598,33 +598,34 @@ parse_percent_token (void)
       c = getc (finput);
     }
 
+  /* %DIRECTIVE="ARG".  Separate into
+     TOKEN_BUFFER = `%DIRECTIVE\0ARG\0'.
+     This is a bit hackish, but once we move to a Bison parser,
+     things will be cleaned up.  */
   if (c == '=')
     {
-      equal_offset = obstack_object_size (&token_obstack);
-      obstack_1grow (&token_obstack, c);
+      /* End of the directive.  We skip the `='. */
+      obstack_1grow (&token_obstack, '\0');
+      /* Fetch the ARG if present. */
       c = getc (finput);
-      if (c = '"')
+      if (c == '"')
 	{
-	  int code;             /* ignored here */
-
-	  obstack_1grow (&token_obstack, '"');
-	  /* Read up to and including ".  */
-	  while (literalchar (&token_obstack, &code, '"'))
-	    /* nothing */;
+	  int code;
+	  arg_offset = obstack_object_size (&token_obstack);
+	  /* Read up to and including `"'.  Do not append the closing
+	     `"' in the output: it's not part of the ARG.  */
+	  while (literalchar (NULL, &code, '"'))
+	    obstack_1grow (&token_obstack, code);
 	}
+      /* else: should be an error. */
     }
   else
     ungetc (c, finput);
 
   obstack_1grow (&token_obstack, '\0');
   token_buffer = obstack_finish (&token_obstack);
-  if (equal_offset)
-    {
-      /* %token_buffer="arg" */
-      arg = token_buffer + equal_offset + 2;
-      arg[strlen (arg) - 1] = '\0';
-      token_buffer[equal_offset] = '\0';
-    }
+  if (arg_offset)
+    arg = token_buffer + arg_offset;
 
   /* table lookup % directive */
   for (tx = option_table; tx->name; tx++)
@@ -647,7 +648,7 @@ parse_percent_token (void)
 	     precedence.  Side effect: if this %-option is used
 	     several times, only the first is honored.  Bah.  */
 	  if (!*((char **) (tx->set_flag)))
-	    *((char **) (tx->set_flag)) = arg;
+	    *((char **) (tx->set_flag)) = xstrdup (arg);
 	}
       else
 	fatal (_("`%s' requires an argument"), token_buffer);
