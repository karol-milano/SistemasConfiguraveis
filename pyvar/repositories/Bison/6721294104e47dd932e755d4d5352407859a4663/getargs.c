@@ -671,3 +671,11 @@ getargs (int argc, char *argv[])
   current_file = grammar_file = uniqstr_new (argv[optind]);
   MUSCLE_INSERT_C_STRING ("file_name", grammar_file);
 }
+
+void
+tr (char *s, char from, char to)
+{
+  for (; *s; s++)
+    if (*s == from)
+      *s = to;
+}
