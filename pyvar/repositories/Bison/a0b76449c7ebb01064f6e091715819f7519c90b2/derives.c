@@ -1,5 +1,7 @@
 /* Match rules with nonterminals for bison,
-   Copyright (C) 1984, 1989, 2000, 2001, 2002  Free Software Foundation, Inc.
+
+   Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -20,20 +22,22 @@
 
 
 #include "system.h"
+
 #include "getargs.h"
-#include "symtab.h"
-#include "reader.h"
-#include "gram.h"
+
 #include "derives.h"
+#include "gram.h"
+#include "reader.h"
+#include "symtab.h"
 
 /* Linked list of rule numbers.  */
-typedef struct rule_list_s
+typedef struct rule_list
 {
-  struct rule_list_s *next;
-  rule_t *value;
-} rule_list_t;
+  struct rule_list *next;
+  rule *value;
+} rule_list;
 
-rule_t ***derives = NULL;
+rule ***derives = NULL;
 
 static void
 print_derives (void)
@@ -44,7 +48,7 @@ print_derives (void)
 
   for (i = ntokens; i < nsyms; i++)
     {
-      rule_t **rp;
+      rule **rp;
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       for (rp = derives[i]; *rp; ++rp)
 	{
@@ -60,23 +64,23 @@ print_derives (void)
 void
 derives_compute (void)
 {
-  symbol_number_t i;
+  symbol_number i;
   int r;
-  rule_t **q;
+  rule **q;
 
   /* DSET[NTERM] -- A linked list of the numbers of the rules whose
      LHS is NTERM.  */
-  rule_list_t **dset = XCALLOC (rule_list_t *, nvars) - ntokens;
+  rule_list **dset = XCALLOC (rule_list *, nvars) - ntokens;
 
   /* DELTS[RULE] -- There are NRULES rule number to attach to nterms.
      Instead of performing NRULES allocations for each, have an array
      indexed by rule numbers.  */
-  rule_list_t *delts = XCALLOC (rule_list_t, nrules);
+  rule_list *delts = XCALLOC (rule_list, nrules);
 
   for (r = nrules - 1; r >= 0; --r)
     {
-      symbol_number_t lhs = rules[r].lhs->number;
-      rule_list_t *p = &delts[r];
+      symbol_number lhs = rules[r].lhs->number;
+      rule_list *p = &delts[r];
       /* A new LHS is found.  */
       p->next = dset[lhs];
       p->value = &rules[r];
@@ -86,12 +90,12 @@ derives_compute (void)
   /* DSET contains what we need under the form of a linked list.  Make
      it a single array.  */
 
-  derives = XCALLOC (rule_t **, nvars) - ntokens;
-  q = XCALLOC (rule_t *, nvars + int_of_rule_number (nrules));
+  derives = XCALLOC (rule **, nvars) - ntokens;
+  q = XCALLOC (rule *, nvars + int_of_rule_number (nrules));
 
   for (i = ntokens; i < nsyms; i++)
     {
-      rule_list_t *p = dset[i];
+      rule_list *p = dset[i];
       derives[i] = q;
       while (p)
 	{
