@@ -30,6 +30,7 @@
 #include "reader.h"
 #include "print.h"
 #include "reduce.h"
+#include "closure.h"
 
 #if 0
 static void
@@ -48,38 +49,48 @@ static void
 print_core (FILE *out, int state)
 {
   int i;
-  core *statep = state_table[state].state;
+  short *sitems = state_table[state].state->items;
+  int snitems   = state_table[state].state->nitems;
 
-  if (!statep->nitems)
-    return;
+  /* New experimental feature: if TRACE_FLAGS output all the items of
+     a state, not only its kernel.  */
+  if (trace_flag)
+    {
+      closure (sitems, snitems);
+      sitems = itemset;
+      snitems = nitemset;
+    }
 
-  for (i = 0; i < statep->nitems; i++)
+  if (snitems)
     {
-      short *sp;
-      short *sp1;
-      int rule;
+      for (i = 0; i < snitems; i++)
+	{
+	  short *sp;
+	  short *sp1;
+	  int rule;
 
-      sp1 = sp = ritem + statep->items[i];
+	  sp1 = sp = ritem + sitems[i];
 
-      while (*sp > 0)
-	sp++;
+	  while (*sp > 0)
+	    sp++;
 
-      rule = -(*sp);
-      fprintf (out, "    %s  ->  ", tags[rule_table[rule].lhs]);
+	  rule = -(*sp);
+	  fprintf (out, "    %s  ->  ", tags[rule_table[rule].lhs]);
 
-      for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
-	fprintf (out, "%s ", tags[*sp]);
+	  for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
+	    fprintf (out, "%s ", tags[*sp]);
 
-      fputc ('.', out);
+	  fputc ('.', out);
 
-      for (/* Nothing */; *sp > 0; ++sp)
-	fprintf (out, " %s", tags[*sp]);
+	  for (/* Nothing */; *sp > 0; ++sp)
+	    fprintf (out, " %s", tags[*sp]);
+
+	  fprintf (out, _("   (rule %d)"), rule);
+	  fputc ('\n', out);
+	}
 
-      fprintf (out, _("   (rule %d)"), rule);
       fputc ('\n', out);
     }
-
-  fputc ('\n', out);
 }
 
 static void
@@ -321,8 +332,15 @@ print_results (void)
 
       print_grammar (out);
 
+      /* New experimental feature: output all the items of a state,
+	 not only its kernel.  Requires to run closure, which need
+	 memory allocation/deallocation.  */
+      if (trace_flag)
+	new_closure (nitems);
       for (i = 0; i < nstates; i++)
 	print_state (out, i);
+      if (trace_flag)
+	free_closure ();
 
       xfclose (out);
     }
