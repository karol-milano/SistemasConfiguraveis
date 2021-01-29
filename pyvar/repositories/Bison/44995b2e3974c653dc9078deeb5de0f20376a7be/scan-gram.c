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
@@ -687,16 +689,16 @@ int yy_flex_debug = 1;
 
 static yyconst short int yy_rule_linenum[92] =
     {   0,
-       88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
-       98,   99,  100,  101,  102,  103,  104,  105,  106,  107,
-      108,  109,  110,  111,  112,  113,  114,  116,  117,  118,
-      119,  121,  122,  123,  129,  132,  135,  138,  139,  142,
-      145,  148,  150,  156,  172,  173,  184,  196,  197,  198,
-      215,  223,  225,  244,  259,  261,  280,  292,  296,  297,
-      298,  299,  300,  301,  302,  303,  304,  319,  325,  326,
-      328,  346,  352,  353,  355,  373,  376,  379,  380,  391,
-      401,  403,  404,  406,  407,  410,  429,  435,  436,  437,
-      457
+      115,  116,  117,  118,  119,  120,  121,  122,  123,  124,
+      125,  126,  127,  128,  129,  130,  131,  132,  133,  134,
+      135,  136,  137,  138,  139,  140,  141,  143,  144,  145,
+      146,  148,  149,  150,  157,  160,  163,  166,  167,  170,
+      173,  176,  178,  184,  200,  201,  212,  224,  225,  226,
+      243,  251,  253,  272,  286,  288,  307,  319,  323,  324,
+      325,  326,  327,  328,  329,  330,  331,  346,  352,  353,
+      355,  373,  379,  380,  382,  400,  403,  406,  407,  418,
+      428,  430,  431,  433,  434,  437,  456,  462,  463,  464,
+      484
 
     } ;
 
@@ -746,15 +748,42 @@ char *yytext;
 #define YY_LINES        LOCATION_LINES (*yylloc, yyleng); lineno += yyleng;
 #define YY_STEP         LOCATION_STEP (*yylloc)
 
-/* Appending to the STRING_OBSTACK. */
-#define YY_INIT         obstack_init (&string_obstack)
-#define YY_GROW         obstack_grow (&string_obstack, yytext, yyleng)
-#define YY_FINISH       obstack_1grow (&string_obstack, '\0'); yylval->string = obstack_finish (&string_obstack);
+
+/* STRING_OBSTACK -- Used to store all the characters that we need to
+   keep (to construct ID, STRINGS etc.).  Use the following macros to
+   use it.
+
+   Use YY_OBS_INIT to initialize a new growing string, YY_OBS_GROW to
+   append what has just been matched, and YY_OBS_FINISH to end the
+   string (it puts the ending 0).  YY_OBS_FINISH also stores this
+   string in LAST_STRING, which can be used, and which is used by
+   YY_OBS_FREE to free the last string.  */
+
+static struct obstack string_obstack;
+char *last_string;
+
+#define YY_OBS_INIT   \
+  obstack_init (&string_obstack)
+
+#define YY_OBS_GROW   \
+  obstack_grow (&string_obstack, yytext, yyleng)
+
+#define YY_OBS_FINISH					\
+  do {							\
+    obstack_1grow (&string_obstack, '\0');		\
+    last_string = obstack_finish (&string_obstack);	\
+    yylval->string = last_string;			\
+  } while (0)
+
+#define YY_OBS_FREE						\
+  do {								\
+    obstack_free (&string_obstack, last_string);		\
+  } while (0)
 
 /* This is only to avoid GCC warnings. */
 #define YY_USER_INIT    if (yycontrol) {;};
 
-static struct obstack string_obstack;
+
 static int braces_level = 0;
 static int percent_percent_count = 0;
 
@@ -773,7 +802,7 @@ static void handle_at PARAMS ((char *cp));
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 777 "scan-gram.c"
+#line 806 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -873,9 +902,20 @@ YY_MALLOC_DECL
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
@@ -924,7 +964,7 @@ YY_DECL
 	register char *yy_cp, *yy_bp;
 	register int yy_act;
 
