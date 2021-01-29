@@ -83,7 +83,6 @@ const struct option_table_struct option_table[] =
   DRTV ("term",		no,		NULL, tok_token)
   DRTV ("nterm",	no,		NULL, tok_nterm)
   DRTV ("type",		no,		NULL, tok_type)
-  DRTV ("guard",	no,		NULL, tok_guard)
   DRTV ("union",	no,		NULL, tok_union)
   DRTV ("expect",	no,		NULL, tok_expect)
   DRTV ("thong",	no,		NULL, tok_thong)
@@ -104,7 +103,6 @@ const struct option_table_struct option_table[] =
   BOTH ("name-prefix", required, &spec_name_prefix, tok_stropt, 'p')
 
   DRTV ("define",	no,	 	  NULL, tok_define)
-  DRTV ("semantic-parser",no, &semantic_parser, tok_intopt)
   DRTV ("pure-parser",	no,	  &pure_parser, tok_intopt)
 
   /*
