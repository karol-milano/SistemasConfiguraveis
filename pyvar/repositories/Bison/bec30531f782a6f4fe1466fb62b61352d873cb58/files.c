@@ -192,6 +192,7 @@ skeleton_find (const char *envvar, const char *skeleton_name)
   const char *res = getenv (envvar);
 
 #if defined (MSDOS) || defined (_WIN32)
+  const char *cp = getenv ("INIT");
   if (!res)
     {
       /* Skeleton file name without path */
@@ -204,7 +205,6 @@ skeleton_find (const char *envvar, const char *skeleton_name)
         ++skel_name;
 
       /* File doesn't exist in current directory; try in INIT directory.  */
-      const char *cp = getenv ("INIT");
       if (cp)
 	{
 	  res = XMALLOC (char, strlen (cp) + strlen (skel_name) + 2);
