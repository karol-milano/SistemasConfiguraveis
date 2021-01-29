@@ -21,18 +21,22 @@
 
 
 #include "system.h"
-#include "quotearg.h"
-#include "error.h"
-#include "subpipe.h"
-#include "getargs.h"
+
+#include <error.h>
+#include <get-errno.h>
+#include <quotearg.h>
+#include <subpipe.h>
+#include <timevar.h>
+
+#include "complain.h"
 #include "files.h"
+#include "getargs.h"
 #include "gram.h"
-#include "complain.h"
+#include "muscle_tab.h"
 #include "output.h"
 #include "reader.h"
 #include "symtab.h"
 #include "tables.h"
-#include "muscle_tab.h"
 
 /* From src/scan-skel.l. */
 void scan_skel (FILE *);
@@ -100,11 +104,11 @@ Name (const char *name,							\
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_int_table, int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_short_table, short)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_base_table, base_t)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_rule_number_table, rule_number_t)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_symbol_number_table, symbol_number_t)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number_t)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_state_number_table, state_number_t)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_base_table, base_number)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_rule_number_table, rule_number)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_symbol_number_table, symbol_number)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_state_number_table, state_number)
 
 
 /*----------------------------------------------------------------------.
@@ -162,9 +166,9 @@ prepare_symbols (void)
 			    symbols[i]->tag);
 	/* Width of the next token, including the two quotes, the comma
 	   and the space.  */
-	int strsize = strlen (cp) + 2;
+	int width = strlen (cp) + 2;
 
-	if (j + strsize > 75)
+	if (j + width > 75)
 	  {
 	    obstack_sgrow (&format_obstack, "\n  ");
 	    j = 2;
@@ -172,7 +176,7 @@ prepare_symbols (void)
 
 	MUSCLE_OBSTACK_SGROW (&format_obstack, cp);
 	obstack_sgrow (&format_obstack, ", ");
-	j += strsize;
+	j += width;
       }
     /* Add a NULL entry to list of tokens (well, 0, as NULL might not be
        defined).  */
