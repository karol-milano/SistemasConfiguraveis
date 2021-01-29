@@ -150,7 +150,7 @@ openfiles()
       short_base_length = strlen (spec_file_prefix);
       /* Count room for `.tab'.  */
       base_length = short_base_length + 4;
-      name_base = (char *) mallocate (base_length + 1);
+      name_base = (char *) xmalloc (base_length + 1);
       /* Append `.tab'.  */
       strcpy (name_base, spec_file_prefix);
 #ifdef VMS
@@ -194,9 +194,9 @@ openfiles()
 #ifdef MSDOS
   /* File doesn't exist in current directory; try in INIT directory.  */
   cp = getenv("INIT");
-  if (filename == 0 && cp != 0)
+  if (filename == 0 && cp != NULL)
     {
-      filename = malloc(strlen(cp) + strlen(PFILE) + 2);
+      filename = xmalloc(strlen(cp) + strlen(PFILE) + 2);
       strcpy(filename, cp);
       cp = filename + strlen(filename);
       *cp++ = '/';
@@ -284,9 +284,9 @@ open_extra_files()
 #ifdef MSDOS
   /* File doesn't exist in current directory; try in INIT directory.  */
   cp = getenv("INIT");
-  if (filename == 0 && cp != 0)
+  if (filename == 0 && cp != NULL)
     {
-      filename = malloc(strlen(cp) + strlen(PFILE1) + 2);
+      filename = xmalloc(strlen(cp) + strlen(PFILE1) + 2);
       strcpy(filename, cp);
       cp = filename + strlen(filename);
       *cp++ = '/';