-#line 64 "scan-gram.l"
+#line 91 "scan-gram.l"
 
 
   /* At each yylex invocation, mark the current position as the
@@ -947,7 +987,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 951 "scan-gram.c"
+#line 991 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -1049,227 +1089,228 @@ do_action:	/* This label is used only to access EOF actions. */
 
 case 1:
 YY_RULE_SETUP
-#line 88 "scan-gram.l"
+#line 115 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 2:
 YY_RULE_SETUP
-#line 89 "scan-gram.l"
+#line 116 "scan-gram.l"
 return PERCENT_DEBUG;
 	YY_BREAK
 case 3:
 YY_RULE_SETUP
-#line 90 "scan-gram.l"
+#line 117 "scan-gram.l"
 return PERCENT_DEFINE;
 	YY_BREAK
 case 4:
 YY_RULE_SETUP
-#line 91 "scan-gram.l"
+#line 118 "scan-gram.l"
 return PERCENT_DEFINES;
 	YY_BREAK
 case 5:
 YY_RULE_SETUP
-#line 92 "scan-gram.l"
+#line 119 "scan-gram.l"
 return PERCENT_ERROR_VERBOSE;
 	YY_BREAK
 case 6:
 YY_RULE_SETUP
-#line 93 "scan-gram.l"
+#line 120 "scan-gram.l"
 return PERCENT_EXPECT;
 	YY_BREAK
 case 7:
 YY_RULE_SETUP
-#line 94 "scan-gram.l"
+#line 121 "scan-gram.l"
 return PERCENT_FILE_PREFIX;
 	YY_BREAK
 case 8:
 YY_RULE_SETUP
-#line 95 "scan-gram.l"
+#line 122 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 9:
 YY_RULE_SETUP
-#line 96 "scan-gram.l"
+#line 123 "scan-gram.l"
 return PERCENT_LEFT;
 	YY_BREAK
 case 10:
 YY_RULE_SETUP
-#line 97 "scan-gram.l"
+#line 124 "scan-gram.l"
 return PERCENT_LOCATIONS;
 	YY_BREAK
 case 11:
 YY_RULE_SETUP
-#line 98 "scan-gram.l"
+#line 125 "scan-gram.l"
 return PERCENT_NAME_PREFIX;
 	YY_BREAK
 case 12:
 YY_RULE_SETUP
-#line 99 "scan-gram.l"
+#line 126 "scan-gram.l"
 return PERCENT_NO_LINES;
 	YY_BREAK
 case 13:
 YY_RULE_SETUP
-#line 100 "scan-gram.l"
+#line 127 "scan-gram.l"
 return PERCENT_NONASSOC;
 	YY_BREAK
 case 14:
 YY_RULE_SETUP
-#line 101 "scan-gram.l"
+#line 128 "scan-gram.l"
 return PERCENT_NTERM;
 	YY_BREAK
 case 15:
 YY_RULE_SETUP
-#line 102 "scan-gram.l"
+#line 129 "scan-gram.l"
 return PERCENT_OUTPUT;
 	YY_BREAK
 case 16:
 YY_RULE_SETUP
-#line 103 "scan-gram.l"
+#line 130 "scan-gram.l"
 return PERCENT_PREC;
 	YY_BREAK
 case 17:
 YY_RULE_SETUP
-#line 104 "scan-gram.l"
+#line 131 "scan-gram.l"
 return PERCENT_PURE_PARSER;
 	YY_BREAK
 case 18:
 YY_RULE_SETUP
-#line 105 "scan-gram.l"
+#line 132 "scan-gram.l"
 return PERCENT_RIGHT;
 	YY_BREAK
 case 19:
 YY_RULE_SETUP
-#line 106 "scan-gram.l"
+#line 133 "scan-gram.l"
 return PERCENT_SKELETON;
 	YY_BREAK
 case 20:
 YY_RULE_SETUP
