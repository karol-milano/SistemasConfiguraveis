@@ -407,7 +407,7 @@ reduce_print (void)
 			       "%d useless rules",
 			       nuseless_productions),
 	     nuseless_productions);
-  fprintf (stderr, "\n");
+  fputc ('\n', stderr);
 }
 
 void
