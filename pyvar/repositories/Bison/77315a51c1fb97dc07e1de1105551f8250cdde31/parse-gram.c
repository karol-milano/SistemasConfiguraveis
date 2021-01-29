@@ -3243,7 +3243,7 @@ lloc_default (YYLTYPE const *rhs, int n)
   loc.start = rhs[n].end;
   loc.end = rhs[n].end;
 
-  /* Ignore empty nonterminals the start of the the right-hand side.
+  /* Ignore empty nonterminals the start of the right-hand side.
      Do not bother to ignore them at the end of the right-hand side,
      since empty nonterminals have the same end as their predecessors.  */
   for (i = 1; i <= n; i++)
