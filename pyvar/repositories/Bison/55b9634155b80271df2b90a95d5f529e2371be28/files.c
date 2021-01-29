@@ -20,25 +20,6 @@
 
 
 #include "system.h"
-
-#if defined (VMS) & !defined (__VMS_POSIX)
-# ifndef BISON_SIMPLE
-#  define BISON_SIMPLE "GNU_BISON:[000000]BISON.SIMPLE"
-# endif
-# ifndef BISON_HAIRY
-#  define BISON_HARIRY "GNU_BISON:[000000]BISON.HAIRY"
-# endif
-#endif
-
-#if defined (_MSC_VER)
-# ifndef BISON_SIMPLE
-#  define BISON_SIMPLE "c:/usr/local/lib/bison.simple"
-# endif
-# ifndef BISON_HAIRY
-#  define BISON_HAIRY "c:/usr/local/lib/bison.hairy"
-# endif
-#endif
-
 #include "getargs.h"
 #include "files.h"
 #include "xalloc.h"
@@ -181,9 +162,6 @@ void
 open_files (void)
 {
   char *name_base;
-#ifdef MSDOS
-  register char *cp;
-#endif
   int base_length;
   int short_base_length;
 
