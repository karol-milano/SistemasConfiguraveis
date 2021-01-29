@@ -138,7 +138,7 @@ reduce_grammar ()
   print_notices();
 
   if (!BITISSET(N, start_symbol - ntokens))
-    fatals("Start symbol %s does not derive any sentence.",
+    fatals("Start symbol %s does not derive any sentence",
 	   tags[start_symbol]);
 
   reduce_grammar_tables();
@@ -593,6 +593,6 @@ print_notices ()
 	      nuseless_productions,
 	      (nuseless_productions == 1 ? "" : "s"));
     }
-  fprintf(stderr, ".\n");
+  fprintf(stderr, "\n");
   fflush(stderr);
 }
