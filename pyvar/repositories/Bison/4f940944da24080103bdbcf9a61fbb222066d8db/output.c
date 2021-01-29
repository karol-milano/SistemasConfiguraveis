@@ -132,20 +132,6 @@ static struct obstack format_obstack;
 
 int error_verbose = 0;
 
-/* Returns the number of lines of S.  */
-size_t
-get_lines_number (const char *s)
-{
-  size_t lines = 0;
-
-  size_t i;
-  for (i = 0; s[i]; ++i)
-    if (s[i] == '\n')
-      ++lines;
-
-  return lines;
-}
-
 
 /*----------------------------------------------------------------.
 | Format the FIRST and then TABLE_DATA[BEGIN..END[ into OOUT, and |
