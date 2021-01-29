@@ -392,18 +392,16 @@ print_nonterminal_symbols (FILE *out)
   for (symbol_number i = ntokens; i < nsyms; i++)
     {
       const char *tag = symbols[i]->tag;
-      int left_count = 0, right_count = 0;
+      bool on_left = false;
+      bool on_right = false;
 
       for (rule_number r = 0; r < nrules; r++)
         {
-          if (rules[r].lhs->number == i)
-            left_count++;
-          for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; rhsp++)
-            if (item_number_as_symbol_number (*rhsp) == i)
-              {
-                right_count++;
-                break;
-              }
+          on_left |= rules[r].lhs->number == i;
+          for (item_number *rhsp = rules[r].rhs; !on_right && 0 <= *rhsp; ++rhsp)
+            on_right |= item_number_as_symbol_number (*rhsp) == i;
+          if (on_left && on_right)
+            break;
         }
 
       int column = 4 + strlen (tag);
@@ -413,7 +411,7 @@ print_nonterminal_symbols (FILE *out)
                            symbols[i]->content->type_name);
       fprintf (out, " (%d)\n", i);
 
-      if (left_count > 0)
+      if (on_left)
         {
           fprintf (out, "%8s%s", "", _("on left:"));
           for (rule_number r = 0; r < nrules; r++)
@@ -422,11 +420,11 @@ print_nonterminal_symbols (FILE *out)
           fputc ('\n', out);
         }
 
-      if (right_count > 0)
+      if (on_right)
         {
           fprintf (out, "%8s%s", "", _("on right:"));
           for (rule_number r = 0; r < nrules; r++)
-            for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; rhsp++)
+            for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
               if (item_number_as_symbol_number (*rhsp) == i)
                 {
                   fprintf (out, " %d", r);
