@@ -35,6 +35,7 @@
 #include "lex.h"
 #include "gram.h"
 #include "complain.h"
+#include "output.h"
 
 #define	LTYPESTR	"\
 \n\
@@ -70,8 +71,6 @@ extern int maxtoken;
 extern void init_lex PARAMS((void));
 extern char *grow_token_buffer PARAMS((char *));
 extern void tabinit PARAMS((void));
-extern void output_headers PARAMS((void));
-extern void output_trailers PARAMS((void));
 extern void free_symtab PARAMS((void));
 extern void open_extra_files PARAMS((void));
 extern char *printable_version PARAMS((int));
@@ -234,8 +233,11 @@ copy_string (FILE *fin, FILE *fout, int match)
 }
 
 
-/* Dump the comment from IN to OUT1 and OUT2.  C is either `*' or `/',
-   depending upon the type of comments used.  OUT2 might be NULL.  */
+/*---------------------------------------------------------------.
+| Dump the comment from IN to OUT1 and OUT2.  C is either `*' or |
+| `/', depending upon the type of comments used.  OUT2 might be  |
+| NULL.                                                          |
+`---------------------------------------------------------------*/
 
 static inline void
 copy_comment2 (FILE *in, FILE *out1, FILE* out2, int c)
