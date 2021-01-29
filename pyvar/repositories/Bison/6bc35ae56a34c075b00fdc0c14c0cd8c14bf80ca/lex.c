@@ -569,8 +569,8 @@ parse_percent_token (void)
   obstack_1grow (&token_obstack, '%');
   while (isalpha (c) || c == '_' || c == '-')
     {
-      if (c == '-')
-	c = '_';
+      if (c == '_')
+	c = '-';
       obstack_1grow (&token_obstack, c);
       c = getc (finput);
     }
