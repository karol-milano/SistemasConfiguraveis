@@ -343,7 +343,7 @@ copy_at (FILE *fin, FILE *fout, struct obstack *oout, int stack_offset)
       if (fout)
 	fprintf (fout, "yyloc");
       if (oout)
-	obstack_grow_literal_string (oout, "yyloc");
+	obstack_grow_string (oout, "yyloc");
       locations_flag = 1;
     }
   else if (isdigit (c) || c == '-')
@@ -401,7 +401,7 @@ copy_dollar (FILE *fin, FILE *fout, struct obstack *oout,
       if (fout)
 	fputs ("yyval", fout);
       if (oout)
-	obstack_grow_literal_string (oout, "yyval");
+	obstack_grow_string (oout, "yyval");
 
       if (!type_name)
 	type_name = get_type_name (0, rule);
@@ -786,9 +786,9 @@ parse_union_decl (void)
   else
     obstack_1grow (&attrs_obstack, '\n');
 
-  obstack_grow_literal_string (&attrs_obstack, "typedef union");
+  obstack_grow_string (&attrs_obstack, "typedef union");
   if (defines_flag)
-    obstack_grow_literal_string (&defines_obstack, "typedef union");
+    obstack_grow_string (&defines_obstack, "typedef union");
 
   c = getc (finput);
 
@@ -818,9 +818,9 @@ parse_union_decl (void)
 	  count--;
 	  if (count <= 0)
 	    {
-	      obstack_grow_literal_string (&attrs_obstack, " YYSTYPE;\n");
+	      obstack_grow_string (&attrs_obstack, " YYSTYPE;\n");
 	      if (defines_flag)
-		obstack_grow_literal_string (&defines_obstack, " YYSTYPE;\n");
+		obstack_grow_string (&defines_obstack, " YYSTYPE;\n");
 	      /* JF don't choke on trailing semi */
 	      c = skip_white_space ();
 	      if (c != ';')
@@ -1117,8 +1117,7 @@ copy_action (symbol_list *rule, int stack_offset)
 	}
     }
 
-  obstack_grow_literal_string (&action_obstack,
-			       ";\n    break;}");
+  obstack_grow_string (&action_obstack, ";\n    break;}");
 }
 
 /*-------------------------------------------------------------------.
@@ -1597,10 +1596,10 @@ readgram (void)
       /* We used to use `unsigned long' as YYSTYPE on MSDOS,
          but it seems better to be consistent.
          Most programs should declare their own type anyway.  */
-      obstack_grow_literal_string (&attrs_obstack,
-			    "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
+      obstack_grow_string (&attrs_obstack,
+			   "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
       if (defines_flag)
-	obstack_grow_literal_string (&defines_obstack, "\
+	obstack_grow_string (&defines_obstack, "\
 #ifndef YYSTYPE\n\
 # define YYSTYPE int\n\
 #endif\n");
@@ -1810,8 +1809,8 @@ packsymbols (void)
 	    obstack_fgrow1 (&defines_obstack, "\nextern YYSTYPE %slval;\n",
 			    spec_name_prefix);
 	  else
-	    obstack_grow_literal_string (&defines_obstack,
-					 "\nextern YYSTYPE yylval;\n");
+	    obstack_grow_string (&defines_obstack,
+				 "\nextern YYSTYPE yylval;\n");
 	}
 
       if (semantic_parser)
@@ -1963,7 +1962,7 @@ reader (void)
 		  no_parser_flag ? "Bison-generated parse tables" : "A Bison parser",
 		  infile, VERSION);
 
-  obstack_grow_literal_string (&table_obstack,
+  obstack_grow_string (&table_obstack,
 		       "#define YYBISON 1  /* Identify Bison output.  */\n\n");
   read_declarations ();
   /* Start writing the guard and action files, if they are needed.  */
@@ -1978,7 +1977,7 @@ reader (void)
   /* Write closing delimiters for actions and guards.  */
   output_trailers ();
   if (locations_flag)
-    obstack_grow_literal_string (&table_obstack, "#define YYLSP_NEEDED 1\n\n");
+    obstack_grow_string (&table_obstack, "#define YYLSP_NEEDED 1\n\n");
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
@@ -1999,7 +1998,7 @@ void
 reader_output_yylsp (struct obstack *oout)
 {
   if (locations_flag)
-    obstack_grow_literal_string (oout, "\
+    obstack_grow_string (oout, "\
 \n\
 #ifndef YYLTYPE\n\
 typedef struct yyltype\n\
