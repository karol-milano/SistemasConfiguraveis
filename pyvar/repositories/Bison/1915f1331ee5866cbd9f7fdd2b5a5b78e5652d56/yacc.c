@@ -197,7 +197,7 @@ b4_syncline([@oline@], [@ofile@])],
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
-#ifndef YYLTYPE
+]b4_location_if([#ifndef YYLTYPE
 typedef struct yyltype
 {
   int first_line;
@@ -208,6 +208,7 @@ typedef struct yyltype
 # define YYLTYPE ]b4_location_type[
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
+])[
 
 /* Copy the second part of user declarations.  */
 ]b4_post_prologue
@@ -249,7 +250,7 @@ b4_syncline([@oline@], [@ofile@])[
 
 #if (! defined (yyoverflow) \
      && (! defined (__cplusplus) \
-	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
+	 || (]b4_location_if([YYLTYPE_IS_TRIVIAL && ])[YYSTYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
