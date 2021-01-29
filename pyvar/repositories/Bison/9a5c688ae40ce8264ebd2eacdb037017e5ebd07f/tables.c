@@ -83,7 +83,7 @@ int nvectors;
 
 static base_number **froms;
 static base_number **tos;
-static unsigned int **conflict_tos;
+static unsigned **conflict_tos;
 static size_t *tally;
 static base_number *width;
 
@@ -112,9 +112,9 @@ base_number *base = NULL;
 base_number base_ninf = 0;
 static base_number *pos = NULL;
 
-static unsigned int *conflrow;
-unsigned int *conflict_table;
-unsigned int *conflict_list;
+static unsigned *conflrow;
+unsigned *conflict_table;
+unsigned *conflict_list;
 int conflict_list_cnt;
 static int conflict_list_free;
 
@@ -394,7 +394,7 @@ save_row (state_number s)
       /* Allocate non defaulted actions.  */
       base_number *sp1 = froms[s] = xnmalloc (count, sizeof *sp1);
       base_number *sp2 = tos[s] = xnmalloc (count, sizeof *sp2);
-      unsigned int *sp3 = conflict_tos[s] =
+      unsigned *sp3 = conflict_tos[s] =
         nondeterministic_parser ? xnmalloc (count, sizeof *sp3) : NULL;
 
       /* Store non defaulted actions.  */
@@ -670,7 +670,7 @@ pack_vector (vector_number vector)
   size_t t = tally[i];
   base_number *from = froms[i];
   base_number *to = tos[i];
-  unsigned int *conflict_to = conflict_tos[i];
+  unsigned *conflict_to = conflict_tos[i];
 
   aver (t != 0);
 
