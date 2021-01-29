@@ -1,5 +1,5 @@
 /* Match rules with nonterminals for bison,
-   Copyright 1984, 1989, 2000, 2001  Free Software Foundation, Inc.
+   Copyright 1984, 1989, 2000, 2001, 2002  Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -27,7 +27,7 @@
 #include "gram.h"
 #include "derives.h"
 
-short **derives = NULL;
+rule_number_t **derives = NULL;
 
 static void
 print_derives (void)
@@ -38,15 +38,16 @@ print_derives (void)
 
   for (i = ntokens; i < nsyms; i++)
     {
-      short *sp;
+      rule_number_t *rp;
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
-      for (sp = derives[i]; *sp > 0; sp++)
+      for (rp = derives[i]; *rp > 0; rp++)
 	{
 	  item_number_t *rhsp;
-	  fprintf (stderr, "\t\t%d:", *sp);
-	  for (rhsp = rules[*sp].rhs; *rhsp >= 0; ++rhsp)
-	    fprintf (stderr, " %s", symbols[*rhsp]->tag);
-	  fprintf (stderr, " (rule %d)\n", -*rhsp - 1);
+	  fprintf (stderr, "\t\t%d:", *rp);
+	  for (rhsp = rules[*rp].rhs; *rhsp >= 0; ++rhsp)
+	    fprintf (stderr, " %s", symbol_tag_get (symbols[*rhsp]));
+	  fprintf (stderr, " (rule %d)\n",
+		   rule_number_of_item_number (*rhsp) - 1);
 	}
     }
 
@@ -57,9 +58,10 @@ print_derives (void)
 void
 set_derives (void)
 {
-  int i;
+  symbol_number_t i;
+  rule_number_t r;
   shorts *p;
-  short *q;
+  rule_number_t *q;
   shorts **dset;
   shorts *delts;
 
@@ -67,17 +69,17 @@ set_derives (void)
   delts = XCALLOC (shorts, nrules + 1);
 
   p = delts;
-  for (i = nrules; i > 0; i--)
+  for (r = nrules; r > 0; r--)
     {
-      symbol_number_t lhs = rules[i].lhs->number;
+      symbol_number_t lhs = rules[r].lhs->number;
       p->next = dset[lhs];
-      p->value = i;
+      p->value = r;
       dset[lhs] = p;
       p++;
     }
 
-  derives = XCALLOC (short *, nvars) - ntokens;
-  q = XCALLOC (short, nvars + nrules);
+  derives = XCALLOC (rule_number_t *, nvars) - ntokens;
+  q = XCALLOC (short, nvars + int_of_rule_number (nrules));
 
   for (i = ntokens; i < nsyms; i++)
     {
