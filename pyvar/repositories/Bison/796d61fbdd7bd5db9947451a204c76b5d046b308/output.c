@@ -214,7 +214,7 @@ output_gram (void)
 
     XFREE (yyrhs);
   }
-  
+
 #if 0
   if (!semantic_parser)
     obstack_sgrow (&table_obstack, "\n#endif\n");
@@ -327,7 +327,6 @@ action_row (int state)
 {
   int i;
   int j;
-  int k;
   int m = 0;
   int n = 0;
   int default_rule;
@@ -397,15 +396,11 @@ action_row (int state)
   errp = state_table[state]->errs;
 
   if (errp)
-    {
-      k = errp->nerrs;
-
-      for (i = 0; i < k; i++)
-	{
-	  symbol = errp->errs[i];
-	  actrow[symbol] = MINSHORT;
-	}
-    }
+    for (i = 0; i < errp->nerrs; i++)
+      {
+	symbol = errp->errs[i];
+	actrow[symbol] = MINSHORT;
+      }
 
   /* Now find the most common reduction and make it the default action
      for this state.  */
@@ -476,10 +471,8 @@ save_row (int state)
 
   count = 0;
   for (i = 0; i < ntokens; i++)
-    {
-      if (actrow[i] != 0)
-	count++;
-    }
+    if (actrow[i] != 0)
+      count++;
 
   if (count == 0)
     return;
@@ -488,13 +481,11 @@ save_row (int state)
   tos[state] = sp2 = XCALLOC (short, count);
 
   for (i = 0; i < ntokens; i++)
-    {
-      if (actrow[i] != 0)
-	{
-	  *sp1++ = i;
-	  *sp2++ = actrow[i];
-	}
-    }
+    if (actrow[i] != 0)
+      {
+	*sp1++ = i;
+	*sp2++ = actrow[i];
+      }
 
   tally[state] = count;
   width[state] = sp1[-1] - sp[0] + 1;
@@ -582,10 +573,8 @@ save_column (int symbol, int default_state)
 
   count = 0;
   for (i = begin; i < end; i++)
-    {
-      if (to_state[i] != default_state)
-	count++;
-    }
+    if (to_state[i] != default_state)
+      count++;
 
   if (count == 0)
     return;
@@ -596,13 +585,11 @@ save_column (int symbol, int default_state)
   tos[symno] = sp2 = XCALLOC (short, count);
 
   for (i = begin; i < end; i++)
-    {
-      if (to_state[i] != default_state)
-	{
-	  *sp1++ = from_state[i];
-	  *sp2++ = to_state[i];
-	}
-    }
+    if (to_state[i] != default_state)
+      {
+	*sp1++ = from_state[i];
+	*sp2++ = to_state[i];
+      }
 
   tally[symno] = count;
   width[symno] = sp1[-1] - sp[0] + 1;
@@ -633,13 +620,11 @@ default_goto (int symbol)
   default_state = -1;
 
   for (i = 0; i < nstates; i++)
-    {
-      if (state_count[i] > max)
-	{
-	  max = state_count[i];
-	  default_state = i;
-	}
-    }
+    if (state_count[i] > max)
+      {
+	max = state_count[i];
+	default_state = i;
+      }
 
   return default_state;
 }
@@ -693,26 +678,24 @@ sort_actions (void)
   nentries = 0;
 
   for (i = 0; i < nvectors; i++)
-    {
-      if (tally[i] > 0)
-	{
-	  t = tally[i];
-	  w = width[i];
-	  j = nentries - 1;
+    if (tally[i] > 0)
+      {
+	t = tally[i];
+	w = width[i];
+	j = nentries - 1;
 
-	  while (j >= 0 && (width[order[j]] < w))
-	    j--;
+	while (j >= 0 && (width[order[j]] < w))
+	  j--;
 
-	  while (j >= 0 && (width[order[j]] == w) && (tally[order[j]] < t))
-	    j--;
+	while (j >= 0 && (width[order[j]] == w) && (tally[order[j]] < t))
+	  j--;
 
-	  for (k = nentries - 1; k > j; k--)
-	    order[k + 1] = order[k];
+	for (k = nentries - 1; k > j; k--)
+	  order[k + 1] = order[k];
 
-	  order[j + 1] = i;
-	  nentries++;
-	}
-    }
+	order[j + 1] = i;
+	nentries++;
+      }
 }
 
 
@@ -742,10 +725,8 @@ matching_state (int vector)
 
       match = 1;
       for (k = 0; match && k < t; k++)
-	{
-	  if (tos[j][k] != tos[i][k] || froms[j][k] != froms[i][k])
-	    match = 0;
-	}
+	if (tos[j][k] != tos[i][k] || froms[j][k] != froms[i][k])
+	  match = 0;
 
       if (match)
 	return j;
@@ -790,10 +771,8 @@ pack_vector (int vector)
 	}
 
       for (k = 0; ok && k < vector; k++)
-	{
-	  if (pos[k] == j)
-	    ok = 0;
-	}
+	if (pos[k] == j)
+	  ok = 0;
 
       if (ok)
 	{
@@ -855,10 +834,8 @@ pack_table (void)
 
   for (i = 0; i < nvectors; i++)
     {
-      if (froms[i])
-	XFREE (froms[i]);
-      if (tos[i])
-	XFREE (tos[i]);
+      XFREE (froms[i]);
+      XFREE (tos[i]);
     }
 
   XFREE (froms);
