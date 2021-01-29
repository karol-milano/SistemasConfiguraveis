@@ -695,12 +695,10 @@ packgram (void)
 }
 
 
-/*------------------------------------------------------------------.
-| Read in the grammar specification and record it in the format     |
-| described in gram.h.  All actions are copied into ACTION_OBSTACK, |
-| in each case forming the body of a C function (YYACTION) which    |
-| contains a switch statement to decide which action to execute.    |
-`------------------------------------------------------------------*/
+/*--------------------------------------------------------------.
+| Read in the grammar specification and record it in the format |
+| described in gram.h.                                          |
+`--------------------------------------------------------------*/
 
 void
 reader (const char *gram)
