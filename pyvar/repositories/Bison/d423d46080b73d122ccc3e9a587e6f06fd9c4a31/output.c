@@ -159,31 +159,30 @@ prepare_symbols (void)
   /* tname -- token names.  */
   {
     int i;
-    int j = 0;
+    /* We assume that the table will be output starting at column 2. */
+    int j = 2;
     for (i = 0; i < nsyms; i++)
       {
-	/* Be sure not to use twice the same QUOTEARG slot:
-	   SYMBOL_TAG_GET uses slot 0.  */
-	const char *cp =
-	  quotearg_n_style (1, c_quoting_style,
-			    symbols[i]->tag);
-	/* Width of the next token, including the two quotes, the comma
-	   and the space.  */
+	const char *cp = quotearg_style (c_quoting_style, symbols[i]->tag);
+	/* Width of the next token, including the two quotes, the
+	   comma and the space.  */
 	int width = strlen (cp) + 2;
 
 	if (j + width > 75)
 	  {
-	    obstack_sgrow (&format_obstack, "\n  ");
-	    j = 2;
+	    obstack_sgrow (&format_obstack, "\n ");
+	    j = 1;
 	  }
 
+	if (i)
+	  obstack_1grow (&format_obstack, ' ');
 	MUSCLE_OBSTACK_SGROW (&format_obstack, cp);
-	obstack_sgrow (&format_obstack, ", ");
+	obstack_1grow (&format_obstack, ',');
 	j += width;
       }
     /* Add a NULL entry to list of tokens (well, 0, as NULL might not be
        defined).  */
-    obstack_sgrow (&format_obstack, "0");
+    obstack_sgrow (&format_obstack, " 0");
 
     /* Finish table and store. */
     obstack_1grow (&format_obstack, 0);
