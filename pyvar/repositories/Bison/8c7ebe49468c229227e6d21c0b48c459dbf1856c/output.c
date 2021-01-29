@@ -1,5 +1,5 @@
 /* Output the generated parsing program for bison,
-   Copyright (C) 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -91,6 +91,7 @@
 */
 
 #include "system.h"
+#include "obstack.h"
 #include "getargs.h"
 #include "xalloc.h"
 #include "files.h"
@@ -214,6 +215,23 @@ register YYLTYPE *yylsp;\n\
   switch (n)\n\
     {"
 
+#define	ACTSTR_PROLOGUE		\
+"\n\
+#include \""
+
+#define	ACTSTR_EPILOGUE		\
+"\"\n\
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
+
 #define	ACTSTR_SIMPLE	"\n  switch (yyn) {\n"
 
 void
@@ -225,7 +243,20 @@ output_headers (void)
   if (no_parser_flag)
     return;
 
-  fprintf (faction, (semantic_parser ? ACTSTR : ACTSTR_SIMPLE), attrsfile);
+  if (semantic_parser)
+    {
+      obstack_grow_literal_string (&action_obstack,
+				   ACTSTR_PROLOGUE);
+      obstack_grow (&action_obstack,
+                    attrsfile, strlen (attrsfile));
+      obstack_grow_literal_string (&action_obstack,
+				   ACTSTR_EPILOGUE);
+   }
+  else
+   {
+      obstack_grow_literal_string (&action_obstack, ACTSTR_SIMPLE);
+   }
+
 /*  if (semantic_parser)	JF moved this below
     fprintf(ftable, "#include \"%s\"\n", attrsfile);
   fprintf(ftable, "#include <stdio.h>\n\n");
@@ -255,14 +286,18 @@ output_trailers (void)
   if (semantic_parser)
     fprintf (fguard, "\n    }\n}\n");
 
-  fprintf (faction, "\n");
+  obstack_1grow (&action_obstack, '\n');
 
   if (no_parser_flag)
     return;
 
   if (semantic_parser)
-    fprintf (faction, "    }\n");
-  fprintf (faction, "}\n");
+    {
+      obstack_grow_literal_string (&action_obstack,
+				   "    }\n");
+    }
+  obstack_grow_literal_string (&action_obstack,
+			       "}\n");
 }
 
 
@@ -1201,15 +1236,17 @@ output_parser (void)
       for (; c != '\n' && c != EOF; c = getc (fpars))
 	if (write_line)
 	  {
+	    /* `$' in the parser file indicates where to put the
+	       actions.  Copy them in at this point.  */
 	    if (c == '$')
 	      {
+		size_t size = obstack_object_size (&action_obstack);
+
 		number_of_dollar_signs++;
 		assert (number_of_dollar_signs == 1);
-		/* `$' in the parser file indicates where to put the actions.
-		   Copy them in at this point.  */
-		rewind (faction);
-		for (c = getc (faction); c != EOF; c = getc (faction))
-		  putc (c, ftable);
+		fwrite (obstack_finish (&action_obstack),
+			1, size, ftable);
+
 		/* Skip the end of the line containing `$'. */
 		write_line = 0;
 	      }
