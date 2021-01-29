@@ -1,4 +1,5 @@
 m4_divert(-1)                                                       -*- C -*-
+m4_include([c.m4])
 
 # Yacc compatible skeleton for Bison
 # Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -18,24 +19,6 @@ m4_divert(-1)                                                       -*- C -*-
 # Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 # 02111-1307  USA
 
-# b4_sint_type(MAX)
-# -----------------
-# Return the smallest signed int type able to handle the number MAX.
-m4_define([b4_sint_type],
-[m4_if(m4_eval([$1 <= 127]),        [1], [signed char],
-       m4_eval([$1 <= 32767]),      [1], [signed short],
-       [signed int])])
-
-
-# b4_uint_type(MAX)
-# -----------------
-# Return the smallest unsigned int type able to handle the number MAX.
-m4_define([b4_uint_type],
-[m4_if(m4_eval([$1 <= 255]),        [1], [unsigned char],
-       m4_eval([$1 <= 65535]),      [1], [unsigned short],
-       [unsigned int])])
-
-
 # b4_lhs_value([TYPE])
 # --------------------
 # Expansion of $<TYPE>$.
@@ -118,48 +101,6 @@ m4_define_default([b4_header_guard],
                                 [[^ABCDEFGHIJKLMNOPQRSTUVWXYZ]], [_])])
 
 
-## ------------------------- ##
-## Assigning token numbers.  ##
-## ------------------------- ##
-
-# b4_token_define(TOKEN-NAME, TOKEN-NUMBER)
-# -----------------------------------------
-# Output the definition of this token as #define.
-m4_define([b4_token_define],
-[#define $1 $2
-])
-
-
-# b4_token_enum(TOKEN-NAME, TOKEN-NUMBER)
-# ---------------------------------------
-# Output the definition of this token as an enum.
-m4_define([b4_token_enum],
-[$1 = $2])
-
-
-# b4_token_defines(LIST-OF-PAIRS-TOKEN-NAME-TOKEN-NUMBER)
-# -------------------------------------------------------
-# Output the definition of the tokens (if there are) as enums and #define.
-m4_define([b4_token_defines],
-[m4_if([$@], [[]], [],
-[/* Tokens.  */
-#ifndef YYTOKENTYPE
-# if defined (__STDC__) || defined (__cplusplus)
-   /* Put the tokens into the symbol table, so that GDB and other debuggers
-      know about them.  */
-   enum yytokentype {
-m4_map_sep([     b4_token_enum], [,
-],
-           [$@])
-   };
-# endif
-  /* POSIX requires `int' for tokens in interfaces.  */
-# define YYTOKENTYPE int
-#endif /* !YYTOKENTYPE */
-m4_map([b4_token_define], [$@])
-])
-])
-
 
 ## --------------------------------------------------------- ##
 ## Defining symbol actions, e.g., printers and destructors.  ##
@@ -185,37 +126,11 @@ m4_popdef([b4_dollar_dollar])dnl
 
 m4_divert(0)dnl
 #output "b4_output_parser_name"
-/* A Bison parser, made from b4_filename
-   by GNU bison b4_version.  */
-
-/* Skeleton output parser for Bison,
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
-   Foundation, Inc.
-
-   This program is free software; you can redistribute it and/or modify
-   it under the terms of the GNU General Public License as published by
-   the Free Software Foundation; either version 2, or (at your option)
-   any later version.
-
-   This program is distributed in the hope that it will be useful,
-   but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-   GNU General Public License for more details.
-
-   You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330,
-   Boston, MA 02111-1307, USA.  */
-
-/* As a special exception, when this file is copied by Bison into a
-   Bison output file, you may use that output file without restriction.
-   This special exception was added by the Free Software Foundation
-   in version 1.24 of Bison.  */
-
-/* This is the parser code that is written into each bison parser when
-   the %semantic_parser declaration is not specified in the grammar.
-   It was written by Richard Stallman by simplifying the original so
-   called ``semantic'' parser.  */
+b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
+             [1984, 1989, 1990, 2000, 2001, 2002])
+
+/* Written by Richard Stallman by simplifying the original so called
+   ``semantic'' parser.  */
 
 /* All symbols defined below should begin with yy or YY, to avoid
    infringing on user name space.  This should be done even for local
@@ -1315,7 +1230,9 @@ m4_map([b4_symbol_actions], m4_defn([b4_symbol_printers]))dnl
 
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
-[#output "b4_output_header_name"
+[b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
+              [1984, 1989, 1990, 2000, 2001, 2002])
+#output "b4_output_header_name"
 #ifndef b4_header_guard
 # define b4_header_guard
 
