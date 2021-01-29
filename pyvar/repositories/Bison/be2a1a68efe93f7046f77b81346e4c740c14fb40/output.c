@@ -90,6 +90,7 @@
 
 #include "system.h"
 #include "quotearg.h"
+#include "error.h"
 #include "getargs.h"
 #include "files.h"
 #include "gram.h"
@@ -101,7 +102,13 @@
 #include "symtab.h"
 #include "conflicts.h"
 #include "muscle_tab.h"
-#include "skeleton.h"
+
+/* From lib/readpipe.h.  */
+FILE *readpipe PARAMS ((const char *, ...));
+
+/* From src/scan-skel.l. */
+int skel_lex PARAMS ((void));
+extern FILE *skel_in;
 
 static int nvectors;
 static int nentries;
@@ -504,7 +511,7 @@ token_actions (void)
 `-----------------------------*/
 
 void
-actions_output (FILE *out, size_t *line)
+actions_output (FILE *out)
 {
   int rule;
   for (rule = 1; rule < nrules + 1; ++rule)
@@ -523,14 +530,6 @@ actions_output (FILE *out, size_t *line)
 	fprintf (out, "{ %s%s }\n    break;\n\n",
 		 rules[rule].action,
 		 yacc_flag ? ";" : "");
-
-	/* We always output 4 '\n' per action.  */
-	*line += 4;
-	/* Plus one if !no_lines_flag.  */
-	if (!no_lines_flag)
-	  ++*line;
-	/* Get the number of lines written by the user.  */
-	*line += get_lines_number (rules[rule].action);
       }
 }
 
@@ -540,11 +539,11 @@ actions_output (FILE *out, size_t *line)
 `----------------------------*/
 
 void
-guards_output (FILE *out, size_t *line)
+guards_output (FILE *out)
 {
   int rule;
   for (rule = 1; rule < nrules + 1; ++rule)
-    if (rules[rule].action)
+    if (rules[rule].guard)
       {
 	fprintf (out, "  case %d:\n", rule);
 
@@ -555,14 +554,6 @@ guards_output (FILE *out, size_t *line)
 				   muscle_find ("filename")));
 	fprintf (out, "{ %s; }\n    break;\n\n",
 		 rules[rule].guard);
-
-	/* We always output 4 '\n' per action.  */
-	*line += 4;
-	/* Plus one if !no_lines_flag.  */
-	if (!no_lines_flag)
-	  ++*line;
-	/* Get the number of lines written by the user.  */
-	*line += get_lines_number (rules[rule].guard);
       }
 }
 
