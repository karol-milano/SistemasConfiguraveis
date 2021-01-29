@@ -64,7 +64,7 @@ struct bison_language const *language = &valid_languages[0];
 
 /** Decode an option's key.
  *
- *  \param option   option being decoded.
+ *  \param opt      option being decoded.
  *  \param keys     array of valid subarguments.
  *  \param values   array of corresponding (int) values.
  *  \param all      the all value.
@@ -79,11 +79,11 @@ struct bison_language const *language = &valid_languages[0];
  *  flags from \c all.  Thus no-none = all and no-all = none.
  */
 static void
-flag_argmatch (const char *option,
-               const char * const keys[], const int values[],
+flag_argmatch (const char *opt,
+               const char *const keys[], const int values[],
                int all, int *flags, char *arg, size_t no)
 {
-  int value = XARGMATCH (option, arg + no, keys, values);
+  int value = XARGMATCH (opt, arg + no, keys, values);
 
   /* -rnone == -rno-all, and -rno-none == -rall.  */
   if (!value)
@@ -100,7 +100,7 @@ flag_argmatch (const char *option,
 
 /** Decode an option's set of keys.
  *
- *  \param option   option being decoded.
+ *  \param opt      option being decoded (e.g., --report).
  *  \param keys     array of valid subarguments.
  *  \param values   array of corresponding (int) values.
  *  \param all      the all value.
@@ -109,7 +109,7 @@ flag_argmatch (const char *option,
  *                  If 0, then activate all the flags.
  */
 static void
-flags_argmatch (const char *option,
+flags_argmatch (const char *opt,
                 const char * const keys[], const int values[],
                 int all, int *flags, char *args)
 {
@@ -117,7 +117,7 @@ flags_argmatch (const char *option,
     for (args = strtok (args, ","); args; args = strtok (NULL, ","))
       {
         size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-        flag_argmatch (option, keys,
+        flag_argmatch (opt, keys,
                        values, all, flags, args, no);
       }
   else
