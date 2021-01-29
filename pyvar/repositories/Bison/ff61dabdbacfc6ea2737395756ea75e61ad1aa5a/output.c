@@ -1153,54 +1153,47 @@ output_actions (void)
   output_check ();
 }
 
-/* copy the parser code into the ftable file at the end.  */
+/*------------------------------------------.
+| Copy the parser code into TABLE_OBSTACK.  |
+`------------------------------------------*/
 
 static void
 output_parser (void)
 {
   int c;
   static int number_of_dollar_signs = 0;
-#ifdef DONTDEF
-  FILE *fpars;
-#else
-#define fpars fparser
-#endif
+  FILE *fskel;
 
   if (pure_parser)
     obstack_grow_literal_string (&table_obstack, "#define YYPURE 1\n\n");
 
-#ifdef DONTDEF
-  /* JF no longer needed 'cuz open_extra_files changes the currently
-     open parser from bison.simple to bison.hairy */
+  /* Loop over lines in the standard parser file.  */
   if (semantic_parser)
-    fpars = fparser;
+    fskel = xfopen (skeleton_find ("BISON_HAIRY", BISON_HAIRY), "r");
   else
-    fpars = fparser1;
-#endif
-
-  /* Loop over lines in the standard parser file.  */
+    fskel = xfopen (skeleton_find ("BISON_SIMPLE", BISON_SIMPLE), "r");
 
   while (1)
     {
       int write_line = 1;
 
-      c = getc (fpars);
+      c = getc (fskel);
 
       /* See if the line starts with `#line.
          If so, set write_line to 0.  */
       if (no_lines_flag)
 	if (c == '#')
 	  {
-	    c = getc (fpars);
+	    c = getc (fskel);
 	    if (c == 'l')
 	      {
-		c = getc (fpars);
+		c = getc (fskel);
 		if (c == 'i')
 		  {
-		    c = getc (fpars);
+		    c = getc (fskel);
 		    if (c == 'n')
 		      {
-			c = getc (fpars);
+			c = getc (fskel);
 			if (c == 'e')
 			  write_line = 0;
 			else
@@ -1217,7 +1210,7 @@ output_parser (void)
 	  }
 
       /* now write out the line... */
-      for (; c != '\n' && c != EOF; c = getc (fpars))
+      for (; c != '\n' && c != EOF; c = getc (fskel))
 	if (write_line)
 	  {
 	    /* `$' in the parser file indicates where to put the
@@ -1243,6 +1236,7 @@ output_parser (void)
       obstack_1grow (&table_obstack, c);
     }
   assert (number_of_dollar_signs == 1);
+  xfclose (fskel);
 }
 
 static void
