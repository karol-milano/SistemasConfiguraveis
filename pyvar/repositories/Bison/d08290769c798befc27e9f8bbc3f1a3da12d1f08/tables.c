@@ -243,8 +243,8 @@ action_row (state *s)
   transitions *trans = s->transitions;
   errs *errp = s->errs;
   /* Set to nonzero to inhibit having any default reduction.  */
-  int nodefault = 0;
-  int conflicted = 0;
+  bool nodefault = false;
+  bool conflicted = false;
 
   for (i = 0; i < ntokens; i++)
     actrow[i] = conflrow[i] = 0;
@@ -264,7 +264,10 @@ action_row (state *s)
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
 	  if (actrow[j] != 0)
-	    conflicted = conflrow[j] = 1;
+	    {
+	      conflicted = true;
+	      conflrow[j] = 1;
+	    }
 	  actrow[j] = rule_number_as_item_number (reds->rules[i]->number);
 	}
     }
@@ -278,13 +281,16 @@ action_row (state *s)
       state *shift_state = trans->states[i];
 
       if (actrow[sym] != 0)
-	conflicted = conflrow[sym] = 1;
+	{
+	  conflicted = true;
+	  conflrow[sym] = 1;
+	}
       actrow[sym] = state_number_as_int (shift_state->number);
 
       /* Do not use any default reduction if there is a shift for
 	 error */
       if (sym == errtoken->number)
-	nodefault = 1;
+	nodefault = true;
     }
 
   /* See which tokens are an explicit error in this state (due to
@@ -669,7 +675,7 @@ pack_vector (vector_number vector)
   for (j = lowzero - from[0]; ; j++)
     {
       int k;
-      int ok = 1;
+      bool ok = true;
 
       if (table_size <= j)
 	abort ();
@@ -681,12 +687,12 @@ pack_vector (vector_number vector)
 	    table_grow (loc);
 
 	  if (table[loc] != 0)
-	    ok = 0;
+	    ok = false;
 	}
 
       for (k = 0; ok && k < vector; k++)
 	if (pos[k] == j)
-	  ok = 0;
+	  ok = false;
 
       if (ok)
 	{
