@@ -22,20 +22,20 @@
 #include "system.h"
 
 #if defined (VMS) & !defined (__VMS_POSIX)
-# ifndef XPFILE
-#  define XPFILE "GNU_BISON:[000000]BISON.SIMPLE"
+# ifndef BISON_SIMPLE
+#  define BISON_SIMPLE "GNU_BISON:[000000]BISON.SIMPLE"
 # endif
-# ifndef XPFILE1
-#  define XPFILE1 "GNU_BISON:[000000]BISON.HAIRY"
+# ifndef BISON_HAIRY
+#  define BISON_HARIRY "GNU_BISON:[000000]BISON.HAIRY"
 # endif
 #endif
 
 #if defined (_MSC_VER)
-# ifndef XPFILE
-#  define XPFILE "c:/usr/local/lib/bison.simple"
+# ifndef BISON_SIMPLE
+#  define BISON_SIMPLE "c:/usr/local/lib/bison.simple"
 # endif
-# ifndef XPFILE1
-#  define XPFILE1 "c:/usr/local/lib/bison.hairy"
+# ifndef BISON_HAIRY
+#  define BISON_HAIRY "c:/usr/local/lib/bison.hairy"
 # endif
 #endif
 
@@ -290,7 +290,7 @@ open_files (void)
   finput = xfopen (infile, "r");
 
   if (!no_parser_flag)
-    fparser = xfopen (skeleton_find ("BISON_SIMPLE", PFILE), "r");
+    fparser = xfopen (skeleton_find ("BISON_SIMPLE", BISON_SIMPLE), "r");
 
   if (verbose_flag)
     {
@@ -354,7 +354,7 @@ open_extra_files (void)
   xfclose (fparser);
 
   if (!no_parser_flag)
-    fparser = xfopen (skeleton_find ("BISON_HAIRY", PFILE1), "r");
+    fparser = xfopen (skeleton_find ("BISON_HAIRY", BISON_HAIRY), "r");
   fguard = xfopen (guardfile, "w");
 }
 
