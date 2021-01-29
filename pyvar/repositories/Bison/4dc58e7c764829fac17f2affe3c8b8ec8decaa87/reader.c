@@ -992,7 +992,7 @@ get_type_name (int n, symbol_list *rule)
 /* Dump the string from FINPUT to FOUTPUT.  MATCH is the delimiter of
    the string (either ' or ").  */
 
-void
+static inline void
 copy_string (FILE *finput, FILE *foutput, int match)
 {
   int c;
@@ -1034,7 +1034,7 @@ copy_string (FILE *finput, FILE *foutput, int match)
 /* Dump the comment from FINPUT to FOUTPUT.  C is either `*' or `/',
    depending upon the type of comments used.  */
 
-void
+static inline void
 copy_comment (FILE *finput, FILE *foutput, int c)
 {
   int cplus_comment;
