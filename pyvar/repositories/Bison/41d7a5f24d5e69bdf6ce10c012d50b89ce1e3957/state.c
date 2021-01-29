@@ -26,6 +26,7 @@
 #include "complain.h"
 #include "gram.h"
 #include "state.h"
+#include "print-xml.h"
 
 
 			/*-------------------.
@@ -143,6 +144,7 @@ state_new (symbol_number accessing_symbol,
   res->errs = NULL;
   res->consistent = 0;
   res->solved_conflicts = NULL;
+  res->solved_conflicts_xml = NULL;
 
   res->nitems = nitems;
   memcpy (res->items, core, items_size);
@@ -244,6 +246,31 @@ state_rule_lookahead_tokens_print (state *s, rule *r, FILE *out)
     }
 }
 
+void
+state_rule_lookahead_tokens_print_xml (state *s, rule *r,
+				       FILE *out, int level)
+{
+  /* Find the reduction we are handling.  */
+  reductions *reds = s->reductions;
+  int red = state_reduction_find (s, r);
+
+  /* Print them if there are.  */
+  if (reds->lookahead_tokens && red != -1)
+    {
+      bitset_iterator biter;
+      int k;
+      char const *sep = "";
+      xml_puts (out, level, "<lookaheads>");
+      BITSET_FOR_EACH (biter, reds->lookahead_tokens[red], k, 0)
+	{
+	  xml_printf (out, level + 1, "<symbol class=\"%s\">%s</symbol>",
+		      symbol_class_get_string (symbols[k]),
+		      xml_escape (symbols[k]->tag));
+	}
+      xml_puts (out, level, "</lookaheads>");
+    }
+}
+
 
 /*---------------------.
 | A state hash table.  |
