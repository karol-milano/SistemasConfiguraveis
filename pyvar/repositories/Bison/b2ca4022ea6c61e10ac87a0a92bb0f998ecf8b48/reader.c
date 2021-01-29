@@ -29,6 +29,17 @@
 #include "gram.h"
 #include "complain.h"
 #include "output.h"
+#include "reader.h"
+
+extern bucket *symval;
+extern int numval;
+extern int expected_conflicts;
+extern char *token_buffer;
+extern int maxtoken;
+
+extern void tabinit PARAMS ((void));
+extern void free_symtab PARAMS ((void));
+extern char *printable_version PARAMS ((int));
 
 #define	LTYPESTR	"\
 \n\
@@ -55,16 +66,6 @@ typedef\n\
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
 static int rline_allocated;
 
-extern bucket *symval;
-extern int numval;
-extern int expected_conflicts;
-extern char *token_buffer;
-extern int maxtoken;
-
-extern void tabinit PARAMS ((void));
-extern void free_symtab PARAMS ((void));
-extern char *printable_version PARAMS ((int));
-
 typedef struct symbol_list
 {
   struct symbol_list *next;
@@ -73,10 +74,6 @@ typedef struct symbol_list
 }
 symbol_list;
 
-
-extern void reader PARAMS ((void));
-extern void reader_output_yylsp PARAMS ((FILE *));
-
 int lineno;
 char **tags;
 short *user_toknums;
@@ -1667,7 +1664,7 @@ output_token_defines (FILE *file)
 
 /*------------------------------------------------------------------.
 | Assign symbol numbers, and write definition of token names into   |
-| fdefines.  Set up vectors tags and sprec of names and precedences |
+| FDEFINES.  Set up vectors TAGS and SPREC of names and precedences |
 | of symbols.                                                       |
 `------------------------------------------------------------------*/
 
