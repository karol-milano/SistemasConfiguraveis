@@ -236,7 +236,7 @@ prepare_rules (void)
       prhs[r] = i;
       /* RHS of the rule R. */
       for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
-	rhs[i++] = *rhsp;
+        rhs[i++] = *rhsp;
       /* Separator in RHS. */
       rhs[i++] = -1;
 
@@ -245,7 +245,7 @@ prepare_rules (void)
       /* LHS of the rule R. */
       r1[r] = rules[r].lhs->number;
       /* Length of rule R's RHS. */
-      r2[r] = rule_rhs_length(&rules[r]);
+      r2[r] = rule_rhs_length (&rules[r]);
       /* Dynamic precedence (GLR).  */
       dprec[r] = rules[r].dprec;
       /* Merger-function index (GLR).  */
