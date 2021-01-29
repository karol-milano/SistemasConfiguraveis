@@ -27,7 +27,11 @@
 #include <hash.h>
 
 #include "complain.h"
+#include "getargs.h"
 #include "gram.h"
+#include "quote.h"
+
+
 
 /*----------------------------------------------------------------.
 | Symbols sorted by tag.  Allocated by table_sort, after which no |
@@ -317,6 +321,16 @@ complain_class_redeclared (symbol *sym, symbol_class class, location second)
     }
 }
 
+static void
+complain_symbol_undeclared (symbol *sym)
+{
+  assert (sym->content->status != declared);
+  complain (&sym->location,
+            sym->content->status == needed ? complaint : Wother,
+            _("symbol %s is used, but is not defined as a token"
+              " and has no rules"),
+            quote (sym->tag));
+}
 
 void
 symbol_location_as_lhs_set (symbol *sym, location loc)
@@ -520,12 +534,7 @@ symbol_check_defined (symbol *sym)
   sym_content *s = sym->content;
   if (s->class == unknown_sym)
     {
-      assert (s->status != declared);
-      complain (&sym->location,
-                s->status == needed ? complaint : Wother,
-                _("symbol %s is used, but is not defined as a token"
-                  " and has no rules"),
-                  sym->tag);
+      complain_symbol_undeclared (sym);
       s->class = nterm_sym;
       s->number = nvars++;
     }
