@@ -87,9 +87,17 @@ flags_argmatch (const char *option,
       args = strtok (args, ",");
       while (args)
         {
+          int value = all;
+          int *save_flags = flags;
           int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-          int value = XARGMATCH (option, args + no, keys, values);
-          if (value == 0)
+          int err = STRPREFIX_LIT ("error", args + no) ? 5 : 0;
+
+          if (err)
+            flags = &errors_flag;
+          if (!err || args[no + err++] != '\0')
+            value = XARGMATCH (option, args + no + err, keys, values);
+
+          if (!value)
             {
               if (no)
                 *flags |= all;
@@ -101,8 +109,13 @@ flags_argmatch (const char *option,
               if (no)
                 *flags &= ~value;
               else
-                *flags |= value;
+                {
+                  if (err)
+                    warnings_flag |= value;
+                  *flags |= value;
+                }
             }
+          flags = save_flags;
           args = strtok (NULL, ",");
         }
     }
@@ -322,16 +335,16 @@ Output:\n\
 
       fputs (_("\
 Warning categories include:\n\
-  `midrule-values'  unset or unused midrule values\n\
-  `yacc'            incompatibilities with POSIX Yacc\n\
-  `conflicts-sr'    S/R conflicts (enabled by default)\n\
-  `conflicts-rr'    R/R conflicts (enabled by default)\n\
-  `deprecated'      obsolete constructs\n\
-  `other'           all other warnings (enabled by default)\n\
-  `all'             all the warnings\n\
-  `no-CATEGORY'     turn off warnings in CATEGORY\n\
-  `none'            turn off all the warnings\n\
-  `error'           treat warnings as errors\n\
+  `midrule-values'    unset or unused midrule values\n\
+  `yacc'              incompatibilities with POSIX Yacc\n\
+  `conflicts-sr'      S/R conflicts (enabled by default)\n\
+  `conflicts-rr'      R/R conflicts (enabled by default)\n\
+  `deprecated'        obsolete constructs\n\
+  `other'             all other warnings (enabled by default)\n\
+  `all'               all the warnings\n\
+  `no-CATEGORY'       turn off warnings in CATEGORY\n\
+  `none'              turn off all the warnings\n\
+  `error[=CATEGORY]'  treat warnings as errors\n\
 "), stdout);
       putc ('\n', stdout);
 
