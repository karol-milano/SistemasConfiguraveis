@@ -68,6 +68,7 @@ static const char * const warnings_args[] =
   "other",
   "all",
   "error",
+  "everything",
   0
 };
 
@@ -83,7 +84,8 @@ static const int warnings_types[] =
   Wprecedence,
   Wother,
   Wall,
-  Werror
+  Werror,
+  Weverything
 };
 
 ARGMATCH_VERIFY (warnings_args, warnings_types);
@@ -94,10 +96,10 @@ warning_argmatch (char const *arg, size_t no, size_t err)
   int value = XARGMATCH ("--warning", arg + no + err,
                          warnings_args, warnings_types);
 
-  /* -Wnone == -Wno-all, and -Wno-none == -Wall.  */
+  /* -Wnone == -Wno-everything, and -Wno-none == -Weverything.  */
   if (!value)
     {
-      value = Wall;
+      value = Weverything;
       no = !no;
     }
 
@@ -145,7 +147,7 @@ warnings_argmatch (char *args)
       else if (STREQ (args, "no-error"))
         {
           warnings_are_errors = false;
-          warning_argmatch ("no-error=all", 3, 6);
+          warning_argmatch ("no-error=everything", 3, 6);
         }
       else
         {
