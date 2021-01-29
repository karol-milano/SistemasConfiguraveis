@@ -26,6 +26,7 @@
 
 #include "complain.h"
 #include "gram.h"
+#include "quote.h"
 #include "symtab.h"
 
 /*-------------------------------------------------------------------.
@@ -444,10 +445,10 @@ void
 symbol_make_alias (symbol *sym, symbol *str, location loc)
 {
   if (str->alias)
-    warn_at (loc, _("symbol '%s' used more than once as a literal string"),
+    warn_at (loc, _("symbol %s used more than once as a literal string"),
              str->tag);
   else if (sym->alias)
-    warn_at (loc, _("symbol '%s' given more than one literal string"),
+    warn_at (loc, _("symbol %s given more than one literal string"),
              sym->tag);
   else
     {
