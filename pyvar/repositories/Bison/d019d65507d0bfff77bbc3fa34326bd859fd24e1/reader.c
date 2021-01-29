@@ -118,7 +118,7 @@ static int get_type PARAMS((void));
 
 int lineno;
 char **tags;
-int *user_toknums;
+short *user_toknums;
 static symbol_list *grammar;
 static int start_flag;
 static bucket *startval;
@@ -296,8 +296,10 @@ copy_comment2 (FILE *in, FILE *out1, FILE* out2, int c)
 }
 
 
-/* Dump the comment from FIN to FOUT.  C is either `*' or `/',
-   depending upon the type of comments used.  */
+/*------------------------------------------------------------.
+| Dump the comment from FIN to FOUT.  C is either `*' or `/', |
+| depending upon the type of comments used.                   |
+`------------------------------------------------------------*/
 
 static inline void
 copy_comment (FILE *fin, FILE *fout, int c)
@@ -1737,7 +1739,7 @@ packsymbols (void)
 
   tags = NEW2(nsyms + 1, char *);
   tags[0] = DOLLAR;
-  user_toknums = NEW2(nsyms + 1, int);
+  user_toknums = NEW2(nsyms + 1, short);
   user_toknums[0] = 0;
 
   sprec = NEW2(nsyms, short);
