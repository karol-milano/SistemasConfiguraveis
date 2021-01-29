@@ -74,7 +74,7 @@ set_nullable (void)
 	if (rules[ruleno].rhs[0] >= 0)
 	  {
 	    /* This rule has a non empty RHS. */
-	    short *r;
+	    item_number_t *r;
 	    int any_tokens = 0;
 	    for (r = rules[ruleno].rhs; *r >= 0; ++r)
 	      if (ISTOKEN (*r))
