@@ -22,6 +22,8 @@
 
 #include "system.h"
 #include "obstack.h"
+#include "quotearg.h"
+#include "quote.h"
 #include "getargs.h"
 #include "files.h"
 #include "xalloc.h"
@@ -32,7 +34,6 @@
 #include "output.h"
 #include "reader.h"
 #include "conflicts.h"
-#include "quote.h"
 
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
 static int rline_allocated;
@@ -461,7 +462,8 @@ copy_definition (void)
   int after_percent;
 
   if (!no_lines_flag)
-    obstack_fgrow2 (&attrs_obstack, "#line %d \"%s\"\n", lineno, infile);
+    obstack_fgrow2 (&attrs_obstack, "#line %d %s\n",
+		    lineno, quotearg_style (c_quoting_style, infile));
 
   after_percent = 0;
 
@@ -779,7 +781,8 @@ parse_union_decl (void)
   typed = 1;
 
   if (!no_lines_flag)
-    obstack_fgrow2 (&attrs_obstack, "\n#line %d \"%s\"\n", lineno, infile);
+    obstack_fgrow2 (&attrs_obstack, "\n#line %d %s\n",
+		    lineno, quotearg_style (c_quoting_style, infile));
   else
     obstack_1grow (&attrs_obstack, '\n');
 
@@ -1053,7 +1056,8 @@ copy_action (symbol_list *rule, int stack_offset)
 
   if (!no_lines_flag)
     {
-      sprintf (buf, "#line %d \"%s\"\n", lineno, infile);
+      sprintf (buf, "#line %d %s\n",
+	       lineno, quotearg_style (c_quoting_style, infile));
       obstack_grow (&action_obstack, buf, strlen (buf));
     }
   obstack_1grow (&action_obstack, '{');
@@ -1141,7 +1145,8 @@ copy_guard (symbol_list *rule, int stack_offset)
 
   fprintf (fguard, "\ncase %d:\n", nrules);
   if (!no_lines_flag)
-    fprintf (fguard, "#line %d \"%s\"\n", lineno, infile);
+    fprintf (fguard, "#line %d %s\n",
+	     lineno, quotearg_style (c_quoting_style, infile));
   putc ('{', fguard);
 
   count = 0;
