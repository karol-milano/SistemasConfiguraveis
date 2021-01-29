@@ -26,8 +26,8 @@
    and the name is looked up in the symbol table using symtab.c;
    symval is set to a pointer to the entry found.  */
 
-#include <stdio.h>
 #include "system.h"
+#include "getargs.h"
 #include "files.h"
 #include "getopt.h"		/* for optarg */
 #include "symtab.h"
@@ -35,17 +35,6 @@
 #include "alloc.h"
 #include "complain.h"
 
-/* flags set by % directives */
-extern int definesflag;    	/* for -d */
-extern int toknumflag;   	/* for -k */
-extern int noparserflag;	/* for -n */
-extern int fixed_outfiles;  	/* for -y */
-extern int nolinesflag;    	/* for -l */
-extern int rawtoknumflag;	/* for -r */
-extern int verboseflag;	/* for -v */
-extern int debugflag;  		/* for -t */
-extern char *spec_name_prefix; 	/* for -p */
-extern char *spec_file_prefix;	/* for -b */
 /*spec_outfile is declared in files.h, for -o */
 
 extern int translations;
