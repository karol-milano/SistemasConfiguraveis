@@ -68,7 +68,6 @@ argmatch_exit_fn argmatch_die = __argmatch_die;
    null-terminated array ARGLIST, return the index in ARGLIST
    of the matched element, else -1 if it does not match any element
    or -2 if it is ambiguous (is a prefix of more than one element).
-   If SENSITIVE, comparison is case sensitive.
 
    If VALLIST is none null, use it to resolve ambiguities limited to
    synonyms, i.e., for
@@ -76,10 +75,9 @@ argmatch_exit_fn argmatch_die = __argmatch_die;
      "no", "nope" -> 1
    "y" is a valid argument, for `0', and "n" for `1'.  */
 
-static int
-__argmatch_internal (const char *arg, const char *const *arglist,
-		     const char *vallist, size_t valsize,
-		     int case_sensitive)
+int
+argmatch (const char *arg, const char *const *arglist,
+	  const char *vallist, size_t valsize)
 {
   int i;			/* Temporary index in ARGLIST.  */
   size_t arglen;		/* Length of ARG.  */
@@ -91,9 +89,7 @@ __argmatch_internal (const char *arg, const char *const *arglist,
   /* Test all elements for either exact match or abbreviated matches.  */
   for (i = 0; arglist[i]; i++)
     {
-      if (case_sensitive
-	  ? !strncmp (arglist[i], arg, arglen)
-	  : !strncasecmp (arglist[i], arg, arglen))
+      if (!strncmp (arglist[i], arg, arglen))
 	{
 	  if (strlen (arglist[i]) == arglen)
 	    /* Exact match found.  */
@@ -121,22 +117,6 @@ __argmatch_internal (const char *arg, const char *const *arglist,
     return matchind;
 }
 
-/* argmatch - case sensitive version */
-int
-argmatch (const char *arg, const char *const *arglist,
-	  const char *vallist, size_t valsize)
-{
-  return __argmatch_internal (arg, arglist, vallist, valsize, 1);
-}
-
-/* argcasematch - case insensitive version */
-int
-argcasematch (const char *arg, const char *const *arglist,
-	      const char *vallist, size_t valsize)
-{
-  return __argmatch_internal (arg, arglist, vallist, valsize, 0);
-}
-
 /* Error reporting for argmatch.
    CONTEXT is a description of the type of entity that was being matched.
    VALUE is the invalid value that was given.
@@ -191,12 +171,9 @@ int
 __xargmatch_internal (const char *context,
 		      const char *arg, const char *const *arglist,
 		      const char *vallist, size_t valsize,
-		      int case_sensitive,
 		      argmatch_exit_fn exit_fn)
 {
-  int res = __argmatch_internal (arg, arglist,
-				 vallist, valsize,
-				 case_sensitive);
+  int res = argmatch (arg, arglist, vallist, valsize);
   if (res >= 0)
     /* Success. */
     return res;
@@ -282,12 +259,12 @@ main (int argc, const char *const *argv)
     }
 
   if ((cp = getenv ("VERSION_CONTROL")))
-    backup_type = XARGCASEMATCH ("$VERSION_CONTROL", cp,
-				 backup_args, backup_vals);
+    backup_type = XARGMATCH ("$VERSION_CONTROL", cp,
+			     backup_args, backup_vals);
 
   if (argc == 2)
-    backup_type = XARGCASEMATCH (program_name, argv[1],
-				 backup_args, backup_vals);
+    backup_type = XARGMATCH (program_name, argv[1],
+			     backup_args, backup_vals);
 
   printf ("The version control is `%s'\n",
 	  ARGMATCH_TO_ARGUMENT (backup_type, backup_args, backup_vals));
