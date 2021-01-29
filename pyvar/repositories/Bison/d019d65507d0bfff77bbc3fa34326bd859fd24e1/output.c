@@ -99,8 +99,10 @@
 #include "complain.h"
 #include "output.h"
 
+extern void berror PARAMS((const char *));
+
 extern char **tags;
-extern int *user_toknums;
+extern short *user_toknums;
 extern int tokensetsize;
 extern int final_state;
 extern core **state_table;
@@ -136,6 +138,44 @@ static int high;
 
 
 
+static inline void
+output_short_table (FILE *out,
+		    const char *table_name,
+		    short *short_table,
+		    short first_value,
+		    short begin, short end)
+{
+  int i, j;
+
+  fprintf (out, "static const short %s[] = {%6d", table_name, first_value);
+
+  j = 10;
+  for (i = begin; i < end; i++)
+    {
+      putc (',', out);
+
+      if (j >= 10)
+	{
+	  putc ('\n', out);
+	  j = 1;
+	}
+      else
+	{
+	  j++;
+	}
+
+      fprintf (out, "%6d", short_table[i]);
+    }
+
+  fprintf (out, "\n};\n");
+}
+
+
+/*--------------------------------------------------------------.
+| output_headers -- Output constant strings to the beginning of |
+| certain files.                                                |
+`--------------------------------------------------------------*/
+
 #define	GUARDSTR	\
 "\n\
 #include \"%s\"\n\
@@ -171,11 +211,6 @@ register YYLTYPE *yylsp;\n\
 
 #define	ACTSTR_SIMPLE	"\n  switch (yyn) {\n"
 
-
-/*------------------------------------------------------------.
-| Output constant strings to the beginning of certain files.  |
-`------------------------------------------------------------*/
-
 void
 output_headers (void)
 {
@@ -274,7 +309,6 @@ output_token_translations (void)
 static void
 output_gram (void)
 {
-  int i;
   int j;
   short *sp;
 
@@ -282,29 +316,10 @@ output_gram (void)
      yyprhs and yyrhs are needed only for yydebug. */
   /* With the noparser option, all tables are generated */
   if (!semantic_parser && !noparserflag)
-    fprintf (ftable, "\n#if YYDEBUG != 0");
-
-  fprintf (ftable, "\nstatic const short yyprhs[] = {     0");
+    fprintf (ftable, "\n#if YYDEBUG != 0\n");
 
-  j = 10;
-  for (i = 1; i <= nrules; i++)
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
-      fprintf (ftable, "%6d", rrhs[i]);
-    }
-
-  fprintf (ftable, "\n};\n");
+  output_short_table (ftable, "yyprhs", rrhs,
+		      0, 1, nrules + 1);
 
   fprintf (ftable, "\nstatic const short yyrhs[] = {%6d", ritem[0]);
 
@@ -339,30 +354,8 @@ output_gram (void)
 static void
 output_stos (void)
 {
-  int i;
-  int j;
-
-  fprintf (ftable, "\nstatic const short yystos[] = {     0");
-
-  j = 10;
-  for (i = 1; i < nstates; i++)
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
-      fprintf (ftable, "%6d", accessing_symbol[i]);
-    }
-
-  fprintf (ftable, "\n};\n");
+  output_short_table (ftable, "yystos", accessing_symbol,
+		      0, 1, nstates);
 }
 
 
@@ -374,27 +367,13 @@ output_rule_data (void)
 
   fputs ("\n\
 #if YYDEBUG != 0\n\
-/* YYRLINE[yyn]: source line where rule number YYN was defined. */\n\
-static const short yyrline[] = { 0", ftable);
-
-  j = 10;
-  for (i = 1; i <= nrules; i++)
-    {
-      putc (',', ftable);
+/* YYRLINE[yyn]: source line where rule number YYN was defined. */\n",
+	 ftable);
 
-      if (j >= 10)
-	{
-	  putc ('\n', ftable);
-	  j = 1;
-	}
-      else
-	{
-	  j++;
-	}
+  output_short_table (ftable, "yyrline", rline,
+		      0, 1, nrules + 1);
 
