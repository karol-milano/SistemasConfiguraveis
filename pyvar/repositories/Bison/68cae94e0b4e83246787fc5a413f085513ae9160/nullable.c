@@ -1,7 +1,7 @@
 /* Calculate which nonterminals can expand into the null string for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2003, 2004, 2005 Free
-   Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2003, 2004, 2005, 2006
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -104,8 +104,8 @@ nullable_compute (void)
 	else
 	  {
 	    /* This rule has an empty RHS. */
-	    if (item_number_as_rule_number (rules_ruleno->rhs[0]) != ruleno)
-	      abort ();
+	    assert (item_number_as_rule_number (rules_ruleno->rhs[0])
+		    == ruleno);
 	    if (rules_ruleno->useful
 		&& ! nullable[rules_ruleno->lhs->number - ntokens])
 	      {
