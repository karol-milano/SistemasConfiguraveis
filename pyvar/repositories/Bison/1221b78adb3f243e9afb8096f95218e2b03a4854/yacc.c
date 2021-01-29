@@ -189,10 +189,11 @@ b4_location_if([#define yylloc b4_prefix[]lloc])])[
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 ]m4_ifdef([b4_stype],
-[b4_syncline([b4_stype_line], [b4_file_name])
-typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
+[typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])
+b4_stype
 /* Line __line__ of yacc.c.  */
-b4_syncline([@oline@], [@ofile@])],
+b4_syncline([@oline@], [@ofile@])
+	YYSTYPE;],
 [typedef int YYSTYPE;])[
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -1508,10 +1509,11 @@ b4_token_enums_defines(b4_tokens)
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 m4_ifdef([b4_stype],
-[b4_syncline([b4_stype_line], [b4_file_name])
-typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
+[typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])
+b4_stype
 /* Line __line__ of yacc.c.  */
-b4_syncline([@oline@], [@ofile@])],
+b4_syncline([@oline@], [@ofile@])
+	YYSTYPE;],
 [typedef int YYSTYPE;])
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
