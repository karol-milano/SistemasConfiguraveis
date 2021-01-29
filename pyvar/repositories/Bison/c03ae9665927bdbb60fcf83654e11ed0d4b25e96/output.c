@@ -276,9 +276,16 @@ output_rule_data (void)
   muscle_insert ("tname", obstack_finish (&format_obstack));
 
   /* Output YYTOKNUM. */
-  output_table_data (&format_obstack, user_toknums,
-		     0, 1, ntokens + 1);
-  muscle_insert ("toknum", obstack_finish (&format_obstack));
+  {
+    short *values = XCALLOC (short, ntokens + 1);
+    for (i = 0; i < ntokens + 1; ++i)
+      values[i] = symbols[i]->user_token_number;
+    output_table_data (&format_obstack, values,
+		       0, 1, ntokens + 1);
+    muscle_insert ("toknum", obstack_finish (&format_obstack));
+    XFREE (values);
+  }
+
 
   /* Output YYR1. */
   {
@@ -1102,7 +1109,6 @@ output (void)
   if (semantic_parser)
     output_stos ();
   output_rule_data ();
-  XFREE (user_toknums);
   output_actions ();
 
   prepare ();
