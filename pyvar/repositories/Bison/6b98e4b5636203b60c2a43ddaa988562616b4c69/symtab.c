@@ -20,6 +20,7 @@
 
 
 #include "system.h"
+#include "quotearg.h"
 #include "hash.h"
 #include "complain.h"
 #include "symtab.h"
@@ -60,6 +61,41 @@ symbol_new (const char *tag, location_t location)
 }
 
 
+/*-----------------------------------------------------------------.
+| Return the tag of this SYMBOL in a printable form.  Warning: use |
+| the first QUOTEARG slot: 0.                                      |
+`-----------------------------------------------------------------*/
+
+const char *
+symbol_tag_get (symbol_t *symbol)
+{
+  return quotearg_style (escape_quoting_style, symbol->tag);
+}
+
+
+/*------------------------------------------------------------.
+| Return the tag of this SYMBOL in a printable form.  Use the |
+| QUOTEARG slot number N.                                     |
+`------------------------------------------------------------*/
+
+const char *
+symbol_tag_get_n (symbol_t *symbol, int n)
+{
+  return quotearg_n_style (n, escape_quoting_style, symbol->tag);
+}
+
+
+/*-------------------------------.
+| Print the tag of this SYMBOL.  |
+`-------------------------------*/
+
+void
+symbol_tag_print (symbol_t *symbol, FILE *out)
+{
+  fputs (symbol_tag_get (symbol), out);
+}
+
+
 /*------------------------------------------------------------------.
 | Set the TYPE_NAME associated to SYMBOL.  Does nothing if passed 0 |
 | as TYPE_NAME.                                                     |
