@@ -34,7 +34,6 @@
 #include "output.h"
 #include "reader.h"
 #include "conflicts.h"
-#include "macrotab.h"
 
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
 static int rline_allocated;
@@ -157,12 +156,11 @@ get_type_name (int n, symbol_list * rule)
 `------------------------------------------------------------*/
 
 static inline void
-copy_string2 (FILE *fin, struct obstack *oout, int match, int store)
+copy_string (FILE *fin, struct obstack *oout, int match)
 {
   int c;
 
-  if (store)
-    obstack_1grow (oout, match);
+  obstack_1grow (oout, match);
 
   c = getc (fin);
 
@@ -194,30 +192,9 @@ copy_string2 (FILE *fin, struct obstack *oout, int match, int store)
       c = getc (fin);
     }
 
-  if (store)
-    obstack_1grow (oout, c);
-}
-
-/* FIXME. */
-
-static inline void
-copy_string (FILE *fin, struct obstack *oout, int match)
-{
-  copy_string2 (fin, oout, match, 1);
+  obstack_1grow (oout, c);
 }
 
-/* FIXME. */
-
-static inline void
-copy_identifier (FILE *fin, struct obstack *oout)
-{
-  int c;
-
-  while (isalnum (c = getc (fin)) || c == '_')
-    obstack_1grow (oout, c);
-
-  ungetc (c, fin);
-}
 
 /*-----------------------------------------------------------------.
 | Dump the wannabee comment from IN to OUT1 and OUT2 (which can be |
@@ -426,11 +403,9 @@ copy_definition (void)
   /* -1 while reading a character if prev char was %. */
   int after_percent;
 
-#if 0
   if (!no_lines_flag)
     obstack_fgrow2 (&attrs_obstack, "#line %d %s\n",
 		    lineno, quotearg_style (c_quoting_style, infile));
-#endif
 
   after_percent = 0;
 
@@ -899,51 +874,6 @@ parse_thong_decl (void)
   nsyms--;
 }
 
-/* FIXME. */
-
-static void
-parse_macro_decl (void)
-{
-  int ch = ungetc (skip_white_space (), finput);
-  char* macro_key;
-  char* macro_value;
-  struct obstack macro_obstack;
-
-  obstack_init (&macro_obstack);
-
-  /* Read key. */
-  if (!isalpha (ch) && ch != '_')
-    {
-      complain (_("invalid %s declaration"), "%define");
-      skip_to_char ('%');
-      return;
-    }
-  copy_identifier (finput, &macro_obstack);
-  macro_key = obstack_finish (&macro_obstack);
-  
-  /* Read value. */
-  ch = skip_white_space ();
-  if (ch != '"')
-    {
-      ungetc (ch, finput);
-      if (ch != EOF)
-	{
-	  complain (_("invalid %s declaration"), "%define");
-	  skip_to_char ('%');
-	  return;
-	}
-      else
-	fatal (_("Premature EOF after %s"), "\"");
-    }
-  copy_string (finput, &macro_obstack, '"');
-  macro_value = obstack_finish (&macro_obstack);
-
-  obstack_free (&macro_obstack, 0);
-
-  /* Store the (key, value) pair in the environment. */
-  macro_insert (macro_key, macro_value);
-}
-
 /*------------------------------------------.
 | Parse what comes after %header_extension. |
 `------------------------------------------*/
@@ -1051,10 +981,6 @@ read_declarations (void)
 	      parse_source_extension_decl ();
 	      break;
 
-	    case tok_define:
-	      parse_macro_decl ();
-	      break;
-
 	    case tok_noop:
 	      break;
 
@@ -1638,7 +1564,6 @@ readgram (void)
   if (nrules == 0)
     fatal (_("no rules in the input grammar"));
 
-#if 0 /* This code is in the skeleton now.  */
   /* JF put out same default YYSTYPE as YACC does */
   if (typed == 0
       && !value_components_used)
@@ -1654,7 +1579,6 @@ readgram (void)
 #  define YYSTYPE int\n\
 # endif\n");
     }
