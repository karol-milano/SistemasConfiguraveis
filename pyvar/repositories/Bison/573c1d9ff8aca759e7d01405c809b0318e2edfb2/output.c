@@ -150,7 +150,7 @@ output_short_or_char_table (struct obstack *oout,
 
       if (j >= 10)
 	{
-	  obstack_grow_literal_string (oout, "\n  ");
+	  obstack_grow_string (oout, "\n  ");
 	  j = 1;
 	}
       else
@@ -161,7 +161,7 @@ output_short_or_char_table (struct obstack *oout,
       obstack_fgrow1 (oout, "%6d", short_table[i]);
     }
 
-  obstack_grow_literal_string (oout, "\n};\n");
+  obstack_grow_string (oout, "\n};\n");
 }
 
 
@@ -234,7 +234,7 @@ output_headers (void)
   if (semantic_parser)
     obstack_fgrow1 (&action_obstack, ACTSTR, attrsfile_quoted);
   else
-    obstack_grow_literal_string (&action_obstack, ACTSTR_SIMPLE);
+    obstack_grow_string (&action_obstack, ACTSTR_SIMPLE);
 
 /*  if (semantic_parser)	JF moved this below
     fprintf(ftable, "#include \"%s\"\n", attrsfile);
@@ -278,9 +278,9 @@ output_trailers (void)
     return;
 
   if (semantic_parser)
-    obstack_grow_literal_string (&action_obstack, "    }\n");
+    obstack_grow_string (&action_obstack, "    }\n");
 
-  obstack_grow_literal_string (&action_obstack, "}\n");
+  obstack_grow_string (&action_obstack, "}\n");
 }
 
 
@@ -288,7 +288,7 @@ output_trailers (void)
 static void
 output_token_translations (void)
 {
-  obstack_grow_literal_string (&table_obstack, "\
+  obstack_grow_string (&table_obstack, "\
 \n\
 /* YYRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */\n");
 
@@ -308,8 +308,8 @@ output_token_translations (void)
     }
   else
     {
-      obstack_grow_literal_string (&table_obstack,
-				   "\n#define YYTRANSLATE(x) (x)\n");
+      obstack_grow_string (&table_obstack,
+			   "\n#define YYTRANSLATE(x) (x)\n");
     }
 }
 
@@ -321,7 +321,7 @@ output_gram (void)
      yyprhs and yyrhs are needed only for yydebug. */
   /* With the no_parser option, all tables are generated */
   if (!semantic_parser && !no_parser_flag)
-    obstack_grow_literal_string (&table_obstack, "\n#if YYDEBUG != 0\n");
+    obstack_grow_string (&table_obstack, "\n#if YYDEBUG != 0\n");
 
   output_short_table (&table_obstack, NULL, "yyprhs", rrhs,
 		      0, 1, nrules + 1);
@@ -344,7 +344,7 @@ output_gram (void)
   }
 
   if (!semantic_parser && !no_parser_flag)
-    obstack_grow_literal_string (&table_obstack, "\n#endif\n");
+    obstack_grow_string (&table_obstack, "\n#endif\n");
 }
 
 
@@ -363,7 +363,7 @@ output_rule_data (void)
   int j;
   short *short_tab = NULL;
 
