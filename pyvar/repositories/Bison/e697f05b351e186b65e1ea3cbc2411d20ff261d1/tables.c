@@ -84,7 +84,7 @@ int nvectors;
 static base_number **froms;
 static base_number **tos;
 static unsigned int **conflict_tos;
-static int *tally;
+static size_t *tally;
 static base_number *width;
 
 
@@ -382,7 +382,7 @@ static void
 save_row (state_number s)
 {
   symbol_number i;
-  int count;
+  size_t count;
   base_number *sp;
   base_number *sp1;
   base_number *sp2;
@@ -489,14 +489,13 @@ save_column (symbol_number sym, state_number default_state)
   base_number *sp;
   base_number *sp1;
   base_number *sp2;
-  int count;
   vector_number symno = symbol_number_to_vector_number (sym);
 
   goto_number begin = goto_map[sym - ntokens];
   goto_number end = goto_map[sym - ntokens + 1];
 
   /* Number of non default GOTO.  */
-  count = 0;
+  size_t count = 0;
   for (i = begin; i < end; i++)
     if (to_state[i] != default_state)
       count++;
@@ -599,7 +598,7 @@ sort_actions (void)
     if (0 < tally[i])
       {
         int k;
-        int t = tally[i];
+        size_t t = tally[i];
         int w = width[i];
         int j = nentries - 1;
 
@@ -628,7 +627,7 @@ static state_number
 matching_state (vector_number vector)
 {
   vector_number i = order[vector];
-  int t;
+  size_t t;
   int w;
   int prev;
 
@@ -677,8 +676,8 @@ static base_number
 pack_vector (vector_number vector)
 {
   vector_number i = order[vector];
+  size_t t = tally[i];
   int j;
-  int t = tally[i];
   int loc = 0;
   base_number *from = froms[i];
   base_number *to = tos[i];
