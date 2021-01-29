@@ -172,6 +172,99 @@ skip_to_char (int target)
 }
 
 
+/* Dump the string from FINPUT to FOUTPUT.  MATCH is the delimiter of
+   the string (either ' or ").  */
+
+static inline void
+copy_string (FILE *finput, FILE *foutput, int match)
+{
+  int c;
+
+  putc (match, foutput);
+  c = getc (finput);
+
+  while (c != match)
+    {
+      if (c == EOF)
+	fatal (_("unterminated string at end of file"));
+      if (c == '\n')
+	{
+	  warn (_("unterminated string"));
+	  ungetc (c, finput);
+	  c = match;		/* invent terminator */
+	  continue;
+	}
+
+      putc(c, foutput);
+
+      if (c == '\\')
+	{
+	  c = getc (finput);
+	  if (c == EOF)
+	    fatal (_("unterminated string at end of file"));
+	  putc (c, foutput);
+	  if (c == '\n')
+	    lineno++;
+	}
+
+      c = getc(finput);
+    }
+
+  putc(c, foutput);
+}
+
+
+/* Dump the comment from FINPUT to FOUTPUT.  C is either `*' or `/',
+   depending upon the type of comments used.  */
+
+static inline void
+copy_comment (FILE *finput, FILE *foutput, int c)
+{
+  int cplus_comment;
+  register int match;
+  register int ended;
+
+  cplus_comment = (c == '/');
+  putc (c, foutput);
+  c = getc (finput);
+
+  ended = 0;
+  while (!ended)
+    {
+      if (!cplus_comment && c == '*')
+	{
+	  while (c == '*')
+	    {
+	      putc(c, foutput);
+	      c = getc(finput);
+	    }
+
+	  if (c == '/')
+	    {
+	      putc(c, foutput);
+	      ended = 1;
+	    }
+	}
+      else if (c == '\n')
+	{
+	  lineno++;
+	  putc (c, foutput);
+	  if (cplus_comment)
+	    ended = 1;
+	  else
+	    c = getc(finput);
+	}
+      else if (c == EOF)
+	fatal (_("unterminated comment"));
+      else
+	{
+	  putc (c, foutput);
+	  c = getc (finput);
+	}
+    }
+}
+
+
 void
 reader (void)
 {
@@ -353,24 +446,22 @@ read_declarations (void)
 }
 
 
-/* copy the contents of a %{ ... %} into the definitions file.
-The %{ has already been read.  Return after reading the %}.  */
+/* Copy the contents of a `%{ ... %}' into the definitions file.  The
+   `%{' has already been read.  Return after reading the `%}'.  */
 
 void
 copy_definition (void)
 {
   register int c;
-  register int match;
-  register int ended;
-  register int after_percent;  /* -1 while reading a character if prev char was % */
-  int cplus_comment;
+  /* -1 while reading a character if prev char was %. */
+  register int after_percent;
 
   if (!nolinesflag)
     fprintf(fattrs, "#line %d \"%s\"\n", lineno, infile);
 
   after_percent = 0;
 
-  c = getc(finput);
+  c = getc (finput);
 
   for (;;)
     {
@@ -387,85 +478,15 @@ copy_definition (void)
 
 	case '\'':
 	case '"':
-	  match = c;
-	  putc(c, fattrs);
-	  c = getc(finput);
-
-	  while (c != match)
-	    {
-	      if (c == EOF)
-		fatal(_("unterminated string at end of file"));
-	      if (c == '\n')
-		{
-		  warn(_("unterminated string"));
-		  ungetc(c, finput);
-		  c = match;
-		  continue;
-		}
-
-	      putc(c, fattrs);
-
-	      if (c == '\\')
-		{
-		  c = getc(finput);
-		  if (c == EOF)
-		    fatal(_("unterminated string at end of file"));
-		  putc(c, fattrs);
-		  if (c == '\n')
-		    lineno++;
-		}
-
-	      c = getc(finput);
-	    }
-
-	  putc(c, fattrs);
+	  copy_string (finput, fattrs, c);
 	  break;
 
 	case '/':
-	  putc(c, fattrs);
-	  c = getc(finput);
+	  putc (c, fattrs);
+	  c = getc (finput);
 	  if (c != '*' && c != '/')
 	    continue;
-
-	  cplus_comment = (c == '/');
-	  putc(c, fattrs);
-	  c = getc(finput);
-
-	  ended = 0;
-	  while (!ended)
-	    {
-	      if (!cplus_comment && c == '*')
-		{
-		  while (c == '*')
-		    {
-		      putc(c, fattrs);
-		      c = getc(finput);
-		    }
-
-		  if (c == '/')
-		    {
-		      putc(c, fattrs);
-		      ended = 1;
-		    }
-		}
-	      else if (c == '\n')
-		{
-		  lineno++;
-		  putc(c, fattrs);
-		  if (cplus_comment)
-		    ended = 1;
-		  else
-		    c = getc(finput);
-		}
-	      else if (c == EOF)
-		fatal(_("unterminated comment in `%{' definition"));
-	      else
-		{
-		  putc(c, fattrs);
-		  c = getc(finput);
-		}
-	    }
-
+	  copy_comment (finput, fattrs, c);
 	  break;
 
 	case EOF:
@@ -989,97 +1010,6 @@ get_type_name (int n, symbol_list *rule)
 }
 
 
-/* Dump the string from FINPUT to FOUTPUT.  MATCH is the delimiter of
-   the string (either ' or ").  */
-
-static inline void
-copy_string (FILE *finput, FILE *foutput, int match)
-{
-  int c;
-
-  putc (match, foutput);
-  c = getc (finput);
-
-  while (c != match)
-    {
-      if (c == EOF)
-	fatal(_("unterminated string at end of file"));
-      if (c == '\n')
-	{
-	  warn (_("unterminated string"));
-	  ungetc (c, finput);
-	  c = match;		/* invent terminator */
-	  continue;
-	}
-
-      putc(c, foutput);
-
-      if (c == '\\')
-	{
-	  c = getc (finput);
-	  if (c == EOF)
-	    fatal (_("unterminated string"));
-	  putc (c, foutput);
-	  if (c == '\n')
-	    lineno++;
-	}
-
-      c = getc(finput);
-    }
-
-  putc(c, foutput);
-}
-
-
-/* Dump the comment from FINPUT to FOUTPUT.  C is either `*' or `/',
-   depending upon the type of comments used.  */
-
-static inline void
-copy_comment (FILE *finput, FILE *foutput, int c)
-{
-  int cplus_comment;
-  register int match;
-  register int ended;
-
-  cplus_comment = (c == '/');
-  putc (c, foutput);
-  c = getc (finput);
-
-  ended = 0;
-  while (!ended)
-    {
-      if (!cplus_comment && c == '*')
-	{
-	  while (c == '*')
-	    {
-	      putc(c, foutput);
-	      c = getc(finput);
-	    }
-
-	  if (c == '/')
-	    {
-	      putc(c, foutput);
-	      ended = 1;
-	    }
-	}
-      else if (c == '\n')
-	{
-	  lineno++;
-	  putc (c, foutput);
-	  if (cplus_comment)
-	    ended = 1;
-	  else
-	    c = getc(finput);
-	}
-      else if (c == EOF)
-	fatal (_("unterminated comment"));
-      else
-	{
-	  putc (c, foutput);
-	  c = getc (finput);
-	}
-    }
-}
 
 /* After `%guard' is seen in the input file, copy the actual guard
    into the guards file.  If the guard is followed by an action, copy
