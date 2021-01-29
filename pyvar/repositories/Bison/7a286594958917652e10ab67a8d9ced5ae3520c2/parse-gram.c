@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.1.123-b0950.  */
+/* A Bison parser, made by GNU Bison 3.5.2.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.1.123-b0950"
+#define YYBISON_VERSION "3.5.2"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -516,8 +516,8 @@ static const yytype_int16 yyrline[] =
      585,   587,   592,   599,   609,   613,   617,   625,   630,   642,
      643,   649,   650,   651,   658,   658,   666,   667,   668,   673,
      676,   678,   680,   682,   684,   686,   688,   690,   692,   697,
-     698,   707,   731,   732,   733,   734,   746,   748,   775,   780,
-     781,   786,   794,   795
+     698,   707,   731,   732,   733,   734,   746,   748,   772,   777,
+     778,   783,   791,   792
 };
 #endif
 
@@ -2450,14 +2450,11 @@ yyreduce:
         }
       if (muscle_percent_define_ifdef (var))
         {
-          int indent = 0;
-          complain_indent (&(yylsp[0]), complaint, &indent,
-                           _("character literals cannot be used together"
-                             " with %s"), var);
-          indent += SUB_INDENT;
+          complain (&(yylsp[0]), complaint,
+                    _("character literals cannot be used together"
+                    " with %s"), var);
           location loc = muscle_percent_define_get_loc (var);
-          complain_indent (&loc, complaint, &indent,
-                           _("definition of %s"), var);
+          subcomplain (&loc, complaint, _("definition of %s"), var);
         }
       (yyval.id) = symbol_get (char_name ((yyvsp[0].CHAR)), (yylsp[0]));
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
