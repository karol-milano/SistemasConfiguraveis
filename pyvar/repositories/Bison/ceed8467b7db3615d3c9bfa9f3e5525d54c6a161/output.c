@@ -103,9 +103,8 @@ YYNTBASE = ntokens.
 
 */
 
-#include <stdio.h>
 #include "system.h"
-#include "machine.h"
+#include "getargs.h"
 #include "alloc.h"
 #include "files.h"
 #include "gram.h"
@@ -113,11 +112,6 @@ YYNTBASE = ntokens.
 #include "complain.h"
 
 
-extern int debugflag;
-extern int nolinesflag;
-extern int noparserflag;
-extern int toknumflag;
-
 extern char **tags;
 extern int *user_toknums;
 extern int tokensetsize;
@@ -135,37 +129,37 @@ extern short *goto_map;
 extern short *from_state;
 extern short *to_state;
 
-extern void output_headers PARAMS((void));
-extern void output_trailers PARAMS((void));
-extern void output PARAMS((void));
-
-static void output_token_translations PARAMS((void));
-static void output_gram PARAMS((void));
-static void output_stos PARAMS((void));
-static void output_rule_data PARAMS((void));
-static void output_defines PARAMS((void));
-static void output_actions PARAMS((void));
-static void token_actions PARAMS((void));
-static void save_row PARAMS((int));
-static void goto_actions PARAMS((void));
-static void save_column PARAMS((int, int));
-static void sort_actions PARAMS((void));
-static void pack_table PARAMS((void));
-static void output_base PARAMS((void));
-static void output_table PARAMS((void));
-static void output_check PARAMS((void));
-static void output_parser PARAMS((void));
-static void output_program PARAMS((void));
-static void free_shifts PARAMS((void));
-static void free_reductions PARAMS((void));
-static void free_itemsets PARAMS((void));
-static int action_row PARAMS((int));
-static int default_goto PARAMS((int));
-static int matching_state PARAMS((int));
-static int pack_vector PARAMS((int));
-
-extern void berror PARAMS((const char *));
-extern void reader_output_yylsp PARAMS((FILE *));
+extern void output_headers PARAMS ((void));
+extern void output_trailers PARAMS ((void));
+extern void output PARAMS ((void));
+
+static void output_token_translations PARAMS ((void));
+static void output_gram PARAMS ((void));
+static void output_stos PARAMS ((void));
+static void output_rule_data PARAMS ((void));
+static void output_defines PARAMS ((void));
+static void output_actions PARAMS ((void));
+static void token_actions PARAMS ((void));
+static void save_row PARAMS ((int));
+static void goto_actions PARAMS ((void));
+static void save_column PARAMS ((int, int));
+static void sort_actions PARAMS ((void));
+static void pack_table PARAMS ((void));
+static void output_base PARAMS ((void));
+static void output_table PARAMS ((void));
+static void output_check PARAMS ((void));
+static void output_parser PARAMS ((void));
+static void output_program PARAMS ((void));
+static void free_shifts PARAMS ((void));
+static void free_reductions PARAMS ((void));
+static void free_itemsets PARAMS ((void));
+static int action_row PARAMS ((int));
+static int default_goto PARAMS ((int));
+static int matching_state PARAMS ((int));
+static int pack_vector PARAMS ((int));
+
+extern void berror PARAMS ((const char *));
+extern void reader_output_yylsp PARAMS ((FILE *));
 
 static int nvectors;
 static int nentries;
@@ -185,16 +179,38 @@ static int high;
 
 
 
