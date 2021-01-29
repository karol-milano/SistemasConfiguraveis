@@ -27,6 +27,7 @@
 #include "gram.h"
 #include "symtab.h"
 #include "lex.h"
+#include "output.h"
 #include "options.h"
 
 /* Shorts options.  */
@@ -50,6 +51,7 @@ const struct option_table_struct option_table[] =
   /* Parser. */
   /* was 'a';  apparently unused -wjh */
   {opt_cmd_line, "name-prefix",	required_argument,	   0,	      0,   'p'},
+  {opt_cmd_line, "include",     required_argument,         0,         0,   'I'},
 
   /* Output. */
   {opt_cmd_line, "file-prefix",	required_argument,	   0,	      0,   'b'},
@@ -80,6 +82,7 @@ const struct option_table_struct option_table[] =
   {opt_percent, "nonassoc",		0,		NULL, tok_nonassoc,  0},
   {opt_percent, "binary",		0,		NULL, tok_nonassoc,  0},
   {opt_percent, "prec",			0,		NULL, tok_prec,      0},
+  {opt_percent, "error-verbose",	0,    &error_verbose, tok_intopt,   0},
 
   /* FIXME: semantic parsers will output an `include' of an
      output file: be sure that the naem included is indeed the name of
@@ -104,7 +107,6 @@ const struct option_table_struct option_table[] =
   /* Output.  */
   {opt_both, "defines",	 optional_argument,	 &defines_flag, tok_intopt,   'd'},
   {opt_both, "verbose",	       no_argument,	 &verbose_flag, tok_intopt,   'v'},
-  {opt_both, "error-verbose",  no_argument,&error_verbose_flag, tok_intopt,   'e'},
 
   /* Operation modes.  */
   {opt_both, "fixed-output-files", no_argument,  &yacc_flag, tok_intopt,   'y'},
@@ -117,7 +119,6 @@ const struct option_table_struct option_table[] =
   {opt_both, "no-parser",      no_argument, &no_parser_flag, tok_intopt,	   'n'},
   {opt_both, "raw",	       no_argument,               0, tok_obsolete, 'r'},
   {opt_both, "skeleton",       required_argument,         0, tok_skel,	   'S'},
-  {opt_both, "include",	       required_argument,         0, tok_include,  'I'},
   {opt_both, "token-table",    no_argument, &token_table_flag, tok_intopt,   'k'},
 
   {0, 0, 0, 0, 0, 0}
