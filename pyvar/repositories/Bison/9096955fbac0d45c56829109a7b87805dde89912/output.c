@@ -50,6 +50,10 @@ static struct obstack format_obstack;
 | result of formatting the FIRST and then TABLE_DATA[BEGIN..END[ (of |
 | TYPE), and to the muscle NAME_max, the max value of the            |
 | TABLE_DATA.                                                        |
+|                                                                    |
+| For the typical case of outputting a complete table from 0, pass   |
+| TABLE[0] as FIRST, and 1 as BEGIN.  For instance                   |
+| muscle_insert_base_table ("pact", base, base[0], 1, nstates);      |
 `-------------------------------------------------------------------*/
 
 
@@ -248,6 +252,26 @@ prepare_symbols (void)
   prepare_symbol_names ("tname");
   prepare_symbol_names ("symbol_names");
 
+  /* translatable -- whether a token is translatable. */
+  {
+    bool translatable = false;
+    for (int i = 0; i < ntokens; ++i)
+      if (symbols[i]->translatable)
+        {
+          translatable = true;
+          break;
+        }
+    if (translatable)
+      {
+        int *values = xnmalloc (nsyms, sizeof *values);
+        for (int i = 0; i < ntokens; ++i)
+          values[i] = symbols[i]->translatable;
+        muscle_insert_int_table ("translatable", values,
+                                 values[0], 1, ntokens);
+        free (values);
+      }
+  }
+
   /* Output YYTOKNUM. */
   {
     int *values = xnmalloc (ntokens, sizeof *values);
