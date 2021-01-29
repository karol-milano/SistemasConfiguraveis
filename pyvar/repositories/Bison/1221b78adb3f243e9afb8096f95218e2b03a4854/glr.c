@@ -173,10 +173,11 @@ m4_define([b4_shared_declarations],
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 ]m4_ifdef([b4_stype],
-[b4_syncline([b4_stype_line], [b4_file_name])
-typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
+[typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])
+b4_stype
 /* Line __line__ of glr.c.  */
-b4_syncline([@oline@], [@ofile@])],
+b4_syncline([@oline@], [@ofile@])
+	YYSTYPE;],
 [typedef int YYSTYPE;])[
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
