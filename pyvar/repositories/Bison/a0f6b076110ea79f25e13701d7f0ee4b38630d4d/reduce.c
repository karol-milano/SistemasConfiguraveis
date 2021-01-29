@@ -35,6 +35,7 @@ Boston, MA 02111-1307, USA.  */
 #include "gram.h"
 #include "machine.h"
 #include "alloc.h"
+#include "complain.h"
 
 
 extern char   **tags;		/* reader.c */
@@ -74,7 +75,6 @@ static void print_results PARAMS((void));
 static void print_notices PARAMS((void));
 void dump_grammar PARAMS((void));
 
-extern void fatals PARAMS((char *, char *));
 
 
 bool
@@ -138,7 +138,7 @@ reduce_grammar (void)
   print_notices();
 
   if (!BITISSET(N, start_symbol - ntokens))
-    fatals(_("Start symbol %s does not derive any sentence"),
+    fatal (_("Start symbol %s does not derive any sentence"),
 	   tags[start_symbol]);
 
   reduce_grammar_tables();
