@@ -704,7 +704,7 @@ parse_expect_decl (void)
   count = 0;
   while (c >= '0' && c <= '9')
     {
-      if (count < 20)
+      if (count < sizeof(buffer) - 1)
 	buffer[count++] = c;
       c = getc (finput);
     }
