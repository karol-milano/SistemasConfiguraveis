@@ -547,7 +547,7 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 #  endif
 # endif]b4_lac_if([[
 # define YYCOPY_NEEDED 1]])[
-#endif]b4_lac_if([], [b4_parse_error_case([simple], [[/* !defined yyoverflow */]])])[
+#endif /* ]b4_lac_if([[1]], [b4_parse_error_case([simple], [[!defined yyoverflow]], [[1]])])[ */
 
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
