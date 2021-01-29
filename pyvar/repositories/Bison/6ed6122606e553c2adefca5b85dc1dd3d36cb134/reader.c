@@ -136,8 +136,6 @@ static bucket *undeftoken;
 /* Nonzero if any action or guard uses the @n construct.  */
 static int yylsp_needed;
 
-extern char *version_string;
-
 
 static void
 skip_to_char (int target)
@@ -209,7 +207,7 @@ reader (void)
 		infile);
   else
     fprintf(ftable, "\n/*  A Bison parser, made from %s\n", infile);
-  fprintf(ftable, " by  %s  */\n\n", version_string);
+  fprintf(ftable, "    by %s  */\n\n", VERSION_STRING);
   fprintf(ftable, "#define YYBISON 1  /* Identify Bison output.  */\n\n");
   read_declarations();
   /* start writing the guard and action files, if they are needed.  */
