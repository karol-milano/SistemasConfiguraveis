@@ -185,7 +185,7 @@ b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
-[typedef union[]m4_bregexp(b4_stype, [^{], [ YYSTYPE])
+[typedef union b4_union_name
 b4_stype
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])
@@ -1495,7 +1495,7 @@ b4_token_enums_defines(b4_tokens)
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 m4_ifdef([b4_stype],
-[typedef union[]m4_bregexp(b4_stype, [^{], [ YYSTYPE])
+[typedef union b4_union_name
 b4_stype
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])
