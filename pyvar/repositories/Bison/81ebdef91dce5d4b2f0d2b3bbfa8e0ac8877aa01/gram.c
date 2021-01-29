@@ -20,26 +20,28 @@
 
 
 #include "system.h"
-#include "quotearg.h"
-#include "symtab.h"
+
+#include <quotearg.h>
+
 #include "gram.h"
-#include "reduce.h"
 #include "reader.h"
+#include "reduce.h"
+#include "symtab.h"
 
 /* Comments for these variables are in gram.h.  */
 
-item_number_t *ritem = NULL;
+item_number *ritem = NULL;
 unsigned int nritems = 0;
 
-rule_t *rules = NULL;
-rule_number_t nrules = 0;
+rule *rules = NULL;
+rule_number nrules = 0;
 
-symbol_t **symbols = NULL;
+symbol **symbols = NULL;
 int nsyms = 0;
 int ntokens = 1;
 int nvars = 0;
 
-symbol_number_t *token_translations = NULL;
+symbol_number *token_translations = NULL;
 
 int max_user_token_number = 256;
 
@@ -52,7 +54,7 @@ int pure_parser = 0;
 `--------------------------------------------------------------*/
 
 bool
-rule_useful_p (rule_t *r)
+rule_useful_p (rule *r)
 {
   return r->number < nrules;
 }
@@ -63,7 +65,7 @@ rule_useful_p (rule_t *r)
 `-------------------------------------------------------------*/
 
 bool
-rule_useless_p (rule_t *r)
+rule_useless_p (rule *r)
 {
   return r->number >= nrules;
 }
@@ -75,7 +77,7 @@ rule_useless_p (rule_t *r)
 `--------------------------------------------------------------------*/
 
 bool
-rule_never_reduced_p (rule_t *r)
+rule_never_reduced_p (rule *r)
 {
   return !r->useful && r->number < nrules;
 }
@@ -88,12 +90,12 @@ rule_never_reduced_p (rule_t *r)
 `----------------------------------------------------------------*/
 
 void
