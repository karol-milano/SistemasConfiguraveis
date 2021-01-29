@@ -358,12 +358,14 @@ static const char *const yytname[[]] =
 };
 #endif
 
+# ifdef YYPRINT
 /* YYTOKNUM[[YYLEX-NUM]] -- Internal token number corresponding to
    token YYLEX-NUM.  */
 static const b4_int_type_for([b4_toknum]) yytoknum[[]] =
 {
   b4_toknum
 };
+# endif
 
 /* YYR1[[YYN]] -- Symbol number of symbol that rule YYN derives.  */
 static const b4_int_type_for([b4_r1]) yyr1[[]] =
