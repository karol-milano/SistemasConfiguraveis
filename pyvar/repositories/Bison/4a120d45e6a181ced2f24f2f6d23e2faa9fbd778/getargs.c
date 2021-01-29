@@ -37,8 +37,10 @@ extern int fixed_outfiles;/* for -y */
 extern char *program_name;
 
 extern void warns PARAMS((char *, char *));	/* main.c */
+static void usage PARAMS((FILE *));
+extern void getargs PARAMS((int argc, char *[]));
 
-struct option longopts[] =
+static struct option longopts[] =
 {
   {"debug", 0, &debugflag, 1},
   {"defines", 0, &definesflag, 1},
@@ -61,7 +63,7 @@ struct option longopts[] =
 /*---------------------------.
 | Display the help message.  |
 `---------------------------*/
-void
+static void
 usage (FILE *stream)
 {
   /* Some efforts were made to ease the translators' task, please