-rule_lhs_print (rule_t *rule, symbol_t *previous_lhs, FILE *out)
+rule_lhs_print (rule *r, symbol *previous_lhs, FILE *out)
 {
-  fprintf (out, "  %3d ", rule->number);
-  if (previous_lhs != rule->lhs)
+  fprintf (out, "  %3d ", r->number);
+  if (previous_lhs != r->lhs)
     {
-      fprintf (out, "%s:", rule->lhs->tag);
+      fprintf (out, "%s:", r->lhs->tag);
     }
   else
     {
@@ -110,28 +112,28 @@ rule_lhs_print (rule_t *rule, symbol_t *previous_lhs, FILE *out)
 `--------------------------------------*/
 
 int
-rule_rhs_length (rule_t *rule)
+rule_rhs_length (rule *r)
 {
   int res = 0;
-  item_number_t *rhsp;
-  for (rhsp = rule->rhs; *rhsp >= 0; ++rhsp)
+  item_number *rhsp;
+  for (rhsp = r->rhs; *rhsp >= 0; ++rhsp)
     ++res;
   return res;
 }
 
 
 /*-------------------------------.
-| Print this RULE's RHS on OUT.  |
+| Print this rule's RHS on OUT.  |
 `-------------------------------*/
 
 void
-rule_rhs_print (rule_t *rule, FILE *out)
+rule_rhs_print (rule *r, FILE *out)
 {
-  if (*rule->rhs >= 0)
+  if (*r->rhs >= 0)
     {
-      item_number_t *r;
-      for (r = rule->rhs; *r >= 0; r++)
-	fprintf (out, " %s", symbols[*r]->tag);
+      item_number *rp;
+      for (rp = r->rhs; *rp >= 0; rp++)
+	fprintf (out, " %s", symbols[*rp]->tag);
       fputc ('\n', out);
     }
   else
@@ -142,14 +144,14 @@ rule_rhs_print (rule_t *rule, FILE *out)
 
 
 /*-------------------------.
-| Print this RULE on OUT.  |
+| Print this rule on OUT.  |
 `-------------------------*/
 
 void
-rule_print (rule_t *rule, FILE *out)
+rule_print (rule *r, FILE *out)
 {
-  fprintf (out, "%s:", rule->lhs->tag);
-  rule_rhs_print (rule, out);
+  fprintf (out, "%s:", r->lhs->tag);
+  rule_rhs_print (r, out);
 }
 
 
@@ -179,7 +181,7 @@ size_t
 ritem_longest_rhs (void)
 {
   int max = 0;
-  rule_number_t r;
+  rule_number r;
 
   for (r = 0; r < nrules; ++r)
     {
@@ -198,11 +200,11 @@ ritem_longest_rhs (void)
 
 void
 grammar_rules_partial_print (FILE *out, const char *title,
-			     rule_filter_t filter)
+			     rule_filter filter)
 {
   int r;
   bool first = true;
-  symbol_t *previous_lhs = NULL;
+  symbol *previous_lhs = NULL;
 
   /* rule # : LHS -> RHS */
   for (r = 0; r < nrules + nuseless_productions; r++)
@@ -249,7 +251,7 @@ grammar_dump (FILE *out, const char *title)
 
   fprintf (out, "Variables\n---------\n\n");
   {
-    symbol_number_t i;
+    symbol_number i;
     fprintf (out, "Value  Sprec  Sassoc  Tag\n");
 
     for (i = ntokens; i < nsyms; i++)
@@ -262,27 +264,27 @@ grammar_dump (FILE *out, const char *title)
 
   fprintf (out, "Rules\n-----\n\n");
   {
-    rule_number_t i;
+    rule_number i;
     fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
     for (i = 0; i < nrules + nuseless_productions; i++)
       {
-	rule_t *rule = &rules[i];
-	item_number_t *r = NULL;
-	unsigned int rhs_itemno = rule->rhs - ritem;
+	rule *rule_i = &rules[i];
+	item_number *r = NULL;
+	unsigned int rhs_itemno = rule_i->rhs - ritem;
   	unsigned int rhs_count = 0;
 	/* Find the last RHS index in ritems. */
-	for (r = rule->rhs; *r >= 0; ++r)
+	for (r = rule_i->rhs; *r >= 0; ++r)
 	  ++rhs_count;
 	fprintf (out, "%3d (%2d, %2d, %2d, %2u-%2u)   %2d ->",
 		 i,
-		 rule->prec ? rule->prec->prec : 0,
-		 rule->prec ? rule->prec->assoc : 0,
-		 rule->useful,
+		 rule_i->prec ? rule_i->prec->prec : 0,
+		 rule_i->prec ? rule_i->prec->assoc : 0,
+		 rule_i->useful,
 		 rhs_itemno,
 		 rhs_itemno + rhs_count - 1,
-		 rule->lhs->number);
+		 rule_i->lhs->number);
 	/* Dumped the RHS. */
-	for (r = rule->rhs; *r >= 0; r++)
+	for (r = rule_i->rhs; *r >= 0; r++)
 	  fprintf (out, " %3d", *r);
 	fprintf (out, "  [%d]\n", item_number_as_rule_number (*r));
       }
@@ -291,7 +293,7 @@ grammar_dump (FILE *out, const char *title)
 
   fprintf (out, "Rules interpreted\n-----------------\n\n");
   {
-    rule_number_t r;
+    rule_number r;
     for (r = 0; r < nrules + nuseless_productions; r++)
       {
 	fprintf (out, "%-5d  ", r);
@@ -312,7 +314,7 @@ grammar_dump (FILE *out, const char *title)
 void
 grammar_rules_never_reduced_report (const char *message)
 {
-  rule_number_t r;
+  rule_number r;
   for (r = 0; r < nrules ; ++r)
     if (!rules[r].useful)
       {
