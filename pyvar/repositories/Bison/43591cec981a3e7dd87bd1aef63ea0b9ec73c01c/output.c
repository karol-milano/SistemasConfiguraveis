@@ -125,20 +125,21 @@ static int high;
 
 
 static inline void
-output_short_table (FILE *out,
-		    const char *comment,
-		    const char *table_name,
-		    short *short_table,
-		    short first_value,
-		    short begin, short end)
+output_short_or_char_table (FILE *out,
+			    const char *comment,
+			    const char *type,
+			    const char *table_name,
+			    short *short_table,
+			    short first_value,
+			    short begin, short end)
 {
   int i, j;
 
   if (comment)
     fprintf (out, "/* %s. */\n", comment);
 
-  fprintf (out, "static const short %s[] =\n{\n  %6d",
-	   table_name, first_value);
+  fprintf (out, "static const %s %s[] =\n{\n  %6d",
+	   type, table_name, first_value);
 
   j = 1;
   for (i = begin; i < end; i++)
@@ -162,6 +163,19 @@ output_short_table (FILE *out,
 }
 
 
+static inline void
+output_short_table (FILE *out,
+		    const char *comment,
+		    const char *table_name,
+		    short *short_table,
+		    short first_value,
+		    short begin, short end)
+{
+  output_short_or_char_table (out, comment, "short", table_name, short_table,
+			      first_value, begin, end);
+}
+
+
 /*--------------------------------------------------------------.
 | output_headers -- Output constant strings to the beginning of |
 | certain files.                                                |
@@ -256,39 +270,23 @@ output_trailers (void)
 static void
 output_token_translations (void)
 {
-  int i, j;
-/*   short *sp; JF unused */
-
+  fputs ("\
+\n\
+/* YYRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */\n",
+	 ftable);
   if (translations)
     {
       fprintf (ftable,
-	       "\n#define YYTRANSLATE(x) ((unsigned)(x) <= %d ? yytranslate[x] : %d)\n",
+      "#define YYTRANSLATE(x) ((unsigned)(x) <= %d ? yytranslate[x] : %d)\
+\n\
+\n",
 	       max_user_token_number, nsyms);
 
-      if (ntokens < 127)	/* play it very safe; check maximum element value.  */
-	fprintf (ftable, "\nstatic const char yytranslate[] = {     0");
-      else
-	fprintf (ftable, "\nstatic const short yytranslate[] = {     0");
-
-      j = 10;
-      for (i = 1; i <= max_user_token_number; i++)
-	{
-	  putc (',', ftable);
-
-	  if (j >= 10)
-	    {
-	      putc ('\n', ftable);
-	      j = 1;
-	    }
-	  else
-	    {
-	      j++;
-	    }
-
-	  fprintf (ftable, "%6d", token_translations[i]);
-	}
-
-      fprintf (ftable, "\n};\n");
+      output_short_or_char_table (ftable,
+	     "YYRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX",
+		    ntokens < 127 ? "char" : "short",
+		    "yytranslate", token_translations,
+		    0, 1, max_user_token_number + 1);
     }
   else
     {
@@ -724,8 +722,13 @@ token_actions (void)
     }
   XFREE (actrow);
 
-  output_short_table (ftable, NULL, "yydefact", yydefact,
+  output_short_table (ftable,
+  "YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE\n\
+   doesn't specify something else to do.  Zero means the default is an\n\
+   error",
+		      "yydefact", yydefact,
 		      yydefact[0], 1, nstates);
+  putc ('\n', ftable);
   XFREE (yydefact);
 }
 
@@ -765,19 +768,17 @@ static void
 save_column (int symbol, int default_state)
 {
   int i;
-  int m;
-  int n;
   short *sp;
   short *sp1;
   short *sp2;
   int count;
   int symno;
 
-  m = goto_map[symbol];
-  n = goto_map[symbol + 1];
+  short begin = goto_map[symbol];
+  short end = goto_map[symbol + 1];
 
   count = 0;
-  for (i = m; i < n; i++)
+  for (i = begin; i < end; i++)
     {
       if (to_state[i] != default_state)
 	count++;
@@ -791,7 +792,7 @@ save_column (int symbol, int default_state)
   froms[symno] = sp1 = sp = XCALLOC (short, count);
   tos[symno] = sp2 = XCALLOC (short, count);
 
-  for (i = m; i < n; i++)
+  for (i = begin; i < end; i++)
     {
       if (to_state[i] != default_state)
 	{
@@ -853,36 +854,23 @@ default_goto (int symbol)
 static void
 goto_actions (void)
 {
-  int i, j, k;
+  int i;
 
+  short *yydefgoto = XMALLOC (short, nsyms - ntokens);
   state_count = XCALLOC (short, nstates);
 
-  k = default_goto (ntokens);
-  fprintf (ftable, "\nstatic const short yydefgoto[] = {%6d", k);
-  save_column (ntokens, k);
-
-  j = 10;
-  for (i = ntokens + 1; i < nsyms; i++)
+  for (i = ntokens; i < nsyms; ++i)
     {
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
-      k = default_goto (i);
-      fprintf (ftable, "%6d", k);
-      save_column (i, k);
+      int default_state = default_goto (i);
+      save_column (i, default_state);
+      yydefgoto[i - ntokens] = default_state;
     }
 
-  fprintf (ftable, "\n};\n");
+  output_short_table (ftable, NULL, "yydefgoto", yydefgoto,
+		      yydefgoto[0], 1, nsyms - ntokens);
+
   XFREE (state_count);
+  XFREE (yydefgoto);
 }
 
 
