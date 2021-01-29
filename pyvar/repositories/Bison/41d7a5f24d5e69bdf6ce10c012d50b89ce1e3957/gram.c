@@ -1,7 +1,7 @@
 /* Allocate input grammar variables for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2001, 2002, 2003, 2005, 2006 Free
-   Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2001, 2002, 2003, 2005, 2006
+   2007 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -27,6 +27,7 @@
 #include "reader.h"
 #include "reduce.h"
 #include "symtab.h"
+#include "print-xml.h"
 
 /* Comments for these variables are in gram.h.  */
 
@@ -102,6 +103,12 @@ rule_lhs_print (rule *r, symbol *previous_lhs, FILE *out)
     }
 }
 
+void
+rule_lhs_print_xml (rule *r, FILE *out, int level)
+{
+  xml_printf (out, level, "<lhs>%s</lhs>", r->lhs->tag);
+}
+
 
 /*--------------------------------------.
 | Return the number of symbols in RHS.  |
@@ -138,6 +145,26 @@ rule_rhs_print (rule *r, FILE *out)
     }
 }
 
+static void
+rule_rhs_print_xml (rule *r, FILE *out, int level)
+{
+  if (*r->rhs >= 0)
+    {
+      item_number *rp;
+      xml_puts (out, level, "<rhs>");
+      for (rp = r->rhs; *rp >= 0; rp++)
+	xml_printf (out, level + 1, "<symbol class=\"%s\">%s</symbol>",
+		    symbol_class_get_string (symbols[*rp]),
+		    xml_escape (symbols[*rp]->tag));
+      xml_puts (out, level, "</rhs>");
+    }
+  else
+    {
+      xml_puts (out, level, "<rhs>");
+      xml_puts (out, level + 1, "<empty/>");
+      xml_puts (out, level, "</rhs>");
+    }
+}
 
 /*-------------------------.
 | Print this rule on OUT.  |
@@ -221,6 +248,40 @@ grammar_rules_partial_print (FILE *out, const char *title,
 }
 
 
+/*----------------------------------------------------------.
+| Print the grammar's rules that match FILTER on OUT (XML). |
+`-----------------------------------------------------------*/
+
+void
+grammar_rules_partial_print_xml (FILE *out, int level, bool rtag,
+				 rule_filter filter)
+{
+  rule_number r;
+  bool first = true;
+
+  for (r = 0; r < nrules + nuseless_productions; r++)
+    {
+      if (filter && !filter (&rules[r]))
+	continue;
+      if (rtag && first)
+	xml_puts (out, level + 1, "<rules>");
+      first = false;
+
+      xml_printf (out, level + 2, "<rule number=\"%d\">",
+		  rules[r].number);
+      rule_lhs_print_xml (&rules[r], out, level + 3);
+      rule_rhs_print_xml (&rules[r], out, level + 3);
+      xml_puts (out, level + 2, "</rule>");
+    }
+  if (rtag)
+    {
+      if (!first)
+	xml_puts (out, level + 1, "</rules>");
+      else
+	xml_puts (out, level + 1, "<rules/>");
+    }
+}
+
 /*------------------------------------------.
 | Print the grammar's useful rules on OUT.  |
 `------------------------------------------*/
@@ -231,6 +292,12 @@ grammar_rules_print (FILE *out)
   grammar_rules_partial_print (out, _("Grammar"), rule_useful_p);
 }
 
+void
+grammar_rules_print_xml (FILE *out, int level)
+{
+  grammar_rules_partial_print_xml (out, level, true, rule_useful_p);
+}
+
 
 /*-------------------.
 | Dump the grammar.  |
