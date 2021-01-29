@@ -135,11 +135,11 @@ int high;
 state_number *yydefgoto;
 rule_number *yydefact;
 
-/*----------------------------------------------------------------.
-| If TABLE (and CHECK) appear to be small to be addressed at      |
-| DESIRED, grow them.  Note that TABLE[DESIRED] is to be used, so |
-| the desired size is at least DESIRED + 1.                       |
-`----------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| If TABLE, CONFLICT_TABLE, and CHECK are too small to be addressed  |
+| at DESIRED, grow them.  TABLE[DESIRED] can be used, so the desired |
+| size is at least DESIRED + 1.                                      |
+`-------------------------------------------------------------------*/
 
 static void
 table_grow (int desired)
@@ -596,17 +596,17 @@ sort_actions (void)
   nentries = 0;
 
   for (i = 0; i < nvectors; i++)
-    if (tally[i] > 0)
+    if (0 < tally[i])
       {
         int k;
         int t = tally[i];
         int w = width[i];
         int j = nentries - 1;
 
-        while (j >= 0 && (width[order[j]] < w))
+        while (0 <= j && width[order[j]] < w)
           j--;
 
-        while (j >= 0 && (width[order[j]] == w) && (tally[order[j]] < t))
+        while (0 <= j && width[order[j]] == w && tally[order[j]] < t)
           j--;
 
         for (k = nentries - 1; k > j; k--)
@@ -618,7 +618,7 @@ sort_actions (void)
 }
 
 
-/* If VECTOR is a state which actions (reflected by FROMS, TOS, TALLY
+/* If VECTOR is a state whose actions (reflected by FROMS, TOS, TALLY
    and WIDTH of VECTOR) are common to a previous state, return this
    state number.
 
@@ -660,7 +660,8 @@ matching_state (vector_number vector)
         return -1;
 
       for (k = 0; match && k < t; k++)
-        if (tos[j][k] != tos[i][k] || froms[j][k] != froms[i][k]
+        if (tos[j][k] != tos[i][k]
+            || froms[j][k] != froms[i][k]
             || (conflict_tos[j] != NULL && conflict_tos[j][k] != 0))
           match = 0;
 
@@ -720,7 +721,7 @@ pack_vector (vector_number vector)
           while (table[lowzero] != 0)
             lowzero++;
 
-          if (loc > high)
+          if (high < loc)
             high = loc;
 
           aver (BASE_MINIMUM <= j && j <= BASE_MAXIMUM);
