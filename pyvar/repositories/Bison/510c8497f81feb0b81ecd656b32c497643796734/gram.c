@@ -47,25 +47,25 @@ symbol_number *token_translations = NULL;
 int max_user_token_number = 256;
 
 bool
-rule_useful_in_grammar_p (rule *r)
+rule_useful_in_grammar_p (rule const *r)
 {
   return r->number < nrules;
 }
 
 bool
-rule_useless_in_grammar_p (rule *r)
+rule_useless_in_grammar_p (rule const *r)
 {
   return !rule_useful_in_grammar_p (r);
 }
 
 bool
-rule_useless_in_parser_p (rule *r)
+rule_useless_in_parser_p (rule const *r)
 {
   return !r->useful && rule_useful_in_grammar_p (r);
 }
 
 void
-rule_lhs_print (rule *r, symbol *previous_lhs, FILE *out)
+rule_lhs_print (rule const *r, symbol const *previous_lhs, FILE *out)
 {
   fprintf (out, "  %3d ", r->number);
   if (previous_lhs != r->lhs)
@@ -82,13 +82,13 @@ rule_lhs_print (rule *r, symbol *previous_lhs, FILE *out)
 }
 
 void
-rule_lhs_print_xml (rule *r, FILE *out, int level)
+rule_lhs_print_xml (rule const *r, FILE *out, int level)
 {
   xml_printf (out, level, "<lhs>%s</lhs>", r->lhs->tag);
 }
 
 size_t
-rule_rhs_length (rule *r)
+rule_rhs_length (rule const *r)
 {
   size_t res = 0;
   item_number *rhsp;
@@ -98,7 +98,7 @@ rule_rhs_length (rule *r)
 }
 
 void
-rule_rhs_print (rule *r, FILE *out)
+rule_rhs_print (rule const *r, FILE *out)
 {
   if (*r->rhs >= 0)
     {
@@ -113,7 +113,7 @@ rule_rhs_print (rule *r, FILE *out)
 }
 
 static void
-rule_rhs_print_xml (rule *r, FILE *out, int level)
+rule_rhs_print_xml (rule const *r, FILE *out, int level)
 {
   if (*r->rhs >= 0)
     {
@@ -133,7 +133,7 @@ rule_rhs_print_xml (rule *r, FILE *out, int level)
 }
 
 static void
-rule_print (rule *r, FILE *out)
+rule_print (rule const *r, FILE *out)
 {
   fprintf (out, "%s:", r->lhs->tag);
   rule_rhs_print (r, out);
@@ -263,10 +263,12 @@ grammar_dump (FILE *out, const char *title)
   fprintf (out, "Rules\n-----\n\n");
   {
     rule_number i;
-    fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
+    fprintf (out,
+             "Num (Prec, Assoc, Useful, Ritem Range) Lhs"
+             " -> Rhs (Ritem range) [Num]\n");
     for (i = 0; i < nrules + nuseless_productions; i++)
       {
-        rule *rule_i = &rules[i];
+        rule const *rule_i = &rules[i];
         item_number *rp = NULL;
         unsigned int rhs_itemno = rule_i->rhs - ritem;
         unsigned int rhs_count = 0;
