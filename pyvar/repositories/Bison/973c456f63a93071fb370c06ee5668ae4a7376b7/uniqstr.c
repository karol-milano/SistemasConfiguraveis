@@ -56,19 +56,36 @@ uniqstr_new (char const *str)
 }
 
 uniqstr
-uniqstr_vsprintf (char const *format, ...)
+uniqstr_concat (int nargs, ...)
 {
   va_list args;
-  size_t length;
-  va_start (args, format);
-  length = vsnprintf (NULL, 0, format, args);
+
+  va_start (args, nargs);
+  size_t reslen = 0;
+  for (int i = 0; i < nargs; i++)
+    reslen += strlen (va_arg (args, char const *));
   va_end (args);
 
-  char res[length + 1];
-  va_start (args, format);
-  vsprintf (res, format, args);
+  char *str = xmalloc (reslen + 1);
+  char *p = str;
+
+  va_start (args, nargs);
+  for (int i = 0; i < nargs; i++)
+    {
+      char const *arg = va_arg (args, char const *);
+      size_t arglen = strlen (arg);
+      memcpy (p, arg, arglen);
+      p += arglen;
+    }
   va_end (args);
-  return uniqstr_new (res);
+
+  *p = '\0';
+  uniqstr res = hash_insert (uniqstrs_table, str);
+  if (!res)
+    xalloc_die ();
+  if (res != str)
+    free (str);
+  return res;
 }
 
 /*------------------------------.
