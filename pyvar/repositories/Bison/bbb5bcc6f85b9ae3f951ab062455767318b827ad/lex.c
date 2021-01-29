@@ -552,9 +552,8 @@ struct percent_table_struct percent_table[] =
   { "file_prefix",	&spec_file_prefix,	tok_setopt },	/* -b */
   { "name_prefix",	&spec_name_prefix,	tok_setopt },	/* -p */
 #endif
-  { "header_extension",	NULL,			tok_hdrext },
-  { "source_extension",	NULL,			tok_srcext },
-  { "define",		NULL,			tok_define },
+  { "header_extension",	NULL,			tok_hdrext},
+  { "source_extension",	NULL,			tok_srcext},
   { "verbose",		&verbose_flag,		tok_noop },	/* -v */
   { "debug",		&debug_flag,		tok_noop },	/* -t */
   { "semantic_parser",	&semantic_parser,	tok_noop },
