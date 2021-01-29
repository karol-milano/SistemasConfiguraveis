@@ -133,10 +133,8 @@ get_lines_number (const char *s)
 
   size_t i;
   for (i = 0; s[i]; ++i)
-    {
-      if (s[i] == '\n')
-	++lines;
-    }
+    if (s[i] == '\n')
+      ++lines;
 
   return lines;
 }
