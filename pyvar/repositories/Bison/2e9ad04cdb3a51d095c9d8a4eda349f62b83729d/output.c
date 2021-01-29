@@ -64,13 +64,10 @@ Name (char const *name,                                                 \
 {                                                                       \
   Type min = first;                                                     \
   Type max = first;                                                     \
-  long lmin;                                                        \
-  long lmax;                                                        \
-  int i;                                                                \
   int j = 1;                                                            \
                                                                         \
   obstack_printf (&format_obstack, "%6d", first);                       \
-  for (i = begin; i < end; ++i)                                         \
+  for (int i = begin; i < end; ++i)                                     \
     {                                                                   \
       obstack_1grow (&format_obstack, ',');                             \
       if (j >= 10)                                                      \
@@ -88,8 +85,8 @@ Name (char const *name,                                                 \
     }                                                                   \
   muscle_insert (name, obstack_finish0 (&format_obstack));              \
                                                                         \
-  lmin = min;                                                           \
-  lmax = max;                                                           \
+  long lmin = min;                                                      \
+  long lmax = max;                                                      \
   /* Build 'NAME_min' and 'NAME_max' in the obstack. */                 \
   obstack_printf (&format_obstack, "%s_min", name);                     \
   MUSCLE_INSERT_LONG_INT (obstack_finish0 (&format_obstack), lmin);     \
@@ -159,13 +156,12 @@ prepare_symbols (void)
 
   /* tname -- token names.  */
   {
-    int i;
     /* We assume that the table will be output starting at column 2. */
     int j = 2;
     struct quoting_options *qo = clone_quoting_options (0);
     set_quoting_style (qo, c_quoting_style);
     set_quoting_flags (qo, QA_SPLIT_TRIGRAPHS);
-    for (i = 0; i < nsyms; i++)
+    for (int i = 0; i < nsyms; i++)
       {
         char *cp = quotearg_alloc (symbols[i]->tag, -1, qo);
         /* Width of the next token, including the two quotes, the
@@ -194,9 +190,8 @@ prepare_symbols (void)
 
   /* Output YYTOKNUM. */
   {
-    int i;
     int *values = xnmalloc (ntokens, sizeof *values);
-    for (i = 0; i < ntokens; ++i)
+    for (int i = 0; i < ntokens; ++i)
       values[i] = symbols[i]->content->user_token_number;
     muscle_insert_int_table ("toknum", values,
                              values[0], 1, ntokens);
@@ -220,8 +215,7 @@ prepare_rules (void)
   int *merger = xnmalloc (nrules, sizeof *merger);
   int *immediate = xnmalloc (nrules, sizeof *immediate);
 
-  rule_number r;
-  for (r = 0; r < nrules; ++r)
+  for (rule_number r = 0; r < nrules; ++r)
     {
       /* LHS of the rule R. */
       r1[r] = rules[r].lhs->number;
@@ -262,9 +256,8 @@ prepare_rules (void)
 static void
 prepare_states (void)
 {
-  state_number i;
   symbol_number *values = xnmalloc (nstates, sizeof *values);
-  for (i = 0; i < nstates; ++i)
+  for (state_number i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
   muscle_insert_symbol_number_table ("stos", values,
                                      0, 1, nstates);
@@ -312,10 +305,9 @@ symbols_by_type_name (void)
 static void
 type_names_output (FILE *out)
 {
-  int i;
   symbol **syms = symbols_by_type_name ();
   fputs ("m4_define([b4_type_names],\n[", out);
-  for (i = 0; i < nsyms; /* nothing */)
+  for (int i = 0; i < nsyms; /* nothing */)
     {
       /* The index of the first symbol of the current type-name.  */
       int i0 = i;
@@ -337,9 +329,8 @@ type_names_output (FILE *out)
 static void
 symbol_numbers_output (FILE *out)
 {
-  int i;
   fputs ("m4_define([b4_symbol_numbers],\n[", out);
-  for (i = 0; i < nsyms; ++i)
+  for (int i = 0; i < nsyms; ++i)
     fprintf (out, "%s[%d]", i ? ", " : "", i);
   fputs ("])\n\n", out);
 }
@@ -352,10 +343,8 @@ symbol_numbers_output (FILE *out)
 static void
 user_actions_output (FILE *out)
 {
-  rule_number r;
-
   fputs ("m4_define([b4_actions], \n[", out);
-  for (r = 0; r < nrules; ++r)
+  for (rule_number r = 0; r < nrules; ++r)
     if (rules[r].action)
       {
         fprintf (out, "%s(%d, [b4_syncline(%d, ",
@@ -374,10 +363,9 @@ user_actions_output (FILE *out)
 static void
 merger_output (FILE *out)
 {
+  fputs ("m4_define([b4_mergers], \n[[", out);
   int n;
   merger_list* p;
-
-  fputs ("m4_define([b4_mergers], \n[[", out);
   for (n = 1, p = merge_functions; p != NULL; n += 1, p = p->next)
     {
       if (p->type[0] == '\0')
@@ -398,12 +386,10 @@ merger_output (FILE *out)
 static void
 prepare_symbol_definitions (void)
 {
-  int i;
-  for (i = 0; i < nsyms; ++i)
+  for (int i = 0; i < nsyms; ++i)
     {
       symbol *sym = symbols[i];
       const char *key;
-      const char *value;
 
 #define SET_KEY(Entry)                                          \
       obstack_printf (&format_obstack, "symbol(%d, %s)",        \
@@ -416,7 +402,7 @@ prepare_symbol_definitions (void)
       key = obstack_finish0 (&format_obstack);
 
       /* Whether the symbol has an identifier.  */
-      value = symbol_id_get (sym);
+      const char *value = symbol_id_get (sym);
       SET_KEY ("has_id");
       MUSCLE_INSERT_INT (key, !!value);
 
@@ -445,29 +431,26 @@ prepare_symbol_definitions (void)
       MUSCLE_INSERT_STRING (key, sym->content->type_name
                             ? sym->content->type_name : "");
 
-      {
-        int j;
-        for (j = 0; j < CODE_PROPS_SIZE; ++j)
-          {
-            /* "printer", not "%printer".  */
-            char const *pname = code_props_type_string (j) + 1;
-            code_props const *p = symbol_code_props_get (sym, j);
-            SET_KEY2 ("has", pname);
-            MUSCLE_INSERT_INT (key, !!p->code);
-
-            if (p->code)
-              {
-                SET_KEY2 (pname, "file");
-                MUSCLE_INSERT_STRING (key, p->location.start.file);
-
-                SET_KEY2 (pname, "line");
-                MUSCLE_INSERT_INT (key, p->location.start.line);
-
-                SET_KEY (pname);
-                MUSCLE_INSERT_STRING_RAW (key, p->code);
-              }
-          }
-      }
+      for (int j = 0; j < CODE_PROPS_SIZE; ++j)
+        {
+          /* "printer", not "%printer".  */
+          char const *pname = code_props_type_string (j) + 1;
+          code_props const *p = symbol_code_props_get (sym, j);
+          SET_KEY2 ("has", pname);
+          MUSCLE_INSERT_INT (key, !!p->code);
+
+          if (p->code)
+            {
+              SET_KEY2 (pname, "file");
+              MUSCLE_INSERT_STRING (key, p->location.start.file);
+
+              SET_KEY2 (pname, "line");
+              MUSCLE_INSERT_INT (key, p->location.start.line);
+
+              SET_KEY (pname);
+              MUSCLE_INSERT_STRING_RAW (key, p->code);
+            }
+        }
 #undef SET_KEY2
 #undef SET_KEY
     }
@@ -545,9 +528,6 @@ muscles_output (FILE *out)
 static void
 output_skeleton (void)
 {
-  int filter_fd[2];
-  pid_t pid;
-
   /* Compute the names of the package data dir and skeleton files.  */
   char const *m4 = (m4 = getenv ("M4")) ? m4 : M4;
   char const *datadir = pkgdatadir ();
@@ -575,6 +555,8 @@ output_skeleton (void)
      See the thread starting at
      <http://lists.gnu.org/archive/html/bug-bison/2008-07/msg00000.html>
      for details.  */
+  int filter_fd[2];
+  pid_t pid;
   {
     char const *argv[10];
     int i = 0;
