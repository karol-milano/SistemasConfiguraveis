@@ -1,4 +1,5 @@
-/* Part of the bison parser generator,
+/* Calculate which nonterminals can expand into the null string for Bison.
+
    Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -46,7 +47,8 @@ nullable_print (FILE *out)
   int i;
   fputs ("NULLABLE\n", out);
   for (i = ntokens; i < nsyms; i++)
-    fprintf (out, "\t%s: %s\n", symbols[i]->tag, nullable[i] ? "yes" : "no");
+    fprintf (out, "\t%s: %s\n", symbols[i]->tag,
+	     nullable[i - ntokens] ? "yes" : "no");
   fputs ("\n\n", out);
 }
 
@@ -58,16 +60,16 @@ nullable_compute (void)
   symbol_number *s2;
   rule_list *p;
 
-  symbol_number *squeue = XCALLOC (symbol_number, nvars);
-  short *rcount = XCALLOC (short, nrules);
+  symbol_number *squeue = CALLOC (squeue, nvars);
+  short *rcount = CALLOC (rcount, nrules);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
-  rule_list **rsets = XCALLOC (rule_list *, nvars) - ntokens;
+  rule_list **rsets = CALLOC (rsets, nvars);
   /* This is said to be more elements than we actually use.
      Supposedly NRITEMS - NRULES is enough.  But why take the risk?  */
-  rule_list *relts = XCALLOC (rule_list, nritems + nvars + 1);
+  rule_list *relts = CALLOC (relts, nritems + nvars + 1);
 
-  nullable = XCALLOC (bool, nvars) - ntokens;
+  CALLOC (nullable, nvars);
 
   s1 = s2 = squeue;
   p = relts;
@@ -91,9 +93,9 @@ nullable_compute (void)
 	      for (r = rules_ruleno->rhs; *r >= 0; ++r)
 		{
 		  rcount[ruleno]++;
-		  p->next = rsets[*r];
+		  p->next = rsets[*r - ntokens];
 		  p->value = rules_ruleno;
-		  rsets[*r] = p;
+		  rsets[*r - ntokens] = p;
 		  p++;
 		}
 	  }
@@ -102,29 +104,30 @@ nullable_compute (void)
 	    /* This rule has an empty RHS. */
 	    if (item_number_as_rule_number (rules_ruleno->rhs[0]) != ruleno)
 	      abort ();
-	    if (rules_ruleno->useful && !nullable[rules_ruleno->lhs->number])
+	    if (rules_ruleno->useful
+		&& ! nullable[rules_ruleno->lhs->number - ntokens])
 	      {
-		nullable[rules_ruleno->lhs->number] = 1;
+		nullable[rules_ruleno->lhs->number - ntokens] = 1;
 		*s2++ = rules_ruleno->lhs->number;
 	      }
 	  }
       }
 
   while (s1 < s2)
-    for (p = rsets[*s1++]; p; p = p->next)
+    for (p = rsets[*s1++ - ntokens]; p; p = p->next)
       {
 	rule *r = p->value;
 	if (--rcount[r->number] == 0)
-	  if (r->useful && !nullable[r->lhs->number])
+	  if (r->useful && ! nullable[r->lhs->number - ntokens])
 	    {
-	      nullable[r->lhs->number] = 1;
+	      nullable[r->lhs->number - ntokens] = 1;
 	      *s2++ = r->lhs->number;
 	    }
       }
 
   XFREE (squeue);
   XFREE (rcount);
-  XFREE (rsets + ntokens);
+  XFREE (rsets);
   XFREE (relts);
 
   if (trace_flag & trace_sets)
@@ -135,5 +138,5 @@ nullable_compute (void)
 void
 nullable_free (void)
 {
-  XFREE (nullable + ntokens);
+  XFREE (nullable);
 }
