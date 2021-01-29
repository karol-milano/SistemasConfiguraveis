@@ -309,7 +309,7 @@ copy_at (FILE *fin, struct obstack *oout, int stack_offset)
   c = getc (fin);
   if (c == '$')
     {
-      obstack_grow_string (oout, "yyloc");
+      obstack_sgrow (oout, "yyloc");
       locations_flag = 1;
     }
   else if (isdigit (c) || c == '-')
@@ -360,7 +360,7 @@ copy_dollar (FILE *fin, struct obstack *oout,
 
   if (c == '$')
     {
-      obstack_grow_string (oout, "yyval");
+      obstack_sgrow (oout, "yyval");
 
       if (!type_name)
 	type_name = get_type_name (0, rule);
@@ -732,9 +732,9 @@ parse_union_decl (void)
   else
     obstack_1grow (&attrs_obstack, '\n');
 
-  obstack_grow_string (&attrs_obstack, "typedef union");
+  obstack_sgrow (&attrs_obstack, "typedef union");
   if (defines_flag)
-    obstack_grow_string (&defines_obstack, "typedef union");
+    obstack_sgrow (&defines_obstack, "typedef union");
 
   c = getc (finput);
 
@@ -764,9 +764,9 @@ parse_union_decl (void)
 	  count--;
 	  if (count <= 0)
 	    {
-	      obstack_grow_string (&attrs_obstack, " YYSTYPE;\n");
+	      obstack_sgrow (&attrs_obstack, " YYSTYPE;\n");
 	      if (defines_flag)
-		obstack_grow_string (&defines_obstack, " YYSTYPE;\n");
+		obstack_sgrow (&defines_obstack, " YYSTYPE;\n");
 	      /* JF don't choke on trailing semi */
 	      c = skip_white_space ();
 	      if (c != ';')
@@ -1061,7 +1061,7 @@ copy_action (symbol_list *rule, int stack_offset)
 	}
     }
 
-  obstack_grow_string (&action_obstack, ";\n    break;}");
+  obstack_sgrow (&action_obstack, ";\n    break;}");
 }
 
 /*-------------------------------------------------------------------.
@@ -1149,7 +1149,7 @@ copy_guard (symbol_list *rule, int stack_offset)
 
   c = skip_white_space ();
 
-  obstack_grow_string (&guard_obstack, ";\n    break;}");
+  obstack_sgrow (&guard_obstack, ";\n    break;}");
   if (c == '{')
     copy_action (rule, stack_offset);
   else if (c == '=')
@@ -1540,10 +1540,10 @@ readgram (void)
       /* We used to use `unsigned long' as YYSTYPE on MSDOS,
          but it seems better to be consistent.
          Most programs should declare their own type anyway.  */
-      obstack_grow_string (&attrs_obstack,
+      obstack_sgrow (&attrs_obstack,
 			   "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
       if (defines_flag)
-	obstack_grow_string (&defines_obstack, "\
+	obstack_sgrow (&defines_obstack, "\
 #ifndef YYSTYPE\n\
 # define YYSTYPE int\n\
 #endif\n");
@@ -1753,7 +1753,7 @@ packsymbols (void)
 	    obstack_fgrow1 (&defines_obstack, "\nextern YYSTYPE %slval;\n",
 			    spec_name_prefix);
 	  else
-	    obstack_grow_string (&defines_obstack,
+	    obstack_sgrow (&defines_obstack,
 				 "\nextern YYSTYPE yylval;\n");
 	}
 
@@ -1906,7 +1906,7 @@ reader (void)
 		  no_parser_flag ? "Bison-generated parse tables" : "A Bison parser",
 		  infile, VERSION);
 
-  obstack_grow_string (&table_obstack,
+  obstack_sgrow (&table_obstack,
 		       "#define YYBISON 1  /* Identify Bison output.  */\n\n");
   read_declarations ();
   /* Start writing the guard and action files, if they are needed.  */
@@ -1921,7 +1921,7 @@ reader (void)
   /* Write closing delimiters for actions and guards.  */
   output_trailers ();
   if (locations_flag)
-    obstack_grow_string (&table_obstack, "#define YYLSP_NEEDED 1\n\n");
+    obstack_sgrow (&table_obstack, "#define YYLSP_NEEDED 1\n\n");
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
@@ -1942,7 +1942,7 @@ void
 reader_output_yylsp (struct obstack *oout)
 {
   if (locations_flag)
-    obstack_grow_string (oout, "\
+    obstack_sgrow (oout, "\
 \n\
 #ifndef YYLTYPE\n\
 typedef struct yyltype\n\
