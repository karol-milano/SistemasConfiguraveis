@@ -122,7 +122,7 @@
   #include "xmemdup0.h"
 
   static int current_prec = 0;
-  static location current_lhs_location;
+  static location current_lhs_loc;
   static named_ref *current_lhs_named_ref;
   static symbol *current_lhs_symbol;
   static symbol_class current_class = unknown_sym;
@@ -2406,7 +2406,7 @@ yyreduce:
     break;
 
   case 95:
-    { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
+    { grammar_current_rule_begin (current_lhs_symbol, current_lhs_loc,
                                   current_lhs_named_ref); }
     break;
 
@@ -3037,7 +3037,7 @@ void
 current_lhs (symbol *sym, location loc, named_ref *ref)
 {
   current_lhs_symbol = sym;
-  current_lhs_location = loc;
+  current_lhs_loc = loc;
   if (sym)
     symbol_location_as_lhs_set (sym, loc);
   /* In order to simplify memory management, named references for lhs
