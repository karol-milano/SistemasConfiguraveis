@@ -143,10 +143,23 @@ m4_define([b4_rhs_location],
 m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
-b4_copyright([Skeleton parser for GLR parsing with Bison],
+b4_copyright([Skeleton implementation for Bison GLR parsers in C],
   [2002, 2003, 2004, 2005, 2006])
 [
-/* This is the parser code for GLR (Generalized LR) parser.  */
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
+
+/* C GLR parser skeleton written by Paul Hilfinger.  */
 
 ]b4_identification
 
@@ -2597,10 +2610,21 @@ yypdumpstack (yyGLRStack* yystackp)
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
-b4_copyright([Skeleton parser for GLR parsing with Bison],
-	     [2002, 2003, 2004, 2005, 2006])[
-
-/* C GLR parser skeleton written by Paul Hilfinger.  */
+b4_copyright([Skeleton interface for Bison GLR parsers in C],
+  [2002, 2003, 2004, 2005, 2006])
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
 ]
 
 b4_shared_declarations
