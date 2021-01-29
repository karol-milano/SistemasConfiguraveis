@@ -461,6 +461,27 @@ type_names_output (FILE *out)
 }
 
 
+/* Define the list of start symbols *if* there are several.  Define
+   them by pairs: [START-SYMBOL-NUM, SWITCHING-TOKEN-SYMBOL-NUM]. */
+static void
+start_symbols_output (FILE *out)
+{
+  if (start_symbols && start_symbols->next)
+    {
+      fputs ("m4_define([b4_start_symbols],\n[", out);
+      for (symbol_list *list = start_symbols; list; list = list->next)
+        {
+          const symbol *start = list->content.sym;
+          const symbol *swtok = switching_token (start);
+          fprintf (out, "%s[%d, %d]",
+                   list == start_symbols ? "" : ", ",
+                   start->content->number, swtok->content->number);
+        }
+      fputs ("])\n\n", out);
+    }
+}
+
+
 /*-------------------------------------.
 | The list of all the symbol numbers.  |
 `-------------------------------------*/
@@ -691,6 +712,7 @@ muscles_output (FILE *out)
   merger_output (out);
   symbol_numbers_output (out);
   type_names_output (out);
+  start_symbols_output (out);
   user_actions_output (out);
   /* Must be last.  */
   muscles_m4_output (out);
