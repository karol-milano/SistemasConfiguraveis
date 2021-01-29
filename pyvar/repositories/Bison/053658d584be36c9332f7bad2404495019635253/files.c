@@ -25,6 +25,7 @@
 
 #include <error.h>
 #include <get-errno.h>
+#include <quote.h>
 
 #include "complain.h"
 #include "files.h"
@@ -118,9 +119,9 @@ xfclose (FILE *ptr)
 }
 
 
-/*----------------------------------------------------------------.
-| Compute BASE_NAME, SHORT_BASE_NAME and output files extensions. |
-`----------------------------------------------------------------*/
+/*---------------------------------------------------------------------.
+| Compute FULL_BASE_NAME, SHORT_BASE_NAME and output files extensions. |
+`---------------------------------------------------------------------*/
 
 /* Replace all characters FROM by TO in the string IN.
    and returns a new allocated string.  */
@@ -222,10 +223,10 @@ compute_base_names (void)
   const char *base, *tab, *ext;
 
   /* If --output=foo.c was specified (SPEC_OUTFILE == foo.c),
-     BASE_NAME and SHORT_BASE_NAME are `foo'.
+     FULL_BASE_NAME and SHORT_BASE_NAME are `foo'.
 
-     If --output=foo.tab.c was specified, BASE_NAME is `foo.tab' and
-     SHORT_BASE_NAME is `foo'.
+     If --output=foo.tab.c was specified, FULL_BASE_NAME is `foo.tab'
+     and SHORT_BASE_NAME is `foo'.
 
      The precise -o name will be used for FTABLE.  For other output
      files, remove the ".c" or ".tab.c" suffix.  */
@@ -286,13 +287,18 @@ compute_base_names (void)
     }
 }
 
-/*-------------------------------------------------------.
-| Close the open files, compute the output files names.  |
-`-------------------------------------------------------*/
+
+/* Compute the output file names.  Warn if we detect conflicting
+   outputs to the same file.  */
 
 void
 compute_output_file_names (void)
 {
+  char const *name[4];
+  int i;
+  int j;
+  int names = 0;
+
   compute_base_names ();
 
   /* If not yet done. */
@@ -301,16 +307,31 @@ compute_output_file_names (void)
   if (!header_extension)
     header_extension = ".h";
 
-  parser_file_name =
+  name[names++] = parser_file_name =
     spec_outfile ? spec_outfile : concat2 (full_base_name, src_extension);
 
-  /* It the defines filename if not given, we create it.  */
-  if (!spec_defines_file)
-    spec_defines_file = concat2 (full_base_name, header_extension);
+  if (defines_flag)
+    {
+      if (! spec_defines_file)
+	spec_defines_file = concat2 (full_base_name, header_extension);
+      name[names++] = spec_defines_file;
+    }
 
-  /* It the graph filename if not given, we create it.  */
-  if (!spec_graph_file)
-    spec_graph_file = concat2 (short_base_name, ".vcg");
+  if (graph_flag)
+    {
+      if (! spec_graph_file)
+	spec_graph_file = concat2 (short_base_name, ".vcg");
+      name[names++] = spec_graph_file;
+    }
+
+  if (report_flag)
+    {
+      spec_verbose_file = concat2 (short_base_name, OUTPUT_EXT);
+      name[names++] = spec_verbose_file;
+    }
 
-  spec_verbose_file = concat2 (short_base_name, OUTPUT_EXT);
+  for (j = 0; j < names; j++)
+    for (i = 0; i < j; i++)
+      if (strcmp (name[i], name[j]) == 0)
+	warn (_("conflicting outputs to file %s"), quote (name[i]));
 }
