@@ -250,11 +250,7 @@ open_files (void)
       name_base = XMALLOC (char, base_length + 1);
       /* Append `.tab'.  */
       strcpy (name_base, spec_file_prefix);
-#ifdef VMS
-      strcat (name_base, "_tab");
-#else
-      strcat (name_base, ".tab");
-#endif
+      strcat (name_base, EXT_TAB);
 #ifdef MSDOS
       strlwr (name_base);
 #endif /* MSDOS */
@@ -275,15 +271,7 @@ open_files (void)
 	base_length -= 2;
       short_base_length = base_length;
 
-#ifdef VMS
-      name_base = stringappend (name_base, short_base_length, "_tab");
-#else
-#ifdef MSDOS
-      name_base = stringappend (name_base, short_base_length, "_tab");
-#else
-      name_base = stringappend (name_base, short_base_length, ".tab");
-#endif /* not MSDOS */
-#endif
+      name_base = stringappend (name_base, short_base_length, EXT_TAB);
       base_length = short_base_length + 4;
     }
 
@@ -294,13 +282,9 @@ open_files (void)
 
   if (verbose_flag)
     {
-#ifdef MSDOS
-      outfile = stringappend (name_base, short_base_length, ".out");
-#else
       /* We used to use just .out if spec_name_prefix (-p) was used,
          but that conflicts with Posix.  */
-      outfile = stringappend (name_base, short_base_length, ".output");
-#endif
+      outfile = stringappend (name_base, short_base_length, EXT_OUTPUT);
       foutput = xfopen (outfile, "w");
     }
 
@@ -321,18 +305,8 @@ open_files (void)
   else
     tabfile = stringappend (name_base, base_length, ".c");
 
-#ifdef VMS
-  attrsfile = stringappend (name_base, short_base_length, "_stype.h");
-  guardfile = stringappend (name_base, short_base_length, "_guard.c");
-#else
-#ifdef MSDOS
-  attrsfile = stringappend (name_base, short_base_length, ".sth");
-  guardfile = stringappend (name_base, short_base_length, ".guc");
-#else
-  attrsfile = stringappend (name_base, short_base_length, ".stype.h");
-  guardfile = stringappend (name_base, short_base_length, ".guard.c");
-#endif /* not MSDOS */
-#endif /* not VMS */
+  attrsfile = stringappend (name_base, short_base_length, EXT_STYPE_H);
+  guardfile = stringappend (name_base, short_base_length, EXT_GUARD_C);
 
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