-#endif
 
   /* Report any undefined symbols and consider them nonterminals.  */
 
@@ -1717,7 +1641,7 @@ output_token_defines (struct obstack *oout)
 	obstack_fgrow2 (oout, "# define\tT%s\t%d\n", symbol, bp->value);
     }
 
-  /* obstack_1grow (oout, '\n'); */
+  obstack_1grow (oout, '\n');
 }
 
 
@@ -1839,12 +1763,8 @@ packsymbols (void)
 
   error_token_number = errtoken->value;
 
-  output_token_defines (&output_obstack);
-  obstack_1grow (&output_obstack, 0);
-  macro_insert ("tokendef", obstack_finish (&output_obstack));
-
-  /* if (!no_parser_flag)
-     output_token_defines (&table_obstack); */
+  if (!no_parser_flag)
+    output_token_defines (&table_obstack);
 
   if (startval->class == unknown_sym)
     fatal (_("the start symbol %s is undefined"), startval->tag);
@@ -1993,12 +1913,10 @@ reader (void)
 
   /* Initialize the symbol table.  */
   tabinit ();
-
   /* Construct the error token */
   errtoken = getsym ("error");
   errtoken->class = token_sym;
   errtoken->user_token_number = 256;	/* Value specified by POSIX.  */
-
   /* Construct a token that represents all undefined literal tokens.
      It is always token number 2.  */
   undeftoken = getsym ("$undefined.");
@@ -2008,22 +1926,30 @@ reader (void)
   /* Read the declaration section.  Copy %{ ... %} groups to
      TABLE_OBSTACK and FDEFINES file.  Also notice any %token, %left,
      etc. found there.  */
-  /* obstack_1grow (&table_obstack, '\n'); */
-
+  obstack_1grow (&table_obstack, '\n');
+  obstack_fgrow3 (&table_obstack, "\
+/* %s, made from %s\n\
+   by GNU bison %s.  */\n\
+\n",
+		  no_parser_flag ? "Bison-generated parse tables" : "A Bison parser",
+		  infile, VERSION);
+
+  obstack_sgrow (&table_obstack,
+		       "#define YYBISON 1  /* Identify Bison output.  */\n\n");
   read_declarations ();
   /* Start writing the guard and action files, if they are needed.  */
-  /* output_headers (); */
+  output_headers ();
   /* Read in the grammar, build grammar in list form.  Write out
      guards and actions.  */
   readgram ();
   /* Now we know whether we need the line-number stack.  If we do,
      write its type into the .tab.h file.  */
-  /* if (defines_flag)
-     reader_output_yylsp (&defines_obstack); */
+  if (defines_flag)
+    reader_output_yylsp (&defines_obstack);
   /* Write closing delimiters for actions and guards.  */
-  /* output_trailers (); */
-  /* if (locations_flag)
-     obstack_sgrow (&table_obstack, "#define YYLSP_NEEDED 1\n\n"); */
+  output_trailers ();
+  if (locations_flag)
+    obstack_sgrow (&table_obstack, "#define YYLSP_NEEDED 1\n\n");
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
@@ -2033,3 +1959,30 @@ reader (void)
      referred to by symbol number.  */
   free_symtab ();
 }
+
+
+/*------------------------------------------------------------------.
+| Define YYLTYPE.  Cannot be in the skeleton since we might have to |
+| output it in the headers if --defines is used.                    |
+`------------------------------------------------------------------*/
+
+void
+reader_output_yylsp (struct obstack *oout)
+{
+  if (locations_flag)
+    obstack_sgrow (oout, "\
+\n\
+#ifndef YYLTYPE\n\
+typedef struct yyltype\n\
+{\n\
+  int first_line;\n\
+  int first_column;\n\
+\n\
+  int last_line;\n\
+  int last_column;\n\
+} yyltype;\n\
+\n\
+# define YYLTYPE yyltype\n\
+#endif\n\
+\n");
+}
