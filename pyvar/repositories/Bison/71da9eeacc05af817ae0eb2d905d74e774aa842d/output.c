@@ -1166,6 +1166,7 @@ static void
 output_parser (void)
 {
   int c;
+  static int number_of_dollar_signs = 0;
 #ifdef DONTDEF
   FILE *fpars;
 #else
@@ -1175,8 +1176,9 @@ output_parser (void)
   if (pure_parser)
     fprintf (ftable, "#define YYPURE 1\n\n");
 
-#ifdef DONTDEF			/* JF no longer needed 'cuz open_extra_files changes the
-				   currently open parser from bison.simple to bison.hairy */
+#ifdef DONTDEF
+  /* JF no longer needed 'cuz open_extra_files changes the currently
+     open parser from bison.simple to bison.hairy */
   if (semantic_parser)
     fpars = fparser;
   else
@@ -1227,11 +1229,15 @@ output_parser (void)
 	  {
 	    if (c == '$')
 	      {
+		number_of_dollar_signs++;
+		assert (number_of_dollar_signs == 1);
 		/* `$' in the parser file indicates where to put the actions.
 		   Copy them in at this point.  */
 		rewind (faction);
 		for (c = getc (faction); c != EOF; c = getc (faction))
 		  putc (c, ftable);
+		/* Skip the end of the line containing `$'. */
+		write_line = 0;
 	      }
 	    else
 	      putc (c, ftable);
@@ -1240,6 +1246,7 @@ output_parser (void)
 	break;
       putc (c, ftable);
     }
+  assert (number_of_dollar_signs == 1);
 }
 
 static void
@@ -1294,7 +1301,7 @@ output (void)
   if (debugflag)
     fputs ("\
 #ifndef YYDEBUG\n\
-#define YYDEBUG 1\n\
+# define YYDEBUG 1\n\
 #endif\n\
 \n",
 	   ftable);
