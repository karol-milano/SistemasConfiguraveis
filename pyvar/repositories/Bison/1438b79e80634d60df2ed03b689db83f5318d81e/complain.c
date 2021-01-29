@@ -35,6 +35,13 @@
 #include "getargs.h"
 #include "quote.h"
 
+// The URL of the manual page about diagnostics.  Use the per-node
+// manual, to avoid downloading repeatedly the whole manual over the
+// Internet.
+static const char *diagnostics_url
+  = "https://www.gnu.org/software/bison/manual/html_node/Diagnostics.html";
+
+
 err_status complaint_status = status_none;
 
 bool warnings_are_errors = false;
@@ -96,6 +103,20 @@ end_use_class (const char *s, FILE *out)
     }
 }
 
+static void
+begin_hyperlink (FILE *out, const char *ref)
+{
+  if (out == stderr)
+    styled_ostream_set_hyperlink (errstream, ref, NULL);
+}
+
+static void
+end_hyperlink (FILE *out)
+{
+  if (out == stderr)
+    styled_ostream_set_hyperlink (errstream, NULL, NULL);
+}
+
 void
 flush (FILE *out)
 {
@@ -427,9 +448,20 @@ warnings_print_categories (warnings warn_flags, FILE *out)
         const char* style = severity_style (s);
         fputs (" [", out);
         begin_use_class (style, out);
-        fprintf (out, "-W%s%s",
-                 s == severity_error ? "error=" : "",
-                 argmatch_warning_argument (&w));
+        // E.g., "counterexamples".
+        const char *warning = argmatch_warning_argument (&w);
+        char ref[200];
+        snprintf (ref, sizeof ref,
+                  "%s#W%s", diagnostics_url, warning);
+        begin_hyperlink (out, ref);
+        ostream_printf (errstream,
+                        "-W%s%s",
+                        s == severity_error ? "error=" : "",
+                        warning);
+        end_hyperlink (out);
+        // Because we mix stdio with ostream I/O, we need to flush
+        // here for sake of color == debug.
+        flush (out);
         end_use_class (style, out);
         fputc (']', out);
         /* Display only the first match, the second is "-Wall".  */
