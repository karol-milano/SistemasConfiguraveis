@@ -1,22 +1,22 @@
 /* Token-reader for Bison's input parser,
-   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   Bison is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to
+   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.  */
 
 
 /*
@@ -33,6 +33,7 @@ Boston, MA 02111-1307, USA.  */
 #include "symtab.h"
 #include "lex.h"
 #include "alloc.h"
+#include "complain.h"
 
 /* flags set by % directives */
 extern int definesflag;    	/* for -d */
@@ -47,7 +48,6 @@ extern char *spec_name_prefix; 	/* for -p */
 extern char *spec_file_prefix;	/* for -b */
 /*spec_outfile is declared in files.h, for -o */
 
-extern int lineno;
 extern int translations;
 
 void init_lex PARAMS((void));
@@ -61,10 +61,6 @@ int parse_percent_token PARAMS((void));
 
 /* functions from main.c */
 extern char *printable_version PARAMS((int));
-extern void fatal PARAMS((char *));
-extern void warn PARAMS((char *));
-extern void warni PARAMS((char *, int));
-extern void warns PARAMS((char *, char *));
 
 /* Buffer for storing the current token.  */
 char *token_buffer;
@@ -116,7 +112,7 @@ skip_white_space (void)
 	  c = getc(finput);
 	  if (c != '*' && c != '/')
 	    {
-	      warn(_("unexpected `/' found and ignored"));
+	      complain (_("unexpected `/' found and ignored"));
 	      break;
 	    }
 	  cplus_comment = (c == '/');
@@ -145,7 +141,7 @@ skip_white_space (void)
 		  c = getc(finput);
 		}
 	      else if (c == EOF)
-		fatal(_("unterminated comment"));
+		fatal (_("unterminated comment"));
 	      else
 		c = getc(finput);
 	    }
@@ -173,7 +169,7 @@ safegetc (FILE *f)
 {
   register int c = getc(f);
   if (c == EOF)
-    fatal(_("Unexpected end of file"));
+    fatal (_("unexpected end of file"));
   return c;
 }
 
@@ -194,7 +190,7 @@ literalchar (char **pp, int *pcode, char term)
   c = safegetc(finput);
   if (c == '\n')
     {
-      warn(_("unescaped newline in constant"));
+      complain (_("unescaped newline in constant"));
       ungetc(c, finput);
       code = '?';
       wasquote = 1;
@@ -226,7 +222,8 @@ literalchar (char **pp, int *pcode, char term)
 	      code = (code * 8) + (c - '0');
 	      if (code >= 256 || code < 0)
 		{
-		  warni(_("octal value outside range 0...255: `\\%o'"), code);
+		  complain (_("octal value outside range 0...255: `\\%o'"),
+			    code);
 		  code &= 0xFF;
 		  break;
 		}
@@ -250,7 +247,8 @@ literalchar (char **pp, int *pcode, char term)
 		break;
 	      if (code >= 256 || code<0)
 		{
-		  warni(_("hexadecimal value above 255: `\\x%x'"), code);
+		  complain (_("hexadecimal value above 255: `\\x%x'"),
+			    code);
 		  code &= 0xFF;
 		  break;
 		}
@@ -260,8 +258,8 @@ literalchar (char **pp, int *pcode, char term)
 	}
       else
 	{
-	  warns (_("unknown escape sequence: `\\' followed by `%s'"),
-		 printable_version(c));
+	  complain (_("unknown escape sequence: `\\' followed by `%s'"),
+		    printable_version(c));
 	  code = '?';
 	}
     } /* has \ */
@@ -393,7 +391,7 @@ lex (void)
 	c = getc(finput);
 	if (c != '\'')
 	  {
-	    warn(_("use \"...\" for multi-character literal tokens"));
+	    complain (_("use \"...\" for multi-character literal tokens"));
 	    while (1)
 	      {
 		dp = discard;
@@ -472,10 +470,10 @@ lex (void)
       while (c != '>')
 	{
 	  if (c == EOF)
-	    fatal(_("unterminated type name at end of file"));
+	    fatal (_("unterminated type name at end of file"));
 	  if (c == '\n')
 	    {
-	      warn(_("unterminated type name"));
+	      complain (_("unterminated type name"));
 	      ungetc(c, finput);
 	      break;
 	    }
