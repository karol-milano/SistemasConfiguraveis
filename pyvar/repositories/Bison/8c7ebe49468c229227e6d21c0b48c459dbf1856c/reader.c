@@ -1,5 +1,5 @@
 /* Input parser for bison
-   Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000
+   Copyright 1984, 1986, 1989, 1992, 1998, 2000
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -21,6 +21,7 @@
 
 
 #include "system.h"
+#include "obstack.h"
 #include "getargs.h"
 #include "files.h"
 #include "xalloc.h"
@@ -151,17 +152,21 @@ get_type_name (int n, symbol_list * rule)
   return rp->sym->type_name;
 }
 
-/*-------------------------------------------------------------------.
-| Dump the string from FINPUT to FOUTPUT.  MATCH is the delimiter of |
-| the string (either ' or ").                                        |
-`-------------------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| Dump the string from FIN to FOUT and OOUT if non null.  MATCH is |
+| the delimiter of the string (either ' or ").                     |
+`-----------------------------------------------------------------*/
 
 static inline void
-copy_string (FILE *fin, FILE *fout, int match)
+copy_string (FILE *fin, FILE *fout, struct obstack *oout, int match)
 {
   int c;
 
-  putc (match, fout);
+  if (fout)
+    putc (match, fout);
+  if (oout)
+    obstack_1grow (oout, match);
+
   c = getc (fin);
 
   while (c != match)
@@ -176,14 +181,21 @@ copy_string (FILE *fin, FILE *fout, int match)
 	  continue;
 	}
 
-      putc (c, fout);
+      if (fout)
+	putc (c, fout);
+      if (oout)
+	obstack_1grow (oout, c);
 
       if (c == '\\')
 	{
 	  c = getc (fin);
 	  if (c == EOF)
 	    fatal (_("unterminated string at end of file"));
-	  putc (c, fout);
+	  if (fout)
+	    putc (c, fout);
+	  if (oout)
+	    obstack_1grow (oout, c);
+
 	  if (c == '\n')
 	    lineno++;
 	}
@@ -191,7 +203,10 @@ copy_string (FILE *fin, FILE *fout, int match)
       c = getc (fin);
     }
 
-  putc (c, fout);
+  if (fout)
+    putc (c, fout);
+  if (oout)
+    obstack_1grow (oout, c);
 }
 
 
@@ -204,16 +219,19 @@ copy_string (FILE *fin, FILE *fout, int match)
 `----------------------------------------------------------------*/
 
 static inline void
-copy_comment2 (FILE *fin, FILE *out1, FILE *out2)
+copy_comment2 (FILE *fin, FILE *out1, FILE *out2, struct obstack *oout)
 {
   int cplus_comment;
   int ended;
   int c;
 
   /* We read a `/', output it. */
-  putc ('/', out1);
+  if (out1)
+    putc ('/', out1);
   if (out2)
     putc ('/', out2);
+  if (oout)
+    obstack_1grow (oout, '/');
 
   switch ((c = getc (fin)))
     {
@@ -228,9 +246,12 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2)
       return;
     }
 
-  putc (c, out1);
+  if (out1)
+    putc (c, out1);
   if (out2)
     putc (c, out2);
+  if (oout)
+    obstack_1grow (oout, c);
   c = getc (fin);
 
   ended = 0;
@@ -240,26 +261,35 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2)
 	{
 	  while (c == '*')
 	    {
-	      putc (c, out1);
+	      if (out1)
+		putc (c, out1);
 	      if (out2)
 		putc (c, out2);
+	      if (oout)
+		obstack_1grow (oout, c);
 	      c = getc (fin);
 	    }
 
 	  if (c == '/')
 	    {
-	      putc (c, out1);
+	      if (out1)
+		putc (c, out1);
 	      if (out2)
 		putc (c, out2);
+	      if (oout)
+		obstack_1grow (oout, c);
 	      ended = 1;
 	    }
 	}
       else if (c == '\n')
 	{
 	  lineno++;
-	  putc (c, out1);
+	  if (out1)
+	    putc (c, out1);
 	  if (out2)
 	    putc (c, out2);
+	  if (oout)
+	    obstack_1grow (oout, c);
 	  if (cplus_comment)
 	    ended = 1;
 	  else
@@ -269,9 +299,12 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2)
 	fatal (_("unterminated comment"));
       else
 	{
-	  putc (c, out1);
+	  if (out1)
+	    putc (c, out1);
 	  if (out2)
 	    putc (c, out2);
+	  if (oout)
+	    obstack_1grow (oout, c);
 	  c = getc (fin);
 	}
     }
