@@ -103,7 +103,7 @@
 #include "lalr.h"
 #include "reader.h"
 #include "conflicts.h"
-#include "macrotab.h"
+#include "muscle_tab.h"
 
 extern void berror PARAMS((const char *));
 
@@ -123,7 +123,7 @@ static short *check;
 static int lowzero;
 static int high;
 
-struct obstack macro_obstack;
+struct obstack muscle_obstack;
 struct obstack output_obstack;
 
 /* FIXME. */
@@ -160,7 +160,7 @@ output_token_translations (void)
 {
   output_table_data (&output_obstack, token_translations, 
 		     0, 1, max_user_token_number + 1);
-  macro_insert ("translate", obstack_finish (&output_obstack));
+  muscle_insert ("translate", obstack_finish (&output_obstack));
 }
 
 
@@ -169,7 +169,7 @@ output_gram (void)
 {
   output_table_data (&output_obstack, rrhs, 
 		     0, 1, nrules + 1);
-  macro_insert ("prhs", obstack_finish (&output_obstack));
+  muscle_insert ("prhs", obstack_finish (&output_obstack));
   
   {
     size_t yyrhs_size = 1;
@@ -185,7 +185,7 @@ output_gram (void)
 
     output_table_data (&output_obstack, yyrhs, 
 		       ritem[0], 1, yyrhs_size);
-    macro_insert ("rhs", obstack_finish (&output_obstack));
+    muscle_insert ("rhs", obstack_finish (&output_obstack));
 
     XFREE (yyrhs);
   }
@@ -202,7 +202,7 @@ output_stos (void)
 {
   output_table_data (&output_obstack, accessing_symbol, 
 		     0, 1, nstates);
-  macro_insert ("stos", obstack_finish (&output_obstack));
+  muscle_insert ("stos", obstack_finish (&output_obstack));
 }
 
 
@@ -215,7 +215,7 @@ output_rule_data (void)
 
   output_table_data (&output_obstack, rline,
 		     0, 1, nrules + 1);
-  macro_insert ("rline", obstack_finish (&output_obstack));
+  muscle_insert ("rline", obstack_finish (&output_obstack));
 
   j = 0;
   for (i = 0; i < nsyms; i++)
@@ -267,17 +267,17 @@ output_rule_data (void)
 
   /* Finish table and store. */
   obstack_1grow (&output_obstack, 0);
-  macro_insert ("tname", obstack_finish (&output_obstack));
+  muscle_insert ("tname", obstack_finish (&output_obstack));
 
   /* Output YYTOKNUM. */
   output_table_data (&output_obstack, user_toknums,
 		     0, 1, ntokens + 1);
-  macro_insert ("toknum", obstack_finish (&output_obstack));
+  muscle_insert ("toknum", obstack_finish (&output_obstack));
 
   /* Output YYR1. */
   output_table_data (&output_obstack, rlhs, 
 		     0, 1, nrules + 1);
-  macro_insert ("r1", obstack_finish (&output_obstack));
+  muscle_insert ("r1", obstack_finish (&output_obstack));
   XFREE (rlhs + 1);
 
   /* Output YYR2. */
@@ -287,7 +287,7 @@ output_rule_data (void)
   short_tab[nrules] = nitems - rrhs[nrules] - 1;
   output_table_data (&output_obstack, short_tab, 
 		     0, 1, nrules + 1);
-  macro_insert ("r2", obstack_finish (&output_obstack));
+  muscle_insert ("r2", obstack_finish (&output_obstack));
   XFREE (short_tab);
 
   XFREE (rrhs + 1);
@@ -536,7 +536,7 @@ token_actions (void)
 
   output_table_data (&output_obstack, yydefact, 
 		     yydefact[0], 1, nstates);
-  macro_insert ("defact", obstack_finish (&output_obstack));
+  muscle_insert ("defact", obstack_finish (&output_obstack));
   
   XFREE (actrow);
   XFREE (yydefact);
@@ -677,7 +677,7 @@ goto_actions (void)
 
   output_table_data (&output_obstack, yydefgoto, 
 		     yydefgoto[0], 1, nsyms - ntokens);
-  macro_insert ("defgoto", obstack_finish (&output_obstack));
+  muscle_insert ("defgoto", obstack_finish (&output_obstack));
 
   XFREE (state_count);
   XFREE (yydefgoto);
@@ -882,12 +882,12 @@ output_base (void)
   /* Output pact. */
   output_table_data (&output_obstack, base, 
 		     base[0], 1, nstates);
-  macro_insert ("pact", obstack_finish (&output_obstack));
+  muscle_insert ("pact", obstack_finish (&output_obstack));
 
   /* Output pgoto. */
   output_table_data (&output_obstack, base, 
 		     base[nstates], nstates + 1, nvectors);
-  macro_insert ("pgoto", obstack_finish (&output_obstack));
+  muscle_insert ("pgoto", obstack_finish (&output_obstack));
 
   XFREE (base);
 }
