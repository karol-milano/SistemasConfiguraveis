@@ -248,7 +248,8 @@ b4_syncline([@oline@], [@ofile@])[
 
 #if (! defined (yyoverflow) \
      && (! defined (__cplusplus) \
-	 || (]b4_location_if([YYLTYPE_IS_TRIVIAL && ])[YYSTYPE_IS_TRIVIAL)))
+	 || (]b4_location_if([[defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
+             && ]])[defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
@@ -275,7 +276,7 @@ union yyalloc
 /* Copy COUNT objects from FROM to TO.  The source and destination do
    not overlap.  */
 # ifndef YYCOPY
-#  if 1 < __GNUC__
+#  if defined (__GNUC__) && 1 < __GNUC__
 #   define YYCOPY(To, From, Count) \
       __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
 #  else
