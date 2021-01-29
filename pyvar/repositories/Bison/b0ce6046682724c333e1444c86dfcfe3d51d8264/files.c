@@ -35,20 +35,20 @@ struct obstack defines_obstack;
 struct obstack guard_obstack;
 struct obstack output_obstack;
 
-char *spec_outfile;	/* for -o. */
-char *spec_file_prefix; /* for -b. */
-char *spec_name_prefix; /* for -p. */
+char *spec_outfile = NULL;	/* for -o. */
+char *spec_file_prefix = NULL; /* for -b. */
+char *spec_name_prefix = NULL; /* for -p. */
 
-char *infile;
-char *attrsfile;
+char *infile = NULL;
+char *attrsfile = NULL;
 
-static char *base_name;
-static char *short_base_name;
+static char *base_name = NULL;
+static char *short_base_name = NULL;
 
 /* C source file extension (the parser source). */
-static char *src_extension;	
+static const char *src_extension = NULL;
 /* Header file extension (if option ``-d'' is specified). */
-static char *header_extension;
+static const char *header_extension = NULL;
 
 
 /*--------------------------.
@@ -135,11 +135,11 @@ obstack_save (struct obstack *obs, const char *filename)
 
 /*------------------------------------------------------------------.
 | Return the path to the skeleton which locaction might be given in |
-| ENVVAR, otherwise return SKELETON.                                |
+| ENVVAR, otherwise return SKELETON_NAME.                           |
 `------------------------------------------------------------------*/
 
 const char *
-skeleton_find (const char *envvar, const char *skeleton)
+skeleton_find (const char *envvar, const char *skeleton_name)
 {
   const char *res = getenv (envvar);
 
@@ -149,13 +149,13 @@ skeleton_find (const char *envvar, const char *skeleton)
   /* File doesn't exist in current directory; try in INIT directory.  */
   if (!res && (cp = getenv ("INIT")))
     {
-      res = XMALLOC (char, strlen (cp) + strlen (skeleton) + 2);
-      sprintf (res, "%s%c%s", cp, '/', skeleton);
+      res = XMALLOC (char, strlen (cp) + strlen (skeleton_name) + 2);
+      sprintf (res, "%s%c%s", cp, '/', skeleton_name);
     }
 #endif /* !MSDOS */
 
   if (!res)
-    res = skeleton;
+    res = skeleton_name;
 
   return res;
 }
@@ -165,14 +165,14 @@ skeleton_find (const char *envvar, const char *skeleton)
 | Compute BASE_NAME, SHORT_BASE_NAME and output files extensions. |
 `----------------------------------------------------------------*/
 
-/* Replace all characters FROM by TO in the string IN. 
-   and returns a new allocated string. */  
+/* Replace all characters FROM by TO in the string IN.
+   and returns a new allocated string. */
 static char *
 tr(const char *in, char from, char to)
 {
   char *temp;
   char *out;
-  
+
   out = XMALLOC (char, strlen (in) + 1);
 
   for (temp = out; *in; in++, out++)
@@ -184,15 +184,15 @@ tr(const char *in, char from, char to)
   return (temp);
 }
 
-/*  Gets the extension index in FILENAME. Returns 0 if fails to 
+/*  Gets the extension index in FILENAME. Returns 0 if fails to
     find an extension. */
-static int 
+static int
 get_extension_index(const char *filename)
 {
   int  len;
 
   len = strlen (filename);
-  
+
   if (filename[len-- - 1] == '.')
     return (0);
 
@@ -232,7 +232,7 @@ compute_base_names (void)
   size_t base_length;
   size_t short_base_length;
   size_t ext_index;
-  
+
   /* Set default extensions */
   src_extension = ".c";
   header_extension = ".h";
@@ -252,9 +252,9 @@ compute_base_names (void)
 #endif /* MSDOS */
       /* BASE_LENGTH includes ".tab" but not ".c".  */
       base_length = strlen (spec_outfile);
-      
+
       ext_index = get_extension_index (spec_outfile);
-      /* if the initial segment of extension contains 'c' or a 'C', I assume 
+      /* if the initial segment of extension contains 'c' or a 'C', I assume
 	 that it is a C or C++ source file */
       if (ext_index)
 	ext_index = (strspn(spec_outfile + ext_index + 1, "cC")) ? ext_index : 0;
@@ -263,7 +263,7 @@ compute_base_names (void)
 	  base_length -= strlen (spec_outfile + ext_index);
 	  compute_exts_from_src(spec_outfile + ext_index);
 	}
-      
+
       base_name = strndup (spec_outfile, base_length);
       /* SHORT_BASE_LENGTH includes neither ".tab" nor ".c".  */
       short_base_length = base_length;
@@ -302,9 +302,9 @@ compute_base_names (void)
     /* BASE_LENGTH gets length of BASE_NAME, sans ".y" suffix if any.  */
 
     base_length = strlen (name_base);
-    
+
     ext_index = get_extension_index (name_base);
-    /* if the initial segment of extension contains a 'y' or a 'Y', I assume 
+    /* if the initial segment of extension contains a 'y' or a 'Y', I assume
        that it is a yacc or bison grammar file */
     if (ext_index)
       ext_index = (strspn(name_base + ext_index + 1, "yY")) ? ext_index : 0;
@@ -360,7 +360,7 @@ output_files (void)
   attrsfile = stringappend (short_base_name, EXT_STYPE_H);
 #ifndef MSDOS
   stringappend (attrsfile, header_extension);
-#endif /* MSDOS */  
+#endif /* MSDOS */
 
   /* Output the main file.  */
   if (spec_outfile)
