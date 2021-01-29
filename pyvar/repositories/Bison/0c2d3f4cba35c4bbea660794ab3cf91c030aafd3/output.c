@@ -184,7 +184,7 @@ Name (const char *name,							\
       int begin,							\
       int end)								\
 {									\
-  long int max = first;							\
+  Type max = first;							\
   int i;								\
   int j = 1;								\
 									\
@@ -209,10 +209,10 @@ Name (const char *name,							\
   /* Build `NAME_max' in the obstack. */				\
   obstack_fgrow1 (&format_obstack, "%s_max", name);			\
   obstack_1grow (&format_obstack, 0);					\
-  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), max);	\
+  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack),		\
+			  (long int) max);				\
 }
 
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_int_table, int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_short_table, short)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_token_number_table, token_number_t)
@@ -285,7 +285,6 @@ prepare_tokens (void)
 static void
 prepare_rules (void)
 {
-  long int max;
   int r;
   unsigned int i = 0;
   item_number_t *rhs = XMALLOC (item_number_t, nritems);
