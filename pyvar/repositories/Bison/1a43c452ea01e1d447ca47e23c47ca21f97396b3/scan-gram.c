@@ -27,7 +27,7 @@
 #define YY_FLEX_MINOR_VERSION 5
 
 #include <stdio.h>
-
+#include <errno.h>
 
 /* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
 #ifdef c_plusplus
@@ -40,7 +40,15 @@
 #ifdef __cplusplus
 
 #include <stdlib.h>
+#ifndef _WIN32
 #include <unistd.h>
+#else
+#ifndef YY_ALWAYS_INTERACTIVE
+#ifndef YY_NEVER_INTERACTIVE
+extern int isatty YY_PROTO(( int ));
+#endif
+#endif
+#endif
 
 /* Use prototypes in function declarations. */
 #define YY_USE_PROTOS
@@ -929,7 +937,7 @@ static int convert_ucn_to_byte (char const *hex_text);
    NUL and newline, as this simplifies our implementation.  */
 /* Zero or more instances of backslash-newline.  Following GCC, allow
    white space between the backslash and the newline.  */
-#line 933 "scan-gram.c"
+#line 941 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -1029,9 +1037,20 @@ YY_MALLOC_DECL
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
@@ -1092,7 +1111,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1096 "scan-gram.c"
+#line 1115 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -2010,7 +2029,7 @@ YY_RULE_SETUP
 #line 672 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 2014 "scan-gram.c"
+#line 2033 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2574,11 +2593,15 @@ YY_BUFFER_STATE b;
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