-#define	GUARDSTR	"\n#include \"%s\"\nextern int yyerror;\n\
-extern int yycost;\nextern char * yymsg;\nextern YYSTYPE yyval;\n\n\
-yyguard(n, yyvsp, yylsp)\nregister int n;\nregister YYSTYPE *yyvsp;\n\
+#define	GUARDSTR	\
+"\n\
+#include \"%s\"\n\
+extern int yyerror;\n\
+extern int yycost;\n\
+extern char * yymsg;\n\
+extern YYSTYPE yyval;\n\
+\n\
+yyguard(n, yyvsp, yylsp)\n\
+register int n;\n\
+register YYSTYPE *yyvsp;\n\
 register YYLTYPE *yylsp;\n\
-{\n  yyerror = 0;\nyycost = 0;\n  yymsg = 0;\nswitch (n)\n    {"
-
-#define	ACTSTR		"\n#include \"%s\"\nextern YYSTYPE yyval;\
-\nextern int yychar;\
-yyaction(n, yyvsp, yylsp)\nregister int n;\nregister YYSTYPE *yyvsp;\n\
-register YYLTYPE *yylsp;\n{\n  switch (n)\n{"
+{\n\
+  yyerror = 0;\n\
+  yycost = 0;\n\
+  yymsg = 0;\n\
+  switch (n)\n\
+    {"
+
+#define	ACTSTR		\
+"\n\
+#include \"%s\"\n\
+extern YYSTYPE yyval;\n\
+extern int yychar;\n\
+\n\
+yyaction(n, yyvsp, yylsp)\n\
+register int n;\n\
+register YYSTYPE *yyvsp;\n\
+register YYLTYPE *yylsp;\n\
+{\n\
+  switch (n)\n\
+    {"
 
 #define	ACTSTR_SIMPLE	"\n  switch (yyn) {\n"
 
@@ -203,12 +219,12 @@ void
 output_headers (void)
 {
   if (semantic_parser)
-    fprintf(fguard, GUARDSTR, attrsfile);
+    fprintf (fguard, GUARDSTR, attrsfile);
 
   if (noparserflag)
-	return;
+    return;
 
-  fprintf(faction, (semantic_parser ? ACTSTR : ACTSTR_SIMPLE), attrsfile);
+  fprintf (faction, (semantic_parser ? ACTSTR : ACTSTR_SIMPLE), attrsfile);
 /*  if (semantic_parser)	JF moved this below
     fprintf(ftable, "#include \"%s\"\n", attrsfile);
   fprintf(ftable, "#include <stdio.h>\n\n");
@@ -217,13 +233,13 @@ output_headers (void)
   /* Rename certain symbols if -p was specified.  */
   if (spec_name_prefix)
     {
-      fprintf(ftable, "#define yyparse %sparse\n", spec_name_prefix);
-      fprintf(ftable, "#define yylex %slex\n", spec_name_prefix);
-      fprintf(ftable, "#define yyerror %serror\n", spec_name_prefix);
-      fprintf(ftable, "#define yylval %slval\n", spec_name_prefix);
-      fprintf(ftable, "#define yychar %schar\n", spec_name_prefix);
-      fprintf(ftable, "#define yydebug %sdebug\n", spec_name_prefix);
-      fprintf(ftable, "#define yynerrs %snerrs\n", spec_name_prefix);
+      fprintf (ftable, "#define yyparse %sparse\n", spec_name_prefix);
+      fprintf (ftable, "#define yylex %slex\n", spec_name_prefix);
+      fprintf (ftable, "#define yyerror %serror\n", spec_name_prefix);
+      fprintf (ftable, "#define yylval %slval\n", spec_name_prefix);
+      fprintf (ftable, "#define yychar %schar\n", spec_name_prefix);
+      fprintf (ftable, "#define yydebug %sdebug\n", spec_name_prefix);
+      fprintf (ftable, "#define yynerrs %snerrs\n", spec_name_prefix);
     }
 }
 
@@ -232,16 +248,16 @@ void
 output_trailers (void)
 {
   if (semantic_parser)
-      fprintf(fguard, "\n    }\n}\n");
+    fprintf (fguard, "\n    }\n}\n");
 
-  fprintf(faction, "\n");
+  fprintf (faction, "\n");
 
   if (noparserflag)
-      return;
+    return;
 
   if (semantic_parser)
-      fprintf(faction, "    }\n");
-  fprintf(faction, "}\n");
+    fprintf (faction, "    }\n");
+  fprintf (faction, "}\n");
 }
 
 
@@ -250,41 +266,52 @@ output (void)
 {
   int c;
 
-  /* output_token_defines(ftable);	/ * JF put out token defines FIRST */
+  /* output_token_defines(ftable);      / * JF put out token defines FIRST */
   if (!semantic_parser)		/* JF Put out other stuff */
     {
-      rewind(fattrs);
-      while ((c=getc(fattrs))!=EOF)
-        putc(c,ftable);
+      rewind (fattrs);
+      while ((c = getc (fattrs)) != EOF)
+	putc (c, ftable);
     }
-  reader_output_yylsp(ftable);
+  reader_output_yylsp (ftable);
   if (debugflag)
-    fprintf(ftable, "#ifndef YYDEBUG\n#define YYDEBUG %d\n#endif\n\n",
-	    !!debugflag);
+    fputs ("\
+#ifndef YYDEBUG\n\
+#define YYDEBUG 1\n\
+#endif\n\
+\n",
+	   ftable);
 
   if (semantic_parser)
-    fprintf(ftable, "#include \"%s\"\n", attrsfile);
+    fprintf (ftable, "#include \"%s\"\n", attrsfile);
 
-  if (! noparserflag)
-    fprintf(ftable, "#include <stdio.h>\n\n");
+  if (!noparserflag)
+    fprintf (ftable, "#include <stdio.h>\n\n");
 
   /* Make "const" do nothing if not in ANSI C.  */
-  fprintf (ftable, "#ifndef __cplusplus\n#ifndef __STDC__\n#define const\n#endif\n#endif\n\n");
-
-  free_itemsets();
-  output_defines();
-  output_token_translations();
+  fputs ("\
+#ifndef __cplusplus\n\
+# ifndef __STDC__\n\
+#  define const\n\
+# endif\n\
+#endif\n\
+\n",
+	 ftable);
+
+  free_itemsets ();
+  output_defines ();
+  output_token_translations ();
 /*   if (semantic_parser) */
   /* This is now unconditional because debugging printouts can use it.  */
-  output_gram();
-  FREE(ritem);
+  output_gram ();
+  FREE (ritem);
   if (semantic_parser)
-    output_stos();
-  output_rule_data();
-  output_actions();
-  if (! noparserflag)
-    output_parser();
-  output_program();
+    output_stos ();
+  output_rule_data ();
+  output_actions ();
+  if (!noparserflag)
+    output_parser ();
+  output_program ();
 }
 
 
@@ -296,23 +323,23 @@ output_token_translations (void)
 
   if (translations)
     {
-      fprintf(ftable,
-	      "\n#define YYTRANSLATE(x) ((unsigned)(x) <= %d ? yytranslate[x] : %d)\n",
-	      max_user_token_number, nsyms);
+      fprintf (ftable,
+	       "\n#define YYTRANSLATE(x) ((unsigned)(x) <= %d ? yytranslate[x] : %d)\n",
+	       max_user_token_number, nsyms);
 
-      if (ntokens < 127)  /* play it very safe; check maximum element value.  */
-        fprintf(ftable, "\nstatic const char yytranslate[] = {     0");
+      if (ntokens < 127)	/* play it very safe; check maximum element value.  */
+	fprintf (ftable, "\nstatic const char yytranslate[] = {     0");
       else
-	fprintf(ftable, "\nstatic const short yytranslate[] = {     0");
+	fprintf (ftable, "\nstatic const short yytranslate[] = {     0");
 
       j = 10;
       for (i = 1; i <= max_user_token_number; i++)
 	{
-	  putc(',', ftable);
+	  putc (',', ftable);
 
 	  if (j >= 10)
 	    {
-	      putc('\n', ftable);
+	      putc ('\n', ftable);
 	      j = 1;
 	    }
 	  else
@@ -320,14 +347,14 @@ output_token_translations (void)
 	      j++;
 	    }
 
-	  fprintf(ftable, "%6d", token_translations[i]);
+	  fprintf (ftable, "%6d", token_translations[i]);
 	}
 
-      fprintf(ftable, "\n};\n");
+      fprintf (ftable, "\n};\n");
     }
   else
     {
-      fprintf(ftable, "\n#define YYTRANSLATE(x) (x)\n");
+      fprintf (ftable, "\n#define YYTRANSLATE(x) (x)\n");
     }
 }
 
@@ -342,19 +369,19 @@ output_gram (void)
   /* With the ordinary parser,
      yyprhs and yyrhs are needed only for yydebug. */
   /* With the noparser option, all tables are generated */
-  if (! semantic_parser  && ! noparserflag)
-    fprintf(ftable, "\n#if YYDEBUG != 0");
+  if (!semantic_parser && !noparserflag)
+    fprintf (ftable, "\n#if YYDEBUG != 0");
 
-  fprintf(ftable, "\nstatic const short yyprhs[] = {     0");
+  fprintf (ftable, "\nstatic const short yyprhs[] = {     0");
 
   j = 10;
   for (i = 1; i <= nrules; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -362,21 +389,21 @@ output_gram (void)
 	  j++;
 	}
 
-      fprintf(ftable, "%6d", rrhs[i]);
+      fprintf (ftable, "%6d", rrhs[i]);
     }
 
-  fprintf(ftable, "\n};\n");
+  fprintf (ftable, "\n};\n");
 
-  fprintf(ftable, "\nstatic const short yyrhs[] = {%6d", ritem[0]);
+  fprintf (ftable, "\nstatic const short yyrhs[] = {%6d", ritem[0]);
 
   j = 10;
   for (sp = ritem + 1; *sp; sp++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -385,15 +412,15 @@ output_gram (void)
 	}
 
       if (*sp > 0)
-	fprintf(ftable, "%6d", *sp);
+	fprintf (ftable, "%6d", *sp);
       else
-	fprintf(ftable, "     0");
+	fprintf (ftable, "     0");
     }
 
