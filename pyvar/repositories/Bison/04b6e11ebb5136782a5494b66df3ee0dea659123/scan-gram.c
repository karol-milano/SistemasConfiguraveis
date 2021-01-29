@@ -15,7 +15,7 @@
 #define yyrestart gram_restart
 #define yytext gram_text
 
-#line 19 "lex.yy.c"
+#line 19 "scan-gram.c"
 /* A lexical scanner generated by flex */
 
 /* Scanner skeleton version:
@@ -27,7 +27,7 @@
 #define YY_FLEX_MINOR_VERSION 5
 
 #include <stdio.h>
-#include <errno.h>
+
 
 /* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
 #ifdef c_plusplus
@@ -40,9 +40,7 @@
 #ifdef __cplusplus
 
 #include <stdlib.h>
-#ifndef _WIN32
 #include <unistd.h>
-#endif
 
 /* Use prototypes in function declarations. */
 #define YY_USE_PROTOS
@@ -825,7 +823,7 @@ static void handle_at PARAMS ((braced_code_t code_kind,
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 829 "lex.yy.c"
+#line 827 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -925,20 +923,9 @@ YY_MALLOC_DECL
 			YY_FATAL_ERROR( "input in flex scanner failed" ); \
 		result = n; \
 		} \
-	else \
-		{ \
-		errno=0; \
-		while ( (result = fread(buf, 1, max_size, yyin))==0 && ferror(yyin)) \
-			{ \
-			if( errno != EINTR) \
-				{ \
-				YY_FATAL_ERROR( "input in flex scanner failed" ); \
-				break; \
-				} \
-			errno=0; \
-			clearerr(yyin); \
-			} \
-		}
+	else if ( ((result = fread( buf, 1, max_size, yyin )) == 0) \
+		  && ferror( yyin ) ) \
+		YY_FATAL_ERROR( "input in flex scanner failed" );
 #endif
 
 /* No semi-colon after return; correct usage is to write "yyterminate();" -
@@ -1010,7 +997,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1014 "lex.yy.c"
+#line 1001 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -1373,7 +1360,7 @@ YY_RULE_SETUP
 #line 200 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, ": invalid character: `%c'\n", *yytext);
+    fprintf (stderr, _(": invalid character: `%c'\n"), *yytext);
     YY_STEP;
   }
 	YY_BREAK
@@ -1435,7 +1422,7 @@ case YY_STATE_EOF(SC_COMMENT):
 #line 244 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, ": unexpected end of file in a comment\n");
+    fprintf (stderr, _(": unexpected end of file in a comment\n"));
     yy_pop_state ();
   }
 	YY_BREAK
@@ -1472,7 +1459,7 @@ case YY_STATE_EOF(SC_ESCAPED_STRING):
 #line 272 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, ": unexpected end of file in a string\n");
+    fprintf (stderr, _(": unexpected end of file in a string\n"));
     assert (yy_top_state () == INITIAL);
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -1519,7 +1506,7 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 #line 309 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, ": unexpected end of file in a character\n");
+    fprintf (stderr, _(": unexpected end of file in a character\n"));
     assert (yy_top_state () == INITIAL);
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -1541,7 +1528,7 @@ YY_RULE_SETUP
     if (c > 255)
       {
 	LOCATION_PRINT (stderr, *yylloc);
-	fprintf (stderr, ": invalid escape: %s\n", quote (yytext));
+	fprintf (stderr, _(": invalid escape: %s\n"), quote (yytext));
 	YY_STEP;
       }
     else
@@ -1600,7 +1587,7 @@ YY_RULE_SETUP
 #line 351 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, ": unrecognized escape: %s\n", quote (yytext));
+    fprintf (stderr, _(": unrecognized escape: %s\n"), quote (yytext));
     YY_OBS_GROW;
   }
 	YY_BREAK
@@ -1651,7 +1638,7 @@ case YY_STATE_EOF(SC_CHARACTER):
 #line 381 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, ": unexpected end of file in a character\n");
+    fprintf (stderr, _(": unexpected end of file in a character\n"));
     assert (yy_top_state () != INITIAL);
     yy_pop_state ();
   }
@@ -1697,7 +1684,7 @@ case YY_STATE_EOF(SC_STRING):
 #line 410 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, ": unexpected end of file in a string\n");
+    fprintf (stderr, _(": unexpected end of file in a string\n"));
     assert (yy_top_state () != INITIAL);
     yy_pop_state ();
   }
@@ -1795,7 +1782,7 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 #line 471 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, ": unexpected end of file in a braced code\n");
+    fprintf (stderr, _(": unexpected end of file in a braced code\n"));
     yy_pop_state ();
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -1837,7 +1824,7 @@ case YY_STATE_EOF(SC_PROLOGUE):
 #line 500 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
-    fprintf (stderr, ": unexpected end of file in a prologue\n");
+    fprintf (stderr, _(": unexpected end of file in a prologue\n"));
     yy_pop_state ();
     YY_OBS_FINISH;
     yylval->string = last_string;
@@ -1871,7 +1858,7 @@ YY_RULE_SETUP
 #line 529 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1875 "lex.yy.c"
+#line 1862 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2435,15 +2422,11 @@ YY_BUFFER_STATE b;
 	}
 
 
-#ifndef _WIN32
-#include <unistd.h>
-#else
 #ifndef YY_ALWAYS_INTERACTIVE
 #ifndef YY_NEVER_INTERACTIVE
 extern int isatty YY_PROTO(( int ));
 #endif
 #endif
-#endif
 
 #ifdef YY_USE_PROTOS
 void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
@@ -2800,7 +2783,7 @@ handle_action_dollar (char *text, location_t location)
       obstack_fgrow1 (&string_obstack,
 		      "]b4_lhs_value([%s])[", type_name);
     }
-  else if (isdigit (*cp) || *cp == '-')
+  else if (('0' <= *cp && *cp <= '9') || *cp == '-')
     {
       /* RULE_LENGTH is the number of values in the current rule so
 	 far, which says where to find `$0' with respect to the top of
@@ -2887,7 +2870,7 @@ handle_action_at (char *text, location_t location)
     {
       obstack_sgrow (&string_obstack, "]b4_lhs_location[");
     }
-  else if (isdigit (*cp) || *cp == '-')
+  else if (('0' <= *cp && *cp <= '9') || *cp == '-')
     {
       /* RULE_LENGTH is the number of values in the current rule so
 	 far, which says where to find `$0' with respect to the top of