-#line 107 "scan-gram.l"
+#line 134 "scan-gram.l"
 return PERCENT_START;
 	YY_BREAK
 case 21:
 YY_RULE_SETUP
-#line 108 "scan-gram.l"
+#line 135 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 22:
 YY_RULE_SETUP
-#line 109 "scan-gram.l"
+#line 136 "scan-gram.l"
 return PERCENT_TOKEN;
 	YY_BREAK
 case 23:
 YY_RULE_SETUP
-#line 110 "scan-gram.l"
+#line 137 "scan-gram.l"
 return PERCENT_TOKEN_TABLE;
 	YY_BREAK
 case 24:
 YY_RULE_SETUP
-#line 111 "scan-gram.l"
+#line 138 "scan-gram.l"
 return PERCENT_TYPE;
 	YY_BREAK
 case 25:
 YY_RULE_SETUP
-#line 112 "scan-gram.l"
+#line 139 "scan-gram.l"
 return PERCENT_UNION;
 	YY_BREAK
 case 26:
 YY_RULE_SETUP
-#line 113 "scan-gram.l"
+#line 140 "scan-gram.l"
 return PERCENT_VERBOSE;
 	YY_BREAK
 case 27:
 YY_RULE_SETUP
-#line 114 "scan-gram.l"
+#line 141 "scan-gram.l"
 return PERCENT_YACC;
 	YY_BREAK
 case 28:
 YY_RULE_SETUP
-#line 116 "scan-gram.l"
+#line 143 "scan-gram.l"
 return EQUAL;
 	YY_BREAK
 case 29:
 YY_RULE_SETUP
-#line 117 "scan-gram.l"
+#line 144 "scan-gram.l"
 return COLON;
 	YY_BREAK
 case 30:
 YY_RULE_SETUP
-#line 118 "scan-gram.l"
+#line 145 "scan-gram.l"
 return PIPE;
 	YY_BREAK
 case 31:
 YY_RULE_SETUP
-#line 119 "scan-gram.l"
+#line 146 "scan-gram.l"
 return SEMICOLON;
 	YY_BREAK
 case 32:
 YY_RULE_SETUP
-#line 121 "scan-gram.l"
+#line 148 "scan-gram.l"
 YY_LINES; YY_STEP;
 	YY_BREAK
 case 33:
 YY_RULE_SETUP
-#line 122 "scan-gram.l"
+#line 149 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 case 34:
 YY_RULE_SETUP
-#line 123 "scan-gram.l"
+#line 150 "scan-gram.l"
 {
-    YY_INIT; YY_GROW; YY_FINISH;
-    yylval->symbol = getsym (yylval->string);
+    YY_OBS_INIT; YY_OBS_GROW; YY_OBS_FINISH;
+    yylval->symbol = getsym (last_string);
+    YY_OBS_FREE;
     return ID;
   }
 	YY_BREAK
 case 35:
 YY_RULE_SETUP
-#line 129 "scan-gram.l"
+#line 157 "scan-gram.l"
 yylval->integer = strtol (yytext, 0, 10); return INT;
 	YY_BREAK
 /* Characters.  We don't check there is only one.  */
 case 36:
 YY_RULE_SETUP
