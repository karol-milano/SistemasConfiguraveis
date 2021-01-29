@@ -551,6 +551,8 @@ struct percent_table_struct percent_table[] =
   { "output_file",	&spec_outfile,		tok_setopt },	/* -o */
   { "file_prefix",	&spec_file_prefix,	tok_setopt },	/* -b */
   { "name_prefix",	&spec_name_prefix,	tok_setopt },	/* -p */
+  { "header_extension",	NULL,			tok_hdrext},
+  { "source_extension",	NULL,			tok_srcext},
 #endif
   { "verbose",		&verbose_flag,		tok_noop },	/* -v */
   { "debug",		&debug_flag,		tok_noop },	/* -t */
