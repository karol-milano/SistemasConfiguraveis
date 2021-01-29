@@ -359,9 +359,9 @@ symbol_numbers_output (FILE *out)
 }
 
 
-/*---------------------------------.
-| Output the user actions to OUT.  |
-`---------------------------------*/
+/*-------------------------------------------.
+| Output the user reduction actions to OUT.  |
+`-------------------------------------------*/
 
 static void
 user_actions_output (FILE *out)
@@ -370,11 +370,19 @@ user_actions_output (FILE *out)
   for (rule_number r = 0; r < nrules; ++r)
     if (rules[r].action)
       {
-        fprintf (out, "%s(%d, [b4_syncline(%d, ",
+        fprintf (out, "%s(%d, [",
                  rules[r].is_predicate ? "b4_predicate_case" : "b4_case",
-                 r + 1, rules[r].action_loc.start.line);
-        string_output (out, rules[r].action_loc.start.file);
-        fprintf (out, ")dnl\n[    %s]])\n\n", rules[r].action);
+                 r + 1);
+        if (!no_lines_flag)
+          {
+            fprintf (out, "b4_syncline(%d, ",
+                     rules[r].action_loc.start.line);
+            string_output (out, rules[r].action_loc.start.file);
+            fprintf (out, ")dnl\n");
+          }
+        fprintf (out, "[%*s%s]])\n\n",
+                 rules[r].action_loc.start.column - 1, "",
+                 rules[r].action);
       }
   fputs ("])\n\n", out);
 }
@@ -482,7 +490,9 @@ prepare_symbol_definitions (void)
               muscle_location_grow (key, p->location);
 
               SET_KEY (pname);
-              MUSCLE_INSERT_STRING_RAW (key, p->code);
+              obstack_printf (&muscle_obstack,
+                              "%*s%s", p->location.start.column - 1, "", p->code);
+              muscle_insert (key, obstack_finish0 (&muscle_obstack));
             }
         }
 #undef SET_KEY2
