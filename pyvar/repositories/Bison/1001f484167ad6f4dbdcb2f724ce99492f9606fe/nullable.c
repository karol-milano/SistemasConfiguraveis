@@ -36,7 +36,7 @@
 typedef struct rule_list
 {
   struct rule_list *next;
-  rule *value;
+  const rule *value;
 } rule_list;
 
 bool *nullable = NULL;
@@ -44,9 +44,8 @@ bool *nullable = NULL;
 static void
 nullable_print (FILE *out)
 {
-  int i;
   fputs ("NULLABLE\n", out);
-  for (i = ntokens; i < nsyms; i++)
+  for (int i = ntokens; i < nsyms; i++)
     fprintf (out, "  %s: %s\n", symbols[i]->tag,
              nullable[i - ntokens] ? "yes" : "no");
   fputs ("\n\n", out);
@@ -55,12 +54,8 @@ nullable_print (FILE *out)
 void
 nullable_compute (void)
 {
-  rule_number ruleno;
-  symbol_number *s1;
-  symbol_number *s2;
-  rule_list *p;
+  nullable = xcalloc (nvars, sizeof *nullable);
 
-  symbol_number *squeue = xnmalloc (nvars, sizeof *squeue);
   size_t *rcount = xcalloc (nrules, sizeof *rcount);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
@@ -69,54 +64,52 @@ nullable_compute (void)
      Supposedly NRITEMS - NRULES is enough.  But why take the risk?  */
   rule_list *relts = xnmalloc (nritems + nvars + 1, sizeof *relts);
 
-  nullable = xcalloc (nvars, sizeof *nullable);
-
-  s1 = s2 = squeue;
-  p = relts;
-
-  for (ruleno = 0; ruleno < nrules; ++ruleno)
-    if (rules[ruleno].useful)
-      {
-        rule *rules_ruleno = &rules[ruleno];
-        if (rules_ruleno->rhs[0] >= 0)
-          {
-            /* This rule has a non empty RHS. */
-            item_number *rp = NULL;
-            bool any_tokens = false;
-            for (rp = rules_ruleno->rhs; *rp >= 0; ++rp)
-              if (ISTOKEN (*rp))
-                any_tokens = true;
-
-            /* This rule has only nonterminals: schedule it for the second
-               pass.  */
-            if (!any_tokens)
-              for (rp = rules_ruleno->rhs; *rp >= 0; ++rp)
+  symbol_number *squeue = xnmalloc (nvars, sizeof *squeue);
+  symbol_number *s2 = squeue;
+  {
+    rule_list *p = relts;
+    for (rule_number ruleno = 0; ruleno < nrules; ++ruleno)
+      if (rules[ruleno].useful)
+        {
+          const rule *r = &rules[ruleno];
+          if (r->rhs[0] >= 0)
+            {
+              /* This rule has a non empty RHS. */
+              bool any_tokens = false;
+              for (item_number *rp = r->rhs; *rp >= 0; ++rp)
+                if (ISTOKEN (*rp))
+                  any_tokens = true;
+
+              /* This rule has only nonterminals: schedule it for the second
+                 pass.  */
+              if (!any_tokens)
+                for (item_number *rp = r->rhs; *rp >= 0; ++rp)
+                  {
+                    rcount[ruleno]++;
+                    p->next = rsets[*rp - ntokens];
+                    p->value = r;
+                    rsets[*rp - ntokens] = p;
+                    p++;
+                  }
+            }
+          else
+            {
+              /* This rule has an empty RHS. */
+              if (r->useful
+                  && ! nullable[r->lhs->number - ntokens])
                 {
-                  rcount[ruleno]++;
-                  p->next = rsets[*rp - ntokens];
-                  p->value = rules_ruleno;
-                  rsets[*rp - ntokens] = p;
-                  p++;
+                  nullable[r->lhs->number - ntokens] = true;
+                  *s2++ = r->lhs->number;
                 }
-          }
-        else
-          {
-            /* This rule has an empty RHS. */
-            aver (item_number_as_rule_number (rules_ruleno->rhs[0])
-                  == ruleno);
-            if (rules_ruleno->useful
-                && ! nullable[rules_ruleno->lhs->number - ntokens])
-              {
-                nullable[rules_ruleno->lhs->number - ntokens] = true;
-                *s2++ = rules_ruleno->lhs->number;
-              }
-          }
-      }
+            }
+        }
+  }
 
+  symbol_number *s1 = squeue;
   while (s1 < s2)
-    for (p = rsets[*s1++ - ntokens]; p; p = p->next)
+    for (rule_list *p = rsets[*s1++ - ntokens]; p; p = p->next)
       {
-        rule *r = p->value;
+        const rule *r = p->value;
         if (--rcount[r->number] == 0)
           if (r->useful && ! nullable[r->lhs->number - ntokens])
             {
