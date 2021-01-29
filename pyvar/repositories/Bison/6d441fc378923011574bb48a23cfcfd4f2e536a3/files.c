@@ -21,11 +21,14 @@
 
 
 #include "system.h"
-#include "getargs.h"
+
+#include <error.h>
+#include <get-errno.h>
+
+#include "complain.h"
 #include "files.h"
+#include "getargs.h"
 #include "gram.h"
-#include "error.h"
-#include "complain.h"
 
 /* From basename.c.  Almost a lie, as it returns a char *. */
 const char *base_name (char const *name);
@@ -50,8 +53,8 @@ char *spec_graph_file = NULL;   /* for -g. */
 char *spec_defines_file = NULL; /* for --defines. */
 char *parser_file_name = NULL;
 
-struniq_t grammar_file = NULL;
-struniq_t current_file = NULL;
+uniqstr grammar_file = NULL;
+uniqstr current_file = NULL;
 
 static char *full_base_name = NULL;
 
@@ -63,36 +66,19 @@ const char *src_extension = NULL;
 /* Header file extension (if option ``-d'' is specified).  */
 const char *header_extension = NULL;
 
-
-/*--------------------------.
-| Is SUFFIX ending STRING?  |
-`--------------------------*/
-
-int
-strsuffix (const char *string, const char *suffix)
-{
-  size_t string_len = strlen (string);
-  size_t suffix_len = strlen (suffix);
-  if (suffix_len <= string_len)
-    return !strcmp (string + string_len - suffix_len, suffix);
-  else
-    return 0;
-}
-
-
 /*-----------------------------------------------------------------.
 | Return a newly allocated string composed of the concatenation of |
-| STRING1, and STRING2.                                            |
+| STR1, and STR2.                                                  |
 `-----------------------------------------------------------------*/
 
-char*
-stringappend (const char *string1, const char *string2)
+static char *
+concat2 (char const *str1, char const *str2)
 {
-  size_t len = strlen (string1) + strlen (string2);
+  size_t len = strlen (str1) + strlen (str2);
   char *res = XMALLOC (char, len + 1);
   char *cp;
-  cp = stpcpy (res, string1);
-  cp = stpcpy (cp, string2);
+  cp = stpcpy (res, str1);
+  cp = stpcpy (cp, str2);
   return res;
 }
 
@@ -108,7 +94,7 @@ xfopen (const char *name, const char *mode)
 
   ptr = fopen (name, mode);
   if (!ptr)
-    error (EXIT_FAILURE, errno, _("cannot open file `%s'"), name);
+    error (EXIT_FAILURE, get_errno (), _("cannot open file `%s'"), name);
 
   return ptr;
 }
@@ -127,7 +113,7 @@ xfclose (FILE *ptr)
     error (EXIT_FAILURE, 0, _("I/O error"));
 
   if (fclose (ptr) != 0)
-    error (EXIT_FAILURE, errno, _("cannot close file"));
+    error (EXIT_FAILURE, get_errno (), _("cannot close file"));
 }
 
 
@@ -288,8 +274,8 @@ compute_base_names (void)
 
       full_base_name = XMALLOC (char,
 				strlen (short_base_name)
-				+ strlen (EXT_TAB) + 1);
-      stpcpy (stpcpy (full_base_name, short_base_name), EXT_TAB);
+				+ strlen (TAB_EXT) + 1);
+      stpcpy (stpcpy (full_base_name, short_base_name), TAB_EXT);
 
       /* Computes the extensions from the grammar file name.  */
       filename_split (grammar_file, &base, &tab, &ext);
@@ -314,15 +300,15 @@ compute_output_file_names (void)
     header_extension = ".h";
 
   parser_file_name =
-    spec_outfile ? spec_outfile : stringappend (full_base_name, src_extension);
+    spec_outfile ? spec_outfile : concat2 (full_base_name, src_extension);
 
   /* It the defines filename if not given, we create it.  */
   if (!spec_defines_file)
-    spec_defines_file = stringappend (full_base_name, header_extension);
+    spec_defines_file = concat2 (full_base_name, header_extension);
 
   /* It the graph filename if not given, we create it.  */
   if (!spec_graph_file)
-    spec_graph_file = stringappend (short_base_name, ".vcg");
+    spec_graph_file = concat2 (short_base_name, ".vcg");
 
-  spec_verbose_file = stringappend (short_base_name, EXT_OUTPUT);
+  spec_verbose_file = concat2 (short_base_name, OUTPUT_EXT);
 }
