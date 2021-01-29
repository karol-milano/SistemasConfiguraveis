@@ -62,68 +62,82 @@ int language_prio = default_prio;
 struct bison_language const *language = &valid_languages[0];
 const char *include = NULL;
 
-
-/** Decode an option's set of keys.
+/** Decode an option's key.
  *
  *  \param option   option being decoded.
  *  \param keys     array of valid subarguments.
  *  \param values   array of corresponding (int) values.
  *  \param all      the all value.
  *  \param flags    the flags to update
- *  \param args     comma separated list of effective subarguments to decode.
- *                  If 0, then activate all the flags.
+ *  \param arg      the subarguments to decode.
+ *                  If null, then activate all the flags.
+ *  \param no       length of the potential "no-" prefix.
+ *                  Can be 0 or 3. If 3, negate the action of the subargument.
+ *  \param err      length of a potential "error=".
+ *                  Can be 0 or 6. If 6, treat the subargument as a CATEGORY
  *
  *  If VALUE != 0 then KEY sets flags and no-KEY clears them.
  *  If VALUE == 0 then KEY clears all flags from \c all and no-KEY sets all
  *  flags from \c all.  Thus no-none = all and no-all = none.
  */
 static void
-flags_argmatch (const char *option,
-                const char * const keys[], const int values[],
-                int all, int *flags, char *args)
+flag_argmatch (const char *option,
+               const char * const keys[], const int values[],
+               int all, int *flags, char *arg, size_t no, size_t err)
 {
-  if (args)
+  int value = 0;
+  if (!err || arg[no + err++] != '\0')
+    value = XARGMATCH (option, arg + no + err, keys, values);
+
+  if (value)
     {
-      args = strtok (args, ",");
-      while (args)
+      if (no)
+        *flags &= ~value;
+      else
         {
-          int value = 0;
-          int *save_flags = flags;
-          int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-          int err = STRPREFIX_LIT ("error", args + no) ? 5 : 0;
-
           if (err)
-            flags = &errors_flag;
-          if (!err || args[no + err++] != '\0')
-            value = XARGMATCH (option, args + no + err, keys, values);
-
-          if (!value)
-            {
-            /*  With a simpler 'if (no)' version, -Werror means -Werror=all
-                (or rather, -Werror=no-none, but that syntax is invalid).
-                The difference is:
-                  - Werror activates all errors, but not the warnings
-                  - Werror=all activates errors, and all warnings */
-              if (no ? !err : err)
-                *flags |= all;
-              else
-                *flags &= ~all;
-            }
-          else
-            {
-              if (no)
-                *flags &= ~value;
-              else
-                {
-                  if (err)
-                    warnings_flag |= value;
-                  *flags |= value;
-                }
-            }
-          flags = save_flags;
-          args = strtok (NULL, ",");
+            warnings_flag |= value;
+          *flags |= value;
         }
     }
+  else
+    {
+      /* With a simpler 'if (no)' version, -Werror means -Werror=all
+         (or rather, -Werror=no-none, but that syntax is invalid).
+         The difference is:
+         - Werror activates all errors, but not the warnings
+         - Werror=all activates errors, and all warnings */
+      if (no ? !err : err)
+        *flags |= all;
+      else
+        *flags &= ~all;
+    }
+}
+/** Decode an option's set of keys.
+ *
+ *  \param option   option being decoded.
+ *  \param keys     array of valid subarguments.
+ *  \param values   array of corresponding (int) values.
+ *  \param all      the all value.
+ *  \param flags    the flags to update
+ *  \param args     comma separated list of effective subarguments to decode.
+ *                  If 0, then activate all the flags.
+ */
+static void
+flags_argmatch (const char *option,
+                const char * const keys[], const int values[],
+                int all, int *flags, char *args)
+{
+  if (args)
+    for (args = strtok (args, ","); args; args = strtok (NULL, ","))
+      {
+        size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
+        size_t err = STRPREFIX_LIT ("error", args + no) ? 5 : 0;
+
+        flag_argmatch (option, keys,
+                       values, all, err ? &errors_flag : flags,
+                       args, no, err);
+      }
   else
     *flags |= all;
 }
