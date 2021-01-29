@@ -66,28 +66,28 @@ static char *defsfile;
 static char *tabfile;
 static char *guardfile;
 static char *actfile;
-
-extern char *getenv ();
-
-extern char *program_name;
 
+/*-----------------------------------------------------------------.
+| Return a newly allocated string composed of the concatenation of |
+| the END1 first chars of STRING1, and STRING2.                    |
+`-----------------------------------------------------------------*/
 
 static char *
 stringappend (const char *string1, int end1, const char *string2)
 {
-  register char *ostring;
-  register char *cp;
-  register const char *cp1;
-  register int i;
+  char *res;
+  char *cp;
+  const char *cp1;
+  int i;
 
   cp1 = string2;
   i = 0;
   while (*cp1++)
     i++;
 
-  ostring = XCALLOC (char, i + end1 + 1);
+  res = XCALLOC (char, i + end1 + 1);
 
-  cp = ostring;
+  cp = res;
   cp1 = string1;
   for (i = 0; i < end1; i++)
     *cp++ = *cp1++;
@@ -96,7 +96,7 @@ stringappend (const char *string1, int end1, const char *string2)
   while ((*cp++ = *cp1++))
     ;
 
-  return ostring;
+  return res;
 }
 
 /*-----------------------------------------------------------------.
@@ -187,40 +187,6 @@ open_files (void)
   int base_length;
   int short_base_length;
 
-#if defined (VMS) & !defined (__VMS_POSIX)
-  const char *tmp_base = "sys$scratch:b_";
-#else
-  const char *tmp_base = "/tmp/b.";
-#endif
-  int tmp_len;
-
-#ifdef MSDOS
-  tmp_base = getenv ("TMP");
-  if (tmp_base == 0)
-    tmp_base = "";
-  strlwr (infile);
-#endif /* MSDOS */
-
-#if (defined(_WIN32) && !defined(__CYGWIN32__))
-  tmp_base = getenv ("TEMP");	/* Windows95 defines this ... */
-  if (tmp_base == 0)
-    tmp_base = getenv ("Temp");	/* ... while NT prefers this */
-  if (tmp_base == 0)
-    tmp_base = "";
-  strlwr (infile);
-#endif /* _WIN32 && !__CYGWIN32__ */
-
-#if (defined(unix) || defined(__unix) || defined(__unix__) || defined(__EMX__))
-  {
-    char *tmp_ptr = getenv ("TMPDIR");
-
-    if (tmp_ptr != 0)
-      tmp_base = stringappend (tmp_ptr, strlen (tmp_ptr), "/b.");
-  }
-#endif /* unix || __unix || __unix__ */
-
-  tmp_len = strlen (tmp_base);
-
   if (spec_outfile)
     {
       /* -o was specified.  The precise -o name will be used for FTABLE.
