@@ -1,5 +1,5 @@
 /* Token-reader for Bison's input parser,
-   Copyright 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -537,7 +537,7 @@ struct percent_table_struct percent_table[] =
   { "prec",		NULL,			tok_prec },
   { "locations",	&locations_flag,	tok_noop },	/* -l */
   { "no_lines",		&no_lines_flag,		tok_noop },	/* -l */
-  { "raw",		&raw_flag,		tok_noop },	/* -r */
+  { "raw",		NULL,			tok_obsolete },	/* -r */
   { "token_table",	&token_table_flag,	tok_noop },	/* -k */
   { "yacc",		&yacc_flag,		tok_noop },	/* -y */
   { "fixed_output_files",&yacc_flag,		tok_noop },	/* -y */
@@ -616,15 +616,23 @@ parse_percent_token (void)
     if (strcmp (token_buffer + 1, tx->name) == 0)
       break;
 
-  if (tx->retval == tok_setopt)
+  if (tx->set_flag)
     {
-      *((char **) (tx->set_flag)) = optarg;
+      *((int *) (tx->set_flag)) = 1;
       return tok_noop;
     }
-  if (tx->set_flag)
+
+  switch (tx->retval)
     {
-      *((int *) (tx->set_flag)) = 1;
+    case tok_setopt:
+      *((char **) (tx->set_flag)) = optarg;
       return tok_noop;
+      break;
+
+    case tok_obsolete:
+      fatal (_("`%s' is no longer supported"), token_buffer);
+      break;
     }
+
   return tx->retval;
 }
