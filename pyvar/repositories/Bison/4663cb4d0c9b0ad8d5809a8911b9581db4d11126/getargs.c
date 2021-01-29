@@ -102,7 +102,7 @@ flags_argmatch (const char *option,
       args = strtok (args, ",");
       while (args)
         {
-          int no = strncmp (args, "no-", 3) == 0 ? 3 : 0;
+          int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
           int value = XARGMATCH (option, args + no, keys, values);
           if (value == 0)
             {
