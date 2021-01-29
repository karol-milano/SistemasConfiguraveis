@@ -283,6 +283,69 @@ prepare_states (void)
 }
 
 
+/*-------------------------------------------------------.
+| Compare two symbols by type-name, and then by number.  |
+`-------------------------------------------------------*/
+
+int
+symbol_type_name_cmp (const symbol **lhs, const symbol **rhs)
+{
+  int res = UNIQSTR_CMP((*lhs)->type_name, (*rhs)->type_name);
+  if (res)
+    return res;
+  return (*lhs)->number - (*rhs)->number;
+}
+
+
+/*----------------------------------------------------------------.
+| Return a (malloc'ed) table of the symbols sorted by type-name.  |
+`----------------------------------------------------------------*/
+
+static symbol **
+symbols_by_type_name ()
+{
+  typedef int (*qcmp_type) (const void *, const void *);
+  symbol **res = xmemdup (symbols, nsyms * sizeof *res);
+  qsort (res, nsyms, sizeof *res, (qcmp_type) &symbol_type_name_cmp);
+  return res;
+}
+
+
+/*------------------------------------------------------------------.
+| Define b4_type_names, which is a list of (lists of the numbers of |
+| symbols with same type-name).                                     |
+`------------------------------------------------------------------*/
+
+static void
+type_names_output (FILE *out)
+{
+  int i;
+  const char *isep = "";
+  symbol **syms = symbols_by_type_name ();
+  fputs ("m4_define([b4_type_names],\n[", out);
+  for (i = 0; i < nsyms; )
+    if (syms[i]->type_name)
+      {
+        int j;
+        const char *jsep = "";
+        fprintf (out, "%s[", isep);
+        isep = ",\n";
+        for (j = i; j < nsyms; ++j)
+          {
+            if (syms[i]->type_name != syms[j]->type_name)
+              break;
+            fprintf (out, "%s%d", jsep, syms[j]->number);
+            jsep = ", ";
+          }
+        fputs ("]", out);
+        i = j;
+      }
+    else
+      ++i;
+  fputs ("])\n\n", out);
+  free (syms);
+}
+
 
 /*-------------------------------------.
 | The list of all the symbol numbers.  |
@@ -523,15 +586,15 @@ static void
 muscles_output (FILE *out)
 {
   fputs ("m4_init()\n", out);
-
   merger_output (out);
   symbol_code_props_output (out, "destructors", &symbol_destructor_get);
   symbol_code_props_output (out, "printers", &symbol_printer_get);
   symbol_definitions_output (out);
   symbol_numbers_output (out);
   token_definitions_output (out);
+  type_names_output (out);
   user_actions_output (out);
-
+  // Must be last.
   muscles_m4_output (out);
 }
 
@@ -630,7 +693,6 @@ output_skeleton (void)
   free (full_m4bison);
   free (full_skeleton);
 
-
   if (trace_flag & trace_muscles)
     muscles_output (stderr);
   {
