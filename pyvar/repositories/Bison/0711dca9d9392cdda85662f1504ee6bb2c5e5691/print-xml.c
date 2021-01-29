@@ -27,12 +27,16 @@
 #include <stdarg.h>
 
 #include "closure.h"
+#include "complain.h"
 #include "conflicts.h"
+#include "execute.h"
 #include "files.h"
 #include "getargs.h"
 #include "gram.h"
 #include "lalr.h"
 #include "lr0.h"
+#include "muscle-tab.h"
+#include "path-join.h"
 #include "print.h"
 #include "reader.h"
 #include "reduce.h"
@@ -531,3 +535,41 @@ print_xml (void)
 
   xfclose (out);
 }
+
+
+void
+print_html (void)
+{
+  assert (xml_flag);
+
+  char *xml2html = xpath_join (pkgdatadir (), "xslt/xml2xhtml.xsl");
+
+  char const *argv[11];
+  int i = 0;
+  argv[i++] = muscle_percent_define_get ("tool.xsltproc");
+  argv[i++] = "-o";
+  argv[i++] = spec_html_file;
+  argv[i++] = xml2html;
+  argv[i++] = spec_xml_file;
+  argv[i++] = NULL;
+  aver (i <= ARRAY_CARDINALITY (argv));
+
+  if (trace_flag & trace_tools)
+    {
+      fputs ("running:", stderr);
+      for (int j = 0; argv[j]; ++j)
+        fprintf (stderr, " %s", argv[j]);
+      fputc ('\n', stderr);
+    }
+
+  int status
+    = execute (argv[0],
+               argv[0], (char **)(void*)(argv),
+               /* ignore_sigpipe */ false,
+               /* null_stdin, null_stdout, null_stderr */ true, true, true,
+               /* slave_process */ true, /* exit_on_error */ false,
+               NULL);
+  if (status)
+    complain (NULL, complaint, _("%s failed with status %d"), argv[0], status);
+  free (xml2html);
+}
