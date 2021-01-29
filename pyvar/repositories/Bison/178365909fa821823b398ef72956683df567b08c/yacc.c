@@ -261,17 +261,17 @@ union yyalloc
 [};
 
 /* The size of the maximum gap between one aligned stack and the next.  */
-# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)
+# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)
 
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
 ]b4_location_if(
 [# define YYSTACK_BYTES(N) \
      ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
-      + 2 * YYSTACK_GAP_MAX)],
+      + 2 * YYSTACK_GAP_MAXIMUM)],
 [# define YYSTACK_BYTES(N) \
      ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
-      + YYSTACK_GAP_MAX)])[
+      + YYSTACK_GAP_MAXIMUM)])[
 
 /* Copy COUNT objects from FROM to TO.  The source and destination do
    not overlap.  */
@@ -302,7 +302,7 @@ union yyalloc
 	YYSIZE_T yynewbytes;						\
 	YYCOPY (&yyptr->Stack, Stack, yysize);				\
 	Stack = &yyptr->Stack;						\
-	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
+	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
 	yyptr += yynewbytes / sizeof (*yyptr);				\
       }									\
     while (0)
