@@ -1,7 +1,7 @@
 /* Print information on generated parser, for bison,
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004, 2005, 2007, 2009
-   Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004, 2005,
+   2007, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -31,6 +31,7 @@
 #include "getargs.h"
 #include "gram.h"
 #include "lalr.h"
+#include "muscle-tab.h"
 #include "print.h"
 #include "reader.h"
 #include "reduce.h"
@@ -244,6 +245,7 @@ print_reductions (FILE *out, state *s)
   rule *default_rule = NULL;
   size_t width = 0;
   int i, j;
+  bool non_default_action = false;
 
   if (reds->num == 0)
     return;
@@ -296,6 +298,8 @@ print_reductions (FILE *out, state *s)
       {
 	bool defaulted = false;
 	bool count = bitset_test (no_reduce_set, i);
+        if (count)
+          non_default_action = true;
 
 	for (j = 0; j < reds->num; ++j)
 	  if (bitset_test (reds->lookahead_tokens[j], i))
@@ -303,15 +307,19 @@ print_reductions (FILE *out, state *s)
 	      if (! count)
 		{
 		  if (reds->rules[j] != default_rule)
-		    print_reduction (out, width,
-				     symbols[i]->tag,
-				     reds->rules[j], true);
+                    {
+                      non_default_action = true;
+                      print_reduction (out, width,
+                                       symbols[i]->tag,
+                                       reds->rules[j], true);
+                    }
 		  else
 		    defaulted = true;
 		  count = true;
 		}
 	      else
 		{
+                  non_default_action = true;
 		  if (defaulted)
 		    print_reduction (out, width,
 				     symbols[i]->tag,
@@ -325,8 +333,15 @@ print_reductions (FILE *out, state *s)
       }
 
   if (default_rule)
-    print_reduction (out, width,
-		     _("$default"), default_rule, true);
+    {
+      char *default_rules = muscle_percent_define_get ("lr.default_rules");
+      print_reduction (out, width, _("$default"), default_rule, true);
+      aver (0 == strcmp (default_rules, "all")
+            || (0 == strcmp (default_rules, "consistent")
+                && !non_default_action)
+            || (reds->num == 1 && reds->rules[0]->number == 0));
+      free (default_rules);
+    }
 }
 
 
