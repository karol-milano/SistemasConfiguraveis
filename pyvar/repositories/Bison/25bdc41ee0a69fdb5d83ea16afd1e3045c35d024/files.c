@@ -184,7 +184,7 @@ static void
 compute_exts_from_src (const char *ext)
 {
   /* We use this function when the user specifies `-o' or `--output',
-     so the extenions must be computed unconditionally from the file name
+     so the extensions must be computed unconditionally from the file name
      given by this option.  */
   src_extension = xstrdup (ext);
   header_extension = xstrdup (ext);
