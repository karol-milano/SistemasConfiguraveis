@@ -42,10 +42,9 @@ char *infile;
 char *attrsfile;
 char *guardfile;
 
-static char *outfile;
-static char *defsfile;
-static char *tabfile;
-static char *actfile;
+static char *base_name;
+static char *short_base_name;
+
 
 /*--------------------------.
 | Is SUFFIX ending STRING?  |
@@ -164,7 +163,7 @@ skeleton_find (const char *envvar, const char *skeleton)
 /* FIXME: Should use xstrndup. */
 
 static void
-base_names (char **base_name, char **short_base_name)
+compute_base_names (void)
 {
   size_t base_length;
   size_t short_base_length;
@@ -190,8 +189,8 @@ base_names (char **base_name, char **short_base_name)
       short_base_length = base_length;
       if (strsuffix (spec_outfile, ".tab") || strsuffix (spec_outfile, "_tab"))
 	short_base_length -= 4;
-      *base_name = strndup (spec_outfile, base_length);
-      *short_base_name = strndup (spec_outfile, short_base_length);
+      base_name = strndup (spec_outfile, base_length);
+      short_base_name = strndup (spec_outfile, short_base_length);
 
       return;
     }
@@ -205,11 +204,11 @@ base_names (char **base_name, char **short_base_name)
 #ifdef MSDOS
       strlwr (spec_file_prefix);
 #endif /* MSDOS */
-      *short_base_name = xstrdup (spec_file_prefix);
+      short_base_name = xstrdup (spec_file_prefix);
 
-      *base_name = XMALLOC (char,
-			    strlen (*short_base_name) + strlen (EXT_TAB) + 1);
-      stpcpy (stpcpy (*base_name, *short_base_name), EXT_TAB);
+      base_name = XMALLOC (char,
+			   strlen (short_base_name) + strlen (EXT_TAB) + 1);
+      stpcpy (stpcpy (base_name, short_base_name), EXT_TAB);
 
       return;
     }
@@ -228,11 +227,11 @@ base_names (char **base_name, char **short_base_name)
     if (strsuffix (name_base, ".y"))
       base_length -= 2;
     short_base_length = base_length;
-    *short_base_name = strndup (name_base, short_base_length);
+    short_base_name = strndup (name_base, short_base_length);
 
-    *base_name = XMALLOC (char,
-			  strlen (*short_base_name) + strlen (EXT_TAB) + 1);
-    stpcpy (stpcpy (*base_name, *short_base_name), EXT_TAB);
+    base_name = XMALLOC (char,
+			 strlen (short_base_name) + strlen (EXT_TAB) + 1);
+    stpcpy (stpcpy (base_name, short_base_name), EXT_TAB);
 
     return;
   }
@@ -246,37 +245,14 @@ base_names (char **base_name, char **short_base_name)
 void
 open_files (void)
 {
-  char *base_name;
-  char *short_base_name;
-
-  base_names (&base_name, &short_base_name);
+  compute_base_names ();
 
   finput = xfopen (infile, "r");
 
   if (verbose_flag)
-    {
-      /* We used to use just .out if spec_name_prefix (-p) was used,
-         but that conflicts with Posix.  */
-      outfile = stringappend (base_name, EXT_OUTPUT);
-      foutput = xfopen (outfile, "w");
-    }
-
-  if (no_parser_flag)
-    {
-      /* use permanent name for actions file */
-      actfile = stringappend (short_base_name, ".act");
-    }
-
-  if (defines_flag)
-    {
-      defsfile = stringappend (base_name, ".h");
-    }
-
-  /* These are opened by `done' or `open_extra_files', if at all */
-  if (spec_outfile)
-    tabfile = spec_outfile;
-  else
-    tabfile = stringappend (base_name, ".c");
+    /* We used to use just .out if spec_name_prefix (-p) was used, but
+       that conflicts with Posix.  */
+    foutput = xfopen (stringappend (base_name, EXT_OUTPUT), "w");
 
   attrsfile = stringappend (short_base_name, EXT_STYPE_H);
   guardfile = stringappend (short_base_name, EXT_GUARD_C);
@@ -302,16 +278,18 @@ output_files (void)
   xfclose (foutput);
 
   /* Output the main file.  */
-  obstack_save (&table_obstack, tabfile);
+  if (spec_outfile)
+    obstack_save (&table_obstack, spec_outfile);
+  else
+    obstack_save (&table_obstack,  stringappend (base_name, ".c"));
 
   /* Output the header file if wanted. */
   if (defines_flag)
-    obstack_save (&defines_obstack, defsfile);
+    obstack_save (&defines_obstack, stringappend (base_name, ".h"));
 
-  /* If we output only the table, dump the actions in ACTFILE.
-     */
+  /* If we output only the table, dump the actions in ACTFILE. */
   if (no_parser_flag)
-    obstack_save (&action_obstack, actfile);
+    obstack_save (&action_obstack, stringappend (short_base_name, ".act"));
 
   /* If we produced a semantic parser ATTRS_OBSTACK must be dumped
      into its own file, ATTTRSFILE.  */
