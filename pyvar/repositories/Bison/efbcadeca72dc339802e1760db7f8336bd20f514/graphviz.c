@@ -72,18 +72,20 @@ output_edge (int source, int destination, char const *label,
 {
   fprintf (fout, "  %d -> %d [style=%s", source, destination, style);
   if (label)
-    fprintf (fout, " label=%s", quote (label));
+    {
+      fputs (" label=\"", fout);
+      for (const char *cp = label; *cp; ++cp)
+        switch (*cp)
+        {
+        case '"':  fputs ("\\\"", fout); break;
+        case '\\': fputs ("\\\\", fout); break;
+        default:   fputc (*cp,    fout); break;
+        }
+      fputc ('"', fout);
+    }
   fputs ("]\n", fout);
 }
 
-char const *
-escape (char const *name)
-{
-  char *q = quote (name);
-  q[strlen (q) - 1] = '\0';
-  return q + 1;
-}
-
 static void
 no_reduce_bitset_init (state const *s, bitset *no_reduce_set)
 {
@@ -149,7 +151,7 @@ print_token (struct obstack *out, bool first, char const *tok)
 {
   if (! first)
     obstack_sgrow (out, ", ");
-  obstack_sgrow (out, escape (tok));
+  obstack_backslash (out, tok);
   return false;
 }
 
