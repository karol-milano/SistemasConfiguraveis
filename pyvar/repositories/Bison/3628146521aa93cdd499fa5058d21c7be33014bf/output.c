@@ -656,10 +656,11 @@ output_actions (void)
 
 
 
-/* figure out the actions for the specified state, indexed by lookahead token type.
+/* Figure out the actions for the specified state, indexed by
+   lookahead token type.
 
-   The yydefact table is output now.  The detailed info
-   is saved for putting into yytable later.  */
+   The yydefact table is output now.  The detailed info is saved for
+   putting into yytable later.  */
 
 void
 token_actions (void)
@@ -700,16 +701,17 @@ token_actions (void)
 
 
 
-/* Decide what to do for each type of token if seen as the lookahead token in specified state.
-   The value returned is used as the default action (yydefact) for the state.
-   In addition, actrow is filled with what to do for each kind of token,
-   index by symbol number, with zero meaning do the default action.
-   The value MINSHORT, a very negative number, means this situation
-   is an error.  The parser recognizes this value specially.
+/* Decide what to do for each type of token if seen as the lookahead
+   token in specified state.  The value returned is used as the
+   default action (yydefact) for the state.  In addition, actrow is
+   filled with what to do for each kind of token, index by symbol
+   number, with zero meaning do the default action.  The value
+   MINSHORT, a very negative number, means this situation is an error.
+   The parser recognizes this value specially.
 
-   This is where conflicts are resolved.  The loop over lookahead rules
-   considered lower-numbered rules last, and the last rule considered that likes
-   a token gets to handle it.  */
+   This is where conflicts are resolved.  The loop over lookahead
+   rules considered lower-numbered rules last, and the last rule
+   considered that likes a token gets to handle it.  */
 
 int
 action_row (int state)
@@ -746,7 +748,8 @@ action_row (int state)
 
       if (nreds >= 1)
 	{
-	  /* loop over all the rules available here which require lookahead */
+	  /* loop over all the rules available here which require
+	     lookahead */
 	  m = lookaheads[state];
 	  n = lookaheads[state + 1];
 
@@ -756,10 +759,12 @@ action_row (int state)
 	      wordp = LA + i * tokensetsize;
 	      mask = 1;
 
-	      /* and find each token which the rule finds acceptable to come next */
+	      /* and find each token which the rule finds acceptable
+		 to come next */
 	      for (j = 0; j < ntokens; j++)
 		{
-		  /* and record this rule as the rule to use if that token follows.  */
+		  /* and record this rule as the rule to use if that
+		     token follows.  */
 		  if (mask & *wordp)
 		    actrow[j] = rule;
 
@@ -776,8 +781,9 @@ action_row (int state)
 
   shiftp = shift_table[state];
 
-  /* now see which tokens are allowed for shifts in this state.
-     For them, record the shift as the thing to do.  So shift is preferred to reduce.  */
+  /* Now see which tokens are allowed for shifts in this state.  For
+     them, record the shift as the thing to do.  So shift is preferred
+     to reduce.  */
 
   if (shiftp)
     {
@@ -795,16 +801,17 @@ action_row (int state)
 
 	  actrow[symbol] = shift_state;
 
-	  /* do not use any default reduction if there is a shift for error */
-
-	  if (symbol == error_token_number) nodefault = 1;
+	  /* Do not use any default reduction if there is a shift for
+	     error */
+	  if (symbol == error_token_number)
+	    nodefault = 1;
 	}
     }
 
   errp = err_table[state];
 
-  /* See which tokens are an explicit error in this state
-     (due to %nonassoc).  For them, record MINSHORT as the action.  */
+  /* See which tokens are an explicit error in this state (due to
+     %nonassoc).  For them, record MINSHORT as the action.  */
 
   if (errp)
     {
@@ -817,7 +824,8 @@ action_row (int state)
 	}
     }
 
-  /* now find the most common reduction and make it the default action for this state.  */
+  /* Now find the most common reduction and make it the default action
+     for this state.  */
 
   if (nreds >= 1 && ! nodefault)
     {
@@ -870,7 +878,7 @@ action_row (int state)
 	  actrow[j] = 0;
       }
 
-  return (default_rule);
+  return default_rule;
 }
 
 
@@ -970,7 +978,7 @@ default_goto (int symbol)
   n = goto_map[symbol + 1];
 
   if (m == n)
-    return (-1);
+    return -1;
 
   for (i = 0; i < nstates; i++)
     state_count[i] = 0;
@@ -990,7 +998,7 @@ default_goto (int symbol)
 	}
     }
 
-  return (default_state);
+  return default_state;
 }
 
 
@@ -1140,7 +1148,7 @@ matching_state (int vector)
 
   i = order[vector];
   if (i >= nstates)
-    return (-1);
+    return -1;
 
   t = tally[i];
   w = width[i];
@@ -1149,7 +1157,7 @@ matching_state (int vector)
     {
       j = order[prev];
       if (width[j] != w || tally[j] != t)
-	return (-1);
+	return -1;
 
       match = 1;
       for (k = 0; match && k < t; k++)
@@ -1159,10 +1167,10 @@ matching_state (int vector)
 	}
 
       if (match)
-	return (j);
+	return j;
     }
 
-  return (-1);
+  return -1;
 }
 
 
@@ -1223,7 +1231,7 @@ pack_vector (int vector)
 	  if (loc > high)
 	    high = loc;
 
-	  return (j);
+	  return j;
 	}
     }
 
@@ -1455,10 +1463,11 @@ free_itemsets (void)
 
   FREE(state_table);
 
-  for (cp = first_state; cp; cp = cptmp) {
-    cptmp=cp->next;
-    FREE(cp);
-  }
+  for (cp = first_state; cp; cp = cptmp)
+    {
+      cptmp=cp->next;
+      FREE(cp);
+    }
 }
 
 
@@ -1469,10 +1478,11 @@ free_shifts (void)
 
   FREE(shift_table);
 
-  for (sp = first_shift; sp; sp = sptmp) {
-    sptmp=sp->next;
-    FREE(sp);
-  }
+  for (sp = first_shift; sp; sp = sptmp)
+    {
+      sptmp=sp->next;
+      FREE(sp);
+    }
 }
 
 
@@ -1483,8 +1493,9 @@ free_reductions (void)
 
   FREE(reduction_table);
 
-  for (rp = first_reduction; rp; rp = rptmp) {
-    rptmp=rp->next;
-    FREE(rp);
-  }
+  for (rp = first_reduction; rp; rp = rptmp)
+    {
+      rptmp=rp->next;
+      FREE(rp);
+    }
 }
