@@ -34,10 +34,10 @@ relation_print (relation r, relation_node size, FILE *out)
 
   for (i = 0; i < size; ++i)
     {
-      fprintf (out, "%3lu: ", (unsigned long int) i);
+      fprintf (out, "%3lu: ", (unsigned long) i);
       if (r[i])
         for (j = 0; r[i][j] != END_NODE; ++j)
-          fprintf (out, "%3lu ", (unsigned long int) r[i][j]);
+          fprintf (out, "%3lu ", (unsigned long) r[i][j]);
       fputc ('\n', out);
     }
   fputc ('\n', out);
