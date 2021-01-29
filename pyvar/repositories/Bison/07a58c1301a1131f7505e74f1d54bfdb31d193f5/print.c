@@ -26,47 +26,13 @@
 #include "state.h"
 #include "lalr.h"
 #include "conflicts.h"
+#include "getargs.h"
+#include "state.h"
 
 extern char **tags;
-extern int nstates;
 extern int final_state;
 
-extern void terse PARAMS ((void));
-extern void verbose PARAMS ((void));
-
-#if 0				/* XXX currently unused.  */
-static void print_token PARAMS ((int, int));
-#endif
-
-static void print_state PARAMS ((int));
-static void print_core PARAMS ((int));
-static void print_actions PARAMS ((int));
-static void print_grammar PARAMS ((void));
-
-void
-terse (void)
-{
-  if (any_conflicts)
-    print_conflicts ();
-}
-
-
-void
-verbose (void)
-{
-  int i;
-
-  if (any_conflicts)
-    print_conflicts ();
-
-  print_grammar ();
-
-  for (i = 0; i < nstates; i++)
-    print_state (i);
-}
-
-
-#if 0				/* XXX currently unused.  */
+#if 0
 static void
 print_token (int extnum, int token)
 {
@@ -74,15 +40,10 @@ print_token (int extnum, int token)
 }
 #endif
 
-
-static void
-print_state (int state)
-{
-  fprintf (foutput, _("\n\nstate %d\n\n"), state);
-  print_core (state);
-  print_actions (state);
-}
-
+
+/*================================\
+| Report information on a state.  |
+\================================*/
 
 static void
 print_core (int state)
@@ -130,7 +91,6 @@ print_core (int state)
   putc ('\n', foutput);
 }
 
-
 static void
 print_actions (int state)
 {
@@ -232,6 +192,18 @@ print_actions (int state)
     }
 }
 
+static void
+print_state (int state)
+{
+  fprintf (foutput, _("\n\nstate %d\n\n"), state);
+  print_core (state);
+  print_actions (state);
+}
+
+/*-----------------------------------------.
+| Print information on the whole grammar.  |
+`-----------------------------------------*/
+
 #define END_TEST(end)				\
   do {						\
     if (column + strlen(buffer) > (end)) {	\
@@ -241,6 +213,7 @@ print_actions (int state)
     }						\
   } while (0)
 
+
 static void
 print_grammar (void)
 {
@@ -370,3 +343,19 @@ print_grammar (void)
       fprintf (foutput, "%s\n", buffer);
     }
 }
+
+void
+print_results (void)
+{
+  int i;
+
+  if (any_conflicts)
+    print_conflicts ();
+
+  if (verboseflag)
+    print_grammar ();
+
+  if (verboseflag)
+    for (i = 0; i < nstates; i++)
+      print_state (i);
+}
