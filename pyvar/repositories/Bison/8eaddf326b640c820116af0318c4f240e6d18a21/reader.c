@@ -21,7 +21,9 @@
 #include <config.h>
 #include "system.h"
 
+#include <c-ctype.h>
 #include <quote.h>
+#include <vasnprintf.h>
 
 #include "complain.h"
 #include "conflicts.h"
@@ -40,7 +42,7 @@ static void prepare_percent_define_front_end_variables (void);
 static void check_and_convert_grammar (void);
 
 static symbol_list *grammar = NULL;
-static bool start_flag = false;
+symbol_list *start_symbols = NULL;
 merger_list *merge_functions;
 
 /* Was %union seen?  */
@@ -54,16 +56,9 @@ bool default_prec = true;
 `-----------------------*/
 
 void
-grammar_start_symbol_set (symbol *sym, location loc)
+grammar_start_symbols_set (symbol_list *syms)
 {
-  if (start_flag)
-    complain (&loc, complaint, _("multiple %s declarations"), "%start");
-  else
-    {
-      start_flag = true;
-      startsymbol = sym;
-      startsymbol_loc = loc;
-    }
+  start_symbols = symbol_list_append (start_symbols, syms);
 }
 
 
@@ -791,6 +786,95 @@ create_start_rule (symbol *swtok, symbol *start)
   grammar = initial_rule;
 }
 
+/* Fetch (or create) a token "YY_PARSE_foo" for start symbol "foo".
+
+   We don't use the simple "YY_FOO" because (i) we might get clashes
+   with some of our symbols (e.g., cast => YY_CAST), and (ii) upcasing
+   introduces possible clashes between terminal FOO and nonterminal
+   foo.  */
+symbol *
+switching_token (const symbol *start)
+{
+  char buf[100];
+  size_t len = sizeof buf;
+  char *name
+    = asnprintf (buf, &len,
+                 "YY_PARSE_%s", start->alias ? start->alias->tag : start->tag);
+  if (!name)
+    xalloc_die ();
+  // Setting the location ensures deterministic symbol numbers.
+  symbol *res = symbol_get (name, start->location);
+  if (name != buf)
+    free (name);
+  symbol_class_set (res, token_sym, start->location, false);
+  return res;
+}
+
+/* Create the start rules in reverse order, since they are inserted at
+   the top of the grammar.  That way the rules follow the order of
+   declaration to %start.  */
+
+static void
+create_multiple_start_rules (symbol_list *start_syms)
+{
+  if (start_syms)
+    {
+      create_multiple_start_rules (start_syms->next);
+      assert (start_syms->content_type == SYMLIST_SYMBOL);
+      symbol *start = start_syms->content.sym;
+      symbol *swtok = switching_token (start);
+      create_start_rule (swtok, start);
+    }
+}
+
+/* For each start symbol "foo", create the rule "$accept: YY_FOO
+   foo $end". */
+static void
+create_start_rules (void)
+{
+  if (!start_symbols)
+    {
+      symbol *start = find_start_symbol ();
+      start_symbols = symbol_list_sym_new (start, start->location);
+    }
+
+  const bool several = start_symbols->next;
+  if (several)
+    create_multiple_start_rules (start_symbols);
+  else
+    {
+      symbol *start = start_symbols->content.sym;
+      create_start_rule (NULL, start);
+    }
+}
+
+static void
+check_start_symbols (void)
+{
+  // Sanity checks on the start symbols.
+  for (symbol_list *list = start_symbols; list; list = list->next)
+    {
+      const symbol *start = list->content.sym;
+      if (start->content->class == unknown_sym)
+        {
+          complain (&start->location, complaint,
+                    _("the start symbol %s is undefined"),
+                    start->tag);
+          // I claim this situation is unreachable.  This is caught
+          // before, and we get "symbol 'foo' is used, but is not
+          // defined as a token and has no rules".
+          abort ();
+        }
+      if (start->content->class == token_sym)
+        complain (&start->location, complaint,
+                  _("the start symbol %s is a token"),
+                  start->tag);
+    }
+  if (complaint_status == status_complaint)
+    exit (EXIT_FAILURE);
+}
+
+
 /*-------------------------------------------------------------.
 | Check the grammar that has just been read, and convert it to |
 | internal form.                                               |
@@ -818,19 +902,12 @@ check_and_convert_grammar (void)
       }
     }
 
+  /* Insert the initial rule(s).  */
+  create_start_rules ();
+
   /* Report any undefined symbols and consider them nonterminals.  */
   symbols_check_defined ();
 
-  /* Find the start symbol if no %start.  */
-  if (!start_flag)
-    {
-      symbol *start = find_start_symbol ();
-      grammar_start_symbol_set (start, start->location);
-    }
-
-  /* Insert the initial rule.  */
-  create_start_rule (NULL, startsymbol);
-
   if (SYMBOL_NUMBER_MAXIMUM - nnterms < ntokens)
     complain (NULL, fatal, "too many symbols in input grammar (limit is %d)",
               SYMBOL_NUMBER_MAXIMUM);
@@ -840,6 +917,8 @@ check_and_convert_grammar (void)
   /* Assign the symbols their symbol numbers.  */
   symbols_pack ();
 
+  check_start_symbols ();
+
   /* Scan rule actions after invoking symbol_check_alias_consistency
      (in symbols_pack above) so that token types are set correctly
      before the rule action type checking.