-#line 132 "scan-gram.l"
-YY_INIT; YY_GROW; yy_push_state (SC_ESCAPED_CHARACTER);
+#line 160 "scan-gram.l"
+YY_OBS_INIT; YY_OBS_GROW; yy_push_state (SC_ESCAPED_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 37:
 YY_RULE_SETUP
-#line 135 "scan-gram.l"
-YY_INIT; YY_GROW; yy_push_state (SC_ESCAPED_STRING);
+#line 163 "scan-gram.l"
+YY_OBS_INIT; YY_OBS_GROW; yy_push_state (SC_ESCAPED_STRING);
 	YY_BREAK
 /* Comments. */
 case 38:
 YY_RULE_SETUP
-#line 138 "scan-gram.l"
+#line 166 "scan-gram.l"
 yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 39:
 YY_RULE_SETUP
-#line 139 "scan-gram.l"
+#line 167 "scan-gram.l"
 YY_STEP;
 	YY_BREAK
 /* Prologue. */
 case 40:
 YY_RULE_SETUP
-#line 142 "scan-gram.l"
-YY_INIT; yy_push_state (SC_PROLOGUE);
+#line 170 "scan-gram.l"
+YY_OBS_INIT; yy_push_state (SC_PROLOGUE);
 	YY_BREAK
 /* Code in between braces.  */
 case 41:
 YY_RULE_SETUP
-#line 145 "scan-gram.l"
-YY_INIT; YY_GROW; ++braces_level; yy_push_state (SC_BRACED_CODE);
+#line 173 "scan-gram.l"
+YY_OBS_INIT; YY_OBS_GROW; ++braces_level; yy_push_state (SC_BRACED_CODE);
 	YY_BREAK
 /* A type. */
 case 42:
 YY_RULE_SETUP
-#line 148 "scan-gram.l"
-YY_INIT; obstack_grow (&string_obstack, yytext + 1, yyleng - 2); YY_FINISH; return TYPE;
+#line 176 "scan-gram.l"
+YY_OBS_INIT; obstack_grow (&string_obstack, yytext + 1, yyleng - 2); YY_OBS_FINISH; return TYPE;
 	YY_BREAK
 case 43:
 YY_RULE_SETUP
-#line 150 "scan-gram.l"
+#line 178 "scan-gram.l"
 {
     if (++percent_percent_count == 2)
       yy_push_state (SC_EPILOGUE);
@@ -1278,7 +1319,7 @@ YY_RULE_SETUP
 	YY_BREAK
 case 44:
 YY_RULE_SETUP
-#line 156 "scan-gram.l"
+#line 184 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": invalid character: `%c'\n", *yytext);
@@ -1295,12 +1336,12 @@ YY_RULE_SETUP
 
 case 45:
 YY_RULE_SETUP
-#line 172 "scan-gram.l"
+#line 200 "scan-gram.l"
 obstack_sgrow (&string_obstack, "@<:@");
 	YY_BREAK
 case 46:
 YY_RULE_SETUP
-#line 173 "scan-gram.l"
+#line 201 "scan-gram.l"
 obstack_sgrow (&string_obstack, "@:>@");
 	YY_BREAK
 
@@ -1311,7 +1352,7 @@ obstack_sgrow (&string_obstack, "@:>@");
 
 case 47:
 YY_RULE_SETUP
-#line 184 "scan-gram.l"
+#line 212 "scan-gram.l"
 { /* End of the comment. */
     if (yy_top_state () == INITIAL)
       {
@@ -1319,28 +1360,28 @@ YY_RULE_SETUP
       }
     else
       {
-	YY_GROW;
+	YY_OBS_GROW;
       }
     yy_pop_state ();
   }
 	YY_BREAK
 case 48:
 YY_RULE_SETUP
-#line 196 "scan-gram.l"
-if (yy_top_state () != INITIAL) YY_GROW;
+#line 224 "scan-gram.l"
+if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case 49:
 YY_RULE_SETUP
-#line 197 "scan-gram.l"
-if (yy_top_state () != INITIAL) YY_GROW; YY_LINES;
+#line 225 "scan-gram.l"
+if (yy_top_state () != INITIAL) YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case 50:
 YY_RULE_SETUP
-#line 198 "scan-gram.l"
-/* Stray `*'. */if (yy_top_state () != INITIAL) YY_GROW;
+#line 226 "scan-gram.l"
+/* Stray `*'. */if (yy_top_state () != INITIAL) YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_COMMENT):
-#line 200 "scan-gram.l"
+#line 228 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a comment\n");
@@ -1356,32 +1397,32 @@ case YY_STATE_EOF(SC_COMMENT):
 
 case 51:
 YY_RULE_SETUP
-#line 215 "scan-gram.l"
+#line 243 "scan-gram.l"
 {
     assert (yy_top_state () == INITIAL);
-    YY_GROW;
-    YY_FINISH;
+    YY_OBS_GROW;
+    YY_OBS_FINISH;
     yy_pop_state ();
     return STRING;
   }
 	YY_BREAK
 case 52:
 YY_RULE_SETUP
-#line 223 "scan-gram.l"
-YY_GROW;
+#line 251 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case 53:
 YY_RULE_SETUP
-#line 225 "scan-gram.l"
+#line 253 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_STRING):
-#line 227 "scan-gram.l"
+#line 255 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a string\n");
     assert (yy_top_state () == INITIAL);
-    YY_FINISH;
+    YY_OBS_FINISH;
     yy_pop_state ();
     return STRING;
   }
