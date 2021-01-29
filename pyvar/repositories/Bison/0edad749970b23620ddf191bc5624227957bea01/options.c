@@ -18,13 +18,10 @@
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.  */
 
-#include <stdio.h>
-#include "xalloc.h"
 #include "system.h"
 #include "getopt.h"
 #include "files.h"
 #include "getargs.h"
-#include "gram.h"
 #include "symtab.h"
 #include "lex.h"
 #include "output.h"
@@ -38,6 +35,27 @@ struct option *longopts = NULL;
 
 struct percent_table_struct *percent_table = NULL;
 
+/* A CLI option only.
+   Arguments is the policy: `no', `optional', `required'.
+   OptionChar is the value given to the Var if the latter is specified.  */
+#undef OPTN
+#define OPTN(OptionString, Arguments, Var, Token, OptionChar) \
+  { opt_cmd_line, \
+    (OptionString), (Arguments##_argument), (Var), (Token), (OptionChar) },
+
+/* A directive only. */
+#undef DRTV
+#define DRTV(DirectiveString, Arguments, Var, Token) \
+  { opt_percent, \
+    (DirectiveString), (Arguments##_argument), (Var), (Token), (0) },
+
+/* An option activated both by a directive and an CLI option. */
+#undef BOTH
+#define BOTH(String, Arguments, Var, Token, OptionChar) \
+  { opt_both, \
+    (String), (Arguments##_argument), (Var), (Token), (OptionChar) },
+
+
 const struct option_table_struct option_table[] =
 {
   /*
@@ -45,81 +63,74 @@ const struct option_table_struct option_table[] =
    */
 
   /* Operation modes. */
-  {opt_cmd_line, "help",      no_argument,		   0,	      0,   'h'},
-  {opt_cmd_line, "version",   no_argument,		   0,	      0,   'V'},
+  OPTN ("help",          no,		0,	0,   'h')
+  OPTN ("version",       no,		0,	0,   'V')
 
   /* Parser. */
-  /* was 'a';  apparently unused -wjh */
-  {opt_cmd_line, "name-prefix",	required_argument,	   0,	      0,   'p'},
-  {opt_cmd_line, "include",     required_argument,         0,         0,   'I'},
+  OPTN ("name-prefix",	required,	0,	0,   'p')
+  OPTN ("include",      required,       0,      0,   'I')
 
   /* Output. */
-  {opt_cmd_line, "file-prefix",	required_argument,	   0,	      0,   'b'},
-  {opt_cmd_line, "output",	required_argument,	   0,	      0,   'o'},
-  {opt_cmd_line, "output-file",	required_argument,	   0,	      0,   'o'},
-  {opt_cmd_line, "graph",	optional_argument,	   0,	      0,   'g'},
+  OPTN ("file-prefix",	required,	0,	0,   'b')
+  OPTN ("output",	required,	0,	0,   'o')
+  OPTN ("output-file",	required,	0,	0,   'o')
+  OPTN ("graph",	optional,	0,	0,   'g')
 
   /* Hidden. */
-  /* Fixme: What is this `1' doing here!!!  Sounds dead wrong.  See
-     locations too below.  */
-  {opt_cmd_line, "trace", no_argument, &trace_flag,	      0,     1},
+  OPTN ("trace",        no,   &trace_flag,      0,     1)
 
   /*
    * Percent declarations.
    */
 
-  {opt_percent, "token",		0,		NULL, tok_token,     0},
-  {opt_percent, "term",			0,		NULL, tok_token,     0},
-  {opt_percent, "nterm",		0,		NULL, tok_nterm,     0},
-  {opt_percent, "type",			0,		NULL, tok_type,      0},
-  {opt_percent, "guard",		0,		NULL, tok_guard,     0},
-  {opt_percent, "union",		0,		NULL, tok_union,     0},
-  {opt_percent, "expect",		0,		NULL, tok_expect,    0},
-  {opt_percent, "thong",		0,		NULL, tok_thong,     0},
-  {opt_percent, "start",		0,		NULL, tok_start,     0},
-  {opt_percent, "left",			0,		NULL, tok_left,      0},
-  {opt_percent, "right",		0,		NULL, tok_right,     0},
-  {opt_percent, "nonassoc",		0,		NULL, tok_nonassoc,  0},
-  {opt_percent, "binary",		0,		NULL, tok_nonassoc,  0},
-  {opt_percent, "prec",			0,		NULL, tok_prec,      0},
-  {opt_percent, "error-verbose",	0,    &error_verbose, tok_intopt,   0},
+  DRTV ("token",	no,		NULL, tok_token)
+  DRTV ("term",		no,		NULL, tok_token)
+  DRTV ("nterm",	no,		NULL, tok_nterm)
+  DRTV ("type",		no,		NULL, tok_type)
+  DRTV ("guard",	no,		NULL, tok_guard)
+  DRTV ("union",	no,		NULL, tok_union)
+  DRTV ("expect",	no,		NULL, tok_expect)
+  DRTV ("thong",	no,		NULL, tok_thong)
+  DRTV ("start",	no,		NULL, tok_start)
+  DRTV ("left",		no,		NULL, tok_left)
+  DRTV ("right",	no,		NULL, tok_right)
+  DRTV ("nonassoc",	no,		NULL, tok_nonassoc)
+  DRTV ("binary",	no,		NULL, tok_nonassoc)
+  DRTV ("prec",		no,		NULL, tok_prec)
+  DRTV ("error-verbose",no,   &error_verbose, tok_intopt)
 
   /* FIXME: semantic parsers will output an `include' of an
      output file: be sure that the naem included is indeed the name of
      the output file.  */ /* FIXME Should we activate this options ?
      */
-  {opt_both, "output", 	    required_argument, &spec_outfile, tok_stropt,  'o'},
-  {opt_both, "file-prefix", required_argument,&spec_file_prefix,tok_stropt,'b'},
-  {opt_both, "name-prefix", required_argument,&spec_name_prefix,tok_stropt,'p'},
+  BOTH ("output",      required,     &spec_outfile, tok_stropt, 'o')
+  BOTH ("file-prefix", required, &spec_file_prefix, tok_stropt, 'b')
+  BOTH ("name-prefix", required, &spec_name_prefix, tok_stropt, 'p')
 
-  {opt_percent, "define",		0,		NULL, tok_define,    0},
-  {opt_percent, "semantic-parser",	0,  &semantic_parser, tok_intopt,	     0},
-  {opt_percent, "pure-parser",		0,	&pure_parser, tok_intopt,      0},
+  DRTV ("define",	no,	 	  NULL, tok_define)
+  DRTV ("semantic-parser",no, &semantic_parser, tok_intopt)
+  DRTV ("pure-parser",	no,	  &pure_parser, tok_intopt)
 
   /*
    * Percent and command line declarations.
    */
 
-  /* FIXME Usually option use `-' to separe words on command line
-     and `_' for percent option.  But here the separator are always
-     the same, the char `-'.  */
-
   /* Output.  */
-  {opt_both, "defines",	 optional_argument,	 &defines_flag, tok_intopt,   'd'},
-  {opt_both, "verbose",	       no_argument,	 &verbose_flag, tok_intopt,   'v'},
+  BOTH ("defines",     optional,   &defines_flag,    tok_intopt,   'd')
+  BOTH ("verbose",	     no,   &verbose_flag,    tok_intopt,   'v')
 
   /* Operation modes.  */
-  {opt_both, "fixed-output-files", no_argument,  &yacc_flag, tok_intopt,   'y'},
-  {opt_both, "yacc",	       no_argument,      &yacc_flag, tok_intopt,   'y'},
+  BOTH ("fixed-output-files", no,  &yacc_flag,	     tok_intopt,   'y')
+  BOTH ("yacc",	              no,  &yacc_flag,	     tok_intopt,   'y')
 
   /* Parser.  */
-  {opt_both, "debug",	       no_argument,     &debug_flag, tok_intopt,	   't'},
-  {opt_both, "locations",      no_argument, &locations_flag, tok_intopt,       1},
-  {opt_both, "no-lines",       no_argument,  &no_lines_flag, tok_intopt,	   'l'},
-  {opt_both, "no-parser",      no_argument, &no_parser_flag, tok_intopt,	   'n'},
-  {opt_both, "raw",	       no_argument,               0, tok_obsolete, 'r'},
-  {opt_both, "skeleton",       required_argument,         0, tok_skel,	   'S'},
-  {opt_both, "token-table",    no_argument, &token_table_flag, tok_intopt,   'k'},
+  BOTH ("debug",	  no,     &debug_flag,	     tok_intopt,   't')
+  BOTH ("locations",      no, &locations_flag,       tok_intopt,     1)
+  BOTH ("no-lines",       no,  &no_lines_flag,       tok_intopt,   'l')
+  BOTH ("no-parser",      no, &no_parser_flag,       tok_intopt,   'n')
+  BOTH ("raw",	          no,               0,       tok_obsolete, 'r')
+  BOTH ("skeleton",       required,         0,       tok_skel,	   'S')
+  BOTH ("token-table",    no, &token_table_flag,     tok_intopt,   'k')
 
   {0, 0, 0, 0, 0, 0}
 };