-  fprintf(ftable, "\n};\n");
+  fprintf (ftable, "\n};\n");
 
-  if (! semantic_parser  && ! noparserflag)
-    fprintf(ftable, "\n#endif\n");
+  if (!semantic_parser && !noparserflag)
+    fprintf (ftable, "\n#endif\n");
 }
 
 
@@ -403,16 +430,16 @@ output_stos (void)
   register int i;
   register int j;
 
-  fprintf(ftable, "\nstatic const short yystos[] = {     0");
+  fprintf (ftable, "\nstatic const short yystos[] = {     0");
 
   j = 10;
   for (i = 1; i < nstates; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -420,10 +447,10 @@ output_stos (void)
 	  j++;
 	}
 
-      fprintf(ftable, "%6d", accessing_symbol[i]);
+      fprintf (ftable, "%6d", accessing_symbol[i]);
     }
 
-  fprintf(ftable, "\n};\n");
+  fprintf (ftable, "\n};\n");
 }
 
 
@@ -441,11 +468,11 @@ static const short yyrline[] = { 0", ftable);
   j = 10;
   for (i = 1; i <= nrules; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -453,40 +480,39 @@ static const short yyrline[] = { 0", ftable);
 	  j++;
 	}
 
-      fprintf(ftable, "%6d", rline[i]);
+      fprintf (ftable, "%6d", rline[i]);
     }
-  fprintf(ftable, "\n};\n#endif\n\n");
+  fprintf (ftable, "\n};\n#endif\n\n");
 
   if (toknumflag || noparserflag)
     {
-      fprintf(ftable, "#define YYNTOKENS %d\n", ntokens);
-      fprintf(ftable, "#define YYNNTS %d\n", nvars);
-      fprintf(ftable, "#define YYNRULES %d\n", nrules);
-      fprintf(ftable, "#define YYNSTATES %d\n", nstates);
-      fprintf(ftable, "#define YYMAXUTOK %d\n\n", max_user_token_number);
+      fprintf (ftable, "#define YYNTOKENS %d\n", ntokens);
+      fprintf (ftable, "#define YYNNTS %d\n", nvars);
+      fprintf (ftable, "#define YYNRULES %d\n", nrules);
+      fprintf (ftable, "#define YYNSTATES %d\n", nstates);
+      fprintf (ftable, "#define YYMAXUTOK %d\n\n", max_user_token_number);
     }
 
-  if (! toknumflag  && ! noparserflag)
-    fprintf(ftable, "\n#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)\n\n");
+  if (!toknumflag && !noparserflag)
+    fprintf (ftable, "\n#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)\n\n");
 
   /* Output the table of symbol names.  */
 
-  fprintf(ftable,
-          "static const char * const yytname[] = {   \"%s\"",
-          tags[0]);
+  fprintf (ftable,
+	   "static const char * const yytname[] = {   \"%s\"", tags[0]);
 
   j = strlen (tags[0]) + 44;
   for (i = 1; i < nsyms; i++)
-		/* this used to be i<=nsyms, but that output a final "" symbol
-			almost by accident */
+    /* this used to be i<=nsyms, but that output a final "" symbol
+       almost by accident */
     {
       register char *p;
-      putc(',', ftable);
+      putc (',', ftable);
       j++;
 
       if (j > 75)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 0;
 	}
 
@@ -497,32 +523,32 @@ static const short yyrline[] = { 0", ftable);
 	{
 	  if (*p == '"' || *p == '\\')
 	    {
-	      fprintf(ftable, "\\%c", *p);
+	      fprintf (ftable, "\\%c", *p);
 	      j += 2;
 	    }
 	  else if (*p == '\n')
 	    {
-	      fprintf(ftable, "\\n");
+	      fprintf (ftable, "\\n");
 	      j += 2;
 	    }
 	  else if (*p == '\t')
 	    {
-	      fprintf(ftable, "\\t");
+	      fprintf (ftable, "\\t");
 	      j += 2;
 	    }
 	  else if (*p == '\b')
 	    {
-	      fprintf(ftable, "\\b");
+	      fprintf (ftable, "\\b");
 	      j += 2;
 	    }
 	  else if (*p < 040 || *p >= 0177)
 	    {
-	      fprintf(ftable, "\\%03o", *p);
+	      fprintf (ftable, "\\%03o", *p);
 	      j += 4;
 	    }
 	  else
 	    {
-	      putc(*p, ftable);
+	      putc (*p, ftable);
 	      j++;
 	    }
 	}
@@ -533,26 +559,27 @@ static const short yyrline[] = { 0", ftable);
   /* add a NULL entry to list of tokens */
   fprintf (ftable, ", NULL\n};\n");
 
-  if (! toknumflag  && ! noparserflag)
+  if (!toknumflag && !noparserflag)
     fprintf (ftable, "#endif\n\n");
 
   /* Output YYTOKNUM. */
   if (toknumflag)
     {
-      fprintf(ftable, "static const short yytoknum[] = { 0");
+      fprintf (ftable, "static const short yytoknum[] = { 0");
       j = 10;
-      for (i = 1; i <= ntokens; i++) {
-          putc(',', ftable);
-          if (j >= 10)
-            {
-              putc('\n', ftable);
-              j = 1;
-            }
-          else
-            j++;
-          fprintf(ftable, "%6d", user_toknums[i]);
-      }
-      fprintf(ftable, "\n};\n\n");
+      for (i = 1; i <= ntokens; i++)
+	{
+	  putc (',', ftable);
+	  if (j >= 10)
+	    {
+	      putc ('\n', ftable);
+	      j = 1;
+	    }
+	  else
+	    j++;
+	  fprintf (ftable, "%6d", user_toknums[i]);
+	}
+      fprintf (ftable, "\n};\n\n");
     }
 
   /* Output YYR1. */
@@ -563,11 +590,11 @@ static const short yyr1[] = {     0", ftable);
   j = 10;
   for (i = 1; i <= nrules; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -575,9 +602,9 @@ static const short yyr1[] = {     0", ftable);
 	  j++;
 	}
 
-      fprintf(ftable, "%6d", rlhs[i]);
+      fprintf (ftable, "%6d", rlhs[i]);
     }
-  FREE(rlhs + 1);
+  FREE (rlhs + 1);
   fputs ("\n\
 };\n\
 \n", ftable);
@@ -589,11 +616,11 @@ static const short yyr2[] = {     0", ftable);
   j = 10;
   for (i = 1; i < nrules; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -601,24 +628,24 @@ static const short yyr2[] = {     0", ftable);
 	  j++;
 	}
 
-      fprintf(ftable, "%6d", rrhs[i + 1] - rrhs[i] - 1);
+      fprintf (ftable, "%6d", rrhs[i + 1] - rrhs[i] - 1);
     }
 
-  putc(',', ftable);
+  putc (',', ftable);
   if (j >= 10)
-    putc('\n', ftable);
+    putc ('\n', ftable);
 
-  fprintf(ftable, "%6d\n};\n", nitems - rrhs[nrules] - 1);
-  FREE(rrhs + 1);
+  fprintf (ftable, "%6d\n};\n", nitems - rrhs[nrules] - 1);
+  FREE (rrhs + 1);
 }
 
 
 static void
 output_defines (void)
 {
-  fprintf(ftable, "\n\n#define\tYYFINAL\t\t%d\n", final_state);
-  fprintf(ftable, "#define\tYYFLAG\t\t%d\n", MINSHORT);
-  fprintf(ftable, "#define\tYYNTBASE\t%d\n", ntokens);
+  fprintf (ftable, "\n\n#define\tYYFINAL\t\t%d\n", final_state);
+  fprintf (ftable, "#define\tYYFLAG\t\t%d\n", MINSHORT);
+  fprintf (ftable, "#define\tYYNTBASE\t%d\n", ntokens);
 }
 
 
@@ -630,29 +657,29 @@ output_actions (void)
 {
   nvectors = nstates + nvars;
 
-  froms = NEW2(nvectors, short *);
-  tos = NEW2(nvectors, short *);
-  tally = NEW2(nvectors, short);
-  width = NEW2(nvectors, short);
-
-  token_actions();
-  free_shifts();
-  free_reductions();
-  FREE(lookaheads);
-  FREE(LA);
-  FREE(LAruleno);
-  FREE(accessing_symbol);
-
-  goto_actions();
-  FREE(goto_map + ntokens);
-  FREE(from_state);
-  FREE(to_state);
-
-  sort_actions();
-  pack_table();
-  output_base();
-  output_table();
-  output_check();
+  froms = NEW2 (nvectors, short *);
+  tos = NEW2 (nvectors, short *);
+  tally = NEW2 (nvectors, short);
+  width = NEW2 (nvectors, short);
+
+  token_actions ();
+  free_shifts ();
+  free_reductions ();
+  FREE (lookaheads);
+  FREE (LA);
+  FREE (LAruleno);
+  FREE (accessing_symbol);
+
+  goto_actions ();
+  FREE (goto_map + ntokens);
+  FREE (from_state);
+  FREE (to_state);
+
+  sort_actions ();
+  pack_table ();
+  output_base ();
+  output_table ();
+  output_check ();
 }
 
 
@@ -670,20 +697,20 @@ token_actions (void)
   register int j;
   register int k;
 
-  actrow = NEW2(ntokens, short);
+  actrow = NEW2 (ntokens, short);
 
-  k = action_row(0);
-  fprintf(ftable, "\nstatic const short yydefact[] = {%6d", k);
-  save_row(0);
+  k = action_row (0);
+  fprintf (ftable, "\nstatic const short yydefact[] = {%6d", k);
+  save_row (0);
 
   j = 10;
   for (i = 1; i < nstates; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -691,13 +718,13 @@ token_actions (void)
 	  j++;
 	}
 
-      k = action_row(i);
-      fprintf(ftable, "%6d", k);
-      save_row(i);
+      k = action_row (i);
+      fprintf (ftable, "%6d", k);
+      save_row (i);
     }
 
-  fprintf(ftable, "\n};\n");
-  FREE(actrow);
+  fprintf (ftable, "\n};\n");
+  FREE (actrow);
 }
 
 
@@ -734,7 +761,7 @@ action_row (int state)
   register reductions *redp;
   register shifts *shiftp;
   register errs *errp;
-  int nodefault = 0;  /* set nonzero to inhibit having any default reduction */
+  int nodefault = 0;		/* set nonzero to inhibit having any default reduction */
 
   for (i = 0; i < ntokens; i++)
     actrow[i] = 0;
@@ -756,12 +783,12 @@ action_row (int state)
 
 	  for (i = n - 1; i >= m; i--)
 	    {
-	      rule = - LAruleno[i];
+	      rule = -LAruleno[i];
 	      wordp = LA + i * tokensetsize;
 	      mask = 1;
 
 	      /* and find each token which the rule finds acceptable
-		 to come next */
+	         to come next */
 	      for (j = 0; j < ntokens; j++)
 		{
 		  /* and record this rule as the rule to use if that
@@ -793,11 +820,12 @@ action_row (int state)
       for (i = 0; i < k; i++)
 	{
 	  shift_state = shiftp->shifts[i];
-	  if (! shift_state) continue;
+	  if (!shift_state)
+	    continue;
 
 	  symbol = accessing_symbol[shift_state];
 
-	  if (ISVAR(symbol))
+	  if (ISVAR (symbol))
 	    break;
 
 	  actrow[symbol] = shift_state;
@@ -828,7 +856,7 @@ action_row (int state)
   /* Now find the most common reduction and make it the default action
      for this state.  */
 
-  if (nreds >= 1 && ! nodefault)
+  if (nreds >= 1 && !nodefault)
     {
       if (consistent[state])
 	default_rule = redp->rules[0];
@@ -838,7 +866,7 @@ action_row (int state)
 	  for (i = m; i < n; i++)
 	    {
 	      count = 0;
-	      rule = - LAruleno[i];
+	      rule = -LAruleno[i];
 
 	      for (j = 0; j < ntokens; j++)
 		{
@@ -864,7 +892,7 @@ action_row (int state)
 		    actrow[j] = 0;
 		}
 
-	      default_rule = - default_rule;
+	      default_rule = -default_rule;
 	    }
 	}
     }
@@ -902,8 +930,8 @@ save_row (int state)
   if (count == 0)
     return;
 
-  froms[state] = sp1 = sp = NEW2(count, short);
-  tos[state] = sp2 = NEW2(count, short);
+  froms[state] = sp1 = sp = NEW2 (count, short);
+  tos[state] = sp2 = NEW2 (count, short);
 
   for (i = 0; i < ntokens; i++)
     {
@@ -934,20 +962,20 @@ goto_actions (void)
   register int j;
   register int k;
 
-  state_count = NEW2(nstates, short);
+  state_count = NEW2 (nstates, short);
 
-  k = default_goto(ntokens);
-  fprintf(ftable, "\nstatic const short yydefgoto[] = {%6d", k);
-  save_column(ntokens, k);
+  k = default_goto (ntokens);
+  fprintf (ftable, "\nstatic const short yydefgoto[] = {%6d", k);
+  save_column (ntokens, k);
 
   j = 10;
   for (i = ntokens + 1; i < nsyms; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -955,13 +983,13 @@ goto_actions (void)
 	  j++;
 	}
 
-      k = default_goto(i);
-      fprintf(ftable, "%6d", k);
-      save_column(i, k);
+      k = default_goto (i);
+      fprintf (ftable, "%6d", k);
+      save_column (i, k);
     }
 
-  fprintf(ftable, "\n};\n");
-  FREE(state_count);
+  fprintf (ftable, "\n};\n");
+  FREE (state_count);
 }
 
 
@@ -1030,8 +1058,8 @@ save_column (int symbol, int default_state)
 
   symno = symbol - ntokens + nstates;
 
-  froms[symno] = sp1 = sp = NEW2(count, short);
-  tos[symno] = sp2 = NEW2(count, short);
+  froms[symno] = sp1 = sp = NEW2 (count, short);
+  tos[symno] = sp2 = NEW2 (count, short);
 
   for (i = m; i < n; i++)
     {
@@ -1060,7 +1088,7 @@ sort_actions (void)
   register int t;
   register int w;
 
-  order = NEW2(nvectors, short);
+  order = NEW2 (nvectors, short);
   nentries = 0;
 
   for (i = 0; i < nvectors; i++)
@@ -1094,10 +1122,10 @@ pack_table (void)
   register int place;
   register int state;
 
-  base = NEW2(nvectors, short);
-  pos = NEW2(nentries, short);
-  table = NEW2(MAXTABLE, short);
-  check = NEW2(MAXTABLE, short);
+  base = NEW2 (nvectors, short);
+  pos = NEW2 (nentries, short);
+  table = NEW2 (MAXTABLE, short);
+  check = NEW2 (MAXTABLE, short);
 
   lowzero = 0;
   high = 0;
@@ -1110,10 +1138,10 @@ pack_table (void)
 
   for (i = 0; i < nentries; i++)
     {
-      state = matching_state(i);
+      state = matching_state (i);
 
       if (state < 0)
-	place = pack_vector(i);
+	place = pack_vector (i);
       else
 	place = base[state];
 
@@ -1124,14 +1152,14 @@ pack_table (void)
   for (i = 0; i < nvectors; i++)
     {
       if (froms[i])
-	FREE(froms[i]);
+	FREE (froms[i]);
       if (tos[i])
-	FREE(tos[i]);
+	FREE (tos[i]);
     }
 
-  FREE(froms);
-  FREE(tos);
-  FREE(pos);
+  FREE (froms);
+  FREE (tos);
+  FREE (pos);
 }
 
 
@@ -1192,7 +1220,7 @@ pack_vector (int vector)
   t = tally[i];
 
   if (t == 0)
-    berror("pack_vector");
+    berror ("pack_vector");
 
   from = froms[i];
   to = tos[i];
@@ -1236,8 +1264,8 @@ pack_vector (int vector)
 	}
     }
 
-  berror("pack_vector");
-  return 0;	/* JF keep lint happy */
+  berror ("pack_vector");
+  return 0;			/* JF keep lint happy */
 }
 
 
