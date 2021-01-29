@@ -237,27 +237,28 @@ grammar_dump (FILE *out, const char *title)
 
   fprintf (out, "Rules\n-----\n\n");
   {
+    /* Reduced number, then original number in the sources.  */
     fprintf (out,
-             "Num (Prec, Assoc, Useful, Ritem Range) Lhs"
-             " -> Rhs (Ritem range) [Num]\n");
-    for (rule_number i = 0; i < nrules + nuseless_productions; i++)
+             "Num (Num, Prec, Assoc, Useful, UselessChain, Ritem Range)"
+             " Lhs -> Rhs (Ritem range)\n");
+    for (rule_number i = 0; i < nrules + nuseless_productions; ++i)
       {
         rule const *rule_i = &rules[i];
         unsigned const rhs_itemno = rule_i->rhs - ritem;
         unsigned length = rule_rhs_length (rule_i);
-        fprintf (out, "%3d (%2d, %2d, %2d, %2u-%2u)   %2d ->",
+        fprintf (out, "%3d (%3d, %2d, %2d, %2s, %2u-%2u)   %2d ->",
+                 item_number_as_rule_number (rule_i->rhs[length]),
                  i,
                  rule_i->prec ? rule_i->prec->prec : 0,
                  rule_i->prec ? rule_i->prec->assoc : 0,
-                 rule_i->useful,
+                 rule_i->useful ? "t" : "f",
                  rhs_itemno,
                  rhs_itemno + length - 1,
                  rule_i->lhs->number);
         /* Dumped the RHS. */
         for (item_number *rhsp = rule_i->rhs; 0 <= *rhsp; ++rhsp)
           fprintf (out, " %3d", *rhsp);
-        fprintf (out, "  [%d]\n",
-                 item_number_as_rule_number (rule_i->rhs[length+1]));
+        fputc ('\n', out);
       }
   }
   fprintf (out, "\n\n");