@@ -1395,17 +1436,16 @@ case YY_STATE_EOF(SC_ESCAPED_STRING):
 
 case 54:
 YY_RULE_SETUP
-#line 244 "scan-gram.l"
+#line 272 "scan-gram.l"
 {
-    YY_GROW;
+    YY_OBS_GROW;
     assert (yy_top_state () == INITIAL);
     {
-      char c;
-      YY_FINISH;
-      c = yylval->string[1];
-      yylval->symbol = getsym (yylval->string);
+      YY_OBS_FINISH;
+      yylval->symbol = getsym (last_string);
       symbol_class_set (yylval->symbol, token_sym);
-      symbol_user_token_number_set (yylval->symbol, (unsigned int) c);
+      symbol_user_token_number_set (yylval->symbol, last_string[1]);
+      YY_OBS_FREE;
       yy_pop_state ();
       return ID;
     }
@@ -1413,21 +1453,21 @@ YY_RULE_SETUP
 	YY_BREAK
 case 55:
 YY_RULE_SETUP
-#line 259 "scan-gram.l"
-YY_GROW;
+#line 286 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case 56:
 YY_RULE_SETUP
-#line 261 "scan-gram.l"
+#line 288 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n'); YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
-#line 263 "scan-gram.l"
+#line 290 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
     assert (yy_top_state () == INITIAL);
-    YY_FINISH;
+    YY_OBS_FINISH;
     yy_pop_state ();
     return CHARACTER;
   }
@@ -1440,7 +1480,7 @@ case YY_STATE_EOF(SC_ESCAPED_CHARACTER):
 
 case 57:
 YY_RULE_SETUP
-#line 280 "scan-gram.l"
+#line 307 "scan-gram.l"
 {
     long c = strtol (yytext + 1, 0, 8);
     if (c > 255)
@@ -1455,58 +1495,58 @@ YY_RULE_SETUP
 	YY_BREAK
 case 58:
 YY_RULE_SETUP
-#line 292 "scan-gram.l"
+#line 319 "scan-gram.l"
 {
     obstack_1grow (&string_obstack, strtol (yytext + 2, 0, 16));
   }
 	YY_BREAK
 case 59:
 YY_RULE_SETUP
-#line 296 "scan-gram.l"
+#line 323 "scan-gram.l"
 obstack_1grow (&string_obstack, '\a');
 	YY_BREAK
 case 60:
 YY_RULE_SETUP
-#line 297 "scan-gram.l"
+#line 324 "scan-gram.l"
 obstack_1grow (&string_obstack, '\b');
 	YY_BREAK
 case 61:
 YY_RULE_SETUP
-#line 298 "scan-gram.l"
+#line 325 "scan-gram.l"
 obstack_1grow (&string_obstack, '\f');
 	YY_BREAK
 case 62:
 YY_RULE_SETUP
-#line 299 "scan-gram.l"
+#line 326 "scan-gram.l"
 obstack_1grow (&string_obstack, '\n');
 	YY_BREAK
 case 63:
 YY_RULE_SETUP
-#line 300 "scan-gram.l"
+#line 327 "scan-gram.l"
 obstack_1grow (&string_obstack, '\r');
 	YY_BREAK
 case 64:
 YY_RULE_SETUP
-#line 301 "scan-gram.l"
+#line 328 "scan-gram.l"
 obstack_1grow (&string_obstack, '\t');
 	YY_BREAK
 case 65:
 YY_RULE_SETUP
-#line 302 "scan-gram.l"
+#line 329 "scan-gram.l"
 obstack_1grow (&string_obstack, '\v');
 	YY_BREAK
 case 66:
 YY_RULE_SETUP
-#line 303 "scan-gram.l"
+#line 330 "scan-gram.l"
 obstack_1grow (&string_obstack, yytext[1]);
 	YY_BREAK
 case 67:
 YY_RULE_SETUP
-#line 304 "scan-gram.l"
+#line 331 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unrecognized escape: %s\n", yytext);
-    YY_GROW;
+    YY_OBS_GROW;
   }
 	YY_BREAK
 
