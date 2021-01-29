@@ -24,8 +24,9 @@
 #include "getargs.h"
 #include "files.h"
 #include "complain.h"
+#include "derives.h"
 
-#if 0                           /* XXX currently unused.  */
+#if 0				/* XXX currently unused.  */
 /* Nonzero means failure has been detected; don't write a parser file.  */
 static int failure;
 #endif
@@ -33,23 +34,21 @@ static int failure;
 /* The name this program was run with, for messages.  */
 char *program_name;
 
-extern char *printable_version PARAMS((int));
-extern void berror PARAMS((const char *));
-
-extern void openfiles PARAMS((void));
-extern void reader PARAMS((void));
-extern void reduce_grammar PARAMS((void));
-extern void set_derives PARAMS((void));
-extern void free_derives PARAMS((void));
-extern void set_nullable PARAMS((void));
-extern void free_nullable PARAMS((void));
-extern void generate_states PARAMS((void));
-extern void lalr PARAMS((void));
-extern void initialize_conflicts PARAMS((void));
-extern void finalize_conflicts PARAMS((void));
-extern void verbose PARAMS((void));
-extern void terse PARAMS((void));
-extern void output PARAMS((void));
+extern char *printable_version PARAMS ((int));
+extern void berror PARAMS ((const char *));
+
+extern void openfiles PARAMS ((void));
+extern void reader PARAMS ((void));
+extern void reduce_grammar PARAMS ((void));
+extern void set_nullable PARAMS ((void));
+extern void free_nullable PARAMS ((void));
+extern void generate_states PARAMS ((void));
+extern void lalr PARAMS ((void));
+extern void initialize_conflicts PARAMS ((void));
+extern void finalize_conflicts PARAMS ((void));
+extern void verbose PARAMS ((void));
+extern void terse PARAMS ((void));
+extern void output PARAMS ((void));
 
 
 /* VMS complained about using `int'.  */
@@ -63,59 +62,58 @@ main (int argc, char *argv[])
   textdomain (PACKAGE);
 
   lineno = 0;
-  getargs(argc, argv);
+  getargs (argc, argv);
 
-  /* Be ready to clean up if we exit.*/
+  /* Be ready to clean up if we exit. */
   atexit (done);
 
-  openfiles();
+  openfiles ();
 
-  /* read the input.  Copy some parts of it to fguard, faction, ftable and fattrs.
-     In file reader.c.
-     The other parts are recorded in the grammar; see gram.h.  */
+  /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
+     and FATTRS.  In file reader.c.  The other parts are recorded in
+     the grammar; see gram.h.  */
   reader ();
   if (complain_message_count)
     exit (1);
 
   /* find useless nonterminals and productions and reduce the grammar.  In
      file reduce.c */
-  reduce_grammar();
+  reduce_grammar ();
 
   /* record other info about the grammar.  In files derives and nullable.  */
-  set_derives();
-  set_nullable();
+  set_derives ();
+  set_nullable ();
 
   /* convert to nondeterministic finite state machine.  In file LR0.
      See state.h for more info.  */
-  generate_states();
+  generate_states ();
 
   /* make it deterministic.  In file lalr.  */
-  lalr();
+  lalr ();
 
-  /* Find and record any conflicts: places where one token of lookahead is not
-     enough to disambiguate the parsing.  In file conflicts.
-     Also resolve s/r conflicts based on precedence declarations.  */
-  initialize_conflicts();
+  /* Find and record any conflicts: places where one token of
+     lookahead is not enough to disambiguate the parsing.  In file
+     conflicts.  Also resolve s/r conflicts based on precedence
+     declarations.  */
+  initialize_conflicts ();
 
-  /* print information about results, if requested.  In file print. */
+  /* Print information about results, if requested.  In file print.
+     */
   if (verboseflag)
-    verbose();
+    verbose ();
   else
-    terse();
+    terse ();
 
-  /* output the tables and the parser to ftable.  In file output. */
-  output();
+  /* Output the tables and the parser to ftable.  In file output.  */
+  output ();
 
-  finalize_conflicts();
-  free_nullable();
-  free_derives();
+  finalize_conflicts ();
+  free_nullable ();
+  free_derives ();
 
   exit (complain_message_count ? 1 : 0);
 }
 
-/* functions to report errors which prevent a parser from being generated */
-
-
 /* Return a string containing a printable version of C:
    either C itself, or the corresponding \DDD code.  */
 
@@ -124,7 +122,7 @@ printable_version (int c)
 {
   static char buf[10];
   if (c < ' ' || c >= '\177')
-    sprintf(buf, "\\%o", c);
+    sprintf (buf, "\\%o", c);
   else
     {
       buf[0] = c;
@@ -139,5 +137,5 @@ void
 berror (const char *s)
 {
   fprintf (stderr, _("%s: internal error: %s\n"), program_name, s);
-  abort();
+  abort ();
 }
