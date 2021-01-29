@@ -35,6 +35,8 @@ static int failure;
 /* The name this program was run with, for messages.  */
 char *program_name;
 
+extern void berror PARAMS((const char *));
+
 extern char *printable_version PARAMS ((int));
 
 extern void openfiles PARAMS ((void));
