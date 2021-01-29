@@ -30,6 +30,7 @@
 #include "files.h"
 #include "getargs.h"
 #include "quote.h"
+#include "quotearg.h"
 
 err_status complaint_status = status_none;
 
@@ -393,6 +394,14 @@ deprecated_directive (location const *loc, char const *old, char const *upd)
     complain (loc, Wdeprecated,
               _("deprecated directive: %s, use %s"),
               quote (old), quote_n (1, upd));
+  /* GCC and Clang follow the same pattern.
+     http://clang.llvm.org/docs/UsersManual.html#cmdoption-fdiagnostics-parseable-fixits */
+  if (feature_flag & feature_fixit_parsable)
+    fprintf (stderr, "fix-it:%s:{%d:%d-%d:%d}:%s\n",
+             quotearg_n_style (1, c_quoting_style, loc->start.file),
+             loc->start.line, loc->start.column,
+             loc->end.line, loc->end.column,
+             quotearg_n_style (2, c_quoting_style, upd));
 }
 
 void
