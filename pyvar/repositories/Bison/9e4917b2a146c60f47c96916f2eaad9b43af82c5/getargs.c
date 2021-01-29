@@ -84,23 +84,19 @@ flag_argmatch (const char *option,
                const char * const keys[], const int values[],
                int all, int *flags, char *arg, size_t no)
 {
-  int value = 0;
-  value = XARGMATCH (option, arg + no, keys, values);
+  int value = XARGMATCH (option, arg + no, keys, values);
 
-  if (value)
+  /* -rnone == -rno-all, and -rno-none == -rall.  */
+  if (!value)
     {
-      if (no)
-        *flags &= ~value;
-      else
-        *flags |= value;
+      value = all;
+      no = !no;
     }
+
+  if (no)
+    *flags &= ~value;
   else
-    {
-      if (no)
-        *flags |= all;
-      else
-        *flags &= ~all;
-    }
+    *flags |= value;
 }
 
 /** Decode an option's set of keys.
