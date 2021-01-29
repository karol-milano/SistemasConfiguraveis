@@ -167,17 +167,18 @@ table_grow (size_t desired)
 }
 
 
-/*------------------------------------------------------------------.
-| Create a function NAME which Format the FIRST and then            |
-| TABLE_DATA[BEGIN..END[ (of TYPE) into OOUT, and return the number |
-| of bits needed for its longuest value.                            |
-`------------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| Create a function NAME which associates to the muscle NAME the     |
+| result of formatting the FIRST and then TABLE_DATA[BEGIN..END[ (of |
+| TYPE), and to the muscle NAME_max, the max value of the            |
+| TABLE_DATA.                                                        |
+`-------------------------------------------------------------------*/
 
 
-#define GENERATE_OUTPUT_TABLE(Name, Type)				\
+#define GENERATE_MUSCLE_INSERT_TABLE(Name, Type)			\
 									\
-static inline long int							\
-Name (struct obstack *oout,						\
+static void								\
+Name (const char *name,							\
       Type *table_data,							\
       Type first,							\
       int begin,							\
@@ -187,31 +188,35 @@ Name (struct obstack *oout,						\
   int i;								\
   int j = 1;								\
 									\
-  obstack_fgrow1 (oout, "%6d", first);					\
+  obstack_fgrow1 (&format_obstack, "%6d", first);			\
   for (i = begin; i < end; ++i)						\
     {									\
-      obstack_1grow (oout, ',');					\
+      obstack_1grow (&format_obstack, ',');				\
       if (j >= 10)							\
 	{								\
-	  obstack_sgrow (oout, "\n  ");					\
+	  obstack_sgrow (&format_obstack, "\n  ");			\
 	  j = 1;							\
 	}								\
       else								\
 	++j;								\
-      obstack_fgrow1 (oout, "%6d", table_data[i]);			\
+      obstack_fgrow1 (&format_obstack, "%6d", table_data[i]);		\
       if (table_data[i] > max)						\
 	max = table_data[i];						\
     }									\
-  obstack_1grow (oout, 0);						\
+  obstack_1grow (&format_obstack, 0);					\
+  muscle_insert (name, obstack_finish (&format_obstack));		\
 									\
-  return max;								\
+  /* Build `NAME_max' in the obstack. */				\
+  obstack_fgrow1 (&format_obstack, "%s_max", name);			\
+  obstack_1grow (&format_obstack, 0);					\
+  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), max);	\
 }
 
