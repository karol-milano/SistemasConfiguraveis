@@ -323,6 +323,37 @@ unlex (int token)
   unlexed_symval = symval;
 }
 
+/*-----------------------------------------------------------------.
+| We just read `<' from FIN.  Store in TOKEN_BUFFER, the type name |
+| specified between the `<...>'.                                   |
+`-----------------------------------------------------------------*/
+
+void
+read_type_name (FILE *fin)
+{
+  char *p = token_buffer;
+  int c = getc (fin);
+
+  while (c != '>')
+    {
+      if (c == EOF)
+	fatal (_("unterminated type name at end of file"));
+      if (c == '\n')
+	{
+	  complain (_("unterminated type name"));
+	  ungetc (c, fin);
+	  break;
+	}
+
+      if (p == token_buffer + maxtoken)
+	p = grow_token_buffer (p);
+
+      *p++ = c;
+      c = getc (fin);
+    }
+  *p = 0;
+}
+
 
 int
 lex (void)
@@ -488,29 +519,9 @@ lex (void)
 	}
 
     case '<':
-      p = token_buffer;
-      c = getc (finput);
-      while (c != '>')
-	{
-	  if (c == EOF)
-	    fatal (_("unterminated type name at end of file"));
-	  if (c == '\n')
-	    {
-	      complain (_("unterminated type name"));
-	      ungetc (c, finput);
-	      break;
-	    }
-
-	  if (p == token_buffer + maxtoken)
-	    p = grow_token_buffer (p);
-
-	  *p++ = c;
-	  c = getc (finput);
-	}
-      *p = 0;
+      read_type_name (finput);
       return TYPENAME;
 
-
     case '%':
       return parse_percent_token ();
 
