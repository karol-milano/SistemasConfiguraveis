@@ -33,14 +33,14 @@ relation_print (const char *title,
 {
   if (title)
     fprintf (out, "%s:\n", title);
-  for (size_t i = 0; i < size; ++i)
+  for (relation_node i = 0; i < size; ++i)
     if (r[i])
       {
         fputs ("    ", out);
         if (print)
           print (i, out);
         else
-          fprintf (out, "%3lu", (unsigned long) i);
+          fprintf (out, "%3ld", (long) i);
         fputc (':', out);
         for (relation_node j = 0; r[i][j] != END_NODE; ++j)
           {
@@ -48,7 +48,7 @@ relation_print (const char *title,
             if (print)
               print (r[i][j], out);
             else
-              fprintf (out, "%3lu", (unsigned long) r[i][j]);
+              fprintf (out, "%3ld", (long) r[i][j]);
           }
         fputc ('\n', out);
       }
