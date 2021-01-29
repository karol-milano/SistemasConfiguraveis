@@ -246,6 +246,11 @@ usage (int status)
 	     program_name);
   else
     {
+      /* For ../build-aux/cross-options.pl to work, use the format:
+		^  -S, --long[=ARGS] (whitespace)
+	 A --long option is required.
+	 Otherwise, add exceptions to ../build-aux/cross-options.pl.  */
+
       printf (_("Usage: %s [OPTION]... FILE\n"), program_name);
       fputs (_("\
 Generate LALR(1) and GLR parsers.\n\
