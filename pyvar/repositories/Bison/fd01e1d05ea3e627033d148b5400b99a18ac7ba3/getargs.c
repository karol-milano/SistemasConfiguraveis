@@ -85,61 +85,42 @@ flags_argmatch (const char *option,
   if (args)
   {
     args = strtok (args, ",");
-
-     /* Not sure whether we should keep this : -Werror=no-bar */
-    int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-    args += no;
-    int value = 0;
- 
     while (args)
     {
-      int err = STRPREFIX_LIT ("error", args); 
+      int value = all;
+      int *save_flags = flags;
+      int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
+      int err = STRPREFIX_LIT ("error", args + no) ? 5 : 0; 
+
       if (err)
-        args += (args[5] == '=') ? 6 : 5;
+        flags = &errors_flag;
+      if (!err || args[no + err++] != '\0')
+        value = XARGMATCH (option, args + no + err, keys, values);
 
-      if (!err || args[-1] == '=')
-        value = XARGMATCH (option, args, keys, values);
-      if (value == 0)
-      {
-        if (no)
+        if (!value)
         {
-          if (err)
-            /* Using &= ~all activates complaint, silent and fatal */
-            errors_flag = Wnone;
-          else
+          if (no)
             *flags |= all;
-        }
-        else
-        {
-          if (err)
-            errors_flag |= all;
           else
-            *flags &= ~all;
-        }
-      }
-      else
-      {
-        if (no)
-        {
-          if (err)
-            errors_flag &= ~value;
-          else
-            *flags &= ~value;
+             *flags &= ~all;
         }
         else
         {
-          if (err)
+          if (no)
+            *flags &= ~value;
+          else
           {
-            errors_flag |= value;
-            warnings_flag |= value;
+            if (err)
+              warnings_flag |= value;
+           *flags |= value;
           }
-          else
-            *flags |= value;
         }
-      }
+      flags = save_flags;
       args = strtok (NULL, ",");
     }
   }
+  else
+    *flags |= all;
 }
 
 /** Decode a set of sub arguments.
