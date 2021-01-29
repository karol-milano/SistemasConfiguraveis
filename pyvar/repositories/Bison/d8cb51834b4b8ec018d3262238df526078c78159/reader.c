@@ -1650,24 +1650,6 @@ readgram (void)
   if (nrules == 0)
     fatal (_("no rules in the input grammar"));
 
-#if 0 /* This code is in the skeleton now.  */
-  /* JF put out same default YYSTYPE as YACC does */
-  if (typed == 0
-      && !value_components_used)
-    {
-      /* We used to use `unsigned long' as YYSTYPE on MSDOS,
-         but it seems better to be consistent.
-         Most programs should declare their own type anyway.  */
-      obstack_sgrow (&attrs_obstack,
-			   "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
-      if (defines_flag)
-	obstack_sgrow (&defines_obstack, "\
-# ifndef YYSTYPE\n\
-#  define YYSTYPE int\n\
-# endif\n");
-    }
-#endif
-
   /* Report any undefined symbols and consider them nonterminals.  */
 
   for (bp = firstsymbol; bp; bp = bp->next)
@@ -1747,8 +1729,6 @@ output_token_defines (struct obstack *oout)
       if (semantic_parser)
 	obstack_fgrow2 (oout, "# define\tT%s\t%d\n", symbol, bp->value);
     }
-
-  /* obstack_1grow (oout, '\n'); */
 }
 
 
@@ -1767,8 +1747,6 @@ packsymbols (void)
   int last_user_token_number;
   static char DOLLAR[] = "$";
 
-  /* int lossage = 0; JF set but not used */
-
   tags = XCALLOC (char *, nsyms + 1);
   tags[0] = DOLLAR;
   user_toknums = XCALLOC (short, nsyms + 1);
@@ -1874,8 +1852,10 @@ packsymbols (void)
   obstack_1grow (&output_obstack, 0);
   macro_insert ("tokendef", obstack_finish (&output_obstack));
 
-  /* if (!no_parser_flag)
-     output_token_defines (&table_obstack); */
+#if 0
+  if (!no_parser_flag)
+    output_token_defines (&table_obstack);
+#endif
 
   if (startval->class == unknown_sym)
     fatal (_("the start symbol %s is undefined"), startval->tag);
@@ -2053,11 +2033,6 @@ reader (void)
 #if 0
   if (defines_flag)
     reader_output_yylsp (&defines_obstack);
-#endif
-  /* Write closing delimiters for actions and guards.  */
-#if 0
-  if (locations_flag)
-    obstack_sgrow (&table_obstack, "#define YYLSP_NEEDED 1\n\n");
 #endif
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
