@@ -25,28 +25,35 @@
 
 #include "system.h"
 #include "getargs.h"
+#include "reader.h"
 #include "types.h"
 #include "gram.h"
 #include "nullable.h"
 
 char *nullable = NULL;
 
+static void
+nullable_print (FILE *out)
+{
+  int i;
+  fputs ("NULLABLE\n", out);
+  for (i = ntokens; i < nsyms; i++)
+    fprintf (out, "\t%s: %s\n", tags[i], nullable[i] ? "yes" : "no");
+  fputs ("\n\n", out);
+}
+
 void
 set_nullable (void)
 {
   short *r;
   short *s1;
   short *s2;
-  int ruleno;
-  int symbol;
   shorts *p;
 
   short *squeue;
   short *rcount;
   shorts **rsets;
   shorts *relts;
-  char any_tokens;
-  short *r1;
 
   if (trace_flag)
     fprintf (stderr, "Entering set_nullable\n");
@@ -69,7 +76,7 @@ set_nullable (void)
     {
       if (*r < 0)
 	{
-	  symbol = rule_table[-(*r++)].lhs;
+	  int symbol = rule_table[-(*r++)].lhs;
 	  if (symbol >= 0 && !nullable[symbol])
 	    {
 	      nullable[symbol] = 1;
@@ -78,17 +85,16 @@ set_nullable (void)
 	}
       else
 	{
-	  r1 = r;
-	  any_tokens = 0;
+	  int any_tokens = 0;
+	  int symbol;
+	  short *r1 = r;
 	  for (symbol = *r++; symbol > 0; symbol = *r++)
-	    {
-	      if (ISTOKEN (symbol))
-		any_tokens = 1;
-	    }
+	    if (ISTOKEN (symbol))
+	      any_tokens = 1;
 
 	  if (!any_tokens)
 	    {
-	      ruleno = -symbol;
+	      int ruleno = -symbol;
 	      r = r1;
 	      for (symbol = *r++; symbol > 0; symbol = *r++)
 		{
@@ -107,11 +113,11 @@ set_nullable (void)
       p = rsets[*s1++];
       while (p)
 	{
-	  ruleno = p->value;
+	  int ruleno = p->value;
 	  p = p->next;
 	  if (--rcount[ruleno] == 0)
 	    {
-	      symbol = rule_table[ruleno].lhs;
+	      int symbol = rule_table[ruleno].lhs;
 	      if (symbol >= 0 && !nullable[symbol])
 		{
 		  nullable[symbol] = 1;
@@ -125,6 +131,9 @@ set_nullable (void)
   XFREE (rcount);
   XFREE (rsets + ntokens);
   XFREE (relts);
+
+  if (trace_flag)
+    nullable_print (stderr);
 }
 
 
