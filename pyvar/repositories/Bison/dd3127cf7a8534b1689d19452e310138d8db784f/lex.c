@@ -554,6 +554,7 @@ struct percent_table_struct percent_table[] =
 #endif
   { "header_extension",	NULL,			tok_hdrext},
   { "source_extension",	NULL,			tok_srcext},
+  { "define",		NULL,			tok_define },
   { "verbose",		&verbose_flag,		tok_noop },	/* -v */
   { "debug",		&debug_flag,		tok_noop },	/* -t */
   { "semantic_parser",	&semantic_parser,	tok_noop },