@@ -1251,16 +1279,16 @@ output_base (void)
   register int i;
   register int j;
 
-  fprintf(ftable, "\nstatic const short yypact[] = {%6d", base[0]);
+  fprintf (ftable, "\nstatic const short yypact[] = {%6d", base[0]);
 
   j = 10;
   for (i = 1; i < nstates; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -1268,19 +1296,20 @@ output_base (void)
 	  j++;
 	}
 
-      fprintf(ftable, "%6d", base[i]);
+      fprintf (ftable, "%6d", base[i]);
     }
 
-  fprintf(ftable, "\n};\n\nstatic const short yypgoto[] = {%6d", base[nstates]);
+  fprintf (ftable, "\n};\n\nstatic const short yypgoto[] = {%6d",
+	   base[nstates]);
 
   j = 10;
   for (i = nstates + 1; i < nvectors; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -1288,11 +1317,11 @@ output_base (void)
 	  j++;
 	}
 
-      fprintf(ftable, "%6d", base[i]);
+      fprintf (ftable, "%6d", base[i]);
     }
 
-  fprintf(ftable, "\n};\n");
-  FREE(base);
+  fprintf (ftable, "\n};\n");
+  FREE (base);
 }
 
 
@@ -1302,17 +1331,17 @@ output_table (void)
   register int i;
   register int j;
 
