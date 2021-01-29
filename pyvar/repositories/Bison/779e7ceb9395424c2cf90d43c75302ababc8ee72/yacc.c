@@ -1,7 +1,7 @@
 m4_divert(-1)                                                       -*- C -*-
 
 # Yacc compatible skeleton for Bison
-# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003
+# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004
 # Free Software Foundation, Inc.
 
 # This program is free software; you can redistribute it and/or modify
@@ -76,8 +76,8 @@ m4_define([b4_int_type],
 [m4_if(b4_ints_in($@,      [0],   [255]), [1], [unsigned char],
        b4_ints_in($@,   [-128],   [127]), [1], [yysigned_char],
 
-       b4_ints_in($@,      [0], [65535]), [1], [unsigned short],
-       b4_ints_in($@, [-32768], [32767]), [1], [short],
+       b4_ints_in($@,      [0], [65535]), [1], [unsigned short int],
+       b4_ints_in($@, [-32768], [32767]), [1], [short int],
 
        m4_eval([0 <= $1]),                [1], [unsigned int],
 
@@ -134,7 +134,7 @@ m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
-             [1984, 1989, 1990, 2000, 2001, 2002, 2003])[
+             [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004])[
 
 /* As a special exception, when this file is copied by Bison into a
    Bison output file, you may use that output file without restriction.
@@ -261,7 +261,7 @@ b4_syncline([@oline@], [@ofile@])[
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  short yyss;
+  short int yyss;
   YYSTYPE yyvs;
   ]b4_location_if([  YYLTYPE yyls;
 ])dnl
@@ -274,10 +274,10 @@ union yyalloc
    N elements.  */
 ]b4_location_if(
 [# define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
+     ((N) * (sizeof (short int) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
       + 2 * YYSTACK_GAP_MAXIMUM)],
 [# define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
+     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
       + YYSTACK_GAP_MAXIMUM)])[
 
 /* Copy COUNT objects from FROM to TO.  The source and destination do
@@ -319,7 +319,7 @@ union yyalloc
 #if defined (__STDC__) || defined (__cplusplus)
    typedef signed char yysigned_char;
 #else
-   typedef short yysigned_char;
+   typedef short int yysigned_char;
 #endif
 
 /* YYFINAL -- State number of the termination state. */
@@ -560,8 +560,8 @@ do {								\
 `------------------------------------------------------------------*/
 
 ]b4_c_function_def([yy_stack_print], [static void],
-                   [[short *bottom], [bottom]],
-                   [[short *top],    [top]])[
+                   [[short int *bottom], [bottom]],
+                   [[short int *top],    [top]])[
 {
   YYFPRINTF (stderr, "Stack now");
   for (/* Nothing. */; bottom <= top; ++bottom)
@@ -763,9 +763,9 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
      to reallocate them elsewhere.  */
 
   /* The state stack.  */
-  short	yyssa[YYINITDEPTH];
-  short *yyss = yyssa;
-  register short *yyssp;
+  short int yyssa[YYINITDEPTH];
+  short int *yyss = yyssa;
+  register short int *yyssp;
 
   /* The semantic value stack.  */
   YYSTYPE yyvsa[YYINITDEPTH];
@@ -842,7 +842,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	   these so that the &'s don't force the real ones into
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
-	short *yyss1 = yyss;
+	short int *yyss1 = yyss;
 ]b4_location_if([	YYLTYPE *yyls1 = yyls;])[
 
 	/* Each stack pointer address is followed by the size of the
@@ -870,7 +870,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	yystacksize = YYMAXDEPTH;
 
       {
-	short *yyss1 = yyss;
+	short int *yyss1 = yyss;
 	union yyalloc *yyptr =
 	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
 	if (! yyptr)
@@ -1241,7 +1241,7 @@ b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
-             [1984, 1989, 1990, 2000, 2001, 2002, 2003])
+             [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004])
 
 /* As a special exception, when this file is copied by Bison into a
    Bison output file, you may use that output file without restriction.
