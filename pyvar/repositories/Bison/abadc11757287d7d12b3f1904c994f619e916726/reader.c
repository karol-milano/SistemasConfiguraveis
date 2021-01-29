@@ -68,17 +68,10 @@ extern int expected_conflicts;
 extern char *token_buffer;
 extern int maxtoken;
 
-extern void init_lex PARAMS((void));
-extern char *grow_token_buffer PARAMS((char *));
 extern void tabinit PARAMS((void));
 extern void free_symtab PARAMS((void));
 extern void open_extra_files PARAMS((void));
 extern char *printable_version PARAMS((int));
-extern void unlex PARAMS((int));
-
-extern int skip_white_space PARAMS((void));
-extern int parse_percent_token PARAMS((void));
-extern int lex PARAMS((void));
 
 typedef
   struct symbol_list
