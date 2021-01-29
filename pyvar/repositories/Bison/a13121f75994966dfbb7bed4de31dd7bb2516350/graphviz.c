@@ -30,7 +30,7 @@
 /* Return an unambiguous printable representation for NAME, suitable
    for C strings.  Use slot 2 since the user may use slots 0 and 1.  */
 
-static char const *
+static char *
 quote (char const *name)
 {
   return quotearg_n_style (2, c_quoting_style, name);
@@ -57,12 +57,12 @@ start_graph (FILE *fout)
 void
 output_node (int id, char const *label, FILE *fout)
 {
-  fprintf (fout, "  %d [label=%s]\n", id, quote (label));
+  fprintf (fout, "  %d [label=\"%s\"]\n", id, label);
 }
 
 void
 output_edge (int source, int destination, char const *label,
-	     char const *style, FILE *fout)
+             char const *style, FILE *fout)
 {
   fprintf (fout, "  %d -> %d [style=%s", source, destination, style);
   if (label)
@@ -70,6 +70,14 @@ output_edge (int source, int destination, char const *label,
   fputs ("]\n", fout);
 }
 
+char const *
+escape (char const *name)
+{
+  char *q = quote (name);
+  q[strlen (q) - 1] = '\0';
+  return q + 1;
+}
+
 void
 finish_graph (FILE *fout)
 {
