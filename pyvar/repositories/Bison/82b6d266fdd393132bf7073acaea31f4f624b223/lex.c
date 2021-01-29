@@ -23,6 +23,7 @@
 #include "files.h"
 #include "getopt.h"		/* for optarg */
 #include "symtab.h"
+#include "options.h"
 #include "lex.h"
 #include "xalloc.h"
 #include "complain.h"
@@ -509,60 +510,23 @@ lex (void)
     }
 }
 
-/* the following table dictates the action taken for the various %
-   directives.  A set_flag value causes the named flag to be set.  A
-   retval action returns the code.  */
-struct percent_table_struct
-{
-  const char *name;
-  void *set_flag;
-  int retval;
-};
+/* This function is a strcmp, which doesn't differentiate `-' and `_'
+   chars.  */
 
-struct percent_table_struct percent_table[] =
+static int
+option_strcmp (const char *left, const char *right)
 {
-  { "token",		NULL,			tok_token },
-  { "term",		NULL,			tok_token },
-  { "nterm",		NULL,			tok_nterm },
-  { "type",		NULL,			tok_type },
-  { "guard",		NULL,			tok_guard },
-  { "union",		NULL,			tok_union },
-  { "expect",		NULL,			tok_expect },
-  { "thong",		NULL,			tok_thong },
-  { "start",		NULL,			tok_start },
-  { "left",		NULL,			tok_left },
-  { "right",		NULL,			tok_right },
-  { "nonassoc",		NULL,			tok_nonassoc },
-  { "binary",		NULL,			tok_nonassoc },
-  { "prec",		NULL,			tok_prec },
-  { "locations",	&locations_flag,	tok_noop },	/* -l */
-  { "no_lines",		&no_lines_flag,		tok_noop },	/* -l */
-  { "raw",		NULL,			tok_obsolete },	/* -r */
-  { "token_table",	&token_table_flag,	tok_noop },	/* -k */
-  { "yacc",		&yacc_flag,		tok_noop },	/* -y */
-  { "fixed_output_files",&yacc_flag,		tok_noop },	/* -y */
-  { "defines",		&defines_flag,		tok_noop },	/* -d */
-  { "no_parser",	&no_parser_flag,	tok_noop },	/* -n */
-#if 0
-  /* For the time being, this is not enabled yet, while it's possible
-     though, since we use obstacks.  The only risk is with semantic
-     parsers which will output an `include' of an output file: be sure
-     that the naem included is indeed the name of the output file.  */
-  { "output_file",	&spec_outfile,		tok_setopt },	/* -o */
-  { "file_prefix",	&spec_file_prefix,	tok_setopt },	/* -b */
-  { "name_prefix",	&spec_name_prefix,	tok_setopt },	/* -p */
-#endif
-  { "header_extension",	NULL,			tok_hdrext },
-  { "source_extension",	NULL,			tok_srcext },
-  { "define",		NULL,			tok_define },
-  { "verbose",		&verbose_flag,		tok_noop },	/* -v */
-  { "debug",		&debug_flag,		tok_noop },	/* -t */
-  { "skeleton",		NULL,			tok_skel },	/* -S */
-  { "semantic_parser",	&semantic_parser,	tok_noop },
-  { "pure_parser",	&pure_parser,		tok_noop },
-
-  { NULL, NULL, tok_illegal}
-};
+    const unsigned char *l, *r;
+    int c;
+
+    assert(left != NULL && right != NULL);     
+    l = (const unsigned char *)left;
+    r = (const unsigned char *)right;
+    while (((c = *l - *r++) == 0 && *l != '\0')
+	   || ((*l == '-' || *l == '_') && (*r == '_' || *r == '-')))
+        l++;
+    return c;
+}
 
 /* Parse a token which starts with %.
    Assumes the % has already been read and discarded.  */
@@ -571,7 +535,7 @@ int
 parse_percent_token (void)
 {
   int c;
-  struct percent_table_struct *tx;
+  const struct option_table_struct *tx;
 
   c = getc (finput);
 
@@ -616,8 +580,9 @@ parse_percent_token (void)
   token_buffer = obstack_finish (&token_obstack);
 
   /* table lookup % directive */
-  for (tx = percent_table; tx->name; tx++)
-    if (strcmp (token_buffer + 1, tx->name) == 0)
+  for (tx = option_table; tx->name; tx++)
+    if ((tx->access == opt_percent || tx->access == opt_both)
+	&& option_strcmp (token_buffer + 1, tx->name) == 0)
       break;
 
   if (tx->set_flag)
@@ -626,7 +591,7 @@ parse_percent_token (void)
       return tok_noop;
     }
 
-  switch (tx->retval)
+  switch (tx->ret_val)
     {
     case tok_setopt:
       *((char **) (tx->set_flag)) = optarg;
@@ -638,5 +603,5 @@ parse_percent_token (void)
       break;
     }
 
-  return tx->retval;
+  return tx->ret_val;
 }
