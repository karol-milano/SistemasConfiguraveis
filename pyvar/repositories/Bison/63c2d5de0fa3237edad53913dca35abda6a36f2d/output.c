@@ -1114,7 +1114,7 @@ output (void)
 #endif
   prepare ();
   /* Copy definitions in directive.  */
-  macro_insert ("definitions", obstack_finish (&attrs_obstack));
+  macro_insert ("prologue", obstack_finish (&attrs_obstack));
   output_parser ();
 
   obstack_free (&macro_obstack, 0);
