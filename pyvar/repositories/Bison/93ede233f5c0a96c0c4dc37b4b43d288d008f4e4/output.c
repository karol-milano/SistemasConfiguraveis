@@ -91,7 +91,6 @@
 */
 
 #include "system.h"
-#include "obstack.h"
 #include "quotearg.h"
 #include "getargs.h"
 #include "files.h"
@@ -1044,6 +1043,48 @@ prepare (void)
   MUSCLE_INSERT_INT ("locations-flag", locations_flag);
 }
 
+
+/*-------------------------.
+| Output the header file.  |
+`-------------------------*/
+
+static void
+header_output (void)
+{
+  FILE *out = xfopen (spec_defines_file, "w");
+  char *macro_name = compute_header_macro ();
+
+  fprintf (out, "#ifndef %s\n", macro_name);
+  fprintf (out, "# define %s\n\n", macro_name);
+
+  fputs (muscle_find ("tokendef"), out);
+  fprintf (out, "\
+#ifndef YYSTYPE\n\
+typedef %s
+yystype;\n\
+# define YYSTYPE yystype\n\
+#endif\n",
+		    muscle_find ("stype"));
+
+  if (!pure_parser)
+    fprintf (out, "\nextern YYSTYPE %slval;\n",
+	     spec_name_prefix);
+  if (semantic_parser)
+    {
+      int i;
+
+      for (i = ntokens; i < nsyms; i++)
+	/* don't make these for dummy nonterminals made by gensym.  */
+	if (*tags[i] != '@')
+	  fprintf (out, "# define\tNT%s\t%d\n", tags[i], i);
+    }
+
+  fprintf (out, "\n#endif /* not %s */\n", macro_name);
+  free (macro_name);
+  xfclose (out);
+}
+
+
 /*----------------------------------------------------------.
 | Output the parsing tables and the parser code to ftable.  |
 `----------------------------------------------------------*/
@@ -1068,7 +1109,11 @@ output (void)
   obstack_1grow (&attrs_obstack, 0);
   muscle_insert ("prologue", obstack_finish (&attrs_obstack));
 
+  /* Output the parser. */
   output_master_parser ();
+  /* Output the header if needed. */
+  if (defines_flag)
+    header_output ();
 
   free (rule_table + 1);
   obstack_free (&muscle_obstack, 0);
