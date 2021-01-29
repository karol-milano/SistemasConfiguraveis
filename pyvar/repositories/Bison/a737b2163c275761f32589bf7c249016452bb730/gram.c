@@ -1,6 +1,7 @@
 /* Allocate input grammar variables for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2001, 2002, 2003 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -203,7 +204,7 @@ void
 grammar_rules_partial_print (FILE *out, const char *title,
 			     rule_filter filter)
 {
-  int r;
+  rule_number r;
   bool first = true;
   symbol *previous_lhs = NULL;
 
@@ -270,11 +271,11 @@ grammar_dump (FILE *out, const char *title)
     for (i = 0; i < nrules + nuseless_productions; i++)
       {
 	rule *rule_i = &rules[i];
-	item_number *r = NULL;
+	item_number *rp = NULL;
 	unsigned int rhs_itemno = rule_i->rhs - ritem;
   	unsigned int rhs_count = 0;
 	/* Find the last RHS index in ritems. */
-	for (r = rule_i->rhs; *r >= 0; ++r)
+	for (rp = rule_i->rhs; *rp >= 0; ++rp)
 	  ++rhs_count;
 	fprintf (out, "%3d (%2d, %2d, %2d, %2u-%2u)   %2d ->",
 		 i,
@@ -285,9 +286,9 @@ grammar_dump (FILE *out, const char *title)
 		 rhs_itemno + rhs_count - 1,
 		 rule_i->lhs->number);
 	/* Dumped the RHS. */
-	for (r = rule_i->rhs; *r >= 0; r++)
-	  fprintf (out, " %3d", *r);
-	fprintf (out, "  [%d]\n", item_number_as_rule_number (*r));
+	for (rp = rule_i->rhs; *rp >= 0; rp++)
+	  fprintf (out, " %3d", *rp);
+	fprintf (out, "  [%d]\n", item_number_as_rule_number (*rp));
       }
   }
   fprintf (out, "\n\n");
