@@ -40,22 +40,16 @@ static void
 print_core (int state, struct obstack *node_obstack)
 {
   int i;
-  int k;
-  int rule;
-  core *statep;
-  short *sp;
-  short *sp1;
+  core *statep = state_table[state].state;
 
-  statep = state_table[state].state;
-  k = statep->nitems;
-
-  if (k == 0)
+  if (!statep->nitems)
     return;
 
-  for (i = 0; i < k; i++)
+  for (i = 0; i < statep->nitems; i++)
     {
-      if (i)
-	obstack_1grow (node_obstack, '\n');
+      short *sp;
+      short *sp1;
+      int rule;
 
       sp1 = sp = ritem + statep->items[i];
 
@@ -64,6 +58,8 @@ print_core (int state, struct obstack *node_obstack)
 
       rule = -(*sp);
 
+      if (i)
+	obstack_1grow (node_obstack, '\n');
       obstack_fgrow1 (node_obstack, "%d: ", rule);
       obstack_fgrow1 (node_obstack, " %s  ->  ",
 		      tags[rule_table[rule].lhs]);
@@ -73,8 +69,8 @@ print_core (int state, struct obstack *node_obstack)
 
       obstack_1grow (node_obstack, '.');
 
-      while (*sp > 0)
-	obstack_fgrow1 (node_obstack, " %s", tags[*sp++]);
+      for (/* Nothing */; *sp > 0; ++sp)
+	obstack_fgrow1 (node_obstack, " %s", tags[*sp]);
     }
 }
 
