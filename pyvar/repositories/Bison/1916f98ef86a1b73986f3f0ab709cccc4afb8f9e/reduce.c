@@ -483,7 +483,7 @@ dump_grammar (void)
 static void
 print_notices (void)
 {
-  if (fixed_outfiles && nuseless_productions)
+  if (yaccflag && nuseless_productions)
     fprintf (stderr, _("%d rules never reduced\n"), nuseless_productions);
 
   fprintf (stderr, _("%s contains "), infile);
