@@ -121,7 +121,7 @@ static int lowzero;
 static int high;
 
 struct obstack muscle_obstack;
-struct obstack output_obstack;
+static struct obstack format_obstack;
 
 int error_verbose = 0;
 
@@ -174,9 +174,9 @@ output_table_data (struct obstack *oout,
 static void
 output_token_translations (void)
 {
-  output_table_data (&output_obstack, token_translations,
+  output_table_data (&format_obstack, token_translations,
 		     0, 1, max_user_token_number + 1);
-  muscle_insert ("translate", obstack_finish (&output_obstack));
+  muscle_insert ("translate", obstack_finish (&format_obstack));
   XFREE (token_translations);
 }
 
@@ -189,12 +189,12 @@ output_gram (void)
     short *values = XCALLOC (short, nrules + 1);
     for (i = 0; i < nrules + 1; ++i)
       values[i] = rule_table[i].rhs;
-    output_table_data (&output_obstack, values,
+    output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
     XFREE (values);
   }
 
-  muscle_insert ("prhs", obstack_finish (&output_obstack));
+  muscle_insert ("prhs", obstack_finish (&format_obstack));
 
   {
     size_t yyrhs_size = 1;
@@ -208,9 +208,9 @@ output_gram (void)
     for (sp = ritem + 1, i = 1; *sp; ++sp, ++i)
       yyrhs[i] = *sp > 0 ? *sp : 0;
 
-    output_table_data (&output_obstack, yyrhs,
+    output_table_data (&format_obstack, yyrhs,
 		       ritem[0], 1, yyrhs_size);
-    muscle_insert ("rhs", obstack_finish (&output_obstack));
+    muscle_insert ("rhs", obstack_finish (&format_obstack));
 
     XFREE (yyrhs);
   }
@@ -229,9 +229,9 @@ output_stos (void)
   short *values = (short *) alloca (sizeof (short) * nstates);
   for (i = 0; i < nstates; ++i)
     values[i] = state_table[i]->accessing_symbol;
-  output_table_data (&output_obstack, values,
+  output_table_data (&format_obstack, values,
 		     0, 1, nstates);
-  muscle_insert ("stos", obstack_finish (&output_obstack));
+  muscle_insert ("stos", obstack_finish (&format_obstack));
 }
 
 
@@ -246,9 +246,9 @@ output_rule_data (void)
     short *values = XCALLOC (short, nrules + 1);
     for (i = 0; i < nrules + 1; ++i)
       values[i] = rule_table[i].line;
-    output_table_data (&output_obstack, values,
+    output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
-    muscle_insert ("rline", obstack_finish (&output_obstack));
+    muscle_insert ("rline", obstack_finish (&format_obstack));
     XFREE (values);
   }
 
@@ -266,34 +266,34 @@ output_rule_data (void)
 
       if (j + strsize > 75)
 	{
-	  obstack_sgrow (&output_obstack, "\n  ");
+	  obstack_sgrow (&format_obstack, "\n  ");
 	  j = 2;
 	}
 
-      obstack_sgrow (&output_obstack, cp);
-      obstack_sgrow (&output_obstack, ", ");
+      obstack_sgrow (&format_obstack, cp);
+      obstack_sgrow (&format_obstack, ", ");
       j += strsize;
     }
   /* add a NULL entry to list of tokens */
-  obstack_sgrow (&output_obstack, "NULL");
+  obstack_sgrow (&format_obstack, "NULL");
 
   /* Finish table and store. */
-  obstack_1grow (&output_obstack, 0);
-  muscle_insert ("tname", obstack_finish (&output_obstack));
+  obstack_1grow (&format_obstack, 0);
+  muscle_insert ("tname", obstack_finish (&format_obstack));
 
   /* Output YYTOKNUM. */
-  output_table_data (&output_obstack, user_toknums,
+  output_table_data (&format_obstack, user_toknums,
 		     0, 1, ntokens + 1);
-  muscle_insert ("toknum", obstack_finish (&output_obstack));
+  muscle_insert ("toknum", obstack_finish (&format_obstack));
 
   /* Output YYR1. */
   {
     short *values = XCALLOC (short, nrules + 1);
     for (i = 0; i < nrules + 1; ++i)
       values[i] = rule_table[i].lhs;
-    output_table_data (&output_obstack, values,
+    output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
-    muscle_insert ("r1", obstack_finish (&output_obstack));
+    muscle_insert ("r1", obstack_finish (&format_obstack));
     XFREE (values);
   }
 
@@ -302,9 +302,9 @@ output_rule_data (void)
   for (i = 1; i < nrules; i++)
     short_tab[i] = rule_table[i + 1].rhs - rule_table[i].rhs - 1;
   short_tab[nrules] =  nitems - rule_table[nrules].rhs - 1;
-  output_table_data (&output_obstack, short_tab,
+  output_table_data (&format_obstack, short_tab,
 		     0, 1, nrules + 1);
-  muscle_insert ("r2", obstack_finish (&output_obstack));
+  muscle_insert ("r2", obstack_finish (&format_obstack));
   XFREE (short_tab);
 }
 
@@ -496,9 +496,9 @@ token_actions (void)
       save_row (i);
     }
 
-  output_table_data (&output_obstack, yydefact,
+  output_table_data (&format_obstack, yydefact,
 		     yydefact[0], 1, nstates);
-  muscle_insert ("defact", obstack_finish (&output_obstack));
+  muscle_insert ("defact", obstack_finish (&format_obstack));
 
   XFREE (actrow);
   XFREE (yydefact);
@@ -628,9 +628,9 @@ goto_actions (void)
       yydefgoto[i - ntokens] = default_state;
     }
 
-  output_table_data (&output_obstack, yydefgoto,
+  output_table_data (&format_obstack, yydefgoto,
 		     yydefgoto[0], 1, nsyms - ntokens);
-  muscle_insert ("defgoto", obstack_finish (&output_obstack));
+  muscle_insert ("defgoto", obstack_finish (&format_obstack));
 
   XFREE (state_count);
   XFREE (yydefgoto);
@@ -813,14 +813,14 @@ static void
 output_base (void)
 {
   /* Output pact. */
-  output_table_data (&output_obstack, base,
+  output_table_data (&format_obstack, base,
 		     base[0], 1, nstates);
-  muscle_insert ("pact", obstack_finish (&output_obstack));
+  muscle_insert ("pact", obstack_finish (&format_obstack));
 
   /* Output pgoto. */
-  output_table_data (&output_obstack, base,
+  output_table_data (&format_obstack, base,
 		     base[nstates], nstates + 1, nvectors);
-  muscle_insert ("pgoto", obstack_finish (&output_obstack));
+  muscle_insert ("pgoto", obstack_finish (&format_obstack));
 
   XFREE (base);
 }
@@ -829,9 +829,9 @@ output_base (void)
 static void
 output_table (void)
 {
-  output_table_data (&output_obstack, table,
+  output_table_data (&format_obstack, table,
 		     table[0], 1, high + 1);
-  muscle_insert ("table", obstack_finish (&output_obstack));
+  muscle_insert ("table", obstack_finish (&format_obstack));
   XFREE (table);
 }
 
@@ -839,9 +839,9 @@ output_table (void)
 static void
 output_check (void)
 {
-  output_table_data (&output_obstack, check,
+  output_table_data (&format_obstack, check,
 		     check[0], 1, high + 1);
-  muscle_insert ("check", obstack_finish (&output_obstack));
+  muscle_insert ("check", obstack_finish (&format_obstack));
   XFREE (check);
 }
 
@@ -1066,7 +1066,7 @@ yystype;\n\
 void
 output (void)
 {
-  obstack_init (&output_obstack);
+  obstack_init (&format_obstack);
 
   output_token_translations ();
   output_gram ();
@@ -1091,6 +1091,6 @@ output (void)
 
   free (rule_table + 1);
   obstack_free (&muscle_obstack, 0);
-  obstack_free (&output_obstack, 0);
+  obstack_free (&format_obstack, 0);
   obstack_free (&action_obstack, 0);
 }
