@@ -2390,7 +2390,15 @@ b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
 b4_copyright([Skeleton parser for GLR parsing with Bison],
-             [2002, 2003, 2004, 2005])
+             [2002, 2003, 2004, 2005])[
+
+/* As a special exception, when this parser skeleton is copied by
+   Bison into a Bison output file, you may use that output file
+   without restriction.  This special exception was added by the Free
+   Software Foundation for C GLR parsers in version 2.2 of Bison.  */
+
+/* C GLR parser skeleton written by Paul Hilfinger.  */
+]
 
 b4_shared_declarations
 
