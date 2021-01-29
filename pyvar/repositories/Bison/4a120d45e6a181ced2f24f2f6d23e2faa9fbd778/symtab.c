@@ -26,18 +26,18 @@ Boston, MA 02111-1307, USA.  */
 #include "gram.h"
 
 
-bucket **symtab;
 bucket *firstsymbol;
-bucket *lastsymbol;
+static bucket *lastsymbol;
+static bucket **symtab;
 
-void tabinit PARAMS((void));
-void free_symtab PARAMS((void));
+extern void tabinit PARAMS((void));
+extern void free_symtab PARAMS((void));
 
 
 static int
-hash (char *key)
+hash (const char *key)
 {
-  register char *cp;
+  register const char *cp;
   register int k;
 
   cp = key;
@@ -51,10 +51,10 @@ hash (char *key)
 
 
 static char *
-copys (char *s)
+copys (const char *s)
 {
   register int i;
-  register char *cp;
+  register const char *cp;
   register char *result;
 
   i = 1;
@@ -80,7 +80,7 @@ tabinit (void)
 
 
 bucket *
-getsym (char *key)
+getsym (const char *key)
 {
   register int hashval;
   register bucket *bp;
