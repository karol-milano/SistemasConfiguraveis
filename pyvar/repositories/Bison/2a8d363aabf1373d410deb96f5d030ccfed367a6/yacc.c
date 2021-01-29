@@ -33,19 +33,37 @@ m4_define_default([b4_stack_depth_init],  [200])
 # Location type.
 m4_define_default([b4_location_type], [yyltype])
 
+
+## ------------------------ ##
+## Pure/impure interfaces.  ##
+## ------------------------ ##
+
+
+# b4_Pure_if(IF-TRUE, IF-FALSE)
+# -----------------------------
+# Expand IF-TRUE, if %pure-parser and %parse-param, IF-FALSE otherwise.
+m4_define([b4_Pure_if],
+[b4_pure_if([m4_ifset([b4_parse_param],
+                      [$1], [$2])],
+            [$2])])
+
+
+# b4_pure_args
+# ------------
+# Arguments passed to yyerror: user args plus yylloc.
+m4_define([b4_pure_args],
+[b4_Pure_if([b4_location_if([, &yylloc])])[]b4_user_args])
+
+
+# b4_lex_param
+# ------------
 # Accumule in b4_lex_param all the yylex arguments.
-# Yes, this is quite ugly...
+# b4_lex_param arrives quoted twice, but we want to keep only one level.
 m4_define([b4_lex_param],
 m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
 b4_location_if([, [[YYLTYPE *], [&yylloc]]])])dnl
 m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
-# Yes, this is quite ugly...
-m4_define_default([b4_parse_param])
-m4_ifdef([b4_parse_param],
-[m4_define([b4_parse_param],
-	   b4_parse_param)])
-
 
 
 ## ------------ ##
@@ -56,7 +74,7 @@ m4_ifdef([b4_parse_param],
 # ---------------------
 # Return the smallest int type able to handle numbers ranging from
 # MIN to MAX (included).  We overwrite the version from c.m4 which relies
-# on `signed char' which is not portable to old K&R compilers.
+# on "signed char" which is not portable to old K&R compilers.
 m4_define([b4_int_type],
 [m4_if(b4_ints_in($@,      [0],   [255]), [1], [unsigned char],
        b4_ints_in($@,   [-128],   [127]), [1], [yysigned_char],
@@ -178,15 +196,7 @@ b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
    define necessary library symbols; they are noted "INFRINGES ON
    USER NAME SPACE" below.  */
 
-/* Identify Bison output.  */
-#define YYBISON	1
-
-/* Pure parsers.  */
-#define YYPURE	b4_pure
-
-/* Using locations.  */
-#define YYLSP_NEEDED b4_locations_flag
-
+b4_identification
 m4_if(b4_prefix[], [yy], [],
 [/* If NAME_PREFIX is specified substitute the variables and functions
    names.  */
@@ -519,7 +529,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror ("syntax error: cannot back up");			\
+      yyerror ("syntax error: cannot back up"b4_pure_args);	\
       YYERROR;							\
     }								\
 while (0)
@@ -1125,15 +1135,15 @@ yyerrlab:
 			yycount++;
 		      }
 		}
-	      yyerror (yymsg);
+	      yyerror (yymsg]b4_pure_args[);
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror ("parse error; also virtual memory exhausted");
+	    yyerror ("parse error; also virtual memory exhausted"]b4_pure_args[);
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror ("parse error");
+	yyerror ("parse error"]b4_pure_args[);
     }
   goto yyerrlab1;
 
@@ -1248,7 +1258,7 @@ yyabortlab:
 | yyoverflowlab -- parser overflow comes here.  |
 `----------------------------------------------*/
 yyoverflowlab:
-  yyerror ("parser stack overflow");
+  yyerror ("parser stack overflow"]b4_pure_args[);
   yyresult = 2;
   /* Fall through.  */
 #endif
