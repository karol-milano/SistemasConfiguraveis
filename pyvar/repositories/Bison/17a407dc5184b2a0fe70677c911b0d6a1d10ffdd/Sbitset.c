@@ -65,14 +65,16 @@ Sbitset__fprint(Sbitset self, Sbitset__Index nbits, FILE *file)
   Sbitset__Index i;
   Sbitset itr;
   bool first = true;
-  fprintf (file, "nbits = %d, set = {", nbits);
+  fprintf (file,
+           "nbits = %" SBITSET__INDEX__CONVERSION_SPEC ", set = {",
+           nbits);
   SBITSET__FOR_EACH (self, nbits, itr, i)
     {
       if (first)
         first = false;
       else
         fprintf (file, ",");
-      fprintf (file, " %d", i);
+      fprintf (file, " %" SBITSET__INDEX__CONVERSION_SPEC, i);
     }
   fprintf (file, " }");
 }
