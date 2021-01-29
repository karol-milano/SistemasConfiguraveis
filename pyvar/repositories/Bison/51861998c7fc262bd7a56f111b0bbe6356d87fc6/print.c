@@ -357,17 +357,6 @@ print_state (FILE *out, state *s)
 | Print information on the whole grammar.  |
 `-----------------------------------------*/
 
-#define END_TEST(End)                           \
-  do {                                          \
-    if (column + strlen (buffer) > (End))       \
-      {                                         \
-        fprintf (out, "%s\n   ", buffer);       \
-        column = 3;                             \
-        buffer[0] = 0;                          \
-      }                                         \
-  } while (0)
-
-
 static void
 print_terminal_symbols (FILE *out)
 {
@@ -377,29 +366,20 @@ print_terminal_symbols (FILE *out)
     if (token_translations[i] != undeftoken->content->number)
       {
         const char *tag = symbols[token_translations[i]]->tag;
-        int column = strlen (tag);
-        char buffer[90];
-
-        buffer[0] = 0;
-        fputs (tag, out);
-        END_TEST (65);
+        fprintf (out, "%4s%s", "", tag);
         if (symbols[token_translations[i]]->content->type_name)
-          {
-            column += fprintf (out, " <%s>",
-                               symbols[token_translations[i]]->content->type_name);
-            END_TEST (65);
-          }
-        sprintf (buffer, " (%d)", i);
+          fprintf (out, " <%s>",
+                   symbols[token_translations[i]]->content->type_name);
+        fprintf (out, " (%d)", i);
 
         for (rule_number r = 0; r < nrules; r++)
           for (item_number *rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
             if (item_number_as_symbol_number (*rhsp) == token_translations[i])
               {
-                END_TEST (65);
-                sprintf (buffer + strlen (buffer), " %d", r);
+                fprintf (out, " %d", r);
                 break;
               }
-        fprintf (out, "%s\n", buffer);
+        fputc ('\n', out);
       }
   fputs ("\n\n", out);
 }
@@ -412,14 +392,13 @@ print_nonterminal_symbols (FILE *out)
   for (symbol_number i = ntokens; i < nsyms; i++)
     {
       const char *tag = symbols[i]->tag;
-      int column = strlen (tag);
       int left_count = 0, right_count = 0;
 
       for (rule_number r = 0; r < nrules; r++)
         {
           if (rules[r].lhs->number == i)
             left_count++;
-          for (item_number *rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+          for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; rhsp++)
             if (item_number_as_symbol_number (*rhsp) == i)
               {
                 right_count++;
@@ -427,49 +406,34 @@ print_nonterminal_symbols (FILE *out)
               }
         }
 
-      fputs (tag, out);
+      int column = 4 + strlen (tag);
+      fprintf (out, "%4s%s", "", tag);
       if (symbols[i]->content->type_name)
         column += fprintf (out, " <%s>",
                            symbols[i]->content->type_name);
-      char buffer[90];
-      buffer[0] = 0;
-      sprintf (buffer, " (%d)", i);
-      END_TEST (0);
+      fprintf (out, " (%d)\n", i);
 
       if (left_count > 0)
         {
-          END_TEST (65);
-          sprintf (buffer + strlen (buffer), _(" on left:"));
-
+          fprintf (out, "%8s%s", "", _("on left:"));
           for (rule_number r = 0; r < nrules; r++)
-            {
-              if (rules[r].lhs->number == i)
-                {
-                  END_TEST (65);
-                  sprintf (buffer + strlen (buffer), " %d", r);
-                }
-            }
+            if (rules[r].lhs->number == i)
+              fprintf (out, " %d", r);
+          fputc ('\n', out);
         }
 
       if (right_count > 0)
         {
-          if (left_count > 0)
-            sprintf (buffer + strlen (buffer), ",");
-          END_TEST (65);
-          sprintf (buffer + strlen (buffer), _(" on right:"));
+          fprintf (out, "%8s%s", "", _("on right:"));
           for (rule_number r = 0; r < nrules; r++)
-            {
-              item_number *rhsp;
-              for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
-                if (item_number_as_symbol_number (*rhsp) == i)
-                  {
-                    END_TEST (65);
-                    sprintf (buffer + strlen (buffer), " %d", r);
-                    break;
-                  }
-            }
+            for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; rhsp++)
+              if (item_number_as_symbol_number (*rhsp) == i)
+                {
+                  fprintf (out, " %d", r);
+                  break;
+                }
+          fputc ('\n', out);
         }
-      fprintf (out, "%s\n", buffer);
     }
 }
 
