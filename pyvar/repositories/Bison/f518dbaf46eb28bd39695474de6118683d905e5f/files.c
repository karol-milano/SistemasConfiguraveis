@@ -142,7 +142,7 @@ xfclose (FILE *ptr)
 static void
 compute_exts_from_gf (const char *ext)
 {
-  if (strcmp (ext, ".y") == 0)
+  if (STREQ (ext, ".y"))
     {
       src_extension = xstrdup (language->src_extension);
       header_extension = xstrdup (language->header_extension);
@@ -347,7 +347,7 @@ void
 output_file_name_check (char **file_name)
 {
   bool conflict = false;
-  if (0 == strcmp (*file_name, grammar_file))
+  if (STREQ (*file_name, grammar_file))
     {
       complain (_("refusing to overwrite the input file %s"),
                 quote (*file_name));
@@ -357,7 +357,7 @@ output_file_name_check (char **file_name)
     {
       int i;
       for (i = 0; i < file_names_count; i++)
-        if (0 == strcmp (file_names[i], *file_name))
+        if (STREQ (file_names[i], *file_name))
           {
             warn (_("conflicting outputs to file %s"),
                   quote (*file_name));
