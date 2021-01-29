@@ -37,10 +37,6 @@ extern int raw_flag;
 extern int yacc_flag;
 extern char * version_string;
 
-/* Allocate storgate and initialize, since bison uses them elsewhere.  */
-char *spec_name_prefix;
-char *spec_file_prefix;
-
 getargs(argc,argv)
      int argc;
      char *argv[];