@@ -1518,30 +1558,30 @@ YY_RULE_SETUP
 
 case 68:
 YY_RULE_SETUP
-#line 319 "scan-gram.l"
+#line 346 "scan-gram.l"
 {
-    YY_GROW;
+    YY_OBS_GROW;
     assert (yy_top_state () != INITIAL);
     yy_pop_state ();
   }
 	YY_BREAK
 case 69:
 YY_RULE_SETUP
-#line 325 "scan-gram.l"
-YY_GROW;
+#line 352 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case 70:
 YY_RULE_SETUP
-#line 326 "scan-gram.l"
-YY_GROW;
+#line 353 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case 71:
 YY_RULE_SETUP
-#line 328 "scan-gram.l"
-YY_GROW; YY_LINES;
+#line 355 "scan-gram.l"
+YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_CHARACTER):
-#line 330 "scan-gram.l"
+#line 357 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a character\n");
@@ -1558,30 +1598,30 @@ case YY_STATE_EOF(SC_CHARACTER):
 
 case 72:
 YY_RULE_SETUP
-#line 346 "scan-gram.l"
+#line 373 "scan-gram.l"
 {
     assert (yy_top_state () != INITIAL);
-    YY_GROW;
+    YY_OBS_GROW;
     yy_pop_state ();
   }
 	YY_BREAK
 case 73:
 YY_RULE_SETUP
-#line 352 "scan-gram.l"
-YY_GROW;
+#line 379 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case 74:
 YY_RULE_SETUP
-#line 353 "scan-gram.l"
-YY_GROW;
+#line 380 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case 75:
 YY_RULE_SETUP
-#line 355 "scan-gram.l"
-YY_GROW; YY_LINES;
+#line 382 "scan-gram.l"
+YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_STRING):
-#line 357 "scan-gram.l"
+#line 384 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a string\n");
@@ -1598,25 +1638,25 @@ case YY_STATE_EOF(SC_STRING):
 /* Characters.  We don't check there is only one.  */
 case 76:
 YY_RULE_SETUP
-#line 373 "scan-gram.l"
-YY_GROW; yy_push_state (SC_CHARACTER);
+#line 400 "scan-gram.l"
+YY_OBS_GROW; yy_push_state (SC_CHARACTER);
 	YY_BREAK
 /* Strings. */
 case 77:
 YY_RULE_SETUP
-#line 376 "scan-gram.l"
-YY_GROW; yy_push_state (SC_STRING);
+#line 403 "scan-gram.l"
+YY_OBS_GROW; yy_push_state (SC_STRING);
 	YY_BREAK
 /* Comments. */
 case 78:
 YY_RULE_SETUP
-#line 379 "scan-gram.l"
-YY_GROW; yy_push_state (SC_COMMENT);
+#line 406 "scan-gram.l"
+YY_OBS_GROW; yy_push_state (SC_COMMENT);
 	YY_BREAK
 case 79:
 YY_RULE_SETUP
