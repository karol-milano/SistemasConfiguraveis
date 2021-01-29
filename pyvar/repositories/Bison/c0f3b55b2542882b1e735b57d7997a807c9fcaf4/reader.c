@@ -21,7 +21,6 @@
 #include <config.h>
 #include "system.h"
 
-#include <c-ctype.h>
 #include <quote.h>
 #include <vasnprintf.h>
 
@@ -349,7 +348,7 @@ grammar_rule_check_and_complete (symbol_list *r)
       const symbol *start = r->next->next->content.sym;
       if (start->content->type_name)
         obstack_printf (obstack_for_actions,
-                        "{ ]b4_accept([%s%d])[; }",
+                        "{ ]b4_accept""([%s%d])[; }",
                         start->content->class == nterm_sym ? "orig " : "",
                         start->content->number);
       else
