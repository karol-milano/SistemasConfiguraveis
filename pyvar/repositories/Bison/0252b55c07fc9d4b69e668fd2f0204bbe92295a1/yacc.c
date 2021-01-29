@@ -130,6 +130,11 @@ m4_divert(0)dnl
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
              [1984, 1989, 1990, 2000, 2001, 2002])
 
+/* As a special exception, when this file is copied by Bison into a
+   Bison output file, you may use that output file without restriction.
+   This special exception was added by the Free Software Foundation
+   in version 1.24 of Bison.  */
+
 /* Written by Richard Stallman by simplifying the original so called
    ``semantic'' parser.  */
 
@@ -1255,7 +1260,12 @@ b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [#output "b4_output_header_name"
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
-              [1984, 1989, 1990, 2000, 2001, 2002])
+             [1984, 1989, 1990, 2000, 2001, 2002])
+
+/* As a special exception, when this file is copied by Bison into a
+   Bison output file, you may use that output file without restriction.
+   This special exception was added by the Free Software Foundation
+   in version 1.24 of Bison.  */
 
 #ifndef b4_header_guard
 # define b4_header_guard
