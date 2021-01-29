@@ -134,59 +134,6 @@ xfclose (FILE *ptr)
 
   return result;
 }
-
-
-/*------------------------------------------------------------------.
-| Return the path to the skeleton which locaction might be given in |
-| ENVVAR, otherwise return SKELETON_NAME.                           |
-`------------------------------------------------------------------*/
-
-const char *
-skeleton_find (const char *envvar, const char *skeleton_name)
-{
-  const char *res = getenv (envvar);
-
-#if defined (MSDOS) || defined (_WIN32)
-  const char *cp = getenv ("INIT");
-  if (!res)
-    {
-      /* Skeleton file name without path */
-      const char *skel_name = strrchr (skeleton_name, '/');
-      if (!skel_name)
-        skel_name = strrchr (skeleton_name, '\\');
-      if (!skel_name)
-        skel_name = skeleton_name;
-      else
-        ++skel_name;
-
-      /* File doesn't exist in current directory; try in INIT directory.  */
-      if (cp)
-	{
-	  res = XMALLOC (char, strlen (cp) + strlen (skel_name) + 2);
-	  sprintf (res, "%s%c%s", cp, '\\', skel_name);
-	}
-      else if (access (skel_name, 4) == 0) /* Look in current dir. */
-        res = skel_name;
-      else
-	{
-	  /* Look in program locations dir. */
-	  extern char *program_name;
-	  cp = strrchr(program_name, '\\');
-	  if (!cp)
-	    return skeleton_name;
-	  else
-	    ++cp;
-	  res = XMALLOC (char, cp - program_name + strlen (skel_name) + 1);
-	  strncpy (res, program_name, cp - program_name);
-	  strcpy (res + (cp - program_name), skel_name);
-	}
-    }
-#endif /* defined (MSDOS) || defined (_WIN32) */
-  if (!res)
-    res = skeleton_name;
-
-  return res;
-}
 
 
 /*----------------------------------------------------------------.
