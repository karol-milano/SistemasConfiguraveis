@@ -126,7 +126,7 @@ static int high;
 
 
 static inline void
-output_short_or_char_table (FILE *out,
+output_short_or_char_table (struct obstack *oout,
 			    const char *comment,
 			    const char *type,
 			    const char *table_name,
@@ -137,19 +137,19 @@ output_short_or_char_table (FILE *out,
   int i, j;
 
   if (comment)
-    fprintf (out, "/* %s. */\n", comment);
+    obstack_fgrow1 (oout, "/* %s. */\n", comment);
 
-  fprintf (out, "static const %s %s[] =\n{\n  %6d",
-	   type, table_name, first_value);
+  obstack_fgrow3 (oout, "static const %s %s[] =\n{\n  %6d",
+		  type, table_name, first_value);
 
   j = 1;
   for (i = begin; i < end; i++)
     {
-      putc (',', out);
+      obstack_1grow (oout, ',');
 
       if (j >= 10)
 	{
-	  fputs ("\n  ", out);
+	  obstack_grow_literal_string (oout, "\n  ");
 	  j = 1;
 	}
       else
@@ -157,22 +157,22 @@ output_short_or_char_table (FILE *out,
 	  j++;
 	}
 
-      fprintf (out, "%6d", short_table[i]);
+      obstack_fgrow1 (oout, "%6d", short_table[i]);
     }
 
-  fprintf (out, "\n};\n");
+  obstack_grow_literal_string (oout, "\n};\n");
 }
 
 
 static inline void
-output_short_table (FILE *out,
+output_short_table (struct obstack *oout,
 		    const char *comment,
 		    const char *table_name,
 		    short *short_table,
 		    short first_value,
 		    short begin, short end)
 {
-  output_short_or_char_table (out, comment, "short", table_name, short_table,
+  output_short_or_char_table (oout, comment, "short", table_name, short_table,
 			      first_value, begin, end);
 }
 
@@ -265,13 +265,20 @@ output_headers (void)
   /* Rename certain symbols if -p was specified.  */
   if (spec_name_prefix)
     {
-      fprintf (ftable, "#define yyparse %sparse\n", spec_name_prefix);
-      fprintf (ftable, "#define yylex %slex\n", spec_name_prefix);
-      fprintf (ftable, "#define yyerror %serror\n", spec_name_prefix);
-      fprintf (ftable, "#define yylval %slval\n", spec_name_prefix);
-      fprintf (ftable, "#define yychar %schar\n", spec_name_prefix);
-      fprintf (ftable, "#define yydebug %sdebug\n", spec_name_prefix);
-      fprintf (ftable, "#define yynerrs %snerrs\n", spec_name_prefix);
+      obstack_fgrow1 (&table_obstack,
+			"#define yyparse %sparse\n", spec_name_prefix);
+      obstack_fgrow1 (&table_obstack,
+			"#define yylex %slex\n", spec_name_prefix);
+      obstack_fgrow1 (&table_obstack,
+			"#define yyerror %serror\n", spec_name_prefix);
+      obstack_fgrow1 (&table_obstack,
+			"#define yylval %slval\n", spec_name_prefix);
+      obstack_fgrow1 (&table_obstack,
+			"#define yychar %schar\n", spec_name_prefix);
+      obstack_fgrow1 (&table_obstack,
+			"#define yydebug %sdebug\n", spec_name_prefix);
+      obstack_fgrow1 (&table_obstack,
+			"#define yynerrs %snerrs\n", spec_name_prefix);
     }
 }
 
@@ -305,19 +312,19 @@ output_trailers (void)
 static void
 output_token_translations (void)
 {
-  fputs ("\
+  obstack_grow_literal_string (&table_obstack, "\
 \n\
-/* YYRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */\n",
-	 ftable);
+/* YYRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */\n");
+
   if (translations)
     {
-      fprintf (ftable,
+      obstack_fgrow2 (&table_obstack,
       "#define YYTRANSLATE(x) ((unsigned)(x) <= %d ? yytranslate[x] : %d)\
 \n\
 \n",
 	       max_user_token_number, nsyms);
 
-      output_short_or_char_table (ftable,
+      output_short_or_char_table (&table_obstack,
 	     "YYRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX",
 		    ntokens < 127 ? "char" : "short",
 		    "yytranslate", token_translations,
@@ -325,7 +332,8 @@ output_token_translations (void)
     }
   else
     {
-      fprintf (ftable, "\n#define YYTRANSLATE(x) (x)\n");
+      obstack_grow_literal_string (&table_obstack,
+				   "\n#define YYTRANSLATE(x) (x)\n");
     }
 }
 
@@ -337,9 +345,9 @@ output_gram (void)
      yyprhs and yyrhs are needed only for yydebug. */
   /* With the no_parser option, all tables are generated */
   if (!semantic_parser && !no_parser_flag)
-    fprintf (ftable, "\n#if YYDEBUG != 0\n");
+    obstack_grow_literal_string (&table_obstack, "\n#if YYDEBUG != 0\n");
 
-  output_short_table (ftable, NULL, "yyprhs", rrhs,
+  output_short_table (&table_obstack, NULL, "yyprhs", rrhs,
 		      0, 1, nrules + 1);
 
   {
@@ -354,20 +362,20 @@ output_gram (void)
     for (sp = ritem + 1, i = 1; *sp; ++sp, ++i)
       yyrhs[i] = *sp > 0 ? *sp : 0;
 
-    output_short_table (ftable, NULL, "yyrhs", yyrhs,
+    output_short_table (&table_obstack, NULL, "yyrhs", yyrhs,
 			ritem[0], 1, yyrhs_size);
     XFREE (yyrhs);
   }
 
   if (!semantic_parser && !no_parser_flag)
-    fprintf (ftable, "\n#endif\n");
+    obstack_grow_literal_string (&table_obstack, "\n#endif\n");
 }
 
 
 static void
 output_stos (void)
 {
-  output_short_table (ftable, NULL, "yystos", accessing_symbol,
+  output_short_table (&table_obstack, NULL, "yystos", accessing_symbol,
 		      0, 1, nstates);
 }
 
@@ -379,33 +387,33 @@ output_rule_data (void)
   int j;
   short *short_tab = NULL;
 
-  fputs ("\n\
-#if YYDEBUG != 0\n",
-	 ftable);
+  obstack_grow_literal_string (&table_obstack, "\n\
+#if YYDEBUG != 0\n");
 
-  output_short_table (ftable,
+  output_short_table (&table_obstack,
            "YYRLINE[YYN] -- source line where rule number YYN was defined",
 		      "yyrline", rline,
 		      0, 1, nrules + 1);
 
-  fputs ("#endif\n\n", ftable);
+  obstack_grow_literal_string (&table_obstack, "#endif\n\n");
 
   if (token_table_flag || no_parser_flag)
     {
-      fprintf (ftable, "#define YYNTOKENS %d\n", ntokens);
-      fprintf (ftable, "#define YYNNTS %d\n", nvars);
-      fprintf (ftable, "#define YYNRULES %d\n", nrules);
-      fprintf (ftable, "#define YYNSTATES %d\n", nstates);
-      fprintf (ftable, "#define YYMAXUTOK %d\n\n", max_user_token_number);
+      obstack_fgrow1 (&table_obstack, "#define YYNTOKENS %d\n", ntokens);
+      obstack_fgrow1 (&table_obstack, "#define YYNNTS %d\n", nvars);
+      obstack_fgrow1 (&table_obstack, "#define YYNRULES %d\n", nrules);
+      obstack_fgrow1 (&table_obstack, "#define YYNSTATES %d\n", nstates);
+      obstack_fgrow1 (&table_obstack, "#define YYMAXUTOK %d\n\n",
+		      max_user_token_number);
     }
 
   /* Output the table of symbol names.  */
   if (!token_table_flag && !no_parser_flag)
-    fputs ("\n#if YYDEBUG != 0 || defined YYERROR_VERBOSE\n\n", ftable);
-  fputs ("\
-/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */\n",
-	 ftable);
-  fprintf (ftable,
+    obstack_grow_literal_string (&table_obstack,
+			  "\n#if YYDEBUG != 0 || defined YYERROR_VERBOSE\n\n");
+  obstack_grow_literal_string (&table_obstack, "\
+/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */\n");
+  obstack_grow_literal_string (&table_obstack,
 	   "static const char *const yytname[] =\n{\n  ");
 
   j = 0;
@@ -429,76 +437,76 @@ output_rule_data (void)
 
       if (j + strsize > 75)
 	{
-	  fputs ("\n  ", ftable);
+	  obstack_grow_literal_string (&table_obstack, "\n  ");
 	  j = 2;
 	}
 
-      putc ('\"', ftable);
+      obstack_1grow (&table_obstack, '\"');
       for (p = tags[i]; p && *p; p++)
 	{
 	  if (*p == '"' || *p == '\\')
 	    {
-	      fprintf (ftable, "\\%c", *p);
+	      obstack_fgrow1 (&table_obstack, "\\%c", *p);
 	    }
 	  else if (*p == '\n')
 	    {
-	      fprintf (ftable, "\\n");
+	      obstack_grow_literal_string (&table_obstack, "\\n");
 	    }
 	  else if (*p == '\t')
 	    {
-	      fprintf (ftable, "\\t");
+	      obstack_grow_literal_string (&table_obstack, "\\t");
 	    }
 	  else if (*p == '\b')
 	    {
-	      fprintf (ftable, "\\b");
+	      obstack_grow_literal_string (&table_obstack, "\\b");
 	    }
 	  else if (*p < 040 || *p >= 0177)
 	    {
-	      fprintf (ftable, "\\%03o", *p);
+	      obstack_fgrow1 (&table_obstack, "\\%03o", *p);
 	    }
 	  else
 	    {
-	      putc (*p, ftable);
+	      obstack_1grow (&table_obstack, *p);
 	    }
 	}
 
-      fputs ("\", ", ftable);
+      obstack_grow_literal_string (&table_obstack, "\", ");
       j += strsize;
     }
   /* add a NULL entry to list of tokens */
-  fprintf (ftable, "NULL\n};\n");
+  obstack_grow_literal_string (&table_obstack, "NULL\n};\n");
 
   if (!token_table_flag && !no_parser_flag)
-    fprintf (ftable, "#endif\n\n");
+    obstack_grow_literal_string (&table_obstack, "#endif\n\n");
 
   /* Output YYTOKNUM. */
   if (token_table_flag)
     {
-      output_short_table (ftable,
+      output_short_table (&table_obstack,
 		  "YYTOKNUM[YYLEX] -- Index in YYTNAME corresponding to YYLEX",
 			  "yytoknum", user_toknums,
 			  0, 1, ntokens + 1);
     }
 
   /* Output YYR1. */
-  output_short_table (ftable,
+  output_short_table (&table_obstack,
 	      "YYR1[YYN] -- Symbol number of symbol that rule YYN derives",
 		      "yyr1", rlhs,
 		      0, 1, nrules + 1);
   XFREE (rlhs + 1);
 
-  putc ('\n', ftable);
+  obstack_1grow (&table_obstack, '\n');
 
   /* Output YYR2. */
   short_tab = XMALLOC (short, nrules + 1);
   for (i = 1; i < nrules; i++)
     short_tab[i] = rrhs[i + 1] - rrhs[i] - 1;
   short_tab[nrules] = nitems - rrhs[nrules] - 1;
-  output_short_table (ftable,
+  output_short_table (&table_obstack,
         "YYR2[YYN] -- Number of symbols composing right hand side of rule YYN",
 		      "yyr2", short_tab,
 		      0, 1, nrules + 1);
-  putc ('\n', ftable);
+  obstack_1grow (&table_obstack, '\n');
 
   XFREE (short_tab);
 
@@ -509,9 +517,9 @@ output_rule_data (void)
 static void
 output_defines (void)
 {
-  fprintf (ftable, "\n\n#define\tYYFINAL\t\t%d\n", final_state);
-  fprintf (ftable, "#define\tYYFLAG\t\t%d\n", MINSHORT);
-  fprintf (ftable, "#define\tYYNTBASE\t%d\n", ntokens);
+  obstack_fgrow1 (&table_obstack, "\n\n#define\tYYFINAL\t\t%d\n", final_state);
+  obstack_fgrow1 (&table_obstack, "#define\tYYFLAG\t\t%d\n", MINSHORT);
+  obstack_fgrow1 (&table_obstack, "#define\tYYNTBASE\t%d\n", ntokens);
 }
 
 
@@ -757,13 +765,13 @@ token_actions (void)
     }
   XFREE (actrow);
 
-  output_short_table (ftable,
+  output_short_table (&table_obstack,
   "YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE\n\
    doesn't specify something else to do.  Zero means the default is an\n\
    error",
 		      "yydefact", yydefact,
 		      yydefact[0], 1, nstates);
-  putc ('\n', ftable);
+  obstack_1grow (&table_obstack, '\n');
   XFREE (yydefact);
 }
 
@@ -901,7 +909,7 @@ goto_actions (void)
       yydefgoto[i - ntokens] = default_state;
     }
 
-  output_short_table (ftable, NULL, "yydefgoto", yydefgoto,
+  output_short_table (&table_obstack, NULL, "yydefgoto", yydefgoto,
 		      yydefgoto[0], 1, nsyms - ntokens);
 
   XFREE (state_count);
@@ -1104,12 +1112,12 @@ pack_table (void)
 static void
 output_base (void)
 {
-  output_short_table (ftable, NULL, "yypact", base,
+  output_short_table (&table_obstack, NULL, "yypact", base,
 		      base[0], 1, nstates);
 
-  putc ('\n', ftable);
+  obstack_1grow (&table_obstack, '\n');
 
-  output_short_table (ftable, NULL, "yypgoto", base,
+  output_short_table (&table_obstack, NULL, "yypgoto", base,
 		      base[nstates], nstates + 1, nvectors);
 
   XFREE (base);
@@ -1119,8 +1127,8 @@ output_base (void)
 static void
 output_table (void)
 {
-  fprintf (ftable, "\n\n#define\tYYLAST\t\t%d\n\n\n", high);
-  output_short_table (ftable, NULL, "yytable", table,
+  obstack_fgrow1 (&table_obstack, "\n\n#define\tYYLAST\t\t%d\n\n\n", high);
+  output_short_table (&table_obstack, NULL, "yytable", table,
 		      table[0], 1, high + 1);
   XFREE (table);
 }
@@ -1129,7 +1137,7 @@ output_table (void)
 static void
 output_check (void)
 {
-  output_short_table (ftable, NULL, "yycheck", check,
+  output_short_table (&table_obstack, NULL, "yycheck", check,
 		      check[0], 1, high + 1);
   XFREE (check);
 }
@@ -1162,10 +1170,10 @@ output_actions (void)
 
   sort_actions ();
   pack_table ();
-  putc ('\n', ftable);
+  obstack_1grow (&table_obstack, '\n');
   output_base ();
   output_table ();
-  putc ('\n', ftable);
+  obstack_1grow (&table_obstack, '\n');
   output_check ();
 }
 
@@ -1183,7 +1191,7 @@ output_parser (void)
 #endif
 
   if (pure_parser)
-    fprintf (ftable, "#define YYPURE 1\n\n");
+    obstack_grow_literal_string (&table_obstack, "#define YYPURE 1\n\n");
 
 #ifdef DONTDEF
   /* JF no longer needed 'cuz open_extra_files changes the currently
@@ -1220,16 +1228,16 @@ output_parser (void)
 			if (c == 'e')
 			  write_line = 0;
 			else
-			  fprintf (ftable, "#lin");
+			  obstack_grow_literal_string (&table_obstack, "#lin");
 		      }
 		    else
-		      fprintf (ftable, "#li");
+		      obstack_grow_literal_string (&table_obstack, "#li");
 		  }
 		else
-		  fprintf (ftable, "#l");
+		  obstack_grow_literal_string (&table_obstack, "#l");
 	      }
 	    else
-	      fprintf (ftable, "#");
+	      obstack_grow_literal_string (&table_obstack, "#");
 	  }
 
       /* now write out the line... */
@@ -1244,18 +1252,19 @@ output_parser (void)
 
 		number_of_dollar_signs++;
 		assert (number_of_dollar_signs == 1);
-		fwrite (obstack_finish (&action_obstack),
-			1, size, ftable);
+		obstack_grow (&table_obstack,
+			      obstack_finish (&action_obstack),
+			      size);
 
 		/* Skip the end of the line containing `$'. */
 		write_line = 0;
 	      }
 	    else
-	      putc (c, ftable);
+	      obstack_1grow (&table_obstack, c);
 	  }
       if (c == EOF)
 	break;
-      putc (c, ftable);
+      obstack_1grow (&table_obstack, c);
     }
   assert (number_of_dollar_signs == 1);
 }
@@ -1266,12 +1275,12 @@ output_program (void)
   int c;
 
   if (!no_lines_flag)
-    fprintf (ftable, "#line %d \"%s\"\n", lineno, infile);
+    obstack_fgrow2 (&table_obstack, "#line %d \"%s\"\n", lineno, infile);
 
   c = getc (finput);
   while (c != EOF)
     {
-      putc (c, ftable);
+      obstack_1grow (&table_obstack, c);
       c = getc (finput);
     }
 }
@@ -1304,36 +1313,34 @@ output (void)
   /* output_token_defines(ftable);      / * JF put out token defines FIRST */
 
   /* If using a simple parser the definition of YYSTYPE are put into
-     FTABLE.  */
+     TABLE_OBSTACK.  */
   if (!semantic_parser)
     {
       size_t size = obstack_object_size (&attrs_obstack);
-      fwrite (obstack_finish (&attrs_obstack), 1, size, ftable);
+      obstack_grow (&table_obstack, obstack_finish (&attrs_obstack), size);
     }
-  reader_output_yylsp (ftable);
+  reader_output_yylsp (&table_obstack);
   if (debug_flag)
-    fputs ("\
+    obstack_grow_literal_string (&table_obstack, "\
 #ifndef YYDEBUG\n\
 # define YYDEBUG 1\n\
 #endif\n\
-\n",
-	   ftable);
+\n");
 
   if (semantic_parser)
-    fprintf (ftable, "#include \"%s\"\n", attrsfile);
+    obstack_fgrow1 (&table_obstack, "#include \"%s\"\n", attrsfile);
 
   if (!no_parser_flag)
-    fprintf (ftable, "#include <stdio.h>\n\n");
+    obstack_grow_literal_string (&table_obstack, "#include <stdio.h>\n\n");
 
   /* Make "const" do nothing if not in ANSI C.  */
-  fputs ("\
+  obstack_grow_literal_string (&table_obstack, "\
 #ifndef __cplusplus\n\
 # ifndef __STDC__\n\
 #  define const\n\
 # endif\n\
 #endif\n\
-\n",
-	 ftable);
+\n");
 
   free_itemsets ();
   output_defines ();
