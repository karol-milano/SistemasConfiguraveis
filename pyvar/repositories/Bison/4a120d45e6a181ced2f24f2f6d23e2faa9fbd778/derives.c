@@ -30,8 +30,13 @@ Boston, MA 02111-1307, USA.  */
 #include "types.h"
 #include "gram.h"
 
-void set_derives PARAMS((void));
-void free_derives PARAMS((void));
+extern void set_derives PARAMS((void));
+extern void free_derives PARAMS((void));
+
+#if DEBUG
+static void print_derives PARAMS((void));
+extern char **tags;
+#endif
 
 short **derives;
 
@@ -95,14 +100,12 @@ free_derives (void)
 
 #ifdef	DEBUG
 
-void
+static void
 print_derives (void)
 {
   register int i;
   register short *sp;
 
-  extern char **tags;
-
   printf(_("\n\n\nDERIVES\n\n"));
 
   for (i = ntokens; i < nsyms; i++)
