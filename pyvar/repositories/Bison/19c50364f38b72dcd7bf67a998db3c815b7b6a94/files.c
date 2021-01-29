@@ -47,35 +47,35 @@ static char *defsfile;
 static char *tabfile;
 static char *actfile;
 
+/*--------------------------.
+| Is SUFFIX ending STRING?  |
+`--------------------------*/
+
+static int
+strsuffix (const char *string, const char *suffix)
+{
+  size_t string_len = strlen (string);
+  size_t suffix_len = strlen (suffix);
+  if (suffix_len <= string_len)
+    return !strcmp (string + string_len - suffix_len, suffix);
+  else
+    return 0;
+}
+
+
 /*-----------------------------------------------------------------.
 | Return a newly allocated string composed of the concatenation of |
-| the END1 first chars of STRING1, and STRING2.                    |
+| STRING1, and STRING2.                                            |
 `-----------------------------------------------------------------*/
 
 static char *
-stringappend (const char *string1, int end1, const char *string2)
+stringappend (const char *string1, const char *string2)
 {
-  char *res;
+  size_t len = strlen (string1) + strlen (string2);
+  char *res = XMALLOC (char, len + 1);
   char *cp;
-  const char *cp1;
-  int i;
-
-  cp1 = string2;
-  i = 0;
-  while (*cp1++)
-    i++;
-
-  res = XCALLOC (char, i + end1 + 1);
-
-  cp = res;
-  cp1 = string1;
-  for (i = 0; i < end1; i++)
-    *cp++ = *cp1++;
-
-  cp1 = string2;
-  while ((*cp++ = *cp1++))
-    ;
-
+  cp = stpcpy (res, string1);
+  cp = stpcpy (cp, string2);
   return res;
 }
 
@@ -157,71 +157,99 @@ skeleton_find (const char *envvar, const char *skeleton)
 }
 
 
-/*-----------------------------------------------------------------.
-| Open the input file.  Look for the skeletons.  Find the names of |
-| the output files.  Prepare the obstacks.                         |
-`-----------------------------------------------------------------*/
+/*----------------------------------------.
+| Compute BASE_NAME and SHORT_BASE_NAME.  |
+`----------------------------------------*/
 
