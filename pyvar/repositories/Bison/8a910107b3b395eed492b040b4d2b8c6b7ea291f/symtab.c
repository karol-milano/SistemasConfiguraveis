@@ -26,12 +26,12 @@
 #include <assure.h>
 #include <fstrcmp.h>
 #include <hash.h>
+#include <quote.h>
 
 #include "complain.h"
 #include "getargs.h"
 #include "gram.h"
 #include "intprops.h"
-#include "quote.h"
 
 static struct hash_table *symbol_table = NULL;
 static struct hash_table *semantic_type_table = NULL;
@@ -610,6 +610,13 @@ symbol_check_defined (symbol *sym)
       s->number = nvars++;
     }
 
+  if (s->class == token_sym
+      && sym->tag[0] == '"'
+      && !sym->is_alias)
+    complain (&sym->location, Wdangling_alias,
+              _("string literal %s not attached to a symbol"),
+              sym->tag);
+
   for (int i = 0; i < 2; ++i)
     symbol_code_props_get (sym, i)->is_used = true;
 
