@@ -36,9 +36,6 @@
 #include "symlist.h"
 #include "symtab.h"
 
-static void grammar_midrule_action (void);
-static void grammar_symbol_append (symbol *sym, location loc);
-
 static symbol_list *grammar = NULL;
 static bool start_flag = false;
 merger_list *merge_functions;
@@ -168,7 +165,7 @@ grammar_symbol_append (symbol *sym, location loc)
 
   grammar_end = p;
 
-  /* SYM = 0 stands for an end of rule, it is not an actual
+  /* A null SYM stands for an end of rule; it is not an actual
      part of it.  */
   if (sym)
     ++nritems;
@@ -247,7 +244,7 @@ grammar_rule_check (const symbol_list *r)
 	warn_at (r->location,
 		 _("empty rule for typed nonterminal, and no action"));
     }
-  
+
   /* Check that typed symbol values are used.  */
   {
     symbol_list *l = r;
