@@ -133,77 +133,50 @@ static struct obstack format_obstack;
 int error_verbose = 0;
 
 
-/*----------------------------------------------------------------.
-| Format the FIRST and then TABLE_DATA[BEGIN..END[ into OOUT, and |
-| return the number of bits needed for its longuest value.        |
-`----------------------------------------------------------------*/
-
-static inline long int
-output_short_table (struct obstack *oout,
-		    short *table_data,
-		    short first,
-		    int begin,
-		    int end)
-{
-  long int max = first;
-  int i;
-  int j = 1;
+/*------------------------------------------------------------------.
+| Create a function NAME which Format the FIRST and then            |
+| TABLE_DATA[BEGIN..END[ (of TYPE) into OOUT, and return the number |
+| of bits needed for its longuest value.                            |
+`------------------------------------------------------------------*/
 
-  obstack_fgrow1 (oout, "%6d", first);
-  for (i = begin; i < end; ++i)
-    {
-      obstack_1grow (oout, ',');
-      if (j >= 10)
-	{
-	  obstack_sgrow (oout, "\n  ");
-	  j = 1;
-	}
-      else
-	++j;
-      obstack_fgrow1 (oout, "%6d", table_data[i]);
-      if (table_data[i] > max)
-	max = table_data[i];
-    }
-  obstack_1grow (oout, 0);
 
-  return max;
+#define GENERATE_OUTPUT_TABLE(Name, Type)				\
+									\
+static inline long int							\
+Name (struct obstack *oout,						\
+      Type *table_data,							\
+      Type first,							\
+      int begin,							\
+      int end)								\
+{									\
+  long int max = first;							\
+  int i;								\
+  int j = 1;								\
+									\
+  obstack_fgrow1 (oout, "%6d", first);					\
+  for (i = begin; i < end; ++i)						\
+    {									\
+      obstack_1grow (oout, ',');					\
+      if (j >= 10)							\
+	{								\
+	  obstack_sgrow (oout, "\n  ");					\
+	  j = 1;							\
+	}								\
+      else								\
+	++j;								\
+      obstack_fgrow1 (oout, "%6d", table_data[i]);			\
+      if (table_data[i] > max)						\
+	max = table_data[i];						\
+    }									\
+  obstack_1grow (oout, 0);						\
+									\
+  return max;								\
 }
 
-
-/*--------------------.
-| Similar, for ints.  |
-`--------------------*/
-
-static inline long int
-output_int_table (struct obstack *oout,
-		  int *table_data,
-		  int first,
-		  int begin,
-		  int end)
-{
-  long int max = first;
-  int i;
-  int j = 1;
-
-  obstack_fgrow1 (oout, "%6d", first);
-  for (i = begin; i < end; ++i)
-    {
-      obstack_1grow (oout, ',');
-      if (j >= 10)
-	{
-	  obstack_sgrow (oout, "\n  ");
-	  j = 1;
-	}
-      else
-	++j;
-      obstack_fgrow1 (oout, "%6d", table_data[i]);
-      if (table_data[i] > max)
-	max = table_data[i];
-    }
-  obstack_1grow (oout, 0);
-
-  return max;
-}
+GENERATE_OUTPUT_TABLE(output_int_table, int)
+GENERATE_OUTPUT_TABLE(output_short_table, short)
+GENERATE_OUTPUT_TABLE(output_token_number_table, token_number_t)
+GENERATE_OUTPUT_TABLE(output_item_number_table, item_number_t)
 
 
 /*-----------------------------------------------------------------.
@@ -214,8 +187,9 @@ output_int_table (struct obstack *oout,
 static void
 prepare_tokens (void)
 {
-  long int max = output_short_table (&format_obstack, token_translations,
-				    0, 1, max_user_token_number + 1);
+  long int max = output_token_number_table (&format_obstack,
+					    token_translations,
+					    0, 1, max_user_token_number + 1);
   muscle_insert ("translate", obstack_finish (&format_obstack));
   MUSCLE_INSERT_LONG_INT ("token_number_max", max);
   XFREE (token_translations);
@@ -281,7 +255,7 @@ prepare_rules (void)
   int i = 0;
   item_number_t *rhs = XMALLOC (item_number_t, nritems);
   short *prhs = XMALLOC (short, nrules + 1);
-  short *r1 = XMALLOC (short, nrules + 1);
+  token_number_t *r1 = XMALLOC (token_number_t, nrules + 1);
   short *r2 = XMALLOC (short, nrules + 1);
   short *rline = XMALLOC (short, nrules + 1);
 
@@ -313,7 +287,7 @@ prepare_rules (void)
   output_short_table (&format_obstack, rline, 0, 1, nrules + 1);
   muscle_insert ("rline", obstack_finish (&format_obstack));
 
-  output_short_table (&format_obstack, r1, 0, 1, nrules + 1);
+  output_token_number_table (&format_obstack, r1, 0, 1, nrules + 1);
   muscle_insert ("r1", obstack_finish (&format_obstack));
 
   output_short_table (&format_obstack, r2, 0, 1, nrules + 1);
@@ -332,11 +306,12 @@ static void
 prepare_states (void)
 {
   size_t i;
-  short *values = (short *) alloca (sizeof (short) * nstates);
+  token_number_t *values =
+    (token_number_t *) alloca (sizeof (token_number_t) * nstates);
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
-  output_short_table (&format_obstack, values,
-		     0, 1, nstates);
+  output_token_number_table (&format_obstack, values,
+			     0, 1, nstates);
   muscle_insert ("stos", obstack_finish (&format_obstack));
 }
 
@@ -389,7 +364,7 @@ action_row (state_t *state)
      to reduce.  */
   for (i = 0; i < shiftp->nshifts; i++)
     {
-      int symbol;
+      token_number_t symbol;
       int shift_state = shiftp->shifts[i];
       if (!shift_state)
 	continue;
