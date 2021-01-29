@@ -773,28 +773,13 @@ parse_union_decl (void)
 static void
 parse_expect_decl (void)
 {
-  int c;
-  size_t count;
-  char buffer[20];
-
-  c = getc (finput);
-  while (c == ' ' || c == '\t')
-    c = getc (finput);
-
-  count = 0;
-  while (c >= '0' && c <= '9')
-    {
-      if (count < sizeof(buffer) - 1)
-	buffer[count++] = c;
-      c = getc (finput);
-    }
-  buffer[count] = 0;
-
+  int c = skip_white_space ();
   ungetc (c, finput);
 
-  if (count <= 0 || count > 10)
+  if (!isdigit (c))
     complain (_("argument of %%expect is not an integer"));
-  expected_conflicts = atoi (buffer);
+  else
+    expected_conflicts = read_signed_integer (finput);
 }
 
 
