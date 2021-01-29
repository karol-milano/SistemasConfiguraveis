@@ -94,7 +94,7 @@ Name (char const *name,                                                 \
   MUSCLE_INSERT_LONG_INT (obstack_finish0 (&format_obstack), lmax);     \
 }
 
-GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_unsigned_int_table, unsigned)
+GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_unsigned_table, unsigned)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_int_table, int)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_base_table, base_number)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_rule_number_table, rule_number)
@@ -246,10 +246,10 @@ prepare_rules (void)
   aver (i == nritems);
 
   muscle_insert_item_number_table ("rhs", rhs, ritem[0], 1, nritems);
-  muscle_insert_unsigned_int_table ("prhs", prhs, 0, 0, nrules);
-  muscle_insert_unsigned_int_table ("rline", rline, 0, 0, nrules);
+  muscle_insert_unsigned_table ("prhs", prhs, 0, 0, nrules);
+  muscle_insert_unsigned_table ("rline", rline, 0, 0, nrules);
   muscle_insert_symbol_number_table ("r1", r1, 0, 0, nrules);
-  muscle_insert_unsigned_int_table ("r2", r2, 0, 0, nrules);
+  muscle_insert_unsigned_table ("r2", r2, 0, 0, nrules);
   muscle_insert_int_table ("dprec", dprec, 0, 0, nrules);
   muscle_insert_int_table ("merger", merger, 0, 0, nrules);
   muscle_insert_int_table ("immediate", immediate, 0, 0, nrules);
@@ -516,10 +516,10 @@ prepare_actions (void)
      parser, so we could avoid accidents by not writing them out in
      that case.  Nevertheless, it seems even better to be able to use
      the GLR skeletons even without the non-deterministic tables.  */
-  muscle_insert_unsigned_int_table ("conflict_list_heads", conflict_table,
-                                    conflict_table[0], 1, high + 1);
-  muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list,
-                                    0, 1, conflict_list_cnt);
+  muscle_insert_unsigned_table ("conflict_list_heads", conflict_table,
+                                conflict_table[0], 1, high + 1);
+  muscle_insert_unsigned_table ("conflicting_rules", conflict_list,
+                                0, 1, conflict_list_cnt);
 }
 
 
