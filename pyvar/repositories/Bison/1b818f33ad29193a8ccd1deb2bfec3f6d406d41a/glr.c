@@ -173,7 +173,7 @@ m4_define([b4_shared_declarations],
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
-[typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])
+[typedef union b4_union_name
 b4_stype
 /* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])