-GENERATE_OUTPUT_TABLE(output_int_table, int)
-GENERATE_OUTPUT_TABLE(output_unsigned_int_table, unsigned int)
-GENERATE_OUTPUT_TABLE(output_short_table, short)
-GENERATE_OUTPUT_TABLE(output_token_number_table, token_number_t)
-GENERATE_OUTPUT_TABLE(output_item_number_table, item_number_t)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_int_table, int)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_short_table, short)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_token_number_table, token_number_t)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number_t)
 
 
 /*-----------------------------------------------------------------.
@@ -222,12 +227,9 @@ GENERATE_OUTPUT_TABLE(output_item_number_table, item_number_t)
 static void
 prepare_tokens (void)
 {
-  long int max = output_token_number_table (&format_obstack,
-					    token_translations,
-					    0, 1, max_user_token_number + 1);
-  muscle_insert ("translate", obstack_finish (&format_obstack));
-  MUSCLE_INSERT_LONG_INT ("token_number_max", max);
-  XFREE (token_translations);
+  muscle_insert_token_number_table ("translate",
+				    token_translations,
+				    0, 1, max_user_token_number + 1);
 
   {
     int i;
@@ -268,9 +270,8 @@ prepare_tokens (void)
     short *values = XCALLOC (short, ntokens + 1);
     for (i = 0; i < ntokens + 1; ++i)
       values[i] = symbols[i]->user_token_number;
-    output_short_table (&format_obstack, values,
-		       0, 1, ntokens + 1);
-    muscle_insert ("toknum", obstack_finish (&format_obstack));
+    muscle_insert_short_table ("toknum", values,
+			       0, 1, ntokens + 1);
     free (values);
   }
 }
@@ -312,24 +313,11 @@ prepare_rules (void)
     }
   assert (i == nritems);
 
-  max = output_item_number_table (&format_obstack, rhs, ritem[0], 1, nritems);
-  muscle_insert ("rhs", obstack_finish (&format_obstack));
-  MUSCLE_INSERT_LONG_INT ("rhs_max", max);
-
-  max = output_unsigned_int_table (&format_obstack, prhs, 0, 1, nrules + 1);
-  muscle_insert ("prhs", obstack_finish (&format_obstack));
-  MUSCLE_INSERT_LONG_INT ("prhs_max", max);
-
-  max = output_unsigned_int_table (&format_obstack, rline, 0, 1, nrules + 1);
-  muscle_insert ("rline", obstack_finish (&format_obstack));
-  MUSCLE_INSERT_LONG_INT ("rline_max", max);
-
-  output_token_number_table (&format_obstack, r1, 0, 1, nrules + 1);
-  muscle_insert ("r1", obstack_finish (&format_obstack));
-
-  max = output_unsigned_int_table (&format_obstack, r2, 0, 1, nrules + 1);
-  muscle_insert ("r2", obstack_finish (&format_obstack));
-  MUSCLE_INSERT_LONG_INT ("r2_max", max);
+  muscle_insert_item_number_table ("rhs", rhs, ritem[0], 1, nritems);
+  muscle_insert_unsigned_int_table ("prhs", prhs, 0, 1, nrules + 1);
+  muscle_insert_unsigned_int_table ("rline", rline, 0, 1, nrules + 1);
+  muscle_insert_token_number_table ("r1", r1, 0, 1, nrules + 1);
+  muscle_insert_unsigned_int_table ("r2", r2, 0, 1, nrules + 1);
 
   free (rhs);
   free (prhs);
@@ -350,9 +338,8 @@ prepare_states (void)
     (token_number_t *) alloca (sizeof (token_number_t) * nstates);
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
-  output_token_number_table (&format_obstack, values,
-			     0, 1, nstates);
-  muscle_insert ("stos", obstack_finish (&format_obstack));
+  muscle_insert_token_number_table ("stos", values,
+				    0, 1, nstates);
 }
 
 
@@ -537,10 +524,8 @@ token_actions (void)
       save_row (i);
     }
 
-  output_short_table (&format_obstack, yydefact,
-		     yydefact[0], 1, nstates);
-  muscle_insert ("defact", obstack_finish (&format_obstack));
-
+  muscle_insert_short_table ("defact", yydefact,
+			     yydefact[0], 1, nstates);
   XFREE (actrow);
   XFREE (yydefact);
 }
@@ -708,10 +693,8 @@ goto_actions (void)
       yydefgoto[i - ntokens] = default_state;
     }
 
-  output_short_table (&format_obstack, yydefgoto,
-		     yydefgoto[0], 1, nsyms - ntokens);
-  muscle_insert ("defgoto", obstack_finish (&format_obstack));
-
+  muscle_insert_short_table ("defgoto", yydefgoto,
+			     yydefgoto[0], 1, nsyms - ntokens);
   XFREE (state_count);
   XFREE (yydefgoto);
 }
@@ -893,15 +876,12 @@ static void
 output_base (void)
 {
   /* Output pact. */
-  output_short_table (&format_obstack, base,
-		     base[0], 1, nstates);
-  muscle_insert ("pact", obstack_finish (&format_obstack));
+  muscle_insert_short_table ("pact", base,
+			     base[0], 1, nstates);
 
   /* Output pgoto. */
-  output_short_table (&format_obstack, base,
-		     base[nstates], nstates + 1, nvectors);
-  muscle_insert ("pgoto", obstack_finish (&format_obstack));
-
+  muscle_insert_short_table ("pgoto", base,
+			     base[nstates], nstates + 1, nvectors);
   XFREE (base);
 }
 
@@ -909,9 +889,8 @@ output_base (void)
 static void
 output_table (void)
 {
-  output_short_table (&format_obstack, table,
-		     table[0], 1, high + 1);
-  muscle_insert ("table", obstack_finish (&format_obstack));
+  muscle_insert_short_table ("table", table,
+			     table[0], 1, high + 1);
   XFREE (table);
 }
 
@@ -919,9 +898,8 @@ output_table (void)
 static void
 output_check (void)
 {
-  output_short_table (&format_obstack, check,
-		     check[0], 1, high + 1);
-  muscle_insert ("check", obstack_finish (&format_obstack));
+  muscle_insert_short_table ("check", check,
+			     check[0], 1, high + 1);
   XFREE (check);
 }
 
