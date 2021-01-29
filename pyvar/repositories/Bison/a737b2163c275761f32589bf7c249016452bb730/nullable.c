@@ -1,6 +1,7 @@
 /* Calculate which nonterminals can expand into the null string for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2003 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -81,21 +82,21 @@ nullable_compute (void)
 	if (rules_ruleno->rhs[0] >= 0)
 	  {
 	    /* This rule has a non empty RHS. */
-	    item_number *r = NULL;
+	    item_number *rp = NULL;
 	    int any_tokens = 0;
-	    for (r = rules_ruleno->rhs; *r >= 0; ++r)
-	      if (ISTOKEN (*r))
+	    for (rp = rules_ruleno->rhs; *rp >= 0; ++rp)
+	      if (ISTOKEN (*rp))
 		any_tokens = 1;
 
 	    /* This rule has only nonterminals: schedule it for the second
 	       pass.  */
 	    if (!any_tokens)
-	      for (r = rules_ruleno->rhs; *r >= 0; ++r)
+	      for (rp = rules_ruleno->rhs; *rp >= 0; ++rp)
 		{
 		  rcount[ruleno]++;
-		  p->next = rsets[*r - ntokens];
+		  p->next = rsets[*rp - ntokens];
 		  p->value = rules_ruleno;
-		  rsets[*r - ntokens] = p;
+		  rsets[*rp - ntokens] = p;
 		  p++;
 		}
 	  }
