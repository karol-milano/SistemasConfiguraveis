@@ -18,7 +18,7 @@ along with Bison; see the file COPYING.  If not, write to
 the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
 
-/* 
+/*
    lex is the entry point.  It is called from reader.c.
    It returns one of the token-type codes defined in lex.h.
    When an identifier is seen, the code IDENTIFIER is returned
@@ -107,9 +107,9 @@ skip_white_space()
 	{
 	case '/':
 	  c = getc(finput);
-	  if (c != '*' && c != '/') 
+	  if (c != '*' && c != '/')
 	    {
-	      warn("unexpected `/' found and ignored");
+	      warn(_("unexpected `/' found and ignored"));
 	      break;
 	    }
 	  cplus_comment = (c == '/');
@@ -138,7 +138,7 @@ skip_white_space()
 		  c = getc(finput);
 		}
 	      else if (c == EOF)
-		fatal("unterminated comment");
+		fatal(_("unterminated comment"));
 	      else
 		c = getc(finput);
 	    }
@@ -167,7 +167,7 @@ safegetc(f)
 {
   register int c = getc(f);
   if (c == EOF)
-    fatal("Unexpected end of file");
+    fatal(_("Unexpected end of file"));
   return c;
 }
 
@@ -189,9 +189,9 @@ literalchar(pp, pcode, term)
   int wasquote = 0;
 
   c = safegetc(finput);
-  if (c == '\n') 
+  if (c == '\n')
     {
-      warn("unescaped newline in constant");
+      warn(_("unescaped newline in constant"));
       ungetc(c, finput);
       code = '?';
       wasquote = 1;
@@ -199,7 +199,7 @@ literalchar(pp, pcode, term)
   else if (c != '\\')
     {
       code = c;
-      if (c == term) 
+      if (c == term)
 	wasquote = 1;
     }
   else
@@ -223,7 +223,7 @@ literalchar(pp, pcode, term)
 	      code = (code * 8) + (c - '0');
 	      if (code >= 256 || code < 0)
 		{
-		  warni("octal value outside range 0...255: `\\%o'", code);
+		  warni(_("octal value outside range 0...255: `\\%o'"), code);
 		  code &= 0xFF;
 		  break;
 		}
@@ -243,11 +243,11 @@ literalchar(pp, pcode, term)
 		code *= 16,  code += c - 'a' + 10;
 	      else if (c >= 'A' && c <= 'F')
 		code *= 16,  code += c - 'A' + 10;
-	      else 
+	      else
 		break;
 	      if (code >= 256 || code<0)
 		{
-		  warni("hexadecimal value above 255: `\\x%x'", code);
+		  warni(_("hexadecimal value above 255: `\\x%x'"), code);
 		  code &= 0xFF;
 		  break;
 		}
@@ -257,7 +257,7 @@ literalchar(pp, pcode, term)
 	}
       else
 	{
-	  warni ("unknown escape sequence: `\\' followed by `%s'", 
+	  warni (_("unknown escape sequence: `\\' followed by `%s'"),
 		 printable_version(c));
 	  code = '?';
 	}
@@ -388,7 +388,7 @@ lex()
 	c = getc(finput);
 	if (c != '\'')
 	  {
-	    warn("use \"...\" for multi-character literal tokens");
+	    warn(_("use \"...\" for multi-character literal tokens"));
 	    dp = discard;
 	    while (literalchar(&dp, &discode, '\'')) {}
 	  }
@@ -463,10 +463,10 @@ lex()
       while (c != '>')
 	{
 	  if (c == EOF)
-	    fatal("unterminated type name at end of file");
-	  if (c == '\n') 
+	    fatal(_("unterminated type name at end of file"));
+	  if (c == '\n')
 	    {
-	      warn("unterminated type name");
+	      warn(_("unterminated type name"));
 	      ungetc(c, finput);
 	      break;
 	    }
@@ -479,7 +479,7 @@ lex()
 	}
       *p = 0;
       return (TYPENAME);
-	    
+
 
     case '%':
       return (parse_percent_token());
@@ -489,13 +489,13 @@ lex()
     }
 }
 
-/* the following table dictates the action taken for the various 
+/* the following table dictates the action taken for the various
 	% directives.  A setflag value causes the named flag to be
 	set.  A retval action returns the code.
 */
 struct percent_table_struct {
 	char *name;
-	void *setflag; 
+	void *setflag;
 	int retval;
 } percent_table[] =
 {
@@ -583,7 +583,7 @@ parse_percent_token ()
     case '=':
       return (PREC);
     }
-  if (!isalpha(c)) 
+  if (!isalpha(c))
     return (ILLEGAL);
 
   p = token_buffer;