@@ -898,7 +898,7 @@ output_table (void)
 {
   output_table_data (&output_obstack, table, 
 		     table[0], 1, high + 1);
-  macro_insert ("table", obstack_finish (&output_obstack));
+  muscle_insert ("table", obstack_finish (&output_obstack));
   XFREE (table);
 }
 
@@ -908,7 +908,7 @@ output_check (void)
 {
   output_table_data (&output_obstack, check, 
 		     check[0], 1, high + 1);
-  macro_insert ("check", obstack_finish (&output_obstack));
+  muscle_insert ("check", obstack_finish (&output_obstack));
   XFREE (check);
 }
 
@@ -983,21 +983,21 @@ output_parser (void)
 	}
       else if ((c = getc (fskel)) == '%')
 	{
-	  /* Read the macro.  */
-	  const char *macro_key = 0;
-	  const char *macro_value = 0;
+	  /* Read the muscle.  */
+	  const char *muscle_key = 0;
+	  const char *muscle_value = 0;
 	  while (isalnum (c = getc (fskel)) || c == '_')
-	    obstack_1grow (&macro_obstack, c);
-	  obstack_1grow (&macro_obstack, 0);
+	    obstack_1grow (&muscle_obstack, c);
+	  obstack_1grow (&muscle_obstack, 0);
 
 	  /* Output the right value, or see if it's something special.  */
-	  macro_key = obstack_finish (&macro_obstack);
-	  macro_value = macro_find (macro_key);
-	  if (macro_value)
-	    obstack_sgrow (&table_obstack, macro_value);
-	  else if (!strcmp (macro_key, "line"))
+	  muscle_key = obstack_finish (&muscle_obstack);
+	  muscle_value = muscle_find (muscle_key);
+	  if (muscle_value)
+	    obstack_sgrow (&table_obstack, muscle_value);
+	  else if (!strcmp (muscle_key, "line"))
 	    obstack_fgrow1 (&table_obstack, "%d", line + 1);
-	  else if (!strcmp (macro_key, "action"))
+	  else if (!strcmp (muscle_key, "action"))
 	    {
 	      size_t size = obstack_object_size (&action_obstack);
 	      obstack_grow (&table_obstack, 
@@ -1006,7 +1006,7 @@ output_parser (void)
 	  else
 	    {
 	      obstack_sgrow (&table_obstack, "%%");
-	      obstack_sgrow (&table_obstack, macro_key);
+	      obstack_sgrow (&table_obstack, muscle_key);
 	    }
 	}
       else
@@ -1033,49 +1033,49 @@ free_itemsets (void)
 
 /* FIXME. */
 
-#define MACRO_INSERT_INT(Key, Value)			\
-{							\
-  obstack_fgrow1 (&macro_obstack, "%d", Value);		\
-  obstack_1grow (&macro_obstack, 0);			\
-  macro_insert (Key, obstack_finish (&macro_obstack));	\
+#define MUSCLE_INSERT_INT(Key, Value)				\
+{								\
+  obstack_fgrow1 (&muscle_obstack, "%d", Value);	       	\
+  obstack_1grow (&muscle_obstack, 0);				\
+  muscle_insert (Key, obstack_finish (&muscle_obstack));	\
 }
 
-#define MACRO_INSERT_STRING(Key, Value)			\
-{							\
-  obstack_sgrow (&macro_obstack, Value);		\
-  obstack_1grow (&macro_obstack, 0);			\
-  macro_insert (Key, obstack_finish (&macro_obstack));	\
+#define MUSCLE_INSERT_STRING(Key, Value)			\
+{								\
+  obstack_sgrow (&muscle_obstack, Value);			\
+  obstack_1grow (&muscle_obstack, 0);				\
+  muscle_insert (Key, obstack_finish (&muscle_obstack));	\
 }
 
-#define MACRO_INSERT_PREFIX(Key, Value)					\
+#define MUSCLE_INSERT_PREFIX(Key, Value)	       			\
 {									\
-  obstack_fgrow2 (&macro_obstack, "%s%s", spec_name_prefix, Value);	\
-  obstack_1grow (&macro_obstack, 0);					\
-  macro_insert (Key, obstack_finish (&macro_obstack));			\
+  obstack_fgrow2 (&muscle_obstack, "%s%s", spec_name_prefix, Value);	\
+  obstack_1grow (&muscle_obstack, 0);					\
+  muscle_insert (Key, obstack_finish (&muscle_obstack));	       	\
 }
 
 static void
 prepare (void)
 {
-  MACRO_INSERT_INT ("last", high);
-  MACRO_INSERT_INT ("flag", MINSHORT);
-  MACRO_INSERT_INT ("pure", pure_parser);
-  MACRO_INSERT_INT ("nsym", nsyms);
-  MACRO_INSERT_INT ("debug", debug_flag);
-  MACRO_INSERT_INT ("final", final_state);
-  MACRO_INSERT_INT ("maxtok", max_user_token_number);
-  MACRO_INSERT_INT ("ntbase", ntokens);
-  MACRO_INSERT_INT ("verbose", 0);
-
-  MACRO_INSERT_INT ("nnts", nvars);
-  MACRO_INSERT_INT ("nrules", nrules);
-  MACRO_INSERT_INT ("nstates", nstates);
-  MACRO_INSERT_INT ("ntokens", ntokens);
-
-  MACRO_INSERT_INT ("locations_flag", locations_flag);
+  MUSCLE_INSERT_INT ("last", high);
+  MUSCLE_INSERT_INT ("flag", MINSHORT);
+  MUSCLE_INSERT_INT ("pure", pure_parser);
+  MUSCLE_INSERT_INT ("nsym", nsyms);
+  MUSCLE_INSERT_INT ("debug", debug_flag);
+  MUSCLE_INSERT_INT ("final", final_state);
+  MUSCLE_INSERT_INT ("maxtok", max_user_token_number);
+  MUSCLE_INSERT_INT ("ntbase", ntokens);
+  MUSCLE_INSERT_INT ("verbose", 0);
+
+  MUSCLE_INSERT_INT ("nnts", nvars);
+  MUSCLE_INSERT_INT ("nrules", nrules);
+  MUSCLE_INSERT_INT ("nstates", nstates);
+  MUSCLE_INSERT_INT ("ntokens", ntokens);
+
+  MUSCLE_INSERT_INT ("locations_flag", locations_flag);
 
   if (spec_name_prefix)
-    MACRO_INSERT_STRING ("prefix", spec_name_prefix);
+    MUSCLE_INSERT_STRING ("prefix", spec_name_prefix);
 }
 
 /*----------------------------------------------------------.
@@ -1106,9 +1106,9 @@ output (void)
 #endif
   prepare ();
   /* Copy definitions in directive.  */
-  macro_insert ("prologue", obstack_finish (&attrs_obstack));
+  muscle_insert ("prologue", obstack_finish (&attrs_obstack));
   output_parser ();
 
-  obstack_free (&macro_obstack, 0);
+  obstack_free (&muscle_obstack, 0);
   obstack_free (&output_obstack, 0);
 }