-      fprintf (ftable, "%6d", rline[i]);
-    }
-  fprintf (ftable, "\n};\n#endif\n\n");
+  fputs ("#endif\n\n", ftable);
 
   if (toknumflag || noparserflag)
     {
@@ -477,49 +456,19 @@ static const short yyrline[] = { 0", ftable);
   /* Output YYTOKNUM. */
   if (toknumflag)
     {
-      fprintf (ftable, "static const short yytoknum[] = { 0");
-      j = 10;
-      for (i = 1; i <= ntokens; i++)
-	{
-	  putc (',', ftable);
-	  if (j >= 10)
-	    {
-	      putc ('\n', ftable);
-	      j = 1;
-	    }
-	  else
-	    j++;
-	  fprintf (ftable, "%6d", user_toknums[i]);
-	}
-      fprintf (ftable, "\n};\n\n");
+      output_short_table (ftable, "yytoknum", user_toknums,
+			  0, 1, ntokens + 1);
     }
 
   /* Output YYR1. */
   fputs ("\
-/* YYR1[YYN]: Symbol number of symbol that rule YYN derives. */\n\
-static const short yyr1[] = {     0", ftable);
-
-  j = 10;
-  for (i = 1; i <= nrules; i++)
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
+/* YYR1[YYN]: Symbol number of symbol that rule YYN derives. */\n", ftable);
 
-      fprintf (ftable, "%6d", rlhs[i]);
-    }
+  output_short_table (ftable, "yyr1", rlhs,
+		      0, 1, nrules + 1);
   FREE (rlhs + 1);
-  fputs ("\n\
-};\n\
-\n", ftable);
+
+  putc ('\n', ftable);
 
   /* Output YYR2. */
   fputs ("\
@@ -1179,51 +1128,14 @@ pack_table (void)
 static void
 output_base (void)
 {
-  int i;
-  int j;
+  output_short_table (ftable, "yypact", base,
+		      base[0], 1, nstates);
 
-  fprintf (ftable, "\nstatic const short yypact[] = {%6d", base[0]);
+  putc ('\n', ftable);
 
-  j = 10;
-  for (i = 1; i < nstates; i++)
-    {
-      putc (',', ftable);
+  output_short_table (ftable, "yypgoto", base,
+		      base[nstates], nstates + 1, nvectors);
 
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
-      fprintf (ftable, "%6d", base[i]);
-    }
-
-  fprintf (ftable, "\n};\n\nstatic const short yypgoto[] = {%6d",
-	   base[nstates]);
-
-  j = 10;
-  for (i = nstates + 1; i < nvectors; i++)
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
-      fprintf (ftable, "%6d", base[i]);
-    }
-
-  fprintf (ftable, "\n};\n");
   FREE (base);
 }
 
@@ -1231,31 +1143,9 @@ output_base (void)
 static void
 output_table (void)
 {
-  int i;
-  int j;
-
-  fprintf (ftable, "\n\n#define\tYYLAST\t\t%d\n\n", high);
-  fprintf (ftable, "\nstatic const short yytable[] = {%6d", table[0]);
-
-  j = 10;
-  for (i = 1; i <= high; i++)
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
-      fprintf (ftable, "%6d", table[i]);
-    }
-
-  fprintf (ftable, "\n};\n");
+  fprintf (ftable, "\n\n#define\tYYLAST\t\t%d\n\n\n", high);
+  output_short_table (ftable, "yytable", table,
+		      table[0], 1, high + 1);
   FREE (table);
 }
 
@@ -1263,30 +1153,8 @@ output_table (void)
 static void
 output_check (void)
 {
-  int i;
-  int j;
-
-  fprintf (ftable, "\nstatic const short yycheck[] = {%6d", check[0]);
-
-  j = 10;
-  for (i = 1; i <= high; i++)
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
-      fprintf (ftable, "%6d", check[i]);
-    }
-
-  fprintf (ftable, "\n};\n");
+  output_short_table (ftable, "yycheck", check,
+		      check[0], 1, high + 1);
   FREE (check);
 }
 
@@ -1318,8 +1186,10 @@ output_actions (void)
 
   sort_actions ();
   pack_table ();
+  putc ('\n', ftable);
   output_base ();
   output_table ();
+  putc ('\n', ftable);
   output_check ();
 }
 
