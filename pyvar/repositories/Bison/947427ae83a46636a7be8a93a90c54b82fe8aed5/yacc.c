@@ -39,7 +39,7 @@ m4_define_default([b4_location_type], [yyltype])
 ## ------------------------ ##
 
 
-# b4_Pure_if(IF-TRUE, IF-FALSE)
+# b4_pure_if(IF-TRUE, IF-FALSE)
 # -----------------------------
 # Expand IF-TRUE, if %pure-parser and %parse-param, IF-FALSE otherwise.
 m4_define([b4_Pure_if],
@@ -105,7 +105,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[yyvsp@<:@m4_eval([$2 - $1])@:>@m4_ifval([$3], [.$3])])
+[yyvsp@{m4_eval([$2 - $1])@}m4_ifval([$3], [.$3])])
 
 
 
@@ -125,32 +125,7 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[yylsp@<:@m4_eval([$2 - $1])@:>@])
-
-
-
-## ------------------- ##
-## Output file names.  ##
-## ------------------- ##
-
-m4_define_default([b4_input_suffix], [.y])
-
-m4_define_default([b4_output_parser_suffix],
-[m4_translit(b4_input_suffix, [yY], [cC])])
-
-m4_define_default([b4_output_parser_name],
-[b4_output_prefix[]b4_output_infix[]b4_output_parser_suffix[]])
-
-
-m4_define_default([b4_output_header_suffix],
-[m4_translit(b4_input_suffix, [yY], [hH])])
-
-m4_define_default([b4_output_header_name],
-[b4_output_prefix[]b4_output_infix[]b4_output_header_suffix[]])
-
-m4_define_default([b4_header_guard],
-                  [m4_bpatsubst(m4_toupper([BISON_]b4_output_header_name),
-                                [[^ABCDEFGHIJKLMNOPQRSTUVWXYZ]], [_])])
+[yylsp@{m4_eval([$2 - $1])@}])
 
 
 
@@ -168,7 +143,7 @@ m4_pushdef([b4_at_dollar], [yylocation])dnl
       case $4: /* $3 */
 b4_syncline([$2], [$1])
         $5;
-b4_syncline([__oline__], [__ofile__])
+b4_syncline([@oline@], [@ofile@])
         break;
 m4_popdef([b4_at_dollar])dnl
 m4_popdef([b4_dollar_dollar])dnl
@@ -178,7 +153,7 @@ m4_popdef([b4_dollar_dollar])dnl
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
 m4_divert(0)dnl
-#output "b4_output_parser_name"
+@output @output_parser_name@
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
              [1984, 1989, 1990, 2000, 2001, 2002])
 
@@ -233,7 +208,7 @@ m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
 /* Line __line__ of __file__.  */
-b4_syncline([__oline__], [__ofile__])],
+b4_syncline([@oline@], [@ofile@])],
 [typedef int yystype;])
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
@@ -255,7 +230,7 @@ typedef struct yyltype
 b4_post_prologue
 
 /* Line __line__ of __file__.  */
-b4_syncline([__oline__], [__ofile__])
+b4_syncline([@oline@], [@ofile@])
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -1054,7 +1029,7 @@ yyreduce:
     }
 
 /* Line __line__ of __file__.  */
-b4_syncline([__oline__], [__ofile__])
+b4_syncline([@oline@], [@ofile@])
 
 [  yyvsp -= yylen;
   yyssp -= yylen;
@@ -1275,7 +1250,7 @@ yyreturn:
 
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
-[#output "b4_output_header_name"
+[@output @output_header_name@
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
              [1984, 1989, 1990, 2000, 2001, 2002])
 
@@ -1284,9 +1259,6 @@ b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
    This special exception was added by the Free Software Foundation
    in version 1.24 of Bison.  */
 
-#ifndef b4_header_guard
-# define b4_header_guard
-
 b4_token_defines(b4_tokens)
 
 #ifndef YYSTYPE
@@ -1294,9 +1266,10 @@ m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
 /* Line __line__ of __file__.  */
-b4_syncline([__oline__], [__ofile__])],
+b4_syncline([@oline@], [@ofile@])],
 [typedef int yystype;])
 # define YYSTYPE yystype
+# define YYSTYPE_IS_TRIVIAL 1
 #endif
 
 b4_pure_if([],
@@ -1317,5 +1290,4 @@ typedef struct yyltype
 m4_if(b4_pure, [0],
 [extern YYLTYPE b4_prefix[]lloc;])
 ])
-#endif /* not b4_header_guard */
 ])
