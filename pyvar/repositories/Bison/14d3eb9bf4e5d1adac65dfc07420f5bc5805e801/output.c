@@ -92,6 +92,7 @@
 
 #include "system.h"
 #include "obstack.h"
+#include "quotearg.h"
 #include "getargs.h"
 #include "xalloc.h"
 #include "files.h"
@@ -182,9 +183,11 @@ output_short_table (struct obstack *oout,
 | certain files.                                                |
 `--------------------------------------------------------------*/
 
+/* Don't put the `%s' insides quotes, since it quotearg puts them. */
+
 #define	GUARDSTR	\
 "\n\
-#include \"%s\"\n\
+#include %s\n\
 extern int yyerror;\n\
 extern int yycost;\n\
 extern char * yymsg;\n\
@@ -203,24 +206,7 @@ register YYLTYPE *yylsp;\n\
 
 #define	ACTSTR		\
 "\n\
-#include \"%s\"\n\
-extern YYSTYPE yyval;\n\
-extern int yychar;\n\
-\n\
-yyaction(n, yyvsp, yylsp)\n\
-register int n;\n\
-register YYSTYPE *yyvsp;\n\
-register YYLTYPE *yylsp;\n\
-{\n\
-  switch (n)\n\
-    {"
-
-#define	ACTSTR_PROLOGUE		\
-"\n\
-#include \""
-
-#define	ACTSTR_EPILOGUE		\
-"\"\n\
+#include %s\n\
 extern YYSTYPE yyval;\n\
 extern int yychar;\n\
 \n\
@@ -237,25 +223,18 @@ register YYLTYPE *yylsp;\n\
 void
 output_headers (void)
 {
+  char *attrsfile_quoted = quotearg_style (c_quoting_style, attrsfile);
+
   if (semantic_parser)
-    fprintf (fguard, GUARDSTR, attrsfile);
+    fprintf (fguard, GUARDSTR, attrsfile_quoted);
 
   if (no_parser_flag)
     return;
 
   if (semantic_parser)
-    {
-      obstack_grow_literal_string (&action_obstack,
-				   ACTSTR_PROLOGUE);
-      obstack_grow (&action_obstack,
-                    attrsfile, strlen (attrsfile));
-      obstack_grow_literal_string (&action_obstack,
-				   ACTSTR_EPILOGUE);
-   }
+    obstack_fgrow1 (&action_obstack, ACTSTR, attrsfile_quoted);
   else
-   {
-      obstack_grow_literal_string (&action_obstack, ACTSTR_SIMPLE);
-   }
+    obstack_grow_literal_string (&action_obstack, ACTSTR_SIMPLE);
 
 /*  if (semantic_parser)	JF moved this below
     fprintf(ftable, "#include \"%s\"\n", attrsfile);
@@ -266,19 +245,19 @@ output_headers (void)
   if (spec_name_prefix)
     {
       obstack_fgrow1 (&table_obstack,
-			"#define yyparse %sparse\n", spec_name_prefix);
+		      "#define yyparse %sparse\n", spec_name_prefix);
       obstack_fgrow1 (&table_obstack,
-			"#define yylex %slex\n", spec_name_prefix);
+		      "#define yylex %slex\n", spec_name_prefix);
       obstack_fgrow1 (&table_obstack,
-			"#define yyerror %serror\n", spec_name_prefix);
+		      "#define yyerror %serror\n", spec_name_prefix);
       obstack_fgrow1 (&table_obstack,
-			"#define yylval %slval\n", spec_name_prefix);
+		      "#define yylval %slval\n", spec_name_prefix);
       obstack_fgrow1 (&table_obstack,
-			"#define yychar %schar\n", spec_name_prefix);
+		      "#define yychar %schar\n", spec_name_prefix);
       obstack_fgrow1 (&table_obstack,
-			"#define yydebug %sdebug\n", spec_name_prefix);
+		      "#define yydebug %sdebug\n", spec_name_prefix);
       obstack_fgrow1 (&table_obstack,
-			"#define yynerrs %snerrs\n", spec_name_prefix);
+		      "#define yynerrs %snerrs\n", spec_name_prefix);
     }
 }
 
@@ -299,12 +278,9 @@ output_trailers (void)
     return;
 
   if (semantic_parser)
-    {
-      obstack_grow_literal_string (&action_obstack,
-				   "    }\n");
-    }
-  obstack_grow_literal_string (&action_obstack,
-			       "}\n");
+    obstack_grow_literal_string (&action_obstack, "    }\n");
+
+  obstack_grow_literal_string (&action_obstack, "}\n");
 }
 
 
@@ -1275,14 +1251,11 @@ output_program (void)
   int c;
 
   if (!no_lines_flag)
-    obstack_fgrow2 (&table_obstack, "#line %d \"%s\"\n", lineno, infile);
+    obstack_fgrow2 (&table_obstack, "#line %d %s\n",
+		    lineno, quotearg_style (c_quoting_style, infile));
 
-  c = getc (finput);
-  while (c != EOF)
-    {
-      obstack_1grow (&table_obstack, c);
-      c = getc (finput);
-    }
+  while ((c = getc (finput)) != EOF)
+    obstack_1grow (&table_obstack, c);
 }
 
 
@@ -1326,7 +1299,8 @@ output (void)
 \n");
 
   if (semantic_parser)
-    obstack_fgrow1 (&table_obstack, "#include \"%s\"\n", attrsfile);
+    obstack_fgrow1 (&table_obstack, "#include %s\n",
+		    quotearg_style (c_quoting_style, attrsfile));
 
   if (!no_parser_flag)
     obstack_grow_literal_string (&table_obstack, "#include <stdio.h>\n\n");
