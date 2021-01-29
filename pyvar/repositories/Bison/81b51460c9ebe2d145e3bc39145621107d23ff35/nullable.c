@@ -71,41 +71,35 @@ set_nullable (void)
   relts = XCALLOC (shorts, nitems + nvars + 1);
   p = relts;
 
-  r = ritem;
-  while (*r)
+  for (r = ritem; *r; ++r)
     {
-      if (*r < 0)
+      /* Walk RITEM to find (i), if there are any tokens in the
+	 RHS, and (ii), to find RULENO. */
+      int ruleno;
+      int any_tokens = 0;
+      short *r1;
+      for (r1 = r; *r1 > 0; ++r1)
+	if (ISTOKEN (*r1))
+	  any_tokens = 1;
+      ruleno = -*r1;
+
+      /* Examine the RHS of the rule.  */
+      if (!any_tokens)
+	for (/* Nothing. */; *r > 0; ++r)
+	  {
+	    rcount[ruleno]++;
+	    p->next = rsets[*r];
+	    p->value = ruleno;
+	    rsets[*r] = p;
+	    p++;
+	  }
+
+      /* Examine its LHS. */
+      if (rule_table[ruleno].useful && !nullable[rule_table[ruleno].lhs])
 	{
-	  int symbol = rule_table[-(*r++)].lhs;
-	  if (symbol >= 0 && !nullable[symbol])
-	    {
-	      nullable[symbol] = 1;
-	      *s2++ = symbol;
-	    }
-	}
-      else
-	{
-	  int any_tokens = 0;
-	  int symbol;
-	  short *r1 = r;
-	  for (symbol = *r++; symbol > 0; symbol = *r++)
-	    if (ISTOKEN (symbol))
-	      any_tokens = 1;
-
-	  if (!any_tokens)
-	    {
-	      int ruleno = -symbol;
-	      r = r1;
-	      for (symbol = *r++; symbol > 0; symbol = *r++)
-		{
-		  rcount[ruleno]++;
-		  p->next = rsets[symbol];
-		  p->value = ruleno;
-		  rsets[symbol] = p;
-		  p++;
-		}
-	    }
-	}
+	  nullable[rule_table[ruleno].lhs] = 1;
+	  *s2++ = rule_table[ruleno].lhs;
+        }
     }
 
   while (s1 < s2)
