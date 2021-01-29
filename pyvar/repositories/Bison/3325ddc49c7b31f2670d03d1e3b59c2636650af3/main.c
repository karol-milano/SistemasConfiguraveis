@@ -137,6 +137,11 @@ main (int argc, char *argv[])
   tables_generate ();
   timevar_pop (TV_ACTIONS);
 
+  /* Lookaheads are no longer needed. */
+  timevar_push (TV_FREE);
+  lalr_free ();
+  timevar_pop (TV_FREE);
+
   /* Output the tables and the parser to ftable.  In file output.  */
   timevar_push (TV_PARSER);
   output ();
