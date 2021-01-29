@@ -1865,6 +1865,14 @@ reader (void)
   undeftoken->class = token_sym;
   undeftoken->user_token_number = 2;
 
+  /* Initialize the obstacks. */
+  obstack_init (&action_obstack);
+  obstack_init (&attrs_obstack);
+  obstack_init (&guard_obstack);
+  obstack_init (&output_obstack);
+
+  finput = xfopen (infile, "r");
+
   /* Read the declaration section.  Copy %{ ... %} groups to
      TABLE_OBSTACK and FDEFINES file.  Also notice any %token, %left,
      etc. found there.  */
@@ -1875,6 +1883,9 @@ reader (void)
   /* Some C code is given at the end of the grammar file. */
   read_additionnal_code ();
 
+  lex_free ();
+  xfclose (finput);
+
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
