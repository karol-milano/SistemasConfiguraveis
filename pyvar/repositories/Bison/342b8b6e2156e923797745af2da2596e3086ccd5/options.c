@@ -45,7 +45,7 @@ const struct option_table_struct option_table[] =
   /* Operation modes. */
   {opt_cmd_line, "help",      no_argument,		   0,	      0,   'h'},
   {opt_cmd_line, "version",   no_argument,		   0,	      0,   'V'},
-  
+
   /* Parser. */
   /* was 'a';  apparently unused -wjh */
   {opt_cmd_line, "name-prefix",	required_argument,	   0,	      0,   'p'},
@@ -53,7 +53,7 @@ const struct option_table_struct option_table[] =
   /* Output. */
   {opt_cmd_line, "file-prefix",	required_argument,	   0,	      0,   'b'},
   {opt_cmd_line, "output-file",	required_argument,	   0,	      0,   'o'},
-  {opt_cmd_line, "graph",     no_argument,		   0,	      0,   'g'},
+  {opt_cmd_line, "graph",	optional_argument,	   0,	      0,   'g'},
 
   /* Hidden. */
   {opt_cmd_line, "statistics", no_argument, &statistics_flag,	      0,     1},
@@ -86,8 +86,6 @@ const struct option_table_struct option_table[] =
   {opt_both, "file-prefix", required_argument,&spec_file_prefix,tok_setopt,'b'},
   {opt_both, "name-prefix", required_argument,&spec_name_prefix,tok_setopt,'p'},
 #endif
-  {opt_percent, "header-extension",	0,		NULL, tok_hdrext,    0},
-  {opt_percent, "source-extension",	0,		NULL, tok_srcext,    0},
   {opt_percent, "define",		0,		NULL, tok_define,    0},
   {opt_percent, "semantic-parser",	0,  &semantic_parser, tok_noop,	     0},
   {opt_percent, "pure-parser",		0,	&pure_parser, tok_noop,      0},
@@ -97,11 +95,11 @@ const struct option_table_struct option_table[] =
    */
 
   /* FIXME Usually option use `-' to separe words on command line
-     and `_' for percent option.  But here the separator are always 
+     and `_' for percent option.  But here the separator are always
      the same, the char `-'.  */
 
   /* Output.  */
-  {opt_both, "defines",	       no_argument,   &defines_flag, tok_noop,	   'd'},
+  {opt_both, "defines",	       optional_argument,   &defines_flag, tok_noop,	   'd'},
   {opt_both, "verbose",	       no_argument,   &verbose_flag, tok_noop,	   'v'},
 
   /* Operation modes.  */
@@ -109,7 +107,7 @@ const struct option_table_struct option_table[] =
   {opt_both, "yacc",	       no_argument,      &yacc_flag, tok_noop,	   'y'},
 
   /* Parser.  */
-  {opt_both, "debug",	       no_argument,     &debug_flag, tok_noop,	   'd'},
+  {opt_both, "debug",	       no_argument,     &debug_flag, tok_noop,	   't'},
   {opt_both, "locations",      no_argument, &locations_flag, tok_noop,       1},
   {opt_both, "no-lines",       no_argument,  &no_lines_flag, tok_noop,	   'l'},
   {opt_both, "no-parser",      no_argument, &no_parser_flag, tok_noop,	   'n'},
