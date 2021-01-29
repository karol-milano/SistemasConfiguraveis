@@ -147,15 +147,19 @@ get_lines_number (const char *s)
 }
 
 
-/* FIXME. */
+/*----------------------------------------------------------------.
+| Format the FIRST and then TABLE_DATA[BEGIN..END[ into OOUT, and |
+| return the number of bits needed for its longuest value.        |
+`----------------------------------------------------------------*/
 
-static inline void
+static inline long int
 output_table_data (struct obstack *oout,
 		   short *table_data,
 		   short first,
 		   int begin,
 		   int end)
 {
+  long int max = first;
   int i;
   int j = 1;
 
@@ -171,8 +175,12 @@ output_table_data (struct obstack *oout,
       else
 	++j;
       obstack_fgrow1 (oout, "%6d", table_data[i]);
+      if (table_data[i] > max)
+	max = table_data[i];
     }
   obstack_1grow (oout, 0);
+
+  return max;
 }
 
 
@@ -184,9 +192,10 @@ output_table_data (struct obstack *oout,
 static void
 prepare_tokens (void)
 {
-  output_table_data (&format_obstack, token_translations,
-		     0, 1, max_user_token_number + 1);
+  long int max = output_table_data (&format_obstack, token_translations,
+				    0, 1, max_user_token_number + 1);
   muscle_insert ("translate", obstack_finish (&format_obstack));
+  MUSCLE_INSERT_LONG_INT ("token_number_max", max);
   XFREE (token_translations);
 
   {
