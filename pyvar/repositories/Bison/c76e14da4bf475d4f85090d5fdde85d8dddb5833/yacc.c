@@ -1230,9 +1230,10 @@ m4_map([b4_symbol_actions], m4_defn([b4_symbol_printers]))dnl
 
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
-[b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
+[#output "b4_output_header_name"
+b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
               [1984, 1989, 1990, 2000, 2001, 2002])
-#output "b4_output_header_name"
+
 #ifndef b4_header_guard
 # define b4_header_guard
 
