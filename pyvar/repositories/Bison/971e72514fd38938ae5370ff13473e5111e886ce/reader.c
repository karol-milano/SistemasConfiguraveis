@@ -26,6 +26,7 @@
 #include "complain.h"
 #include "conflicts.h"
 #include "files.h"
+#include "fixits.h"
 #include "getargs.h"
 #include "gram.h"
 #include "muscle-tab.h"
@@ -344,14 +345,22 @@ grammar_rule_check_and_complete (symbol_list *r)
   /* Check that %empty => empty rule.  */
   if (r->percent_empty_loc.start.file
       && r->next && r->next->content.sym)
-    complain (&r->percent_empty_loc, complaint,
-              _("%%empty on non-empty rule"));
+    {
+      complain (&r->percent_empty_loc, complaint,
+                _("%%empty on non-empty rule"));
+      fixits_register (&r->percent_empty_loc, "");
+    }
 
   /* Check that empty rule => %empty.  */
   if (!(r->next && r->next->content.sym)
       && !r->midrule_parent_rule
-      && !r->percent_empty_loc.start.file)
-    complain (&r->location, Wempty_rule, _("empty rule without %%empty"));
+      && !r->percent_empty_loc.start.file
+      && warning_is_enabled (Wempty_rule))
+    {
+      complain (&r->location, Wempty_rule,
+                _("empty rule without %%empty"));
+      fixits_register (&r->location, " %empty ");
+    }
 
   /* See comments in grammar_current_rule_prec_set for how POSIX
      mandates this complaint.  It's only for identifiers, so skip
