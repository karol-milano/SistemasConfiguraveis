@@ -407,7 +407,7 @@ reduce_print (void)
 			       "%d useless rules",
 			       nuseless_productions),
 	     nuseless_productions);
-  fputc ('\n', stderr);
+  fprintf (stderr, "\n");
 }
 
 void
