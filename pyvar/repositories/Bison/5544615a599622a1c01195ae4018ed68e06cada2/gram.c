@@ -23,6 +23,7 @@
 
 #include "complain.h"
 #include "getargs.h"
+#include "glyphs.h"
 #include "gram.h"
 #include "print-xml.h"
 #include "reader.h"
@@ -56,8 +57,7 @@ item_print (item_number *item, rule const *previous_rule, FILE *out)
 
   for (item_number *sp = r->rhs; sp < item; sp++)
     fprintf (out, " %s", symbols[*sp]->tag);
-  putc (' ', out);
-  print_dot (out);
+  fprintf (out, " %s", dot);
   if (0 <= *r->rhs)
     for (item_number *sp = item; 0 <= *sp; ++sp)
       fprintf (out, " %s", symbols[*sp]->tag);
