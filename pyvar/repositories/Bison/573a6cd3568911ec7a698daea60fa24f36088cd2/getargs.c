@@ -284,18 +284,6 @@ static struct option const long_options[] =
   /* Hidden. */
   { "trace",         optional_argument,   0,     'T' },
 
-  /* FIXME: semantic parsers will output an `include' of an
-     output file: be sure that the naem included is indeed the name of
-     the output file.  */ /* FIXME Should we activate this options ?
-     */
-  { "output",      required_argument,     0, 'o' },
-  { "file-prefix", required_argument,     0, 'b' },
-  { "name-prefix", required_argument,     0, 'p' },
-
-  /*
-   * Percent and command line declarations.
-   */
-
   /* Output.  */
   { "defines",     optional_argument,   0,   'd' },
 
