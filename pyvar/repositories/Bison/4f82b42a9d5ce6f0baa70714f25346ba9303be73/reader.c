@@ -22,7 +22,6 @@
 
 #include <config.h>
 #include "system.h"
-#include <assert.h>
 
 #include <quotearg.h>
 
@@ -148,7 +147,7 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
        merge_function != NULL && merger_find != merger;
        merge_function = merge_function->next)
     merger_find += 1;
-  assert (merge_function != NULL && merger_find == merger);
+  aver (merge_function != NULL && merger_find == merger);
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
       complain_at (declaration_loc,
@@ -515,15 +514,15 @@ packgram (void)
 	}
       /* An item ends by the rule number (negated).  */
       ritem[itemno++] = rule_number_as_item_number (ruleno);
-      assert (itemno < ITEM_NUMBER_MAX);
+      aver (itemno < ITEM_NUMBER_MAX);
       ++ruleno;
-      assert (ruleno < RULE_NUMBER_MAX);
+      aver (ruleno < RULE_NUMBER_MAX);
 
       if (p)
 	p = p->next;
     }
 
-  assert (itemno == nritems);
+  aver (itemno == nritems);
 
   if (trace_flag & trace_sets)
     ritem_print (stderr);
@@ -614,7 +613,7 @@ check_and_convert_grammar (void)
                node = node->next)
             ;
         }
-      assert (node != NULL);
+      aver (node != NULL);
       grammar_start_symbol_set (node->content.sym,
                                 node->content.sym->location);
     }
@@ -635,7 +634,7 @@ check_and_convert_grammar (void)
     grammar = p;
   }
 
-  assert (nsyms <= SYMBOL_NUMBER_MAXIMUM && nsyms == ntokens + nvars);
+  aver (nsyms <= SYMBOL_NUMBER_MAXIMUM && nsyms == ntokens + nvars);
 
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
