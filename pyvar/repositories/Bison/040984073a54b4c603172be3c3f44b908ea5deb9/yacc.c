@@ -82,7 +82,7 @@ m4_define([b4_int_type],
 
        m4_eval([0 <= $1]),                [1], [unsigned int],
 
- 	                                       [int])])
+	                                       [int])])
 
 
 ## ----------------- ##
@@ -390,7 +390,7 @@ union yyalloc
 #define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
-#define YYTRANSLATE(YYX) 						\
+#define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
@@ -529,7 +529,7 @@ do								\
       goto yybackup;						\
     }								\
   else								\
-    { 								\
+    {								\
       yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
@@ -609,7 +609,7 @@ do {								\
   if (yydebug)							\
     {								\
       YYFPRINTF (stderr, "%s ", Title);				\
-      yysymprint (stderr, 					\
+      yysymprint (stderr,					\
                   Type, Value]b4_location_if([, Location])[);	\
       YYFPRINTF (stderr, "\n");					\
     }								\
