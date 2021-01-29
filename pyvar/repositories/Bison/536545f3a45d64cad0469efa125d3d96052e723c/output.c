@@ -104,12 +104,8 @@
 #include "conflicts.h"
 #include "muscle_tab.h"
 
-/* From lib/readpipe.h.  */
-FILE *readpipe PARAMS ((const char *, ...));
-
 /* From src/scan-skel.l. */
-int skel_lex PARAMS ((void));
-extern FILE *skel_in;
+void m4_invoke PARAMS ((const char *definitions));
 
 static int nvectors;
 static int nentries;
@@ -894,7 +890,6 @@ sort_actions (void)
 {
   int i;
 
-  order = XCALLOC (short, nvectors);
   nentries = 0;
 
   for (i = 0; i < nvectors; i++)
@@ -1056,10 +1051,10 @@ pack_table (void)
       XFREE (conflict_tos[i]);
     }
 
-  XFREE (froms);
-  XFREE (tos);
-  XFREE (conflict_tos);
-  XFREE (pos);
+  free (froms);
+  free (tos);
+  free (conflict_tos);
+  free (pos);
 }
 
 /* the following functions output yytable, yycheck, yyconflp, yyconfl,
@@ -1124,7 +1119,7 @@ output_check (void)
 `-----------------------------------------------------------------*/
 
 static void
-output_actions (void)
+prepare_actions (void)
 {
   /* That's a poor way to make sure the sizes are properly corelated,
      in particular the signedness is not taking into account, but it's
@@ -1149,8 +1144,13 @@ output_actions (void)
   XFREE (from_state);
   XFREE (to_state);
 
+  order = XCALLOC (short, nvectors);
   sort_actions ();
   pack_table ();
+  free (order);
+
+  free (tally);
+  free (width);
 
   output_base ();
   output_table ();
@@ -1160,46 +1160,6 @@ output_actions (void)
 }
 
 
-/*----------------------.
-| Run our backend, M4.  |
-`----------------------*/
-
-static void
-m4_invoke (const char *definitions)
-{
-  /* Invoke m4 on the definition of the muscles, and the skeleton. */
-  const char *bison_pkgdatadir = getenv ("BISON_PKGDATADIR");
-  const char *m4 = getenv ("M4");
-  int pkg_data_len;
-  char *full_skeleton;
-
-  if (!m4)
-    m4 = M4;
-  if (!bison_pkgdatadir)
-    bison_pkgdatadir = PKGDATADIR;
-  pkg_data_len = strlen (bison_pkgdatadir);
-  full_skeleton = XMALLOC (char, pkg_data_len + strlen (skeleton) + 2);
-  if (bison_pkgdatadir[pkg_data_len-1] == '/')
-    sprintf (full_skeleton, "%s%s", bison_pkgdatadir, skeleton);
-  else
-    sprintf (full_skeleton, "%s/%s", bison_pkgdatadir, skeleton);
-  if (trace_flag)
-    fprintf (stderr,
-	     "running: %s -I %s m4sugar/m4sugar.m4 %s %s\n",
-	     m4, bison_pkgdatadir, definitions, full_skeleton);
-  skel_in = readpipe (m4,
-		      "-I", bison_pkgdatadir,
-		      "m4sugar/m4sugar.m4",
-		      definitions,
-		      full_skeleton,
-		      NULL);
-  XFREE (full_skeleton);
-  if (!skel_in)
-    error (EXIT_FAILURE, errno, "cannot run m4");
-  skel_lex ();
-}
-
-
 /*---------------------------.
 | Call the skeleton parser.  |
 `---------------------------*/
@@ -1312,7 +1272,7 @@ output (void)
   prepare_tokens ();
   prepare_rules ();
   prepare_states ();
-  output_actions ();
+  prepare_actions ();
 
   prepare ();
 
