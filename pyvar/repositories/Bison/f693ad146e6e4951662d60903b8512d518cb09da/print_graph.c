@@ -40,7 +40,7 @@ static void
 print_core (int state, struct obstack *node_obstack)
 {
   int i;
-  core *statep = state_table[state].state;
+  state_t *statep = state_table[state];
 
   if (!statep->nitems)
     return;
@@ -85,10 +85,10 @@ print_actions (int state, const char *node_name)
 {
   int i;
 
-  shifts   *shiftp = state_table[state].shifts;
-  reductions *redp = state_table[state].reductions;
+  shifts   *shiftp = state_table[state]->shifts;
+  reductions *redp = state_table[state]->reductions;
 #if 0
-  errs       *errp = err_table[state];
+  errs       *errp = state_table[state]->errs;
 #endif
 
   static char buff[10];
@@ -109,7 +109,7 @@ print_actions (int state, const char *node_name)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
 	int state1 = shiftp->shifts[i];
-	int symbol = state_table[state1].accessing_symbol;
+	int symbol = state_table[state1]->accessing_symbol;
 
 	new_edge (&edge);
 
@@ -150,7 +150,7 @@ print_actions (int state, const char *node_name)
 	obstack_1grow (node_obstack, '\n');
     }
 
-  if (state_table[state].consistent && redp)
+  if (state_table[state]->consistent && redp)
     {
       rule = redp->rules[0];
       symbol = rule_table[rule].lhs;
@@ -168,7 +168,7 @@ print_actions (int state, const char *node_name)
       if (!SHIFT_IS_DISABLED (shiftp, i))
 	{
 	  int state1 = shiftp->shifts[i];
-	  int symbol = state_table[state1].accessing_symbol;
+	  int symbol = state_table[state1]->accessing_symbol;
 
 	  new_edge (&edge);
 	  open_edge (&edge, fgraph);
