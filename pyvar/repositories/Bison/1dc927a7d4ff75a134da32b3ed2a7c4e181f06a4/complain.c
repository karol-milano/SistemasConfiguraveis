@@ -28,6 +28,7 @@
 #include "complain.h"
 #include "files.h"
 #include "getargs.h"
+#include "quote.h"
 
 warnings warnings_flag =
   Wconflicts_sr | Wconflicts_rr | Wdeprecated  | Wother;
@@ -188,4 +189,18 @@ complain_args (location const *loc, warnings w, unsigned *indent,
     complain (loc, fatal, "too many arguments for complains");
     break;
   }
+
+}
+
+void
+deprecated_directive (location const *loc, char const *old, char const *upd)
+{
+  if (feature_flag & feature_caret)
+    complain (loc, Wdeprecated,
+              _("deprecated directive, use %s"),
+              quote_n (1, upd));
+  else
+    complain (loc, Wdeprecated,
+              _("deprecated directive: %s, use %s"),
+              quote (old), quote_n (1, upd));
 }
