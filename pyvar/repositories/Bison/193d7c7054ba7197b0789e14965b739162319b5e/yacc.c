@@ -135,13 +135,21 @@ m4_define([b4_rhs_location],
 m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
-b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
-  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])[
-
-/* As a special exception, when this file is copied by Bison into a
-   Bison output file, you may use that output file without restriction.
-   This special exception was added by the Free Software Foundation
-   in version 1.24 of Bison.  */
+b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],
+  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
+[
+/* As a special exception, you may create a larger work that contains
+   part or all of the Bison parser skeleton and distribute that work
+   under terms of your choice, so long as that work isn't itself a
+   parser generator using the skeleton or a modified version thereof
+   as a parser skeleton.  Alternatively, if you modify or redistribute
+   the parser skeleton itself, you may (at your option) remove this
+   special exception, which will cause the skeleton and the resulting
+   Bison output files to be licensed under the GNU General Public
+   License without this special exception.
+
+   This special exception was added by the Free Software Foundation in
+   version 2.2 of Bison.  */
 
 /* C LALR(1) parser skeleton written by Richard Stallman, by
    simplifying the original so-called "semantic" parser.  */
@@ -1492,14 +1500,22 @@ yyreturn:
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
-b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
+b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
-
-/* As a special exception, when this file is copied by Bison into a
-   Bison output file, you may use that output file without restriction.
-   This special exception was added by the Free Software Foundation
-   in version 1.24 of Bison.  */
-
+[
+/* As a special exception, you may create a larger work that contains
+   part or all of the Bison parser skeleton and distribute that work
+   under terms of your choice, so long as that work isn't itself a
+   parser generator using the skeleton or a modified version thereof
+   as a parser skeleton.  Alternatively, if you modify or redistribute
+   the parser skeleton itself, you may (at your option) remove this
+   special exception, which will cause the skeleton and the resulting
+   Bison output files to be licensed under the GNU General Public
+   License without this special exception.
+
+   This special exception was added by the Free Software Foundation in
+   version 2.2 of Bison.  */
+]
 b4_token_enums_defines(b4_tokens)
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
