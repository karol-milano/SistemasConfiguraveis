@@ -15,7 +15,7 @@
 #define yyrestart gram_restart
 #define yytext gram_text
 
-#line 19 "scan-gram.c"
+#line 19 "lex.yy.c"
 /* A lexical scanner generated by flex */
 
 /* Scanner skeleton version:
@@ -27,7 +27,7 @@
 #define YY_FLEX_MINOR_VERSION 5
 
 #include <stdio.h>
-
+#include <errno.h>
 
 /* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
 #ifdef c_plusplus
@@ -40,7 +40,9 @@
 #ifdef __cplusplus
 
 #include <stdlib.h>
+#ifndef _WIN32
 #include <unistd.h>
+#endif
 
 /* Use prototypes in function declarations. */
 #define YY_USE_PROTOS
@@ -823,7 +825,7 @@ static void handle_at PARAMS ((braced_code_t code_kind,
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 827 "scan-gram.c"
+#line 829 "lex.yy.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -923,9 +925,20 @@ YY_MALLOC_DECL
 			YY_FATAL_ERROR( "input in flex scanner failed" ); \
 		result = n; \
 		} \
-	else if ( ((result = fread( buf, 1, max_size, yyin )) == 0) \
-		  && ferror( yyin ) ) \
-		YY_FATAL_ERROR( "input in flex scanner failed" );
+	else \
+		{ \
+		errno=0; \
+		while ( (result = fread(buf, 1, max_size, yyin))==0 && ferror(yyin)) \
+			{ \
+			if( errno != EINTR) \
+				{ \
+				YY_FATAL_ERROR( "input in flex scanner failed" ); \
+				break; \
+				} \
+			errno=0; \
+			clearerr(yyin); \
+			} \
+		}
 #endif
 
 /* No semi-colon after return; correct usage is to write "yyterminate();" -
@@ -997,7 +1010,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1001 "scan-gram.c"
+#line 1014 "lex.yy.c"
 
 	if ( yy_init )
 		{
@@ -1291,7 +1304,7 @@ case 39:
 YY_RULE_SETUP
 #line 162 "scan-gram.l"
 {
-    yylval->symbol = getsym (yytext, *yylloc);
+    yylval->symbol = symbol_get (yytext, *yylloc);
     return ID;
   }
 	YY_BREAK
@@ -1482,7 +1495,7 @@ YY_RULE_SETUP
     assert (yy_top_state () == INITIAL);
     {
       YY_OBS_FINISH;
-      yylval->symbol = getsym (last_string, *yylloc);
+      yylval->symbol = symbol_get (last_string, *yylloc);
       symbol_class_set (yylval->symbol, token_sym, *yylloc);
       symbol_user_token_number_set (yylval->symbol, last_string[1], *yylloc);
       YY_OBS_FREE;
@@ -1857,7 +1870,7 @@ YY_RULE_SETUP
 #line 528 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1861 "scan-gram.c"
+#line 1874 "lex.yy.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2421,11 +2434,15 @@ YY_BUFFER_STATE b;
 	}
 
 
+#ifndef _WIN32
+#include <unistd.h>
+#else
 #ifndef YY_ALWAYS_INTERACTIVE
 #ifndef YY_NEVER_INTERACTIVE
 extern int isatty YY_PROTO(( int ));
 #endif
 #endif
+#endif
 
 #ifdef YY_USE_PROTOS
 void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )