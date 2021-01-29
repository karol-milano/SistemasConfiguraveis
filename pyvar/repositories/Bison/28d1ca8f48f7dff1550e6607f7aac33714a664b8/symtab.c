@@ -33,7 +33,6 @@
 #include "intprops.h"
 #include "quote.h"
 
-
 static struct hash_table *symbol_table = NULL;
 static struct hash_table *semantic_type_table = NULL;
 
@@ -233,7 +232,14 @@ symbol_print (symbol const *s, FILE *f)
 {
   if (s)
     {
-      fputs (s->tag, f);
+      symbol_class c = s->content->class;
+      fprintf (f, "%s: %s",
+               c == unknown_sym    ? "unknown"
+               : c == pct_type_sym ? "%type"
+               : c == token_sym    ? "token"
+               : c == nterm_sym    ? "nterm"
+               : NULL, /* abort.  */
+               s->tag);
       SYMBOL_ATTR_PRINT (type_name);
       SYMBOL_CODE_PRINT (destructor);
       SYMBOL_CODE_PRINT (printer);
@@ -502,15 +508,33 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
 | Set the CLASS associated with SYM.  |
 `------------------------------------*/
 
+static void
+complain_pct_type_on_token (location *loc)
+{
+  complain (loc, Wyacc,
+            _("POSIX yacc reserves %%type to nonterminals"));
+}
+
 void
 symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 {
   aver (class != unknown_sym);
   sym_content *s = sym->content;
-  if (s->class != unknown_sym && s->class != class)
+  if (class == pct_type_sym)
+    {
+      if (s->class == token_sym)
+        complain_pct_type_on_token (&loc);
+      else if (s->class == unknown_sym)
+        s->class = class;
+    }
+  else if (s->class != unknown_sym && s->class != pct_type_sym
+           && s->class != class)
     complain_class_redeclared (sym, class, loc);
   else
     {
+      if (class == token_sym && s->class == pct_type_sym)
+        complain_pct_type_on_token (&sym->location);
+
       if (class == nterm_sym && s->class != nterm_sym)
         s->number = nvars++;
       else if (class == token_sym && s->number == NUMBER_UNDEFINED)
@@ -579,7 +603,7 @@ static void
 symbol_check_defined (symbol *sym)
 {
   sym_content *s = sym->content;
-  if (s->class == unknown_sym)
+  if (s->class == unknown_sym || s->class == pct_type_sym)
     {
       complain_symbol_undeclared (sym);
       s->class = nterm_sym;
