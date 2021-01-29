@@ -205,18 +205,20 @@ copy_string (FILE *finput, FILE *foutput, int match)
 }
 
 
-/* Dump the comment from FINPUT to FOUTPUT.  C is either `*' or `/',
-   depending upon the type of comments used.  */
+/* Dump the comment from IN to OUT1 and OUT2.  C is either `*' or `/',
+   depending upon the type of comments used.  OUT2 might be NULL.  */
 
 static inline void
-copy_comment (FILE *finput, FILE *foutput, int c)
+copy_comment2 (FILE *in, FILE *out1, FILE* out2, int c)
 {
   int cplus_comment;
   register int ended;
 
   cplus_comment = (c == '/');
-  putc (c, foutput);
-  c = getc (finput);
+  putc (c, out1);
+  if (out2)
+    putc (c, out2);
+  c = getc (in);
 
   ended = 0;
   while (!ended)
@@ -225,36 +227,54 @@ copy_comment (FILE *finput, FILE *foutput, int c)
 	{
 	  while (c == '*')
 	    {
-	      putc(c, foutput);
-	      c = getc(finput);
+	      putc (c, out1);
+	      if (out2)
+		putc (c, out2);
+	      c = getc (in);
 	    }
 
 	  if (c == '/')
 	    {
-	      putc(c, foutput);
+	      putc(c, out1);
+	      if (out2)
+		putc(c, out2);
 	      ended = 1;
 	    }
 	}
       else if (c == '\n')
 	{
 	  lineno++;
-	  putc (c, foutput);
+	  putc (c, out1);
+	  if (out2)
+	    putc (c, out2);
 	  if (cplus_comment)
 	    ended = 1;
 	  else
-	    c = getc(finput);
+	    c = getc (in);
 	}
       else if (c == EOF)
 	fatal (_("unterminated comment"));
       else
 	{
-	  putc (c, foutput);
-	  c = getc (finput);
+	  putc (c, out1);
+	  if (out2)
+	    putc (c, out2);
+	  c = getc (in);
 	}
     }
 }
 
 
