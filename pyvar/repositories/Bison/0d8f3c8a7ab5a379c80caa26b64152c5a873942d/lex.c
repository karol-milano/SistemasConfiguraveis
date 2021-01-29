@@ -535,14 +535,14 @@ struct percent_table_struct percent_table[] =
   { "nonassoc",		NULL,			tok_nonassoc },
   { "binary",		NULL,			tok_nonassoc },
   { "prec",		NULL,			tok_prec },
-  { "locations",	&locations_flag,	tok_noop },		/* -l */
-  { "no_lines",		&no_lines_flag,		tok_noop },		/* -l */
-  { "raw",		&raw_flag,		tok_noop },		/* -r */
-  { "token_table",	&token_table_flag,	tok_noop },		/* -k */
-  { "yacc",		&yacc_flag,		tok_noop },		/* -y */
-  { "fixed_output_files",&yacc_flag,		tok_noop },		/* -y */
-  { "defines",		&defines_flag,		tok_noop },		/* -d */
-  { "no_parser",	&no_parser_flag,	tok_noop },		/* -n */
+  { "locations",	&locations_flag,	tok_noop },	/* -l */
+  { "no_lines",		&no_lines_flag,		tok_noop },	/* -l */
+  { "raw",		&raw_flag,		tok_noop },	/* -r */
+  { "token_table",	&token_table_flag,	tok_noop },	/* -k */
+  { "yacc",		&yacc_flag,		tok_noop },	/* -y */
+  { "fixed_output_files",&yacc_flag,		tok_noop },	/* -y */
+  { "defines",		&defines_flag,		tok_noop },	/* -d */
+  { "no_parser",	&no_parser_flag,	tok_noop },	/* -n */
 #if 0
   /* For the time being, this is not enabled yet, while it's possible
      though, since we use obstacks.  The only risk is with semantic
@@ -552,12 +552,11 @@ struct percent_table_struct percent_table[] =
   { "file_prefix",	&spec_file_prefix,	tok_setopt },	/* -b */
   { "name_prefix",	&spec_name_prefix,	tok_setopt },	/* -p */
 #endif
-  { "verbose",		&verbose_flag,		tok_noop },		/* -v */
-  { "debug",		&debug_flag,		tok_noop },		/* -t */
+  { "verbose",		&verbose_flag,		tok_noop },	/* -v */
+  { "debug",		&debug_flag,		tok_noop },	/* -t */
   { "semantic_parser",	&semantic_parser,	tok_noop },
   { "pure_parser",	&pure_parser,		tok_noop },
-/*    {"help", <print usage stmt>, tok_noop}, *//* -h */
-/*    {"version", <print version number> ,  tok_noop}, *//* -V */
+
   { NULL, NULL, tok_illegal}
 };
 
