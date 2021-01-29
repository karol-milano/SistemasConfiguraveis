@@ -1992,6 +1992,11 @@ reader (void)
 }
 
 
+/*------------------------------------------------------------------.
+| Define YYLTYPE.  Cannot be in the skeleton since we might have to |
+| output it in the headers if --defines is used.                    |
+`------------------------------------------------------------------*/
+
 void
 reader_output_yylsp (struct obstack *oout)
 {
@@ -2001,13 +2006,11 @@ reader_output_yylsp (struct obstack *oout)
 #ifndef YYLTYPE\n\
 typedef struct yyltype\n\
 {\n\
-  int timestamp;\n\
   int first_line;\n\
-  int first_column;\
+  int first_column;\n\
 \n\
   int last_line;\n\
   int last_column;\n\
-  char *text;\n\
 } yyltype;\n\
 \n\
 # define YYLTYPE yyltype\n\