+/* Dump the comment from FINPUT to FOUTPUT.  C is either `*' or `/',
+   depending upon the type of comments used.  */
+
+static inline void
+copy_comment (FILE *finput, FILE *foutput, int c)
+{
+  copy_comment2 (finput, foutput, NULL, c);
+}
+
+
 void
 reader (void)
 {
@@ -384,7 +404,7 @@ read_declarations (void)
 	      break;
 
 	    case UNION:
-	      parse_union_decl();
+	      parse_union_decl ();
 	      break;
 
 	    case EXPECT:
@@ -671,9 +691,9 @@ void
 parse_start_decl (void)
 {
   if (start_flag)
-    complain ("%s", _("multiple %start declarations"));
-  if (lex() != IDENTIFIER)
-    complain ("%s", _("invalid %start declaration"));
+    complain (_("multiple %s declarations"), "%start");
+  if (lex () != IDENTIFIER)
+    complain (_("invalid %s declaration"), "%start");
   else
     {
       start_flag = 1;
@@ -829,34 +849,29 @@ void
 parse_union_decl (void)
 {
   register int c;
-  register int count;
-  register int in_comment;
-  int cplus_comment;
+  register int count = 0;
 
   if (typed)
-    complain ("%s", _("multiple %union declarations"));
+    complain (_("multiple %s declarations"), "%union");
 
   typed = 1;
 
   if (!nolinesflag)
-    fprintf(fattrs, "\n#line %d \"%s\"\n", lineno, infile);
+    fprintf (fattrs, "\n#line %d \"%s\"\n", lineno, infile);
   else
-    fprintf(fattrs, "\n");
+    fprintf (fattrs, "\n");
 
-  fprintf(fattrs, "typedef union");
+  fprintf (fattrs, "typedef union");
   if (fdefines)
-    fprintf(fdefines, "typedef union");
+    fprintf (fdefines, "typedef union");
 
-  count = 0;
-  in_comment = 0;
-
-  c = getc(finput);
+  c = getc (finput);
 
   while (c != EOF)
     {
-      putc(c, fattrs);
+      putc (c, fattrs);
       if (fdefines)
-	putc(c, fdefines);
+	putc (c, fdefines);
 
       switch (c)
 	{
@@ -865,50 +880,10 @@ parse_union_decl (void)
 	  break;
 
 	case '/':
-	  c = getc(finput);
+	  c = getc (finput);
 	  if (c != '*' && c != '/')
-	    ungetc(c, finput);
-	  else
-	    {
-	      putc(c, fattrs);
-	      if (fdefines)
-		putc(c, fdefines);
-	      cplus_comment = (c == '/');
-	      in_comment = 1;
-	      c = getc(finput);
-	      while (in_comment)
-		{
-		  putc(c, fattrs);
-		  if (fdefines)
-		    putc(c, fdefines);
-
-		  if (c == '\n')
-		    {
-		      lineno++;
-		      if (cplus_comment)
-			{
-			  in_comment = 0;
-			  break;
-			}
-		    }
-		  if (c == EOF)
-		    fatal (_("unterminated comment at end of file"));
-
-		  if (!cplus_comment && c == '*')
-		    {
-		      c = getc(finput);
-		      if (c == '/')
-			{
-			  putc('/', fattrs);
-			  if (fdefines)
-			    putc('/', fdefines);
-			  in_comment = 0;
-			}
-		    }
-		  else
-		    c = getc(finput);
-		}
-	    }
+	    continue;
+	  copy_comment2 (finput, fattrs, fdefines, c);
 	  break;
 
 
@@ -918,21 +893,22 @@ parse_union_decl (void)
 
 	case '}':
 	  if (count == 0)
-	    complain (_("unmatched close-brace (`}')"));
+	    complain (_("unmatched %s"), "`}'");
 	  count--;
 	  if (count <= 0)
 	    {
-	      fprintf(fattrs, " YYSTYPE;\n");
+	      fprintf (fattrs, " YYSTYPE;\n");
 	      if (fdefines)
-		fprintf(fdefines, " YYSTYPE;\n");
+		fprintf (fdefines, " YYSTYPE;\n");
 	      /* JF don't choke on trailing semi */
-	      c=skip_white_space();
-	      if(c!=';') ungetc(c,finput);
+	      c = skip_white_space ();
+	      if (c != ';')
+		ungetc (c,finput);
 	      return;
 	    }
 	}
 
-      c = getc(finput);
+      c = getc (finput);
     }
 }
 
@@ -1080,7 +1056,7 @@ copy_guard (symbol_list *rule, int stack_offset)
 	    count--;
 	  else
 	    {
-	      complain (_("unmatched right brace (`}')"));
+	      complain (_("unmatched %s"), "`}'");
 	      c = getc(finput);	/* skip it */
 	    }
           break;
@@ -1231,8 +1207,8 @@ copy_action (symbol_list *rule, int stack_offset)
 	      break;
 
 	    case '/':
-	      putc(c, faction);
-	      c = getc(finput);
+	      putc (c, faction);
+	      c = getc (finput);
 	      if (c != '*' && c != '/')
 		continue;
 	      copy_comment (finput, faction, c);
@@ -1297,7 +1273,7 @@ copy_action (symbol_list *rule, int stack_offset)
 	      break;
 
 	    case EOF:
-	      fatal (_("unmatched `{'"));
+	      fatal (_("unmatched %s"), "`{'");
 
 	    default:
 	      putc(c, faction);
@@ -1670,7 +1646,7 @@ get_type (void)
 
   if (t != TYPENAME)
     {
-      complain (_("ill-formed %type declaration"));
+      complain (_("invalid %s declaration"), "%type");
       return t;
     }
 
