@@ -22,8 +22,6 @@
 #include "system.h"
 
 #if defined (VMS) & !defined (__VMS_POSIX)
-# include <ssdef.h>
-# define unlink delete
 # ifndef XPFILE
 #  define XPFILE "GNU_BISON:[000000]BISON.SIMPLE"
 # endif
