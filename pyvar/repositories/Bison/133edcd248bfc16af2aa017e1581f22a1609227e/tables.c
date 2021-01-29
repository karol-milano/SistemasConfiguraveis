@@ -84,7 +84,7 @@ int nvectors;
 
 static base_number **froms;
 static base_number **tos;
-static unsigned **conflict_tos;
+static int **conflict_tos;
 static size_t *tally;
 static base_number *width;
 
@@ -115,9 +115,9 @@ base_number base_ninf = 0;
    -nstates..table_size (as an upper bound) */
 static bitset pos_set = NULL;
 
-static unsigned *conflrow;
-unsigned *conflict_table;
-unsigned *conflict_list;
+static int *conflrow;
+int *conflict_table;
+int *conflict_list;
 int conflict_list_cnt;
 static int conflict_list_free;
 
@@ -391,7 +391,7 @@ save_row (state_number s)
       /* Allocate non defaulted actions.  */
       base_number *sp1 = froms[s] = xnmalloc (count, sizeof *sp1);
       base_number *sp2 = tos[s] = xnmalloc (count, sizeof *sp2);
-      unsigned *sp3 = conflict_tos[s] =
+      int *sp3 = conflict_tos[s] =
         nondeterministic_parser ? xnmalloc (count, sizeof *sp3) : NULL;
 
       /* Store non defaulted actions.  */
@@ -646,7 +646,7 @@ pack_vector (vector_number vector)
   size_t t = tally[i];
   base_number *from = froms[i];
   base_number *to = tos[i];
-  unsigned *conflict_to = conflict_tos[i];
+  int *conflict_to = conflict_tos[i];
 
   aver (t != 0);
 
