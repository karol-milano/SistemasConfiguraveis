@@ -156,7 +156,8 @@ m4_popdef([b4_dollar_dollar])dnl
 ])
 
 
-
+# We do want M4 expansion after # for CPP macros.
+m4_changecom()
 m4_divert(0)dnl
 #output "b4_output_parser_name"
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
