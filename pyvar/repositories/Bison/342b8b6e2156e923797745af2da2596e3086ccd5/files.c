@@ -22,7 +22,6 @@
 #include "system.h"
 #include "getargs.h"
 #include "files.h"
-#include "xalloc.h"
 #include "gram.h"
 #include "complain.h"
 
@@ -34,11 +33,13 @@ struct obstack table_obstack;
 struct obstack defines_obstack;
 struct obstack guard_obstack;
 struct obstack output_obstack;
-struct obstack graph_obstack;
 
 char *spec_outfile = NULL;	/* for -o. */
 char *spec_file_prefix = NULL;	/* for -b. */
 char *spec_name_prefix = NULL;	/* for -p. */
+char *spec_verbose_file = NULL;   /* for --verbose. */
+char *spec_graph_file = NULL;   /* for -g. */
+char *spec_defines_file = NULL; /* for --defines. */
 
 char *infile = NULL;
 char *attrsfile = NULL;
@@ -93,24 +94,26 @@ stringappend (const char *string1, const char *string2)
 static char *
 compute_header_macro (void)
 {
-  int ite;
-  char *macro_name;
+  char *macro_name, *cp;
 
-  macro_name = XMALLOC (char,
-			strlen (base_name) +
-			strlen (header_extension) + 1);
+  if (spec_defines_file)
+    macro_name = xstrdup (spec_defines_file);
+  else
+    {
+      macro_name = XMALLOC (char,
+			    strlen (base_name) +
+			    strlen (header_extension) + 1);
 
-  stpcpy (macro_name, base_name);
-  strcat (macro_name, header_extension);
+      stpcpy (macro_name, base_name);
+      strcat (macro_name, header_extension);
+    }
+
+  for (cp = macro_name; *cp; ++cp)
+    if (islower (*cp))
+      *cp = toupper (*cp);
+    else if (!isalnum (*cp))
+      *cp = '_';
 
-  for (ite = 0; macro_name[ite]; ite++)
-    if (macro_name[ite] == '.')
-      macro_name[ite] = '_';
-    else
-      {
-	if (islower (macro_name[ite]))
-	  macro_name[ite] -= ('a' - 'A');
-      }
   return macro_name;
 }
 
@@ -194,17 +197,42 @@ skeleton_find (const char *envvar, const char *skeleton_name)
 {
   const char *res = getenv (envvar);
 
-#ifdef MSDOS
-  const char *cp;
-
-  /* File doesn't exist in current directory; try in INIT directory.  */
-  if (!res && (cp = getenv ("INIT")))
+#if defined (MSDOS) || defined (_WIN32)
+  if (!res)
     {
-      res = XMALLOC (char, strlen (cp) + strlen (skeleton_name) + 2);
-      sprintf (res, "%s%c%s", cp, '/', skeleton_name);
+      /* Skeleton file name without path */
+      const char *skel_name = strrchr(skeleton_name, '/');
+      if (!skel_name)
+        skel_name = strrchr(skeleton_name, '\\');
+      if (!skel_name)
+        skel_name = skeleton_name;
+      else
+        ++skel_name;
+
+      /* File doesn't exist in current directory; try in INIT directory.  */
+      const char *cp = getenv ("INIT");
+      if (cp)
+	{
+	  res = XMALLOC (char, strlen (cp) + strlen (skel_name) + 2);
+	  sprintf (res, "%s%c%s", cp, '\\', skel_name);
+	}
+      else if (access (skel_name, 4) == 0) /* Look in current dir. */
+        res = skel_name;
+      else
+	{
+	  /* Look in program locations dir. */
+	  extern char *program_name;
+	  cp = strrchr(program_name, '\\');
+	  if (!cp)
+	    return skeleton_name;
+	  else
+	    ++cp;
+	  res = XMALLOC (char, cp - program_name + strlen (skel_name) + 1);
+	  strncpy (res, program_name, cp - program_name);
+	  strcpy (res + (cp - program_name), skel_name);
+	}
     }
-#endif /* !MSDOS */
-
+#endif /* defined (MSDOS) || defined (_WIN32) */
   if (!res)
     res = skeleton_name;
 
@@ -260,20 +288,10 @@ get_extension_index (const char *filename)
 static void
 compute_exts_from_gf (const char *ext)
 {
-  /* Checks if SRC_EXTENSION is NULL. In the other case, %source_extension
-     was specified in the grammar file.  */
-  if (src_extension == NULL)
-    {
-      src_extension = tr (ext, 'y', 'c');
-      src_extension = tr (src_extension, 'Y', 'C');
-    }
-  /* Checks if HEADER_EXTENSION is NULL. In the other case,
-     %header_extension was specified in the grammar file.  */
-  if (header_extension == NULL)
-    {
-      header_extension = tr (ext, 'y', 'h');
-      header_extension = tr (header_extension, 'Y', 'H');
-    }
+  src_extension = tr (ext, 'y', 'c');
+  src_extension = tr (src_extension, 'Y', 'C');
+  header_extension = tr (ext, 'y', 'h');
+  header_extension = tr (header_extension, 'Y', 'H');
 }
 
 /* Computes extensions from the given c source file extension. */
@@ -395,6 +413,38 @@ compute_base_names (void)
   }
 }
 
