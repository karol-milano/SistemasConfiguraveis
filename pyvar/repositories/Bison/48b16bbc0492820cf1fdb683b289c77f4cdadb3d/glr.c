@@ -179,7 +179,7 @@ b4_pre_prologue[
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 ]m4_ifdef([b4_stype],
-[b4_syncline([b4_stype_line], [b4_filename])
+[b4_syncline([b4_stype_line], [b4_file_name])
 typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
 /* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])],
@@ -2306,7 +2306,7 @@ b4_token_defines(b4_tokens)
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 m4_ifdef([b4_stype],
-[b4_syncline([b4_stype_line], [b4_filename])
+[b4_syncline([b4_stype_line], [b4_file_name])
 typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
 /* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])],
