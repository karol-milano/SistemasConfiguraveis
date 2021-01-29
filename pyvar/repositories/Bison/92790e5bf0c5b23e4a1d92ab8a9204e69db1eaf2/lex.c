@@ -140,24 +140,16 @@ xgetc (FILE *f)
 }
 
 
-/*------------------------------------------------------------------.
-| Read one literal character from finput.  Process \ escapes.       |
-| Append the normalized string version of the char to OUT.  Assign  |
-| the character code to *PCODE. Return 1 unless the character is an |
-| unescaped `term' or \n report error for \n.                       |
-`------------------------------------------------------------------*/
-
-/* FIXME: We could directly work in the obstack, but that would make
-   it more difficult to move to quotearg some day.  So for the time
-   being, I prefer have literalchar behave like quotearg, and change
-   my mind later if I was wrong.  */
+/*-----------------------------------------------------------------.
+| Read one literal character from FINPUT.  Process \-escapes.      |
+| Append the char to OUT and assign it *PCODE. Return 1 unless the |
+| character is an unescaped `term' or \n report error for \n.      |
+`-----------------------------------------------------------------*/
 
 int
 literalchar (struct obstack *out, int *pcode, char term)
 {
   int c;
-  char buf[4096];
-  char *cp;
   int code;
   int wasquote = 0;
 
@@ -249,71 +241,8 @@ literalchar (struct obstack *out, int *pcode, char term)
 	}
     }				/* has \ */
 
-  /* now fill BUF with the canonical name for this character as a
-     literal token.  Do not use what the user typed, so that `\012'
-     and `\n' can be interchangeable.  */
-
-  cp = buf;
-  if (code == term && wasquote)
-    *cp++ = code;
-  else if (code == '\\')
-    {
-      *cp++ = '\\';
-      *cp++ = '\\';
-    }
-  else if (code == '\'')
-    {
-      *cp++ = '\\';
-      *cp++ = '\'';
-    }
-  else if (code == '\"')
-    {
-      *cp++ = '\\';
-      *cp++ = '\"';
-    }
-  else if (code >= 040 && code < 0177)
-    *cp++ = code;
-  else if (code == '\t')
-    {
-      *cp++ = '\\';
-      *cp++ = 't';
-    }
-  else if (code == '\n')
-    {
-      *cp++ = '\\';
-      *cp++ = 'n';
-    }
-  else if (code == '\r')
-    {
-      *cp++ = '\\';
-      *cp++ = 'r';
-    }
-  else if (code == '\v')
-    {
-      *cp++ = '\\';
-      *cp++ = 'v';
-    }
-  else if (code == '\b')
-    {
-      *cp++ = '\\';
-      *cp++ = 'b';
-    }
-  else if (code == '\f')
-    {
-      *cp++ = '\\';
-      *cp++ = 'f';
-    }
-  else
-    {
-      *cp++ = '\\';
-      *cp++ = code / 0100 + '0';
-      *cp++ = ((code / 010) & 07) + '0';
-      *cp++ = (code & 07) + '0';
-    }
-  *cp = '\0';
-
   if (out)
-    obstack_sgrow (out, buf);
+    obstack_1grow (out, code);
   *pcode = code;
   return !wasquote;
 }
