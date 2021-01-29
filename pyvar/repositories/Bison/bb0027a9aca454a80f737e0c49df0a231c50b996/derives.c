@@ -1,5 +1,5 @@
 /* Match rules with nonterminals for bison,
-   Copyright 1984, 1989, 2000, 2001, 2002  Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002  Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -30,10 +30,10 @@
 typedef struct rule_list_s
 {
   struct rule_list_s *next;
-  rule_number_t value;
+  rule_t *value;
 } rule_list_t;
 
-rule_number_t **derives = NULL;
+rule_t ***derives = NULL;
 
 static void
 print_derives (void)
@@ -44,12 +44,12 @@ print_derives (void)
 
   for (i = ntokens; i < nsyms; i++)
     {
-      rule_number_t *rp;
+      rule_t **rp;
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
-      for (rp = derives[i]; *rp >= 0; rp++)
+      for (rp = derives[i]; *rp; ++rp)
 	{
-	  fprintf (stderr, "\t\t%3d ", *rp);
-	  rule_rhs_print (&rules[*rp], stderr);
+	  fprintf (stderr, "\t\t%3d ", (*rp)->user_number);
+	  rule_rhs_print (*rp, stderr);
 	}
     }
 
@@ -58,11 +58,11 @@ print_derives (void)
 
 
 void
-set_derives (void)
+derives_compute (void)
 {
   symbol_number_t i;
   int r;
-  rule_number_t *q;
+  rule_t **q;
 
   /* DSET[NTERM] -- A linked list of the numbers of the rules whose
      LHS is NTERM.  */
@@ -79,15 +79,15 @@ set_derives (void)
       rule_list_t *p = &delts[r];
       /* A new LHS is found.  */
       p->next = dset[lhs];
-      p->value = r;
+      p->value = &rules[r];
       dset[lhs] = p;
     }
 
   /* DSET contains what we need under the form of a linked list.  Make
      it a single array.  */
 
-  derives = XCALLOC (rule_number_t *, nvars) - ntokens;
-  q = XCALLOC (rule_number_t, nvars + int_of_rule_number (nrules));
+  derives = XCALLOC (rule_t **, nvars) - ntokens;
+  q = XCALLOC (rule_t *, nvars + int_of_rule_number (nrules));
 
   for (i = ntokens; i < nsyms; i++)
     {
@@ -98,7 +98,7 @@ set_derives (void)
 	  *q++ = p->value;
 	  p = p->next;
 	}
-      *q++ = -1;
+      *q++ = NULL;
     }
 
   if (trace_flag & trace_sets)
@@ -110,7 +110,7 @@ set_derives (void)
 
 
 void
-free_derives (void)
+derives_free (void)
 {
   XFREE (derives[ntokens]);
   XFREE (derives + ntokens);
