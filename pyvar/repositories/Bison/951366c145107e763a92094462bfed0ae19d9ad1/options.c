@@ -22,6 +22,7 @@
 #include "xalloc.h"
 #include "system.h"
 #include "getopt.h"
+#include "files.h"
 #include "getargs.h"
 #include "gram.h"
 #include "symtab.h"
@@ -52,10 +53,13 @@ const struct option_table_struct option_table[] =
 
   /* Output. */
   {opt_cmd_line, "file-prefix",	required_argument,	   0,	      0,   'b'},
+  {opt_cmd_line, "output",	required_argument,	   0,	      0,   'o'},
   {opt_cmd_line, "output-file",	required_argument,	   0,	      0,   'o'},
   {opt_cmd_line, "graph",	optional_argument,	   0,	      0,   'g'},
 
   /* Hidden. */
+  /* Fixme: What is this `1' doing here!!!  Sounds dead wrong.  See
+     locations too below.  */
   {opt_cmd_line, "statistics", no_argument, &statistics_flag,	      0,     1},
 
   /*
@@ -76,19 +80,18 @@ const struct option_table_struct option_table[] =
   {opt_percent, "nonassoc",		0,		NULL, tok_nonassoc,  0},
   {opt_percent, "binary",		0,		NULL, tok_nonassoc,  0},
   {opt_percent, "prec",			0,		NULL, tok_prec,      0},
-#if 0
-  /* For the time being, this is not enabled yet, while it's possible
-     though, since we use obstacks.  The only risk is with semantic
-     parsers which will output an `include' of an output file: be sure
-     that the naem included is indeed the name of the output file.  */
-  /* FIXME Should we activate this options ?  */
-  {opt_both, "output-file", required_argument, &spec_outfile, tok_setopt,  'o'},
-  {opt_both, "file-prefix", required_argument,&spec_file_prefix,tok_setopt,'b'},
-  {opt_both, "name-prefix", required_argument,&spec_name_prefix,tok_setopt,'p'},
-#endif
+
+  /* FIXME: semantic parsers will output an `include' of an
+     output file: be sure that the naem included is indeed the name of
+     the output file.  */ /* FIXME Should we activate this options ?
+     */
+  {opt_both, "output", 	    required_argument, &spec_outfile, tok_stropt,  'o'},
+  {opt_both, "file-prefix", required_argument,&spec_file_prefix,tok_stropt,'b'},
+  {opt_both, "name-prefix", required_argument,&spec_name_prefix,tok_stropt,'p'},
+
   {opt_percent, "define",		0,		NULL, tok_define,    0},
-  {opt_percent, "semantic-parser",	0,  &semantic_parser, tok_noop,	     0},
-  {opt_percent, "pure-parser",		0,	&pure_parser, tok_noop,      0},
+  {opt_percent, "semantic-parser",	0,  &semantic_parser, tok_intopt,	     0},
+  {opt_percent, "pure-parser",		0,	&pure_parser, tok_intopt,      0},
 
   /*
    * Percent and command line declarations.
@@ -99,21 +102,21 @@ const struct option_table_struct option_table[] =
      the same, the char `-'.  */
 
   /* Output.  */
-  {opt_both, "defines",	       optional_argument,   &defines_flag, tok_noop,	   'd'},
-  {opt_both, "verbose",	       no_argument,   &verbose_flag, tok_noop,	   'v'},
+  {opt_both, "defines",	 optional_argument,   &defines_flag, tok_intopt,   'd'},
+  {opt_both, "verbose",	       no_argument,   &verbose_flag, tok_intopt,   'v'},
 
   /* Operation modes.  */
-  {opt_both, "fixed-output-files", no_argument,  &yacc_flag, tok_noop,	   'y'},
-  {opt_both, "yacc",	       no_argument,      &yacc_flag, tok_noop,	   'y'},
+  {opt_both, "fixed-output-files", no_argument,  &yacc_flag, tok_intopt,   'y'},
+  {opt_both, "yacc",	       no_argument,      &yacc_flag, tok_intopt,   'y'},
 
   /* Parser.  */
-  {opt_both, "debug",	       no_argument,     &debug_flag, tok_noop,	   't'},
-  {opt_both, "locations",      no_argument, &locations_flag, tok_noop,       1},
-  {opt_both, "no-lines",       no_argument,  &no_lines_flag, tok_noop,	   'l'},
-  {opt_both, "no-parser",      no_argument, &no_parser_flag, tok_noop,	   'n'},
+  {opt_both, "debug",	       no_argument,     &debug_flag, tok_intopt,	   't'},
+  {opt_both, "locations",      no_argument, &locations_flag, tok_intopt,       1},
+  {opt_both, "no-lines",       no_argument,  &no_lines_flag, tok_intopt,	   'l'},
+  {opt_both, "no-parser",      no_argument, &no_parser_flag, tok_intopt,	   'n'},
   {opt_both, "raw",	       no_argument,               0, tok_obsolete, 'r'},
   {opt_both, "skeleton",       required_argument,         0, tok_skel,	   'S'},
-  {opt_both, "token-table",    no_argument, &token_table_flag, tok_noop,   'k'},
+  {opt_both, "token-table",    no_argument, &token_table_flag, tok_intopt,   'k'},
 
   {0, 0, 0, 0, 0, 0}
 };
@@ -143,7 +146,7 @@ create_long_option_table ()
 	longopts[j].name = option_table[i].name;
 	longopts[j].has_arg = option_table[i].has_arg;
 	/* When an options is declared having 'optional_argument' and
-	   a flag is specified to be set, the option is skipped on 
+	   a flag is specified to be set, the option is skipped on
 	   command line. So we never use a flag when a command line
 	   option is declared 'optional_argument.  */
 	if (longopts[j].has_arg == optional_argument)
