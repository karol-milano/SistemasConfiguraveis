@@ -1,5 +1,5 @@
 /* Output the generated parsing program for bison,
-   Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.
 
 This file is part of Bison, the GNU Compiler Compiler.
 
@@ -34,10 +34,13 @@ Output the parsing tables and the parser code to ftable.
 
 The parser tables consist of these tables.
 Starred ones needed only for the semantic parser.
+Double starred are output only if switches are set.
 
 yytranslate = vector mapping yylex's token numbers into bison's token numbers.
 
-yytname = vector of string-names indexed by bison token number
+** yytname = vector of string-names indexed by bison token number
+
+** yytoknum = vector of yylex token numbers corresponding to entries in yytname
 
 yyrline = vector of line-numbers of all rules.  For yydebug printouts.
 
@@ -74,9 +77,10 @@ yypact[s] = index in yytable of the portion describing state s.
 
 yypgoto[i] = the index in yytable of the portion describing 
              what to do after reducing a rule that derives variable i + ntokens.
-             This portion is indexed by the parser state number
+             This portion is indexed by the parser state number, s,
 	     as of before the text for this nonterminal was read.
-	     The value from yytable is the state to go to.
+	     The value from yytable is the state to go to if 
+             the corresponding value in yycheck is s.
 
 yytable = a vector filled with portions for different uses,
           found via yypact and yypgoto.
@@ -109,8 +113,11 @@ YYNTBASE = ntokens.
 
 extern int debugflag;
 extern int nolinesflag;
+extern int noparserflag;
+extern int toknumflag;
 
 extern char **tags;
+extern int *user_toknums;
 extern int tokensetsize;
 extern int final_state;
 extern core **state_table;
@@ -154,6 +161,8 @@ int pack_vector();
 
 extern void berror();
 extern void fatals();
+extern char *int_to_string();
+extern void reader_output_yylsp();
 
 static int nvectors;
 static int nentries;
@@ -192,6 +201,10 @@ output_headers()
 {
   if (semantic_parser)
     fprintf(fguard, GUARDSTR, attrsfile);
+
+  if (noparserflag)
+	return;
+
   fprintf(faction, (semantic_parser ? ACTSTR : ACTSTR_SIMPLE), attrsfile);
 /*  if (semantic_parser)	JF moved this below
     fprintf(ftable, "#include \"%s\"\n", attrsfile);
@@ -216,12 +229,16 @@ void
 output_trailers()
 {
   if (semantic_parser)
-    {
       fprintf(fguard, "\n    }\n}\n");
-      fprintf(faction, "\n    }\n}\n");
-    }
-  else
-    fprintf(faction, "\n}\n");
+
+  fprintf(faction, "\n");
+  
+  if (noparserflag) 
+      return;
+
+  if (semantic_parser)
+      fprintf(faction, "    }\n");
+  fprintf(faction, "}\n");
 }
 
 
@@ -237,14 +254,16 @@ output()
       while ((c=getc(fattrs))!=EOF)
         putc(c,ftable);
     }
-
+  reader_output_yylsp(ftable);
   if (debugflag)
     fprintf(ftable, "#ifndef YYDEBUG\n#define YYDEBUG %d\n#endif\n\n",
 	    !!debugflag);
 
   if (semantic_parser)
     fprintf(ftable, "#include \"%s\"\n", attrsfile);
-  fprintf(ftable, "#include <stdio.h>\n\n");
+
+  if (! noparserflag)
+    fprintf(ftable, "#include <stdio.h>\n\n");
 
   /* Make "const" do nothing if not in ANSI C.  */
   fprintf (ftable, "#ifndef __cplusplus\n#ifndef __STDC__\n#define const\n#endif\n#endif\n\n");
@@ -260,7 +279,8 @@ output()
     output_stos();
   output_rule_data();
   output_actions();
-  output_parser();
+  if (! noparserflag)
+    output_parser();
   output_program();
 }
 
@@ -316,9 +336,10 @@ output_gram()
   register int j;
   register short *sp;
 
