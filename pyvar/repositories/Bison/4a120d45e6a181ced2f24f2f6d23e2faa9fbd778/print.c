@@ -44,13 +44,17 @@ extern void conflict_log PARAMS((void));
 extern void verbose_conflict_log PARAMS((void));
 extern void print_reductions PARAMS((int));
 
-void terse PARAMS((void));
-void verbose PARAMS((void));
-void print_token PARAMS((int, int));
-void print_state PARAMS((int));
-void print_core PARAMS((int));
-void print_actions PARAMS((int));
-void print_grammar PARAMS((void));
+extern void terse PARAMS((void));
+extern void verbose PARAMS((void));
+
+#if 0                           /* XXX currently unused.  */
+static void print_token PARAMS((int, int));
+#endif
+
+static void print_state PARAMS((int));
+static void print_core PARAMS((int));
+static void print_actions PARAMS((int));
+static void print_grammar PARAMS((void));
 
 void
 terse (void)
@@ -79,14 +83,16 @@ verbose (void)
 }
 
 
-void
+#if 0                           /* XXX currently unused.  */
+static void
 print_token (int extnum, int token)
 {
   fprintf(foutput, _(" type %d is %s\n"), extnum, tags[token]);
 }
+#endif
 
 
-void
+static void
 print_state (int state)
 {
   fprintf(foutput, _("\n\nstate %d\n\n"), state);
@@ -95,7 +101,7 @@ print_state (int state)
 }
 
 
-void
+static void
 print_core (int state)
 {
   register int i;
@@ -141,7 +147,7 @@ print_core (int state)
 }
 
 
-void
+static void
 print_actions (int state)
 {
   register int i;
@@ -236,12 +242,16 @@ print_actions (int state)
     }
 }
 
-#define END_TEST(end) \
-  if (column + strlen(buffer) > (end))					 \
-    { fprintf (foutput, "%s\n   ", buffer); column = 3; buffer[0] = 0; } \
-  else
+#define END_TEST(end)				\
+  do {						\
+    if (column + strlen(buffer) > (end)) {	\
+      fprintf (foutput, "%s\n   ", buffer);	\
+      column = 3;				\
+      buffer[0] = 0;				\
+    }						\
+  } while (0)
 
-void
+static void
 print_grammar (void)
 {
   int i, j;
