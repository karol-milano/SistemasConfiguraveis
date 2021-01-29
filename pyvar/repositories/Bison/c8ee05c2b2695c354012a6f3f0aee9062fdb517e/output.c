@@ -137,6 +137,46 @@ string_output (FILE *out, char const *string)
 }
 
 
+/*----------------------------.
+| Prepare the symbols names.  |
+`----------------------------*/
+
+static void
+prepare_symbol_names (char const *muscle_name)
+{
+  /* We assume that the table will be output starting at column 2. */
+  int j = 2;
+  struct quoting_options *qo = clone_quoting_options (0);
+  set_quoting_style (qo, c_quoting_style);
+  set_quoting_flags (qo, QA_SPLIT_TRIGRAPHS);
+  for (int i = 0; i < nsyms; i++)
+    {
+      char *cp = quotearg_alloc (symbols[i]->tag, -1, qo);
+      /* Width of the next token, including the two quotes, the
+         comma and the space.  */
+      int width = strlen (cp) + 2;
+
+      if (j + width > 75)
+        {
+          obstack_sgrow (&format_obstack, "\n ");
+          j = 1;
+        }
+
+      if (i)
+        obstack_1grow (&format_obstack, ' ');
+      obstack_escape (&format_obstack, cp);
+      free (cp);
+      obstack_1grow (&format_obstack, ',');
+      j += width;
+    }
+  free (qo);
+  obstack_sgrow (&format_obstack, " ]b4_null[");
+
+  /* Finish table and store. */
+  muscle_insert (muscle_name, obstack_finish0 (&format_obstack));
+}
+
+
 /*------------------------------------------------------------------.
 | Prepare the muscles related to the symbols: translate, tname, and |
 | toknum.                                                           |
@@ -157,38 +197,7 @@ prepare_symbols (void)
                                      1, max_user_token_number + 1);
 
   /* tname -- token names.  */
-  {
-    /* We assume that the table will be output starting at column 2. */
-    int j = 2;
-    struct quoting_options *qo = clone_quoting_options (0);
-    set_quoting_style (qo, c_quoting_style);
-    set_quoting_flags (qo, QA_SPLIT_TRIGRAPHS);
-    for (int i = 0; i < nsyms; i++)
-      {
-        char *cp = quotearg_alloc (symbols[i]->tag, -1, qo);
-        /* Width of the next token, including the two quotes, the
-           comma and the space.  */
-        int width = strlen (cp) + 2;
-
-        if (j + width > 75)
-          {
-            obstack_sgrow (&format_obstack, "\n ");
-            j = 1;
-          }
-
-        if (i)
-          obstack_1grow (&format_obstack, ' ');
-        obstack_escape (&format_obstack, cp);
-        free (cp);
-        obstack_1grow (&format_obstack, ',');
-        j += width;
-      }
-    free (qo);
-    obstack_sgrow (&format_obstack, " ]b4_null[");
-
-    /* Finish table and store. */
-    muscle_insert ("tname", obstack_finish0 (&format_obstack));
-  }
+  prepare_symbol_names ("tname");
 
   /* Output YYTOKNUM. */
   {