-  fprintf(ftable, "\n\n#define\tYYLAST\t\t%d\n\n", high);
-  fprintf(ftable, "\nstatic const short yytable[] = {%6d", table[0]);
+  fprintf (ftable, "\n\n#define\tYYLAST\t\t%d\n\n", high);
+  fprintf (ftable, "\nstatic const short yytable[] = {%6d", table[0]);
 
   j = 10;
   for (i = 1; i <= high; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -1320,11 +1349,11 @@ output_table (void)
 	  j++;
 	}
 
-      fprintf(ftable, "%6d", table[i]);
+      fprintf (ftable, "%6d", table[i]);
     }
 
-  fprintf(ftable, "\n};\n");
-  FREE(table);
+  fprintf (ftable, "\n};\n");
+  FREE (table);
 }
 
 
@@ -1334,16 +1363,16 @@ output_check (void)
   register int i;
   register int j;
 
-  fprintf(ftable, "\nstatic const short yycheck[] = {%6d", check[0]);
+  fprintf (ftable, "\nstatic const short yycheck[] = {%6d", check[0]);
 
   j = 10;
   for (i = 1; i <= high; i++)
     {
-      putc(',', ftable);
+      putc (',', ftable);
 
       if (j >= 10)
 	{
-	  putc('\n', ftable);
+	  putc ('\n', ftable);
 	  j = 1;
 	}
       else
@@ -1351,11 +1380,11 @@ output_check (void)
 	  j++;
 	}
 
