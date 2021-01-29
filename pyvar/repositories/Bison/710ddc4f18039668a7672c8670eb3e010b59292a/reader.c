@@ -1688,6 +1688,13 @@ read_additionnal_code (void)
 
   obstack_init (&el_obstack);
 
+  if (!no_lines_flag)
+    {
+      obstack_fgrow2 (&el_obstack, muscle_find ("linef"),
+		      lineno, quotearg_style (c_quoting_style,
+					      muscle_find("filename")));
+    }
+
   while ((c = getc (finput)) != EOF)
     obstack_1grow (&el_obstack, c);
 