@@ -284,9 +317,9 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2)
 `-------------------------------------------------------------------*/
 
 static inline void
-copy_comment (FILE *fin, FILE *fout)
+copy_comment (FILE *fin, FILE *fout, struct obstack *oout)
 {
-  copy_comment2 (fin, fout, NULL);
+  copy_comment2 (fin, fout, NULL, oout);
 }
 
 
@@ -298,24 +331,32 @@ copy_comment (FILE *fin, FILE *fout)
 `-----------------------------------------------------------------*/
 
 static inline void
-copy_at (FILE *fin, FILE *fout, int stack_offset)
+copy_at (FILE *fin, FILE *fout, struct obstack *oout, int stack_offset)
 {
   int c;
 
   c = getc (fin);
   if (c == '$')
     {
-      fprintf (fout, "yyloc");
+      if (fout)
+	fprintf (fout, "yyloc");
+      if (oout)
+	obstack_grow_literal_string (oout, "yylloc");
       locations_flag = 1;
     }
   else if (isdigit (c) || c == '-')
     {
       int n;
+      char buf[4096];
 
       ungetc (c, fin);
       n = read_signed_integer (fin);
 
-      fprintf (fout, "yylsp[%d]", n - stack_offset);
+      sprintf (buf, "yylsp[%d]", n - stack_offset);
+      if (fout)
+	fputs (buf, fout);
+      if (oout)
+	obstack_grow (oout, buf, strlen (buf));
       locations_flag = 1;
     }
   else
@@ -338,7 +379,7 @@ copy_at (FILE *fin, FILE *fout, int stack_offset)
 `-------------------------------------------------------------------*/
 
 static inline void
-copy_dollar (FILE *fin, FILE *fout,
+copy_dollar (FILE *fin, FILE *fout, struct obstack *oout,
 	     symbol_list *rule, int stack_offset)
 {
   int c = getc (fin);
@@ -355,11 +396,20 @@ copy_dollar (FILE *fin, FILE *fout,
 
   if (c == '$')
     {
-      fprintf (fout, "yyval");
+      if (fout)
+	fputs ("yyval", fout);
+      if (oout)
+	obstack_grow_literal_string (oout, "yyval");
+
       if (!type_name)
 	type_name = get_type_name (0, rule);
       if (type_name)
-	fprintf (fout, ".%s", type_name);
+	{
+	  if (fout)
+	    fprintf (fout, ".%s", type_name);
+	  if (oout)
+	    obstack_fgrow1 (oout, ".%s", type_name);
+	}
       if (!type_name && typed)
 	complain (_("$$ of `%s' has no declared type"),
 		  rule->sym->tag);
