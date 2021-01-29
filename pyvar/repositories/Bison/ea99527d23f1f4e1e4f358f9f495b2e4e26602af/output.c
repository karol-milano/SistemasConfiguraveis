@@ -503,19 +503,19 @@ prepare_actions (void)
   muscle_insert_base_table ("check", check,
 			    check[0], 1, high + 1);
 
-  if (glr_parser)
-    {
-      /* GLR parsing slightly modifies yytable and yycheck
-	 (and thus yypact) so that in states with unresolved conflicts,
-	 the default reduction is not used in the conflicted entries, so
-	 that there is a place to put a conflict pointer.  This means that
-	 yyconflp and yyconfl are nonsense for a non-GLR parser, so we
-	 avoid accidents by not writing them out in that case. */
-      muscle_insert_unsigned_int_table ("conflict_list_heads", conflict_table,
-					conflict_table[0], 1, high+1);
-      muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list,
-			     conflict_list[0], 1, conflict_list_cnt);
-    }
+  /* GLR parsing slightly modifies YYTABLE and YYCHECK (and thus
+     YYPACT) so that in states with unresolved conflicts, the default
+     reduction is not used in the conflicted entries, so that there is
+     a place to put a conflict pointer.
+
+     This means that YYCONFLP and YYCONFL are nonsense for a non-GLR
+     parser, so we could avoid accidents by not writing them out in
+     that case.  Nevertheless, it seems even better to be able to use
+     the GLR skeletons even without the non-deterministic tables.  */
+  muscle_insert_unsigned_int_table ("conflict_list_heads", conflict_table,
+				    conflict_table[0], 1, high+1);
+  muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list,
+				    conflict_list[0], 1, conflict_list_cnt);
 }
 
 
