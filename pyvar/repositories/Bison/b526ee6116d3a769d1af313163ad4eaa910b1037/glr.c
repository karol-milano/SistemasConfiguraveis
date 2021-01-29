@@ -111,6 +111,8 @@ m4_define_default([b4_header_guard],
                                 [[^ABCDEFGHIJKLMNOPQRSTUVWXYZ]], [_])])
 
 
+# We do want M4 expansion after # for CPP macros.
+m4_changecom()
 m4_divert(0)dnl
 #output "b4_output_parser_name"
 b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
