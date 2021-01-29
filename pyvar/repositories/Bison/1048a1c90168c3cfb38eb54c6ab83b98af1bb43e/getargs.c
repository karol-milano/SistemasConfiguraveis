@@ -87,7 +87,7 @@ flags_argmatch (const char *option,
       args = strtok (args, ",");
       while (args)
         {
-          int value = all;
+          int value = 0;
           int *save_flags = flags;
           int no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
           int err = STRPREFIX_LIT ("error", args + no) ? 5 : 0;
@@ -99,7 +99,12 @@ flags_argmatch (const char *option,
 
           if (!value)
             {
-              if (no)
+            /*  With a simpler 'if (no)' version, -Werror means -Werror=all
+                (or rather, -Werror=no-none, but that syntax is invalid).
+                The difference is:
+                  - Werror activates all errors, but not the warnings
+                  - Werror=all activates errors, and all warnings */
+              if (no ? !err : err)
                 *flags |= all;
               else
                 *flags &= ~all;
@@ -681,6 +686,8 @@ getargs (int argc, char *argv[])
         break;
 
       case 'y':
+        warnings_flag |= Wyacc;
+        errors_flag |= Wyacc;
         yacc_flag = true;
         break;
 
