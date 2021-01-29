@@ -54,12 +54,11 @@ static bitsetv firsts = NULL;
 static void
 print_closure (char const *title, item_number const *array, size_t size)
 {
-  size_t i;
   fprintf (stderr, "Closure: %s\n", title);
-  for (i = 0; i < size; ++i)
+  for (size_t i = 0; i < size; ++i)
     {
-      item_number *rp;
       fprintf (stderr, "  %2d: .", array[i]);
+      item_number *rp;
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
         fprintf (stderr, " %s", symbols[*rp]->tag);
       fprintf (stderr, "  (rule %d)\n", -*rp - 1);
@@ -71,13 +70,12 @@ print_closure (char const *title, item_number const *array, size_t size)
 static void
 print_firsts (void)
 {
-  symbol_number i, j;
-
   fprintf (stderr, "FIRSTS\n");
-  for (i = ntokens; i < nsyms; i++)
+  for (symbol_number i = ntokens; i < nsyms; ++i)
     {
-      bitset_iterator iter;
       fprintf (stderr, "  %s firsts\n", symbols[i]->tag);
+      bitset_iterator iter;
+      symbol_number j;
       BITSET_FOR_EACH (iter, FIRSTS (i), j, 0)
         fprintf (stderr, "    %s\n", symbols[j + ntokens]->tag);
     }
@@ -88,14 +86,12 @@ print_firsts (void)
 static void
 print_fderives (void)
 {
-  int i;
-  rule_number r;
-
   fprintf (stderr, "FDERIVES\n");
-  for (i = ntokens; i < nsyms; i++)
+  for (symbol_number i = ntokens; i < nsyms; ++i)
     {
-      bitset_iterator iter;
       fprintf (stderr, "  %s derives\n", symbols[i]->tag);
+      bitset_iterator iter;
+      rule_number r;
       BITSET_FOR_EACH (iter, FDERIVES (i), r, 0)
         {
           fprintf (stderr, "    %3d ", r);
@@ -120,12 +116,10 @@ print_fderives (void)
 static void
 set_firsts (void)
 {
-  symbol_number i, j;
-
   firsts = bitsetv_create (nvars, nvars, BITSET_FIXED);
 
-  for (i = ntokens; i < nsyms; i++)
-    for (j = 0; derives[i - ntokens][j]; ++j)
+  for (symbol_number i = ntokens; i < nsyms; ++i)
+    for (symbol_number j = 0; derives[i - ntokens][j]; ++j)
       {
         item_number sym = derives[i - ntokens][j]->rhs[0];
         if (ISVAR (sym))
@@ -155,17 +149,14 @@ set_firsts (void)
 static void
 set_fderives (void)
 {
-  symbol_number i, j;
-  rule_number k;
-
   fderives = bitsetv_create (nvars, nrules, BITSET_FIXED);
 
   set_firsts ();
 
-  for (i = ntokens; i < nsyms; ++i)
-    for (j = ntokens; j < nsyms; ++j)
+  for (symbol_number i = ntokens; i < nsyms; ++i)
+    for (symbol_number j = ntokens; j < nsyms; ++j)
       if (bitset_test (FIRSTS (i), j - ntokens))
-        for (k = 0; derives[j - ntokens][k]; ++k)
+        for (rule_number k = 0; derives[j - ntokens][k]; ++k)
           bitset_set (FDERIVES (i), derives[j - ntokens][k]->number);
 
   if (trace_flag & trace_sets)
@@ -191,27 +182,23 @@ new_closure (unsigned int n)
 void
 closure (item_number const *core, size_t n)
 {
-  /* Index over CORE. */
-  size_t c;
-
-  /* A bit index over RULESET. */
-  rule_number ruleno;
-
-  bitset_iterator iter;
-
   if (trace_flag & trace_sets)
     print_closure ("input", core, n);
 
   bitset_zero (ruleset);
 
-  for (c = 0; c < n; ++c)
+  for (size_t c = 0; c < n; ++c)
     if (ISVAR (ritem[core[c]]))
       bitset_or (ruleset, ruleset, FDERIVES (ritem[core[c]]));
 
   /* core is sorted on item index in ritem, which is sorted on rule number.
      Compute itemset with the same sort.  */
+  /* A bit index over RULESET. */
+  rule_number ruleno;
+  bitset_iterator iter;
+
   nitemset = 0;
-  c = 0;
+  size_t c = 0;
   BITSET_FOR_EACH (iter, ruleset, ruleno, 0)
     {
       item_number itemno = rules[ruleno].rhs - ritem;
