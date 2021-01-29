@@ -60,9 +60,9 @@ max_length (size_t *width, const char *str)
 `--------------------------------*/
 
 static void
-print_core (FILE *out, state *s)
+print_core (FILE *out, const state *s)
 {
-  item_index *sitems = s->items;
+  const item_index *sitems = s->items;
   size_t snritems = s->nitems;
   /* Output all the items of a state, not only its kernel.  */
   if (report_flag & report_itemsets)
@@ -100,7 +100,7 @@ print_core (FILE *out, state *s)
 `------------------------------------------------------------*/
 
 static void
-print_transitions (state *s, FILE *out, bool display_transitions_p)
+print_transitions (const state *s, FILE *out, bool display_transitions_p)
 {
   transitions *trans = s->transitions;
   size_t width = 0;
@@ -128,7 +128,7 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
       {
         symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
         const char *tag = sym->tag;
-        state *s1 = trans->states[i];
+        const state *s1 = trans->states[i];
 
         fprintf (out, "    %s", tag);
         for (int j = width - mbswidth (tag, 0); j > 0; --j)
@@ -146,7 +146,7 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
 `--------------------------------------------------------*/
 
 static void
-print_errs (FILE *out, state *s)
+print_errs (FILE *out, const state *s)
 {
   errs *errp = s->errs;
   size_t width = 0;
@@ -208,7 +208,7 @@ print_reduction (FILE *out, size_t width,
 `-------------------------------------------*/
 
 static void
-print_reductions (FILE *out, state *s)
+print_reductions (FILE *out, const state *s)
 {
   reductions *reds = s->reductions;
   if (reds->num == 0)
@@ -324,7 +324,7 @@ print_reductions (FILE *out, state *s)
 `--------------------------------------------------------------*/
 
 static void
-print_actions (FILE *out, state *s)
+print_actions (FILE *out, const state *s)
 {
   /* Print shifts.  */
   print_transitions (s, out, true);
@@ -340,7 +340,7 @@ print_actions (FILE *out, state *s)
 `----------------------------------*/
 
 static void
-print_state (FILE *out, state *s)
+print_state (FILE *out, const state *s)
 {
   fputs ("\n\n", out);
   fprintf (out, _("State %d"), s->number);