@@ -373,9 +423,18 @@ copy_dollar (FILE *fin, FILE *fout,
       if (!type_name && n > 0)
 	type_name = get_type_name (n, rule);
 
-      fprintf (fout, "yyvsp[%d]", n - stack_offset);
+      if (fout)
+	fprintf (fout, "yyvsp[%d]", n - stack_offset);
+      if (oout)
+	obstack_fgrow1 (oout, "yyvsp[%d]", n - stack_offset);
+
       if (type_name)
-	fprintf (fout, ".%s", type_name);
+	{
+	  if (fout)
+	    fprintf (fout, ".%s", type_name);
+	  if (oout)
+	    obstack_fgrow1 (oout, ".%s", type_name);
+	}
       if (!type_name && typed)
 	complain (_("$%d of `%s' has no declared type"),
 		  n, rule->sym->tag);
@@ -422,11 +481,11 @@ copy_definition (void)
 
 	case '\'':
 	case '"':
-	  copy_string (finput, fattrs, c);
+	  copy_string (finput, fattrs, 0, c);
 	  break;
 
 	case '/':
-	  copy_comment (finput, fattrs);
+	  copy_comment (finput, fattrs, 0);
 	  break;
 
 	case EOF:
@@ -744,7 +803,7 @@ parse_union_decl (void)
 	  break;
 
 	case '/':
-	  copy_comment2 (finput, fattrs, fdefines);
+	  copy_comment2 (finput, fattrs, fdefines, 0);
 	  break;
 
 	case '{':
@@ -984,15 +1043,21 @@ copy_action (symbol_list *rule, int stack_offset)
 {
   int c;
   int count;
+  char buf[4096];
 
   /* offset is always 0 if parser has already popped the stack pointer */
   if (semantic_parser)
     stack_offset = 0;
 
-  fprintf (faction, "\ncase %d:\n", nrules);
+  sprintf (buf, "\ncase %d:\n", nrules);
+  obstack_grow (&action_obstack, buf, strlen (buf));
+
   if (!no_lines_flag)
-    fprintf (faction, "#line %d \"%s\"\n", lineno, infile);
-  putc ('{', faction);
+    {
+      sprintf (buf, "#line %d \"%s\"\n", lineno, infile);
+      obstack_grow (&action_obstack, buf, strlen (buf));
+    }
+  obstack_1grow (&action_obstack, '{');
 
   count = 1;
   c = getc (finput);
@@ -1004,37 +1069,39 @@ copy_action (symbol_list *rule, int stack_offset)
 	  switch (c)
 	    {
 	    case '\n':
-	      putc (c, faction);
+	      obstack_1grow (&action_obstack, c);
 	      lineno++;
 	      break;
 
 	    case '{':
-	      putc (c, faction);
+	      obstack_1grow (&action_obstack, c);
 	      count++;
 	      break;
 
 	    case '\'':
 	    case '"':
-	      copy_string (finput, faction, c);
+	      copy_string (finput, 0, &action_obstack, c);
 	      break;
 
 	    case '/':
-	      copy_comment (finput, faction);
+	      copy_comment (finput, 0, &action_obstack);
 	      break;
 
 	    case '$':
-	      copy_dollar (finput, faction, rule, stack_offset);
+	      copy_dollar (finput, 0, &action_obstack,
+			   rule, stack_offset);
 	      break;
 
 	    case '@':
-	      copy_at (finput, faction, stack_offset);
+	      copy_at (finput, 0, &action_obstack,
+		       stack_offset);
 	      break;
 
 	    case EOF:
 	      fatal (_("unmatched %s"), "`{'");
 
 	    default:
-	      putc (c, faction);
+	      obstack_1grow (&action_obstack, c);
 	    }
 
 	  c = getc (finput);
@@ -1044,12 +1111,13 @@ copy_action (symbol_list *rule, int stack_offset)
 
       if (--count)
 	{
-	  putc (c, faction);
+	  obstack_1grow (&action_obstack, c);
 	  c = getc (finput);
 	}
     }
 
-  fprintf (faction, ";\n    break;}");
+  obstack_grow_literal_string (&action_obstack,
+			       ";\n    break;}");
 }
 
 /*-------------------------------------------------------------------.
@@ -1108,19 +1176,19 @@ copy_guard (symbol_list *rule, int stack_offset)
 
 	case '\'':
 	case '"':
-	  copy_string (finput, fguard, c);
+	  copy_string (finput, fguard, 0, c);
 	  break;
 
 	case '/':
-	  copy_comment (finput, fguard);
+	  copy_comment (finput, fguard, 0);
 	  break;
 
 	case '$':
-	  copy_dollar (finput, fguard, rule, stack_offset);
+	  copy_dollar (finput, fguard, 0, rule, stack_offset);
 	  break;
 
 	case '@':
-	  copy_at (finput, fguard, stack_offset);
+	  copy_at (finput, fguard, 0, stack_offset);
 	  break;
 
 	case EOF:
@@ -1823,9 +1891,9 @@ packgram (void)
 /*-------------------------------------------------------------------.
 | Read in the grammar specification and record it in the format      |
 | described in gram.h.  All guards are copied into the FGUARD file   |
-| and all actions into FACTION, in each case forming the body of a C |
-| function (YYGUARD or YYACTION) which contains a switch statement   |
-| to decide which guard or action to execute.                        |
+| and all actions into ACTION_OBSTACK, in each case forming the body |
+| of a C function (YYGUARD or YYACTION) which contains a switch      |
+| statement to decide which guard or action to execute.              |
 `-------------------------------------------------------------------*/
 
 void