@@ -572,7 +563,7 @@ guards_output (FILE *out, size_t *line)
 `---------------------------------------*/
 
 void
-token_definitions_output (FILE *out, size_t *line)
+token_definitions_output (FILE *out)
 {
   int i;
   for (i = 0; i < ntokens; ++i)
@@ -603,14 +594,10 @@ token_definitions_output (FILE *out, size_t *line)
 
       fprintf (out, "# define %s\t%d\n",
 	       symbol->tag, number);
-      ++*line;
       if (semantic_parser)
-	{
-	  /* FIXME: This is probably wrong, and should be just as
-	     above. --akim.  */
-	  fprintf (out, "# define T%s\t%d\n", symbol->tag, symbol->value);
-	  ++*line;
-	}
+	/* FIXME: This is probably wrong, and should be just as
+	   above. --akim.  */
+	fprintf (out, "# define T%s\t%d\n", symbol->tag, symbol->value);
     }
 }
 
@@ -972,14 +959,57 @@ output_skeleton (void)
   if (!skeleton)
     {
       if (semantic_parser)
-	skeleton = skeleton_find ("BISON_HAIRY", BISON_HAIRY);
+	skeleton = "bison.hairy";
       else
-	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
+	skeleton = "bison.simple";
     }
 
   /* Parse the skeleton file and output the needed parsers.  */
   muscle_insert ("skeleton", skeleton);
-  process_skeleton (skeleton);
+
+  /* Store the definition of all the muscles. */
+  {
+    FILE *muscles_m4 = xfopen ("/tmp/muscles.m4", "w");
+    /* There are no comments, especially not `#': we do want M4 expansion
+       after `#': think of CPP macros!  */
+    fprintf (muscles_m4, "m4_changecom()\n");
+    fprintf (muscles_m4, "m4_init()\n");
+
+    fprintf (muscles_m4, "m4_define([b4_actions], \n[[");
+    actions_output (muscles_m4);
+    fprintf (muscles_m4, "]])\n\n");
+
+    fprintf (muscles_m4, "m4_define([b4_guards], \n[[");
+    guards_output (muscles_m4);
+    fprintf (muscles_m4, "]])\n\n");
+
+    fprintf (muscles_m4, "m4_define([b4_tokendef], \n[[");
+    token_definitions_output (muscles_m4);
+    fprintf (muscles_m4, "]])\n\n");
+
+    muscles_m4_output (muscles_m4);
+
+    fprintf (muscles_m4, "m4_wrap([m4_divert_pop(0)])\n");
+    fprintf (muscles_m4, "m4_divert_push(0)dnl\n");
+    xfclose (muscles_m4);
+  }
+
+  /* Invoke m4 on the definition of the muscles, and the skeleton. */
+  {
+    const char *bison_pkgdatadir = getenv ("BISON_PKGDATADIR");
+    if (!bison_pkgdatadir)
+      bison_pkgdatadir = PKGDATADIR;
+    skel_in = readpipe ("m4",
+			"-I",
+			bison_pkgdatadir,
+			"m4sugar/m4sugar.m4",
+			"/tmp/muscles.m4",
+			skeleton,
+			NULL);
+    if (!skel_in)
+      error (EXIT_FAILURE, errno, "cannot run m4");
+    skel_lex ();
+  }
 }
 
 static void
@@ -992,20 +1022,23 @@ prepare (void)
   MUSCLE_INSERT_INT ("debug", debug_flag);
   MUSCLE_INSERT_INT ("final", final_state);
   MUSCLE_INSERT_INT ("maxtok", max_user_token_number);
-  MUSCLE_INSERT_INT ("error-verbose", error_verbose);
+  MUSCLE_INSERT_INT ("error_verbose", error_verbose);
   MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
 
   /* FIXME: This is wrong: the muscles should decide whether they hold
      a copy or not, but the situation is too obscure currently.  */
-  MUSCLE_INSERT_STRING ("output-infix", output_infix ? output_infix : "");
-  MUSCLE_INSERT_STRING ("output-prefix", short_base_name);
+  MUSCLE_INSERT_STRING ("output_infix", output_infix ? output_infix : "");
+  MUSCLE_INSERT_STRING ("output_prefix", short_base_name);
+  MUSCLE_INSERT_STRING ("output_parser_name", parser_file_name);
+  MUSCLE_INSERT_STRING ("output_header_name", spec_defines_file);
 
   MUSCLE_INSERT_INT ("nnts", nvars);
   MUSCLE_INSERT_INT ("nrules", nrules);
   MUSCLE_INSERT_INT ("nstates", nstates);
   MUSCLE_INSERT_INT ("ntokens", ntokens);
 
-  MUSCLE_INSERT_INT ("locations-flag", locations_flag);
+  MUSCLE_INSERT_INT ("locations_flag", locations_flag);
+  MUSCLE_INSERT_INT ("defines_flag", defines_flag);
 }
 
 /*-------------------------.
@@ -1015,14 +1048,13 @@ prepare (void)
 static void
 header_output (void)
 {
-  size_t dummy_line;
   FILE *out = xfopen (spec_defines_file, "w");
   char *macro_name = compute_header_macro ();
 
   fprintf (out, "#ifndef %s\n", macro_name);
   fprintf (out, "# define %s\n\n", macro_name);
 
-  token_definitions_output (out, &dummy_line);
+  token_definitions_output (out);
   fprintf (out, "\
 #ifndef YYSTYPE\n\
 typedef %s
@@ -1097,7 +1129,8 @@ output (void)
   output_skeleton ();
 
   /* Output the header if needed. */
-  if (defines_flag)
+
+  if (0)
     header_output ();
 
   free (rules + 1);
