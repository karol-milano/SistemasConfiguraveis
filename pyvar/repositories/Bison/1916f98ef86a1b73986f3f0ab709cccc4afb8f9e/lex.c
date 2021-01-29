@@ -548,8 +548,8 @@ percent_table[] =
        But %{ and %union both put information into files
        that have to be opened before read_declarations().
      */
-  { "yacc", &fixed_outfiles, NOOP},			/* -y */
-  { "fixed_output_files", &fixed_outfiles, NOOP},	/* -y */
+  { "yacc", &yaccflag, NOOP},			/* -y */
+  { "fixed_output_files", &yaccflag, NOOP},	/* -y */
   { "defines", &definesflag, NOOP},			/* -d */
   { "no_parser", &noparserflag, NOOP},			/* -n */
   { "output_file", &spec_outfile, SETOPT},		/* -o */
