@@ -110,6 +110,7 @@ YYNTBASE = ntokens.
 #include "files.h"
 #include "gram.h"
 #include "state.h"
+#include "complain.h"
 
 
 extern int debugflag;
@@ -133,7 +134,6 @@ extern char *consistent;
 extern short *goto_map;
 extern short *from_state;
 extern short *to_state;
-extern int lineno;
 
 void output_headers PARAMS((void));
 void output_trailers PARAMS((void));
@@ -164,8 +164,6 @@ int matching_state PARAMS((int));
 int pack_vector PARAMS((int));
 
 extern void berror PARAMS((char *));
-extern void fatals PARAMS((char *, char *));
-extern char *int_to_string PARAMS((int));
 extern void reader_output_yylsp PARAMS((FILE *));
 
 static int nvectors;
@@ -1198,7 +1196,7 @@ pack_vector (int vector)
 	{
 	  loc = j + from[k];
 	  if (loc > MAXTABLE)
-	    fatals(_("maximum table size (%s) exceeded"), int_to_string(MAXTABLE));
+	    fatal (_("maximum table size (%d) exceeded"), MAXTABLE);
 
 	  if (table[loc] != 0)
 	    ok = 0;
