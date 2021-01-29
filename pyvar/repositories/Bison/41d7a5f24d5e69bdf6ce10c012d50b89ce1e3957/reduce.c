@@ -1,7 +1,7 @@
 /* Grammar reduction for Bison.
 
-   Copyright (C) 1988, 1989, 2000, 2001, 2002, 2003, 2005, 2006 Free
-   Software Foundation, Inc.
+   Copyright (C) 1988, 1989, 2000, 2001, 2002, 2003, 2005, 2006,
+   2007 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -35,6 +35,7 @@
 #include "files.h"
 #include "getargs.h"
 #include "gram.h"
+#include "print-xml.h"
 #include "reader.h"
 #include "reduce.h"
 #include "symtab.h"
@@ -374,8 +375,62 @@ reduce_output (FILE *out)
 }
 
 
+/*--------------------------------------------------------------.
+| Output the detailed results of the reductions.  For FILE.xml. |
+`---------------------------------------------------------------*/
 
+void
+reduce_xml (FILE *out, int level)
+{
+  fputc ('\n', out);
+  xml_puts (out, level, "<reductions>");
+  xml_puts (out, level + 1, "<useless>");
 
+  if (nuseless_nonterminals > 0)
+    {
+      int i;
+      xml_puts (out, level + 2, "<nonterminals>");
+      for (i = 0; i < nuseless_nonterminals; ++i)
+	xml_printf (out, level + 3,
+		    "<nonterminal>%s</nonterminal>",
+		    symbols[nsyms + i]->tag);
+      xml_puts (out, level + 2, "</nonterminals>");
+    }
+  else
+    xml_puts (out, level + 2, "<nonterminals/>");
+
+  if (nuseless_productions > 0)
+    grammar_rules_partial_print_xml (out, level + 1, true, rule_useless_p);
+  else
+    xml_puts (out, level + 2, "<rules/>");
+
+  xml_puts (out, level + 1, "</useless>");
+  xml_puts (out, level + 1, "<unused>");
+
+  {
+    bool b = false;
+    int i;
+    for (i = 0; i < ntokens; i++)
+      if (!bitset_test (V, i) && !bitset_test (V1, i))
+	{
+	  if (!b)
+	    xml_puts (out, level + 2, "<terminals>");
+	  b = true;
+	  xml_printf (out, level + 3,
+		      "<terminal>%s</terminal>",
+		      symbols[i]->tag);
+	}
+    if (b)
+      xml_puts (out, level + 2, "</terminals>");
+    else
+      xml_puts (out, level + 2, "<terminals/>");
+  }
+
+  xml_puts (out, level + 1, "</unused>");
+  xml_puts (out, level, "</reductions>");
+  fputc ('\n', out);
+}
+
 
 /*-------------------------------.
 | Report the results to STDERR.  |
