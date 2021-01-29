@@ -84,20 +84,17 @@ static void
 print_actions (int state, const char *node_name)
 {
   int i;
-  int k;
-  int state1;
-  int symbol;
-  shifts *shiftp;
-  errs *errp;
-  reductions *redp;
+
+  shifts   *shiftp = state_table[state].shift_table;
+  reductions *redp = state_table[state].reduction_table;
+#if 0
+  errs       *errp = err_table[state];
+#endif
+
   static char buff[10];
   edge_t edge;
 
-  shiftp = state_table[state].shift_table;
-  redp = state_table[state].reduction_table;
-  errp = err_table[state];
-
-  if (!shiftp && !redp)
+  if (!shiftp->nshifts && !redp)
     {
 #if 0
       if (final_state == state)
@@ -108,42 +105,26 @@ print_actions (int state, const char *node_name)
       return;
     }
 
-  if (shiftp)
-    {
-      k = shiftp->nshifts;
-
-      for (i = 0; i < k; i++)
-	{
-	  if (!shiftp->shifts[i])
-	    continue;
-	  state1 = shiftp->shifts[i];
-	  symbol = state_table[state1].accessing_symbol;
-
-	  if (ISVAR (symbol))
-	    break;
-
-	  {
-	    new_edge (&edge);
-
-	    if (state > state1)
-	      edge.type = back_edge;
-	    open_edge (&edge, fgraph);
-	    /* The edge source is the current node.  */
-	    edge.sourcename = node_name;
-	    sprintf (buff, "%d", state1);
-	    edge.targetname = buff;
-	    edge.color = (symbol == 0) ? red : blue;
-	    edge.label = tags[symbol];
-	    output_edge (&edge, fgraph);
-	    close_edge (fgraph);
-	  }
-	}
-    }
-  else
-    {
-      i = 0;
-      k = 0;
-    }
+  for (i = 0; i < shiftp->nshifts; i++)
+    if (!SHIFT_IS_DISABLED (shiftp, i))
+      {
+	int state1 = shiftp->shifts[i];
+	int symbol = state_table[state1].accessing_symbol;
+
+	new_edge (&edge);
+
+	if (state > state1)
+	  edge.type = back_edge;
+	open_edge (&edge, fgraph);
+	/* The edge source is the current node.  */
+	edge.sourcename = node_name;
+	sprintf (buff, "%d", state1);
+	edge.targetname = buff;
+	edge.color = (symbol == 0) ? red : blue;
+	edge.label = tags[symbol];
+	output_edge (&edge, fgraph);
+	close_edge (fgraph);
+      }
 
 #if 0
   if (errp)
@@ -182,14 +163,12 @@ print_actions (int state, const char *node_name)
     }
 #endif
 
-  if (i < k)
-    {
-      for (; i < k; i++)
+  if (i < shiftp->nshifts)
+    for (; i < shiftp->nshifts; i++)
+      if (!SHIFT_IS_DISABLED (shiftp, i))
 	{
-	  if (!shiftp->shifts[i])
-	    continue;
-	  state1 = shiftp->shifts[i];
-	  symbol = state_table[state1].accessing_symbol;
+	  int state1 = shiftp->shifts[i];
+	  int symbol = state_table[state1].accessing_symbol;
 
 	  new_edge (&edge);
 	  open_edge (&edge, fgraph);
@@ -201,7 +180,6 @@ print_actions (int state, const char *node_name)
 	  output_edge (&edge, fgraph);
 	  close_edge (fgraph);
 	}
-    }
 }
 
 