-  obstack_grow_literal_string (&table_obstack, "\n\
+  obstack_grow_string (&table_obstack, "\n\
 #if YYDEBUG != 0\n");
 
   output_short_table (&table_obstack,
@@ -371,7 +371,7 @@ output_rule_data (void)
 		      "yyrline", rline,
 		      0, 1, nrules + 1);
 
-  obstack_grow_literal_string (&table_obstack, "#endif\n\n");
+  obstack_grow_string (&table_obstack, "#endif\n\n");
 
   if (token_table_flag || no_parser_flag)
     {
@@ -385,11 +385,11 @@ output_rule_data (void)
 
   /* Output the table of symbol names.  */
   if (!token_table_flag && !no_parser_flag)
-    obstack_grow_literal_string (&table_obstack,
-			  "\n#if YYDEBUG != 0 || defined YYERROR_VERBOSE\n\n");
-  obstack_grow_literal_string (&table_obstack, "\
+    obstack_grow_string (&table_obstack,
+			 "\n#if YYDEBUG != 0 || defined YYERROR_VERBOSE\n\n");
+  obstack_grow_string (&table_obstack, "\
 /* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */\n");
-  obstack_grow_literal_string (&table_obstack,
+  obstack_grow_string (&table_obstack,
 	   "static const char *const yytname[] =\n{\n  ");
 
   j = 0;
@@ -413,7 +413,7 @@ output_rule_data (void)
 
       if (j + strsize > 75)
 	{
-	  obstack_grow_literal_string (&table_obstack, "\n  ");
+	  obstack_grow_string (&table_obstack, "\n  ");
 	  j = 2;
 	}
 
@@ -421,39 +421,27 @@ output_rule_data (void)
       for (p = tags[i]; p && *p; p++)
 	{
 	  if (*p == '"' || *p == '\\')
-	    {
-	      obstack_fgrow1 (&table_obstack, "\\%c", *p);
-	    }
+	    obstack_fgrow1 (&table_obstack, "\\%c", *p);
 	  else if (*p == '\n')
-	    {
-	      obstack_grow_literal_string (&table_obstack, "\\n");
-	    }
+	    obstack_grow_string (&table_obstack, "\\n");
 	  else if (*p == '\t')
-	    {
-	      obstack_grow_literal_string (&table_obstack, "\\t");
-	    }
+	    obstack_grow_string (&table_obstack, "\\t");
 	  else if (*p == '\b')
-	    {
-	      obstack_grow_literal_string (&table_obstack, "\\b");
-	    }
+	    obstack_grow_string (&table_obstack, "\\b");
 	  else if (*p < 040 || *p >= 0177)
-	    {
-	      obstack_fgrow1 (&table_obstack, "\\%03o", *p);
-	    }
+	    obstack_fgrow1 (&table_obstack, "\\%03o", *p);
 	  else
-	    {
-	      obstack_1grow (&table_obstack, *p);
-	    }
+	    obstack_1grow (&table_obstack, *p);
 	}
 
-      obstack_grow_literal_string (&table_obstack, "\", ");
+      obstack_grow_string (&table_obstack, "\", ");
       j += strsize;
     }
   /* add a NULL entry to list of tokens */
-  obstack_grow_literal_string (&table_obstack, "NULL\n};\n");
+  obstack_grow_string (&table_obstack, "NULL\n};\n");
 
   if (!token_table_flag && !no_parser_flag)
-    obstack_grow_literal_string (&table_obstack, "#endif\n\n");
+    obstack_grow_string (&table_obstack, "#endif\n\n");
 
   /* Output YYTOKNUM. */
   if (token_table_flag)
@@ -1164,10 +1152,10 @@ output_parser (void)
   FILE *fskel;
   size_t line;
   const char *skeleton = NULL;
-  int number_of_dollar_signs = 0;
+  int actions_dumped = 0;
 
   if (pure_parser)
-    obstack_grow_literal_string (&table_obstack, "#define YYPURE 1\n\n");
+    obstack_grow_string (&table_obstack, "#define YYPURE 1\n\n");
 
   /* Loop over lines in the standard parser file.  */
   if (semantic_parser)
@@ -1184,63 +1172,106 @@ output_parser (void)
 
   while (1)
     {
-      int is_sync_line = 0;
-      int write_line = 1;
+      enum line_type_e
+	{
+	  regular_line,
+	  sync_line,	/* #line. */
+	  actions_line	/* %% actions. */
+	};
+      enum line_type_e line_type = regular_line;
 
       c = getc (fskel);
 
-      /* See if the line starts with `#line'. */
+      /* Is this line special? */
       if (c == '#')
-	if ((c = getc (fskel)) == 'l')
-	  if ((c = getc (fskel)) == 'i')
-	    if ((c = getc (fskel)) == 'n')
-	      if ((c = getc (fskel)) == 'e')
-		is_sync_line = 1;
+	{
+	  /* See if it's a `#line' line. */
+	  if ((c = getc (fskel)) == 'l')
+	    if ((c = getc (fskel)) == 'i')
+	      if ((c = getc (fskel)) == 'n')
+		if ((c = getc (fskel)) == 'e')
+		  line_type = sync_line;
+		else
+		  obstack_grow_string (&table_obstack, "#lin");
 	      else
-		obstack_grow_literal_string (&table_obstack, "#lin");
+		obstack_grow_string (&table_obstack, "#li");
 	    else
-	      obstack_grow_literal_string (&table_obstack, "#li");
+	      obstack_grow_string (&table_obstack, "#l");
 	  else
-	    obstack_grow_literal_string (&table_obstack, "#l");
-	else
-	  obstack_grow_literal_string (&table_obstack, "#");
+	    obstack_grow_string (&table_obstack, "#");
+	}
+      else if (c == '%')
+	{
+	  /* See if it's a `%% actions' line. */
+	  if ((c = getc (fskel)) == '%')
+	    if ((c = getc (fskel)) == ' ')
+	      if ((c = getc (fskel)) == 'a')
+		if ((c = getc (fskel)) == 'c')
+		  if ((c = getc (fskel)) == 't')
+		    if ((c = getc (fskel)) == 'i')
+		      if ((c = getc (fskel)) == 'o')
+			if ((c = getc (fskel)) == 'n')
+			  if ((c = getc (fskel)) == 's')
+			    line_type = actions_line;
+			  else
+			    obstack_grow_string (&table_obstack, "%% action");
+			else
+			  obstack_grow_string (&table_obstack, "%% actio");
+		      else
+			obstack_grow_string (&table_obstack, "%% acti");
+		    else
+		      obstack_grow_string (&table_obstack, "%% act");
+		  else
+		    obstack_grow_string (&table_obstack, "%% ac");
+		else
+		  obstack_grow_string (&table_obstack, "%% a");
+	      else
+		obstack_grow_string (&table_obstack, "%% ");
+	    else
+	      obstack_grow_string (&table_obstack, "%%");
+	  else
+	    obstack_grow_string (&table_obstack, "%");
+	}
 
-      /* If was a `#line' line, either compute it, or drop it. */
-      if (is_sync_line && !no_lines_flag)
-	obstack_fgrow2 (&table_obstack, "#line %d %s\n",
-			line, quotearg_style (c_quoting_style, skeleton));
+      switch (line_type)
+	{
+	case sync_line:
+	  if (!no_lines_flag)
+	    obstack_fgrow2 (&table_obstack, "#line %d %s\n",
+			    line, quotearg_style (c_quoting_style, skeleton));
 
-      if (is_sync_line)
-	write_line = 0;
+	  /* Skip the end of line. */
+	  for (; c != '\n' && c != EOF; c = getc (fskel))
+	    /* nothing */;
+	  break;
 
-      /* now write out the line... */
-      for (; c != '\n' && c != EOF; c = getc (fskel))
-	if (write_line)
+	case actions_line:
 	  {
-	    /* `$' in the parser file indicates where to put the
-	       actions.  Copy them in at this point.  */
-	    if (c == '$')
-	      {
-		size_t size = obstack_object_size (&action_obstack);
-
-		number_of_dollar_signs++;
-		assert (number_of_dollar_signs == 1);
-		obstack_grow (&table_obstack,
-			      obstack_finish (&action_obstack),
-			      size);
-
-		/* Skip the end of the line containing `$'. */
-		write_line = 0;
-	      }
-	    else
-	      obstack_1grow (&table_obstack, c);
+	    size_t size = obstack_object_size (&action_obstack);
+
+	    actions_dumped++;
+	    assert (actions_dumped == 1);
+	    obstack_grow (&table_obstack,
+			  obstack_finish (&action_obstack),
+			  size);
 	  }
+
+	  /* Skip the end of line. */
+	  for (; c != '\n' && c != EOF; c = getc (fskel))
+	    /* nothing */;
+	  break;
+
+	case regular_line:
+	  for (; c != '\n' && c != EOF; c = getc (fskel))
+	    obstack_1grow (&table_obstack, c);
+	}
+
       if (c == EOF)
 	break;
       obstack_1grow (&table_obstack, c);
       line++;
     }
-  assert (number_of_dollar_signs == 1);
+  assert (actions_dumped == 1);
   xfclose (fskel);
 }
 
@@ -1291,7 +1322,7 @@ output (void)
     }
   reader_output_yylsp (&table_obstack);
   if (debug_flag)
-    obstack_grow_literal_string (&table_obstack, "\
+    obstack_grow_string (&table_obstack, "\
 #ifndef YYDEBUG\n\
 # define YYDEBUG 1\n\
 #endif\n\
@@ -1302,10 +1333,10 @@ output (void)
 		    quotearg_style (c_quoting_style, attrsfile));
 
   if (!no_parser_flag)
-    obstack_grow_literal_string (&table_obstack, "#include <stdio.h>\n\n");
+    obstack_grow_string (&table_obstack, "#include <stdio.h>\n\n");
 
   /* Make "const" do nothing if not in ANSI C.  */
-  obstack_grow_literal_string (&table_obstack, "\
+  obstack_grow_string (&table_obstack, "\
 #ifndef __cplusplus\n\
 # ifndef __STDC__\n\
 #  define const\n\
