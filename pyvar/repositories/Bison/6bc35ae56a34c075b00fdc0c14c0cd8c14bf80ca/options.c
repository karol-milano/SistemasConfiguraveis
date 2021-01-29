@@ -86,11 +86,11 @@ const struct option_table_struct option_table[] =
   {opt_both, "file-prefix", required_argument,&spec_file_prefix,tok_setopt,'b'},
   {opt_both, "name-prefix", required_argument,&spec_name_prefix,tok_setopt,'p'},
 #endif
-  {opt_percent, "header_extension",	0,		NULL, tok_hdrext,    0},
-  {opt_percent, "source_extension",	0,		NULL, tok_srcext,    0},
+  {opt_percent, "header-extension",	0,		NULL, tok_hdrext,    0},
+  {opt_percent, "source-extension",	0,		NULL, tok_srcext,    0},
   {opt_percent, "define",		0,		NULL, tok_define,    0},
-  {opt_percent, "semantic_parser",	0,  &semantic_parser, tok_noop,	     0},
-  {opt_percent, "pure_parser",		0,	&pure_parser, tok_noop,      0},
+  {opt_percent, "semantic-parser",	0,  &semantic_parser, tok_noop,	     0},
+  {opt_percent, "pure-parser",		0,	&pure_parser, tok_noop,      0},
 
   /*
    * Percent and command line declarations.