+/*-------------------------------------------------------.
+| Close the open files, compute the output files names.  |
+`-------------------------------------------------------*/
+
+void
+compute_output_file_names (void)
+{
+  compute_base_names ();
+
+  /* If not yet done. */
+  if (!src_extension)
+    src_extension = ".c";
+  if (!header_extension)
+    header_extension = ".h";
+
+  /* It the defines filename if not given, we create it.  */
+  if (!spec_defines_file)
+    spec_defines_file = stringappend (base_name, header_extension);
+
+  /* It the graph filename if not given, we create it.  */
+  if (!spec_graph_file)
+    spec_graph_file = stringappend (short_base_name, ".vcg");
+
+  spec_verbose_file = stringappend (short_base_name, EXT_OUTPUT);
+
+  attrsfile = stringappend (short_base_name, EXT_STYPE_H);
+#ifndef MSDOS
+  attrsfile = stringappend (attrsfile, header_extension);
+#endif /* MSDOS */
+
+}
+
 /*-----------------------------------------------------------------.
 | Open the input file.  Look for the skeletons.  Find the names of |
 | the output files.  Prepare the obstacks.                         |
@@ -412,46 +462,47 @@ open_files (void)
   obstack_init (&defines_obstack);
   obstack_init (&guard_obstack);
   obstack_init (&output_obstack);
-  obstack_init (&graph_obstack);
 }
 
 
 
-/*-----------------------------------------------------.
-| Close the open files, produce all the output files.  |
-`-----------------------------------------------------*/
+/*-----------------------.
+| Close the open file..  |
+`-----------------------*/
 
 void
-output_files (void)
+close_files (void)
 {
   xfclose (finput);
+}
 
-  compute_base_names ();
-
-  /* Set default extensions */
-  if (!src_extension)
-    src_extension = ".c";
-  if (!header_extension)
-    header_extension = ".h";
-
-  attrsfile = stringappend (short_base_name, EXT_STYPE_H);
-#ifndef MSDOS
-  stringappend (attrsfile, header_extension);
-#endif /* MSDOS */
+/*---------------------------.
+| Produce the output files.  |
+`---------------------------*/
 
+void
+output_files (void)
+{
   /* Output the main file.  */
   if (spec_outfile)
     obstack_save (&table_obstack, spec_outfile);
   else
     obstack_save (&table_obstack, stringappend (base_name, src_extension));
+  obstack_free (&table_obstack, NULL);
 
   /* Output the header file if wanted. */
   if (defines_flag)
-    defines_obstack_save (stringappend (base_name, header_extension));
+    defines_obstack_save (spec_defines_file);
+  obstack_free (&defines_obstack, NULL);
+
+#if 0
+  /* Seems to be invalid now --akim. */
 
   /* If we output only the table, dump the actions in ACTFILE. */
   if (no_parser_flag)
     obstack_save (&action_obstack, stringappend (short_base_name, ".act"));
+  obstack_free (&action_obstack, NULL);
+#endif
 
   /* If we produced a semantic parser ATTRS_OBSTACK must be dumped
      into its own file, ATTTRSFILE.  */
@@ -460,19 +511,12 @@ output_files (void)
       char *temp_name;
 
       obstack_save (&attrs_obstack, attrsfile);
+      obstack_free (&attrs_obstack, NULL);
       temp_name = stringappend (short_base_name, EXT_GUARD_C);
 #ifndef MSDOS
       temp_name = stringappend (temp_name, src_extension);
 #endif /* MSDOS */
       obstack_save (&guard_obstack, temp_name);
+      obstack_free (&guard_obstack, NULL);
     }
-
-  if (verbose_flag)
-    /* We used to use just .out if spec_name_prefix (-p) was used, but
-       that conflicts with Posix.  */
-    obstack_save (&output_obstack,
-		  stringappend (short_base_name, EXT_OUTPUT));
-
-  if (graph_flag)
-    obstack_save (&graph_obstack, stringappend (short_base_name, ".vcg"));
 }
