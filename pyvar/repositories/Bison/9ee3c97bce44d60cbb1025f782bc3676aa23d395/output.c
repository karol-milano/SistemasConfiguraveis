@@ -1,22 +1,22 @@
 /* Output the generated parsing program for bison,
-   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   Bison is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to the Free
+   Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
+   02111-1307, USA.  */
 
 
 /* functions to output parsing data to various files.  Entries are:
@@ -76,11 +76,11 @@ yypact[s] = index in yytable of the portion describing state s.
 
 	    If the value is zero, the default action from yydefact[s] is used.
 
-yypgoto[i] = the index in yytable of the portion describing 
+yypgoto[i] = the index in yytable of the portion describing
              what to do after reducing a rule that derives variable i + ntokens.
              This portion is indexed by the parser state number, s,
 	     as of before the text for this nonterminal was read.
-	     The value from yytable is the state to go to if 
+	     The value from yytable is the state to go to if
              the corresponding value in yycheck is s.
 
 yytable = a vector filled with portions for different uses,
@@ -236,8 +236,8 @@ output_trailers (void)
       fprintf(fguard, "\n    }\n}\n");
 
   fprintf(faction, "\n");
-  
-  if (noparserflag) 
+
+  if (noparserflag)
       return;
 
   if (semantic_parser)
@@ -300,17 +300,17 @@ output_token_translations (void)
       fprintf(ftable,
 	      "\n#define YYTRANSLATE(x) ((unsigned)(x) <= %d ? yytranslate[x] : %d)\n",
 	      max_user_token_number, nsyms);
-    
+
       if (ntokens < 127)  /* play it very safe; check maximum element value.  */
         fprintf(ftable, "\nstatic const char yytranslate[] = {     0");
       else
 	fprintf(ftable, "\nstatic const short yytranslate[] = {     0");
-    
+
       j = 10;
       for (i = 1; i <= max_user_token_number; i++)
 	{
 	  putc(',', ftable);
-    
+
 	  if (j >= 10)
 	    {
 	      putc('\n', ftable);
@@ -320,16 +320,16 @@ output_token_translations (void)
 	    {
 	      j++;
 	    }
-    
+
 	  fprintf(ftable, "%6d", token_translations[i]);
 	}
-    
+
       fprintf(ftable, "\n};\n");
     }
   else
     {
       fprintf(ftable, "\n#define YYTRANSLATE(x) (x)\n");
-    } 
+    }
 }
 
 
@@ -340,7 +340,7 @@ output_gram (void)
   register int j;
   register short *sp;
 
-  /* With the ordinary parser, 
+  /* With the ordinary parser,
      yyprhs and yyrhs are needed only for yydebug. */
   /* With the noparser option, all tables are generated */
   if (! semantic_parser  && ! noparserflag)
@@ -434,8 +434,10 @@ output_rule_data (void)
   register int i;
   register int j;
 
-  fprintf(ftable, "\n#if YYDEBUG != 0\n");
-  fprintf(ftable, "static const short yyrline[] = { 0");
+  fputs ("\n\
+#if YYDEBUG != 0\n\
+/* YYRLINE[yyn]: source line where rule number YYN was defined. */\n\
+static const short yyrline[] = { 0", ftable);
 
   j = 10;
   for (i = 1; i <= nrules; i++)
@@ -529,18 +531,20 @@ output_rule_data (void)
       putc ('\"', ftable);
       j++;
     }
-    fprintf(ftable, ", NULL\n};\n");	/* add a NULL entry to list of tokens */
+  /* add a NULL entry to list of tokens */
+  fprintf (ftable, ", NULL\n};\n");
 
   if (! toknumflag  && ! noparserflag)
-    fprintf(ftable, "#endif\n\n");
+    fprintf (ftable, "#endif\n\n");
 
-  if (toknumflag) 
+  /* Output YYTOKNUM. */
+  if (toknumflag)
     {
       fprintf(ftable, "static const short yytoknum[] = { 0");
       j = 10;
       for (i = 1; i <= ntokens; i++) {
           putc(',', ftable);
-          if (j >= 10) 
+          if (j >= 10)
             {
               putc('\n', ftable);
               j = 1;
@@ -552,7 +556,10 @@ output_rule_data (void)
       fprintf(ftable, "\n};\n\n");
     }
 
-  fprintf(ftable, "static const short yyr1[] = {     0");
+  /* Output YYR1. */
+  fputs ("\
+/* YYR1[YYN]: Symbol number of symbol that rule YYN derives. */\n\
+static const short yyr1[] = {     0", ftable);
 
   j = 10;
   for (i = 1; i <= nrules; i++)
@@ -571,11 +578,15 @@ output_rule_data (void)
 
       fprintf(ftable, "%6d", rlhs[i]);
     }
-
   FREE(rlhs + 1);
-
-  fprintf(ftable, "\n};\n\nstatic const short yyr2[] = {     0");
-
+  fputs ("\n\
+};\n\
+\n", ftable);
+
+  /* Output YYR2. */
+  fputs ("\
+/* YYR2[YYN]: Number of symbols composing right hand side of rule YYN. */\n\
+static const short yyr2[] = {     0", ftable);
   j = 10;
   for (i = 1; i < nrules; i++)
     {
@@ -821,23 +832,23 @@ action_row (int state)
 	    {
 	      count = 0;
 	      rule = - LAruleno[i];
-    
+
 	      for (j = 0; j < ntokens; j++)
 		{
 		  if (actrow[j] == rule)
 		    count++;
 		}
-    
+
 	      if (count > max)
 		{
 		  max = count;
 		  default_rule = rule;
 		}
 	    }
-    
+
 	  /* actions which match the default are replaced with zero,
 	     which means "use the default" */
-    
+
 	  if (max > 0)
 	    {
 	      for (j = 0; j < ntokens; j++)
@@ -845,7 +856,7 @@ action_row (int state)
 		  if (actrow[j] == default_rule)
 		    actrow[j] = 0;
 		}
-    
+
 	      default_rule = - default_rule;
 	    }
 	}
@@ -1030,8 +1041,8 @@ save_column (int symbol, int default_state)
 
 
 
-/* the next few functions decide how to pack 
-   the actions and gotos information into yytable. */
+/* The next few functions decide how to pack the actions and gotos
+   information into yytable. */
 
 void
 sort_actions (void)
@@ -1375,7 +1386,7 @@ output_parser (void)
       /* See if the line starts with `#line.
 	 If so, set write_line to 0.  */
       if (nolinesflag)
-	if (c == '#') 
+	if (c == '#')
 	  {
 	    c = getc(fpars);
 	    if (c == 'l')
