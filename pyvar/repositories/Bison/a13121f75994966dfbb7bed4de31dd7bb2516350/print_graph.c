@@ -18,6 +18,7 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
+#include <quotearg.h>
 #include "system.h"
 
 #include "LR0.h"
@@ -54,7 +55,7 @@ print_core (struct obstack *oout, state *s)
       snritems = nitemset;
     }
 
-  obstack_printf (oout, "%d", s->number);
+  obstack_printf (oout, "%d\\n", s->number);
   for (i = 0; i < snritems; i++)
     {
       item_number *sp;
@@ -64,43 +65,45 @@ print_core (struct obstack *oout, state *s)
       sp1 = sp = ritem + sitems[i];
 
       while (*sp >= 0)
-	sp++;
+        sp++;
 
       r = item_number_as_rule_number (*sp);
 
-      obstack_printf (oout, "\n%d: %s -> ", r, rules[r].lhs->tag);
+      obstack_printf (oout, "%d: %s -> ", r, escape (rules[r].lhs->tag));
 
       for (sp = rules[r].rhs; sp < sp1; sp++)
-	obstack_printf (oout, "%s ", symbols[*sp]->tag);
+        obstack_printf (oout, "%s ", escape (symbols[*sp]->tag));
 
       obstack_1grow (oout, '.');
 
       for (/* Nothing */; *sp >= 0; ++sp)
-	obstack_printf (oout, " %s", symbols[*sp]->tag);
+        obstack_printf (oout, " %s", escape (symbols[*sp]->tag));
 
       /* Experimental feature: display the lookahead tokens. */
       if (report_flag & report_lookahead_tokens
           && item_number_is_rule_number (*sp1))
-	{
-	  /* Find the reduction we are handling.  */
-	  reductions *reds = s->reductions;
-	  int redno = state_reduction_find (s, &rules[r]);
-
-	  /* Print them if there are.  */
-	  if (reds->lookahead_tokens && redno != -1)
-	    {
-	      bitset_iterator biter;
-	      int k;
-	      char const *sep = "";
-	      obstack_sgrow (oout, "[");
-	      BITSET_FOR_EACH (biter, reds->lookahead_tokens[redno], k, 0)
-		{
-		  obstack_printf (oout, "%s%s", sep, symbols[k]->tag);
-		  sep = ", ";
-		}
-	      obstack_sgrow (oout, "]");
-	    }
-	}
+        {
+          /* Find the reduction we are handling.  */
+          reductions *reds = s->reductions;
+          int redno = state_reduction_find (s, &rules[r]);
+
+          /* Print them if there are.  */
+          if (reds->lookahead_tokens && redno != -1)
+            {
+              bitset_iterator biter;
+              int k;
+              char const *sep = "";
+              obstack_1grow (oout, '[');
+              BITSET_FOR_EACH (biter, reds->lookahead_tokens[redno], k, 0)
+                {
+                  obstack_sgrow (oout, sep);
+                  obstack_sgrow (oout, escape (symbols[k]->tag));
+                  sep = ", ";
+                }
+              obstack_1grow (oout, ']');
+            }
+        }
+      obstack_sgrow (oout, "\\l");
     }
 }
 
