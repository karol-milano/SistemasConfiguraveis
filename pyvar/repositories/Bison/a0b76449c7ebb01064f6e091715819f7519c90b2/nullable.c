@@ -24,18 +24,19 @@
    do so.  */
 
 #include "system.h"
+
 #include "getargs.h"
-#include "symtab.h"
 #include "gram.h"
-#include "reduce.h"
 #include "nullable.h"
+#include "reduce.h"
+#include "symtab.h"
 
 /* Linked list of rules.  */
-typedef struct rule_list_s
+typedef struct rule_list
 {
-  struct rule_list_s *next;
-  rule_t *value;
-} rule_list_t;
+  struct rule_list *next;
+  rule *value;
+} rule_list;
 
 bool *nullable = NULL;
 
@@ -52,19 +53,19 @@ nullable_print (FILE *out)
 void
 nullable_compute (void)
 {
-  rule_number_t ruleno;
-  symbol_number_t *s1;
-  symbol_number_t *s2;
-  rule_list_t *p;
+  rule_number ruleno;
+  symbol_number *s1;
+  symbol_number *s2;
+  rule_list *p;
 
-  symbol_number_t *squeue = XCALLOC (symbol_number_t, nvars);
+  symbol_number *squeue = XCALLOC (symbol_number, nvars);
   short *rcount = XCALLOC (short, nrules);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
-  rule_list_t **rsets = XCALLOC (rule_list_t *, nvars) - ntokens;
+  rule_list **rsets = XCALLOC (rule_list *, nvars) - ntokens;
   /* This is said to be more elements than we actually use.
      Supposedly NRITEMS - NRULES is enough.  But why take the risk?  */
-  rule_list_t *relts = XCALLOC (rule_list_t, nritems + nvars + 1);
+  rule_list *relts = XCALLOC (rule_list, nritems + nvars + 1);
 
   nullable = XCALLOC (bool, nvars) - ntokens;
 
@@ -74,24 +75,24 @@ nullable_compute (void)
   for (ruleno = 0; ruleno < nrules; ++ruleno)
     if (rules[ruleno].useful)
       {
-	rule_t *rule = &rules[ruleno];
-	if (rule->rhs[0] >= 0)
+	rule *rules_ruleno = &rules[ruleno];
+	if (rules_ruleno->rhs[0] >= 0)
 	  {
 	    /* This rule has a non empty RHS. */
-	    item_number_t *r = NULL;
+	    item_number *r = NULL;
 	    int any_tokens = 0;
-	    for (r = rule->rhs; *r >= 0; ++r)
+	    for (r = rules_ruleno->rhs; *r >= 0; ++r)
 	      if (ISTOKEN (*r))
 		any_tokens = 1;
 
 	    /* This rule has only nonterminals: schedule it for the second
 	       pass.  */
 	    if (!any_tokens)
-	      for (r = rule->rhs; *r >= 0; ++r)
+	      for (r = rules_ruleno->rhs; *r >= 0; ++r)
 		{
 		  rcount[ruleno]++;
 		  p->next = rsets[*r];
-		  p->value = rule;
+		  p->value = rules_ruleno;
 		  rsets[*r] = p;
 		  p++;
 		}
@@ -99,12 +100,12 @@ nullable_compute (void)
 	else
 	  {
 	    /* This rule has an empty RHS. */
-	    if (item_number_as_rule_number (rule->rhs[0]) != ruleno)
+	    if (item_number_as_rule_number (rules_ruleno->rhs[0]) != ruleno)
 	      abort ();
-	    if (rule->useful && !nullable[rule->lhs->number])
+	    if (rules_ruleno->useful && !nullable[rules_ruleno->lhs->number])
 	      {
-		nullable[rule->lhs->number] = 1;
-		*s2++ = rule->lhs->number;
+		nullable[rules_ruleno->lhs->number] = 1;
+		*s2++ = rules_ruleno->lhs->number;
 	      }
 	  }
       }
@@ -112,12 +113,12 @@ nullable_compute (void)
   while (s1 < s2)
     for (p = rsets[*s1++]; p; p = p->next)
       {
-	rule_t *rule = p->value;
-	if (--rcount[rule->number] == 0)
-	  if (rule->useful && !nullable[rule->lhs->number])
+	rule *r = p->value;
+	if (--rcount[r->number] == 0)
+	  if (r->useful && !nullable[r->lhs->number])
 	    {
-	      nullable[rule->lhs->number] = 1;
-	      *s2++ = rule->lhs->number;
+	      nullable[r->lhs->number] = 1;
+	      *s2++ = r->lhs->number;
 	    }
       }
 
