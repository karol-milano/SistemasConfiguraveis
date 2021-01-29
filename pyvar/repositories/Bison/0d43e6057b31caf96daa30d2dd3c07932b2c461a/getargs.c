@@ -83,63 +83,31 @@ flags_argmatch (const char *option,
                 int all, int *flags, char *args)
 {
   if (args)
-  {
-    args = strtok (args, ",");
-
-     /* Not sure whether we should keep this : -Werror=no-bar */
-    int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-    args += no;
-    int value = 0;
- 
-    while (args)
     {
-      int err = STRPREFIX_LIT ("error", args); 
-      if (err)
-        args += (args[5] == '=') ? 6 : 5;
-
-      if (!err || args[-1] == '=')
-        value = XARGMATCH (option, args, keys, values);
-      if (value == 0)
-      {
-        if (no)
-        {
-          if (err)
-            /* Using &= ~all activates complaint, silent and fatal */
-            errors_flag = Wnone;
-          else
-            *flags |= all;
-        }
-        else
-        {
-          if (err)
-            errors_flag |= all;
-          else
-            *flags &= ~all;
-        }
-      }
-      else
-      {
-        if (no)
+      args = strtok (args, ",");
+      while (args)
         {
-          if (err)
-            errors_flag &= ~value;
+          int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
+          int value = XARGMATCH (option, args + no, keys, values);
+          if (value == 0)
+            {
+              if (no)
+                *flags |= all;
+              else
+                *flags &= ~all;
+            }
           else
-            *flags &= ~value;
+            {
+              if (no)
+                *flags &= ~value;
+              else
+                *flags |= value;
+            }
+          args = strtok (NULL, ",");
         }
-        else
-        {
-          if (err)
-          {
-            errors_flag |= value;
-            warnings_flag |= value;
-          }
-          else
-            *flags |= value;
-        }
-      }
-      args = strtok (NULL, ",");
     }
-  }
+  else
+    *flags |= all;
 }
 
 /** Decode a set of sub arguments.
