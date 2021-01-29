@@ -584,8 +584,7 @@ output_edge (edge *e, FILE *fout)
     fprintf (fout, "\t\tlabel:\t%s\n", quote (e->label));
 
   if (e->linestyle != E_LINESTYLE)
-    fprintf (fout, "\t\tlinestyle:\t%s\n",
-	     quote (get_linestyle_str (e->linestyle)));
+    fprintf (fout, "\t\tlinestyle:\t%s\n", get_linestyle_str (e->linestyle));
 
   if (e->thickness != E_THICKNESS)
     fprintf (fout, "\t\tthickness:\t%d\n", e->thickness);
