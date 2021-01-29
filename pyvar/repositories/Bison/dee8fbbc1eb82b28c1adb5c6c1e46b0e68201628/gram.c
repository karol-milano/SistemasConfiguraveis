@@ -274,25 +274,23 @@ grammar_dump (FILE *out, const char *title)
 
   fprintf (out, "Rules\n-----\n\n");
   {
-    /* Reduced number, then original number in the sources.  */
     fprintf (out,
-             "Num (Num, Prec, Assoc, Useful, UselessChain, Ritem Range)"
-             " Lhs -> Rhs (Ritem range)\n");
+             "Num (Prec, Assoc, Useful, UselessChain) Lhs"
+             " -> (Ritem Range) Rhs\n");
     for (rule_number i = 0; i < nrules + nuseless_productions; ++i)
       {
         rule const *rule_i = &rules[i];
         unsigned const rhs_itemno = rule_i->rhs - ritem;
         unsigned length = rule_rhs_length (rule_i);
-        fprintf (out, "%3d (%3d, %2d, %2d, %2s, %2s, %2u-%2u)   %2d ->",
-                 item_number_as_rule_number (rule_i->rhs[length]),
+        aver (item_number_as_rule_number (rule_i->rhs[length] == i));
+        fprintf (out, "%3d (%2d, %2d, %2s, %2s)   %2d -> (%2u-%2u)",
                  i,
                  rule_i->prec ? rule_i->prec->prec : 0,
                  rule_i->prec ? rule_i->prec->assoc : 0,
                  rule_i->useful ? "t" : "f",
                  rule_useless_chain_p (rule_i) ? "t" : "f",
-                 rhs_itemno,
-                 rhs_itemno + length - 1,
-                 rule_i->lhs->number);
+                 rule_i->lhs->number,
+                 rhs_itemno, rhs_itemno + length - 1);
         /* Dumped the RHS. */
         for (item_number *rhsp = rule_i->rhs; 0 <= *rhsp; ++rhsp)
           fprintf (out, " %3d", *rhsp);
