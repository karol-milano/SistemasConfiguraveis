@@ -84,6 +84,37 @@ stringappend (const char *string1, const char *string2)
   return res;
 }
 
+
+/*---------------------------------------------------------------.
+|  Computes the macro name used to avoid double inclusion in the |
+|  header of the parser and store it in header_macro_name.       |
+`---------------------------------------------------------------*/
+
+static const char *
+compute_header_macro (void)
+{
+  int ite;
+  char *macro_name;
+
+  macro_name = XMALLOC (char,
+			strlen (base_name) +
+			strlen (header_extension) + 1);
+
+  stpcpy (macro_name, base_name);
+  strcat (macro_name, header_extension);
+
+  for (ite = 0; macro_name[ite]; ite++)
+    if (macro_name[ite] == '.')
+      macro_name[ite] = '_';
+    else
+      {
+	if (islower (macro_name[ite]))
+	  macro_name[ite] -= ('a' - 'A');
+      }
+  return macro_name;
+}
+
+
 /*-----------------------------------------------------------------.
 | Try to open file NAME with mode MODE, and print an error message |
 | if fails.                                                        |
@@ -133,6 +164,25 @@ obstack_save (struct obstack *obs, const char *filename)
   xfclose (out);
 }
 
+/*---------------------------------------------------------------------.
+| Output double inclusion protection macros and saves defines_obstack  |
+`---------------------------------------------------------------------*/
+
+static void
+defines_obstack_save (const char *filename)
+{
+  FILE *out = xfopen (filename, "w");
+  size_t size = obstack_object_size (&defines_obstack);
+  char *macro_name = compute_header_macro ();
+
+  fprintf (out, "#ifndef %s\n", macro_name);
+  fprintf (out, "# define %s\n\n", macro_name);
+  fwrite (obstack_finish (&defines_obstack), 1, size, out);
+  fprintf (out, "\n#endif /* not %s */\n", macro_name);
+
+  free (macro_name);
+  xfclose (out);
+}
 
 /*------------------------------------------------------------------.
 | Return the path to the skeleton which locaction might be given in |
@@ -397,8 +447,7 @@ output_files (void)
 
   /* Output the header file if wanted. */
   if (defines_flag)
-    obstack_save (&defines_obstack,
-		  stringappend (base_name, header_extension));
+    defines_obstack_save (stringappend (base_name, header_extension));
 
   /* If we output only the table, dump the actions in ACTFILE. */
   if (no_parser_flag)
