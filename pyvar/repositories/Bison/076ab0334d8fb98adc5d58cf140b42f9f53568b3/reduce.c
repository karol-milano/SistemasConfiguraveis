@@ -264,28 +264,35 @@ inaccessable_symbols (void)
 static void
 reduce_grammar_tables (void)
 {
-/* This is turned off because we would need to change the numbers
-   in the case statements in the actions file.  */
-#if 0
-  /* remove useless productions */
-  if (nuseless_productions > 0)
-    {
-      short np, pn, ni, pi;
+  /* This is turned off because we would need to change the numbers in
+     the case statements in the actions file.
 
-      np = 0;
-      ni = 0;
-      for (pn = 1; pn <= nrules; pn++)
-	{
+     We don't disable it via CPP so that it is still checked with the
+     rest of the code, to avoid its becoming completely obsolete.
+
+     FIXME: I think the comment above demonstrates this code must be
+     turned off for *semantic* parser, not in the general case.  Try
+     to understand this better --akim.  */
+
+  if (0)
+    /* remove useless productions */
+    if (nuseless_productions > 0)
+      {
+	short np, pn, ni, pi;
+
+	np = 0;
+	ni = 0;
+	for (pn = 1; pn <= nrules; pn++)
 	  if (BITISSET (P, pn))
 	    {
 	      np++;
 	      if (pn != np)
 		{
-		  rule_table[np].lhs = rule_table[pn].lhs;
-		  rline[np] = rline[pn];
-		  rule_table[np].prec = rule_table[pn].prec;
+		  rule_table[np].lhs   = rule_table[pn].lhs;
+		  rule_table[np].line  = rule_table[pn].line;
+		  rule_table[np].prec  = rule_table[pn].prec;
 		  rule_table[np].assoc = rule_table[pn].assoc;
-		  rule_table[np].rhs = rule_table[pn].rhs;
+		  rule_table[np].rhs   = rule_table[pn].rhs;
 		  if (rule_table[np].rhs != ni)
 		    {
 		      pi = rule_table[np].rhs;
@@ -300,16 +307,15 @@ reduce_grammar_tables (void)
 		  while (ritem[ni++] >= 0);
 		}
 	    }
-	}
-      ritem[ni] = 0;
-      nrules -= nuseless_productions;
-      nitems = ni;
 
-      /* Is it worth it to reduce the amount of memory for the
-         grammar? Probably not.  */
+	ritem[ni] = 0;
+	nrules -= nuseless_productions;
+	nitems = ni;
+
+	/* Is it worth it to reduce the amount of memory for the
+	   grammar? Probably not.  */
+      }
 
-    }
-#endif /* 0 */
   /* Disable useless productions. */
   if (nuseless_productions > 0)
     {
