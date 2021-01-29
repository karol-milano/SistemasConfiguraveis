@@ -32,7 +32,7 @@
 /* Comments for these variables are in gram.h.  */
 
 item_number *ritem = NULL;
-unsigned nritems = 0;
+int nritems = 0;
 
 rule *rules = NULL;
 rule_number nrules = 0;
@@ -165,7 +165,7 @@ void
 ritem_print (FILE *out)
 {
   fputs ("RITEM\n", out);
-  for (unsigned i = 0; i < nritems; ++i)
+  for (int i = 0; i < nritems; ++i)
     if (ritem[i] >= 0)
       fprintf (out, "  %s", symbols[ritem[i]]->tag);
     else
@@ -280,8 +280,8 @@ grammar_dump (FILE *out, const char *title)
     for (rule_number i = 0; i < nrules + nuseless_productions; ++i)
       {
         rule const *rule_i = &rules[i];
-        unsigned const rhs_itemno = rule_i->rhs - ritem;
-        unsigned length = rule_rhs_length (rule_i);
+        int const rhs_itemno = rule_i->rhs - ritem;
+        int length = rule_rhs_length (rule_i);
         aver (item_number_as_rule_number (rule_i->rhs[length] == i));
         fprintf (out, "%3d (%2d, %2d, %2s, %2s)   %2d -> (%2u-%2u)",
                  i,
