@@ -303,7 +303,7 @@ bitset_print (FILE *file, bitset bset, bool verbose)
   {
     if (pos > 70)
       {
-	fputc ('\n', file);
+	fprintf (file, "\n");
 	pos = 0;
       }
 
@@ -312,7 +312,7 @@ bitset_print (FILE *file, bitset bset, bool verbose)
   };
 
   if (verbose)
-    fputs ("}\n", file);
+    fprintf (file, "}\n");
 }
 
 
