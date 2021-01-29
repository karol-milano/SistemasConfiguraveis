@@ -48,20 +48,17 @@ static void
 print_core (FILE *out, int state)
 {
   int i;
-  int k;
-  int rule;
-  core *statep;
-  short *sp;
-  short *sp1;
-
-  statep = state_table[state].state;
-  k = statep->nitems;
+  core *statep = state_table[state].state;
 
-  if (k == 0)
+  if (!statep->nitems)
     return;
 
-  for (i = 0; i < k; i++)
+  for (i = 0; i < statep->nitems; i++)
     {
+      short *sp;
+      short *sp1;
+      int rule;
+
       sp1 = sp = ritem + statep->items[i];
 
       while (*sp > 0)
@@ -71,17 +68,12 @@ print_core (FILE *out, int state)
       fprintf (out, "    %s  ->  ", tags[rule_table[rule].lhs]);
 
       for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
-	{
-	  fprintf (out, "%s ", tags[*sp]);
-	}
+	fprintf (out, "%s ", tags[*sp]);
 
       fputc ('.', out);
 
-      while (*sp > 0)
-	{
-	  fprintf (out, " %s", tags[*sp]);
-	  sp++;
-	}
+      for (/* Nothing */; *sp > 0; ++sp)
+	fprintf (out, " %s", tags[*sp]);
 
       fprintf (out, _("   (rule %d)"), rule);
       fputc ('\n', out);
