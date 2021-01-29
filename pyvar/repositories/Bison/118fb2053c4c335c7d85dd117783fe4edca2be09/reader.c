@@ -26,7 +26,6 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 The entry point is reader().  */
 
 #include <stdio.h>
-#include <ctype.h>
 #include "system.h"
 #include "files.h"
 #include "alloc.h"
@@ -52,46 +51,30 @@ extern bucket *symval;
 extern int numval;
 extern int expected_conflicts;
 extern char *token_buffer;
-
-extern void init_lex();
-extern void tabinit();
-extern void output_headers();
-extern void output_trailers();
-extern void free_symtab();
-extern void open_extra_files();
-extern char *int_to_string();
-extern void fatal();
-extern void fatals();
-extern void warn();
-extern void warni();
-extern void warns();
-extern void warnss();
-extern void warnsss();
-extern void unlex();
-extern void done();
-
-extern int skip_white_space();
-extern int parse_percent_token();
-extern int lex();
-
-void reader_output_yylsp();
-void read_declarations();
-void copy_definition();
-void parse_token_decl();
-void parse_start_decl();
-void parse_type_decl();
-void parse_assoc_decl();
-void parse_union_decl();
-void parse_expect_decl();
-void parse_thong_decl();
-void copy_action();
-void readgram();
-void record_rule_line();
-void packsymbols();
-void output_token_defines();
-void packgram();
-int read_signed_integer();
-static int get_type();
+extern int maxtoken;
+
+extern void init_lex PARAMS((void));
+extern char *grow_token_buffer PARAMS((char *));
+extern void tabinit PARAMS((void));
+extern void output_headers PARAMS((void));
+extern void output_trailers PARAMS((void));
+extern void free_symtab PARAMS((void));
+extern void open_extra_files PARAMS((void));
+extern char *int_to_string PARAMS((int));
+extern char *printable_version PARAMS((int));
+extern void fatal PARAMS((char *));
+extern void fatals PARAMS((char *, char *));
+extern void warn PARAMS((char *));
+extern void warni PARAMS((char *, int));
+extern void warns PARAMS((char *, char *));
+extern void warnss PARAMS((char *, char *, char *));
+extern void warnsss PARAMS((char *, char *, char *, char *));
+extern void unlex PARAMS((int));
+extern void done PARAMS((int));
+
+extern int skip_white_space PARAMS((void));
+extern int parse_percent_token PARAMS((void));
+extern int lex PARAMS((void));
 
 typedef
   struct symbol_list
@@ -103,6 +86,29 @@ typedef
   symbol_list;
 
 
+void reader PARAMS((void));
+void reader_output_yylsp PARAMS((FILE *));
+void read_declarations PARAMS((void));
+void copy_definition PARAMS((void));
+void parse_token_decl PARAMS((int, int));
+void parse_start_decl PARAMS((void));
+void parse_type_decl PARAMS((void));
+void parse_assoc_decl PARAMS((int));
+void parse_union_decl PARAMS((void));
+void parse_expect_decl PARAMS((void));
+char *get_type_name PARAMS((int, symbol_list *));
+void copy_guard PARAMS((symbol_list *, int));
+void parse_thong_decl PARAMS((void));
+void copy_action PARAMS((symbol_list *, int));
+bucket *gensym PARAMS((void));
+void readgram PARAMS((void));
+void record_rule_line PARAMS((void));
+void packsymbols PARAMS((void));
+void output_token_defines PARAMS((FILE *));
+void packgram PARAMS((void));
+int read_signed_integer PARAMS((FILE *));
+static int get_type PARAMS((void));
+
 
 int lineno;
 symbol_list *grammar;
@@ -131,8 +137,7 @@ extern char *version_string;
 
 
 static void
