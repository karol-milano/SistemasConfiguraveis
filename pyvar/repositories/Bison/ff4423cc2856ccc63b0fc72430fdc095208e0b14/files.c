@@ -27,13 +27,13 @@
 #include "complain.h"
 
 FILE *finput = NULL;
-FILE *foutput = NULL;
 
 struct obstack action_obstack;
 struct obstack attrs_obstack;
 struct obstack table_obstack;
 struct obstack defines_obstack;
 struct obstack guard_obstack;
+struct obstack output_obstack;
 
 char *spec_outfile;	/* for -o. */
 char *spec_file_prefix; /* for -b. */
@@ -249,11 +249,6 @@ open_files (void)
 
   finput = xfopen (infile, "r");
 
-  if (verbose_flag)
-    /* We used to use just .out if spec_name_prefix (-p) was used, but
-       that conflicts with Posix.  */
-    foutput = xfopen (stringappend (short_base_name, EXT_OUTPUT), "w");
-
   attrsfile = stringappend (short_base_name, EXT_STYPE_H);
 
   /* Initialize the obstacks. */
@@ -262,6 +257,7 @@ open_files (void)
   obstack_init (&table_obstack);
   obstack_init (&defines_obstack);
   obstack_init (&guard_obstack);
+  obstack_init (&output_obstack);
 }
 
 
@@ -274,7 +270,6 @@ void
 output_files (void)
 {
   xfclose (finput);
-  xfclose (foutput);
 
   /* Output the main file.  */
   if (spec_outfile)
@@ -298,4 +293,9 @@ output_files (void)
       obstack_save (&guard_obstack,
 		    stringappend (short_base_name, EXT_GUARD_C));
     }
+
+  if (verbose_flag)
+    /* We used to use just .out if spec_name_prefix (-p) was used, but
+       that conflicts with Posix.  */
+    obstack_save (&output_obstack, stringappend (short_base_name, EXT_OUTPUT));
 }
