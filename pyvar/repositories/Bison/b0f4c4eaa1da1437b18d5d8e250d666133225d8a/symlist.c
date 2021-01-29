@@ -23,7 +23,6 @@
 #include "system.h"
 
 #include "complain.h"
-#include "scan-code.h"
 #include "symlist.h"
 
 
@@ -44,7 +43,8 @@ symbol_list_sym_new (symbol *sym, location loc)
   res->midrule_parent_rule = NULL;
   res->midrule_parent_rhs_index = 0;
 
-  code_props_none_init (&res->action_props);
+  res->action = NULL;
+  res->used = false;
 
   res->ruleprec = NULL;
   res->dprec = 0;
@@ -118,9 +118,7 @@ symbol_list_syms_print (const symbol_list *l, FILE *f)
   for (/* Nothing. */; l && l->content.sym; l = l->next)
     {
       symbol_print (l->content.sym, f);
-      fprintf (stderr,
-               code_props_is_value_used (l->action_props)
-               ? " used" : " unused");
+      fprintf (stderr, l->used ? " used" : " unused");
       if (l && l->content.sym)
 	fprintf (f, ", ");
     }
@@ -209,50 +207,57 @@ symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
 }
 
 
+/*--------------------------------------.
+| The item N in symbol list L is USED.  |
+`--------------------------------------*/
+
+void
+symbol_list_n_used_set (symbol_list *l, int n, bool used)
+{
+  l = symbol_list_n_get (l, n);
+  if (l)
+    l->used = used;
+}
+
 void
-symbol_list_destructor_set (symbol_list *node, const char *code, location loc)
+symbol_list_destructor_set (symbol_list *node, const char *destructor,
+                            location loc)
 {
-  code_props destructor;
-  code_props_symbol_action_init (&destructor, code, loc);
-  code_props_translate_code (&destructor);
   switch (node->content_type)
     {
       case SYMLIST_SYMBOL:
-        symbol_destructor_set (node->content.sym, destructor);
+        symbol_destructor_set (node->content.sym, destructor, loc);
         break;
       case SYMLIST_TYPE:
         semantic_type_destructor_set (
-          semantic_type_get (node->content.type_name), destructor);
+          semantic_type_get (node->content.type_name), destructor, loc);
         break;
       case SYMLIST_DEFAULT_TAGGED:
-        default_tagged_destructor_set (destructor);
+        default_tagged_destructor_set (destructor, loc);
         break;
       case SYMLIST_DEFAULT_TAGLESS:
-        default_tagless_destructor_set (destructor);
+        default_tagless_destructor_set (destructor, loc);
         break;
     }
 }
 
 void
-symbol_list_printer_set (symbol_list *node, const char *code, location loc)
+symbol_list_printer_set (symbol_list *node, const char *printer, location loc)
 {
-  code_props printer;
-  code_props_symbol_action_init (&printer, code, loc);
-  code_props_translate_code (&printer);
   switch (node->content_type)
     {
       case SYMLIST_SYMBOL:
-        symbol_printer_set (node->content.sym, printer);
+        symbol_printer_set (node->content.sym, printer, loc);
         break;
       case SYMLIST_TYPE:
         semantic_type_printer_set (
-          semantic_type_get (node->content.type_name), printer);
+          semantic_type_get (node->content.type_name), printer, loc);
         break;
       case SYMLIST_DEFAULT_TAGGED:
-        default_tagged_printer_set (printer);
+        default_tagged_printer_set (printer, loc);
         break;
       case SYMLIST_DEFAULT_TAGLESS:
-        default_tagless_printer_set (printer);
+        default_tagless_printer_set (printer, loc);
         break;
     }
 }