@@ -204,19 +208,19 @@ prepare_symbols (void)
 static void
 prepare_rules (void)
 {
-  rule_number_t r;
+  rule_number r;
   unsigned int i = 0;
-  item_number_t *rhs = XMALLOC (item_number_t, nritems);
+  item_number *rhs = XMALLOC (item_number, nritems);
   unsigned int *prhs = XMALLOC (unsigned int, nrules);
   unsigned int *rline = XMALLOC (unsigned int, nrules);
-  symbol_number_t *r1 = XMALLOC (symbol_number_t, nrules);
+  symbol_number *r1 = XMALLOC (symbol_number, nrules);
   unsigned int *r2 = XMALLOC (unsigned int, nrules);
   short *dprec = XMALLOC (short, nrules);
   short *merger = XMALLOC (short, nrules);
 
   for (r = 0; r < nrules; ++r)
     {
-      item_number_t *rhsp = NULL;
+      item_number *rhsp = NULL;
       /* Index of rule R in RHS. */
       prhs[r] = i;
       /* RHS of the rule R. */
@@ -264,9 +268,9 @@ prepare_rules (void)
 static void
 prepare_states (void)
 {
-  state_number_t i;
-  symbol_number_t *values =
-    (symbol_number_t *) alloca (sizeof (symbol_number_t) * nstates);
+  state_number i;
+  symbol_number *values =
+    (symbol_number *) alloca (sizeof (symbol_number) * nstates);
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
   muscle_insert_symbol_number_table ("stos", values,
@@ -286,7 +290,7 @@ prepare_states (void)
 static void
 user_actions_output (FILE *out)
 {
-  rule_number_t r;
+  rule_number r;
 
   fputs ("m4_define([b4_actions], \n[[", out);
   for (r = 0; r < nrules; ++r)
@@ -340,8 +344,8 @@ token_definitions_output (FILE *out)
   fputs ("m4_define([b4_tokens], \n[", out);
   for (i = 0; i < ntokens; ++i)
     {
-      symbol_t *symbol = symbols[i];
-      int number = symbol->user_token_number;
+      symbol *sym = symbols[i];
+      int number = sym->user_token_number;
 
       /* At this stage, if there are literal aliases, they are part of
 	 SYMBOLS, so we should not find symbols which are the aliases
@@ -350,27 +354,27 @@ token_definitions_output (FILE *out)
 	abort ();
 
       /* Skip error token.  */
-      if (symbol == errtoken)
+      if (sym == errtoken)
 	continue;
 
       /* If this string has an alias, then it is necessarily the alias
 	 which is to be output.  */
-      if (symbol->alias)
-	symbol = symbol->alias;
+      if (sym->alias)
+	sym = sym->alias;
 
       /* Don't output literal chars or strings (when defined only as a
 	 string).  Note that must be done after the alias resolution:
 	 think about `%token 'f' "f"'.  */
-      if (symbol->tag[0] == '\'' || symbol->tag[0] == '\"')
+      if (sym->tag[0] == '\'' || sym->tag[0] == '\"')
 	continue;
 
       /* Don't #define nonliteral tokens whose names contain periods
 	 or '$' (as does the default value of the EOF token).  */
-      if (strchr (symbol->tag, '.') || strchr (symbol->tag, '$'))
+      if (strchr (sym->tag, '.') || strchr (sym->tag, '$'))
 	continue;
 
       fprintf (out, "%s[[[%s]], [%d]]",
-	       first ? "" : ",\n", symbol->tag, number);
+	       first ? "" : ",\n", sym->tag, number);
 
       first = 0;
     }
@@ -392,20 +396,20 @@ symbol_destructors_output (FILE *out)
   for (i = 0; i < nsyms; ++i)
     if (symbols[i]->destructor)
       {
-	symbol_t *symbol = symbols[i];
+	symbol *sym = symbols[i];
 
 	/* Filename, lineno,
 	   Symbol-name, Symbol-number,
 	   destructor, typename. */
 	fprintf (out, "%s[",
 		 first ? "" : ",\n");
-	escaped_file_name_output (out, symbol->destructor_location.start.file);
+	escaped_file_name_output (out, sym->destructor_location.start.file);
 	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
-		 symbol->destructor_location.start.line,
-		 symbol->tag,
-		 symbol->number,
-		 symbol->destructor,
-		 symbol->type_name);
+		 sym->destructor_location.start.line,
+		 sym->tag,
+		 sym->number,
+		 sym->destructor,
+		 sym->type_name);
 
 	first = 0;
       }
@@ -427,20 +431,20 @@ symbol_printers_output (FILE *out)
   for (i = 0; i < nsyms; ++i)
     if (symbols[i]->destructor)
       {
-	symbol_t *symbol = symbols[i];
+	symbol *sym = symbols[i];
 
 	/* Filename, lineno,
 	   Symbol-name, Symbol-number,
 	   printer, typename. */
 	fprintf (out, "%s[",
 		 first ? "" : ",\n");
-	escaped_file_name_output (out, symbol->printer_location.start.file);
+	escaped_file_name_output (out, sym->printer_location.start.file);
 	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
-		 symbol->printer_location.start.line,
-		 symbol->tag,
-		 symbol->number,
-		 symbol->printer,
-		 symbol->type_name);
+		 sym->printer_location.start.line,
+		 sym->tag,
+		 sym->number,
+		 sym->printer,
+		 sym->type_name);
 
 	first = 0;
       }
@@ -551,7 +555,7 @@ output_skeleton (void)
 
   out = fdopen (filter_fd[0], "w");
   if (! out)
-    error (EXIT_FAILURE, errno, "fdopen");
+    error (EXIT_FAILURE, get_errno (), "fdopen");
 
   /* Output the definitions of all the muscles.  */
   fputs ("m4_init()\n", out);
@@ -572,7 +576,7 @@ output_skeleton (void)
   timevar_push (TV_M4);
   in = fdopen (filter_fd[1], "r");
   if (! in)
-    error (EXIT_FAILURE, errno, "fdopen");
+    error (EXIT_FAILURE, get_errno (), "fdopen");
   scan_skel (in);
   xfclose (in);
   reap_subpipe (pid, m4);