-  /* With the ordinary parser,
-     yyprhs and yyrhs are needed only for yydebug.  */
-  if (!semantic_parser)
+  /* With the ordinary parser, 
+     yyprhs and yyrhs are needed only for yydebug. */
+  /* With the noparser option, all tables are generated */
+  if (! semantic_parser  && ! noparserflag)
     fprintf(ftable, "\n#if YYDEBUG != 0");
 
   fprintf(ftable, "\nstatic const short yyprhs[] = {     0");
@@ -368,7 +389,7 @@ output_gram()
 
   fprintf(ftable, "\n};\n");
 
-  if(!semantic_parser)
+  if (! semantic_parser  && ! noparserflag)
     fprintf(ftable, "\n#endif\n");
 }
 
@@ -409,7 +430,8 @@ output_rule_data()
   register int i;
   register int j;
 
-  fprintf(ftable, "\n#if YYDEBUG != 0\nstatic const short yyrline[] = { 0");
+  fprintf(ftable, "\n#if YYDEBUG != 0\n");
+  fprintf(ftable, "static const short yyrline[] = { 0");
 
   j = 10;
   for (i = 1; i <= nrules; i++)
@@ -428,15 +450,30 @@ output_rule_data()
 
       fprintf(ftable, "%6d", rline[i]);
     }
+  fprintf(ftable, "\n};\n#endif\n\n");
+
+  if (toknumflag || noparserflag)
+    {
+      fprintf(ftable, "#define YYNTOKENS %d\n", ntokens);
+      fprintf(ftable, "#define YYNNTS %d\n", nvars);
+      fprintf(ftable, "#define YYNRULES %d\n", nrules);
+      fprintf(ftable, "#define YYNSTATES %d\n", nstates);
+      fprintf(ftable, "#define YYMAXUTOK %d\n\n", max_user_token_number);
+    }
+
+  if (! toknumflag  && ! noparserflag)
+    fprintf(ftable, "\n#if YYDEBUG != 0\n\n");
 
   /* Output the table of symbol names.  */
 
   fprintf(ftable,
-          "\n};\n\nstatic const char * const yytname[] = {   \"%s\"",
+          "static const char * const yytname[] = {   \"%s\"",
           tags[0]);
 
   j = strlen (tags[0]) + 44;
-  for (i = 1; i <= nsyms; i++)
+  for (i = 1; i < nsyms; i++)
+		/* this used to be i<=nsyms, but that output a final "" symbol
+			almost by accident */
     {
       register char *p;
       putc(',', ftable);
@@ -488,8 +525,30 @@ output_rule_data()
       putc ('\"', ftable);
       j++;
     }
+    fprintf(ftable, ", NULL\n};\n");	/* add a NULL entry to list of tokens */
 
-  fprintf(ftable, "\n};\n#endif\n\nstatic const short yyr1[] = {     0");
+  if (! toknumflag  && ! noparserflag)
+    fprintf(ftable, "#endif\n\n");
+
+  if (toknumflag) 
+    {
+      fprintf(ftable, "static const short yytoknum[] = { 0");
+      j = 10;
+      for (i = 1; i <= ntokens; i++) {
+          putc(',', ftable);
+          if (j >= 10) 
+            {
+              putc('\n', ftable);
+              j = 1;
+            }
+          else
+            j++;
+          fprintf(ftable, "%6d", user_toknums[i]);
+      }
+      fprintf(ftable, "\n};\n\n");
+    }
+
+  fprintf(ftable, "static const short yyr1[] = {     0");
 
   j = 10;
   for (i = 1; i <= nrules; i++)
@@ -1131,7 +1190,7 @@ int vector;
 	{
 	  loc = j + from[k];
 	  if (loc > MAXTABLE)
-	    fatals("maximum table size (%d) exceeded",MAXTABLE);
+	    fatals("maximum table size (%s) exceeded", int_to_string(MAXTABLE));
 
 	  if (table[loc] != 0)
 	    ok = 0;
@@ -1347,7 +1406,7 @@ output_parser()
 	  }
 
       /* now write out the line... */
-      for ( ; c != '\n' && c != EOF; c = getc(fpars))
+      for (; c != '\n' && c != EOF; c = getc(fpars))
 	if (write_line)
 	  if (c == '$')
 	    {
@@ -1365,7 +1424,6 @@ output_parser()
     }
 }
 
-
 void
 output_program()
 {
