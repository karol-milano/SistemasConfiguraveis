@@ -24,7 +24,6 @@
 #include "getargs.h"
 #include "symtab.h"
 #include "gram.h"
-#include "lex.h"
 #include "output.h"
 #include "options.h"
 
@@ -77,55 +76,33 @@ const struct option_table_s option_table[] =
   /* Hidden. */
   OPTN ("trace",        no,   &trace_flag,      0,     1)
 
-  /*
-   * Percent declarations.
-   */
-
-  DRTV ("token",	no,		NULL, tok_token)
-  DRTV ("term",		no,		NULL, tok_token)
-  DRTV ("nterm",	no,		NULL, tok_nterm)
-  DRTV ("type",		no,		NULL, tok_type)
-  DRTV ("union",	no,		NULL, tok_union)
-  DRTV ("expect",	no,		NULL, tok_expect)
-  DRTV ("start",	no,		NULL, tok_start)
-  DRTV ("left",		no,		NULL, tok_left)
-  DRTV ("right",	no,		NULL, tok_right)
-  DRTV ("nonassoc",	no,		NULL, tok_nonassoc)
-  DRTV ("binary",	no,		NULL, tok_nonassoc)
-  DRTV ("prec",		no,		NULL, tok_prec)
-  DRTV ("verbose",	no,     &report_flag, tok_intopt)
-  DRTV ("error-verbose",no,   &error_verbose, tok_intopt)
-
   /* FIXME: semantic parsers will output an `include' of an
      output file: be sure that the naem included is indeed the name of
      the output file.  */ /* FIXME Should we activate this options ?
      */
-  BOTH ("output",      required,     &spec_outfile, tok_stropt, 'o')
-  BOTH ("file-prefix", required, &spec_file_prefix, tok_stropt, 'b')
-  BOTH ("name-prefix", required, &spec_name_prefix, tok_stropt, 'p')
-
-  DRTV ("define",	no,	 	  NULL, tok_define)
-  DRTV ("pure-parser",	no,	  &pure_parser, tok_intopt)
+  OPTN ("output",      required,     &spec_outfile, 0, 'o')
+  OPTN ("file-prefix", required, &spec_file_prefix, 0, 'b')
+  OPTN ("name-prefix", required, &spec_name_prefix, 0, 'p')
 
   /*
    * Percent and command line declarations.
    */
 
   /* Output.  */
-  BOTH ("defines",     optional,   &defines_flag,    tok_intopt,   'd')
+  OPTN ("defines",     optional,   &defines_flag,    0,   'd')
 
   /* Operation modes.  */
-  BOTH ("fixed-output-files", no,  &yacc_flag,	     tok_intopt,   'y')
-  BOTH ("yacc",	              no,  &yacc_flag,	     tok_intopt,   'y')
+  OPTN ("fixed-output-files", no,  &yacc_flag,	     0,   'y')
+  OPTN ("yacc",	              no,  &yacc_flag,	     0,   'y')
 
   /* Parser.  */
-  BOTH ("debug",	  no,     &debug_flag,	     tok_intopt,   't')
-  BOTH ("locations",      no, &locations_flag,       tok_intopt,     1)
-  BOTH ("no-lines",       no,  &no_lines_flag,       tok_intopt,   'l')
-  BOTH ("no-parser",      no, &no_parser_flag,       tok_intopt,   'n')
-  BOTH ("raw",	          no,               0,       tok_obsolete,   0)
-  BOTH ("skeleton",       required,         0,       tok_skel,	   'S')
-  BOTH ("token-table",    no, &token_table_flag,     tok_intopt,   'k')
+  OPTN ("debug",	  no,     &debug_flag,	     0,   't')
+  OPTN ("locations",      no, &locations_flag,       0,     1)
+  OPTN ("no-lines",       no,  &no_lines_flag,       0,   'l')
+  OPTN ("no-parser",      no, &no_parser_flag,       0,   'n')
+  OPTN ("raw",	          no,               0,       0,   0)
+  OPTN ("skeleton",       required,         0,       0,	   'S')
+  OPTN ("token-table",    no, &token_table_flag,     0,   'k')
 
   {0, 0, 0, 0, 0, 0}
 };
