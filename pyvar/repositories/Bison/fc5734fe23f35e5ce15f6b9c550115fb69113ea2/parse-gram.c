@@ -1,7 +1,7 @@
 /* A Bison parser, made from parse-gram.y, by GNU bison 1.49b.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -91,11 +91,11 @@ do {							\
    correctly typed access to it.  */
 #define yycontrol ((gram_control_t *) gram_control)
 
-/* Request detailed parse error messages, and pass them to
-   GRAM_ERROR. */
+/* Request detailed parse error messages, and pass them to GRAM_ERROR.
+   FIXME: depends on the undocumented availability of YYLLOC.t */
 #undef  yyerror
 #define yyerror(Msg) \
-        gram_error (yycontrol, &yylloc, Msg)
+        gram_error (&yylloc, Msg)
 
 #define YYPRINT(File, Type, Value) \
         yyprint (File, Type, &Value)
@@ -1846,9 +1846,32 @@ yyprint (FILE *file,
 }
 
 void
-gram_error (gram_control_t *control ATTRIBUTE_UNUSED,
-	    location_t *yylloc, const char *msg)
+gram_error (location_t *yylloc, const char *msg)
 {
   complain_at (*yylloc, "%s", msg);
 }
 
+/* A Bison parser, made from parse-gram.y, by GNU bison 1.49b.  */
+
+/* Skeleton parser for Yacc-like parsing with Bison,
+   Copyright 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
+
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.  */
+
+/* As a special exception, when this file is copied by Bison into a
+   Bison output file, you may use that output file without restriction.
+   This special exception was added by the Free Software Foundation
+   in version 1.24 of Bison.  */
