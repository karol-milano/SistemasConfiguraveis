@@ -2638,7 +2638,8 @@ b4_copyright([Skeleton interface for Bison GLR parsers in C],
 
 b4_shared_declarations
 
-extern YYSTYPE b4_prefix[]lval;
+b4_pure_if([],
+[[extern YYSTYPE b4_prefix][lval;]])
 
 b4_locations_if([b4_pure_if([],
 [extern YYLTYPE b4_prefix[]lloc;])
