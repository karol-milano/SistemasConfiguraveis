@@ -538,48 +538,47 @@ struct percent_table_struct
   const char *name;
   void *set_flag;
   int retval;
-}
-percent_table[] =
+};
+
+struct percent_table_struct percent_table[] =
 {
-  { "token", NULL, TOKEN },
-  { "term", NULL, TOKEN },
-  { "nterm", NULL, NTERM },
-  { "type", NULL, TYPE },
-  { "guard", NULL, GUARD },
-  { "union", NULL, UNION },
-  { "expect", NULL, EXPECT },
-  { "thong", NULL, THONG },
-  { "start", NULL, START },
-  { "left", NULL, LEFT },
-  { "right", NULL, RIGHT },
-  { "nonassoc", NULL, NONASSOC },
-  { "binary", NULL, NONASSOC },
-  { "semantic_parser", NULL, SEMANTIC_PARSER },
-  { "pure_parser", NULL, PURE_PARSER },
-  { "prec", NULL, PREC },
-  { "locations", &locations_flag, NOOP},	/* -l */
-  { "no_lines", &no_lines_flag, NOOP},	/* -l */
-  { "raw", &raw_flag, NOOP },	/* -r */
-  { "token_table", &token_table_flag, NOOP},	/* -k */
+  { "token",		NULL,			TOKEN },
+  { "term",		NULL,			TOKEN },
+  { "nterm",		NULL,			NTERM },
+  { "type",		NULL,			TYPE },
+  { "guard",		NULL,			GUARD },
+  { "union",		NULL,			UNION },
+  { "expect",		NULL,			EXPECT },
+  { "thong",		NULL,			THONG },
+  { "start",		NULL,			START },
+  { "left",		NULL,			LEFT },
+  { "right",		NULL,			RIGHT },
+  { "nonassoc",		NULL,			NONASSOC },
+  { "binary",		NULL,			NONASSOC },
+  { "prec",		NULL,			PREC },
+  { "locations",	&locations_flag,	NOOP },		/* -l */
+  { "no_lines",		&no_lines_flag,		NOOP },		/* -l */
+  { "raw",		&raw_flag,		NOOP },		/* -r */
+  { "token_table",	&token_table_flag,	NOOP },		/* -k */
+  { "yacc",		&yacc_flag,		NOOP },		/* -y */
+  { "fixed_output_files",&yacc_flag,		NOOP },		/* -y */
+  { "defines",		&defines_flag,		NOOP },		/* -d */
+  { "no_parser",	&no_parser_flag,	NOOP },		/* -n */
 #if 0
-    /* These can be utilized after main is reoganized so
-       open_files() is deferred 'til after read_declarations().
-       But %{ and %union both put information into files
-       that have to be opened before read_declarations().
-     */
-  { "yacc", &yacc_flag, NOOP},				/* -y */
-  { "fixed_output_files", &yacc_flag, NOOP},		/* -y */
-  { "defines", &defines_flag, NOOP},			/* -d */
-  { "no_parser", &no_parser_flag, NOOP},		/* -n */
-  { "output_file", &spec_outfile, SETOPT},		/* -o */
-  { "file_prefix", &spec_file_prefix, SETOPT},		/* -b */
-  { "name_prefix", &spec_name_prefix, SETOPT},		/* -p */
-    /* These would be acceptable, but they do not affect processing */
-  { "verbose", &verbose_flag, NOOP},			/* -v */
-  { "debug", &debug_flag, NOOP},			/* -t */
+  /* For the time being, this is not enabled yet, while it's possible
+     though, since we use obstacks.  The only risk is with semantic
+     parsers which will output an `include' of an output file: be sure
+     that the naem included is indeed the name of the output file.  */
+  { "output_file",	&spec_outfile,		SETOPT },	/* -o */
+  { "file_prefix",	&spec_file_prefix,	SETOPT },	/* -b */
+  { "name_prefix",	&spec_name_prefix,	SETOPT },	/* -p */
+#endif
+  { "verbose",		&verbose_flag,		NOOP },		/* -v */
+  { "debug",		&debug_flag,		NOOP },		/* -t */
+  { "semantic_parser",	&semantic_parser,	NOOP },
+  { "pure_parser",	&pure_parser,		NOOP },
 /*    {"help", <print usage stmt>, NOOP}, *//* -h */
 /*    {"version", <print version number> ,  NOOP}, *//* -V */
-#endif
   { NULL, NULL, ILLEGAL}
 };
 
@@ -646,6 +645,7 @@ parse_percent_token (void)
   for (tx = percent_table; tx->name; tx++)
     if (strcmp (token_buffer + 1, tx->name) == 0)
       break;
+
   if (tx->retval == SETOPT)
     {
       *((char **) (tx->set_flag)) = optarg;
