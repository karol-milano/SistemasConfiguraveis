@@ -19,6 +19,8 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
+#include "print-graph.h"
+
 #include "system.h"
 
 #include "closure.h"
@@ -30,7 +32,6 @@
 #include "graphviz.h"
 #include "lalr.h"
 #include "lr0.h"
-#include "print-graph.h"
 #include "reader.h"
 #include "state.h"
 #include "symtab.h"
@@ -63,12 +64,7 @@ print_core (struct obstack *oout, state *s)
   for (size_t i = 0; i < snritems; ++i)
     {
       item_number const *sp1 = ritem + sitems[i];
-      item_number const *sp = sp1;
-
-      while (0 <= *sp)
-        sp++;
-
-      rule *r = &rules[item_number_as_rule_number (*sp)];
+      rule const *r = item_rule (sp1);
 
       obstack_printf (oout, "%3d ", r->number);
       if (previous_lhs && UNIQSTR_EQ (previous_lhs->symbol->tag,
@@ -79,13 +75,13 @@ print_core (struct obstack *oout, state *s)
         obstack_printf (oout, "%s: ", escape (r->lhs->symbol->tag));
       previous_lhs = r->lhs;
 
-      for (sp = r->rhs; sp < sp1; sp++)
+      for (item_number const *sp = r->rhs; sp < sp1; sp++)
         obstack_printf (oout, "%s ", escape (symbols[*sp]->tag));
 
       obstack_1grow (oout, '.');
 
       if (0 <= *r->rhs)
-        for (/* Nothing */; *sp >= 0; ++sp)
+        for (item_number const *sp = sp1; 0 <= *sp; ++sp)
           obstack_printf (oout, " %s", escape (symbols[*sp]->tag));
       else
         obstack_printf (oout, " %%empty");
