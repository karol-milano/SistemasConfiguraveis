@@ -513,12 +513,12 @@ lex (void)
 }
 
 /* the following table dictates the action taken for the various %
-   directives.  A setflag value causes the named flag to be set.  A
+   directives.  A set_flag value causes the named flag to be set.  A
    retval action returns the code.  */
 struct percent_table_struct
 {
   const char *name;
-  void *setflag;
+  void *set_flag;
   int retval;
 }
 percent_table[] =
@@ -539,25 +539,26 @@ percent_table[] =
   { "semantic_parser", NULL, SEMANTIC_PARSER },
   { "pure_parser", NULL, PURE_PARSER },
   { "prec", NULL, PREC },
-  { "no_lines", &nolinesflag, NOOP},	/* -l */
-  { "raw", &rawtoknumflag, NOOP },	/* -r */
-  { "token_table", &toknumflag, NOOP},	/* -k */
+  { "locations", &locations_flag, NOOP},	/* -l */
+  { "no_lines", &no_lines_flag, NOOP},	/* -l */
+  { "raw", &raw_flag, NOOP },	/* -r */
+  { "token_table", &token_table_flag, NOOP},	/* -k */
 #if 0
     /* These can be utilized after main is reoganized so
        open_files() is deferred 'til after read_declarations().
        But %{ and %union both put information into files
        that have to be opened before read_declarations().
      */
-  { "yacc", &yaccflag, NOOP},			/* -y */
-  { "fixed_output_files", &yaccflag, NOOP},	/* -y */
-  { "defines", &definesflag, NOOP},			/* -d */
-  { "no_parser", &noparserflag, NOOP},			/* -n */
+  { "yacc", &yacc_flag, NOOP},				/* -y */
+  { "fixed_output_files", &yacc_flag, NOOP},		/* -y */
+  { "defines", &defines_flag, NOOP},			/* -d */
+  { "no_parser", &no_parser_flag, NOOP},		/* -n */
   { "output_file", &spec_outfile, SETOPT},		/* -o */
   { "file_prefix", &spec_file_prefix, SETOPT},		/* -b */
   { "name_prefix", &spec_name_prefix, SETOPT},		/* -p */
     /* These would be acceptable, but they do not affect processing */
-  { "verbose", &verboseflag, NOOP},			/* -v */
-  { "debug", &debugflag, NOOP},				/* -t */
+  { "verbose", &verbose_flag, NOOP},			/* -v */
+  { "debug", &debug_flag, NOOP},			/* -t */
 /*    {"help", <print usage stmt>, NOOP}, *//* -h */
 /*    {"version", <print version number> ,  NOOP}, *//* -V */
 #endif
@@ -629,12 +630,12 @@ parse_percent_token (void)
       break;
   if (tx->retval == SETOPT)
     {
-      *((char **) (tx->setflag)) = optarg;
+      *((char **) (tx->set_flag)) = optarg;
       return NOOP;
     }
-  if (tx->setflag)
+  if (tx->set_flag)
     {
-      *((int *) (tx->setflag)) = 1;
+      *((int *) (tx->set_flag)) = 1;
       return NOOP;
     }
   return tx->retval;
