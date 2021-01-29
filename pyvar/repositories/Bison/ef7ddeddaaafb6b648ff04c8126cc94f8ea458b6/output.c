@@ -1161,53 +1161,57 @@ static void
 output_parser (void)
 {
   int c;
-  static int number_of_dollar_signs = 0;
   FILE *fskel;
+  size_t line;
+  const char *skeleton = NULL;
+  int number_of_dollar_signs = 0;
 
   if (pure_parser)
     obstack_grow_literal_string (&table_obstack, "#define YYPURE 1\n\n");
 
   /* Loop over lines in the standard parser file.  */
   if (semantic_parser)
-    fskel = xfopen (skeleton_find ("BISON_HAIRY", BISON_HAIRY), "r");
+    skeleton = skeleton_find ("BISON_HAIRY", BISON_HAIRY);
   else
-    fskel = xfopen (skeleton_find ("BISON_SIMPLE", BISON_SIMPLE), "r");
+    skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
+  fskel = xfopen (skeleton, "r");
+
+  /* Set LINE to 2, not 1: `#line LINENUM' -- Here LINENUM is a
+     decimal integer constant.  This specifies that the line number of
+     the *following* line of input, in its original source file, was
+     LINENUM.  */
+  line = 2;
 
   while (1)
     {
+      int is_sync_line = 0;
       int write_line = 1;
 
       c = getc (fskel);
 
-      /* See if the line starts with `#line.
-         If so, set write_line to 0.  */
-      if (no_lines_flag)
-	if (c == '#')
-	  {
-	    c = getc (fskel);
-	    if (c == 'l')
-	      {
-		c = getc (fskel);
-		if (c == 'i')
-		  {
-		    c = getc (fskel);
-		    if (c == 'n')
-		      {
-			c = getc (fskel);
-			if (c == 'e')
-			  write_line = 0;
-			else
-			  obstack_grow_literal_string (&table_obstack, "#lin");
-		      }
-		    else
-		      obstack_grow_literal_string (&table_obstack, "#li");
-		  }
-		else
-		  obstack_grow_literal_string (&table_obstack, "#l");
-	      }
+      /* See if the line starts with `#line'. */
+      if (c == '#')
+	if ((c = getc (fskel)) == 'l')
+	  if ((c = getc (fskel)) == 'i')
+	    if ((c = getc (fskel)) == 'n')
+	      if ((c = getc (fskel)) == 'e')
+		is_sync_line = 1;
+	      else
+		obstack_grow_literal_string (&table_obstack, "#lin");
 	    else
-	      obstack_grow_literal_string (&table_obstack, "#");
-	  }
+	      obstack_grow_literal_string (&table_obstack, "#li");
+	  else
+	    obstack_grow_literal_string (&table_obstack, "#l");
+	else
+	  obstack_grow_literal_string (&table_obstack, "#");
+
+      /* If was a `#line' line, either compute it, or drop it. */
+      if (is_sync_line && !no_lines_flag)
+	obstack_fgrow2 (&table_obstack, "#line %d %s\n",
+			line, quotearg_style (c_quoting_style, skeleton));
+
+      if (is_sync_line)
+	write_line = 0;
 
       /* now write out the line... */
       for (; c != '\n' && c != EOF; c = getc (fskel))
@@ -1234,6 +1238,7 @@ output_parser (void)
       if (c == EOF)
 	break;
       obstack_1grow (&table_obstack, c);
+      line++;
     }
   assert (number_of_dollar_signs == 1);
   xfclose (fskel);
