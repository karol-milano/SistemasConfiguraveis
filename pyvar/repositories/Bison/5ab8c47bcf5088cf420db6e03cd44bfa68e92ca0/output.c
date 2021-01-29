@@ -283,6 +283,31 @@ prepare_states (void)
 
 
 
+/*-----------------------------------------------.
+| For each symbol type, its tags and type name.  |
+`-----------------------------------------------*/
+
+static void
+type_names_output (FILE *out)
+{
+  int i;
+  char const *sep = "";
+
+  fputs ("m4_define([b4_type_names],\n[", out);
+  for (i = 0; i < nsyms; ++i)
+    {
+      symbol *sym = symbols[i];
+      /* Symbol-name, Symbol-number, optional typename.  */
+      fprintf (out, "%s[", i ? ",\n" : "");
+      escaped_output (out, sym->tag);
+      fprintf (out, ", %d, [[%s]]]",
+               sym->number,
+               sym->type_name ? sym->type_name : "");
+    }
+  fputs ("])\n\n", out);
+}
+
+
 /*---------------------------------.
 | Output the user actions to OUT.  |
 `---------------------------------*/
@@ -461,7 +486,6 @@ prepare_actions (void)
   muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list,
 				    0, 1, conflict_list_cnt);
 }
-
 
 /*---------------------------.
 | Call the skeleton parser.  |
@@ -567,6 +591,7 @@ output_skeleton (void)
   /* Output the definitions of all the muscles.  */
   fputs ("m4_init()\n", out);
 
+  type_names_output (out);
   user_actions_output (out);
   merger_output (out);
   token_definitions_output (out);
