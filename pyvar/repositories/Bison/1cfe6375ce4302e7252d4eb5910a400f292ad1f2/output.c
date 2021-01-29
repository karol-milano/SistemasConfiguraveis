@@ -1,7 +1,7 @@
 /* Output the generated parsing program for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005, 2006, 2007 Free Software Foundation, Inc.
+   2005, 2006, 2007, 2008 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -156,9 +156,12 @@ prepare_symbols (void)
     int i;
     /* We assume that the table will be output starting at column 2. */
     int j = 2;
+    struct quoting_options *qo = clone_quoting_options (0);
+    set_quoting_style (qo, c_quoting_style);
+    set_quoting_flags (qo, QA_SPLIT_TRIGRAPHS);
     for (i = 0; i < nsyms; i++)
       {
-	char const *cp = quotearg_style (c_quoting_style, symbols[i]->tag);
+	char *cp = quotearg_alloc (symbols[i]->tag, -1, qo);
 	/* Width of the next token, including the two quotes, the
 	   comma and the space.  */
 	int width = strlen (cp) + 2;
@@ -172,9 +175,11 @@ prepare_symbols (void)
 	if (i)
 	  obstack_1grow (&format_obstack, ' ');
 	MUSCLE_OBSTACK_SGROW (&format_obstack, cp);
+        free (cp);
 	obstack_1grow (&format_obstack, ',');
 	j += width;
       }
+    free (qo);
     obstack_sgrow (&format_obstack, " ]b4_null[");
 
     /* Finish table and store. */
