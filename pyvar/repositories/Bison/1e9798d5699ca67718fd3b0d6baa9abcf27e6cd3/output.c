@@ -126,6 +126,7 @@ static int high;
 
 static inline void
 output_short_table (FILE *out,
+		    const char *comment,
 		    const char *table_name,
 		    short *short_table,
 		    short first_value,
@@ -133,16 +134,20 @@ output_short_table (FILE *out,
 {
   int i, j;
 
-  fprintf (out, "static const short %s[] = {%6d", table_name, first_value);
+  if (comment)
+    fprintf (out, "/* %s. */\n", comment);
 
-  j = 10;
+  fprintf (out, "static const short %s[] =\n{\n  %6d",
+	   table_name, first_value);
+
+  j = 1;
   for (i = begin; i < end; i++)
     {
       putc (',', out);
 
       if (j >= 10)
 	{
-	  putc ('\n', out);
+	  fputs ("\n  ", out);
 	  j = 1;
 	}
       else
@@ -295,42 +300,31 @@ output_token_translations (void)
 static void
 output_gram (void)
 {
-  int j;
-  short *sp;
-
   /* With the ordinary parser,
      yyprhs and yyrhs are needed only for yydebug. */
   /* With the no_parser option, all tables are generated */
   if (!semantic_parser && !no_parser_flag)
     fprintf (ftable, "\n#if YYDEBUG != 0\n");
 
-  output_short_table (ftable, "yyprhs", rrhs,
+  output_short_table (ftable, NULL, "yyprhs", rrhs,
 		      0, 1, nrules + 1);
 
-  fprintf (ftable, "\nstatic const short yyrhs[] = {%6d", ritem[0]);
+  {
+    size_t yyrhs_size = 1;
+    short *yyrhs, *sp;
+    int i;
 
-  j = 10;
-  for (sp = ritem + 1; *sp; sp++)
-    {
-      putc (',', ftable);
+    for (sp = ritem + 1; *sp; sp++)
+      ++yyrhs_size;
+    yyrhs = XMALLOC (short, yyrhs_size);
 
-      if (j >= 10)
-	{
-	  putc ('\n', ftable);
-	  j = 1;
-	}
-      else
-	{
-	  j++;
-	}
+    for (sp = ritem + 1, i = 1; *sp; ++sp, ++i)
+      yyrhs[i] = *sp > 0 ? *sp : 0;
 
-      if (*sp > 0)
-	fprintf (ftable, "%6d", *sp);
-      else
-	fprintf (ftable, "     0");
-    }
-
-  fprintf (ftable, "\n};\n");
+    output_short_table (ftable, NULL, "yyrhs", yyrhs,
+			ritem[0], 1, yyrhs_size);
+    XFREE (yyrhs);
+  }
 
   if (!semantic_parser && !no_parser_flag)
     fprintf (ftable, "\n#endif\n");
@@ -340,7 +334,7 @@ output_gram (void)
 static void
 output_stos (void)
 {
-  output_short_table (ftable, "yystos", accessing_symbol,
+  output_short_table (ftable, NULL, "yystos", accessing_symbol,
 		      0, 1, nstates);
 }
 
@@ -350,13 +344,15 @@ output_rule_data (void)
 {
   int i;
   int j;
+  short *short_tab = NULL;
 
   fputs ("\n\
-#if YYDEBUG != 0\n\
-/* YYRLINE[yyn]: source line where rule number YYN was defined. */\n",
+#if YYDEBUG != 0\n",
 	 ftable);
 
-  output_short_table (ftable, "yyrline", rline,
+  output_short_table (ftable,
+           "YYRLINE[YYN] -- source line where rule number YYN was defined",
+		      "yyrline", rline,
 		      0, 1, nrules + 1);
 
   fputs ("#endif\n\n", ftable);
@@ -370,71 +366,74 @@ output_rule_data (void)
       fprintf (ftable, "#define YYMAXUTOK %d\n\n", max_user_token_number);
     }
 
-  if (!token_table_flag && !no_parser_flag)
-    fprintf (ftable, "\n#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)\n\n");
-
   /* Output the table of symbol names.  */
-
+  if (!token_table_flag && !no_parser_flag)
+    fputs ("\n#if YYDEBUG != 0 || defined YYERROR_VERBOSE\n\n", ftable);
+  fputs ("\
+/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */\n",
+	 ftable);
   fprintf (ftable,
-	   "static const char * const yytname[] = {   \"%s\"", tags[0]);
+	   "static const char *const yytname[] =\n{\n  ");
 
-  j = strlen (tags[0]) + 44;
-  for (i = 1; i < nsyms; i++)
+  j = 0;
+  for (i = 0; i < nsyms; i++)
     /* this used to be i<=nsyms, but that output a final "" symbol
        almost by accident */
     {
+      /* Width of the next token, including the two quotes, the coma
+	 and the space.  */
+      int strsize = 4;
       char *p;
-      putc (',', ftable);
-      j++;
 
-      if (j > 75)
+      for (p = tags[i]; p && *p; p++)
+	if (*p == '"' || *p == '\\' || *p == '\n' || *p == '\t'
+	    || *p == '\b')
+	  strsize += 2;
+	else if (*p < 040 || *p >= 0177)
+	  strsize += 4;
+	else
+	  strsize++;
+
+      if (j + strsize > 75)
 	{
-	  putc ('\n', ftable);
-	  j = 0;
+	  fputs ("\n  ", ftable);
+	  j = 2;
 	}
 
       putc ('\"', ftable);
-      j++;
-
       for (p = tags[i]; p && *p; p++)
 	{
 	  if (*p == '"' || *p == '\\')
 	    {
 	      fprintf (ftable, "\\%c", *p);
-	      j += 2;
 	    }
 	  else if (*p == '\n')
 	    {
 	      fprintf (ftable, "\\n");
-	      j += 2;
 	    }
 	  else if (*p == '\t')
 	    {
 	      fprintf (ftable, "\\t");
-	      j += 2;
 	    }
 	  else if (*p == '\b')
 	    {
 	      fprintf (ftable, "\\b");
-	      j += 2;
 	    }
 	  else if (*p < 040 || *p >= 0177)
 	    {
 	      fprintf (ftable, "\\%03o", *p);
-	      j += 4;
 	    }
 	  else
 	    {
 	      putc (*p, ftable);
-	      j++;
 	    }
 	}
 
-      putc ('\"', ftable);
-      j++;
+      fputs ("\", ", ftable);
+      j += strsize;
     }
   /* add a NULL entry to list of tokens */
-  fprintf (ftable, ", NULL\n};\n");
+  fprintf (ftable, "NULL\n};\n");
 
   if (!token_table_flag && !no_parser_flag)
     fprintf (ftable, "#endif\n\n");
@@ -442,47 +441,34 @@ output_rule_data (void)
   /* Output YYTOKNUM. */
   if (token_table_flag)
     {
-      output_short_table (ftable, "yytoknum", user_toknums,
+      output_short_table (ftable,
+		  "YYTOKNUM[YYLEX] -- Index in YYTNAME corresponding to YYLEX",
+			  "yytoknum", user_toknums,
 			  0, 1, ntokens + 1);
     }
 
   /* Output YYR1. */
-  fputs ("\
-/* YYR1[YYN]: Symbol number of symbol that rule YYN derives. */\n", ftable);
-
-  output_short_table (ftable, "yyr1", rlhs,
+  output_short_table (ftable,
+	      "YYR1[YYN] -- Symbol number of symbol that rule YYN derives",
+		      "yyr1", rlhs,
 		      0, 1, nrules + 1);
   XFREE (rlhs + 1);
 
   putc ('\n', ftable);
 
   /* Output YYR2. */
-  fputs ("\
-/* YYR2[YYN]: Number of symbols composing right hand side of rule YYN. */\n\
-static const short yyr2[] = {     0", ftable);
-  j = 10;
+  short_tab = XMALLOC (short, nrules + 1);
   for (i = 1; i < nrules; i++)
-    {
-      putc (',', ftable);
-
-      if (j >= 10)
-	{
-	  putc ('\n', ftable);
-	  j = 1;
-	}
-      else
-	{
-	  j++;
-	}
-
-      fprintf (ftable, "%6d", rrhs[i + 1] - rrhs[i] - 1);
-    }
+    short_tab[i] = rrhs[i + 1] - rrhs[i] - 1;
+  short_tab[nrules] = nitems - rrhs[nrules] - 1;
+  output_short_table (ftable,
+        "YYR2[YYN] -- Number of symbols composing right hand side of rule YYN",
+		      "yyr2", short_tab,
+		      0, 1, nrules + 1);
+  putc ('\n', ftable);
 
-  putc (',', ftable);
-  if (j >= 10)
-    putc ('\n', ftable);
+  XFREE (short_tab);
 
-  fprintf (ftable, "%6d\n};\n", nitems - rrhs[nrules] - 1);
   XFREE (rrhs + 1);
 }
 
@@ -738,7 +724,7 @@ token_actions (void)
     }
   XFREE (actrow);
 
-  output_short_table (ftable, "yydefact", yydefact,
+  output_short_table (ftable, NULL, "yydefact", yydefact,
 		      yydefact[0], 1, nstates);
   XFREE (yydefact);
 }
@@ -1095,12 +1081,12 @@ pack_table (void)
 static void
 output_base (void)
 {
-  output_short_table (ftable, "yypact", base,
+  output_short_table (ftable, NULL, "yypact", base,
 		      base[0], 1, nstates);
 
   putc ('\n', ftable);
 
-  output_short_table (ftable, "yypgoto", base,
+  output_short_table (ftable, NULL, "yypgoto", base,
 		      base[nstates], nstates + 1, nvectors);
 
   XFREE (base);
@@ -1111,7 +1097,7 @@ static void
 output_table (void)
 {
   fprintf (ftable, "\n\n#define\tYYLAST\t\t%d\n\n\n", high);
-  output_short_table (ftable, "yytable", table,
+  output_short_table (ftable, NULL, "yytable", table,
 		      table[0], 1, high + 1);
   XFREE (table);
 }
@@ -1120,7 +1106,7 @@ output_table (void)
 static void
 output_check (void)
 {
-  output_short_table (ftable, "yycheck", check,
+  output_short_table (ftable, NULL, "yycheck", check,
 		      check[0], 1, high + 1);
   XFREE (check);
 }
