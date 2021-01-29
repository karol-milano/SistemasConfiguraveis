@@ -153,7 +153,7 @@ bitsetv_dump (FILE *file, char const *title, char const *subtitle,
       bitset_dump (file, bsetv[i]);
     }
 
-  fputc ('\n', file);
+  fprintf (file, "\n");
 }
 
 
@@ -168,5 +168,5 @@ debug_bitsetv (bitsetv bsetv)
       debug_bitset (bsetv[i]);
     }
 
-  fputc ('\n', stderr);
+  fprintf (stderr, "\n");
 }