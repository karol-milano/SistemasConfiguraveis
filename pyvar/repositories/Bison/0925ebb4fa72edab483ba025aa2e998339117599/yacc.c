@@ -262,6 +262,9 @@ b4_syncline([@oline@], [@ofile@])[
 #  ifndef YYSTACK_ALLOC_MAXIMUM
 #   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
 #  endif
+#  ifdef __cplusplus
+extern "C" {
+#  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
 #   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
@@ -276,6 +279,9 @@ void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
+#  ifdef __cplusplus
+}
+#  endif
 # endif
 #endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
 