-      fprintf(ftable, "%6d", check[i]);
+      fprintf (ftable, "%6d", check[i]);
     }
 
-  fprintf(ftable, "\n};\n");
-  FREE(check);
+  fprintf (ftable, "\n};\n");
+  FREE (check);
 }
 
 
@@ -1373,13 +1402,14 @@ output_parser (void)
 #endif
 
   if (pure_parser)
-    fprintf(ftable, "#define YYPURE 1\n\n");
+    fprintf (ftable, "#define YYPURE 1\n\n");
 
-#ifdef DONTDEF	/* JF no longer needed 'cuz open_extra_files changes the
-		   currently open parser from bison.simple to bison.hairy */
+#ifdef DONTDEF			/* JF no longer needed 'cuz open_extra_files changes the
+				   currently open parser from bison.simple to bison.hairy */
   if (semantic_parser)
     fpars = fparser;
-  else fpars = fparser1;
+  else
+    fpars = fparser1;
 #endif
 
   /* Loop over lines in the standard parser file.  */
@@ -1388,55 +1418,56 @@ output_parser (void)
     {
       int write_line = 1;
 
-      c = getc(fpars);
+      c = getc (fpars);
 
       /* See if the line starts with `#line.
-	 If so, set write_line to 0.  */
+         If so, set write_line to 0.  */
       if (nolinesflag)
 	if (c == '#')
 	  {
-	    c = getc(fpars);
+	    c = getc (fpars);
 	    if (c == 'l')
 	      {
-		c = getc(fpars);
+		c = getc (fpars);
 		if (c == 'i')
 		  {
-		    c = getc(fpars);
+		    c = getc (fpars);
 		    if (c == 'n')
 		      {
-			c = getc(fpars);
+			c = getc (fpars);
 			if (c == 'e')
 			  write_line = 0;
 			else
-			  fprintf(ftable, "#lin");
+			  fprintf (ftable, "#lin");
 		      }
 		    else
-		      fprintf(ftable, "#li");
+		      fprintf (ftable, "#li");
 		  }
 		else
-		  fprintf(ftable, "#l");
+		  fprintf (ftable, "#l");
 	      }
 	    else
-	      fprintf(ftable, "#");
+	      fprintf (ftable, "#");
 	  }
 
       /* now write out the line... */
-      for (; c != '\n' && c != EOF; c = getc(fpars))
-	if (write_line) {
-	  if (c == '$')
-	    {
-	      /* `$' in the parser file indicates where to put the actions.
-		 Copy them in at this point.  */
-	      rewind(faction);
-	      for(c=getc(faction);c!=EOF;c=getc(faction))
-		putc(c,ftable);
-	    }
-	  else
-	    putc(c, ftable);
-	}
+      for (; c != '\n' && c != EOF; c = getc (fpars))
+	if (write_line)
+	  {
+	    if (c == '$')
+	      {
+		/* `$' in the parser file indicates where to put the actions.
+		   Copy them in at this point.  */
+		rewind (faction);
+		for (c = getc (faction); c != EOF; c = getc (faction))
+		  putc (c, ftable);
+	      }
+	    else
+	      putc (c, ftable);
+	  }
       if (c == EOF)
 	break;
-      putc(c, ftable);
+      putc (c, ftable);
     }
 }
 
