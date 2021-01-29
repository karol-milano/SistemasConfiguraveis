@@ -1,6 +1,6 @@
 /* Print an xml on generated parser, for Bison,
 
-   Copyright (C) 2007 Free Software Foundation, Inc.
+   Copyright (C) 2007, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -244,7 +244,7 @@ print_reductions (FILE *out, int level, state *s)
 {
   transitions *trans = s->transitions;
   reductions *reds = s->reductions;
-  rule *default_rule = NULL;
+  rule *default_reduction = NULL;
   int report = false;
   int i, j;
 
@@ -254,7 +254,7 @@ print_reductions (FILE *out, int level, state *s)
   }
 
   if (yydefact[s->number] != 0)
-    default_rule = &rules[yydefact[s->number] - 1];
+    default_reduction = &rules[yydefact[s->number] - 1];
 
   bitset_zero (no_reduce_set);
   FOR_EACH_SHIFT (trans, i)
@@ -263,7 +263,7 @@ print_reductions (FILE *out, int level, state *s)
     if (s->errs->symbols[i])
       bitset_set (no_reduce_set, s->errs->symbols[i]->number);
 
-  if (default_rule)
+  if (default_reduction)
     report = true;
 
   if (reds->lookahead_tokens)
@@ -276,7 +276,7 @@ print_reductions (FILE *out, int level, state *s)
 	    {
 	      if (! count)
 		{
-		  if (reds->rules[j] != default_rule)
+		  if (reds->rules[j] != default_reduction)
 		    report = true;
 		  count = true;
 		}
@@ -307,7 +307,7 @@ print_reductions (FILE *out, int level, state *s)
 	    {
 	      if (! count)
 		{
-		  if (reds->rules[j] != default_rule)
+		  if (reds->rules[j] != default_reduction)
 		    print_reduction (out, level + 1, symbols[i]->tag,
 				     reds->rules[j], true);
 		  else
@@ -318,7 +318,7 @@ print_reductions (FILE *out, int level, state *s)
 		{
 		  if (defaulted)
 		    print_reduction (out, level + 1, symbols[i]->tag,
-				     default_rule, true);
+				     default_reduction, true);
 		  defaulted = false;
 		  print_reduction (out, level + 1, symbols[i]->tag,
 				   reds->rules[j], false);
@@ -326,9 +326,9 @@ print_reductions (FILE *out, int level, state *s)
 	    }
       }
 
-  if (default_rule)
+  if (default_reduction)
     print_reduction (out, level + 1,
-		     "$default", default_rule, true);
+		     "$default", default_reduction, true);
 
   xml_puts (out, level, "</reductions>");
 }
