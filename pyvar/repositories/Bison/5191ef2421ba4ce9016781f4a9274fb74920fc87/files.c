@@ -154,7 +154,7 @@ openfiles (void)
   strlwr (infile);
 #endif /* _WIN32 && !__CYGWIN32__ */
 
-#if (defined(unix) || defined(__unix) || defined(__unix__))
+#if (defined(unix) || defined(__unix) || defined(__unix__) || defined(__EMX__))
   {
     char *tmp_ptr = getenv("TMPDIR");
 