-skip_to_char(target)
-     int target;
+skip_to_char (int target)
 {
   int c;
   if (target == '\n')
@@ -149,7 +154,7 @@ skip_to_char(target)
 
 
 void
-reader()
+reader (void)
 {
   start_flag = 0;
   startval = NULL;  /* start symbol not specified yet. */
@@ -227,8 +232,7 @@ reader()
 }
 
 void
-reader_output_yylsp(f)
-     FILE *f;
+reader_output_yylsp (FILE *f)
 {
   if (yylsp_needed)
     fprintf(f, LTYPESTR);
@@ -239,7 +243,7 @@ Handle any % declarations,
 and copy the contents of any %{ ... %} groups to fattrs.  */
 
 void
-read_declarations ()
+read_declarations (void)
 {
   register int c;
   register int tok;
@@ -336,7 +340,7 @@ read_declarations ()
 The %{ has already been read.  Return after reading the %}.  */
 
 void
-copy_definition ()
+copy_definition (void)
 {
   register int c;
   register int match;
@@ -475,8 +479,7 @@ For %token, what_is is STOKEN and what_is_not is SNTERM.
 For %nterm, the arguments are reversed.  */
 
 void
-parse_token_decl (what_is, what_is_not)
-     int what_is, what_is_not;
+parse_token_decl (int what_is, int what_is_not)
 {
   register int token = 0;
   register char *typename = 0;
@@ -569,7 +572,7 @@ parse_token_decl (what_is, what_is_not)
 */
 
 void
-parse_thong_decl ()
+parse_thong_decl (void)
 {
   register int token;
   register struct bucket *symbol;
@@ -631,7 +634,7 @@ parse_thong_decl ()
 /* parse what comes after %start */
 
 void
-parse_start_decl ()
+parse_start_decl (void)
 {
   if (start_flag)
     warn(_("multiple %start declarations"));
@@ -649,7 +652,7 @@ parse_start_decl ()
 /* read in a %type declaration and record its information for get_type_name to access */
 
 void
-parse_type_decl ()
+parse_type_decl (void)
 {
   register int k;
   register char *name;
@@ -702,8 +705,7 @@ parse_type_decl ()
 /* assoc is either LEFT_ASSOC, RIGHT_ASSOC or NON_ASSOC.  */
 
 void
-parse_assoc_decl (assoc)
-int assoc;
+parse_assoc_decl (int assoc)
 {
   register int k;
   register char *name = NULL;
@@ -783,7 +785,7 @@ int assoc;
    definition of YYSTYPE, the type of elements of the parser value stack.  */
 
 void
-parse_union_decl()
+parse_union_decl (void)
 {
   register int c;
   register int count;
@@ -897,7 +899,7 @@ parse_union_decl()
    shift-reduce conflicts.  */
 
 void
-parse_expect_decl()
+parse_expect_decl (void)
 {
   register int c;
   register int count;
@@ -928,9 +930,7 @@ parse_expect_decl()
 /* Get the data type (alternative in the union) of the value for symbol n in rule rule.  */
 
 char *
-get_type_name(n, rule)
-int n;
-symbol_list *rule;
+get_type_name (int n, symbol_list *rule)
 {
   static char *msg = N_("invalid $ value");
 
@@ -969,9 +969,7 @@ which says where to find $0 with respect to the top of the stack,
 for the simple parser in which the stack is not popped until after the guard is run.  */
 
 void
-copy_guard(rule, stack_offset)
-symbol_list *rule;
-int stack_offset;
+copy_guard (symbol_list *rule, int stack_offset)
 {
   register int c;
   register int n;
@@ -1111,7 +1109,12 @@ int stack_offset;
 	      register char *cp = token_buffer;
 
 	      while ((c = getc(finput)) != '>' && c > 0)
-		*cp++ = c;
+		{
+		  if (cp == token_buffer + maxtoken)
+		    cp = grow_token_buffer(cp);
+
+		  *cp++ = c;
+		}
 	      *cp = 0;
 	      type_name = token_buffer;
 
@@ -1202,9 +1205,7 @@ stack_offset is the number of values in the current rule so far,
 which says where to find $0 with respect to the top of the stack.  */
 
 void
-copy_action(rule, stack_offset)
-symbol_list *rule;
-int stack_offset;
+copy_action (symbol_list *rule, int stack_offset)
 {
   register int c;
   register int n;
@@ -1333,7 +1334,12 @@ int stack_offset;
 		  register char *cp = token_buffer;
 
 		  while ((c = getc(finput)) != '>' && c > 0)
-		    *cp++ = c;
+		    {
+		      if (cp == token_buffer + maxtoken)
+			cp = grow_token_buffer(cp);
+
+		      *cp++ = c;
+		    }
 		  *cp = 0;
 		  type_name = token_buffer;
 		  value_components_used = 1;
@@ -1418,7 +1424,7 @@ int stack_offset;
 whose name cannot conflict with the user's names. */
 
 bucket *
-gensym()
+gensym (void)
 {
   register bucket *sym;
 
@@ -1439,7 +1445,7 @@ All guards and actions are copied out to the appropriate files,
 labelled by the rule number they apply to.  */
 
 void
-readgram()
+readgram (void)
 {
   register int t;
   register bucket *lhs;
@@ -1731,15 +1737,15 @@ readgram()
 
 
 void
-record_rule_line ()
+record_rule_line (void)
 {
   /* Record each rule's source line number in rline table.  */
 
   if (nrules >= rline_allocated)
     {
       rline_allocated = nrules * 2;
-      rline = (short *) xrealloc (rline,
-				 rline_allocated * sizeof (short));
+      rline = (short *) xrealloc ((char *) rline,
+				  rline_allocated * sizeof (short));
     }
   rline[nrules] = lineno;
 }
@@ -1748,7 +1754,7 @@ record_rule_line ()
 /* read in a %type declaration and record its information for get_type_name to access */
 /* this is unused.  it is only called from the #if 0 part of readgram */
 static int
-get_type()
+get_type (void)
 {
   register int k;
   register int t;
@@ -1798,7 +1804,7 @@ get_type()
 Set up vectors tags and sprec of names and precedences of symbols.  */
 
 void
-packsymbols()
+packsymbols (void)
 {
   register bucket *bp;
   register int tokno = 1;
@@ -1945,8 +1951,7 @@ packsymbols()
    The value is the user token number.
 */
 void
-output_token_defines(file)
-FILE *file;
+output_token_defines (FILE *file)
 {
   bucket *bp;
   register char *cp, *symbol;
@@ -1990,7 +1995,7 @@ FILE *file;
 /* convert the rules into the representation using rrhs, rlhs and ritems.  */
 
 void
-packgram()
+packgram (void)
 {
   register int itemno;
   register int ruleno;
@@ -2051,8 +2056,7 @@ packgram()
 /* Read a signed integer from STREAM and return its value.  */
 
 int
-read_signed_integer (stream)
-     FILE *stream;
+read_signed_integer (FILE *stream)
 {
   register int c = getc(stream);
   register int sign = 1;
