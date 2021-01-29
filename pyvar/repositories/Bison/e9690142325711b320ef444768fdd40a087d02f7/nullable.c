@@ -48,7 +48,7 @@ nullable_print (FILE *out)
   fputs ("NULLABLE\n", out);
   for (i = ntokens; i < nsyms; i++)
     fprintf (out, "\t%s: %s\n", symbols[i]->tag,
-	     nullable[i - ntokens] ? "yes" : "no");
+             nullable[i - ntokens] ? "yes" : "no");
   fputs ("\n\n", out);
 }
 
@@ -77,52 +77,52 @@ nullable_compute (void)
   for (ruleno = 0; ruleno < nrules; ++ruleno)
     if (rules[ruleno].useful)
       {
-	rule *rules_ruleno = &rules[ruleno];
-	if (rules_ruleno->rhs[0] >= 0)
-	  {
-	    /* This rule has a non empty RHS. */
-	    item_number *rp = NULL;
-	    bool any_tokens = false;
-	    for (rp = rules_ruleno->rhs; *rp >= 0; ++rp)
-	      if (ISTOKEN (*rp))
-		any_tokens = true;
-
-	    /* This rule has only nonterminals: schedule it for the second
-	       pass.  */
-	    if (!any_tokens)
-	      for (rp = rules_ruleno->rhs; *rp >= 0; ++rp)
-		{
-		  rcount[ruleno]++;
-		  p->next = rsets[*rp - ntokens];
-		  p->value = rules_ruleno;
-		  rsets[*rp - ntokens] = p;
-		  p++;
-		}
-	  }
-	else
-	  {
-	    /* This rule has an empty RHS. */
-	    aver (item_number_as_rule_number (rules_ruleno->rhs[0])
-		  == ruleno);
-	    if (rules_ruleno->useful
-		&& ! nullable[rules_ruleno->lhs->number - ntokens])
-	      {
-		nullable[rules_ruleno->lhs->number - ntokens] = true;
-		*s2++ = rules_ruleno->lhs->number;
-	      }
-	  }
+        rule *rules_ruleno = &rules[ruleno];
+        if (rules_ruleno->rhs[0] >= 0)
+          {
+            /* This rule has a non empty RHS. */
+            item_number *rp = NULL;
+            bool any_tokens = false;
+            for (rp = rules_ruleno->rhs; *rp >= 0; ++rp)
+              if (ISTOKEN (*rp))
+                any_tokens = true;
+
+            /* This rule has only nonterminals: schedule it for the second
+               pass.  */
+            if (!any_tokens)
+              for (rp = rules_ruleno->rhs; *rp >= 0; ++rp)
+                {
+                  rcount[ruleno]++;
+                  p->next = rsets[*rp - ntokens];
+                  p->value = rules_ruleno;
+                  rsets[*rp - ntokens] = p;
+                  p++;
+                }
+          }
+        else
+          {
+            /* This rule has an empty RHS. */
+            aver (item_number_as_rule_number (rules_ruleno->rhs[0])
+                  == ruleno);
+            if (rules_ruleno->useful
+                && ! nullable[rules_ruleno->lhs->number - ntokens])
+              {
+                nullable[rules_ruleno->lhs->number - ntokens] = true;
+                *s2++ = rules_ruleno->lhs->number;
+              }
+          }
       }
 
   while (s1 < s2)
     for (p = rsets[*s1++ - ntokens]; p; p = p->next)
       {
-	rule *r = p->value;
-	if (--rcount[r->number] == 0)
-	  if (r->useful && ! nullable[r->lhs->number - ntokens])
-	    {
-	      nullable[r->lhs->number - ntokens] = true;
-	      *s2++ = r->lhs->number;
-	    }
+        rule *r = p->value;
+        if (--rcount[r->number] == 0)
+          if (r->useful && ! nullable[r->lhs->number - ntokens])
+            {
+              nullable[r->lhs->number - ntokens] = true;
+              *s2++ = r->lhs->number;
+            }
       }
 
   free (squeue);
