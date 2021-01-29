@@ -1017,16 +1017,6 @@ output_parser (void)
   xfclose (fskel);
 }
 
-static void
-output_program (void)
-{
-  int c;
-
-  while ((c = getc (finput)) != EOF)
-    obstack_1grow (&table_obstack, c);
-}
-
-
 static void
 free_itemsets (void)
 {
@@ -1122,7 +1112,6 @@ output (void)
   /* Copy definitions in directive.  */
   macro_insert ("definitions", obstack_finish (&attrs_obstack));
   output_parser ();
-  output_program ();
 
   obstack_free (&macro_obstack, 0);
   obstack_free (&output_obstack, 0);
