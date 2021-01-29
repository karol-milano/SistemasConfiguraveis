@@ -61,7 +61,7 @@ output_node (int id, char const *label, FILE *fout)
 
 void
 output_edge (int source, int destination, char const *label,
-	     char const *style, FILE *fout)
+             char const *style, FILE *fout)
 {
   fprintf (fout, "  %d -> %d [style=%s", source, destination, style);
   if (label)
