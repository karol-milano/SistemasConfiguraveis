@@ -341,7 +341,7 @@ copy_at (FILE *fin, FILE *fout, struct obstack *oout, int stack_offset)
       if (fout)
 	fprintf (fout, "yyloc");
       if (oout)
-	obstack_grow_literal_string (oout, "yylloc");
+	obstack_grow_literal_string (oout, "yyloc");
       locations_flag = 1;
     }
   else if (isdigit (c) || c == '-')
@@ -460,7 +460,7 @@ copy_definition (void)
   int after_percent;
 
   if (!no_lines_flag)
-    fprintf (fattrs, "#line %d \"%s\"\n", lineno, infile);
+    obstack_fgrow2 (&attrs_obstack, "#line %d \"%s\"\n", lineno, infile);
 
   after_percent = 0;
 
@@ -471,7 +471,7 @@ copy_definition (void)
       switch (c)
 	{
 	case '\n':
-	  putc (c, fattrs);
+	  obstack_1grow (&attrs_obstack, c);
 	  lineno++;
 	  break;
 
@@ -481,18 +481,18 @@ copy_definition (void)
 
 	case '\'':
 	case '"':
-	  copy_string (finput, fattrs, 0, c);
+	  copy_string (finput, 0, &attrs_obstack, c);
 	  break;
 
 	case '/':
-	  copy_comment (finput, fattrs, 0);
+	  copy_comment (finput, 0, &attrs_obstack);
 	  break;
 
 	case EOF:
 	  fatal ("%s", _("unterminated `%{' definition"));
 
 	default:
-	  putc (c, fattrs);
+	  obstack_1grow (&attrs_obstack, c);
 	}
 
       c = getc (finput);
@@ -501,12 +501,10 @@ copy_definition (void)
 	{
 	  if (c == '}')
 	    return;
-	  putc ('%', fattrs);
+	  obstack_1grow (&attrs_obstack, '%');
 	}
       after_percent = 0;
-
     }
-
 }
 
 
@@ -762,11 +760,11 @@ token_buffer);
 
 
 
-/*-------------------------------------------------------------------.
-| Copy the union declaration into fattrs (and fdefines), where it is |
-| made into the definition of YYSTYPE, the type of elements of the   |
-| parser value stack.                                                |
-`-------------------------------------------------------------------*/
+/*--------------------------------------------------------------.
+| Copy the union declaration into ATTRS_OBSTACK (and fdefines), |
+| where it is made into the definition of YYSTYPE, the type of  |
+| elements of the parser value stack.                           |
+`--------------------------------------------------------------*/
 
 static void
 parse_union_decl (void)
@@ -780,11 +778,11 @@ parse_union_decl (void)
   typed = 1;
 
   if (!no_lines_flag)
-    fprintf (fattrs, "\n#line %d \"%s\"\n", lineno, infile);
+    obstack_fgrow2 (&attrs_obstack, "\n#line %d \"%s\"\n", lineno, infile);
   else
-    fprintf (fattrs, "\n");
+    obstack_1grow (&attrs_obstack, '\n');
 
-  fprintf (fattrs, "typedef union");
+  obstack_grow_literal_string (&attrs_obstack, "typedef union");
   if (fdefines)
     fprintf (fdefines, "typedef union");
 
@@ -792,7 +790,7 @@ parse_union_decl (void)
 
   while (c != EOF)
     {
-      putc (c, fattrs);
+      obstack_1grow (&attrs_obstack, c);
       if (fdefines)
 	putc (c, fdefines);
 
@@ -803,7 +801,7 @@ parse_union_decl (void)
 	  break;
 
 	case '/':
-	  copy_comment2 (finput, fattrs, fdefines, 0);
+	  copy_comment2 (finput, 0, fdefines, &attrs_obstack);
 	  break;
 
 	case '{':
@@ -816,7 +814,7 @@ parse_union_decl (void)
 	  count--;
 	  if (count <= 0)
 	    {
-	      fprintf (fattrs, " YYSTYPE;\n");
+	      obstack_grow_literal_string (&attrs_obstack, " YYSTYPE;\n");
 	      if (fdefines)
 		fprintf (fdefines, " YYSTYPE;\n");
 	      /* JF don't choke on trailing semi */
@@ -934,7 +932,7 @@ parse_thong_decl (void)
 /*----------------------------------------------------------------.
 | Read from finput until `%%' is seen.  Discard the `%%'.  Handle |
 | any `%' declarations, and copy the contents of any `%{ ... %}'  |
-| groups to fattrs.                                               |
+| groups to ATTRS_OBSTACK.                                        |
 `----------------------------------------------------------------*/
 
 static void
@@ -1595,7 +1593,8 @@ readgram (void)
       /* We used to use `unsigned long' as YYSTYPE on MSDOS,
          but it seems better to be consistent.
          Most programs should declare their own type anyway.  */
-      fprintf (fattrs, "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
+      obstack_grow_literal_string (&attrs_obstack,
+			    "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
       if (fdefines)
 	fprintf (fdefines, "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
     }