-void
-open_files (void)
+/* FIXME: Should use xstrndup. */
+
+static void
+base_names (char **base_name, char **short_base_name)
 {
-  char *name_base;
-  int base_length;
-  int short_base_length;
+  size_t base_length;
+  size_t short_base_length;
+
+  /* If --output=foo.c was specified (SPEC_OUTFILE == foo.c),
+     BASE_NAME and SHORT_BASE_NAME are `foo'.
 
+     If --output=foo.tab.c was specified, BASE_NAME is `foo.tab' and
+     SHORT_BASE_NAME is `foo'.
+
+     The precise -o name will be used for FTABLE.  For other output
+     files, remove the ".c" or ".tab.c" suffix.  */
   if (spec_outfile)
     {
-      /* -o was specified.  The precise -o name will be used for FTABLE.
-         For other output files, remove the ".c" or ".tab.c" suffix.  */
-      name_base = spec_outfile;
 #ifdef MSDOS
-      strlwr (name_base);
+      strlwr (spec_outfile);
 #endif /* MSDOS */
       /* BASE_LENGTH includes ".tab" but not ".c".  */
-      base_length = strlen (name_base);
-      if (!strcmp (name_base + base_length - 2, ".c"))
+      base_length = strlen (spec_outfile);
+      if (strsuffix (spec_outfile, ".c"))
 	base_length -= 2;
       /* SHORT_BASE_LENGTH includes neither ".tab" nor ".c".  */
       short_base_length = base_length;
-      if (!strncmp (name_base + short_base_length - 4, ".tab", 4))
-	short_base_length -= 4;
-      else if (!strncmp (name_base + short_base_length - 4, "_tab", 4))
+      if (strsuffix (spec_outfile, ".tab") || strsuffix (spec_outfile, "_tab"))
 	short_base_length -= 4;
+      *base_name = strndup (spec_outfile, base_length);
+      *short_base_name = strndup (spec_outfile, short_base_length);
+
+      return;
     }
-  else if (spec_file_prefix)
+
+  /* If --file-prefix=foo was specified, BASE_NAME and SHORT_BASE_NAME
+     are `foo'.
+
+     Construct names from it.  */
+  if (spec_file_prefix)
     {
-      /* -b was specified.  Construct names from it.  */
-      /* SHORT_BASE_LENGTH includes neither ".tab" nor ".c".  */
-      short_base_length = strlen (spec_file_prefix);
-      /* Count room for `.tab'.  */
-      base_length = short_base_length + 4;
-      name_base = XMALLOC (char, base_length + 1);
-      /* Append `.tab'.  */
-      strcpy (name_base, spec_file_prefix);
-      strcat (name_base, EXT_TAB);
 #ifdef MSDOS
-      strlwr (name_base);
+      strlwr (spec_file_prefix);
 #endif /* MSDOS */
+      *short_base_name = xstrdup (spec_file_prefix);
+
+      *base_name = XMALLOC (char,
+			    strlen (*short_base_name) + strlen (EXT_TAB) + 1);
+      stpcpy (stpcpy (*base_name, *short_base_name), EXT_TAB);
+
+      return;
     }
-  else
-    {
-      /* -o was not specified; compute output file name from input
-         or use y.tab.c, etc., if -y was specified.  */
 
-      static char FIXED_NAME_BASE[] = "y.y";
+  /* If neither -o nor --file-prefix were specified, and the input
+     file is foo.y, BASE_NAME is `foo.tab', and SHORT_BASE_NAME is
+     `foo'.
 
-      name_base = yacc_flag ? FIXED_NAME_BASE : infile;
+     If --yacc is used, do as if the input file was `y.y'.  */
+  {
+    const char *name_base = yacc_flag ? "y.y" : infile;
 
-      /* BASE_LENGTH gets length of NAME_BASE, sans ".y" suffix if any.  */
+    /* BASE_LENGTH gets length of BASE_NAME, sans ".y" suffix if any.  */
 
-      base_length = strlen (name_base);
-      if (!strcmp (name_base + base_length - 2, ".y"))
-	base_length -= 2;
-      short_base_length = base_length;
+    base_length = strlen (name_base);
+    if (strsuffix (name_base, ".y"))
+      base_length -= 2;
+    short_base_length = base_length;
+    *short_base_name = strndup (name_base, short_base_length);
 
-      name_base = stringappend (name_base, short_base_length, EXT_TAB);
-      base_length = short_base_length + 4;
-    }
+    *base_name = XMALLOC (char,
+			  strlen (*short_base_name) + strlen (EXT_TAB) + 1);
+    stpcpy (stpcpy (*base_name, *short_base_name), EXT_TAB);
+
+    return;
+  }
+}
+
+/*-----------------------------------------------------------------.
+| Open the input file.  Look for the skeletons.  Find the names of |
+| the output files.  Prepare the obstacks.                         |
+`-----------------------------------------------------------------*/
+
+void
+open_files (void)
+{
+  char *base_name;
+  char *short_base_name;
+
+  base_names (&base_name, &short_base_name);
 
   finput = xfopen (infile, "r");
 
@@ -229,29 +257,29 @@ open_files (void)
     {
       /* We used to use just .out if spec_name_prefix (-p) was used,
          but that conflicts with Posix.  */
-      outfile = stringappend (name_base, short_base_length, EXT_OUTPUT);
+      outfile = stringappend (base_name, EXT_OUTPUT);
       foutput = xfopen (outfile, "w");
     }
 
   if (no_parser_flag)
     {
       /* use permanent name for actions file */
-      actfile = stringappend (name_base, short_base_length, ".act");
+      actfile = stringappend (short_base_name, ".act");
     }
 
   if (defines_flag)
     {
-      defsfile = stringappend (name_base, base_length, ".h");
+      defsfile = stringappend (base_name, ".h");
     }
 
   /* These are opened by `done' or `open_extra_files', if at all */
   if (spec_outfile)
     tabfile = spec_outfile;
   else
-    tabfile = stringappend (name_base, base_length, ".c");
+    tabfile = stringappend (base_name, ".c");
 
-  attrsfile = stringappend (name_base, short_base_length, EXT_STYPE_H);
-  guardfile = stringappend (name_base, short_base_length, EXT_GUARD_C);
+  attrsfile = stringappend (short_base_name, EXT_STYPE_H);
+  guardfile = stringappend (short_base_name, EXT_GUARD_C);
 
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
