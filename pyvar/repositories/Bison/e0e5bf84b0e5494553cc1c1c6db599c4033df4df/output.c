@@ -378,8 +378,8 @@ conflict_row (state_t *state)
   if (! glr_parser)
     return;
 
-  for (j = 0; j < ntokens; j += 1) 
-    if (conflrow[j]) 
+  for (j = 0; j < ntokens; j += 1)
+    if (conflrow[j])
       {
 	conflrow[j] = conflict_list_cnt;
 
@@ -388,14 +388,14 @@ conflict_row (state_t *state)
 	for (i = 0; i < state->nlookaheads; i += 1)
 	  if (bitset_test (state->lookaheads[i], j)
 	      && actrow[j] != -state->lookaheads_rule[i]->number)
-	    {	    
+	    {
 	      assert (conflict_list_free > 0);
-	      conflict_list[conflict_list_cnt] 
+	      conflict_list[conflict_list_cnt]
 		= state->lookaheads_rule[i]->number;
 	      conflict_list_cnt += 1;
 	      conflict_list_free -= 1;
 	    }
-	
+
 	/* Leave a 0 at the end */
 	assert (conflict_list_free > 0);
 	conflict_list_cnt += 1;
@@ -519,7 +519,7 @@ action_row (state_t *state)
 
 	  /* GLR parsers need space for conflict lists, so we can't
 	     default conflicted entries.  For non-conflicted entries
-	     or as long as we are not building a GLR parser, 
+	     or as long as we are not building a GLR parser,
 	     actions that match the default are replaced with zero,
 	     which means "use the default". */
 
@@ -554,10 +554,10 @@ save_row (int state)
 {
   int i;
   int count;
-  short *sp;
-  short *sp1;
-  short *sp2;
-  unsigned int *sp3;
+  short *sp = NULL;
+  short *sp1 = NULL;
+  short *sp2 = NULL;
+  unsigned int *sp3 = NULL;
 
   count = 0;
   for (i = 0; i < ntokens; i++)
@@ -570,8 +570,8 @@ save_row (int state)
   froms[state] = sp1 = sp = XCALLOC (short, count);
   tos[state] = sp2 = XCALLOC (short, count);
   if (glr_parser)
-    conflict_tos[state] = sp3 = XCALLOC (unsigned int, count);  
-  else 
+    conflict_tos[state] = sp3 = XCALLOC (unsigned int, count);
+  else
     conflict_tos[state] = NULL;
 
   for (i = 0; i < ntokens; i++)
@@ -612,8 +612,8 @@ token_actions (void)
       conflict_list = XCALLOC (unsigned int, 1 + 2 * nconflict);
       conflict_list_free = 2 * nconflict;
       conflict_list_cnt = 1;
-    } 
-  else 
+    }
+  else
     conflict_list_free = conflict_list_cnt = 0;
 
   for (i = 0; i < nstates; ++i)
@@ -667,9 +667,9 @@ merger_output (FILE *out)
   merger_list* p;
 
   fputs ("m4_define([b4_mergers], \n[[", out);
-  for (n = 1, p = merge_functions; p != NULL; n += 1, p = p->next) 
+  for (n = 1, p = merge_functions; p != NULL; n += 1, p = p->next)
     {
-      if (p->type[0] == '\0') 
+      if (p->type[0] == '\0')
 	fprintf (out, "  case %d: yyval = %s (*yy0, *yy1); break;\n",
 		 n, p->name);
       else
@@ -1103,9 +1103,9 @@ output_conflicts (void)
   if (! glr_parser)
     return;
 
-  muscle_insert_unsigned_int_table ("conflict_list_heads", conflict_table, 
+  muscle_insert_unsigned_int_table ("conflict_list_heads", conflict_table,
 				    conflict_table[0], 1, high+1);
-  muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list, 
+  muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list,
 			     conflict_list[0], 1, conflict_list_cnt);
 
   XFREE (conflict_table);