-#line 380 "scan-gram.l"
-YY_GROW;
+#line 407 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 
 /*---------------------------------------------------------------.
@@ -1627,55 +1667,55 @@ YY_GROW;
 
 case 80:
 YY_RULE_SETUP
-#line 391 "scan-gram.l"
+#line 418 "scan-gram.l"
 {
-    YY_GROW;
+    YY_OBS_GROW;
     if (--braces_level == 0)
       {
 	yy_pop_state ();
-	YY_FINISH;
+	YY_OBS_FINISH;
 	return BRACED_CODE;
       }
   }
 	YY_BREAK
 case 81:
 YY_RULE_SETUP
-#line 401 "scan-gram.l"
-YY_GROW; braces_level++;
+#line 428 "scan-gram.l"
+YY_OBS_GROW; braces_level++;
 	YY_BREAK
 case 82:
 YY_RULE_SETUP
-#line 403 "scan-gram.l"
+#line 430 "scan-gram.l"
 { handle_dollar (yytext); }
 	YY_BREAK
 case 83:
 YY_RULE_SETUP
-#line 404 "scan-gram.l"
+#line 431 "scan-gram.l"
 { handle_at (yytext); }
 	YY_BREAK
 case 84:
 YY_RULE_SETUP
-#line 406 "scan-gram.l"
-YY_GROW;
+#line 433 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case 85:
 YY_RULE_SETUP
-#line 407 "scan-gram.l"
-YY_GROW; YY_LINES;
+#line 434 "scan-gram.l"
+YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 /* A lose $, or /, or etc. */
 case 86:
 YY_RULE_SETUP
-#line 410 "scan-gram.l"
-YY_GROW;
+#line 437 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_BRACED_CODE):
-#line 412 "scan-gram.l"
+#line 439 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a braced code\n");
     yy_pop_state ();
-    YY_FINISH;
+    YY_OBS_FINISH;
     return PROLOGUE;
   }
 	YY_BREAK
@@ -1687,35 +1727,35 @@ case YY_STATE_EOF(SC_BRACED_CODE):
 
 case 87:
 YY_RULE_SETUP
-#line 429 "scan-gram.l"
+#line 456 "scan-gram.l"
 {
     yy_pop_state ();
-    YY_FINISH;
+    YY_OBS_FINISH;
     return PROLOGUE;
   }
 	YY_BREAK
 case 88:
 YY_RULE_SETUP
-#line 435 "scan-gram.l"
-YY_GROW;
+#line 462 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case 89:
 YY_RULE_SETUP
-#line 436 "scan-gram.l"
-YY_GROW;
+#line 463 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case 90:
 YY_RULE_SETUP
-#line 437 "scan-gram.l"
-YY_GROW; YY_LINES;
+#line 464 "scan-gram.l"
+YY_OBS_GROW; YY_LINES;
 	YY_BREAK
 case YY_STATE_EOF(SC_PROLOGUE):
-#line 439 "scan-gram.l"
+#line 466 "scan-gram.l"
 {
     LOCATION_PRINT (stderr, *yylloc);
     fprintf (stderr, ": unexpected end of file in a prologue\n");
     yy_pop_state ();
-    YY_FINISH;
+    YY_OBS_FINISH;
     return PROLOGUE;
   }
 	YY_BREAK
@@ -1728,24 +1768,24 @@ case YY_STATE_EOF(SC_PROLOGUE):
 
 case 91:
 YY_RULE_SETUP
-#line 457 "scan-gram.l"
-YY_GROW;
+#line 484 "scan-gram.l"
+YY_OBS_GROW;
 	YY_BREAK
 case YY_STATE_EOF(SC_EPILOGUE):
-#line 459 "scan-gram.l"
+#line 486 "scan-gram.l"
 {
     yy_pop_state ();
-    YY_FINISH;
+    YY_OBS_FINISH;
     return EPILOGUE;
   }
 	YY_BREAK
 
 case 92:
 YY_RULE_SETUP
-#line 467 "scan-gram.l"
+#line 494 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1749 "scan-gram.c"
+#line 1789 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
@@ -2309,11 +2349,15 @@ YY_BUFFER_STATE b;
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
@@ -2631,7 +2675,7 @@ int main()
 	return 0;
 	}
 #endif
-#line 467 "scan-gram.l"
+#line 494 "scan-gram.l"
 
 
 /*------------------------------------------------------------------.
