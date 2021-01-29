@@ -36,11 +36,11 @@
 #include "symtab.h"
 
 static symbol_list *grammar = NULL;
-static int start_flag = 0;
+static bool start_flag = false;
 merger_list *merge_functions;
 
-/* Nonzero if %union has been seen.  */
-int typed = 0;
+/* Has %union been seen?  */
+bool typed = false;
 
 /*-----------------------.
 | Set the start symbol.  |
@@ -53,7 +53,7 @@ grammar_start_symbol_set (symbol *sym, location loc)
     complain_at (loc, _("multiple %s declarations"), "%start");
   else
     {
-      start_flag = 1;
+      start_flag = true;
       startsymbol = sym;
       startsymbol_location = loc;
     }
@@ -213,7 +213,7 @@ grammar_rule_begin (symbol *lhs, location loc)
     {
       startsymbol = lhs;
       startsymbol_location = loc;
-      start_flag = 1;
+      start_flag = true;
     }
 
   /* Start a new rule and record its lhs.  */
