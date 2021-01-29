@@ -85,42 +85,61 @@ flags_argmatch (const char *option,
   if (args)
   {
     args = strtok (args, ",");
+
+     /* Not sure whether we should keep this : -Werror=no-bar */
+    int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
+    args += no;
+    int value = 0;
+ 
     while (args)
     {
-      int value = all;
-      int *save_flags = flags;
-      int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-      int err = STRPREFIX_LIT ("error", args + no) ? 5 : 0; 
-
+      int err = STRPREFIX_LIT ("error", args); 
       if (err)
-        flags = &errors_flag;
-      if (!err || args[no + err++] != '\0')
-        value = XARGMATCH (option, args + no + err, keys, values);
+        args += (args[5] == '=') ? 6 : 5;
 
-        if (!value)
+      if (!err || args[-1] == '=')
+        value = XARGMATCH (option, args, keys, values);
+      if (value == 0)
+      {
+        if (no)
         {
-          if (no)
-            *flags |= all;
+          if (err)
+            /* Using &= ~all activates complaint, silent and fatal */
+            errors_flag = Wnone;
           else
-             *flags &= ~all;
+            *flags |= all;
         }
         else
         {
-          if (no)
-            *flags &= ~value;
+          if (err)
+            errors_flag |= all;
           else
+            *flags &= ~all;
+        }
+      }
+      else
+      {
+        if (no)
+        {
+          if (err)
+            errors_flag &= ~value;
+          else
+            *flags &= ~value;
+        }
+        else
+        {
+          if (err)
           {
-            if (err)
-              warnings_flag |= value;
-           *flags |= value;
+            errors_flag |= value;
+            warnings_flag |= value;
           }
+          else
+            *flags |= value;
         }
-      flags = save_flags;
+      }
       args = strtok (NULL, ",");
     }
   }
-  else
-    *flags |= all;
 }
 
 /** Decode a set of sub arguments.
