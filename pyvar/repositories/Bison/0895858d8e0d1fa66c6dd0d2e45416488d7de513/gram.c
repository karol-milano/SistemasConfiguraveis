@@ -40,7 +40,7 @@ rule_number nrules = 0;
 symbol **symbols = NULL;
 int nsyms = 0;
 int ntokens = 1;
-int nvars = 0;
+int nnterms = 0;
 
 symbol_number *token_translations = NULL;
 
@@ -192,10 +192,10 @@ grammar_rules_partial_print (FILE *out, const char *title,
       if (first)
         fprintf (out, "%s\n\n", title);
       else if (previous_rule && previous_rule->lhs != rules[r].lhs)
-        fputc ('\n', out);
+        putc ('\n', out);
       first = false;
       rule_print (&rules[r], previous_rule, out);
-      fputc ('\n', out);
+      putc ('\n', out);
       previous_rule = &rules[r];
     }
   if (!first)
@@ -241,15 +241,25 @@ grammar_rules_print_xml (FILE *out, int level)
    xml_puts (out, level + 1, "<rules/>");
 }
 
+static void
+section (FILE *out, const char *s)
+{
+  fprintf (out, "%s\n", s);
+  for (int i = strlen (s); 0 < i; --i)
+    putc ('-', out);
+  putc ('\n', out);
+  putc ('\n', out);
+}
+
 void
 grammar_dump (FILE *out, const char *title)
 {
   fprintf (out, "%s\n\n", title);
   fprintf (out,
-           "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nritems = %d\n\n",
-           ntokens, nvars, nsyms, nrules, nritems);
+           "ntokens = %d, nnterms = %d, nsyms = %d, nrules = %d, nritems = %d\n\n",
+           ntokens, nnterms, nsyms, nrules, nritems);
 
-  fprintf (out, "Tokens\n------\n\n");
+  section (out, "Tokens");
   {
     fprintf (out, "Value  Sprec  Sassoc  Tag\n");
 
@@ -261,7 +271,7 @@ grammar_dump (FILE *out, const char *title)
     fprintf (out, "\n\n");
   }
 
-  fprintf (out, "Non terminals\n-------------\n\n");
+  section (out, "Nonterminals");
   {
     fprintf (out, "Value  Tag\n");
 
@@ -271,7 +281,7 @@ grammar_dump (FILE *out, const char *title)
     fprintf (out, "\n\n");
   }
 
-  fprintf (out, "Rules\n-----\n\n");
+  section (out, "Rules");
   {
     fprintf (out,
              "Num (Prec, Assoc, Useful, UselessChain) Lhs"
@@ -293,17 +303,17 @@ grammar_dump (FILE *out, const char *title)
         /* Dumped the RHS. */
         for (item_number *rhsp = rule_i->rhs; 0 <= *rhsp; ++rhsp)
           fprintf (out, " %3d", *rhsp);
-        fputc ('\n', out);
+        putc ('\n', out);
       }
   }
   fprintf (out, "\n\n");
 
-  fprintf (out, "Rules interpreted\n-----------------\n\n");
+  section (out, "Rules interpreted");
   for (rule_number r = 0; r < nrules + nuseless_productions; ++r)
     {
       fprintf (out, "%-5d  %s:", r, rules[r].lhs->symbol->tag);
       rule_rhs_print (&rules[r], out);
-      fputc ('\n', out);
+      putc ('\n', out);
     }
   fprintf (out, "\n\n");
 }
