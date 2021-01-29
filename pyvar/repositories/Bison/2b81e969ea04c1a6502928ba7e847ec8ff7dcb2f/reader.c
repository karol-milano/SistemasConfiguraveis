@@ -474,8 +474,7 @@ reader (void)
   obstack_init (&pre_prologue_obstack);
   obstack_init (&post_prologue_obstack);
 
-  finput = xfopen (grammar_file, "r");
-  gram_in = finput;
+  gram_in = xfopen (grammar_file, "r");
 
   gram__flex_debug = trace_flag & trace_scan;
   gram_debug = trace_flag & trace_parse;
@@ -523,7 +522,7 @@ reader (void)
   if (! (nsyms <= SYMBOL_NUMBER_MAXIMUM && nsyms == ntokens + nvars))
     abort ();
 
-  xfclose (finput);
+  xfclose (gram_in);
 
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
