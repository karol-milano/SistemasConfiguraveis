@@ -29,7 +29,7 @@
 #include "options.h"
 
 /* Shorts options.  */
-const char *shortopts = "yvegdhrltknVo:b:p:S:";
+const char *shortopts = "yvegdhr:ltknVo:b:p:S:";
 
 /* A CLI option only.
    Arguments is the policy: `no', `optional', `required'.
@@ -52,7 +52,7 @@ const char *shortopts = "yvegdhrltknVo:b:p:S:";
     (String), (Arguments##_argument), (Var), (Token), (OptionChar) },
 
 
-const struct option_table_struct option_table[] =
+const struct option_table_s option_table[] =
 {
   /*
    * Command line.
@@ -71,6 +71,8 @@ const struct option_table_struct option_table[] =
   OPTN ("output",	required,	0,	0,   'o')
   OPTN ("output-file",	required,	0,	0,   'o')
   OPTN ("graph",	optional,	0,	0,   'g')
+  OPTN ("report",	required,   	0,	0,   'r')
+  OPTN ("verbose",	     no,	0,    	0,   'v')
 
   /* Hidden. */
   OPTN ("trace",        no,   &trace_flag,      0,     1)
@@ -92,6 +94,7 @@ const struct option_table_struct option_table[] =
   DRTV ("nonassoc",	no,		NULL, tok_nonassoc)
   DRTV ("binary",	no,		NULL, tok_nonassoc)
   DRTV ("prec",		no,		NULL, tok_prec)
+  DRTV ("verbose",	no,     &report_flag, tok_intopt)
   DRTV ("error-verbose",no,   &error_verbose, tok_intopt)
 
   /* FIXME: semantic parsers will output an `include' of an
@@ -111,7 +114,6 @@ const struct option_table_struct option_table[] =
 
   /* Output.  */
   BOTH ("defines",     optional,   &defines_flag,    tok_intopt,   'd')
-  BOTH ("verbose",	     no,   &verbose_flag,    tok_intopt,   'v')
 
   /* Operation modes.  */
   BOTH ("fixed-output-files", no,  &yacc_flag,	     tok_intopt,   'y')
@@ -122,7 +124,7 @@ const struct option_table_struct option_table[] =
   BOTH ("locations",      no, &locations_flag,       tok_intopt,     1)
   BOTH ("no-lines",       no,  &no_lines_flag,       tok_intopt,   'l')
   BOTH ("no-parser",      no, &no_parser_flag,       tok_intopt,   'n')
-  BOTH ("raw",	          no,               0,       tok_obsolete, 'r')
+  BOTH ("raw",	          no,               0,       tok_obsolete,   0)
   BOTH ("skeleton",       required,         0,       tok_skel,	   'S')
   BOTH ("token-table",    no, &token_table_flag,     tok_intopt,   'k')
 
@@ -153,17 +155,16 @@ long_option_table_new ()
     if (option_table[i].access == opt_cmd_line
 	|| option_table[i].access == opt_both)
       {
-	/* Copy the struct information in the longoptions.  */
 	res[j].name = option_table[i].name;
 	res[j].has_arg = option_table[i].has_arg;
-	/* When an options is declared having 'optional_argument' and
-	   a flag is specified to be set, the option is skipped on
-	   command line. So we never use a flag when a command line
-	   option is declared 'optional_argument.  */
+	/* When a getopt_long option has an associated variable
+	   (member FLAG), then it is set of the VAL member value.  In
+	   other words, we cannot expect getopt_long to store the
+	   argument if we also want a short option.  */
 	if (res[j].has_arg == optional_argument)
 	  res[j].flag = NULL;
 	else
-	  res[j].flag = option_table[i].set_flag;
+	  res[j].flag = option_table[i].flag;
 	res[j++].val = option_table[i].val;
       }
   res[number_options].name = NULL;
