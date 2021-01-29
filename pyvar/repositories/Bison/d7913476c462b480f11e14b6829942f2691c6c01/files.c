@@ -43,7 +43,7 @@
 
 #include "getargs.h"
 #include "files.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "gram.h"
 #include "complain.h"
 
@@ -90,7 +90,7 @@ stringappend (const char *string1, int end1, const char *string2)
   while (*cp1++)
     i++;
 
-  ostring = NEW2 (i + end1 + 1, char);
+  ostring = XCALLOC (char, i + end1 + 1);
 
   cp = ostring;
   cp1 = string1;
@@ -213,7 +213,7 @@ open_files (void)
       short_base_length = strlen (spec_file_prefix);
       /* Count room for `.tab'.  */
       base_length = short_base_length + 4;
-      name_base = (char *) xmalloc (base_length + 1);
+      name_base = XMALLOC (char, base_length + 1);
       /* Append `.tab'.  */
       strcpy (name_base, spec_file_prefix);
 #ifdef VMS
@@ -263,7 +263,7 @@ open_files (void)
       cp = getenv ("INIT");
       if (filename == 0 && cp != NULL)
 	{
-	  filename = xmalloc (strlen (cp) + strlen (PFILE) + 2);
+	  filename = XMALLOC (char, strlen (cp) + strlen (PFILE) + 2);
 	  strcpy (filename, cp);
 	  cp = filename + strlen (filename);
 	  *cp++ = '/';
@@ -372,7 +372,7 @@ open_extra_files (void)
       cp = getenv ("INIT");
       if (filename == 0 && cp != NULL)
 	{
-	  filename = xmalloc (strlen (cp) + strlen (PFILE1) + 2);
+	  filename = XMALLOC (char, strlen (cp) + strlen (PFILE1) + 2);
 	  strcpy (filename, cp);
 	  cp = filename + strlen (filename);
 	  *cp++ = '/';
