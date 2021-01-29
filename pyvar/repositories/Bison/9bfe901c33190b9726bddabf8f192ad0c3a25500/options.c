@@ -60,7 +60,7 @@ const struct option_table_struct option_table[] =
   /* Hidden. */
   /* Fixme: What is this `1' doing here!!!  Sounds dead wrong.  See
      locations too below.  */
-  {opt_cmd_line, "statistics", no_argument, &statistics_flag,	      0,     1},
+  {opt_cmd_line, "trace", no_argument, &trace_flag,	      0,     1},
 
   /*
    * Percent declarations.
