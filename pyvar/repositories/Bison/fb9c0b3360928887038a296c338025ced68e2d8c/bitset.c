@@ -303,7 +303,7 @@ bitset_print (FILE *file, bitset bset, bool verbose)
   {
     if (pos > 70)
       {
-	fprintf (file, "\n");
+	fputc ('\n', file);
 	pos = 0;
       }
 
@@ -312,7 +312,7 @@ bitset_print (FILE *file, bitset bset, bool verbose)
   };
 
   if (verbose)
-    fprintf (file, "}\n");
+    fputs ("}\n", file);
 }
 
 
