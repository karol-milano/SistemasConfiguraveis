@@ -116,6 +116,7 @@ const struct option_table_struct option_table[] =
   {opt_both, "no-parser",      no_argument, &no_parser_flag, tok_intopt,	   'n'},
   {opt_both, "raw",	       no_argument,               0, tok_obsolete, 'r'},
   {opt_both, "skeleton",       required_argument,         0, tok_skel,	   'S'},
+  {opt_both, "include",	       required_argument,         0, tok_include,  'I'},
   {opt_both, "token-table",    no_argument, &token_table_flag, tok_intopt,   'k'},
 
   {0, 0, 0, 0, 0, 0}