@@ -1446,13 +1477,13 @@ output_program (void)
   register int c;
 
   if (!nolinesflag)
-    fprintf(ftable, "#line %d \"%s\"\n", lineno, infile);
+    fprintf (ftable, "#line %d \"%s\"\n", lineno, infile);
 
-  c = getc(finput);
+  c = getc (finput);
   while (c != EOF)
     {
-      putc(c, ftable);
-      c = getc(finput);
+      putc (c, ftable);
+      c = getc (finput);
     }
 }
 
@@ -1460,14 +1491,14 @@ output_program (void)
 static void
 free_itemsets (void)
 {
-  register core *cp,*cptmp;
+  register core *cp, *cptmp;
 
-  FREE(state_table);
+  FREE (state_table);
 
   for (cp = first_state; cp; cp = cptmp)
     {
-      cptmp=cp->next;
-      FREE(cp);
+      cptmp = cp->next;
+      FREE (cp);
     }
 }
 
@@ -1475,14 +1506,14 @@ free_itemsets (void)
 static void
 free_shifts (void)
 {
-  register shifts *sp,*sptmp;/* JF derefrenced freed ptr */
+  register shifts *sp, *sptmp;	/* JF derefrenced freed ptr */
 
-  FREE(shift_table);
+  FREE (shift_table);
 
   for (sp = first_shift; sp; sp = sptmp)
     {
-      sptmp=sp->next;
-      FREE(sp);
+      sptmp = sp->next;
+      FREE (sp);
     }
 }
 
@@ -1490,13 +1521,13 @@ free_shifts (void)
 static void
 free_reductions (void)
 {
-  register reductions *rp,*rptmp;/* JF fixed freed ptr */
+  register reductions *rp, *rptmp;	/* JF fixed freed ptr */
 
-  FREE(reduction_table);
+  FREE (reduction_table);
 
   for (rp = first_reduction; rp; rp = rptmp)
     {
-      rptmp=rp->next;
-      FREE(rp);
+      rptmp = rp->next;
+      FREE (rp);
     }
 }
