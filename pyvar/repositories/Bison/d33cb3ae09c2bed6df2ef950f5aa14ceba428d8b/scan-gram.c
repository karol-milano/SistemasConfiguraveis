@@ -27,7 +27,7 @@
 #define YY_FLEX_MINOR_VERSION 5
 
 #include <stdio.h>
-#include <errno.h>
+
 
 /* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
 #ifdef c_plusplus
@@ -40,15 +40,7 @@
 #ifdef __cplusplus
 
 #include <stdlib.h>
-#ifndef _WIN32
 #include <unistd.h>
-#else
-#ifndef YY_ALWAYS_INTERACTIVE
-#ifndef YY_NEVER_INTERACTIVE
-extern int isatty YY_PROTO(( int ));
-#endif
-#endif
-#endif
 
 /* Use prototypes in function declarations. */
 #define YY_USE_PROTOS
@@ -837,10 +829,10 @@ static int percent_percent_count = 0;
    Outside of well-formed rules, RULE_LENGTH has an undefined value.  */
 static int rule_length;
 
-static void handle_dollar PARAMS ((braced_code_t code_kind,
-				   char *cp, location_t location));
-static void handle_at PARAMS ((braced_code_t code_kind,
-			       char *cp, location_t location));
+static void handle_dollar (braced_code_t code_kind,
+			   char *cp, location_t location);
+static void handle_at (braced_code_t code_kind,
+		       char *cp, location_t location);
 
 #define SC_COMMENT 1
 
@@ -854,7 +846,7 @@ static void handle_at PARAMS ((braced_code_t code_kind,
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 858 "scan-gram.c"
+#line 850 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -954,20 +946,9 @@ YY_MALLOC_DECL
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
@@ -1028,7 +1009,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1032 "scan-gram.c"
+#line 1013 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -1908,7 +1889,7 @@ YY_RULE_SETUP
 #line 533 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1912 "scan-gram.c"
+#line 1893 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2472,15 +2453,11 @@ YY_BUFFER_STATE b;
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
